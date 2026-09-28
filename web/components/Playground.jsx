'use client';

import React, { useState, useEffect } from 'react';
import wordsData from '../data/words.json';
import generatorsData from '../data/generators.json';

export default function Playground() {
  const [activeTab, setActiveTab] = useState('combinator'); // 'combinator' | 'procedural'

  // Combinator state
  const [separator, setSeparator] = useState('-');
  const [nullSeparator, setNullSeparator] = useState(false);
  const [casing, setCasing] = useState('normal'); // 'normal' | 'cap' | 'camel'
  const [exclude, setExclude] = useState("-'");
  const [count, setCount] = useState(5);
  const [combinatorResults, setCombinatorResults] = useState([]);

  // Procedural state
  const [selectedGenId, setSelectedGenId] = useState('descriptions-pokemons');
  const [proceduralResults, setProceduralResults] = useState([]);
  const [searchTerm, setSearchTerm] = useState('');
  const [copiedCmd, setCopiedCmd] = useState(false);

  // Generate Combinator names
  const generateCombinations = () => {
    const { adjectives, nouns } = wordsData;
    const results = [];
    const excludeSet = new Set(exclude.split(''));

    const filterWord = (w) => {
      return w.split('').filter((c) => !excludeSet.has(c)).join('');
    };

    for (let i = 0; i < count; i++) {
      let adj = adjectives[Math.floor(Math.random() * adjectives.length)] || 'silent';
      let noun = nouns[Math.floor(Math.random() * nouns.length)] || 'forest';

      adj = filterWord(adj);
      noun = filterWord(noun);

      if (casing === 'cap') {
        adj = adj.charAt(0).toUpperCase() + adj.slice(1);
        noun = noun.charAt(0).toUpperCase() + noun.slice(1);
      } else if (casing === 'camel') {
        adj = adj.toLowerCase();
        noun = noun.charAt(0).toUpperCase() + noun.slice(1);
      } else {
        adj = adj.toLowerCase();
        noun = noun.toLowerCase();
      }

      const sep = nullSeparator ? '' : separator;
      results.push(`${adj}${sep}${noun}`);
    }
    setCombinatorResults(results);
  };

  // Find currently selected generator
  const currentGen = generatorsData.find((g) => g.id === selectedGenId) || generatorsData[0];

  // Roll Procedural names
  const rollProcedural = () => {
    if (!currentGen) return;
    // Pick 1-3 samples
    if (currentGen.samples && currentGen.samples.length > 0) {
      setProceduralResults(currentGen.samples);
    } else {
      setProceduralResults(['Generated sample instance']);
    }
  };

  useEffect(() => {
    generateCombinations();
  }, [separator, nullSeparator, casing, exclude, count]);

  useEffect(() => {
    rollProcedural();
  }, [selectedGenId]);

  // Construct CLI command for current state
  const getCombinatorCommand = () => {
    let cmd = 'namgen';
    if (count !== 24) cmd += ` -c ${count}`;
    if (nullSeparator) cmd += ' -x';
    else if (separator !== '-') cmd += ` -s "${separator}"`;
    if (casing === 'cap') cmd += ' --cap';
    if (casing === 'camel') cmd += ' --camel';
    if (exclude !== "-'") cmd += ` -e "${exclude}"`;
    return cmd;
  };

  const getProceduralCommand = () => {
    return `namgen ${currentGen.flag} -c ${count}`;
  };

  const copyCommand = (cmdText) => {
    navigator.clipboard.writeText(cmdText);
    setCopiedCmd(true);
    setTimeout(() => setCopiedCmd(false), 2000);
  };

  // Filtered generators list for quick selector
  const filteredGenerators = searchTerm
    ? generatorsData.filter(
        (g) =>
          g.name.toLowerCase().includes(searchTerm.toLowerCase()) ||
          g.category.toLowerCase().includes(searchTerm.toLowerCase()) ||
          g.flag.toLowerCase().includes(searchTerm.toLowerCase())
      ).slice(0, 50)
    : generatorsData.slice(0, 50);

  return (
    <section id="simulator" className="py-16 bg-slate-900/50 border-b border-slate-800">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div className="text-center max-w-3xl mx-auto mb-10">
          <h2 className="text-xs uppercase font-bold tracking-wider text-emerald-400">Interactive Playground</h2>
          <p className="mt-2 text-3xl font-extrabold text-white">Experience namgen in Your Browser</p>
          <p className="mt-3 text-slate-300">
            Test adjective-noun combinatorics with real-time casing controls, or sample output from 907 specialized procedural generators.
          </p>
        </div>

        {/* Tab switcher */}
        <div className="flex justify-center mb-8">
          <div className="inline-flex p-1 rounded-xl bg-slate-900 border border-slate-800 shadow-inner">
            <button
              type="button"
              onClick={() => setActiveTab('combinator')}
              className={`px-5 py-2 rounded-lg text-sm font-semibold transition-all ${
                activeTab === 'combinator'
                  ? 'bg-emerald-500 text-slate-950 shadow'
                  : 'text-slate-400 hover:text-white'
              }`}
            >
              1. Adjective + Noun Combinator
            </button>
            <button
              type="button"
              onClick={() => setActiveTab('procedural')}
              className={`px-5 py-2 rounded-lg text-sm font-semibold transition-all ${
                activeTab === 'procedural'
                  ? 'bg-emerald-500 text-slate-950 shadow'
                  : 'text-slate-400 hover:text-white'
              }`}
            >
              2. 907 Universe Generators Explorer
            </button>
          </div>
        </div>

        {/* Tab 1: Combinator */}
        {activeTab === 'combinator' && (
          <div className="grid grid-cols-1 lg:grid-cols-12 gap-8 items-start">
            {/* Controls Panel */}
            <div className="lg:col-span-5 p-6 rounded-2xl bg-slate-900 border border-slate-800 shadow-xl space-y-6">
              <h3 className="text-lg font-bold text-white flex items-center justify-between">
                <span>Combinator Options</span>
                <button
                  type="button"
                  onClick={generateCombinations}
                  className="text-xs font-semibold px-2.5 py-1 rounded-md bg-emerald-500/10 text-emerald-400 border border-emerald-500/30 hover:bg-emerald-500/20 transition-colors"
                >
                  ⚡ Re-roll
                </button>
              </h3>

              {/* Separator Controls */}
              <div>
                <label className="block text-xs font-semibold uppercase text-slate-400 mb-2">
                  Separator Character
                </label>
                <div className="grid grid-cols-4 gap-2">
                  {['-', '_', '.', ' '].map((sep) => (
                    <button
                      key={sep}
                      type="button"
                      disabled={nullSeparator}
                      onClick={() => setSeparator(sep)}
                      className={`px-3 py-1.5 text-xs font-mono rounded-lg border transition-all ${
                        separator === sep && !nullSeparator
                          ? 'bg-emerald-500/20 border-emerald-500 text-emerald-300 font-bold'
                          : 'bg-slate-800 border-slate-700 text-slate-300 hover:border-slate-600'
                      } ${nullSeparator ? 'opacity-40 cursor-not-allowed' : ''}`}
                    >
                      {sep === ' ' ? 'Space' : sep}
                    </button>
                  ))}
                </div>
                <div className="mt-3 flex items-center gap-2">
                  <input
                    type="checkbox"
                    id="nullSep"
                    checked={nullSeparator}
                    onChange={(e) => setNullSeparator(e.target.checked)}
                    className="w-4 h-4 rounded border-slate-700 text-emerald-500 focus:ring-emerald-400 bg-slate-800"
                  />
                  <label htmlFor="nullSep" className="text-xs text-slate-300 select-none cursor-pointer">
                    Null Separator (<code className="text-emerald-400">-x</code> / concatenate words)
                  </label>
                </div>
              </div>

              {/* Casing Controls */}
              <div>
                <label className="block text-xs font-semibold uppercase text-slate-400 mb-2">
                  Casing Style
                </label>
                <div className="grid grid-cols-3 gap-2">
                  <button
                    type="button"
                    onClick={() => setCasing('normal')}
                    className={`px-3 py-1.5 text-xs rounded-lg border transition-all ${
                      casing === 'normal'
                        ? 'bg-emerald-500/20 border-emerald-500 text-emerald-300 font-bold'
                        : 'bg-slate-800 border-slate-700 text-slate-300 hover:border-slate-600'
                    }`}
                  >
                    normal
                  </button>
                  <button
                    type="button"
                    onClick={() => setCasing('cap')}
                    className={`px-3 py-1.5 text-xs rounded-lg border transition-all ${
                      casing === 'cap'
                        ? 'bg-emerald-500/20 border-emerald-500 text-emerald-300 font-bold'
                        : 'bg-slate-800 border-slate-700 text-slate-300 hover:border-slate-600'
                    }`}
                  >
                    --cap (Pascal)
                  </button>
                  <button
                    type="button"
                    onClick={() => setCasing('camel')}
                    className={`px-3 py-1.5 text-xs rounded-lg border transition-all ${
                      casing === 'camel'
                        ? 'bg-emerald-500/20 border-emerald-500 text-emerald-300 font-bold'
                        : 'bg-slate-800 border-slate-700 text-slate-300 hover:border-slate-600'
                    }`}
                  >
                    --camel (camelCase)
                  </button>
                </div>
              </div>

              {/* Exclude Characters */}
              <div>
                <label className="block text-xs font-semibold uppercase text-slate-400 mb-2">
                  Exclude Characters (<code className="text-emerald-400">-e</code>)
                </label>
                <input
                  type="text"
                  value={exclude}
                  onChange={(e) => setExclude(e.target.value)}
                  className="w-full px-3 py-2 bg-slate-800 border border-slate-700 rounded-lg text-sm text-slate-100 font-mono focus:outline-none focus:border-emerald-500"
                  placeholder="Chars to strip (e.g. -')"
                />
              </div>

              {/* Count Slider */}
              <div>
                <div className="flex justify-between text-xs font-semibold uppercase text-slate-400 mb-2">
                  <span>Count (<code className="text-emerald-400">-c</code>)</span>
                  <span className="text-emerald-400 font-mono">{count} names</span>
                </div>
                <input
                  type="range"
                  min="1"
                  max="15"
                  value={count}
                  onChange={(e) => setCount(parseInt(e.target.value, 10))}
                  className="w-full h-2 bg-slate-800 rounded-lg appearance-none cursor-pointer accent-emerald-500"
                />
              </div>
            </div>

            {/* Terminal Preview Panel */}
            <div className="lg:col-span-7">
              <div className="rounded-2xl bg-slate-950 border border-slate-800 overflow-hidden shadow-2xl">
                {/* Terminal Header */}
                <div className="flex items-center justify-between px-4 py-3 bg-slate-900 border-b border-slate-800">
                  <div className="flex items-center gap-2">
                    <span className="w-3 h-3 rounded-full bg-red-500/80" />
                    <span className="w-3 h-3 rounded-full bg-yellow-500/80" />
                    <span className="w-3 h-3 rounded-full bg-green-500/80" />
                    <span className="ml-2 text-xs font-mono text-slate-400">namgen - bash terminal</span>
                  </div>
                  <button
                    type="button"
                    onClick={() => copyCommand(getCombinatorCommand())}
                    className="inline-flex items-center gap-1.5 px-2.5 py-1 text-xs font-medium rounded-md bg-slate-800 hover:bg-slate-700 text-slate-300 border border-slate-700 transition-colors"
                  >
                    {copiedCmd ? 'Copied!' : 'Copy CLI Command'}
                  </button>
                </div>

                {/* Terminal Body */}
                <div className="p-5 font-mono text-sm space-y-3">
                  <div className="flex items-center gap-2 text-emerald-400">
                    <span className="select-none text-slate-500">$</span>
                    <span className="text-slate-100">{getCombinatorCommand()}</span>
                  </div>
                  <div className="pt-2 text-slate-200 space-y-1">
                    {combinatorResults.map((name, i) => (
                      <div key={i} className="hover:text-emerald-300 transition-colors flex items-center gap-3">
                        <span className="text-slate-600 select-none text-xs w-5 text-right">{i + 1}</span>
                        <span>{name}</span>
                      </div>
                    ))}
                  </div>
                </div>
              </div>
            </div>
          </div>
        )}

        {/* Tab 2: Procedural Generator Explorer */}
        {activeTab === 'procedural' && (
          <div className="grid grid-cols-1 lg:grid-cols-12 gap-8 items-start">
            {/* Generator Picker Panel */}
            <div className="lg:col-span-5 p-6 rounded-2xl bg-slate-900 border border-slate-800 shadow-xl space-y-5">
              <h3 className="text-lg font-bold text-white">Select a Procedural Generator</h3>

              {/* Search input */}
              <div className="relative">
                <input
                  type="text"
                  value={searchTerm}
                  onChange={(e) => setSearchTerm(e.target.value)}
                  placeholder="Filter 907 generators (e.g. pokemon, sith, sword)..."
                  className="w-full px-3.5 py-2.5 bg-slate-800 border border-slate-700 rounded-lg text-sm text-slate-100 placeholder-slate-500 focus:outline-none focus:border-emerald-500"
                />
              </div>

              {/* Scrollable list */}
              <div className="max-h-72 overflow-y-auto space-y-1.5 pr-1">
                {filteredGenerators.map((gen) => (
                  <button
                    key={gen.id}
                    type="button"
                    onClick={() => setSelectedGenId(gen.id)}
                    className={`w-full text-left p-2.5 rounded-lg text-xs transition-all flex items-center justify-between ${
                      selectedGenId === gen.id
                        ? 'bg-emerald-500/20 border border-emerald-500 text-emerald-300 font-semibold'
                        : 'bg-slate-800/80 hover:bg-slate-800 text-slate-300 border border-transparent'
                    }`}
                  >
                    <div>
                      <div className="font-semibold text-slate-100">{gen.name}</div>
                      <div className="text-[11px] text-slate-400 font-mono">{gen.flag}</div>
                    </div>
                    <span className="text-[10px] px-2 py-0.5 rounded bg-slate-900 text-slate-400 border border-slate-800">
                      {gen.category}
                    </span>
                  </button>
                ))}
              </div>

              <div className="pt-2 border-t border-slate-800 flex items-center justify-between text-xs text-slate-400">
                <span>Showing {filteredGenerators.length} of 907 generators</span>
                <a href="#generators" className="text-emerald-400 hover:underline">
                  Browse all 907 →
                </a>
              </div>
            </div>

            {/* Generator Output Preview */}
            <div className="lg:col-span-7">
              <div className="rounded-2xl bg-slate-950 border border-slate-800 overflow-hidden shadow-2xl">
                {/* Terminal Header */}
                <div className="flex items-center justify-between px-4 py-3 bg-slate-900 border-b border-slate-800">
                  <div className="flex items-center gap-2">
                    <span className="w-3 h-3 rounded-full bg-red-500/80" />
                    <span className="w-3 h-3 rounded-full bg-yellow-500/80" />
                    <span className="w-3 h-3 rounded-full bg-green-500/80" />
                    <span className="ml-2 text-xs font-mono text-slate-400">
                      namgen {currentGen.flag}
                    </span>
                  </div>
                  <button
                    type="button"
                    onClick={() => copyCommand(getProceduralCommand())}
                    className="inline-flex items-center gap-1.5 px-2.5 py-1 text-xs font-medium rounded-md bg-slate-800 hover:bg-slate-700 text-slate-300 border border-slate-700 transition-colors"
                  >
                    {copiedCmd ? 'Copied!' : 'Copy Flag'}
                  </button>
                </div>

                {/* Terminal Body */}
                <div className="p-6 font-mono text-sm space-y-4">
                  <div className="flex items-center gap-2 text-emerald-400">
                    <span className="select-none text-slate-500">$</span>
                    <span className="text-slate-100">{getProceduralCommand()}</span>
                  </div>

                  <div className="p-4 rounded-xl bg-slate-900/90 border border-slate-800/80 text-slate-200 leading-relaxed font-sans text-sm whitespace-pre-wrap">
                    {proceduralResults.map((sample, idx) => (
                      <div key={idx} className="py-1 border-b border-slate-800/50 last:border-0 font-medium">
                        {sample}
                      </div>
                    ))}
                  </div>

                  <div className="pt-2 text-xs text-slate-400 font-sans flex items-center justify-between">
                    <div>
                      <strong className="text-slate-200">Category:</strong> {currentGen.categoryName} ({currentGen.category})
                    </div>
                    <div className="text-emerald-400 font-mono">Zero Heap Allocations</div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        )}
      </div>
    </section>
  );
}
