'use strict';

const fs = require('fs');
const net = require('net');
const readline = require('readline');

const USER_AGENT = 'namgen-namespace-oracle/1.3 (https://github.com/namgen)';

const SUPPORTED_TLDS = ['com', 'io', 'dev', 'org', 'gg', 'ai', 'app', 'net', 'games', 'xyz'];
const DEFAULT_TLDS = ['com', 'io', 'dev', 'org'];
const SUPPORTED_REGISTRIES = ['github', 'npm', 'pypi', 'crates', 'homebrew', 'dockerhub'];
const DEFAULT_REGISTRIES = ['github', 'npm', 'pypi', 'crates'];

const EXPLICIT_RDAP = {
  com: 'https://rdap.verisign.com/com/v1',
  net: 'https://rdap.verisign.com/net/v1',
  io: 'https://rdap.identitydigital.services/rdap',
  org: 'https://rdap.publicinterestregistry.org/rdap',
  dev: 'https://pubapi.registry.google/rdap',
  app: 'https://pubapi.registry.google/rdap',
  games: 'https://rdap.identitydigital.services/rdap',
  xyz: 'https://rdap.centralnic.com/xyz'
};

const EXPLICIT_WHOIS = {
  com: 'whois.verisign-grs.com',
  net: 'whois.verisign-grs.com',
  io: 'whois.nic.io',
  dev: 'whois.nic.google',
  app: 'whois.nic.google',
  org: 'whois.publicinterestregistry.org',
  ai: 'whois.nic.ai',
  gg: 'whois.gg',
  games: 'whois.nic.games',
  xyz: 'whois.nic.xyz'
};

const WHOIS_NOT_FOUND_MARKERS = [
  'no match for',
  'not found',
  'no entries found',
  'no data found',
  'domain not found',
  'no object found',
  'status: free',
  'status: available',
  'is available for registration',
  'is free'
];

const WHOIS_TAKEN_MARKERS = [
  'domain name:',
  'registry domain id:',
  'registrar:',
  'creation date:',
  'name server:',
  'nserver:'
];

const GITHUB_RESERVED = new Set([
  'about', 'account', 'accounts', 'admin', 'api', 'apps', 'blog', 'business',
  'careers', 'contact', 'copilot', 'customer', 'dashboard', 'developer',
  'docs', 'downloads', 'education', 'enterprise', 'events', 'explore',
  'features', 'gist', 'github', 'help', 'home', 'issues', 'join', 'login',
  'logout', 'marketplace', 'new', 'notifications', 'orgs', 'organizations',
  'packages', 'pricing', 'pulls', 'search', 'security', 'settings', 'shop',
  'signup', 'site', 'sponsors', 'status', 'support', 'team', 'teams',
  'topics', 'trending', 'users'
]);

let cachedIanaBootstrap = null;
let ianaBootstrapPromise = null;

function isVowel(ch) {
  return 'aeiouy'.includes((ch || '').toLowerCase());
}

function toSlug(name) {
  return String(name || '').toLowerCase().replace(/[^a-z0-9]/g, '');
}

function normalizePypiName(name) {
  return String(name || '').toLowerCase().replace(/[-_.]+/g, '-').replace(/^-+|-+$/g, '');
}

function countSyllables(name) {
  const words = String(name || '').toLowerCase().split(/[\s-]+/).filter(Boolean);
  if (words.length === 0) return 1;
  let total = 0;
  for (const raw of words) {
    const word = raw.replace(/[^a-z]/g, '');
    if (!word) continue;
    let count = 0;
    let prevVowel = false;
    for (let i = 0; i < word.length; i++) {
      const curVowel = isVowel(word[i]);
      if (curVowel && !prevVowel) count++;
      prevVowel = curVowel;
    }
    if (word.length > 2 && word.endsWith('e') && !word.endsWith('le') && count > 1) {
      count--;
    }
    total += Math.max(1, count);
  }
  return Math.max(1, total);
}

function clarifyChunk(chunk, isFirst) {
  let out = '';
  for (let i = 0; i < chunk.length; i++) {
    const c = chunk[i];
    const next = chunk[i + 1] || '';
    if (c === 'p' && next === 'h') { out += 'f'; i++; }
    else if (c === 'q' && next === 'u') { out += 'kw'; i++; }
    else if (c === 'a' && next === 'e') { out += 'ay'; i++; }
    else if (c === 'e' && next === 'i') { out += 'ay'; i++; }
    else if (c === 'a' && next === 'u') { out += 'aw'; i++; }
    else if (c === 'o' && next === 'u') { out += 'ow'; i++; }
    else if (c === 'x') { out += (isFirst && i === 0) ? 'z' : 'ks'; }
    else if (c === 'y' && !isFirst && !next) { out += 'ee'; }
    else { out += c; }
  }
  return out;
}

function pronunciationSigil(word) {
  const clean = toSlug(word).replace(/[0-9]/g, '');
  if (!clean) return '';
  const syllables = [];
  let cur = '';
  for (let i = 0; i < clean.length; i++) {
    const c = clean[i];
    cur += c;
    if (isVowel(c) && i + 1 < clean.length && !isVowel(clean[i + 1])) {
      if (i + 2 < clean.length) {
        if (isVowel(clean[i + 2])) {
          syllables.push(cur);
          cur = '';
        } else {
          cur += clean[i + 1];
          i++;
          syllables.push(cur);
          cur = '';
        }
      }
    }
  }
  if (cur) {
    if (syllables.length > 0 && !cur.split('').some(isVowel)) {
      syllables[syllables.length - 1] += cur;
    } else {
      syllables.push(cur);
    }
  }
  if (syllables.length === 0) syllables.push(clean);
  return '/' + syllables.map((s, idx) => {
    const c = clarifyChunk(s, idx === 0);
    return idx === 0 ? c.toUpperCase() : c;
  }).join('-') + '/';
}

