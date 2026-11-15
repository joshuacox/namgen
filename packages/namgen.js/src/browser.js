const { getGenerator } = require('./index');
const { executeGeneratorFn } = require('./combinator');

const cache = new Map();
const inflight = new Map();
let wasmPromise = null;

/**
 * Resolve Next.js / static hosting basePath cleanly in browser environments.
 */
function getBasePath(overrideBasePath) {
  if (typeof overrideBasePath === 'string') return overrideBasePath;
  if (typeof process !== 'undefined' && process.env && process.env.NEXT_PUBLIC_BASE_PATH) {
    return process.env.NEXT_PUBLIC_BASE_PATH;
  }
  return '';
}

/**
 * Dynamically load and return a real JavaScript generator function in the browser.
 * Returns a function: (type?: number) => string
 */
async function loadGenerator(idOrFlag, options = {}) {
  if (typeof window === 'undefined') {
    return () => 'Server preview';
  }

  const resolved = getGenerator(idOrFlag);
  const genId = resolved ? resolved.id : String(idOrFlag).replace(/^--/, '');

  if (window.__NAMGEN_GENS && window.__NAMGEN_GENS[genId]) {
    const fn = window.__NAMGEN_GENS[genId];
    cache.set(genId, fn);
    return fn;
  }
  if (cache.has(genId)) {
    return cache.get(genId);
  }
  if (inflight.has(genId)) {
    return inflight.get(genId);
  }

  const basePath = getBasePath(options.basePath);
  const scriptUrl = `${basePath}/generators/${genId}.js`;

  const promise = new Promise((resolve, reject) => {
    const existing = document.querySelector(`script[data-gen-id="${genId}"]`);
    if (existing && window.__NAMGEN_GENS && window.__NAMGEN_GENS[genId]) {
      const fn = window.__NAMGEN_GENS[genId];
      cache.set(genId, fn);
      inflight.delete(genId);
      resolve(fn);
      return;
    }

    const script = document.createElement('script');
    script.src = scriptUrl;
    script.async = true;
    script.setAttribute('data-gen-id', genId);

    script.onload = () => {
      inflight.delete(genId);
      if (window.__NAMGEN_GENS && window.__NAMGEN_GENS[genId]) {
        const fn = window.__NAMGEN_GENS[genId];
        cache.set(genId, fn);
        resolve(fn);
      } else {
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
 * Load a generator script in the browser and immediately roll `count` names.
 */
async function rollGenerator(idOrFlag, count = 1, options = {}) {
  const fn = await loadGenerator(idOrFlag, options);
  return executeGeneratorFn(fn, count, options);
}

/**
 * Singleton WebAssembly runtime loader for browser clients.
 * Properly honors basePath so GitHub Pages (/namgen) and root deployments both work.
 */
async function initBrowserWasm(options = {}) {
  if (typeof window === 'undefined') {
    return null;
  }
  if (wasmPromise) {
    return wasmPromise;
  }

  const basePath = getBasePath(options.basePath);
  wasmPromise = (async () => {
    try {
      if (!window.createNamgen) {
        await new Promise((resolve, reject) => {
          const existing = document.querySelector('script[data-namgen-wasm="true"]');
          if (existing && window.createNamgen) {
            resolve();
            return;
          }
          const script = document.createElement('script');
          script.src = `${basePath}/wasm/namgen.js`;
          script.async = true;
          script.setAttribute('data-namgen-wasm', 'true');
          script.onload = resolve;
          script.onerror = () => reject(new Error(`Failed to load ${basePath}/wasm/namgen.js`));
          document.body.appendChild(script);
        });
      }

      if (!window.createNamgen) {
        throw new Error('createNamgen global missing after script load');
      }

      const instance = await window.createNamgen({
        locateFile: (file) => `${basePath}/wasm/${file}`,
        noInitialRun: true,
      });

      const generateWasm = instance.cwrap('namgen_generate_wasm', 'string', ['string', 'number']);
      const hasGeneratorWasm = instance.cwrap('namgen_has_generator_wasm', 'number', ['string']);

      return {
        instance,
        mod: instance,
        hasGenerator: (flag) => Boolean(hasGeneratorWasm(flag)),
        generate: (flag, count = 1, seed = 0) => {
          const results = [];
          for (let i = 0; i < count; i++) {
            const currentSeed = seed ? Number(seed) + i : 0;
            results.push(generateWasm(flag, currentSeed));
          }
          return results;
        },
        callMain: (args) => instance.callMain(args),
      };
    } catch (err) {
      wasmPromise = null;
      throw err;
    }
  })();

  return wasmPromise;
}

module.exports = {
  getBasePath,
  loadGenerator,
  rollGenerator,
  executeGenerator: executeGeneratorFn,
  executeGeneratorFn,
  initBrowserWasm,
};
