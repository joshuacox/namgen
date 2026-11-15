'use client';

import React, { useState, useMemo, useEffect } from 'react';
import { categories, searchGenerators, getGenerator } from 'namgen.js';

export default function GeneratorStudioPanel({
  pinnedGenerators = [],
  onTogglePin,
  onSaveCodex,
  onNotify,
}) {
  const [mode, setMode] = useState('browser');

  // Mode 1: 907 Generator Browser
  const [query, setQuery] = useState('');
  const [selectedCategory, setSelectedCategory] = useState('all');
  const [selectedGenId, setSelectedGenId] = useState('fantasy-dragons');
  const [count, setCount] = useState(10);
  const [seed, setSeed] = useState('');
  const [nameType, setNameType] = useState(0);
  const [alliterate, setAlliterate] = useState(false);
  const [syllables, setSyllables] = useState(0);
  const [matchRegex, setMatchRegex] = useState('');
  const [withLore, setWithLore] = useState(false);
  const [capitalize, setCapitalize] = useState(true);
  const [format, setFormat] = useState('plain');

  // Mode 2: Combinator
  const [combCount, setCombCount] = useState(10);
  const [combSeed, setCombSeed] = useState('');
  const [combSep, setCombSep] = useState('-');
  const [combNullSep, setCombNullSep] = useState(false);
  const [combCasing, setCombCasing] = useState('cap');
  const [combAlliterate, setCombAlliterate] = useState(false);
  const [combLore, setCombLore] = useState(false);

  // Mode 3: Multi-Generator Composer
  const [compGen1, setCompGen1] = useState('fantasy-knights');
  const [compGen2, setCompGen2] = useState('places-castles');
  const [compGen3, setCompGen3] = useState('weapons-swords');
  const [compTemplate, setCompTemplate] = useState('{1} of {2}');
  const [compCount, setCompCount] = useState(8);
  const [compSeed, setCompSeed] = useState('');

  // Shared results state
  const [names, setNames] = useState([]);
  const [formattedText, setFormattedText] = useState('');
  const [loading, setLoading] = useState(false);

  const matchingGenerators = useMemo(
    () => searchGenerators(query, selectedCategory, 80),
    [query, selectedCategory]
  );

  const activeGenMeta = useMemo(() => getGenerator(selectedGenId), [selectedGenId]);

  const rollBrowser = async (genId = selectedGenId) => {
    setSelectedGenId(genId);
    setLoading(true);
    try {
      const res = await fetch('/api/namgen', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          action: 'roll',
          generator: genId,
          count: Number(count) || 10,
          seed,
          unique: true,
          type: Number(nameType) || 0,
          alliterate,
          syllables: Number(syllables) || 0,
          matchRegex,
          withLore,
          format,
          capitalize,
        }),
      });
      const data = await res.json();
      setNames(data.names || []);
      setFormattedText(data.formatted || (data.names || []).join('\n'));
    } catch (err) {
      onNotify?.(`Roll error: ${err.message}`);
    } finally {
      setLoading(false);
    }
  };

  const rollCombinator = async () => {
    setLoading(true);
    try {
      const res = await fetch('/api/namgen', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          action: 'combinator',
          count: Number(combCount) || 10,
          seed: combSeed,
          unique: true,
          separator: combSep,
          nullSeparator: combNullSep,
          casing: combCasing,
          alliterate: combAlliterate,
          withLore: combLore,
          format,
        }),
      });
      const data = await res.json();
      setNames(data.names || []);
      setFormattedText(data.formatted || (data.names || []).join('\n'));
    } catch (err) {
      onNotify?.(`Combinator error: ${err.message}`);
    } finally {
      setLoading(false);
    }
  };

  const rollComposer = async () => {
    setLoading(true);
    try {
      const gens = [compGen1, compGen2, compGen3].filter(Boolean);
      const res = await fetch('/api/namgen', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          action: 'compose',
          generators: gens,
          template: compTemplate,
          count: Number(compCount) || 8,
          seed: compSeed,
          unique: true,
        }),
      });
      const data = await res.json();
      setNames(data.names || []);
      setFormattedText((data.names || []).join('\n'));
    } catch (err) {
      onNotify?.(`Composer error: ${err.message}`);
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => {
    rollBrowser('fantasy-dragons');
  }, []);

  const copyItem = (text) => {
    if (typeof navigator !== 'undefined' && navigator.clipboard) {
      navigator.clipboard.writeText(text);
    }
    onNotify?.(`Copied: ${text}`);
  };

  const isPinned = pinnedGenerators.includes(selectedGenId);

  return (
    <div className="space-y-5">
      {/* Sub-mode Tabs */}
      <div className="flex flex-wrap items-center justify-between gap-3 bg-slate-900/80 border border-slate-800 rounded-2xl p-3">
        <div className="flex flex-wrap gap-1.5">
          {[
            { id: 'browser', label: '📚 907 Generator Browser' },
            { id: 'combinator', label: '🧪 Word Combinator' },
            { id: 'composer', label: '🧩 {1} of {2} Composer' },
          ].map((t) => (
            <button
              key={t.id}
              type="button"
              onClick={() => setMode(t.id)}
              className={`px-3.5 py-2 rounded-xl text-xs font-bold border ${
                mode === t.id
                  ? 'bg-emerald-500/20 border-emerald-500/60 text-emerald-200'
                  : 'bg-slate-950 border-slate-800 text-slate-300 hover:text-white'
              }`}
            >
              {t.label}
            </button>
          ))}
        </div>
        <span className="text-xs font-mono text-slate-400">
          Offline Node Engine • 907 Procedural Scripts Loaded Locally
        </span>
      </div>

      {/* Mode 1: Browser */}
      {mode === 'browser' && (
        <div className="grid grid-cols-1 xl:grid-cols-12 gap-5">
          {/* Left: Generator Directory */}
          <section className="xl:col-span-5 bg-slate-900/80 border border-slate-800 rounded-2xl p-4 space-y-3">
            <input
              type="text"
              value={query}
              onChange={(e) => setQuery(e.target.value)}
              placeholder="Search 907 generators (taverns, swords, elves, demons)..."
              className="w-full bg-slate-950 border border-slate-800 rounded-xl px-3 py-2 text-xs text-slate-100 placeholder-slate-500 focus:outline-none focus:border-emerald-500"
            />

            <div className="flex flex-wrap gap-1 max-h-28 overflow-y-auto">
              <button
                type="button"
                onClick={() => setSelectedCategory('all')}
                className={`px-2 py-0.5 rounded text-[11px] border ${
                  selectedCategory === 'all'
                    ? 'bg-amber-500/20 border-amber-500/50 text-amber-200'
                    : 'bg-slate-950 border-slate-800 text-slate-400 hover:text-white'
                }`}
              >
                All ({categories.reduce((acc, c) => acc + c.count, 0)})
              </button>
              {categories.map((cat) => (
                <button
                  key={cat.id}
                  type="button"
                  onClick={() => setSelectedCategory(cat.id)}
                  className={`px-2 py-0.5 rounded text-[11px] border ${
                    selectedCategory === cat.id
                      ? 'bg-amber-500/20 border-amber-500/50 text-amber-200'
                      : 'bg-slate-950 border-slate-800 text-slate-400 hover:text-white'
                  }`}
                >
                  {cat.name} ({cat.count})
                </button>
              ))}
            </div>

            <div className="max-h-[420px] overflow-y-auto space-y-1.5 pr-1">
              {matchingGenerators.map((gen) => {
                const pinned = pinnedGenerators.includes(gen.id);
                const selected = selectedGenId === gen.id;
                return (
                  <div
                    key={gen.id}
                    className={`rounded-xl border p-2.5 flex items-center justify-between gap-2 transition-colors ${
                      selected
                        ? 'bg-slate-950 border-emerald-500/60'
                        : 'bg-slate-950/50 border-slate-800 hover:border-slate-700'
                    }`}
                  >
                    <button
                      type="button"
                      onClick={() => rollBrowser(gen.id)}
                      className="text-left flex-1 min-w-0"
                    >
                      <div className="text-xs font-bold text-slate-100 truncate">{gen.name}</div>
                      <div className="text-[11px] font-mono text-slate-500 truncate">
                        {gen.flag} • {gen.categoryName}
                      </div>
                    </button>
                    <button
                      type="button"
                      onClick={() => onTogglePin?.(gen.id)}
                      title={pinned ? 'Unpin from campaign bar' : 'Pin to campaign bar'}
                      className={`px-2 py-1 rounded text-[11px] border shrink-0 ${
                        pinned
                          ? 'bg-amber-500/20 border-amber-500/50 text-amber-300'
                          : 'bg-slate-900 border-slate-800 text-slate-500 hover:text-white'
                      }`}
                    >
                      {pinned ? '★' : '☆'}
                    </button>
                  </div>
                );
              })}
            </div>
          </section>

          {/* Right: Options & Output */}
          <section className="xl:col-span-7 bg-slate-900/80 border border-slate-800 rounded-2xl p-4 space-y-4">
            <div className="flex flex-wrap items-center justify-between gap-2 pb-3 border-b border-slate-800">
              <div>
                <h3 className="text-lg font-bold text-white">{activeGenMeta?.name || selectedGenId}</h3>
                <p className="text-xs text-slate-400">
                  {activeGenMeta?.description || 'Procedural namgen generator'}
                </p>
              </div>
              <div className="flex items-center gap-2">
                <button
                  type="button"
                  onClick={() => onTogglePin?.(selectedGenId)}
                  className={`px-3 py-1.5 rounded-lg text-xs font-semibold border ${
                    isPinned
                      ? 'bg-amber-500/20 border-amber-500/50 text-amber-200'
                      : 'bg-slate-950 border-slate-800 text-slate-300'
                  }`}
                >
                  {isPinned ? '★ Pinned to Top Bar' : '☆ Pin to Top Bar'}
                </button>
                <button
                  type="button"
                  disabled={loading}
                  onClick={() => rollBrowser(selectedGenId)}
                  className="px-4 py-1.5 rounded-lg bg-emerald-500 hover:bg-emerald-400 disabled:opacity-50 text-slate-950 text-xs font-bold"
                >
                  {loading ? 'Rolling...' : '🎲 Generate'}
                </button>
              </div>
            </div>

            <div className="grid grid-cols-2 sm:grid-cols-4 gap-2.5 text-xs">
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Count</label>
                <input
                  type="number"
                  min={1}
                  max={50}
                  value={count}
                  onChange={(e) => setCount(parseInt(e.target.value, 10) || 1)}
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 font-mono text-white"
                />
              </div>
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Seed</label>
                <input
                  type="text"
                  value={seed}
                  onChange={(e) => setSeed(e.target.value)}
                  placeholder="Optional"
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-white"
                />
              </div>
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Type (0/1/2)</label>
                <input
                  type="number"
                  min={0}
                  max={4}
                  value={nameType}
                  onChange={(e) => setNameType(parseInt(e.target.value, 10) || 0)}
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 font-mono text-white"
                />
              </div>
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Syllables (0=any)</label>
                <input
                  type="number"
                  min={0}
                  max={10}
                  value={syllables}
                  onChange={(e) => setSyllables(parseInt(e.target.value, 10) || 0)}
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 font-mono text-white"
                />
              </div>
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Regex Filter</label>
                <input
                  type="text"
                  value={matchRegex}
                  onChange={(e) => setMatchRegex(e.target.value)}
                  placeholder="^K|thorn$"
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 font-mono text-white"
                />
              </div>
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Format</label>
                <select
                  value={format}
                  onChange={(e) => setFormat(e.target.value)}
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-white"
                >
                  <option value="plain">Plain Lines</option>
                  <option value="json">JSON</option>
                  <option value="csv">CSV</option>
                  <option value="slug">Slug</option>
                </select>
              </div>
              <label className="flex items-center gap-2 pt-4 cursor-pointer text-slate-300">
                <input
                  type="checkbox"
                  checked={alliterate}
                  onChange={(e) => setAlliterate(e.target.checked)}
                />
                <span>Alliterate</span>
              </label>
              <div className="flex items-center gap-3 pt-4">
                <label className="flex items-center gap-1.5 cursor-pointer text-slate-300">
                  <input
                    type="checkbox"
                    checked={withLore}
                    onChange={(e) => setWithLore(e.target.checked)}
                  />
                  <span>Lore</span>
                </label>
                <label className="flex items-center gap-1.5 cursor-pointer text-slate-300">
                  <input
                    type="checkbox"
                    checked={capitalize}
                    onChange={(e) => setCapitalize(e.target.checked)}
                  />
                  <span>Title Case</span>
                </label>
              </div>
            </div>

            <StudioResults names={names} formatted={formattedText} format={format} onCopy={copyItem} onSaveCodex={onSaveCodex} />
          </section>
        </div>
      )}

      {/* Mode 2: Combinator */}
      {mode === 'combinator' && (
        <section className="bg-slate-900/80 border border-slate-800 rounded-2xl p-5 space-y-4">
          <div className="flex flex-wrap items-center justify-between gap-2 pb-3 border-b border-slate-800">
            <div>
              <h3 className="text-base font-bold text-white">Adjective + Noun Word Combinator</h3>
              <p className="text-xs text-slate-400">Classic project, tavern, ship, and faction callsign Forge.</p>
            </div>
            <button
              type="button"
              disabled={loading}
              onClick={rollCombinator}
              className="px-4 py-2 rounded-xl bg-amber-500 hover:bg-amber-400 text-slate-950 text-xs font-bold"
            >
              {loading ? 'Generating...' : '🎲 Roll Combinations'}
            </button>
          </div>

          <div className="grid grid-cols-2 sm:grid-cols-6 gap-3 text-xs">
            <div>
              <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Count</label>
              <input
                type="number"
                min={1}
                max={50}
                value={combCount}
                onChange={(e) => setCombCount(parseInt(e.target.value, 10) || 1)}
                className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 font-mono text-white"
              />
            </div>
            <div>
              <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Casing</label>
              <select
                value={combCasing}
                onChange={(e) => setCombCasing(e.target.value)}
                className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-white"
              >
                <option value="cap">Title Case</option>
                <option value="normal">lowercase</option>
                <option value="camel">camelCase</option>
              </select>
            </div>
            <div>
              <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Separator</label>
              <input
                type="text"
                value={combSep}
                onChange={(e) => setCombSep(e.target.value)}
                className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 font-mono text-white"
              />
            </div>
            <div>
              <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Seed</label>
              <input
                type="text"
                value={combSeed}
                onChange={(e) => setCombSeed(e.target.value)}
                placeholder="Optional"
                className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-white"
              />
            </div>
            <label className="flex items-center gap-2 pt-4 text-slate-300">
              <input
                type="checkbox"
                checked={combNullSep}
                onChange={(e) => setCombNullSep(e.target.checked)}
              />
              <span>No Separator</span>
            </label>
            <div className="flex items-center gap-3 pt-4 text-slate-300">
              <label className="flex items-center gap-1">
                <input
                  type="checkbox"
                  checked={combAlliterate}
                  onChange={(e) => setCombAlliterate(e.target.checked)}
                />
                <span>Allit.</span>
              </label>
              <label className="flex items-center gap-1">
                <input
                  type="checkbox"
                  checked={combLore}
                  onChange={(e) => setCombLore(e.target.checked)}
                />
                <span>Lore</span>
              </label>
            </div>
          </div>

          <StudioResults names={names} formatted={formattedText} format={format} onCopy={copyItem} onSaveCodex={onSaveCodex} />
        </section>
      )}

      {/* Mode 3: Multi-Generator Composer */}
      {mode === 'composer' && (
        <section className="bg-slate-900/80 border border-slate-800 rounded-2xl p-5 space-y-4">
          <div className="flex flex-wrap items-center justify-between gap-2 pb-3 border-b border-slate-800">
            <div>
              <h3 className="text-base font-bold text-white">Multi-Generator Template Composer</h3>
              <p className="text-xs text-slate-400">
                Combine multiple generators into custom phrases like <code className="text-amber-300">{'{1} of {2}'}</code> or <code className="text-amber-300">{'Wielder {1}: {3}'}</code>.
              </p>
            </div>
            <button
              type="button"
              disabled={loading}
              onClick={rollComposer}
              className="px-4 py-2 rounded-xl bg-amber-500 hover:bg-amber-400 text-slate-950 text-xs font-bold"
            >
              {loading ? 'Composing...' : '🧩 Compose Phrases'}
            </button>
          </div>

          <div className="grid grid-cols-1 sm:grid-cols-3 gap-3 text-xs">
            {[
              { label: 'Slot {1} Generator', val: compGen1, setter: setCompGen1 },
              { label: 'Slot {2} Generator', val: compGen2, setter: setCompGen2 },
              { label: 'Slot {3} Generator (optional)', val: compGen3, setter: setCompGen3 },
            ].map((slot, idx) => (
              <div key={idx}>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">
                  {slot.label}
                </label>
                <input
                  type="text"
                  list="namgen-all-ids"
                  value={slot.val}
                  onChange={(e) => slot.setter(e.target.value)}
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 font-mono text-white"
                />
              </div>
            ))}
          </div>

          <datalist id="namgen-all-ids">
            {searchGenerators('', 'all', 950).map((g) => (
              <option key={g.id} value={g.id}>
                {g.name}
              </option>
            ))}
          </datalist>

          <div className="grid grid-cols-1 sm:grid-cols-3 gap-3 text-xs">
            <div className="sm:col-span-2">
              <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Template</label>
              <input
                type="text"
                value={compTemplate}
                onChange={(e) => setCompTemplate(e.target.value)}
                className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 font-mono text-amber-200"
              />
            </div>
            <div className="grid grid-cols-2 gap-2">
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Count</label>
                <input
                  type="number"
                  min={1}
                  max={30}
                  value={compCount}
                  onChange={(e) => setCompCount(parseInt(e.target.value, 10) || 5)}
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 font-mono text-white"
                />
              </div>
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Seed</label>
                <input
                  type="text"
                  value={compSeed}
                  onChange={(e) => setCompSeed(e.target.value)}
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-white"
                />
              </div>
            </div>
          </div>

          <StudioResults names={names} formatted={formattedText} format="plain" onCopy={copyItem} onSaveCodex={onSaveCodex} />
        </section>
      )}
    </div>
  );
}

