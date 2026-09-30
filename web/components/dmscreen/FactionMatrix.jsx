'use client';

import React, { useState, useEffect } from 'react';
import { GENRE_PRESETS } from './dmscreenData';
import NpcDossierModal from './NpcDossierModal';

export default function FactionMatrix({ wasmModule }) {
  const [selectedGenre, setSelectedGenre] = useState('fantasy');
  const [factionName, setFactionName] = useState(GENRE_PRESETS.fantasy.defaultFaction);
  const [slots, setSlots] = useState(
    GENRE_PRESETS.fantasy.slots.map((s) => ({
      ...s,
      name: 'Generating...',
    }))
  );
  const [activeDossier, setActiveDossier] = useState(null);
  const [copied, setCopied] = useState(false);

  // Helper to roll a name from WASM or fallback
  const rollNameForGen = (genFlag) => {
    if (wasmModule && wasmModule.callMain) {
      try {
        let captured = '';
        const oldOut = wasmModule.print;
        wasmModule.print = (text) => { captured += text + '\n'; };
        wasmModule.callMain([`--${genFlag}`, '-c', '1']);
        wasmModule.print = oldOut;
        const line = captured.trim().split('\n')[0];
        if (line) return line;
      } catch (err) {
        console.warn('WASM roll error:', err);
      }
    }
    // Fallback names
    const fallbacks = [
      'Valerius of the Astral Dawn', 'Aethelgard Vowkeeper', 'Igniscor the Ash-Bringer',
      'The Obsidian Bastion', 'Sunfire Galleon', 'Sir Balthazar Ironclad', 'The Broken Anchor',
    ];
    return fallbacks[Math.floor(Math.random() * fallbacks.length)];
  };

  // Populate slots on genre change or initial mount
  useEffect(() => {
    const preset = GENRE_PRESETS[selectedGenre];
    setFactionName(preset.defaultFaction);
    setSlots(
      preset.slots.map((s) => ({
        ...s,
        name: rollNameForGen(s.generator),
      }))
    );
  }, [selectedGenre, wasmModule]);

  const rollEntireFaction = () => {
    setSlots((prev) =>
      prev.map((slot) => ({
        ...slot,
        name: rollNameForGen(slot.generator),
      }))
    );
  };

  const rollSingleSlot = (id) => {
    setSlots((prev) =>
      prev.map((slot) => {
        if (slot.id === id) {
          return { ...slot, name: rollNameForGen(slot.generator) };
        }
        return slot;
      })
    );
  };

  const speak = (name) => {
    if (typeof window !== 'undefined' && 'speechSynthesis' in window && name) {
      window.speechSynthesis.cancel();
      const utterance = new SpeechSynthesisUtterance(name);
      utterance.rate = 0.85;
      window.speechSynthesis.speak(utterance);
    }
  };

  const generateMarkdown = () => {
    let md = `# Campaign Faction: [[${factionName}]]\n\n`;
    md += `*Genre: ${GENRE_PRESETS[selectedGenre].name}*\n`;
    md += `*Generated with [namgen](https://github.com/joshuacox/namgen) procedural engine*\n\n`;
    md += `| Role | Entity / Character | Generator Flag |\n`;
    md += `| :--- | :--- | :--- |\n`;
    slots.forEach((s) => {
      md += `| ${s.icon} **${s.title}** | [[${s.name}]] | \`--${s.generator}\` |\n`;
    });
    md += `\n---\n*Ready for import into Obsidian / Logseq with automatic graph wiki-links.*\n`;
    return md;
  };

  const copyMarkdown = async () => {
    const md = generateMarkdown();
    await navigator.clipboard.writeText(md);
    setCopied(true);
    setTimeout(() => setCopied(false), 2000);
  };

  const downloadMarkdown = () => {
    const md = generateMarkdown();
    const blob = new Blob([md], { type: 'text/markdown' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = `${factionName.toLowerCase().replace(/[^a-z0-9]+/g, '-')}.md`;
    a.click();
    URL.revokeObjectURL(url);
  };

  const downloadJson = () => {
    const data = {
      faction: factionName,
      genre: GENRE_PRESETS[selectedGenre].name,
      generatedAt: new Date().toISOString(),
      roster: slots.map((s) => ({ role: s.title, name: s.name, generator: s.generator })),
    };
    const blob = new Blob([JSON.stringify(data, null, 2)], { type: 'application/json' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = `${factionName.toLowerCase().replace(/[^a-z0-9]+/g, '-')}.json`;
    a.click();
    URL.revokeObjectURL(url);
  };

  return (
    <div className="space-y-6">
      {/* Control Header Bar */}
      <div className="bg-slate-950/80 border border-slate-800 rounded-2xl p-6 backdrop-blur-md shadow-xl flex flex-col md:flex-row items-center justify-between gap-4">
        {/* Preset Selector & Faction Name */}
        <div className="flex flex-col sm:flex-row items-stretch sm:items-center gap-4 w-full md:w-auto flex-1">
          <div className="w-full sm:w-64">
            <label className="block text-xs uppercase tracking-wider font-semibold text-slate-400 mb-1">
              Campaign Setting / Genre
            </label>
            <select
              value={selectedGenre}
              onChange={(e) => setSelectedGenre(e.target.value)}
              className="w-full bg-slate-900 border border-slate-700 rounded-lg px-3 py-2 text-white font-medium focus:ring-2 focus:ring-emerald-500 focus:outline-none"
            >
              {Object.values(GENRE_PRESETS).map((p) => (
                <option key={p.id} value={p.id}>
                  {p.icon} {p.name}
                </option>
              ))}
            </select>
          </div>

          <div className="flex-1">
            <label className="block text-xs uppercase tracking-wider font-semibold text-slate-400 mb-1">
              Faction / Realm Name
            </label>
            <input
              type="text"
              value={factionName}
              onChange={(e) => setFactionName(e.target.value)}
              className="w-full bg-slate-900 border border-slate-700 rounded-lg px-4 py-2 text-white font-medium focus:ring-2 focus:ring-emerald-500 focus:outline-none"
            />
          </div>
        </div>

        {/* Action Buttons */}
        <div className="flex flex-wrap items-center gap-2.5 w-full md:w-auto justify-end">
          <button
            onClick={rollEntireFaction}
            className="px-4 py-2 bg-gradient-to-r from-emerald-500 to-teal-500 hover:from-emerald-400 hover:to-teal-400 text-slate-950 font-bold rounded-lg shadow-lg hover:shadow-emerald-500/25 transition-all flex items-center gap-1.5 text-sm"
          >
            <span>🎲</span> Roll Entire Faction
          </button>
          <button
            onClick={copyMarkdown}
            className="px-3 py-2 bg-slate-800 hover:bg-slate-700 text-slate-200 text-xs sm:text-sm font-semibold rounded-lg border border-slate-700 transition-all flex items-center gap-1.5"
          >
            <span>{copied ? '✅' : '📋'}</span> {copied ? 'Copied Wiki!' : 'Copy Wiki Note'}
          </button>
          <button
            onClick={downloadMarkdown}
            className="px-3 py-2 bg-slate-800 hover:bg-slate-700 text-slate-200 text-xs sm:text-sm font-semibold rounded-lg border border-slate-700 transition-all flex items-center gap-1"
            title="Download Obsidian / Logseq Markdown"
          >
            <span>💾</span> .md
          </button>
          <button
            onClick={downloadJson}
            className="px-3 py-2 bg-slate-800 hover:bg-slate-700 text-slate-200 text-xs sm:text-sm font-semibold rounded-lg border border-slate-700 transition-all flex items-center gap-1"
            title="Download structured JSON"
          >
            <span>💾</span> .json
          </button>
        </div>
      </div>

      {/* 8-Slot Roster Grid */}
      <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-4 gap-5">
        {slots.map((slot) => (
          <div
            key={slot.id}
            className="bg-slate-950/70 border border-slate-800/80 hover:border-emerald-500/50 rounded-xl p-5 transition-all group flex flex-col justify-between shadow-md"
          >
            <div>
              <div className="flex items-center justify-between mb-2.5">
                <div className="flex items-center gap-2">
                  <span className="text-2xl">{slot.icon}</span>
                  <span className="text-xs uppercase tracking-wider font-bold text-slate-400">
                    {slot.title}
                  </span>
                </div>
                <span className="text-[10px] font-mono text-emerald-400/80 bg-emerald-500/10 px-2 py-0.5 rounded border border-emerald-500/20">
                  --{slot.generator.split('-')[1] || slot.generator}
                </span>
              </div>

              {/* Name & Click to Inspect */}
              <button
                type="button"
                onClick={() => setActiveDossier(slot)}
                className="text-left w-full group/btn"
                title="Click to inspect NPC dossier"
              >
                <div className="text-lg font-bold text-slate-100 group-hover/btn:text-emerald-300 transition-colors py-2 break-words flex items-center justify-between">
                  <span>{slot.name}</span>
                  <span className="text-xs font-normal text-slate-500 group-hover/btn:text-emerald-400 opacity-0 group-hover/btn:opacity-100 transition-opacity">
                    Inspect ↗
                  </span>
                </div>
              </button>
            </div>

            <div className="mt-4 pt-3 border-t border-slate-800/60 flex items-center justify-between text-xs text-slate-400">
              <button
                type="button"
                onClick={() => speak(slot.name)}
                className="flex items-center gap-1 px-2 py-1 rounded bg-slate-900 hover:bg-slate-800 text-slate-300 hover:text-emerald-400 transition-colors"
                title="Pronounce"
              >
                <span>🔊</span> Listen
              </button>
              <button
                type="button"
                onClick={() => rollSingleSlot(slot.id)}
                className="flex items-center gap-1 px-2.5 py-1 rounded bg-emerald-500/10 hover:bg-emerald-500/20 text-emerald-400 font-semibold border border-emerald-500/20 transition-all hover:scale-105"
                title="Re-roll this entity"
              >
                <span>🎲</span> Re-roll
              </button>
            </div>
          </div>
        ))}
      </div>

      {/* NPC Dossier Modal */}
      {activeDossier && (
        <NpcDossierModal
          character={activeDossier}
          onClose={() => setActiveDossier(null)}
          onRerollName={(id) => {
            rollSingleSlot(id);
            setActiveDossier((prev) => ({
              ...prev,
              name: rollNameForGen(prev.generator),
            }));
          }}
        />
      )}
    </div>
  );
}
