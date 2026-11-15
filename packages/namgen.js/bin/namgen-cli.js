#!/usr/bin/env node

const path = require('path');
const fs = require('fs');

const wasmDir = path.join(__dirname, '..', 'wasm');
const wasmJsPath = path.join(wasmDir, 'namgen.js');

if (!fs.existsSync(wasmJsPath)) {
  console.error('Error: packages/namgen.js/wasm/namgen.js not found. Please run "make wasm" first.');
  process.exit(1);
}

const createNamgen = require(wasmJsPath);

async function runCli() {
  const args = process.argv.slice(2);

  try {
    const instance = await createNamgen({
      locateFile: (fileName) => path.join(wasmDir, fileName),
      noInitialRun: true,
      print: (text) => console.log(text),
      printErr: (text) => console.error(text),
    });

    instance.callMain(args);
  } catch (err) {
    if (err && err.name === 'ExitStatus') {
      process.exit(err.status);
    }
    console.error('Error executing namgen WASM:', err);
    process.exit(1);
  }
}

async function initNamgen() {
  const instance = await createNamgen({
    locateFile: (fileName) => path.join(wasmDir, fileName),
    noInitialRun: true,
  });

  const generateWasm = instance.cwrap('namgen_generate_wasm', 'string', ['string', 'number']);
  const hasGeneratorWasm = instance.cwrap('namgen_has_generator_wasm', 'number', ['string']);

  return {
    instance,
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
}

if (require.main === module) {
  runCli();
}

module.exports = {
  createNamgen,
  initNamgen,
};
