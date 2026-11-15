'use client';

import React, { useState } from 'react';

const DICE_TYPES = [
  { label: 'd4', sides: 4, icon: '▲' },
  { label: 'd6', sides: 6, icon: '⚅' },
  { label: 'd8', sides: 8, icon: '◆' },
  { label: 'd10', sides: 10, icon: '🔟' },
  { label: 'd12', sides: 12, icon: '⬡' },
  { label: 'd20', sides: 20, icon: '🎲' },
  { label: 'd100', sides: 100, icon: '💯' },
];

export default function DiceTray() {
  const [isOpen, setIsOpen] = useState(false);
  const [modifier, setModifier] = useState(0);
  const [advMode, setAdvMode] = useState('normal'); // 'normal', 'adv', 'dis'
  const [history, setHistory] = useState([]);
  const [latestRoll, setLatestRoll] = useState(null);

  const rollDie = (sides) => {
    return Math.floor(Math.random() * sides) + 1;
  };

  const handleRoll = (sides) => {
    let result = {};
    const mod = parseInt(modifier, 10) || 0;

    if (sides === 20 && advMode !== 'normal') {
      const r1 = rollDie(20);
      const r2 = rollDie(20);
      const chosen = advMode === 'adv' ? Math.max(r1, r2) : Math.min(r1, r2);
      const total = chosen + mod;
      const isNat20 = chosen === 20;
      const isNat1 = chosen === 1;

      result = {
        id: Date.now() + Math.random(),
        die: 'd20',
        advMode,
        rolls: [r1, r2],
        chosen,
        mod,
        total,
        isNat20,
        isNat1,
        time: new Date().toLocaleTimeString([], { hour: '2-digit', minute: '2-digit', second: '2-digit' }),
      };
    } else {
      const r = rollDie(sides);
      const total = r + mod;
      const isNat20 = sides === 20 && r === 20;
      const isNat1 = sides === 20 && r === 1;

      result = {
        id: Date.now() + Math.random(),
        die: `d${sides}`,
        advMode: 'normal',
        rolls: [r],
        chosen: r,
        mod,
        total,
        isNat20,
        isNat1,
        time: new Date().toLocaleTimeString([], { hour: '2-digit', minute: '2-digit', second: '2-digit' }),
      };
    }

    setLatestRoll(result);
    setHistory((prev) => [result, ...prev.slice(0, 24)]);
  };

  const clearHistory = () => {
    setHistory([]);
    setLatestRoll(null);
  };

  return (
    <div className="fixed bottom-5 right-5 z-40">
      {/* Minimized Bubble Button */}
      {!isOpen && (
        <button
          onClick={() => setIsOpen(true)}
          className="flex items-center gap-2 px-4 py-3 bg-gradient-to-r from-emerald-600 to-teal-600 hover:from-emerald-500 hover:to-teal-500 text-slate-950 font-extrabold rounded-full shadow-2xl border border-emerald-400/40 hover:scale-105 transition-all text-sm group"
          title="Open Dice Tray"
        >
          <span className="text-xl group-hover:rotate-12 transition-transform">🎲</span>
          <span>Live Dice Tray</span>
          {latestRoll && (
            <span className="ml-1 px-2 py-0.5 rounded-full bg-slate-950/80 text-emerald-300 font-mono text-xs">
              {latestRoll.total}
            </span>
          )}
        </button>
      )}

      {/* Expanded Modal / Floating Tray */}
      {isOpen && (
        <div className="w-80 sm:w-96 bg-slate-950/95 border border-slate-700/80 rounded-2xl shadow-2xl backdrop-blur-xl flex flex-col overflow-hidden animate-in fade-in slide-in-from-bottom-5 duration-200">
          {/* Header */}
          <div className="flex items-center justify-between px-4 py-3 bg-slate-900/90 border-b border-slate-800">
            <div className="flex items-center gap-2">
              <span className="text-lg">🎲</span>
              <span className="font-bold text-white text-sm">Tabletop Dice Tray</span>
            </div>
            <div className="flex items-center gap-1">
              <button
                onClick={clearHistory}
                className="text-xs text-slate-400 hover:text-slate-200 px-2 py-1 rounded hover:bg-slate-800"
                title="Clear roll log"
              >
                Clear
              </button>
              <button
                onClick={() => setIsOpen(false)}
                className="text-slate-400 hover:text-white p-1 rounded-lg hover:bg-slate-800 transition-colors"
                title="Minimize tray"
              >
                ✕
              </button>
            </div>
          </div>

          {/* Controls Bar: Advantage & Modifier */}
          <div className="p-3 bg-slate-900/40 border-b border-slate-800/80 flex items-center justify-between gap-2 text-xs">
            {/* Advantage Mode */}
            <div className="flex bg-slate-950 border border-slate-800 rounded-lg p-0.5">
              <button
                onClick={() => setAdvMode('adv')}
                className={`px-2 py-1 rounded text-[11px] font-semibold transition-all ${
                  advMode === 'adv'
                    ? 'bg-emerald-500 text-slate-950 font-bold shadow'
                    : 'text-slate-400 hover:text-slate-200'
                }`}
                title="Roll 2d20, take highest"
              >
                ADV
              </button>
              <button
                onClick={() => setAdvMode('normal')}
                className={`px-2 py-1 rounded text-[11px] font-semibold transition-all ${
                  advMode === 'normal'
                    ? 'bg-slate-700 text-white font-bold'
                    : 'text-slate-400 hover:text-slate-200'
                }`}
              >
                NORM
              </button>
              <button
                onClick={() => setAdvMode('dis')}
                className={`px-2 py-1 rounded text-[11px] font-semibold transition-all ${
                  advMode === 'dis'
                    ? 'bg-rose-500 text-white font-bold shadow'
                    : 'text-slate-400 hover:text-slate-200'
                }`}
                title="Roll 2d20, take lowest"
              >
                DIS
              </button>
            </div>

            {/* Modifier Input */}
            <div className="flex items-center gap-1.5">
              <span className="text-slate-400 font-medium">Mod:</span>
              <input
                type="number"
                value={modifier}
                onChange={(e) => setModifier(e.target.value)}
                className="w-14 bg-slate-950 border border-slate-700 rounded px-2 py-1 text-white text-center font-mono font-bold focus:ring-1 focus:ring-emerald-500 focus:outline-none"
              />
            </div>
          </div>

          {/* Dice Buttons Row */}
          <div className="p-3 grid grid-cols-4 sm:grid-cols-7 gap-1.5 border-b border-slate-800/80">
            {DICE_TYPES.map((d) => (
              <button
                key={d.label}
                onClick={() => handleRoll(d.sides)}
                className={`flex flex-col items-center justify-center p-2 rounded-xl border transition-all active:scale-95 ${
                  d.sides === 20
                    ? 'bg-emerald-500/15 border-emerald-500/40 text-emerald-300 hover:bg-emerald-500/25 hover:border-emerald-400'
                    : 'bg-slate-900 border-slate-800 text-slate-300 hover:bg-slate-800 hover:text-white hover:border-slate-700'
                }`}
              >
                <span className="text-sm">{d.icon}</span>
                <span className="text-xs font-bold font-mono mt-0.5">{d.label}</span>
              </button>
            ))}
          </div>

          {/* Result Banner */}
          {latestRoll && (
            <div
              className={`p-3 text-center border-b border-slate-800 ${
                latestRoll.isNat20
                  ? 'bg-emerald-950/70 border-emerald-500/40 text-emerald-200 animate-pulse'
                  : latestRoll.isNat1
                  ? 'bg-rose-950/70 border-rose-500/40 text-rose-200'
                  : 'bg-slate-900/60 text-slate-200'
              }`}
            >
              <div className="text-3xl font-extrabold font-mono tracking-tight flex items-center justify-center gap-2">
                <span>{latestRoll.total}</span>
                {latestRoll.isNat20 && <span className="text-sm font-bold text-amber-300 uppercase tracking-widest bg-amber-500/20 px-2 py-0.5 rounded border border-amber-500/30">Natural 20!</span>}
                {latestRoll.isNat1 && <span className="text-sm font-bold text-rose-300 uppercase tracking-widest bg-rose-500/20 px-2 py-0.5 rounded border border-rose-500/30">Critical Fail!</span>}
              </div>
              <div className="text-xs text-slate-400 font-mono mt-1">
                {latestRoll.advMode !== 'normal'
                  ? `[${latestRoll.rolls.join(', ')}] (take ${latestRoll.chosen}) ${latestRoll.mod >= 0 ? `+ ${latestRoll.mod}` : `- ${Math.abs(latestRoll.mod)}`}`
                  : `Die: [${latestRoll.chosen}] ${latestRoll.mod >= 0 ? `+ ${latestRoll.mod}` : `- ${Math.abs(latestRoll.mod)}`}`}
              </div>
            </div>
          )}

          {/* History Scroll Area */}
          <div className="max-h-44 overflow-y-auto p-2 space-y-1 text-xs font-mono">
            {history.length === 0 ? (
              <div className="text-center py-6 text-slate-500 italic">No rolls yet. Click any die above!</div>
            ) : (
              history.map((h) => (
                <div
                  key={h.id}
                  className="flex items-center justify-between px-2.5 py-1.5 rounded bg-slate-900/50 border border-slate-800/60 hover:bg-slate-900 transition-colors"
                >
                  <div className="flex items-center gap-2">
                    <span className="text-slate-500 text-[10px]">{h.time}</span>
                    <span className="font-bold text-slate-300">{h.die}</span>
                    {h.advMode !== 'normal' && (
                      <span className={`text-[10px] px-1 py-0.2 rounded font-bold ${h.advMode === 'adv' ? 'bg-emerald-500/20 text-emerald-400' : 'bg-rose-500/20 text-rose-400'}`}>
                        {h.advMode.toUpperCase()}
                      </span>
                    )}
                    <span className="text-slate-400">
                      [{h.rolls.join(', ')}]
                    </span>
                  </div>
                  <div className="flex items-center gap-1.5">
                    {h.mod !== 0 && (
                      <span className="text-slate-500 text-[11px]">
                        {h.mod > 0 ? `+${h.mod}` : h.mod}
                      </span>
                    )}
                    <span
                      className={`font-bold px-1.5 py-0.5 rounded text-xs ${
                        h.isNat20
                          ? 'bg-amber-500/20 text-amber-300 font-extrabold'
                          : h.isNat1
                          ? 'bg-rose-500/20 text-rose-400 font-extrabold'
                          : 'text-white'
                      }`}
                    >
                      = {h.total}
                    </span>
                  </div>
                </div>
              ))
            )}
          </div>
        </div>
      )}
    </div>
  );
}
