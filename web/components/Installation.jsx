'use client';

import React, { useState } from 'react';

export default function Installation() {
  const [activeTab, setActiveTab] = useState('make'); // 'make' | 'curl' | 'cmake' | 'direct' | 'test'

  const snippets = {
    curl: `# One-liner installer (downloads, builds, and installs binary & assets)
curl -s https://raw.githubusercontent.com/joshuacox/namgen/refs/heads/main/scripts/install.sh | sh`,
    make: `# 1. Clone the repository
git clone https://github.com/joshuacox/namgen.git
cd namgen

# 2. Build in parallel across all CPU cores
make -j$(nproc)

# 3. Install binary, man page, and assets
sudo make install`,
    cmake: `# 1. Clone the repository
git clone https://github.com/joshuacox/namgen.git
cd namgen

# 2. Configure and build with CMake
cmake -B build
cmake --build build

# 3. Install binary, man page, and assets
sudo cmake --install build`,
    direct: `# Direct compilation with GCC or Clang (no build tool required)
git clone https://github.com/joshuacox/namgen.git
cd namgen

g++ -std=c++17 -O2 src/*.cpp -o namgen
sudo cp namgen /usr/local/bin/
sudo mkdir -p /usr/local/share/namgen
sudo cp -r assets /usr/local/share/namgen/`,
    wasm: `# WebAssembly (Node.js & Browser)
# 1. Run immediately via Node.js CLI runner (no C++ toolchain needed)
node wasm/namgen-cli.js --fantasy-dragons -c 5

# 2. Or rebuild WebAssembly bundle from source using Emscripten
make wasm

# 3. Use programmatically in Node.js or modern browsers
const { initNamgen } = require('./wasm/namgen-cli.js');
const namgen = await initNamgen();
console.log(namgen.generate('--fantasy-dragons', 3));`,
    test: `# Run automated test suite (86 tests)
./test.sh

# Run Bats integration tests directly
bats test/full.bats

# Verify non-empty generation across all 907 modules
bash test/tester.sh`,
  };

  const [copied, setCopied] = useState(false);

  const copyCode = () => {
    navigator.clipboard.writeText(snippets[activeTab]);
    setCopied(true);
    setTimeout(() => setCopied(false), 2000);
  };

  return (
    <section id="installation" className="py-20 bg-slate-900/40 border-b border-slate-800">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div className="text-center max-w-3xl mx-auto mb-12">
          <h2 className="text-xs uppercase font-bold tracking-wider text-emerald-400">Installation & Setup</h2>
          <p className="mt-2 text-3xl sm:text-4xl font-extrabold text-white">Get Started in Seconds</p>
          <p className="mt-4 text-slate-300">
            namgen has zero external C++ dependencies besides the C++17 standard library.
          </p>
        </div>

        <div className="max-w-4xl mx-auto">
          {/* Method tabs */}
          <div className="flex flex-wrap gap-2 justify-center mb-6">
            <button
              type="button"
              onClick={() => setActiveTab('make')}
              className={`px-4 py-2 rounded-lg text-sm font-semibold transition-all ${
                activeTab === 'make'
                  ? 'bg-emerald-500 text-slate-950 shadow'
                  : 'bg-slate-900 text-slate-400 border border-slate-800 hover:text-white'
              }`}
            >
              Parallel Make (Recommended)
            </button>
            <button
              type="button"
              onClick={() => setActiveTab('curl')}
              className={`px-4 py-2 rounded-lg text-sm font-semibold transition-all ${
                activeTab === 'curl'
                  ? 'bg-emerald-500 text-slate-950 shadow'
                  : 'bg-slate-900 text-slate-400 border border-slate-800 hover:text-white'
              }`}
            >
              One-Liner Script
            </button>
            <button
              type="button"
              onClick={() => setActiveTab('cmake')}
              className={`px-4 py-2 rounded-lg text-sm font-semibold transition-all ${
                activeTab === 'cmake'
                  ? 'bg-emerald-500 text-slate-950 shadow'
                  : 'bg-slate-900 text-slate-400 border border-slate-800 hover:text-white'
              }`}
            >
              CMake
            </button>
            <button
              type="button"
              onClick={() => setActiveTab('direct')}
              className={`px-4 py-2 rounded-lg text-sm font-semibold transition-all ${
                activeTab === 'direct'
                  ? 'bg-emerald-500 text-slate-950 shadow'
                  : 'bg-slate-900 text-slate-400 border border-slate-800 hover:text-white'
              }`}
            >
              Direct g++
            </button>
            <button
              type="button"
              onClick={() => setActiveTab('wasm')}
              className={`px-4 py-2 rounded-lg text-sm font-semibold transition-all ${
                activeTab === 'wasm'
                  ? 'bg-emerald-500 text-slate-950 shadow'
                  : 'bg-slate-900 text-slate-400 border border-slate-800 hover:text-white'
              }`}
            >
              WebAssembly / Node.js
            </button>
            <button
              type="button"
              onClick={() => setActiveTab('test')}
              className={`px-4 py-2 rounded-lg text-sm font-semibold transition-all ${
                activeTab === 'test'
                  ? 'bg-emerald-500 text-slate-950 shadow'
                  : 'bg-slate-900 text-slate-400 border border-slate-800 hover:text-white'
              }`}
            >
              Run Test Suite
            </button>
          </div>

          {/* Code display terminal */}
          <div className="rounded-2xl bg-slate-950 border border-slate-800 overflow-hidden shadow-2xl">
            <div className="flex items-center justify-between px-4 py-3 bg-slate-900 border-b border-slate-800">
              <div className="flex items-center gap-2">
                <span className="w-3 h-3 rounded-full bg-red-500/80" />
                <span className="w-3 h-3 rounded-full bg-yellow-500/80" />
                <span className="w-3 h-3 rounded-full bg-green-500/80" />
                <span className="ml-2 text-xs font-mono text-slate-400">Terminal — {activeTab}</span>
              </div>
              <button
                type="button"
                onClick={copyCode}
                className="inline-flex items-center gap-1.5 px-3 py-1 text-xs font-medium rounded-md bg-slate-800 hover:bg-slate-700 text-slate-300 border border-slate-700 transition-colors"
              >
                {copied ? 'Copied!' : 'Copy Commands'}
              </button>
            </div>
            <pre className="p-6 font-mono text-xs sm:text-sm text-slate-200 overflow-x-auto leading-relaxed">
              <code>{snippets[activeTab]}</code>
            </pre>
          </div>

          {/* Requirements & Info */}
          <div className="mt-8 grid grid-cols-1 sm:grid-cols-3 gap-4 text-xs text-slate-300">
            <div className="p-4 rounded-xl bg-slate-900/50 border border-slate-800">
              <div className="font-semibold text-white mb-1">Compiler Requirement</div>
              <div>GCC 7+ or Clang 6+ with C++17 support enabled (<code className="text-emerald-400">-std=c++17</code>).</div>
            </div>
            <div className="p-4 rounded-xl bg-slate-900/50 border border-slate-800">
              <div className="font-semibold text-white mb-1">Asset Directory</div>
              <div>Assets are looked up in <code className="text-emerald-400">/usr/local/share/namgen/assets</code> or local repo directory.</div>
            </div>
            <div className="p-4 rounded-xl bg-slate-900/50 border border-slate-800">
              <div className="font-semibold text-white mb-1">Unix Manual Page</div>
              <div>View system documentation anytime with <code className="text-emerald-400">man namgen</code>.</div>
            </div>
          </div>
        </div>
      </div>
    </section>
  );
}