function cleanMatchKey(value) {
  return String(value || '').toLowerCase().replace(/[^a-z0-9]/g, '');
}

class HostRateLimiter {
  constructor() {
    this.queues = new Map();
    this.lastRun = new Map();
  }

  async schedule(host, minIntervalMs, fn, signal) {
    const prev = this.queues.get(host) || Promise.resolve();
    const run = prev.then(async () => {
      if (signal && signal.aborted) {
        throw new Error('Aborted');
      }
      const now = Date.now();
      const prevTs = this.lastRun.get(host) || 0;
      const waitMs = prevTs + minIntervalMs - now;
      if (waitMs > 0) {
        await new Promise((resolve, reject) => {
          const timer = setTimeout(resolve, waitMs);
          if (signal) {
            signal.addEventListener('abort', () => {
              clearTimeout(timer);
              reject(new Error('Aborted'));
            }, { once: true });
          }
        });
      }
      this.lastRun.set(host, Date.now());
      return fn();
    });
    this.queues.set(host, run.catch(() => {}));
    return run;
  }
}

async function fetchWithTimeout(url, options = {}) {
  const { timeoutMs = 8000, signal: outerSignal, headers = {}, method = 'GET' } = options;
  const controller = new AbortController();
  const timer = setTimeout(() => controller.abort(new Error('Timeout')), timeoutMs);
  const onOuterAbort = () => controller.abort(new Error('Aborted'));
  if (outerSignal) {
    if (outerSignal.aborted) {
      clearTimeout(timer);
      throw new Error('Aborted');
    }
    outerSignal.addEventListener('abort', onOuterAbort, { once: true });
  }
  try {
    const res = await fetch(url, {
      method,
      headers: { 'User-Agent': USER_AGENT, ...headers },
      signal: controller.signal,
      redirect: 'follow'
    });
    const text = method === 'HEAD' ? '' : await res.text();
    let json = null;
    if (text && (res.headers.get('content-type') || '').includes('json')) {
      try { json = JSON.parse(text); } catch {}
    } else if (text && (text.startsWith('{') || text.startsWith('['))) {
      try { json = JSON.parse(text); } catch {}
    }
    return { status: res.status, headers: res.headers, text, json };
  } finally {
    clearTimeout(timer);
    if (outerSignal) outerSignal.removeEventListener('abort', onOuterAbort);
  }
}

async function loadIanaBootstrap(signal) {
  if (cachedIanaBootstrap) return cachedIanaBootstrap;
  if (ianaBootstrapPromise) return ianaBootstrapPromise;
  ianaBootstrapPromise = (async () => {
    try {
      const res = await fetchWithTimeout('https://data.iana.org/rdap/dns.json', {
        timeoutMs: 8000,
        signal,
        headers: { Accept: 'application/json' }
      });
      const map = new Map();
      if (res.status === 200 && res.json && Array.isArray(res.json.services)) {
        for (const entry of res.json.services) {
          if (!Array.isArray(entry) || entry.length < 2) continue;
          const tlds = entry[0] || [];
          const urls = entry[1] || [];
          const chosen = urls.find((u) => String(u).startsWith('https://')) || urls[0];
          if (!chosen) continue;
          const clean = String(chosen).replace(/\/+$/, '');
          for (const tld of tlds) {
            map.set(String(tld).toLowerCase(), clean);
          }
        }
      }
      cachedIanaBootstrap = map;
      return map;
    } catch {
      cachedIanaBootstrap = new Map();
      return cachedIanaBootstrap;
    }
  })();
  return ianaBootstrapPromise;
}

function queryWhoisPort43(host, query, timeoutMs = 7000) {
  return new Promise((resolve) => {
    let settled = false;
    let output = '';
    const finish = (status, note) => {
      if (settled) return;
      settled = true;
      resolve({ status, note, raw: output });
    };
    const socket = net.createConnection({ port: 43, host });
    socket.setTimeout(timeoutMs);
    socket.on('connect', () => {
      socket.write(`${query}\r\n`);
    });
    socket.on('data', (chunk) => {
      output += chunk.toString('utf8');
      if (output.length > 65536) socket.destroy();
    });
    socket.on('timeout', () => {
      socket.destroy();
      finish('UNKNOWN', 'WHOIS timeout');
    });
    socket.on('error', (err) => {
      finish('UNKNOWN', err ? err.message : 'WHOIS error');
    });
    socket.on('close', () => {
      const low = output.toLowerCase();
      if (!low.trim()) {
        return finish('UNKNOWN', 'Empty WHOIS response');
      }
      if (WHOIS_NOT_FOUND_MARKERS.some((m) => low.includes(m))) {
        return finish('FREE', 'WHOIS unallocated');
      }
      if (WHOIS_TAKEN_MARKERS.some((m) => low.includes(m))) {
        return finish('TAKEN', 'WHOIS registered');
      }
      return finish('UNKNOWN', 'Ambiguous WHOIS output');
    });
  });
}

