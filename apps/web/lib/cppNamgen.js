'use strict';

const fs = require('fs');
const path = require('path');
const { execFile } = require('child_process');
const { promisify } = require('util');

const execFileAsync = promisify(execFile);

const nodeNamgen = require('namgen.js/node');
const namgenMeta = require('namgen.js');
const nameChecker = require('namgen.js/name-checker');

let cachedPaths = null;

function resolveRepoAndBinary() {
  if (cachedPaths) return cachedPaths;
  const candidates = [
    process.env.NAMGEN_BIN_PATH ? path.dirname(path.resolve(process.env.NAMGEN_BIN_PATH)) : null,
    process.cwd(),
    path.resolve(process.cwd(), '../..'),
    path.resolve(__dirname, '../../../..'),
    path.resolve(__dirname, '../../..'),
  ].filter(Boolean);

  for (const dir of candidates) {
    const bin = process.env.NAMGEN_BIN_PATH && fs.existsSync(process.env.NAMGEN_BIN_PATH)
      ? path.resolve(process.env.NAMGEN_BIN_PATH)
      : path.join(dir, 'namgen');
    if (fs.existsSync(bin)) {
      try {
        fs.accessSync(bin, fs.constants.X_OK);
        cachedPaths = { available: true, repoRoot: path.dirname(bin), binaryPath: bin };
        return cachedPaths;
      } catch {}
    }
  }
  cachedPaths = { available: false, repoRoot: process.cwd(), binaryPath: null };
  return cachedPaths;
}

async function execNamgen(args, timeoutMs = 10000) {
  const info = resolveRepoAndBinary();
  if (!info.available || !info.binaryPath) {
    throw new Error('Native namgen binary not found');
  }
  const { stdout } = await execFileAsync(info.binaryPath, args, {
    cwd: info.repoRoot,
    timeout: timeoutMs,
    maxBuffer: 8 * 1024 * 1024,
  });
  return stdout;
}

function getCppEngineStatus() {
  const info = resolveRepoAndBinary();
  return {
    available: info.available,
    binaryPath: info.binaryPath,
    generatorCount: namgenMeta.generators.length,
  };
}

function cleanKeywordList(keywords) {
  if (Array.isArray(keywords)) {
    return keywords.map((k) => String(k || '').trim()).filter(Boolean);
  }
  return String(keywords || '')
    .split(/[\s,;]+/)
    .map((s) => s.trim())
    .filter(Boolean);
}

function fallbackPortmanteauBlend(aRaw, bRaw) {
  const a = nameChecker.toSlug(aRaw);
  const b = nameChecker.toSlug(bRaw);
  if (!a && !b) return '';
  if (!a) return b.charAt(0).toUpperCase() + b.slice(1);
  if (!b) return a.charAt(0).toUpperCase() + a.slice(1);
  for (let ov = Math.min(3, Math.min(a.length, b.length) - 1); ov >= 1; ov--) {
    if (a.length >= ov + 2 && b.length >= ov + 2 && a.slice(-ov) === b.slice(0, ov)) {
      const merged = a + b.slice(ov);
      return merged.charAt(0).toUpperCase() + merged.slice(1);
    }
  }
  const head = a.slice(0, Math.max(2, Math.ceil(a.length * 0.6)));
  const tail = b.length >= 6 ? b.slice(1) : b;
  const raw = head + tail;
  return raw.charAt(0).toUpperCase() + raw.slice(1);
}

async function rollCpp(options = {}) {
  const {
    generator = 'fantasy-dragons',
    count = 10,
    seed,
    minSyllables,
    maxSyllables,
    minLen,
    maxLen,
    alliterate = false,
    withLore = false,
    unique = false,
    preferCpp = true,
  } = options;

  const safeCount = Math.max(1, Math.min(500, Number(count) || 10));
  const resolved = namgenMeta.getGenerator(generator);
  const flag = resolved ? resolved.id : String(generator || '').replace(/^--/, '');

  if (preferCpp && resolveRepoAndBinary().available && flag && flag !== 'combinator' && flag !== 'default') {
    try {
      const args = [`--${flag}`, '-c', String(safeCount), '--json'];
      if (seed !== undefined && seed !== '' && seed !== null) {
        args.push('--seed', String(Math.floor(Number(seed)) || 1));
      }
      if (minSyllables || maxSyllables) {
        const minS = Number(minSyllables) || 1;
        const maxS = Number(maxSyllables) || minS;
        args.push('--syllables', `${minS}-${maxS}`);
      }
      if (minLen) args.push('--min-len', String(Number(minLen)));
      if (maxLen) args.push('--max-len', String(Number(maxLen)));
      if (alliterate) args.push('--alliterate');
      if (withLore) args.push('--with-lore');
      if (unique) args.push('--unique');

      const stdout = await execNamgen(args);
      const parsed = JSON.parse(stdout);
      if (Array.isArray(parsed)) {
        return { engine: 'cpp17', generator: flag, names: parsed };
      }
    } catch {}
  }

  // Fallback to JS engine
  const names = [];
  const seen = new Set();
  for (let i = 0; i < safeCount * 4 && names.length < safeCount; i++) {
    const batch = nodeNamgen.generateNames(flag || 'combinator', 1, seed !== undefined && seed !== '' ? { seed: Number(seed) + i } : {});
    const val = batch[0];
    if (!val) continue;
    if (unique) {
      const k = val.toLowerCase();
      if (seen.has(k)) continue;
      seen.add(k);
    }
    names.push(val);
  }
  return { engine: 'js-fallback', generator: flag || 'combinator', names };
}

