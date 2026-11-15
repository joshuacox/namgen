#!/usr/bin/env node
/**
 * Sync generated JS modules and WASM bundle from packages/namgen.js into a target public/ dir
 * (e.g. apps/githubio/public) so git never stores duplicate copies.
 */
const fs = require('fs');
const path = require('path');

const pkgRoot = path.resolve(__dirname, '..');
const targetPublic = path.resolve(process.cwd(), process.argv[2] || 'public');

const srcGens = path.join(pkgRoot, 'generators');
const destGens = path.join(targetPublic, 'generators');

const srcWasm = path.join(pkgRoot, 'wasm');
const destWasm = path.join(targetPublic, 'wasm');

function copyDir(src, dest, filterFn = () => true) {
  if (!fs.existsSync(src)) return 0;
  fs.mkdirSync(dest, { recursive: true });
  let count = 0;
  for (const entry of fs.readdirSync(src)) {
    if (!filterFn(entry)) continue;
    const s = path.join(src, entry);
    const d = path.join(dest, entry);
    if (fs.statSync(s).isFile()) {
      fs.copyFileSync(s, d);
      count++;
    }
  }
  return count;
}

const genCount = copyDir(srcGens, destGens, (f) => f.endsWith('.js'));
const wasmCount = copyDir(srcWasm, destWasm, (f) =>
  ['namgen.js', 'namgen.wasm', 'namgen.data'].includes(f)
);

console.log(`Synced ${genCount} generator scripts and ${wasmCount} WASM files to ${targetPublic}`);