async function checkDnsDoh(domain, limiter, signal) {
  const endpoints = [
    `https://dns.google/resolve?name=${encodeURIComponent(domain)}&type=NS`,
    `https://cloudflare-dns.com/dns-query?name=${encodeURIComponent(domain)}&type=NS`
  ];
  for (const url of endpoints) {
    const host = new URL(url).hostname;
    try {
      const res = await limiter.schedule(host, 60, () =>
        fetchWithTimeout(url, {
          timeoutMs: 6000,
          signal,
          headers: { Accept: 'application/dns-json' }
        }), signal);
      if (res.status === 200 && res.json) {
        const status = res.json.Status;
        const answers = res.json.Answer || [];
        if (status === 0 && answers.length > 0) {
          return { status: 'TAKEN', method: `DoH NS (${host})` };
        }
        if (status === 3) {
          return { status: 'NXDOMAIN', method: `DoH NXDOMAIN (${host})` };
        }
        if (status === 0) {
          return { status: 'UNDELEGATED', method: `DoH NODATA (${host})` };
        }
      }
    } catch (err) {
      if (err && err.message === 'Aborted') throw err;
    }
  }
  return { status: 'UNKNOWN', method: 'DoH failed' };
}

async function checkDomainAvailability(slug, tld, ctx) {
  const domain = `${slug}.${tld}`;
  const doh = await checkDnsDoh(domain, ctx.limiter, ctx.signal);
  if (doh.status === 'TAKEN') {
    return { tld, domain, status: 'TAKEN', method: doh.method };
  }

  let rdapBase = EXPLICIT_RDAP[tld];
  if (!rdapBase) {
    const iana = await loadIanaBootstrap(ctx.signal);
    rdapBase = iana.get(tld) || '';
  }

  if (rdapBase) {
    const rdapUrl = `${rdapBase}/domain/${encodeURIComponent(domain)}`;
    const rdapHost = new URL(rdapBase).hostname;
    try {
      const res = await ctx.limiter.schedule(rdapHost, 200, () =>
        fetchWithTimeout(rdapUrl, {
          timeoutMs: 8000,
          signal: ctx.signal,
          headers: { Accept: 'application/rdap+json, application/json' }
        }), ctx.signal);
      if (res.status === 200) {
        return { tld, domain, status: 'TAKEN', method: `RDAP ${rdapHost}` };
      }
      if (res.status === 404) {
        return { tld, domain, status: 'FREE', method: `RDAP 404 (${rdapHost})` };
      }
    } catch (err) {
      if (err && err.message === 'Aborted') throw err;
    }
  }

  const whoisHost = EXPLICIT_WHOIS[tld];
  if (whoisHost) {
    try {
      const whoisRes = await ctx.limiter.schedule(whoisHost, 400, () =>
        queryWhoisPort43(whoisHost, domain, 6500), ctx.signal);
      if (whoisRes.status === 'FREE' || whoisRes.status === 'TAKEN') {
        return { tld, domain, status: whoisRes.status, method: `WHOIS ${whoisHost}` };
      }
    } catch (err) {
      if (err && err.message === 'Aborted') throw err;
    }
  }

  return { tld, domain, status: 'UNKNOWN', method: doh.method || 'No RDAP/WHOIS verdict' };
}

async function checkGithub(slug, ctx) {
  if (GITHUB_RESERVED.has(slug)) {
    return { status: 'RESERVED', repos: 0, method: 'GitHub reserved route' };
  }
  const headers = { Accept: 'application/vnd.github+json' };
  if (ctx.githubToken) {
    headers.Authorization = `Bearer ${ctx.githubToken}`;
  }
  const minDelay = ctx.githubToken ? 120 : 850;
  try {
    const res = await ctx.limiter.schedule('api.github.com', minDelay, () =>
      fetchWithTimeout(`https://api.github.com/users/${encodeURIComponent(slug)}`, {
        timeoutMs: 7000,
        signal: ctx.signal,
        headers
      }), ctx.signal);

    if (res.status === 200) {
      let repos = (res.json && typeof res.json.public_repos === 'number') ? res.json.public_repos : 0;
      if (ctx.githubRepoSearch) {
        try {
          const sRes = await ctx.limiter.schedule('api.github.com', minDelay, () =>
            fetchWithTimeout(`https://api.github.com/search/repositories?q=${encodeURIComponent(slug)}+in:name&per_page=1`, {
              timeoutMs: 7000,
              signal: ctx.signal,
              headers
            }), ctx.signal);
          if (sRes.status === 200 && sRes.json && typeof sRes.json.total_count === 'number') {
            repos = sRes.json.total_count;
          }
        } catch {}
      }
      return { status: 'TAKEN', repos, method: 'GitHub API 200' };
    }
    if (res.status === 404) {
      try {
        const webRes = await ctx.limiter.schedule('github.com', 150, () =>
          fetchWithTimeout(`https://github.com/${encodeURIComponent(slug)}`, {
            method: 'HEAD',
            timeoutMs: 6000,
            signal: ctx.signal
          }), ctx.signal);
        if (webRes.status === 200) {
          return { status: 'TAKEN', repos: 0, method: 'GitHub Web HEAD 200' };
        }
        if (webRes.status === 404) {
          let repos = 0;
          if (ctx.githubRepoSearch) {
            try {
              const sRes = await ctx.limiter.schedule('api.github.com', minDelay, () =>
                fetchWithTimeout(`https://api.github.com/search/repositories?q=${encodeURIComponent(slug)}+in:name&per_page=1`, {
                  timeoutMs: 7000,
                  signal: ctx.signal,
                  headers
                }), ctx.signal);
              if (sRes.status === 200 && sRes.json && typeof sRes.json.total_count === 'number') {
                repos = sRes.json.total_count;
              }
            } catch {}
          }
          return { status: 'FREE', repos, method: 'GitHub 404 + Web 404' };
        }
      } catch {}
      return { status: 'FREE', repos: 0, method: 'GitHub API 404' };
    }
    if (res.status === 403 || res.status === 429) {
      // Rate-limited fallback to github.com HEAD
      try {
        const webRes = await ctx.limiter.schedule('github.com', 250, () =>
          fetchWithTimeout(`https://github.com/${encodeURIComponent(slug)}`, {
            method: 'HEAD',
            timeoutMs: 6000,
            signal: ctx.signal
          }), ctx.signal);
        if (webRes.status === 404) return { status: 'FREE', repos: 0, method: 'GitHub Web 404 (API throttled)' };
        if (webRes.status === 200) return { status: 'TAKEN', repos: 0, method: 'GitHub Web 200 (API throttled)' };
      } catch {}
      return { status: 'RATE_LIMITED', repos: 0, method: `GitHub API ${res.status}` };
    }
    return { status: 'UNKNOWN', repos: 0, method: `GitHub HTTP ${res.status}` };
  } catch (err) {
    if (err && err.message === 'Aborted') throw err;
    return { status: 'UNKNOWN', repos: 0, method: 'GitHub network error' };
  }
}

