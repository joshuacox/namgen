'use client';

import React from 'react';

export default function Features() {
  const features = [
    {
      icon: '🛡️',
      title: 'Zero Heap Allocation Engine',
      description:
        'All word datasets are pre-compiled into immutable .rodata using static constexpr std::string_view tables. Dynamic branch switching uses lightweight ArrayView spans to avoid any runtime vector allocations.',
    },
    {
      icon: '⚡',
      title: '907 Lore-Accurate Generators',
      description:
        'Over 900 standalone procedural generators spanning 40 categories—from narrative character & planet descriptions to DnD, Star Wars, Warhammer, Elder Scrolls, Pokémon, and historical cultures.',
    },
    {
      icon: '🚀',
      title: 'Sub-Millisecond Execution',
      description:
        'Compiled directly with GCC/Clang with -O2 optimization. All 907 generators can be executed sequentially in under 19 seconds, making namgen ideal for scripts, game development, and pipelines.',
    },
    {
      icon: '🧩',
      title: 'Decoupled Dynamic Registry',
      description:
        'Clean C++ architecture replaces monolithic if/else blocks with a modular GeneratorRegistry. Dynamic registration powers command routing and automatic, categorized --help output.',
    },
    {
      icon: '🔤',
      title: 'Advanced Combinatorics',
      description:
        'Generate combinations from built-in or custom wordlists with versatile casing styles (CapWords, camelCase, lowercase), arbitrary separators, and character exclusion filters.',
    },
    {
      icon: '🌐',
      title: 'WebAssembly & Node.js (`namgen.wasm`)',
      description:
        'All 907 C++ generators compile to standalone WebAssembly via Emscripten. Includes an out-of-the-box Node.js CLI runner and full C-export interop for client-side web applications.',
    },
    {
      icon: '🐧',
      title: 'Unix Standard & Environment Config',
      description:
        'Full support for shell environment variables (SEPARATOR, COUNT, ADJ_FILE, NOUN_FILE) and bundled with an extensive 900+ entry Unix manual page (man namgen).',
    },
  ];

  return (
    <section id="features" className="py-20 border-b border-slate-800">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div className="text-center max-w-3xl mx-auto mb-16">
          <h2 className="text-xs uppercase font-bold tracking-wider text-emerald-400">Architecture & Features</h2>
          <p className="mt-2 text-3xl sm:text-4xl font-extrabold text-white">
            Engineered for Extreme Speed and Flexibility
          </p>
          <p className="mt-4 text-slate-300">
            A look under the hood of namgen’s C++17 design and performance optimizations.
          </p>
        </div>

        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-8">
          {features.map((feat, idx) => (
            <div
              key={idx}
              className="p-6 rounded-2xl bg-slate-900/60 border border-slate-800 hover:border-slate-700 transition-all hover:bg-slate-900/90 shadow-lg"
            >
              <div className="w-12 h-12 rounded-xl bg-slate-800/80 border border-slate-700/80 flex items-center justify-center text-2xl mb-4">
                {feat.icon}
              </div>
              <h3 className="text-lg font-bold text-white mb-2">{feat.title}</h3>
              <p className="text-sm text-slate-300 leading-relaxed">{feat.description}</p>
            </div>
          ))}
        </div>
      </div>
    </section>
  );
}
