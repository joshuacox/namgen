// web/lib/generatorLoader.js

const cache = new Map();
const inflight = new Map();

/**
 * Dynamically loads and returns the real JavaScript generator function for a given ID.
 * Returns a function: (type?: number) => string
 */
export async function loadGenerator(genId) {
  if (typeof window === 'undefined') {
    return () => 'Server preview';
  }

  // Check global registry or cache
  if (window.__NAMGEN_GENS && window.__NAMGEN_GENS[genId]) {
    return window.__NAMGEN_GENS[genId];
  }
  if (cache.has(genId)) {
    return cache.get(genId);
  }
  if (inflight.has(genId)) {
    return inflight.get(genId);
  }

  const promise = new Promise((resolve, reject) => {
    const basePath = process.env.NEXT_PUBLIC_BASE_PATH || '';
    const scriptUrl = `${basePath}/generators/${genId}.js`;

    const existing = document.querySelector(`script[data-gen-id="${genId}"]`);
    if (existing) {
      if (window.__NAMGEN_GENS && window.__NAMGEN_GENS[genId]) {
        const fn = window.__NAMGEN_GENS[genId];
        cache.set(genId, fn);
        inflight.delete(genId);
        resolve(fn);
        return;
      }
    }

    const script = document.createElement('script');
    script.src = scriptUrl;
    script.async = true;
    script.setAttribute('data-gen-id', genId);

    script.onload = () => {
      if (window.__NAMGEN_GENS && window.__NAMGEN_GENS[genId]) {
        const fn = window.__NAMGEN_GENS[genId];
        cache.set(genId, fn);
        inflight.delete(genId);
        resolve(fn);
      } else {
        inflight.delete(genId);
        reject(new Error(`Generator ${genId} loaded but failed to register`));
      }
    };

    script.onerror = () => {
      inflight.delete(genId);
      reject(new Error(`Failed to load generator script: ${scriptUrl}`));
    };

    document.head.appendChild(script);
  });

  inflight.set(genId, promise);
  return promise;
}

/**
 * Execute generator function live to produce count names with optional seed and uniqueness.
 */
export function executeGenerator(fn, count = 1, options = {}) {
  const { seed, unique = false } = options;
  const results = [];
  const seen = new Set();

  const runOnce = () => {
    try {
      const res = fn(options.type !== undefined ? options.type : 0);
      return typeof res === 'string' ? res.trim() : String(res).trim();
    } catch (e) {
      console.error('Error in live generator:', e);
      return null;
    }
  };

  const loop = () => {
    let attempts = 0;
    const maxAttempts = count * 60 + 200;
    while (results.length < count && attempts < maxAttempts) {
      attempts++;
      const val = runOnce();
      if (!val) continue;
      if (unique) {
        if (!seen.has(val)) {
          seen.add(val);
          results.push(val);
        }
      } else {
        results.push(val);
      }
    }
  };

  if (seed) {
    let s = 0;
    const seedStr = String(seed);
    for (let i = 0; i < seedStr.length; i++) {
      s = (s * 31 + seedStr.charCodeAt(i)) >>> 0;
    }
    const oldRandom = Math.random;
    Math.random = () => {
      s = (1664525 * s + 1013904223) >>> 0;
      return s / 4294967296;
    };
    try {
      loop();
    } finally {
      Math.random = oldRandom;
    }
  } else {
    loop();
  }

  return results;
}
