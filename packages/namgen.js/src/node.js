const fs = require('fs');
const path = require('path');
const vm = require('vm');
const { createRequire } = require('module');
const { getGenerator } = require('./index');
const {
  executeGeneratorFn,
  generateCombinations,
  composeGenerators,
} = require('./combinator');

let cachedPkgRoot = null;
let cachedWasmPromise = null;

/**
 * Locate the root directory of packages/namgen.js robustly across direct Node,
 * npm workspaces, and Next.js server bundles.
 */
function getPackageRoot() {
  if (cachedPkgRoot) return cachedPkgRoot;

  const candidates = [
    path.resolve(__dirname, '..'),
    path.resolve(process.cwd(), 'packages', 'namgen.js'),
    path.resolve(process.cwd(), '..', 'packages', 'namgen.js'),
    path.resolve(process.cwd(), '..', '..', 'packages', 'namgen.js'),
    path.resolve(process.cwd(), 'node_modules', 'namgen.js'),
    path.resolve(process.cwd(), '..', '..', 'node_modules', 'namgen.js'),
  ];

  for (const dir of candidates) {
    if (fs.existsSync(path.join(dir, 'generators')) && fs.existsSync(path.join(dir, 'data', 'generators.json'))) {
      cachedPkgRoot = dir;
      return dir;
    }
  }

  throw new Error('Unable to locate namgen.js package assets (generators/ and data/).');
}

function getGeneratorsDir() {
  return path.join(getPackageRoot(), 'generators');
}

function getWasmDir() {
  return path.join(getPackageRoot(), 'wasm');
}

function getDataDir() {
  return path.join(getPackageRoot(), 'data');
}

/**
 * Load a single procedural generator function in Node.js without bundler dynamic-require warnings.
 */
function loadGeneratorNode(idOrFlag) {
  const resolved = getGenerator(idOrFlag);
  const genId = resolved ? resolved.id : String(idOrFlag || '').replace(/^--/, '');
  if (!genId) {
    throw new Error('Generator ID or flag is required');
  }

  globalThis.__NAMGEN_GENS = globalThis.__NAMGEN_GENS || {};
  if (globalThis.__NAMGEN_GENS[genId]) {
    return globalThis.__NAMGEN_GENS[genId];
  }

  const filePath = path.join(getGeneratorsDir(), `${genId}.js`);
  if (!fs.existsSync(filePath)) {
    throw new Error(`Unknown generator '${idOrFlag}' (file not found: ${filePath})`);
  }

  const code = fs.readFileSync(filePath, 'utf8');
  vm.runInThisContext(code, { filename: filePath });

  if (typeof globalThis.__NAMGEN_GENS[genId] !== 'function') {
    throw new Error(`Generator '${genId}' failed to register on globalThis.__NAMGEN_GENS`);
  }

  return globalThis.__NAMGEN_GENS[genId];
}

/**
 * Generate `count` names using any of the 907 procedural generators or the combinator.
 */
function generateNames(idOrFlag, count = 1, options = {}) {
  if (!idOrFlag || idOrFlag === 'combinator' || idOrFlag === 'default') {
    return generateCombinations({ count, ...options });
  }
  const fn = loadGeneratorNode(idOrFlag);
  return executeGeneratorFn(fn, count, options);
}

/**
 * Compose multiple generators using a template string like "{1} of {2}".
 */
function composeNamesNode(generatorIds, template = '{1} {2}', count = 1, options = {}) {
  const fns = generatorIds.map((id) => loadGeneratorNode(id));
  return composeGenerators(fns, template, count, options);
}

/**
 * Roll a batch of named generator specs in one synchronous call.
 * Accepts an array of { key, generator, count, ...options } or { [key]: { generator, count, ...options } }.
 */
function generateBatch(specs) {
  const entries = Array.isArray(specs)
    ? specs
    : Object.entries(specs).map(([key, cfg]) => ({ key, ...cfg }));

  const out = {};
  for (const spec of entries) {
    const key = spec.key || spec.generator;
    out[key] = generateNames(spec.generator, spec.count || 1, spec);
  }
  return out;
}

/**
 * Initialize the compiled C++17 WebAssembly runtime in Node.js.
 */
async function initNodeWasm() {
  if (cachedWasmPromise) return cachedWasmPromise;

  const wasmDir = getWasmDir();
  const wasmJsPath = path.join(wasmDir, 'namgen.js');
  if (!fs.existsSync(wasmJsPath)) {
    throw new Error(`namgen WebAssembly runtime not found at ${wasmJsPath}`);
  }

  const pkgRequire = createRequire(path.join(getPackageRoot(), 'package.json'));
  const createNamgen = pkgRequire('./wasm/namgen.js');

  cachedWasmPromise = (async () => {
    const instance = await createNamgen({
      locateFile: (fileName) => path.join(wasmDir, fileName),
      noInitialRun: true,
    });

    const generateWasm = instance.cwrap('namgen_generate_wasm', 'string', ['string', 'number']);
    const hasGeneratorWasm = instance.cwrap('namgen_has_generator_wasm', 'number', ['string']);

    return {
      instance,
      createNamgen,
      hasGenerator: (flag) => Boolean(hasGeneratorWasm(flag)),
      generate: (flag, count = 1, seed = 0) => {
        const results = [];
        for (let i = 0; i < count; i++) {
          const currentSeed = seed ? Number(seed) + i : 0;
          results.push(generateWasm(flag, currentSeed));
        }
        return results;
      },
      run: (args) => instance.callMain(args),
    };
  })();

  return cachedWasmPromise;
}

module.exports = {
  getPackageRoot,
  getGeneratorsDir,
  getWasmDir,
  getDataDir,
  loadGeneratorNode,
  generateNames,
  composeNamesNode,
  generateBatch,
  initNodeWasm,
};
