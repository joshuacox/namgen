'use client';

import React, { useState, useEffect } from 'react';
import wordsData from '../data/words.json';
import generatorsData from '../data/generators.json';
import { loadGenerator, executeGenerator } from '../lib/generatorLoader';

export default function Playground() {
  const [activeTab, setActiveTab] = useState('combinator'); // 'combinator' | 'procedural'

  // Engine selection (WASM vs JS)
  const [engine, setEngine] = useState('wasm'); // 'wasm' | 'js'
  const [wasmInstance, setWasmInstance] = useState(null);
  const [execMetrics, setExecMetrics] = useState({ timeMs: 0, count: 5, engine: 'wasm' });

  // Common CLI options
  const [count, setCount] = useState(5);
  const [seed, setSeed] = useState('');
  const [unique, setUnique] = useState(false);
  const [format, setFormat] = useState('plain'); // 'plain' | 'json' | 'csv' | 'slug'
  const [matchRegex, setMatchRegex] = useState('');
  const [copiedCmd, setCopiedCmd] = useState(false);
  const [copiedLink, setCopiedLink] = useState(false);

  // Favorites state
  const [favorites, setFavorites] = useState([]);
  const [showFavorites, setShowFavorites] = useState(false);

  // Combinator state
  const [separator, setSeparator] = useState('-');
  const [nullSeparator, setNullSeparator] = useState(false);
  const [casing, setCasing] = useState('normal'); // 'normal' | 'cap' | 'camel'
  const [exclude, setExclude] = useState("-'");
  const [combinatorResults, setCombinatorResults] = useState([]);

  // Procedural state
  const [selectedGenId, setSelectedGenId] = useState('descriptions-pokemons');
  const [proceduralResults, setProceduralResults] = useState([]);
  const [searchTerm, setSearchTerm] = useState('');
  const [loadingGen, setLoadingGen] = useState(false);

  // Load favorites from localStorage
  useEffect(() => {
    try {
      const saved = localStorage.getItem('namgen_favorites');
      if (saved) setFavorites(JSON.parse(saved));
    } catch (_) {}
  }, []);

  const toggleFavorite = (name) => {
    if (!name || name === '(No matching names found)') return;
    setFavorites((prev) => {
      const next = prev.includes(name) ? prev.filter((x) => x !== name) : [...prev, name];
      try {
        localStorage.setItem('namgen_favorites', JSON.stringify(next));
      } catch (_) {}
      return next;
    });
  };

  const exportFavorites = (type) => {
    let content = '';
    let mime = 'text/plain';
    let filename = 'namgen-favorites.txt';
    if (type === 'json') {
      content = JSON.stringify(favorites, null, 2);
      mime = 'application/json';
      filename = 'namgen-favorites.json';
    } else if (type === 'csv') {
      content = '"name"\n' + favorites.map((n) => `"${n.replace(/"/g, '""')}"`).join('\n');
      mime = 'text/csv';
      filename = 'namgen-favorites.csv';
    } else {
      content = favorites.join('\n');
    }
    const blob = new Blob([content], { type: mime });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = filename;
    a.click();
    URL.revokeObjectURL(url);
  };

  // Initialize WebAssembly engine on mount
  useEffect(() => {
    let isMounted = true;
    async function initWasm() {
      try {
        if (!window.createNamgen) {
          const script = document.createElement('script');
          script.src = '/wasm/namgen.js';
          script.async = true;
          document.body.appendChild(script);
          await new Promise((res, rej) => {
            script.onload = res;
            script.onerror = rej;
          });
        }
        if (window.createNamgen && isMounted) {
          const inst = await window.createNamgen({
            locateFile: (f) => `/wasm/${f}`,
            noInitialRun: true,
          });
          if (isMounted) setWasmInstance(inst);
        }
      } catch (err) {
        console.warn('WASM module load warning in Playground:', err);
      }
    }
    initWasm();
    return () => { isMounted = false; };
  }, []);

  // Handle URL deep-linking on mount
  useEffect(() => {
    if (typeof window !== 'undefined') {
      const params = new URLSearchParams(window.location.search);
      const genParam = params.get('gen');
      const tabParam = params.get('tab');
      const countParam = params.get('c') || params.get('count');
      const seedParam = params.get('seed') || params.get('S');
      const formatParam = params.get('format');
      const uniqueParam = params.get('unique') || params.get('u');

      if (genParam) {
        const found = generatorsData.find(
          (g) => g.id === genParam || g.flag === `--${genParam}` || g.flag === genParam
        );
        if (found) {
          setSelectedGenId(found.id);
          setActiveTab('procedural');
        }
      } else if (tabParam === 'procedural' || tabParam === 'combinator') {
        setActiveTab(tabParam);
      }

      if (countParam) {
        const parsed = parseInt(countParam, 10);
        if (!isNaN(parsed) && parsed > 0 && parsed <= 30) {
          setCount(parsed);
        }
      }
      if (seedParam) {
        setSeed(seedParam);
      }
      if (formatParam && ['plain', 'json', 'csv', 'slug'].includes(formatParam)) {
        setFormat(formatParam);
      }
      if (uniqueParam === 'true' || uniqueParam === '1') {
        setUnique(true);
      }
    }
  }, []);

  // Simple deterministic PRNG for seeded simulation in UI
  const createSeededRandom = (seedStr) => {
    if (!seedStr) return Math.random;
    let s = 0;
    for (let i = 0; i < seedStr.length; i++) {
      s = (s * 31 + seedStr.charCodeAt(i)) >>> 0;
    }
    return () => {
      s = (1664525 * s + 1013904223) >>> 0;
      return s / 4294967296;
    };
  };

  const toSlug = (str) => {
    return str
      .toLowerCase()
      .replace(/[^a-z0-9]+/g, '-')
      .replace(/^-+|-+$/g, '');
  };

  // Generate Combinator names live
  const generateCombinations = () => {
    const { adjectives, nouns } = wordsData;
    const results = [];
    const seen = new Set();
    const excludeSet = new Set(exclude.split(''));
    const rng = createSeededRandom(seed);

    const filterWord = (w) => {
      return w.split('').filter((c) => !excludeSet.has(c)).join('');
    };

    let attempts = 0;
    while (results.length < count && attempts < count * 50 + 200) {
      attempts++;
      let adj = adjectives[Math.floor(rng() * adjectives.length)] || 'silent';
      let noun = nouns[Math.floor(rng() * nouns.length)] || 'forest';

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
      let finalName = `${adj}${sep}${noun}`;
      if (unique) {
        if (!seen.has(finalName)) {
          seen.add(finalName);
          results.push(finalName);
        }
      } else {
        results.push(finalName);
      }
    }
    setCombinatorResults(results);
  };

  // Find currently selected generator
  const currentGen = generatorsData.find((g) => g.id === selectedGenId) || generatorsData[0];

  // Execute either WebAssembly Engine or JavaScript Generator
  const rollProcedural = async () => {
    if (!currentGen) return;
    setLoadingGen(true);
    const start = performance.now();
    try {
      let liveNames = [];
      if (engine === 'wasm' && wasmInstance) {
        const genWasm = wasmInstance.cwrap('namgen_generate_wasm', 'string', ['string', 'number']);
        const seedNum = seed ? parseInt(seed, 10) || 1 : 0;
        const seen = new Set();
        let attempts = 0;
        while (liveNames.length < count && attempts < count * 200 + 1000) {
          attempts++;
          const currentSeed = seedNum ? (seedNum + attempts) : 0;
          const name = genWasm(currentGen.flag, currentSeed);
          if (!name || name.startsWith('Error:')) break;
          if (matchRegex) {
            try {
              const re = new RegExp(matchRegex);
              if (!re.test(name)) continue;
            } catch (_) {}
          }
          if (unique) {
            if (!seen.has(name)) {
              seen.add(name);
              liveNames.push(name);
            }
          } else {
            liveNames.push(name);
          }
        }
      } else {
        const genFn = await loadGenerator(currentGen.id);
        let names = executeGenerator(genFn, count * 3, { seed, unique });
        if (matchRegex) {
          try {
            const re = new RegExp(matchRegex);
            names = names.filter((n) => re.test(n));
          } catch (_) {}
        }
        liveNames = names.slice(0, count);
      }
      const elapsed = Math.max(0.01, performance.now() - start);
      setExecMetrics({ timeMs: elapsed, count: liveNames.length, engine });
      setProceduralResults(liveNames.length > 0 ? liveNames : ['(No matching names found)']);
    } catch (err) {
      console.warn('Procedural roll fallback:', err);
      let samples = currentGen.samples || ['Sample name'];
      if (unique) samples = Array.from(new Set(samples));
      setProceduralResults(samples.slice(0, count));
    } finally {
      setLoadingGen(false);
    }
  };

  useEffect(() => {
    generateCombinations();
  }, [separator, nullSeparator, casing, exclude, count, seed, unique]);

  useEffect(() => {
    rollProcedural();
  }, [selectedGenId, count, seed, unique, engine, wasmInstance, matchRegex]);

  // Construct CLI command for current state
  const getCombinatorCommand = () => {
    let cmd = 'namgen';
    if (count !== 24) cmd += ` -c ${count}`;
    if (seed) cmd += ` -S ${seed}`;
    if (unique) cmd += ' -u';
    if (format === 'json') cmd += ' --json';
    else if (format === 'csv') cmd += ' --csv';
    else if (format === 'slug') cmd += ' --slug';
    if (nullSeparator) cmd += ' -x';
    else if (separator !== '-') cmd += ` -s "${separator}"`;
    if (casing === 'cap') cmd += ' --cap';
    if (casing === 'camel') cmd += ' --camel';
    if (exclude !== "-'") cmd += ` -e "${exclude}"`;
    return cmd;
  };

  const getProceduralCommand = () => {
    let cmd = `namgen ${currentGen.flag} -c ${count}`;
    if (seed) cmd += ` -S ${seed}`;
    if (unique) cmd += ' -u';
    if (matchRegex) cmd += ` -m "${matchRegex}"`;
    if (format === 'json') cmd += ' --json';
    else if (format === 'csv') cmd += ' --csv';
    else if (format === 'slug') cmd += ' --slug';
    return cmd;
  };

  const copyCommand = (cmdText) => {
    navigator.clipboard.writeText(cmdText);
    setCopiedCmd(true);
    setTimeout(() => setCopiedCmd(false), 2000);
  };

  const shareLink = () => {
    if (typeof window === 'undefined') return;
    const url = new URL(window.location.href);
    url.searchParams.set('tab', activeTab);
    url.searchParams.set('c', count);
    if (activeTab === 'procedural') {
      url.searchParams.set('gen', selectedGenId);
    } else {
      url.searchParams.delete('gen');
    }
    if (seed) url.searchParams.set('seed', seed);
    else url.searchParams.delete('seed');
    if (format !== 'plain') url.searchParams.set('format', format);
    else url.searchParams.delete('format');
    if (unique) url.searchParams.set('unique', 'true');
    else url.searchParams.delete('unique');

    navigator.clipboard.writeText(url.toString());
    setCopiedLink(true);
    setTimeout(() => setCopiedLink(false), 2000);
  };

  // Render output formatted according to format selection
  const renderFormattedOutput = (rawList) => {
    if (format === 'json') {
      const items = rawList.map((n) => n);
      return (
        <pre className="text-emerald-300 font-mono text-xs overflow-x-auto p-2 bg-slate-950/70 rounded-lg">
          {JSON.stringify(items, null, 2)}
        </pre>
      );
    }
    if (format === 'csv') {
      return (
        <div className="font-mono text-xs text-emerald-300 space-y-0.5 p-2 bg-slate-950/70 rounded-lg">
          <div className="text-slate-400 font-bold">"name"</div>
          {rawList.map((n, i) => (
            <div key={i}>"{n.replace(/"/g, '""')}"</div>
          ))}
        </div>
      );
    }
    if (format === 'slug') {
      return (
        <div className="space-y-1 font-mono text-xs text-emerald-300">
          {rawList.map((n, i) => (
            <div key={i} className="py-0.5 border-b border-slate-800/40 last:border-0">
              {toSlug(n)}
            </div>
          ))}
        </div>
      );
    }
    return (
      <div className="space-y-1">
        {rawList.map((sample, idx) => (
          <div key={idx} className="py-1 border-b border-slate-800/50 last:border-0 font-medium text-slate-200 flex items-center justify-between group">
            <span>{sample}</span>
            {sample && sample !== '(No matching names found)' && (
              <button
                type="button"
                onClick={() => toggleFavorite(sample)}
                className={`p-1 text-xs rounded transition-all ${
                  favorites.includes(sample)
                    ? 'text-red-400 hover:text-red-300 scale-110'
                    : 'text-slate-600 hover:text-red-400 opacity-40 group-hover:opacity-100'
                }`}
                title={favorites.includes(sample) ? 'Remove favorite' : 'Save to favorites'}
              >
                {favorites.includes(sample) ? '❤️' : '🤍'}
              </button>
            )}
          </div>
        ))}
      </div>
    );
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
          <p className="mt-2 text-3xl font-extrabold text-white">Live In-Browser Name Engine</p>
          <p className="mt-3 text-slate-300">
            Running real procedural generators directly in your browser. Zero simulation—every click executes the actual JavaScript engine.
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
              2. 907 Live JavaScript Generators
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

              {/* Output Format Controls */}
              <div>
                <label className="block text-xs font-semibold uppercase text-slate-400 mb-2">
                  Output Format
                </label>
                <div className="grid grid-cols-4 gap-2">
                  {[
                    { id: 'plain', label: 'Plain' },
                    { id: 'json', label: 'JSON' },
                    { id: 'csv', label: 'CSV' },
                    { id: 'slug', label: 'Slug' },
                  ].map((fmt) => (
                    <button
                      key={fmt.id}
                      type="button"
                      onClick={() => setFormat(fmt.id)}
                      className={`px-2 py-1.5 text-xs rounded-lg border font-mono transition-all ${
                        format === fmt.id
                          ? 'bg-emerald-500/20 border-emerald-500 text-emerald-300 font-bold'
                          : 'bg-slate-800 border-slate-700 text-slate-300 hover:border-slate-600'
                      }`}
                    >
                      {fmt.label}
                    </button>
                  ))}
                </div>
              </div>

              {/* Advanced Flags (Seed & Unique) */}
              <div className="grid grid-cols-2 gap-3 pt-2 border-t border-slate-800">
                <div>
                  <label className="block text-xs font-semibold uppercase text-slate-400 mb-1">
                    Seed (<code className="text-emerald-400">-S</code>)
                  </label>
                  <input
                    type="text"
                    value={seed}
                    onChange={(e) => setSeed(e.target.value)}
                    placeholder="e.g. 42"
                    className="w-full px-2.5 py-1.5 bg-slate-800 border border-slate-700 rounded-lg text-xs text-slate-100 font-mono focus:outline-none focus:border-emerald-500"
                  />
                </div>
                <div className="flex flex-col justify-end">
                  <label className="flex items-center gap-2 cursor-pointer select-none py-1.5">
                    <input
                      type="checkbox"
                      checked={unique}
                      onChange={(e) => setUnique(e.target.checked)}
                      className="w-4 h-4 rounded border-slate-700 text-emerald-500 focus:ring-emerald-400 bg-slate-800"
                    />
                    <span className="text-xs text-slate-300">
                      Unique (<code className="text-emerald-400">-u</code>)
                    </span>
                  </label>
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
                  max="20"
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
                  <div className="flex items-center gap-2">
                    <button
                      type="button"
                      onClick={shareLink}
                      className="inline-flex items-center gap-1.5 px-2.5 py-1 text-xs font-medium rounded-md bg-slate-800 hover:bg-slate-700 text-slate-300 border border-slate-700 transition-colors"
                    >
                      {copiedLink ? 'Link Copied!' : '🔗 Share'}
                    </button>
                    <button
                      type="button"
                      onClick={() => copyCommand(getCombinatorCommand())}
                      className="inline-flex items-center gap-1.5 px-2.5 py-1 text-xs font-medium rounded-md bg-emerald-500/10 hover:bg-emerald-500/20 text-emerald-400 border border-emerald-500/30 transition-colors"
                    >
                      {copiedCmd ? 'Copied!' : 'Copy CLI Command'}
                    </button>
                  </div>
                </div>

                {/* Terminal Body */}
                <div className="p-5 font-mono text-sm space-y-3">
                  <div className="flex items-center gap-2 text-emerald-400">
                    <span className="select-none text-slate-500">$</span>
                    <span className="text-slate-100">{getCombinatorCommand()}</span>
                  </div>

                  <div className="p-4 rounded-xl bg-slate-900/90 border border-slate-800/80 text-slate-200 leading-relaxed font-sans text-sm">
                    {renderFormattedOutput(combinatorResults)}
                  </div>

                  <div className="text-xs text-slate-400 font-sans flex items-center justify-between pt-2 border-t border-slate-900">
                    <span>Live in-browser combinatorics: 42,000+ words</span>
                    <span className="text-emerald-400 font-mono">Instant Client Execution</span>
                  </div>
                </div>
              </div>
            </div>
          </div>
        )}

        {/* Tab 2: Procedural Generator Explorer */}
        {activeTab === 'procedural' && (
          <div className="grid grid-cols-1 lg:grid-cols-12 gap-8 items-start">
            {/* Quick Generator Selector */}
            <div className="lg:col-span-5 p-6 rounded-2xl bg-slate-900 border border-slate-800 shadow-xl space-y-4">
              <h3 className="text-lg font-bold text-white flex items-center justify-between">
                <span>Select Generator</span>
                <div className="flex items-center gap-2">
                  <button
                    type="button"
                    onClick={rollProcedural}
                    disabled={loadingGen}
                    className="text-xs font-semibold px-2.5 py-1 rounded-md bg-emerald-500/10 text-emerald-400 border border-emerald-500/30 hover:bg-emerald-500/20 transition-colors disabled:opacity-50"
                  >
                    {loadingGen ? '⏳ Generating...' : '⚡ Re-roll'}
                  </button>
                  <span className="text-xs text-emerald-400 font-mono">907 Available</span>
                </div>
              </h3>

              <div className="relative">
                <input
                  type="text"
                  value={searchTerm}
                  onChange={(e) => setSearchTerm(e.target.value)}
                  placeholder="Filter (e.g. pokemon, dragon, sith, elf)..."
                  className="w-full px-3 py-2 bg-slate-800 border border-slate-700 rounded-lg text-xs text-slate-100 placeholder-slate-500 focus:outline-none focus:border-emerald-500"
                />
              </div>

              {/* Execution Engine Selector */}
              <div>
                <label className="block text-xs font-semibold uppercase text-slate-400 mb-1.5">
                  Execution Engine
                </label>
                <div className="grid grid-cols-2 gap-2">
                  <button
                    type="button"
                    onClick={() => setEngine('wasm')}
                    className={`px-3 py-1.5 rounded-lg text-xs font-semibold border flex items-center justify-center gap-1.5 transition-all ${
                      engine === 'wasm'
                        ? 'bg-emerald-500/20 border-emerald-500 text-emerald-300 font-bold'
                        : 'bg-slate-800 border-slate-700 text-slate-400 hover:text-white'
                    }`}
                  >
                    <span>⚡ WebAssembly</span>
                    <span className="text-[10px] px-1 rounded bg-slate-900 text-slate-400">C++17</span>
                  </button>
                  <button
                    type="button"
                    onClick={() => setEngine('js')}
                    className={`px-3 py-1.5 rounded-lg text-xs font-semibold border flex items-center justify-center gap-1.5 transition-all ${
                      engine === 'js'
                        ? 'bg-emerald-500/20 border-emerald-500 text-emerald-300 font-bold'
                        : 'bg-slate-800 border-slate-700 text-slate-400 hover:text-white'
                    }`}
                  >
                    <span>📜 JavaScript</span>
                    <span className="text-[10px] px-1 rounded bg-slate-900 text-slate-400">ESM</span>
                  </button>
                </div>
              </div>

              {/* Output Format Controls for Procedural */}
              <div>
                <label className="block text-xs font-semibold uppercase text-slate-400 mb-1.5">
                  Output Format
                </label>
                <div className="grid grid-cols-4 gap-2">
                  {[
                    { id: 'plain', label: 'Plain' },
                    { id: 'json', label: 'JSON' },
                    { id: 'csv', label: 'CSV' },
                    { id: 'slug', label: 'Slug' },
                  ].map((fmt) => (
                    <button
                      key={fmt.id}
                      type="button"
                      onClick={() => setFormat(fmt.id)}
                      className={`px-2 py-1 text-xs rounded-lg border font-mono transition-all ${
                        format === fmt.id
                          ? 'bg-emerald-500/20 border-emerald-500 text-emerald-300 font-bold'
                          : 'bg-slate-800 border-slate-700 text-slate-300 hover:border-slate-600'
                      }`}
                    >
                      {fmt.label}
                    </button>
                  ))}
                </div>
              </div>

              {/* Count Slider for Procedural */}
              <div>
                <div className="flex justify-between text-xs font-semibold uppercase text-slate-400 mb-1">
                  <span>Batch Count (<code className="text-emerald-400">-c</code>)</span>
                  <span className="text-emerald-400 font-mono">{count} names</span>
                </div>
                <input
                  type="range"
                  min="1"
                  max="20"
                  value={count}
                  onChange={(e) => setCount(parseInt(e.target.value, 10))}
                  className="w-full h-2 bg-slate-800 rounded-lg appearance-none cursor-pointer accent-emerald-500"
                />
              </div>

              {/* Advanced Flags (Seed & Unique) */}
              <div className="grid grid-cols-2 gap-3 pt-2 border-t border-slate-800">
                <div>
                  <label className="block text-xs font-semibold uppercase text-slate-400 mb-1">
                    Seed (<code className="text-emerald-400">-S</code>)
                  </label>
                  <input
                    type="text"
                    value={seed}
                    onChange={(e) => setSeed(e.target.value)}
                    placeholder="e.g. 100"
                    className="w-full px-2.5 py-1.5 bg-slate-800 border border-slate-700 rounded-lg text-xs text-slate-100 font-mono focus:outline-none focus:border-emerald-500"
                  />
                </div>
                <div className="flex flex-col justify-end">
                  <label className="flex items-center gap-2 cursor-pointer select-none py-1.5">
                    <input
                      type="checkbox"
                      checked={unique}
                      onChange={(e) => setUnique(e.target.checked)}
                      className="w-4 h-4 rounded border-slate-700 text-emerald-500 focus:ring-emerald-400 bg-slate-800"
                    />
                    <span className="text-xs text-slate-300">
                      Unique (<code className="text-emerald-400">-u</code>)
                    </span>
                  </label>
                </div>
              </div>

              {/* Regex Filter */}
              <div>
                <label className="block text-xs font-semibold uppercase text-slate-400 mb-1">
                  Regex Filter (<code className="text-emerald-400">-m</code>)
                </label>
                <input
                  type="text"
                  value={matchRegex}
                  onChange={(e) => setMatchRegex(e.target.value)}
                  placeholder="e.g. ^[A-Z].*th$ (leave empty for none)"
                  className="w-full px-2.5 py-1.5 bg-slate-800 border border-slate-700 rounded-lg text-xs text-slate-100 font-mono focus:outline-none focus:border-emerald-500"
                />
              </div>

              <div className="max-h-72 overflow-y-auto space-y-1.5 pr-1 border border-slate-800 rounded-xl p-2 bg-slate-950/50">
                {filteredGenerators.map((gen) => (
                  <button
                    key={gen.id}
                    type="button"
                    onClick={() => setSelectedGenId(gen.id)}
                    className={`w-full text-left px-3 py-2 rounded-lg text-xs flex items-center justify-between transition-all ${
                      selectedGenId === gen.id
                        ? 'bg-emerald-500/20 border border-emerald-500 text-emerald-300 font-bold'
                        : 'bg-slate-800/60 hover:bg-slate-800 text-slate-300 border border-transparent'
                    }`}
                  >
                    <div className="truncate pr-2">
                      <div>{gen.name}</div>
                      <div className="text-[10px] font-mono text-slate-500">{gen.flag}</div>
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
                    <span className="hidden sm:inline-flex items-center gap-1.5 px-2 py-0.5 rounded text-[10px] font-mono bg-emerald-500/10 text-emerald-400 border border-emerald-500/20">
                      <span className="w-1.5 h-1.5 rounded-full bg-emerald-400 animate-pulse" />
                      {execMetrics.timeMs.toFixed(2)}ms ({execMetrics.engine.toUpperCase()})
                    </span>
                  </div>
                  <div className="flex items-center gap-2">
                    <button
                      type="button"
                      onClick={shareLink}
                      className="inline-flex items-center gap-1.5 px-2.5 py-1 text-xs font-medium rounded-md bg-slate-800 hover:bg-slate-700 text-slate-300 border border-slate-700 transition-colors"
                    >
                      {copiedLink ? 'Link Copied!' : '🔗 Share'}
                    </button>
                    <button
                      type="button"
                      onClick={() => copyCommand(getProceduralCommand())}
                      className="inline-flex items-center gap-1.5 px-2.5 py-1 text-xs font-medium rounded-md bg-slate-800 hover:bg-slate-700 text-slate-300 border border-slate-700 transition-colors"
                    >
                      {copiedCmd ? 'Copied!' : 'Copy Flag'}
                    </button>
                  </div>
                </div>

                {/* Terminal Body */}
                <div className="p-6 font-mono text-sm space-y-4">
                  <div className="flex items-center gap-2 text-emerald-400">
                    <span className="select-none text-slate-500">$</span>
                    <span className="text-slate-100">{getProceduralCommand()}</span>
                  </div>

                  <div className="p-4 rounded-xl bg-slate-900/90 border border-slate-800/80 text-slate-200 leading-relaxed font-sans text-sm whitespace-pre-wrap min-h-[140px]">
                    {loadingGen ? (
                      <div className="flex items-center justify-center py-8 text-slate-400 text-xs gap-2">
                        <svg className="animate-spin h-4 w-4 text-emerald-400" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24">
                          <circle className="opacity-25" cx="12" cy="12" r="10" stroke="currentColor" strokeWidth="4"></circle>
                          <path className="opacity-75" fill="currentColor" d="M4 12a8 8 0 018-8V0C5.373 0 0 5.373 0 12h4zm2 5.291A7.962 7.962 0 014 12H0c0 3.042 1.135 5.824 3 7.938l3-2.647z"></path>
                        </svg>
                        <span>Executing JavaScript generator...</span>
                      </div>
                    ) : (
                      renderFormattedOutput(proceduralResults)
                    )}
                  </div>

                  <div className="pt-2 text-xs text-slate-400 font-sans flex items-center justify-between">
                    <div>
                      <strong className="text-slate-200">Generator:</strong> {currentGen.name} • {currentGen.categoryName}
                    </div>
                    <div className="text-emerald-400 font-mono text-[11px]">
                      ⚡ Live In-Browser Generator
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        )}

        {/* Favorites Drawer */}
        {favorites.length > 0 && (
          <div className="mt-10 p-5 rounded-2xl bg-slate-900/90 border border-slate-800 shadow-xl space-y-4">
            <div className="flex flex-wrap items-center justify-between gap-4">
              <div className="flex items-center gap-2.5">
                <span className="text-red-400 text-lg">❤️</span>
                <span className="text-base font-bold text-white">
                  Saved Favorites ({favorites.length})
                </span>
                <button
                  type="button"
                  onClick={() => setShowFavorites(!showFavorites)}
                  className="text-xs text-emerald-400 hover:underline ml-2"
                >
                  {showFavorites ? '▲ Collapse' : '▼ Expand'}
                </button>
              </div>
              <div className="flex flex-wrap items-center gap-2">
                <button
                  type="button"
                  onClick={() => exportFavorites('txt')}
                  className="px-3 py-1.5 text-xs font-mono rounded-lg bg-slate-800 hover:bg-slate-700 text-slate-200 border border-slate-700 transition-colors"
                >
                  Export TXT
                </button>
                <button
                  type="button"
                  onClick={() => exportFavorites('json')}
                  className="px-3 py-1.5 text-xs font-mono rounded-lg bg-slate-800 hover:bg-slate-700 text-slate-200 border border-slate-700 transition-colors"
                >
                  Export JSON
                </button>
                <button
                  type="button"
                  onClick={() => exportFavorites('csv')}
                  className="px-3 py-1.5 text-xs font-mono rounded-lg bg-slate-800 hover:bg-slate-700 text-slate-200 border border-slate-700 transition-colors"
                >
                  Export CSV
                </button>
                <button
                  type="button"
                  onClick={() => {
                    setFavorites([]);
                    try { localStorage.removeItem('namgen_favorites'); } catch (_) {}
                  }}
                  className="px-3 py-1.5 text-xs font-mono rounded-lg bg-red-500/10 hover:bg-red-500/20 text-red-400 border border-red-500/30 transition-colors"
                >
                  Clear All
                </button>
              </div>
            </div>

            {showFavorites && (
              <div className="pt-3 border-t border-slate-800 flex flex-wrap gap-2 max-h-48 overflow-y-auto">
                {favorites.map((fav, i) => (
                  <span
                    key={i}
                    className="inline-flex items-center gap-2 px-3 py-1.5 rounded-lg text-xs bg-slate-950 border border-slate-800 text-slate-200 shadow-sm"
                  >
                    <span>{fav}</span>
                    <button
                      type="button"
                      onClick={() => toggleFavorite(fav)}
                      className="text-slate-500 hover:text-red-400 text-sm font-bold ml-1 leading-none"
                    >
                      ×
                    </button>
                  </span>
                ))}
              </div>
            )}
          </div>
        )}
      </div>
    </section>
  );
}