function StudioResults({ names, formatted, format, onCopy, onSaveCodex }) {
  if (!names || names.length === 0) {
    return (
      <div className="text-center py-8 text-xs text-slate-500 border border-dashed border-slate-800 rounded-xl">
        Roll to generate results.
      </div>
    );
  }

  return (
    <div className="space-y-3">
      {format === 'plain' ? (
        <div className="grid grid-cols-1 sm:grid-cols-2 gap-2">
          {names.map((item, idx) => (
            <div
              key={`${idx}_${item}`}
              className="bg-slate-950 border border-slate-800 rounded-xl p-2.5 flex items-center justify-between gap-2 text-xs"
            >
              <span className="text-slate-100 whitespace-pre-line break-words flex-1">{item}</span>
              <div className="flex items-center gap-1 shrink-0">
                <button
                  type="button"
                  onClick={() => onCopy?.(item)}
                  className="px-2 py-1 rounded bg-slate-900 hover:bg-slate-800 text-slate-300"
                >
                  Copy
                </button>
                <button
                  type="button"
                  onClick={() =>
                    onSaveCodex?.({
                      kind: 'item',
                      title: item.split('\n')[0].slice(0, 80),
                      subtitle: 'Generated in Studio',
                      status: 'Active',
                      tags: ['studio'],
                      summary: item,
                      dmNotes: '',
                      data: null,
                    })
                  }
                  className="px-2 py-1 rounded bg-emerald-500/15 hover:bg-emerald-500/30 text-emerald-300"
                  title="Save to Codex"
                >
                  +Codex
                </button>
              </div>
            </div>
          ))}
        </div>
      ) : (
        <pre className="bg-slate-950 border border-slate-800 rounded-xl p-3 text-xs font-mono text-emerald-200 overflow-x-auto max-h-80">
          {formatted}
        </pre>
      )}
    </div>
  );
}
