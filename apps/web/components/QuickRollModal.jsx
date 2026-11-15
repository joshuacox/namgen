'use client';

import React, { useState, useMemo, useEffect, useRef } from 'react';
import { searchGenerators } from 'namgen.js';

export default function QuickRollModal({
  isOpen,
  onClose,
  pinnedGenerators = [],
  onTogglePin,
  onNotify,
}) {
  const [query, setQuery] = useState('');
  const [selectedId, setSelectedId] = useState('dungeon_and_dragons-elfs');
  const [results, setResults] = useState([]);
  const [loading, setLoading] = useState(false);
  const inputRef = useRef(null);

  const matches = useMemo(() => searchGenerators(query, 'all', 30), [query]);

  useEffect(() => {
    if (isOpen) {
      setTimeout(() => inputRef.current?.focus(), 40);
      rollQuick(selectedId);
    }
  }, [isOpen]);

  const rollQuick = async (genId) => {
    setSelectedId(genId);
    setLoading(true);
    try {
      const res = await fetch('/api/namgen', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ action: 'roll', generator: genId, count: 8, unique: true, capitalize: true }),
      });
      const data = await res.json();
      setResults(data.names || []);
    } catch (_) {
      setResults([]);
    } finally {
      setLoading(false);
    }
  };

  if (!isOpen) return null;

  const isPinned = pinnedGenerators.includes(selectedId);

  return (
    <div
      className="fixed inset-0 z-50 flex items-start justify-center pt-16 p-4 bg-slate-950/80 backdrop-blur-sm no-print"
      onClick={onClose}
    >
      <div
        className="w-full max-w-3xl bg-slate-900 border border-slate-700 rounded-2xl shadow-2xl overflow-hidden"
        onClick={(e) => e.stopPropagation()}
      >
        <div className="flex items-center gap-3 px-4 py-3 border-b border-slate-800 bg-slate-950">
          <span className="text-amber-400 text-lg">⚡</span>
          <input
            ref={inputRef}
            type="text"
            value={query}
            onChange={(e) => setQuery(e.target.value)}
            placeholder="Quick-search 907 namgen generators (e.g. elf, tavern, sword, drow, potion, goblin)..."
            className="flex-1 bg-transparent text-white text-sm focus:outline-none placeholder-slate-500"
          />
          <kbd className="text-[10px] font-mono px-2 py-0.5 rounded bg-slate-800 text-slate-400 border border-slate-700">
            ESC
          </kbd>
        </div>

        <div className="grid grid-cols-1 md:grid-cols-2 divide-y md:divide-y-0 md:divide-x divide-slate-800 max-h-[440px]">
          <div className="overflow-y-auto p-2 space-y-1 max-h-[440px]">
            {matches.map((gen) => (
              <button
                key={gen.id}
                type="button"
                onClick={() => rollQuick(gen.id)}
                className={`w-full text-left px-3 py-2 rounded-lg text-xs flex items-center justify-between transition-colors ${
                  selectedId === gen.id
                    ? 'bg-emerald-500/20 border border-emerald-500/50 text-emerald-300 font-semibold'
                    : 'hover:bg-slate-800 text-slate-300'
                }`}
              >
                <div className="truncate pr-2">
                  <div>{gen.name}</div>
                  <div className="text-[10px] font-mono text-slate-500">{gen.flag}</div>
                </div>
                <span className="text-[10px] text-slate-500 whitespace-nowrap">{gen.category}</span>
              </button>
            ))}
          </div>

          <div className="p-4 flex flex-col justify-between bg-slate-950/60">
            <div>
              <div className="flex items-center justify-between gap-2 mb-3">
                <div>
                  <div className="text-[11px] font-mono text-emerald-400">--{selectedId}</div>
                  <div className="text-sm font-bold text-white">Instant Rolls</div>
                </div>
                <div className="flex items-center gap-1.5">
                  {onTogglePin && (
                    <button
                      type="button"
                      onClick={() => onTogglePin(selectedId)}
                      className={`px-2.5 py-1 rounded-lg text-xs font-semibold border ${
                        isPinned
                          ? 'bg-amber-500/20 border-amber-500/40 text-amber-300'
                          : 'bg-slate-800 border-slate-700 text-slate-300 hover:text-white'
                      }`}
                    >
                      {isPinned ? '📌 Pinned' : 'Pin'}
                    </button>
                  )}
                  <button
                    type="button"
                    onClick={() => rollQuick(selectedId)}
                    className="px-3 py-1 rounded-lg bg-emerald-500 hover:bg-emerald-400 text-slate-950 text-xs font-bold"
                  >
                    🎲 Roll
                  </button>
                </div>
              </div>

              <div className="space-y-1.5 max-h-[320px] overflow-y-auto">
                {loading ? (
                  <div className="text-xs text-slate-400 py-8 text-center">Generating...</div>
                ) : (
                  results.map((name, idx) => (
                    <div
                      key={idx}
                      className="flex items-center justify-between gap-2 px-3 py-2 rounded-lg bg-slate-900 border border-slate-800 text-xs text-slate-100"
                    >
                      <span className="break-words">{name}</span>
                      <button
                        type="button"
                        onClick={() => {
                          navigator.clipboard.writeText(name);
                          if (onNotify) onNotify(`Copied "${name}"`);
                        }}
                        className="text-[11px] px-2 py-0.5 rounded bg-slate-800 hover:bg-slate-700 text-slate-300 flex-shrink-0"
                      >
                        Copy
                      </button>
                    </div>
                  ))
                )}
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}
