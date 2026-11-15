'use client';

import React, { useState } from 'react';

const DICE_TYPES = [
  { label: 'd4', sides: 4 },
  { label: 'd6', sides: 6 },
  { label: 'd8', sides: 8 },
  { label: 'd10', sides: 10 },
  { label: 'd12', sides: 12 },
  { label: 'd20', sides: 20 },
  { label: 'd100', sides: 100 },
];

/**
 * Evaluate tabletop dice expressions such as "2d6+3", "4d6kh3", "1d20-1", "8d6".
 */
function parseAndRollFormula(rawExpr) {
  const expr = String(rawExpr || '').replace(/\s+/g, '').toLowerCase();
  const match = expr.match(/^(\d+)d(\d+)(?:kh(\d+)|kl(\d+))?([+-]\d+)?$/);
  if (!match) return null;

  const count = Math.min(100, Math.max(1, parseInt(match[1], 10)));
  const sides = Math.min(1000, Math.max(2, parseInt(match[2], 10)));
  const keepHigh = match[3] ? parseInt(match[3], 10) : 0;
  const keepLow = match[4] ? parseInt(match[4], 10) : 0;
  const mod = match[5] ? parseInt(match[5], 10) : 0;

  const rolls = [];
  for (let i = 0; i < count; i++) {
    rolls.push(Math.floor(Math.random() * sides) + 1);
  }

  let kept = [...rolls];
  if (keepHigh > 0 && keepHigh < rolls.length) {
    kept = [...rolls].sort((a, b) => b - a).slice(0, keepHigh);
  } else if (keepLow > 0 && keepLow < rolls.length) {
    kept = [...rolls].sort((a, b) => a - b).slice(0, keepLow);
  }

  const sum = kept.reduce((acc, n) => acc + n, 0) + mod;
  return {
    die: expr,
    advMode: 'formula',
    rolls,
    kept,
    mod,
    total: sum,
    isNat20: count === 1 && sides === 20 && rolls[0] === 20,
    isNat1: count === 1 && sides === 20 && rolls[0] === 1,
  };
}

