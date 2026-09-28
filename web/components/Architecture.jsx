'use client';

import React from 'react';

export default function Architecture() {
  return (
    <section id="architecture" className="py-20 border-b border-slate-800 bg-slate-900/40">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div className="text-center max-w-3xl mx-auto mb-16">
          <h2 className="text-xs uppercase font-bold tracking-wider text-emerald-400">Technical Deep Dive</h2>
          <p className="mt-2 text-3xl sm:text-4xl font-extrabold text-white">
            Zero-Allocation C++17 Architecture
          </p>
          <p className="mt-4 text-slate-300">
            How namgen achieves instant startup, zero runtime heap allocations, and sub-millisecond name generation.
          </p>
        </div>

        {/* 3 Pillars Grid */}
        <div className="grid grid-cols-1 lg:grid-cols-3 gap-8 mb-14">
          <div className="p-6 rounded-2xl bg-slate-900 border border-slate-800 shadow-xl">
            <div className="text-emerald-400 font-mono text-sm font-bold mb-2">01 / STATIC CONSTEXPR</div>
            <h3 className="text-lg font-bold text-white mb-2">Immutable .rodata Tables</h3>
            <p className="text-xs sm:text-sm text-slate-300 leading-relaxed">
              Every word, prefix, suffix, and title across all 907 generators is compiled as <code className="text-emerald-400">static constexpr std::string_view</code> arrays directly embedded into the binary’s <code className="text-slate-200">.rodata</code> section. No JSON parsing, no filesystem reads, and zero startup latency.
            </p>
          </div>

          <div className="p-6 rounded-2xl bg-slate-900 border border-slate-800 shadow-xl">
            <div className="text-emerald-400 font-mono text-sm font-bold mb-2">02 / ARRAYVIEW SPANS</div>
            <h3 className="text-lg font-bold text-white mb-2">Zero-Heap Array Switching</h3>
            <p className="text-xs sm:text-sm text-slate-300 leading-relaxed">
              To support runtime conditionals (such as male/female/neutral variants, or culture tables) without allocating <code className="text-emerald-400">std::vector</code>, namgen uses a lightweight non-owning span:
            </p>
            <pre className="mt-3 p-3 rounded-lg bg-slate-950 font-mono text-xs text-slate-300 overflow-x-auto">
{`struct ArrayView {
    const std::string_view* data;
    std::size_t length;
    constexpr bool empty() const { 
        return length == 0; 
    }
};`}
            </pre>
          </div>

          <div className="p-6 rounded-2xl bg-slate-900 border border-slate-800 shadow-xl">
            <div className="text-emerald-400 font-mono text-sm font-bold mb-2">03 / DECOUPLED REGISTRY</div>
            <h3 className="text-lg font-bold text-white mb-2">GeneratorRegistry Design</h3>
            <p className="text-xs sm:text-sm text-slate-300 leading-relaxed">
              Rather than maintaining thousands of lines of fragile if/else ladders in <code className="text-slate-200">namgen.cpp</code>, generators register their canonical name, aliases, description, and lambda runner into a centralized <code className="text-emerald-400">GeneratorRegistry</code>.
            </p>
          </div>
        </div>

        {/* Contributing a Generator */}
        <div className="max-w-4xl mx-auto p-8 rounded-2xl bg-slate-950 border border-slate-800 shadow-2xl">
          <h3 className="text-xl font-bold text-white mb-4 flex items-center gap-2">
            <span>Adding a New Generator in 3 Steps</span>
          </h3>
          <ol className="space-y-4 text-sm text-slate-300">
            <li className="flex items-start gap-3">
              <span className="flex-shrink-0 w-6 h-6 rounded-full bg-emerald-500/20 text-emerald-400 font-bold text-xs flex items-center justify-center">1</span>
              <div>
                <strong className="text-white">Create Header:</strong> Define your generator signature in <code className="text-emerald-400">src/&lt;category&gt;-&lt;name&gt;_lib.h</code>:
                <pre className="mt-1.5 p-2.5 rounded-lg bg-slate-900 font-mono text-xs text-slate-200">
                  std::string generate_custom_name(std::mt19937& rng);
                </pre>
              </div>
            </li>
            <li className="flex items-start gap-3">
              <span className="flex-shrink-0 w-6 h-6 rounded-full bg-emerald-500/20 text-emerald-400 font-bold text-xs flex items-center justify-center">2</span>
              <div>
                <strong className="text-white">Implement Module:</strong> Define your constexpr string tables and generation logic in <code className="text-emerald-400">src/&lt;category&gt;-&lt;name&gt;_lib.cpp</code> using <code className="text-emerald-400">generator_common.h</code>.
              </div>
            </li>
            <li className="flex items-start gap-3">
              <span className="flex-shrink-0 w-6 h-6 rounded-full bg-emerald-500/20 text-emerald-400 font-bold text-xs flex items-center justify-center">3</span>
              <div>
                <strong className="text-white">Register in GeneratorRegistry:</strong> Add one registration entry in <code className="text-emerald-400">src/generator_registry.cpp</code>:
                <pre className="mt-1.5 p-2.5 rounded-lg bg-slate-900 font-mono text-xs text-slate-200">
{`registerGenerator({
    "my_category-my_name",
    {"optional-alias"},
    "Generate My Name style names",
    [](std::mt19937& rng) { return generate_custom_name(rng); }
});`}
                </pre>
              </div>
            </li>
          </ol>
        </div>
      </div>
    </section>
  );
}