async function checkNpm(slug, ctx) {
  try {
    const res = await ctx.limiter.schedule('registry.npmjs.org', 120, () =>
      fetchWithTimeout(`https://registry.npmjs.org/${encodeURIComponent(slug)}`, {
        timeoutMs: 7000,
        signal: ctx.signal,
        headers: { Accept: 'application/vnd.npm.install-v1+json' }
      }), ctx.signal);
    if (res.status === 404) return { status: 'FREE', method: 'NPM 404' };
    if (res.status === 200) return { status: 'TAKEN', method: 'NPM 200' };
    return { status: 'UNKNOWN', method: `NPM HTTP ${res.status}` };
  } catch (err) {
    if (err && err.message === 'Aborted') throw err;
    return { status: 'UNKNOWN', method: 'NPM error' };
  }
}

async function checkPypi(slug, ctx) {
  const norm = normalizePypiName(slug);
  if (!norm) return { status: 'UNKNOWN', method: 'Invalid slug' };
  try {
    const res = await ctx.limiter.schedule('pypi.org', 140, () =>
      fetchWithTimeout(`https://pypi.org/pypi/${encodeURIComponent(norm)}/json`, {
        timeoutMs: 7000,
        signal: ctx.signal,
        headers: { Accept: 'application/json' }
      }), ctx.signal);
    if (res.status === 404) return { status: 'FREE', method: 'PyPI 404' };
    if (res.status === 200) return { status: 'TAKEN', method: 'PyPI 200' };
    return { status: 'UNKNOWN', method: `PyPI HTTP ${res.status}` };
  } catch (err) {
    if (err && err.message === 'Aborted') throw err;
    return { status: 'UNKNOWN', method: 'PyPI error' };
  }
}

function getCratesSparsePath(slug) {
  const s = slug.toLowerCase();
  if (s.length === 1) return `1/${s}`;
  if (s.length === 2) return `2/${s}`;
  if (s.length === 3) return `3/${s[0]}/${s}`;
  return `${s.slice(0, 2)}/${s.slice(2, 4)}/${s}`;
}

async function checkCrates(slug, ctx) {
  const sparsePath = getCratesSparsePath(slug);
  try {
    const res = await ctx.limiter.schedule('index.crates.io', 200, () =>
      fetchWithTimeout(`https://index.crates.io/${sparsePath}`, {
        timeoutMs: 7000,
        signal: ctx.signal
      }), ctx.signal);
    if (res.status === 404) return { status: 'FREE', method: 'Crates Sparse 404' };
    if (res.status === 200) return { status: 'TAKEN', method: 'Crates Sparse 200' };
  } catch (err) {
    if (err && err.message === 'Aborted') throw err;
  }

  try {
    const apiRes = await ctx.limiter.schedule('crates.io', 1050, () =>
      fetchWithTimeout(`https://crates.io/api/v1/crates/${encodeURIComponent(slug)}`, {
        timeoutMs: 7000,
        signal: ctx.signal,
        headers: { Accept: 'application/json' }
      }), ctx.signal);
    if (apiRes.status === 404) return { status: 'FREE', method: 'Crates API 404' };
    if (apiRes.status === 200) return { status: 'TAKEN', method: 'Crates API 200' };
    return { status: 'UNKNOWN', method: `Crates HTTP ${apiRes.status}` };
  } catch (err) {
    if (err && err.message === 'Aborted') throw err;
    return { status: 'UNKNOWN', method: 'Crates error' };
  }
}

async function checkHomebrew(slug, ctx) {
  try {
    const [fRes, cRes] = await Promise.all([
      ctx.limiter.schedule('formulae.brew.sh', 160, () =>
        fetchWithTimeout(`https://formulae.brew.sh/api/formula/${encodeURIComponent(slug)}.json`, {
          timeoutMs: 6500, signal: ctx.signal
        }), ctx.signal),
      ctx.limiter.schedule('formulae.brew.sh', 160, () =>
        fetchWithTimeout(`https://formulae.brew.sh/api/cask/${encodeURIComponent(slug)}.json`, {
          timeoutMs: 6500, signal: ctx.signal
        }), ctx.signal)
    ]);
    if (fRes.status === 200 || cRes.status === 200) return { status: 'TAKEN', method: 'Homebrew 200' };
    if (fRes.status === 404 && cRes.status === 404) return { status: 'FREE', method: 'Homebrew 404' };
    return { status: 'UNKNOWN', method: `Homebrew ${fRes.status}/${cRes.status}` };
  } catch (err) {
    if (err && err.message === 'Aborted') throw err;
    return { status: 'UNKNOWN', method: 'Homebrew error' };
  }
}