async function markovCpp(options = {}) {
  const {
    generators = ['fantasy-elfs'],
    keywords = [],
    order = 3,
    count = 15,
    seed,
    minSyllables,
    maxSyllables,
    preferCpp = true,
  } = options;

  const genList = (Array.isArray(generators) ? generators : String(generators || '').split(','))
    .map((g) => String(g || '').trim().replace(/^--/, ''))
    .filter(Boolean);
  const kwList = cleanKeywordList(keywords);
  const safeCount = Math.max(1, Math.min(500, Number(count) || 15));
  const safeOrder = Math.max(2, Math.min(5, Number(order) || 3));

  if (preferCpp && resolveRepoAndBinary().available) {
    try {
      const args = ['--markov'];
      if (genList.length > 0) args.push(genList.join(','));
      args.push('--order', String(safeOrder), '-c', String(safeCount), '--unique', '--json');
      if (kwList.length > 0) args.push('--keywords', kwList.join(','));
      if (seed !== undefined && seed !== '' && seed !== null) {
        args.push('--seed', String(Math.floor(Number(seed)) || 1));
      }
      if (minSyllables || maxSyllables) {
        const minS = Number(minSyllables) || 1;
        const maxS = Number(maxSyllables) || minS;
        args.push('--syllables', `${minS}-${maxS}`);
      }
      const stdout = await execNamgen(args);
      const parsed = JSON.parse(stdout);
      if (Array.isArray(parsed)) {
        return { engine: 'cpp17', generators: genList, order: safeOrder, names: parsed };
      }
    } catch {}
  }

  // JS Markov fallback
  const corpus = [];
  for (const g of (genList.length > 0 ? genList : ['brand-sovereign_neologisms'])) {
    try {
      corpus.push(...nodeNamgen.generateNames(g, 35));
    } catch {}
  }
  for (const kw of kwList) {
    corpus.push(kw, kw, kw);
  }
  const transitions = new Map();
  const starts = [];
  for (const raw of corpus) {
    for (const token of String(raw).split(/\s+/)) {
      const clean = token.replace(/[^a-zA-Z]/g, '').toLowerCase();
      if (clean.length < safeOrder) continue;
      starts.push(clean.slice(0, safeOrder));
      for (let i = 0; i <= clean.length - safeOrder; i++) {
        const gram = clean.slice(i, i + safeOrder);
        const next = i + safeOrder < clean.length ? clean[i + safeOrder] : '\0';
        if (!transitions.has(gram)) transitions.set(gram, []);
        transitions.get(gram).push(next);
      }
    }
  }
  const out = [];
  const seen = new Set();
  for (let att = 0; out.length < safeCount && att < safeCount * 20 && starts.length > 0; att++) {
    let w = starts[Math.floor(Math.random() * starts.length)];
    for (let step = 0; step < 12; step++) {
      const list = transitions.get(w.slice(-safeOrder));
      if (!list || list.length === 0) break;
      const nxt = list[Math.floor(Math.random() * list.length)];
      if (nxt === '\0') break;
      w += nxt;
    }
    const fmt = w.charAt(0).toUpperCase() + w.slice(1);
    if (fmt.length >= 4 && !seen.has(fmt.toLowerCase())) {
      seen.add(fmt.toLowerCase());
      out.push(fmt);
    }
  }
  return { engine: 'js-fallback', generators: genList, order: safeOrder, names: out };
}

async function blendCpp(options = {}) {
  const {
    keywords = [],
    generator = '',
    count = 15,
    seed,
    preferCpp = true,
  } = options;

  const kwList = cleanKeywordList(keywords);
  const safeCount = Math.max(1, Math.min(500, Number(count) || 15));

  if (preferCpp && resolveRepoAndBinary().available) {
    try {
      const args = ['--blend', '-c', String(safeCount), '--unique', '--json'];
      if (kwList.length > 0) args.push('--keywords', kwList.join(','));
      if (generator) {
        const g = namgenMeta.getGenerator(generator);
        if (g) args.push(`--${g.id}`);
      }
      if (seed !== undefined && seed !== '' && seed !== null) {
        args.push('--seed', String(Math.floor(Number(seed)) || 1));
      }
      const stdout = await execNamgen(args);
      const parsed = JSON.parse(stdout);
      if (Array.isArray(parsed)) {
        return { engine: 'cpp17', names: parsed };
      }
    } catch {}
  }

  const pool = [...kwList];
  if (pool.length < 4) {
    pool.push('deck', 'spell', 'summon', 'mana', 'rift', 'arena', 'clash', 'brawl', 'forge', 'vault');
  }
  const names = [];
  const seen = new Set();
  for (let att = 0; names.length < safeCount && att < safeCount * 30; att++) {
    const a = pool[Math.floor(Math.random() * pool.length)];
    const b = pool[Math.floor(Math.random() * pool.length)];
    if (a.toLowerCase() === b.toLowerCase()) continue;
    const blended = fallbackPortmanteauBlend(a, b);
    if (blended.length >= 4 && !seen.has(blended.toLowerCase())) {
      seen.add(blended.toLowerCase());
      names.push(blended);
    }
  }
  return { engine: 'js-fallback', names };
}

