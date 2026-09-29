# namgen WebAssembly (`namgen.wasm`)

This directory contains the WebAssembly (WASM) build of `namgen`, compiling the complete suite of 900+ procedural generators directly into portable, high-performance WebAssembly.

## Features

- **900+ Generators Built-in**: Full procedural generation algorithms compiled from C++17 to WASM.
- **Embedded Wordlists**: Pre-bundled standard wordlists (`assets/adjectives.txt`, `assets/nouns.txt`) mapped into Emscripten virtual filesystem.
- **Dual Interface**:
  - **CLI Runner**: Run from Node.js with native command-line arguments identical to the C++ binary (`node wasm/namgen-cli.js --fantasy-dragons -c 5`).
  - **Direct C/JS Export API**: Use `namgen_generate_wasm(flag, seed)` or programmatic wrapper `initNamgen()` in Node.js or modern web browsers.

## Building

Prerequisites:
- [Emscripten SDK](https://emscripten.org/) (`emcc` / `em++` 3.x+)

Run:
```bash
make wasm
```

This compiles all object files to `build-wasm/` and produces:
- `wasm/namgen.js`: Emscripten modularized JavaScript loader
- `wasm/namgen.wasm`: WebAssembly binary
- `wasm/namgen.data`: Embedded virtual filesystem containing asset wordlists

The files are also automatically copied to `web/public/wasm/` for static website serving.

## Usage

### 1. Command Line (Node.js)

```bash
# Display help and options
node wasm/namgen-cli.js --help

# Generate default adjective-noun names
node wasm/namgen-cli.js -c 3

# Generate fantasy dragon names
node wasm/namgen-cli.js --fantasy-dragons -c 5

# JSON output
node wasm/namgen-cli.js --fantasy-elfs -c 3 --json

# Seeded deterministic output
node wasm/namgen-cli.js --fantasy-dragons -c 3 --seed 12345
```

### 2. Node.js Programmatic API

```javascript
const { initNamgen } = require('./namgen-cli.js');

async function example() {
  const namgen = await initNamgen();

  // Check if a generator flag exists
  console.log(namgen.hasGenerator('--fantasy-dragons')); // true

  // Generate names
  const dragons = namgen.generate('--fantasy-dragons', 3);
  console.log('Dragons:', dragons);

  // Seeded generation
  const elfs = namgen.generate('--fantasy-elfs', 2, 42);
  console.log('Elfs:', elfs);
}

example();
```

### 3. Browser Usage

```html
<script src="/wasm/namgen.js"></script>
<script>
  createNamgen({
    locateFile: (file) => `/wasm/${file}`
  }).then((m) => {
    const generate = m.cwrap('namgen_generate_wasm', 'string', ['string', 'number']);
    console.log(generate('--fantasy-dragons', 0));
  });
</script>
```