async function checkDockerHub(slug, ctx) {
  try {
    const res = await ctx.limiter.schedule('hub.docker.com', 200, () =>
      fetchWithTimeout(`https://hub.docker.com/v2/namespaces/${encodeURIComponent(slug)}/repositories/?page_size=1`, {
        timeoutMs: 6500, signal: ctx.signal, headers: { Accept: 'application/json' }
      }), ctx.signal);
    if (res.status === 200) {
      const count = res.json && typeof res.json.count === 'number' ? res.json.count : 0;
      return count > 0
        ? { status: 'TAKEN', method: `DockerHub (${count} repos)` }
        : { status: 'FREE', method: 'DockerHub 0 repos' };
    }
    if (res.status === 404) return { status: 'FREE', method: 'DockerHub 404' };
    return { status: 'UNKNOWN', method: `DockerHub ${res.status}` };
  } catch (err) {
    if (err && err.message === 'Aborted') throw err;
    return { status: 'UNKNOWN', method: 'DockerHub error' };
  }
}

async function checkSteamStore(name, ctx) {
  try {
    const url = `https://store.steampowered.com/api/storesearch/?term=${encodeURIComponent(name)}&l=english&cc=US`;
    const res = await ctx.limiter.schedule('store.steampowered.com', 320, () =>
      fetchWithTimeout(url, { timeoutMs: 7000, signal: ctx.signal, headers: { Accept: 'application/json' } }), ctx.signal);
    if (res.status === 200 && res.json && Array.isArray(res.json.items)) {
      const targetKey = cleanMatchKey(name);
      for (const item of res.json.items) {
        const itemName = String(item.name || '');
        const itemKey = cleanMatchKey(itemName);
        if (itemKey === targetKey) {
          return { status: 'COLLISION', match: itemName, id: item.id };
        }
      }
      return { status: 'CLEAR', match: null };
    }
    return { status: 'UNKNOWN', match: null };
  } catch (err) {
    if (err && err.message === 'Aborted') throw err;
    return { status: 'UNKNOWN', match: null };
  }
}

async function checkAppleAppStore(name, ctx) {
  try {
    const url = `https://itunes.apple.com/search?term=${encodeURIComponent(name)}&entity=software&limit=10`;
    const res = await ctx.limiter.schedule('itunes.apple.com', 320, () =>
      fetchWithTimeout(url, { timeoutMs: 7000, signal: ctx.signal, headers: { Accept: 'application/json' } }), ctx.signal);
    if (res.status === 200 && res.json && Array.isArray(res.json.results)) {
      const targetKey = cleanMatchKey(name);
      for (const item of res.json.results) {
        const trackName = String(item.trackName || '');
        const key = cleanMatchKey(trackName);
        if (key === targetKey || (targetKey.length >= 6 && key.startsWith(targetKey + ' '))) {
          return { status: 'COLLISION', match: trackName };
        }
      }
      return { status: 'CLEAR', match: null };
    }
    return { status: 'UNKNOWN', match: null };
  } catch (err) {
    if (err && err.message === 'Aborted') throw err;
    return { status: 'UNKNOWN', match: null };
  }
}

function parseCsvLine(line) {
  const fields = [];
  let cur = '';
  let inQuotes = false;
  for (let i = 0; i < line.length; i++) {
    const ch = line[i];
    if (inQuotes) {
      if (ch === '"' && line[i + 1] === '"') {
        cur += '"';
        i++;
      } else if (ch === '"') {
        inQuotes = false;
      } else {
        cur += ch;
      }
    } else if (ch === '"') {
      inQuotes = true;
    } else if (ch === ',') {
      fields.push(cur);
      cur = '';
    } else {
      cur += ch;
    }
  }
  fields.push(cur);
  return fields;
}

async function scanUsptoBulkCsv(targetNames, csvPath) {
  const hits = new Map();
  if (!csvPath || !fs.existsSync(csvPath)) {
    return { scanned: false, hits };
  }
  const targetMap = new Map();
  for (const name of targetNames) {
    targetMap.set(cleanMatchKey(name), name);
  }
  if (targetMap.size === 0) return { scanned: true, hits };

  const rl = readline.createInterface({
    input: fs.createReadStream(csvPath, { encoding: 'utf8' }),
    crlfDelay: Infinity
  });

  let markCol = -1;
  let serialCol = -1;
  let icCol = -1;
  let lineNo = 0;

  for await (const line of rl) {
    if (!line) continue;
    lineNo++;
    if (lineNo === 1) {
      const header = parseCsvLine(line).map((h) => h.trim().toLowerCase());
      markCol = header.findIndex((h) => ['mark_id_char', 'mark_identification', 'word_mark'].includes(h));
      serialCol = header.findIndex((h) => ['serial_no', 'serial_number'].includes(h));
      icCol = header.findIndex((h) => ['international_class', 'ic_code', 'intl_class'].includes(h));
      if (markCol === -1) markCol = 0;
      continue;
    }
    const cols = parseCsvLine(line);
    const mark = cols[markCol];
    if (!mark) continue;
    const key = cleanMatchKey(mark);
    if (targetMap.has(key)) {
      const existing = hits.get(key) || [];
      if (existing.length < 5) {
        existing.push({
          mark,
          serial: serialCol >= 0 ? (cols[serialCol] || '') : '',
          intlClass: icCol >= 0 ? (cols[icCol] || '') : ''
        });
        hits.set(key, existing);
      }
    }
  }
  return { scanned: true, hits };
}