function mapArchetypeToBrandId(archetype, idx) {
  const low = String(archetype || '').toLowerCase();
  if (low.includes('arcane') || low.includes('cyber')) return 'brand-arcane_cyberpunk';
  if (low.includes('class') || low.includes('etym') || low.includes('latin') || low.includes('greek')) return 'brand-classical_etymology';
  if (low.includes('portmanteau') || low.includes('punchy') || low.includes('blend')) return 'brand-punchy_portmanteaus';
  if (low.includes('minimal') || low.includes('func') || low.includes('clean')) return 'brand-functional_minimalist';
  if (low.includes('sovereign') || low.includes('neolog') || low.includes('coin')) return 'brand-sovereign_neologisms';
  const list = [
    'brand-arcane_cyberpunk',
    'brand-classical_etymology',
    'brand-punchy_portmanteaus',
    'brand-functional_minimalist',
    'brand-sovereign_neologisms',
  ];
  return list[idx % list.length];
}

async function oraclePoolCpp(options = {}) {
  const {
    count = 50,
    keywords = [],
    archetypes = [
      'Arcane/Cyberpunk',
      'Classical Etymology',
      'Punchy Portmanteaus',
      'Functional Minimalist',
      'Sovereign Neologisms',
    ],
    seed,
    minSyllables,
    maxSyllables,
    preferCpp = true,
  } = options;

  const safeCount = Math.max(1, Math.min(1000, Number(count) || 50));
  const kwList = cleanKeywordList(keywords);
  const archList = (Array.isArray(archetypes) && archetypes.length > 0
    ? archetypes
    : ['Arcane/Cyberpunk', 'Classical Etymology', 'Punchy Portmanteaus', 'Functional Minimalist', 'Sovereign Neologisms']
  ).map((a) => String(typeof a === 'object' ? a.name : a).trim()).filter(Boolean);

  if (preferCpp && resolveRepoAndBinary().available) {
    try {
      const args = ['--oracle-pool', '-c', String(safeCount), '--json-rich'];
      if (kwList.length > 0) args.push('--keywords', kwList.join(','));
      if (archList.length > 0) args.push('--archetypes', archList.join(','));
      if (seed !== undefined && seed !== '' && seed !== null) {
        args.push('--seed', String(Math.floor(Number(seed)) || 1));
      }
      if (minSyllables || maxSyllables) {
        const minS = Number(minSyllables) || 1;
        const maxS = Number(maxSyllables) || minS;
        args.push('--syllables', `${minS}-${maxS}`);
      }
      const stdout = await execNamgen(args, 15000);
      const parsed = JSON.parse(stdout);
      if (Array.isArray(parsed)) {
        return { engine: 'cpp17', candidates: parsed };
      }
    } catch {}
  }

  // JS fallback
  const candidates = [];
  const seen = new Set();
  for (let att = 0; candidates.length < safeCount && att < safeCount * 10; att++) {
    const idx = att % archList.length;
    const arch = archList[idx];
    const genId = mapArchetypeToBrandId(arch, idx);
    let name = '';
    if (kwList.length >= 2 && att % 5 === 2) {
      name = fallbackPortmanteauBlend(
        kwList[Math.floor(Math.random() * kwList.length)],
        kwList[Math.floor(Math.random() * kwList.length)]
      );
    } else {
      name = nodeNamgen.generateNames(genId, 1)[0] || '';
    }
    const slug = nameChecker.toSlug(name);
    if (!slug || seen.has(slug)) continue;
    const syl = nameChecker.countSyllables(name);
    if (minSyllables && syl < Number(minSyllables)) continue;
    if (maxSyllables && syl > Number(maxSyllables)) continue;
    seen.add(slug);
    candidates.push({
      name,
      archetype: arch,
      syllables: syl,
      sigil: nameChecker.pronunciationSigil(name),
      slug,
    });
  }
  return { engine: 'js-fallback', candidates };
}

module.exports = {
  getCppEngineStatus,
  rollCpp,
  markovCpp,
  blendCpp,
  oraclePoolCpp,
};
