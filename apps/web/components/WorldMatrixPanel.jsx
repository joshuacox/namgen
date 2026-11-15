'use client';

import React, { useState, useEffect } from 'react';
import { GENRE_PRESETS } from 'namgen.js/dnd';

export default function WorldMatrixPanel({ onSaveCodex, onNotify }) {
  const presets = Object.values(GENRE_PRESETS);
  const [genreId, setGenreId] = useState('fantasy');
  const [seed, setSeed] = useState('');
  const [faction, setFaction] = useState(null);
  const [loading, setLoading] = useState(false);
  const [rerollingSlot, setRerollingSlot] = useState('');

  const generateFaction = async (nextGenre = genreId, nextSeed = seed) => {
    setLoading(true);
    try {
      const res = await fetch('/api/namgen', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          action: 'faction',
          genreId: nextGenre,
          seed: nextSeed,
        }),
      });
      const data = await res.json();
      if (data.faction) {
        setFaction(data.faction);
      } else {
        onNotify?.(data.error || 'Failed to generate realm & faction');
      }
    } catch (err) {
      onNotify?.(`Faction generation failed: ${err.message}`);
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => {
    generateFaction('fantasy', '');
  }, []);

  const rerollSlot = async (slot) => {
    if (!faction) return;
    setRerollingSlot(slot.id);
    try {
      const res = await fetch('/api/namgen', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          action: 'roll',
          generator: slot.generator,
          count: 1,
          unique: true,
          capitalize: true,
        }),
      });
      const data = await res.json();
      const fresh = data.names?.[0];
      if (fresh) {
        setFaction((prev) => ({
          ...prev,
          slots: prev.slots.map((s) => (s.id === slot.id ? { ...s, name: fresh } : s)),
        }));
      }
    } catch (err) {
      onNotify?.(`Slot reroll failed: ${err.message}`);
    } finally {
      setRerollingSlot('');
    }
  };

  const copyObsidianMarkdown = () => {
    if (!faction) return;
    const lines = [
      `# [[${faction.factionName}]] (${faction.genreName})`,
      '',
      `**Heraldry:** ${faction.coatOfArms}`,
      '',
      `**Law & Custom:** ${faction.law}`,
      '',
      '## Key Pillars & Holdings',
      ...faction.slots.map((s) => `- **${s.title}:** [[${s.name}]] (*${s.desc}*)`),
    ];
    if (typeof navigator !== 'undefined' && navigator.clipboard) {
      navigator.clipboard.writeText(lines.join('\n'));
    }
    onNotify?.(`Copied Obsidian [[WikiLink]] sheet for ${faction.factionName}`);
  };

  return (
    <div className="space-y-5">
      {/* Genre Presets Bar */}
      <section className="bg-slate-900/80 border border-slate-800 rounded-2xl p-4 flex flex-wrap items-center justify-between gap-3">
        <div className="flex flex-wrap gap-2">
          {presets.map((p) => {
            const active = genreId === p.id;
            return (
              <button
                key={p.id}
                type="button"
                onClick={() => {
                  setGenreId(p.id);
                  generateFaction(p.id, seed);
                }}
                className={`px-3 py-2 rounded-xl text-xs font-semibold border flex items-center gap-1.5 transition-colors ${
                  active
                    ? 'bg-emerald-500/20 border-emerald-500/60 text-emerald-200'
                    : 'bg-slate-950 border-slate-800 text-slate-300 hover:border-slate-700 hover:text-white'
                }`}
              >
                <span>{p.icon}</span>
                <span>{p.name}</span>
              </button>
            );
          })}
        </div>

        <div className="flex items-center gap-2">
          <input
            type="text"
            value={seed}
            onChange={(e) => setSeed(e.target.value)}
            placeholder="Optional seed..."
            className="bg-slate-950 border border-slate-800 rounded-xl px-3 py-1.5 text-xs text-slate-100 placeholder-slate-600 w-36"
          />
          <button
            type="button"
            onClick={() => generateFaction(genreId, seed)}
            disabled={loading}
            className="px-4 py-2 rounded-xl bg-amber-500 hover:bg-amber-400 disabled:opacity-50 text-slate-950 text-xs font-bold"
          >
            {loading ? 'Weaving...' : '🏰 Generate Faction & Realm'}
          </button>
        </div>
      </section>

      {faction && (
        <section className="bg-slate-900/80 border border-slate-800 rounded-2xl p-5 space-y-5">
          {/* Header & Actions */}
          <div className="flex flex-wrap items-start justify-between gap-3 pb-4 border-b border-slate-800">
            <div>
              <div className="flex items-center gap-2 text-xs font-mono uppercase text-amber-400">
                <span>{faction.icon}</span>
                <span>{faction.genreName} Setting Pillar</span>
              </div>
              <h2 className="text-2xl font-extrabold text-white mt-0.5">{faction.factionName}</h2>
            </div>

            <div className="flex flex-wrap gap-2">
              <button
                type="button"
                onClick={copyObsidianMarkdown}
                className="px-3 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 text-xs font-semibold text-slate-100"
              >
                📋 Copy Obsidian [[WikiLink]]
              </button>
              <button
                type="button"
                onClick={() =>
                  onSaveCodex?.({
                    kind: 'faction',
                    title: faction.factionName,
                    subtitle: `${faction.genreName} Faction & Settlement Matrix`,
                    status: 'Active',
                    tags: ['faction', faction.genreId],
                    summary: `Coat of Arms: ${faction.coatOfArms}\nHoldings: ${faction.slots
                      .map((s) => `${s.title}: ${s.name}`)
                      .join(' | ')}`,
                    dmNotes: `Law & Custom: ${faction.law}`,
                    data: faction,
                  })
                }
                className="px-3 py-1.5 rounded-lg bg-emerald-500/20 hover:bg-emerald-500/30 border border-emerald-500/40 text-xs font-semibold text-emerald-300"
              >
                + Save Faction to Codex
              </button>
            </div>
          </div>

          {/* Heraldry & Realm Decree */}
          <div className="grid grid-cols-1 md:grid-cols-2 gap-4 text-xs">
            <div className="bg-slate-950 border border-amber-500/30 rounded-xl p-3.5 space-y-1">
              <span className="text-[10px] font-mono uppercase text-amber-400 block">
                Heraldry &amp; Coat of Arms
              </span>
              <p className="text-slate-200 whitespace-pre-line leading-relaxed">{faction.coatOfArms}</p>
            </div>

            <div className="bg-slate-950 border border-rose-500/30 rounded-xl p-3.5 space-y-1">
              <span className="text-[10px] font-mono uppercase text-rose-400 block">
                Notable Law, Custom &amp; Taboo
              </span>
              <p className="text-slate-200 whitespace-pre-line leading-relaxed">{faction.law}</p>
            </div>
          </div>

          {/* 6 Interconnected Realm Slots */}
          <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-3">
            {faction.slots.map((slot) => (
              <div
                key={slot.id}
                className="bg-slate-950 border border-slate-800 hover:border-emerald-500/40 rounded-xl p-3.5 flex flex-col justify-between gap-2.5"
              >
                <div>
                  <div className="flex items-center justify-between gap-2">
                    <span className="text-xs font-semibold text-emerald-300 flex items-center gap-1.5">
                      <span>{slot.icon}</span>
                      <span>{slot.title}</span>
                    </span>
                    <button
                      type="button"
                      disabled={rerollingSlot === slot.id}
                      onClick={() => rerollSlot(slot)}
                      className="px-2 py-0.5 rounded bg-slate-900 hover:bg-slate-800 border border-slate-700 text-[11px] text-slate-300"
                    >
                      {rerollingSlot === slot.id ? '...' : '↻ Reroll'}
                    </button>
                  </div>
                  <div className="text-base font-bold text-white mt-2">{slot.name}</div>
                </div>

                <div className="flex items-center justify-between text-[11px] text-slate-500 pt-2 border-t border-slate-800/80">
                  <span>{slot.desc}</span>
                  <span className="font-mono text-slate-600">{slot.generator}</span>
                </div>
              </div>
            ))}
          </div>
        </section>
      )}
    </div>
  );
}