function scoreAndRecommend(record, options) {
  const tlds = options.tlds || DEFAULT_TLDS;
  const tldWeights = { com: 30, io: 15, dev: 10, org: 5, gg: 8, ai: 12, app: 8, net: 6, games: 5, xyz: 3 };
  const totalTldWeight = tlds.reduce((acc, t) => acc + (tldWeights[t] || 5), 0) || 1;

  let earnedTldWeight = 0;
  let freeDomains = [];
  for (const tld of tlds) {
    const info = record.dns[tld];
    if (info && info.status === 'FREE') {
      earnedTldWeight += tldWeights[tld] || 5;
      freeDomains.push(`${record.slug}.${tld}`);
    }
  }
  const dnsScore = Math.round((earnedTldWeight / totalTldWeight) * 60);

  let ghScore = 0;
  const ghChecked = Boolean(record.registries.github);
  if (ghChecked) {
    if (record.registries.github.status === 'FREE') ghScore = 20;
    else if (record.registries.github.status === 'TAKEN' && (record.registries.github.repos || 0) === 0) ghScore = 5;
  } else {
    ghScore = 20;
  }

  const pkgKeys = (options.registries || DEFAULT_REGISTRIES).filter((r) => r !== 'github');
  let pkgScore = 15;
  if (pkgKeys.length > 0) {
    const freePkgs = pkgKeys.filter((k) => record.registries[k] && record.registries[k].status === 'FREE').length;
    pkgScore = Math.round((freePkgs / pkgKeys.length) * 15);
  }

  let marketScore = 5;
  const hasMarketCollision =
    (record.market.steam && record.market.steam.status === 'COLLISION') ||
    (record.market.apple && record.market.apple.status === 'COLLISION') ||
    (record.market.usptoHits && record.market.usptoHits.length > 0);
  if (hasMarketCollision) {
    marketScore = 0;
  }

  const score = Math.max(0, Math.min(100, dnsScore + ghScore + pkgScore + marketScore));
  record.score = score;

  // Trademark Clearance Probability heuristic label
  if (hasMarketCollision) {
    record.tmProbability = 'LOW (<25% — Conflict)';
  } else if (score === 100) {
    record.tmProbability = 'HIGH (85–95% Est.)';
  } else if (score >= 70) {
    record.tmProbability = 'MODERATE-HIGH (65–84% Est.)';
  } else if (score >= 45) {
    record.tmProbability = 'MEDIUM (40–64% Est.)';
  } else {
    record.tmProbability = 'LOW (<40% — Crowded)';
  }

  // Market proxy summary string
  const collisions = [];
  if (record.market.steam && record.market.steam.status === 'COLLISION') {
    collisions.push(`Steam:${record.market.steam.match}`);
  }
  if (record.market.apple && record.market.apple.status === 'COLLISION') {
    collisions.push(`AppStore:${record.market.apple.match}`);
  }
  if (record.market.usptoHits && record.market.usptoHits.length > 0) {
    collisions.push(`USPTO:${record.market.usptoHits[0].mark}`);
  }
  record.marketSummary = collisions.length > 0
    ? `COLLISION (${collisions.join('; ')})`
    : (options.marketChecks === false ? 'SKIPPED' : 'CLEAR_PROXY (verify USPTO/WIPO)');

  // Sovereign DNS + GitHub recommendation
  const preferredDomain = freeDomains[0] || `play${record.slug}.com`;
  const preferredGh = (record.registries.github && record.registries.github.status === 'FREE')
    ? `github.com/${record.slug}`
    : `github.com/${record.slug}-game`;
  record.recommendation = `${preferredDomain} + ${preferredGh}`;
  return record;
}

function buildFunnelStats(records, options) {
  const tlds = options.tlds || DEFAULT_TLDS;
  const pkgs = (options.registries || DEFAULT_REGISTRIES).filter((r) => r !== 'github');
  const total = records.length;
  const byTld = {};
  for (const tld of tlds) {
    byTld[tld] = records.filter((r) => r.dns[tld] && r.dns[tld].status === 'FREE').length;
  }
  const allTldsFree = records.filter((r) => tlds.every((t) => r.dns[t] && r.dns[t].status === 'FREE')).length;
  const githubFree = records.filter((r) => !r.registries.github || r.registries.github.status === 'FREE').length;
  const allPkgsFree = records.filter((r) => pkgs.every((p) => r.registries[p] && r.registries[p].status === 'FREE')).length;
  const cleanSweep = records.filter((r) => r.score === 100).length;
  const highScore = records.filter((r) => r.score >= 70).length;
  const marketCollisions = records.filter((r) => String(r.marketSummary || '').startsWith('COLLISION')).length;
  return { total, byTld, allTldsFree, githubFree, allPkgsFree, cleanSweep, highScore, marketCollisions };
}

async function mapWithConcurrency(items, concurrency, worker, signal) {
  const results = new Array(items.length);
  let cursor = 0;
  const runners = Array.from({ length: Math.min(concurrency, items.length || 1) }, async () => {
    while (true) {
      if (signal && signal.aborted) throw new Error('Aborted');
      const idx = cursor++;
      if (idx >= items.length) return;
      results[idx] = await worker(items[idx], idx);
    }
  });
  await Promise.all(runners);
  return results;
}