export default function DiceRollerDrawer({ isOpen, onToggle }) {
  const [modifier, setModifier] = useState(0);
  const [advMode, setAdvMode] = useState('normal');
  const [formula, setFormula] = useState('2d6+3');
  const [formulaErr, setFormulaErr] = useState('');
  const [latestRoll, setLatestRoll] = useState(null);
  const [history, setHistory] = useState([]);

  const pushResult = (entry) => {
    const stamped = {
      id: `${Date.now()}_${Math.random()}`,
      time: new Date().toLocaleTimeString([], { hour: '2-digit', minute: '2-digit', second: '2-digit' }),
      ...entry,
    };
    setLatestRoll(stamped);
    setHistory((prev) => [stamped, ...prev.slice(0, 29)]);
  };

  const rollSingle = (sides) => {
    const mod = parseInt(modifier, 10) || 0;
    if (sides === 20 && advMode !== 'normal') {
      const r1 = Math.floor(Math.random() * 20) + 1;
      const r2 = Math.floor(Math.random() * 20) + 1;
      const chosen = advMode === 'adv' ? Math.max(r1, r2) : Math.min(r1, r2);
      pushResult({
        die: 'd20',
        advMode,
        rolls: [r1, r2],
        kept: [chosen],
        mod,
        total: chosen + mod,
        isNat20: chosen === 20,
        isNat1: chosen === 1,
      });
      return;
    }

    const r = Math.floor(Math.random() * sides) + 1;
    pushResult({
      die: `d${sides}`,
      advMode: 'normal',
      rolls: [r],
      kept: [r],
      mod,
      total: r + mod,
      isNat20: sides === 20 && r === 20,
      isNat1: sides === 20 && r === 1,
    });
  };

  const handleFormulaSubmit = (e) => {
    e.preventDefault();
    const res = parseAndRollFormula(formula);
    if (!res) {
      setFormulaErr('Use format like 2d6+3, 4d6kh3, or 8d6');
      return;
    }
    setFormulaErr('');
    pushResult(res);
  };

  return (
    <div className="fixed bottom-4 right-4 z-40 no-print">
      {!isOpen && (
        <button
          type="button"
          onClick={() => onToggle(true)}
          className="flex items-center gap-2 px-4 py-2.5 rounded-full bg-gradient-to-r from-amber-500 to-orange-500 hover:from-amber-400 hover:to-orange-400 text-slate-950 font-extrabold text-sm shadow-2xl border border-amber-300/40 transition-transform hover:scale-105"
          title="Open Dice Tray"
        >
          <span>🎲</span>
          <span>Dice Tray</span>
          {latestRoll && (
            <span className="px-2 py-0.5 rounded-full bg-slate-950/85 text-amber-300 font-mono text-xs">
              {latestRoll.total}
            </span>
          )}
        </button>
      )}

      {isOpen && (
        <div className="w-80 sm:w-96 bg-slate-950/95 border border-slate-700/90 rounded-2xl shadow-2xl backdrop-blur-xl overflow-hidden flex flex-col">
          <div className="flex items-center justify-between px-4 py-3 bg-slate-900 border-b border-slate-800">
            <div className="flex items-center gap-2">
              <span>🎲</span>
              <span className="font-bold text-white text-sm">DM Dice Tray &amp; Formula Roller</span>
            </div>
            <div className="flex items-center gap-2">
              <button
                type="button"
                onClick={() => { setHistory([]); setLatestRoll(null); }}
                className="text-xs text-slate-400 hover:text-white px-2 py-0.5 rounded hover:bg-slate-800"
              >
                Clear
              </button>
              <button
                type="button"
                onClick={() => onToggle(false)}
                className="text-slate-400 hover:text-white px-2 py-0.5 rounded hover:bg-slate-800"
              >
                ✕
              </button>
            </div>
          </div>

          {/* Adv / Mod row */}
          <div className="p-3 bg-slate-900/50 border-b border-slate-800 flex items-center justify-between gap-2 text-xs">
            <div className="flex bg-slate-950 border border-slate-800 rounded-lg p-0.5">
              {['adv', 'normal', 'dis'].map((m) => (
                <button
                  key={m}
                  type="button"
                  onClick={() => setAdvMode(m)}
                  className={`px-2 py-1 rounded text-[11px] font-bold uppercase ${
                    advMode === m
                      ? m === 'adv'
                        ? 'bg-emerald-500 text-slate-950'
                        : m === 'dis'
                        ? 'bg-rose-500 text-white'
                        : 'bg-slate-700 text-white'
                      : 'text-slate-400 hover:text-white'
                  }`}
                >
                  {m === 'normal' ? 'Norm' : m}
                </button>
              ))}
            </div>
            <div className="flex items-center gap-1.5">
              <span className="text-slate-400">Mod:</span>
              <input
                type="number"
                value={modifier}
                onChange={(e) => setModifier(e.target.value)}
                className="w-16 bg-slate-950 border border-slate-700 rounded px-2 py-1 text-white text-center font-mono font-bold focus:outline-none focus:border-amber-500"
              />
            </div>
          </div>

          {/* Polyhedral buttons */}
          <div className="p-3 grid grid-cols-7 gap-1.5 border-b border-slate-800">
            {DICE_TYPES.map((d) => (
              <button
                key={d.label}
                type="button"
                onClick={() => rollSingle(d.sides)}
                className={`py-2 rounded-lg border font-mono text-xs font-bold transition-all active:scale-95 ${
                  d.sides === 20
                    ? 'bg-amber-500/20 border-amber-500/50 text-amber-300 hover:bg-amber-500/30'
                    : 'bg-slate-900 border-slate-800 text-slate-200 hover:bg-slate-800'
                }`}
              >
                {d.label}
              </button>
            ))}
          </div>

          {/* Custom formula */}
          <form onSubmit={handleFormulaSubmit} className="p-3 border-b border-slate-800 space-y-1.5">
            <div className="flex gap-1.5">
              <input
                type="text"
                value={formula}
                onChange={(e) => setFormula(e.target.value)}
                placeholder="2d6+3, 4d6kh3, 8d6"
                className="flex-1 bg-slate-900 border border-slate-700 rounded-lg px-2.5 py-1.5 text-xs font-mono text-white focus:outline-none focus:border-amber-500"
              />
              <button
                type="submit"
                className="px-3 py-1.5 rounded-lg bg-amber-500 hover:bg-amber-400 text-slate-950 text-xs font-bold"
              >
                Roll
              </button>
            </div>
            <div className="flex flex-wrap gap-1">
              {['4d6kh3', '2d6+3', '8d6', '1d8+4', '1d100'].map((preset) => (
                <button
                  key={preset}
                  type="button"
                  onClick={() => {
                    setFormula(preset);
                    const res = parseAndRollFormula(preset);
                    if (res) { setFormulaErr(''); pushResult(res); }
                  }}
                  className="text-[10px] font-mono px-1.5 py-0.5 rounded bg-slate-900 border border-slate-800 text-slate-400 hover:text-amber-300"
                >
                  {preset}
                </button>
              ))}
            </div>
            {formulaErr && <p className="text-[11px] text-rose-400">{formulaErr}</p>}
          </form>

          {/* Latest Roll */}
          {latestRoll && (
            <div
              className={`p-3 text-center border-b border-slate-800 ${
                latestRoll.isNat20
                  ? 'bg-emerald-950/60 text-emerald-200'
                  : latestRoll.isNat1
                  ? 'bg-rose-950/60 text-rose-200'
                  : 'bg-slate-900/60 text-slate-100'
              }`}
            >
              <div className="text-3xl font-extrabold font-mono flex items-center justify-center gap-2">
                <span>{latestRoll.total}</span>
                {latestRoll.isNat20 && (
                  <span className="text-xs px-2 py-0.5 rounded bg-amber-500/20 text-amber-300 border border-amber-500/40">
                    NAT 20!
                  </span>
                )}
                {latestRoll.isNat1 && (
                  <span className="text-xs px-2 py-0.5 rounded bg-rose-500/20 text-rose-300 border border-rose-500/40">
                    NAT 1!
                  </span>
                )}
              </div>
              <div className="text-[11px] font-mono text-slate-400 mt-1">
                {latestRoll.die}: [{latestRoll.rolls.join(', ')}]
                {latestRoll.mod !== 0 ? ` ${latestRoll.mod > 0 ? '+' : ''}${latestRoll.mod}` : ''}
              </div>
            </div>
          )}

          {/* History */}
          <div className="max-h-40 overflow-y-auto p-2 space-y-1 text-xs font-mono">
            {history.length === 0 ? (
              <div className="text-center py-4 text-slate-500 italic">Click any die or formula above</div>
            ) : (
              history.map((h) => (
                <div
                  key={h.id}
                  className="flex items-center justify-between px-2 py-1 rounded bg-slate-900/60 border border-slate-800/70"
                >
                  <span className="text-slate-400 truncate max-w-[180px]">
                    {h.die} [{h.rolls.join(',')}]
                  </span>
                  <span className="font-bold text-white">= {h.total}</span>
                </div>
              ))
            )}
          </div>
        </div>
      )}
    </div>
  );
}
