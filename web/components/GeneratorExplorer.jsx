'use client';

import React, { useState, useMemo } from 'react';
import generatorsData from '../data/generators.json';
import categoriesData from '../data/categories.json';
import { loadGenerator, executeGenerator } from '../lib/generatorLoader';

export default function GeneratorExplorer() {
  const [selectedCategory, setSelectedCategory] = useState('all');
  const [searchQuery, setSearchQuery] = useState('');
  const [copiedId, setCopiedId] = useState(null);
  const [displayLimit, setDisplayLimit] = useState(48);
  const [liveOutputs, setLiveOutputs] = useState({});
  const [rollingId, setRollingId] = useState(null);

  const rollCardLive = async (genId) => {
    setRollingId(genId);
    try {
      const fn = await loadGenerator(genId);
      const names = executeGenerator(fn, 2, { unique: true });
      setLiveOutputs((prev) => ({
        ...prev,
        [genId]: names,
      }));
    } catch (e) {
      console.error('Failed to roll live in card:', genId, e);
    } finally {
      setRollingId(null);
    }
  };

  const filtered = useMemo(() => {
    return generatorsData.filter((gen) => {
      const matchesCategory =
        selectedCategory === 'all' || gen.category === selectedCategory;
      if (!matchesCategory) return false;

      if (!searchQuery.trim()) return true;
      const query = searchQuery.toLowerCase();
      return (
        gen.name.toLowerCase().includes(query) ||
        gen.flag.toLowerCase().includes(query) ||
        gen.category.toLowerCase().includes(query) ||
        gen.categoryName.toLowerCase().includes(query) ||
        gen.description.toLowerCase().includes(query) ||
        (gen.aliases && gen.aliases.some((a) => a.toLowerCase().includes(query)))
      );
    });
  }, [selectedCategory, searchQuery]);

  const displayedGenerators = useMemo(() => {
    return filtered.slice(0, displayLimit);
  }, [filtered, displayLimit]);

  const copyFlag = (flag, id) => {
    navigator.clipboard.writeText(`namgen ${flag}`);
    setCopiedId(id);
    setTimeout(() => setCopiedId(null), 1800);
  };

  return (
    <section id="generators" className="py-20 bg-slate-950 border-b border-slate-800">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div className="text-center max-w-3xl mx-auto mb-12">
          <div className="inline-flex items-center gap-2 px-3 py-1 rounded-full text-xs font-semibold bg-emerald-500/10 text-emerald-400 border border-emerald-500/30 mb-3">
            <span>Directory of 907 Modules</span>
          </div>
          <h2 className="text-3xl sm:text-4xl font-extrabold text-white tracking-tight">
            Specialized Procedural Generators
          </h2>
          <p className="mt-4 text-slate-300">
            Search and explore all 907 C++17 procedural name generator modules. Every module is compiled with zero runtime heap allocation into <code className="text-emerald-400">.rodata</code>.
          </p>
        </div>

        {/* Search & Category Filter Bar */}
        <div className="space-y-4 mb-10 max-w-5xl mx-auto">
          {/* Search Input */}
          <div className="relative">
            <div className="absolute inset-y-0 left-0 pl-4 flex items-center pointer-events-none text-slate-400">
              <svg className="w-5 h-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                <path strokeLinecap="round" strokeLinejoin="round" strokeWidth={2} d="M21 21l-6-6m2-5a7 7 0 11-14 0 7 7 0 0114 0z" />
              </svg>
            </div>
            <input
              type="text"
              value={searchQuery}
              onChange={(e) => {
                setSearchQuery(e.target.value);
                setDisplayLimit(48);
              }}
              placeholder="Search 907 generators by name, flag, universe, or category (e.g. sith, elf, sword, pokemon, japan)..."
              className="w-full pl-11 pr-4 py-3.5 bg-slate-900 border border-slate-800 rounded-xl text-slate-100 placeholder-slate-500 text-sm focus:outline-none focus:border-emerald-500 shadow-xl"
            />
            {searchQuery && (
              <button
                type="button"
                onClick={() => setSearchQuery('')}
                className="absolute inset-y-0 right-0 pr-4 flex items-center text-slate-400 hover:text-white text-xs"
              >
                Clear
              </button>
            )}
          </div>

          {/* Category Filter Pills */}
          <div className="flex flex-wrap gap-1.5 justify-center max-h-36 overflow-y-auto p-1 scrollbar-none">
            <button
              type="button"
              onClick={() => {
                setSelectedCategory('all');
                setDisplayLimit(48);
              }}
              className={`px-3 py-1.5 rounded-lg text-xs font-medium transition-all ${
                selectedCategory === 'all'
                  ? 'bg-emerald-500 text-slate-950 font-bold shadow'
                  : 'bg-slate-900 text-slate-400 border border-slate-800 hover:text-white hover:border-slate-700'
              }`}
            >
              All Categories ({generatorsData.length})
            </button>
            {categoriesData.map((cat) => (
              <button
                key={cat.id}
                type="button"
                onClick={() => {
                  setSelectedCategory(cat.id);
                  setDisplayLimit(48);
                }}
                className={`px-3 py-1.5 rounded-lg text-xs font-medium transition-all whitespace-nowrap ${
                  selectedCategory === cat.id
                    ? 'bg-emerald-500 text-slate-950 font-bold shadow'
                    : 'bg-slate-900 text-slate-400 border border-slate-800 hover:text-white hover:border-slate-700'
                }`}
              >
                {cat.name} ({cat.count})
              </button>
            ))}
          </div>
        </div>

        {/* Results Count & Current Filter */}
        <div className="flex items-center justify-between text-xs text-slate-400 mb-6 px-1">
          <div>
            Showing <strong className="text-white">{displayedGenerators.length}</strong> of{' '}
            <strong className="text-emerald-400">{filtered.length}</strong> matching generators
            {selectedCategory !== 'all' && (
              <span> in <strong className="text-white">{categoriesData.find(c => c.id === selectedCategory)?.name}</strong></span>
            )}
          </div>
          {filtered.length > displayLimit && (
            <button
              type="button"
              onClick={() => setDisplayLimit((prev) => prev + 48)}
              className="text-emerald-400 hover:underline font-semibold"
            >
              Load more +
            </button>
          )}
        </div>

        {/* Generator Cards Grid */}
        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-5">
          {displayedGenerators.map((gen) => (
            <div
              key={gen.id}
              className="deferred-generator-card flex flex-col justify-between p-5 rounded-2xl bg-slate-900/70 border border-slate-800/80 hover:border-slate-700 hover:bg-slate-900 transition-all shadow-md group"
            >
              <div>
                {/* Header: Title and Category badge */}
                <div className="flex items-start justify-between gap-2 mb-2">
                  <h3 className="font-bold text-white text-base group-hover:text-emerald-400 transition-colors">
                    {gen.name}
                  </h3>
                  <span className="text-[10px] px-2 py-0.5 rounded-full bg-slate-800 text-slate-300 border border-slate-700/60 font-medium whitespace-nowrap">
                    {gen.category}
                  </span>
                </div>

                {/* Flag bar with 1-click copy */}
                <div className="flex items-center justify-between gap-2 p-2 rounded-lg bg-slate-950/80 border border-slate-800/80 font-mono text-xs text-emerald-400 mb-3">
                  <span className="truncate">{gen.flag}</span>
                  <button
                    type="button"
                    onClick={() => copyFlag(gen.flag, gen.id)}
                    className="flex-shrink-0 px-2 py-0.5 rounded text-[11px] font-sans font-medium bg-slate-800 hover:bg-slate-700 text-slate-200 transition-colors"
                  >
                    {copiedId === gen.id ? 'Copied!' : 'Copy'}
                  </button>
                </div>

                {/* Aliases if present */}
                {gen.aliases && gen.aliases.length > 0 && (
                  <div className="text-[11px] text-slate-400 mb-2 font-mono">
                    <span className="text-slate-500">Aliases: </span>
                    {gen.aliases.map((a) => `--${a}`).join(', ')}
                  </div>
                )}

                {/* Description */}
                <p className="text-xs text-slate-400 line-clamp-2 mb-3">
                  {gen.description}
                </p>
              </div>

              {/* Sample / Live Output preview */}
              <div className="pt-3 border-t border-slate-800/60">
                <div className="flex items-center justify-between text-[10px] uppercase font-bold text-slate-400 tracking-wider mb-1.5">
                  <span className={liveOutputs[gen.id] ? "text-emerald-400" : ""}>
                    {liveOutputs[gen.id] ? "⚡ Live Output" : "Sample Output"}
                  </span>
                  <button
                    type="button"
                    onClick={() => rollCardLive(gen.id)}
                    disabled={rollingId === gen.id}
                    className="text-[11px] font-sans font-medium text-emerald-400 hover:text-emerald-300 disabled:opacity-50 transition-colors"
                  >
                    {rollingId === gen.id ? "Rolling..." : "⚡ Roll Live"}
                  </button>
                </div>
                <div className="p-2.5 rounded-lg bg-slate-950/60 border border-slate-800/40 text-xs text-slate-300 font-sans space-y-1">
                  {(liveOutputs[gen.id] || (gen.samples && gen.samples.length > 0 ? gen.samples.slice(0, 2) : ['Generated instance'])).map((s, i) => (
                    <div key={i} className="truncate text-slate-200">
                      • {s}
                    </div>
                  ))}
                </div>
                <div className="mt-2 flex justify-end">
                  <a
                    href={`?gen=${gen.id}#simulator`}
                    className="text-[11px] font-semibold text-emerald-400 hover:text-emerald-300 transition-colors"
                  >
                    Full Simulator →
                  </a>
                </div>
              </div>
            </div>
          ))}
        </div>

        {/* Empty State */}
        {filtered.length === 0 && (
          <div className="text-center py-16 p-8 rounded-2xl bg-slate-900 border border-slate-800 max-w-lg mx-auto">
            <div className="text-4xl mb-3">🔍</div>
            <h3 className="text-lg font-bold text-white mb-1">No generators found</h3>
            <p className="text-sm text-slate-400 mb-4">
              No generators match your query "{searchQuery}". Try searching for another universe or topic.
            </p>
            <button
              type="button"
              onClick={() => {
                setSearchQuery('');
                setSelectedCategory('all');
              }}
              className="px-4 py-2 rounded-lg bg-emerald-500 text-slate-950 text-xs font-bold"
            >
              Reset Filters
            </button>
          </div>
        )}

        {/* Load More Button */}
        {filtered.length > displayLimit && (
          <div className="text-center mt-12">
            <button
              type="button"
              onClick={() => setDisplayLimit((prev) => prev + 48)}
              className="px-8 py-3 rounded-xl bg-slate-900 hover:bg-slate-800 text-white font-semibold text-sm border border-slate-700 hover:border-slate-600 transition-all shadow-lg"
            >
              Load 48 More Generators ({filtered.length - displayLimit} remaining)
            </button>
          </div>
        )}
      </div>
    </section>
  );
}