async function verifyCandidatePool(rawCandidates, options = {}) {
  const tlds = Array.isArray(options.tlds) && options.tlds.length > 0
    ? options.tlds.filter((t) => SUPPORTED_TLDS.includes(t))
    : DEFAULT_TLDS;
  const registries = Array.isArray(options.registries) && options.registries.length > 0
    ? options.registries.filter((r) => SUPPORTED_REGISTRIES.includes(r))
    : DEFAULT_REGISTRIES;
  const marketChecks = options.marketChecks !== false;
  const concurrency = Math.max(1, Math.min(10, Number(options.concurrency) || 5));
  const signal = options.signal || null;
  const onProgress = typeof options.onProgress === 'function' ? options.onProgress : () => {};

  // Normalize & deduplicate input candidates by slug
  const seenSlugs = new Set();
  const candidates = [];
  for (const item of rawCandidates || []) {
    const name = typeof item === 'string' ? item : item?.name;
    const slug = toSlug(name);
    if (!slug || seenSlugs.has(slug)) continue;
    seenSlugs.add(slug);
    candidates.push({
      name: String(name).trim(),
      slug,
      archetype: (typeof item === 'object' && item?.archetype) ? String(item.archetype) : 'Custom',
      syllables: (typeof item === 'object' && item?.syllables) ? Number(item.syllables) : countSyllables(name),
      sigil: (typeof item === 'object' && item?.sigil) ? String(item.sigil) : pronunciationSigil(name),
      rationale: (typeof item === 'object' && item?.rationale) ? String(item.rationale) : ''
    });
  }

  const ctx = {
    limiter: new HostRateLimiter(),
    signal,
    githubToken: options.githubToken || process.env.GITHUB_TOKEN || '',
    githubRepoSearch: Boolean(options.githubRepoSearch),
    marketChecks,
    tlds,
    registries
  };

  onProgress({ type: 'start', total: candidates.length, tlds, registries });

  // Optional USPTO offline bulk CSV scan before/alongside Stage 1
  let usptoHitsMap = new Map();
  let usptoScanned = false;
  if (options.usptoCsvPath) {
    const scan = await scanUsptoBulkCsv(candidates.map((c) => c.name), options.usptoCsvPath);
    usptoHitsMap = scan.hits;
    usptoScanned = scan.scanned;
    onProgress({ type: 'uspto_done', scanned: usptoScanned, matchedCount: usptoHitsMap.size });
  }

  let completedStage1 = 0;
  const stage1Records = await mapWithConcurrency(candidates, concurrency, async (cand) => {
    const dnsTasks = tlds.map((tld) => checkDomainAvailability(cand.slug, tld, ctx));
    const regTasks = [];
    if (registries.includes('github')) regTasks.push(['github', checkGithub(cand.slug, ctx)]);
    if (registries.includes('npm')) regTasks.push(['npm', checkNpm(cand.slug, ctx)]);
    if (registries.includes('pypi')) regTasks.push(['pypi', checkPypi(cand.slug, ctx)]);
    if (registries.includes('crates')) regTasks.push(['crates', checkCrates(cand.slug, ctx)]);
    if (registries.includes('homebrew')) regTasks.push(['homebrew', checkHomebrew(cand.slug, ctx)]);
    if (registries.includes('dockerhub')) regTasks.push(['dockerhub', checkDockerHub(cand.slug, ctx)]);

    const [dnsList, regEntries] = await Promise.all([
      Promise.all(dnsTasks),
      Promise.all(regTasks.map(async ([k, p]) => [k, await p]))
    ]);

    const dns = {};
    for (const d of dnsList) dns[d.tld] = d;
    const regMap = {};
    for (const [k, v] of regEntries) regMap[k] = v;

    const usptoHits = usptoHitsMap.get(cleanMatchKey(cand.name)) || [];
    const record = scoreAndRecommend({
      ...cand,
      dns,
      registries: regMap,
      market: { steam: null, apple: null, usptoHits }
    }, { tlds, registries, marketChecks: false });

    completedStage1++;
    onProgress({
      type: 'candidate_stage1',
      completed: completedStage1,
      total: candidates.length,
      record
    });
    return record;
  }, signal);

  // Stage 2: Market collision checks (Steam + Apple App Store) for shortlist (>= 50 pts, capped to avoid excessive latency on huge runs)
  const shortlistLimit = Number(options.stage2Limit) || 80;
  const shortlist = marketChecks
    ? stage1Records
        .filter((r) => r.score >= 50)
        .sort((a, b) => b.score - a.score)
        .slice(0, shortlistLimit)
    : [];

  if (shortlist.length > 0) {
    onProgress({ type: 'stage2_start', shortlistCount: shortlist.length });
    let completedStage2 = 0;
    await mapWithConcurrency(shortlist, Math.min(3, concurrency), async (rec) => {
      const [steam, apple] = await Promise.all([
        checkSteamStore(rec.name, ctx),
        checkAppleAppStore(rec.name, ctx)
      ]);
      rec.market.steam = steam;
      rec.market.apple = apple;
      scoreAndRecommend(rec, { tlds, registries, marketChecks: true });
      completedStage2++;
      onProgress({
        type: 'candidate_stage2',
        completed: completedStage2,
        total: shortlist.length,
        record: rec
      });
    }, signal);
  } else {
    for (const rec of stage1Records) {
      scoreAndRecommend(rec, { tlds, registries, marketChecks });
    }
  }

  stage1Records.sort((a, b) => (b.score - a.score) || (a.syllables - b.syllables) || a.name.localeCompare(b.name));
  const ranked = stage1Records.map((rec, idx) => ({ ...rec, rank: idx + 1 }));
  const stats = buildFunnelStats(ranked, { tlds, registries });

  const disclaimer =
    'Verification Note: DNS/RDAP/WHOIS, GitHub, package registries, and Steam/App Store checks are live empirical proxies, NOT legal trademark clearance. Confirm finalists on USPTO Trademark Search and WIPO Global Brand Database (Class 9 / Class 42) before filing.';

  onProgress({ type: 'done', stats, total: ranked.length });
  return {
    results: ranked,
    stats,
    tlds,
    registries,
    usptoScanned,
    disclaimer
  };
}

