'use client';

import React, { useState, useEffect } from 'react';

const DEFAULT_ROSTER_SLOTS = [
  { id: 'monarch', title: 'Sovereign / Ruler', icon: '👑', generator: 'fantasy-kings_and_queens', name: 'Aethelgard the Vow-Keeper' },
  { id: 'mage', title: 'High Sage / Arch-Mage', icon: '🔮', generator: 'dungeon_and_dragons-wizards', name: 'Valerius of the Astral Dawn' },
  { id: 'champion', title: 'Grand Champion', icon: '⚔️', generator: 'warhammer-knights', name: 'Sir Balthazar Ironclad' },
  { id: 'citadel', title: 'Capital Citadel', icon: '🏰', generator: 'towns_and_cities-castles', name: 'Fortress of the Pale Moon' },
  { id: 'beast', title: 'Guardian Dragon / Titan', icon: '🐉', generator: 'fantasy-dragons', name: 'Igniscor the Ash-Bringer' },
  { id: 'relic', title: 'Sacred Relic / Blade', icon: '🗡️', generator: 'weapons-swords', name: 'Oathkeeper of the Sunken Spire' },
  { id: 'flagship', title: 'Flagship Vessel', icon: '⛵', generator: 'military-naval_ships', name: 'The Void-Strider' },
  { id: 'tavern', title: 'Waypoint Tavern / Haven', icon: '🍺', generator: 'places-taverns', name: 'The Drunken Manticore' },
];

export default function WorldbuilderBoard() {
  const [slots, setSlots] = useState(DEFAULT_ROSTER_SLOTS);
  const [factionName, setFactionName] = useState('Kingdom of the Obsidian Reach');
  const [wasmModule, setWasmModule] = useState(null);
  const [copied, setCopied] = useState(false);

  useEffect(() => {
    let isMounted = true;
    const initWasm = async () => {
      try {
        if (typeof window !== 'undefined' && window.createNamgen) {
          const mod = await window.createNamgen({
            locateFile: (path) => `/wasm/${path}`,
          });
          if (isMounted) setWasmModule(mod);
        } else if (typeof window !== 'undefined') {
          const script = document.createElement('script');
          script.src = '/wasm/namgen.js';
          script.onload = async () => {
            if (window.createNamgen && isMounted) {
              const mod = await window.createNamgen({
                locateFile: (path) => `/wasm/${path}`,
              });
              if (isMounted) setWasmModule(mod);
            }
          };
          document.body.appendChild(script);
        }
      } catch (e) {
        console.warn('WASM load error in WorldbuilderBoard:', e);
      }
    };
    initWasm();
    return () => { isMounted = false; };
  }, []);

  const rollSlotName = (genFlag) => {
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
    return 'Eldrin the Star-Watcher';
  };

  const rollSingleSlot = (id) => {
    setSlots((prev) =>
      prev.map((slot) => {
        if (slot.id === id) {
          return { ...slot, name: rollSlotName(slot.generator) };
        }
        return slot;
      })
    );
  };

  const rollEntireFaction = () => {
    setSlots((prev) =>
      prev.map((slot) => ({
        ...slot,
        name: rollSlotName(slot.generator),
      }))
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
    let md = `# Campaign Roster: ${factionName}\n\n`;
    md += `*Generated with [namgen](https://github.com/joshuacox/namgen) procedural engine*\n\n`;
    md += `| Role | Name | Module Generator |\n`;
    md += `| :--- | :--- | :--- |\n`;
    slots.forEach((s) => {
      md += `| ${s.icon} **${s.title}** | ${s.name} | \`--${s.generator}\` |\n`;
    });
    md += `\n---\n*Ready for import into Obsidian, Notion, or Foundry VTT.*\n`;
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
    <section id="worldbuilder" className="py-20 bg-slate-900/60 border-y border-slate-800/80">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div className="text-center mb-12">
          <div className="inline-flex items-center gap-2 px-3 py-1 rounded-full bg-emerald-500/10 border border-emerald-500/20 text-emerald-400 text-xs font-mono mb-4">
            <span>✨ Tabletop Campaign Studio</span>
          </div>
          <h2 className="text-3xl sm:text-4xl font-extrabold text-white tracking-tight">
            Worldbuilding &amp; Faction Matrix
          </h2>
          <p className="mt-4 text-lg text-slate-400 max-w-3xl mx-auto">
            Roll an entire coherent realm, court, or faction roster with a single click. Export to formatted Markdown for Obsidian, Notion, or your tabletop game binder.
          </p>
        </div>

        {/* Faction Header Bar */}
        <div className="bg-slate-950/80 border border-slate-800 rounded-2xl p-6 mb-8 backdrop-blur-md shadow-xl flex flex-col md:flex-row items-center justify-between gap-4">
          <div className="flex-1 w-full md:w-auto">
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

          <div className="flex flex-wrap items-center gap-3 w-full md:w-auto justify-end">
            <button
              onClick={rollEntireFaction}
              className="px-5 py-2.5 bg-gradient-to-r from-emerald-500 to-teal-500 hover:from-emerald-400 hover:to-teal-400 text-slate-950 font-bold rounded-lg shadow-lg hover:shadow-emerald-500/25 transition-all flex items-center gap-2"
            >
              <span>🎲</span> Roll Entire Faction
            </button>
            <button
              onClick={copyMarkdown}
              className="px-4 py-2.5 bg-slate-800 hover:bg-slate-700 text-slate-200 text-sm font-semibold rounded-lg border border-slate-700 transition-all flex items-center gap-2"
            >
              <span>{copied ? '✅' : '📋'}</span> {copied ? 'Copied!' : 'Copy Markdown'}
            </button>
            <button
              onClick={downloadMarkdown}
              className="px-4 py-2.5 bg-slate-800 hover:bg-slate-700 text-slate-200 text-sm font-semibold rounded-lg border border-slate-700 transition-all flex items-center gap-1.5"
              title="Download Obsidian / Notion Markdown"
            >
              <span>💾</span> .md
            </button>
            <button
              onClick={downloadJson}
              className="px-4 py-2.5 bg-slate-800 hover:bg-slate-700 text-slate-200 text-sm font-semibold rounded-lg border border-slate-700 transition-all flex items-center gap-1.5"
              title="Download structured JSON"
            >
              <span>💾</span> .json
            </button>
          </div>
        </div>

        {/* 8-Slot Roster Grid */}
        <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-4 gap-6">
          {slots.map((slot) => (
            <div
              key={slot.id}
              className="bg-slate-950/70 border border-slate-800/80 hover:border-emerald-500/40 rounded-xl p-5 transition-all group flex flex-col justify-between"
            >
              <div>
                <div className="flex items-center justify-between mb-3">
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
                <div className="text-lg font-bold text-slate-100 group-hover:text-emerald-300 transition-colors py-2 break-words">
                  {slot.name}
                </div>
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
                  title="Re-roll this character"
                >
                  <span>🎲</span> Re-roll
                </button>
              </div>
            </div>
          ))}
        </div>
      </div>
    </section>
  );
}
