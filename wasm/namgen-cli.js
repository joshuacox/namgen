#!/usr/bin/env node

const path = require('path');
const fs = require('fs');

const wasmJsPath = path.join(__dirname, 'namgen.js');

if (!fs.existsSync(wasmJsPath)) {
  console.error('Error: wasm/namgen.js not found. Please run "make wasm" first.');
  process.exit(1);
}

const createNamgen = require(wasmJsPath);

async function runCli() {
  const args = process.argv.slice(2);

  try {
    const instance = await createNamgen({
      locateFile: (fileName) => path.join(__dirname, fileName),
      noInitialRun: true,
      print: (text) => console.log(text),
      printErr: (text) => console.error(text),
    });

    // Run the compiled C++ main with process arguments
    instance.callMain(args);
  } catch (err) {
    if (err && err.name === 'ExitStatus') {
      process.exit(err.status);
    }
    console.error('Error executing namgen WASM:', err);
    process.exit(1);
  }
}

// Programmatic API helper
async function initNamgen() {
  const instance = await createNamgen({
    locateFile: (fileName) => path.join(__dirname, fileName),
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
        // If seed is provided and count > 1, offset seed per item so we don't repeat
        const currentSeed = seed ? (seed + i) : 0;
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