function renderSurvivalReportMarkdown(runResult, meta = {}) {
  const results = runResult.results || [];
  const stats = runResult.stats || buildFunnelStats(results, { tlds: runResult.tlds || DEFAULT_TLDS, registries: runResult.registries || DEFAULT_REGISTRIES });
  const tlds = runResult.tlds || DEFAULT_TLDS;
  const pkgs = (runResult.registries || DEFAULT_REGISTRIES).filter((r) => r !== 'github');

  const lines = [];
  lines.push(`# ${meta.title || 'Namespace Oracle Survival Matrix'}`);
  if (meta.pitch) {
    lines.push(`\n**Concept Pitch**: ${meta.pitch}`);
  }
  lines.push(`\n> **Legal Notice**: ${runResult.disclaimer || 'DNS/WHOIS/Store checks are empirical availability proxies only — always verify finalists directly on USPTO & WIPO (Class 9 / Class 42).'}`);

  // Attrition funnel mermaid
  lines.push('\n## Empirical Attrition Funnel\n');
  lines.push('```mermaid');
  lines.push('flowchart LR');
  lines.push(`  A["Initial Pool (${stats.total})"] --> B["All TLDs Free (${stats.allTldsFree})"]`);
  lines.push(`  B --> C["GitHub Free (${stats.githubFree})"]`);
  lines.push(`  C --> D["Packages Free (${stats.allPkgsFree})"]`);
  lines.push(`  D --> E["Clean Sweep 100 (${stats.cleanSweep})"]`);
  lines.push('```\n');

  lines.push('## Empirical Attrition Summary\n');
  lines.push('| Gate | Survivors | Survival Rate |');
  lines.push('| :--- | ---: | ---: |');
  const pct = (n) => (stats.total ? ((n / stats.total) * 100).toFixed(1) + '%' : '0.0%');
  lines.push(`| Total Candidates Scanned | ${stats.total} | 100.0% |`);
  for (const t of tlds) {
    lines.push(`| \`.${t}\` Unallocated / Free | ${stats.byTld[t] || 0} | ${pct(stats.byTld[t] || 0)} |`);
  }
  lines.push(`| GitHub Global Namespace Free | ${stats.githubFree} | ${pct(stats.githubFree)} |`);
  lines.push(`| Package Registries Free (${pkgs.join(', ')}) | ${stats.allPkgsFree} | ${pct(stats.allPkgsFree)} |`);
  lines.push(`| **Clean Sweep (Score 100)** | **${stats.cleanSweep}** | **${pct(stats.cleanSweep)}** |`);

  if (meta.aiSummary) {
    lines.push('\n## AI Executive Verdict\n');
    lines.push(meta.aiSummary.trim());
  }

  lines.push('\n## Survival Matrix\n');
  const tldHeaders = tlds.map((t) => `.${t}`).join(' | ');
  const tldAlign = tlds.map(() => ':--:').join(' | ');
  lines.push(`| Rank | Score | Name | Archetype | Syl | Pronunciation Sigil | TM Est. | ${tldHeaders} | GitHub | ${pkgs.map((p) => p.toUpperCase()).join(' / ')} | Market / TM Proxy | Sovereign Recommendation |`);
  lines.push(`| ---: | ----: | :--- | :--- | :-: | :--- | :--- | ${tldAlign} | :--: | :-: | :--- | :--- |`);

  for (const r of results) {
    const tldCols = tlds.map((t) => (r.dns[t] ? r.dns[t].status : 'SKIP')).join(' | ');
    const ghStatus = r.registries.github ? r.registries.github.status : 'SKIP';
    const pkgCols = pkgs.map((p) => (r.registries[p] ? r.registries[p].status : 'SKIP')).join('/');
    lines.push(
      `| ${r.rank} | ${r.score} | **${r.name}** | ${r.archetype} | ${r.syllables} | \`${r.sigil}\` | ${r.tmProbability} | ${tldCols} | ${ghStatus} | ${pkgCols} | ${r.marketSummary} | \`${r.recommendation}\` |`
    );
  }
  lines.push('');
  return lines.join('\n');
}

module.exports = {
  SUPPORTED_TLDS,
  DEFAULT_TLDS,
  SUPPORTED_REGISTRIES,
  DEFAULT_REGISTRIES,
  HostRateLimiter,
  toSlug,
  normalizePypiName,
  countSyllables,
  pronunciationSigil,
  checkDnsDoh,
  checkDomainAvailability,
  queryWhoisPort43,
  checkGithub,
  checkNpm,
  checkPypi,
  checkCrates,
  checkHomebrew,
  checkDockerHub,
  checkSteamStore,
  checkAppleAppStore,
  scanUsptoBulkCsv,
  scoreAndRecommend,
  buildFunnelStats,
  verifyCandidatePool,
  renderSurvivalReportMarkdown
};
