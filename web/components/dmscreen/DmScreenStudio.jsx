'use client';

import React, { useState, useEffect } from 'react';
import FactionMatrix from './FactionMatrix';
import TavernGenerator from './TavernGenerator';
import DungeonDelver from './DungeonDelver';
import LootForge from './LootForge';
import DiceTray from './DiceTray';
import DmScratchpad from './DmScratchpad';

export default function DmScreenStudio() {
  const [activeTab, setActiveTab] = useState('faction'); // 'faction', 'tavern', 'dungeon', 'loot'
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
        console.warn('WASM load error in DmScreenStudio:', e);
      }
    };
    initWasm();
    return () => { isMounted = false; };
  }, []);

  const handlePrint = () => {
    if (typeof window !== 'undefined') {
      window.print();
    }
  };

  const copyQuickSummary = async () => {
    const summary = `# Dungeon Master Studio - Quick Reference
Generated with namgen (907 C++ procedural modules)
https://github.com/joshuacox/namgen

- Faction Matrix: High Fantasy, Grimdark, Space Opera, Underdark, High Seas, Mythic Norse
- Emergency Tavern: Atmosphere, Staff, Rumor Mill (True / Half / False), Shady Corner Patron
- 5-Room Dungeon Delver: Entrance, Hazard (DC), Guardian, Boss Sanctum (Lair Hazard), Hoard
- Relic & Loot Forge: Named Weapon, Quirky Potions, Art Curios, Coin Hoard
`;
    await navigator.clipboard.writeText(summary);
    setCopied(true);
    setTimeout(() => setCopied(false), 2000);
  };

  return (
    <section id="worldbuilder" className="py-20 bg-slate-900/70 border-y border-slate-800/80 relative">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        {/* Section Header */}
        <div className="text-center mb-10">
          <div className="inline-flex items-center gap-2 px-3 py-1 rounded-full bg-emerald-500/10 border border-emerald-500/20 text-emerald-400 text-xs font-mono mb-4">
            <span>⚔️ Complete Tabletop Campaign Engine</span>
          </div>
          <h2 className="text-3xl sm:text-4xl lg:text-5xl font-extrabold text-white tracking-tight">
            DM Screen &amp; Worldbuilding Studio
          </h2>
          <p className="mt-4 text-base sm:text-lg text-slate-400 max-w-3xl mx-auto">
            Everything a Dungeon Master needs on game night: 6-genre faction matrices, deep NPC dossiers with audio pronunciation, walk-in taverns with multi-tier rumors, 5-room procedural dungeons, and a magic item forge.
          </p>
        </div>

        {/* Studio Navigation & Master Action Bar */}
        <div className="bg-slate-950/80 border border-slate-800 rounded-2xl p-4 sm:p-5 mb-8 backdrop-blur-md shadow-xl flex flex-col lg:flex-row items-center justify-between gap-4">
          {/* Tab Selector */}
          <div className="flex flex-wrap items-center gap-1.5 p-1 bg-slate-900 border border-slate-800 rounded-xl w-full lg:w-auto">
            <button
              onClick={() => setActiveTab('faction')}
              className={`flex-1 sm:flex-initial flex items-center justify-center gap-2 px-4 py-2 rounded-lg font-bold text-xs sm:text-sm transition-all ${
                activeTab === 'faction'
                  ? 'bg-emerald-500 text-slate-950 shadow-md font-extrabold'
                  : 'text-slate-300 hover:text-white hover:bg-slate-800'
              }`}
            >
              <span>🏰</span>
              <span>Faction Matrix</span>
            </button>
            <button
              onClick={() => setActiveTab('tavern')}
              className={`flex-1 sm:flex-initial flex items-center justify-center gap-2 px-4 py-2 rounded-lg font-bold text-xs sm:text-sm transition-all ${
                activeTab === 'tavern'
                  ? 'bg-amber-500 text-slate-950 shadow-md font-extrabold'
                  : 'text-slate-300 hover:text-white hover:bg-slate-800'
              }`}
            >
              <span>🍺</span>
              <span>Tavern &amp; Rumors</span>
            </button>
            <button
              onClick={() => setActiveTab('dungeon')}
              className={`flex-1 sm:flex-initial flex items-center justify-center gap-2 px-4 py-2 rounded-lg font-bold text-xs sm:text-sm transition-all ${
                activeTab === 'dungeon'
                  ? 'bg-cyan-500 text-slate-950 shadow-md font-extrabold'
                  : 'text-slate-300 hover:text-white hover:bg-slate-800'
              }`}
            >
              <span>🗝️</span>
              <span>5-Room Dungeon</span>
            </button>
            <button
              onClick={() => setActiveTab('loot')}
              className={`flex-1 sm:flex-initial flex items-center justify-center gap-2 px-4 py-2 rounded-lg font-bold text-xs sm:text-sm transition-all ${
                activeTab === 'loot'
                  ? 'bg-violet-500 text-slate-950 shadow-md font-extrabold'
                  : 'text-slate-300 hover:text-white hover:bg-slate-800'
              }`}
            >
              <span>💎</span>
              <span>Loot &amp; Relics</span>
            </button>
          </div>

          {/* Master Utility Actions */}
          <div className="flex flex-wrap items-center gap-2 w-full lg:w-auto justify-end">
            <button
              onClick={copyQuickSummary}
              className="px-3.5 py-2 bg-slate-900 hover:bg-slate-800 text-slate-300 hover:text-white text-xs font-semibold rounded-lg border border-slate-700 transition-all flex items-center gap-1.5"
              title="Copy Quick Studio Summary"
            >
              <span>{copied ? '✅' : '📋'}</span>
              <span>{copied ? 'Copied!' : 'Studio Summary'}</span>
            </button>
            <button
              onClick={handlePrint}
              className="px-3.5 py-2 bg-slate-900 hover:bg-slate-800 text-slate-300 hover:text-white text-xs font-semibold rounded-lg border border-slate-700 transition-all flex items-center gap-1.5"
              title="Print Game Night Sheet"
            >
              <span>🖨️</span>
              <span>Print Sheet</span>
            </button>
          </div>
        </div>

        {/* Tab Content Panels */}
        <div className="min-h-[500px]">
          {activeTab === 'faction' && <FactionMatrix wasmModule={wasmModule} />}
          {activeTab === 'tavern' && <TavernGenerator wasmModule={wasmModule} />}
          {activeTab === 'dungeon' && <DungeonDelver wasmModule={wasmModule} />}
          {activeTab === 'loot' && <LootForge />}
        </div>
      </div>

      {/* Floating Live Tabletop Tools */}
      <DiceTray />
      <DmScratchpad />
    </section>
  );
}
