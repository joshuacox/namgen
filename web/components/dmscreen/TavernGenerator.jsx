'use client';

import React, { useState, useEffect } from 'react';
import { TAVERN_DATA } from './dmscreenData';

export default function TavernGenerator({ wasmModule }) {
  const [tavernName, setTavernName] = useState('The Gilded Manticore');
  const [atmosphereIndex, setAtmosphereIndex] = useState(0);
  const [barkeepIndex, setBarkeepIndex] = useState(0);
  const [serverIndex, setServerIndex] = useState(0);
  const [specialIndex, setSpecialIndex] = useState(0);
  const [trueRumorIndex, setTrueRumorIndex] = useState(0);
  const [halfRumorIndex, setHalfRumorIndex] = useState(0);
  const [falseRumorIndex, setFalseRumorIndex] = useState(0);
  const [patronIndex, setPatronIndex] = useState(0);
  const [copied, setCopied] = useState(false);

  const rollTavernName = () => {
    if (wasmModule && wasmModule.callMain) {
      try {
        let captured = '';
        const oldOut = wasmModule.print;
        wasmModule.print = (text) => { captured += text + '\n'; };
        wasmModule.callMain(['--places-taverns', '-c', '1']);
        wasmModule.print = oldOut;
        const line = captured.trim().split('\n')[0];
        if (line) return line;
      } catch (err) {
        console.warn('WASM roll error:', err);
      }
    }
    const fallbacks = [
      'The Prancing Griffin', 'The Drunken Manticore', 'The Rusty Flagon',
      'The Siren\'s Anchor', 'The Hearth & Hammer', 'The Crooked Lantern',
    ];
    return fallbacks[Math.floor(Math.random() * fallbacks.length)];
  };

  const rollFullTavern = () => {
    setTavernName(rollTavernName());
    setAtmosphereIndex((prev) => prev + 1);
    setBarkeepIndex((prev) => prev + 1);
    setServerIndex((prev) => prev + 1);
    setSpecialIndex((prev) => prev + 1);
    setTrueRumorIndex((prev) => prev + 1);
    setHalfRumorIndex((prev) => prev + 1);
    setFalseRumorIndex((prev) => prev + 1);
    setPatronIndex((prev) => prev + 1);
  };

  useEffect(() => {
    if (wasmModule) {
      setTavernName(rollTavernName());
    }
  }, [wasmModule]);

  const speak = (name) => {
    if (typeof window !== 'undefined' && 'speechSynthesis' in window && name) {
      window.speechSynthesis.cancel();
      const utterance = new SpeechSynthesisUtterance(name);
      utterance.rate = 0.85;
      window.speechSynthesis.speak(utterance);
    }
  };

  const atmosphere = TAVERN_DATA.atmospheres[atmosphereIndex % TAVERN_DATA.atmospheres.length];
  const barkeep = TAVERN_DATA.barkeepPersonalities[barkeepIndex % TAVERN_DATA.barkeepPersonalities.length];
  const server = TAVERN_DATA.serverPersonalities[serverIndex % TAVERN_DATA.serverPersonalities.length];
  const special = TAVERN_DATA.houseSpecials[specialIndex % TAVERN_DATA.houseSpecials.length];
  const trueRumor = TAVERN_DATA.rumors.trueRumors[trueRumorIndex % TAVERN_DATA.rumors.trueRumors.length];
  const halfRumor = TAVERN_DATA.rumors.halfTrueRumors[halfRumorIndex % TAVERN_DATA.rumors.halfTrueRumors.length];
  const falseRumor = TAVERN_DATA.rumors.falseRumors[falseRumorIndex % TAVERN_DATA.rumors.falseRumors.length];
  const patron = TAVERN_DATA.shadyPatrons[patronIndex % TAVERN_DATA.shadyPatrons.length];

  const copyMarkdown = async () => {
    let md = `## Tavern: [[${tavernName}]]\n\n`;
    md += `* **Atmosphere**: ${atmosphere}\n`;
    md += `* **Barkeep**: ${barkeep}\n`;
    md += `* **Server**: ${server}\n`;
    md += `* **Today's House Special**: ${special.food} paired with ${special.brew} (${special.price})\n\n`;
    md += `### Rumor Mill\n`;
    md += `1. **True Rumor**: ${trueRumor}\n`;
    md += `2. **Half-True Rumor**: ${halfRumor}\n`;
    md += `3. **Dangerous Falsehood / Decoy**: ${falseRumor}\n\n`;
    md += `### Shady Corner Patron: [[${patron.name}]]\n`;
    md += `* **Job Offer & Hook**: ${patron.hook}\n`;

    await navigator.clipboard.writeText(md);
    setCopied(true);
    setTimeout(() => setCopied(false), 2000);
  };

  return (
    <div className="space-y-6">
      {/* Tavern Header Bar */}
      <div className="bg-slate-950/80 border border-slate-800 rounded-2xl p-6 backdrop-blur-md shadow-xl flex flex-col sm:flex-row items-center justify-between gap-4">
        <div className="flex items-center gap-3 w-full sm:w-auto">
          <span className="text-3xl p-2.5 rounded-xl bg-amber-500/10 border border-amber-500/20 text-amber-400">
            🍺
          </span>
          <div>
            <span className="text-xs uppercase tracking-wider font-bold text-amber-400">
              Emergency Tabletop Generator
            </span>
            <h3 className="text-2xl font-extrabold text-white flex items-center gap-2">
              {tavernName}
              <button
                type="button"
                onClick={() => speak(tavernName)}
                className="p-1 text-sm rounded bg-slate-800 hover:bg-slate-700 text-slate-300 hover:text-amber-400 transition-colors"
                title="Pronounce Tavern Name"
              >
                🔊
              </button>
            </h3>
          </div>
        </div>

        <div className="flex items-center gap-2.5 w-full sm:w-auto justify-end">
          <button
            onClick={rollFullTavern}
            className="px-4 py-2 bg-gradient-to-r from-amber-500 to-orange-500 hover:from-amber-400 hover:to-orange-400 text-slate-950 font-bold rounded-lg shadow-lg hover:shadow-amber-500/25 transition-all flex items-center gap-1.5 text-sm"
          >
            <span>🎲</span> Roll New Tavern
          </button>
          <button
            onClick={copyMarkdown}
            className="px-3.5 py-2 bg-slate-800 hover:bg-slate-700 text-slate-200 text-xs sm:text-sm font-semibold rounded-lg border border-slate-700 transition-all flex items-center gap-1.5"
          >
            <span>{copied ? '✅' : '📋'}</span> {copied ? 'Copied Tavern!' : 'Copy Tavern Note'}
          </button>
        </div>
      </div>

      {/* Main Grid: Atmosphere, Staff, Menu */}
      <div className="grid grid-cols-1 md:grid-cols-3 gap-5">
        {/* Atmosphere */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-5 shadow-md flex flex-col justify-between">
          <div>
            <div className="flex items-center justify-between mb-2">
              <span className="text-xs uppercase font-bold text-slate-400 tracking-wider">
                🕯️ Sights &amp; Atmosphere
              </span>
              <button
                onClick={() => setAtmosphereIndex((p) => p + 1)}
                className="text-xs text-amber-400 hover:underline"
              >
                Re-roll
              </button>
            </div>
            <p className="text-slate-200 text-sm leading-relaxed">{atmosphere}</p>
          </div>
        </div>

        {/* Staff */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-5 shadow-md flex flex-col justify-between">
          <div>
            <div className="flex items-center justify-between mb-2">
              <span className="text-xs uppercase font-bold text-slate-400 tracking-wider">
                🧔 Innkeeper &amp; Server
              </span>
              <button
                onClick={() => {
                  setBarkeepIndex((p) => p + 1);
                  setServerIndex((p) => p + 1);
                }}
                className="text-xs text-amber-400 hover:underline"
              >
                Re-roll
              </button>
            </div>
            <div className="text-sm space-y-2">
              <p className="text-slate-200">
                <strong className="text-amber-300">Barkeep:</strong> {barkeep}
              </p>
              <p className="text-slate-300">
                <strong className="text-teal-300">Server:</strong> {server}
              </p>
            </div>
          </div>
        </div>

        {/* Daily Special & Brew */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-5 shadow-md flex flex-col justify-between">
          <div>
            <div className="flex items-center justify-between mb-2">
              <span className="text-xs uppercase font-bold text-slate-400 tracking-wider">
                🍲 Today’s House Special
              </span>
              <button
                onClick={() => setSpecialIndex((p) => p + 1)}
                className="text-xs text-amber-400 hover:underline"
              >
                Re-roll
              </button>
            </div>
            <div className="text-sm space-y-1.5">
              <div className="font-semibold text-white">{special.food}</div>
              <div className="text-amber-300 text-xs">Brew: {special.brew}</div>
              <span className="inline-block mt-1 px-2 py-0.5 rounded text-xs font-mono bg-amber-500/10 text-amber-400 border border-amber-500/20">
                Price: {special.price}
              </span>
            </div>
          </div>
        </div>
      </div>

      {/* Rumor Mill (3 Distinct Tiers) */}
      <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-6 shadow-md">
        <div className="flex items-center justify-between mb-4">
          <div className="flex items-center gap-2">
            <span className="text-xl">📜</span>
            <h4 className="text-base font-bold text-white uppercase tracking-wider">
              The Rumor Mill (3 Tabletop Leads)
            </h4>
          </div>
          <button
            onClick={() => {
              setTrueRumorIndex((p) => p + 1);
              setHalfRumorIndex((p) => p + 1);
              setFalseRumorIndex((p) => p + 1);
            }}
            className="text-xs text-amber-400 hover:underline"
          >
            Re-roll All Rumors
          </button>
        </div>

        <div className="grid grid-cols-1 md:grid-cols-3 gap-4 text-sm">
          {/* True Rumor */}
          <div className="bg-emerald-950/20 border border-emerald-900/40 rounded-xl p-4">
            <span className="text-xs uppercase font-bold text-emerald-400 block mb-1">
              ✅ True Dungeon Lead
            </span>
            <p className="text-emerald-200/90 leading-relaxed">{trueRumor}</p>
          </div>

          {/* Half-True Rumor */}
          <div className="bg-amber-950/20 border border-amber-900/40 rounded-xl p-4">
            <span className="text-xs uppercase font-bold text-amber-400 block mb-1">
              ⚠️ Half-Truth (Hidden Danger)
            </span>
            <p className="text-amber-200/90 leading-relaxed">{halfRumor}</p>
          </div>

          {/* Falsehood */}
          <div className="bg-red-950/20 border border-red-900/40 rounded-xl p-4">
            <span className="text-xs uppercase font-bold text-red-400 block mb-1">
              ❌ False Myth / Bandit Decoy
            </span>
            <p className="text-red-200/90 leading-relaxed">{falseRumor}</p>
          </div>
        </div>
      </div>

      {/* Shady Corner Patron */}
      <div className="bg-purple-950/20 border border-purple-900/40 rounded-xl p-5 shadow-md flex flex-col sm:flex-row items-start sm:items-center justify-between gap-4">
        <div>
          <span className="text-xs uppercase font-bold text-purple-400 tracking-wider block mb-1">
            🕵️ Shady Patron in the Dark Corner
          </span>
          <h5 className="text-base font-bold text-white mb-1">{patron.name}</h5>
          <p className="text-purple-200/90 text-sm leading-relaxed">{patron.hook}</p>
        </div>
        <button
          onClick={() => setPatronIndex((p) => p + 1)}
          className="px-3 py-1.5 rounded-lg bg-purple-500/10 hover:bg-purple-500/20 text-purple-400 font-semibold border border-purple-500/30 text-xs transition-all whitespace-nowrap"
        >
          <span>🎲</span> New Patron
        </button>
      </div>
    </div>
  );
}
