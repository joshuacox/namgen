'use client';

import React, { useState, useEffect } from 'react';
import { DUNGEON_DATA } from './dmscreenData';

export default function DungeonDelver({ wasmModule }) {
  const [dungeonTitle, setDungeonTitle] = useState('The Sunken Crypt of Karas');
  const [r1Index, setR1Index] = useState(0);
  const [r2Index, setR2Index] = useState(0);
  const [r3Index, setR3Index] = useState(0);
  const [r4Index, setR4Index] = useState(0);
  const [r5Index, setR5Index] = useState(0);
  const [copied, setCopied] = useState(false);

  const rollDungeonName = () => {
    if (wasmModule && wasmModule.callMain) {
      try {
        let captured = '';
        const oldOut = wasmModule.print;
        wasmModule.print = (text) => { captured += text + '\n'; };
        wasmModule.callMain(['--descriptions-dungeons', '-c', '1']);
        wasmModule.print = oldOut;
        const line = captured.trim().split('\n')[0];
        if (line) return line.slice(0, 36);
      } catch (err) {
        console.warn('WASM roll error:', err);
      }
    }
    const fallbacks = [
      'The Weeping Catacombs', 'The Obsidian Vault', 'Caverns of the Pale Eye',
      'The Sunken Hall of Karas', 'The Tomb of the Black Rose',
    ];
    return fallbacks[Math.floor(Math.random() * fallbacks.length)];
  };

  const rollFullDungeon = () => {
    setDungeonTitle(rollDungeonName());
    setR1Index((p) => p + 1);
    setR2Index((p) => p + 1);
    setR3Index((p) => p + 1);
    setR4Index((p) => p + 1);
    setR5Index((p) => p + 1);
  };

  useEffect(() => {
    if (wasmModule) {
      setDungeonTitle(rollDungeonName());
    }
  }, [wasmModule]);

  const r1 = DUNGEON_DATA.room1Entrance[r1Index % DUNGEON_DATA.room1Entrance.length];
  const r2 = DUNGEON_DATA.room2Hazards[r2Index % DUNGEON_DATA.room2Hazards.length];
  const r3 = DUNGEON_DATA.room3Setbacks[r3Index % DUNGEON_DATA.room3Setbacks.length];
  const r4 = DUNGEON_DATA.room4BossSanctums[r4Index % DUNGEON_DATA.room4BossSanctums.length];
  const r5 = DUNGEON_DATA.room5Hoards[r5Index % DUNGEON_DATA.room5Hoards.length];

  const copyMarkdown = async () => {
    let md = `# 5-Room Dungeon: [[${dungeonTitle}]]\n\n`;
    md += `### Room 1: Entrance & Threshold — [[${r1.name}]]\n${r1.desc}\n\n`;
    md += `### Room 2: Puzzle & Hazard — [[${r2.name}]]\n* **Check**: \`${r2.dc}\`\n* **Description**: ${r2.desc}\n\n`;
    md += `### Room 3: The Setback & Guardian — [[${r3.name}]]\n* **Monsters**: ${r3.monster}\n* **Tactics**: ${r3.desc}\n\n`;
    md += `### Room 4: Boss Sanctum — [[${r4.name}]]\n* **Boss**: ${r4.boss}\n* **Lair Hazard**: ${r4.lairHazard}\n* **Scene**: ${r4.desc}\n\n`;
    md += `### Room 5: The Hoard & Reward — [[${r5.name}]]\n* **Loot**: ${r5.reward}\n`;

    await navigator.clipboard.writeText(md);
    setCopied(true);
    setTimeout(() => setCopied(false), 2000);
  };

  return (
    <div className="space-y-6">
      {/* Header */}
      <div className="bg-slate-950/80 border border-slate-800 rounded-2xl p-6 backdrop-blur-md shadow-xl flex flex-col sm:flex-row items-center justify-between gap-4">
        <div className="flex items-center gap-3 w-full sm:w-auto">
          <span className="text-3xl p-2.5 rounded-xl bg-purple-500/10 border border-purple-500/20 text-purple-400">
            🗝️
          </span>
          <div>
            <span className="text-xs uppercase tracking-wider font-bold text-purple-400">
              5-Room Procedural Adventure
            </span>
            <h3 className="text-2xl font-extrabold text-white">
              {dungeonTitle}
            </h3>
          </div>
        </div>

        <div className="flex items-center gap-2.5 w-full sm:w-auto justify-end">
          <button
            onClick={rollFullDungeon}
            className="px-4 py-2 bg-gradient-to-r from-purple-500 to-indigo-500 hover:from-purple-400 hover:to-indigo-400 text-slate-950 font-bold rounded-lg shadow-lg hover:shadow-purple-500/25 transition-all flex items-center gap-1.5 text-sm"
          >
            <span>🎲</span> Roll New Dungeon
          </button>
          <button
            onClick={copyMarkdown}
            className="px-3.5 py-2 bg-slate-800 hover:bg-slate-700 text-slate-200 text-xs sm:text-sm font-semibold rounded-lg border border-slate-700 transition-all flex items-center gap-1.5"
          >
            <span>{copied ? '✅' : '📋'}</span> {copied ? 'Copied Dungeon!' : 'Copy Dungeon Note'}
          </button>
        </div>
      </div>

      {/* 5 Rooms Cards */}
      <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-5">
        {/* Room 1 */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-5 shadow-md flex flex-col justify-between">
          <div>
            <div className="flex items-center justify-between mb-2">
              <span className="text-xs uppercase font-bold text-emerald-400 tracking-wider">
                🚪 Room 1: Entrance &amp; Threshold
              </span>
              <button onClick={() => setR1Index((p) => p + 1)} className="text-xs text-purple-400 hover:underline">
                Re-roll
              </button>
            </div>
            <h4 className="text-base font-bold text-white mb-2">{r1.name}</h4>
            <p className="text-slate-300 text-sm leading-relaxed">{r1.desc}</p>
          </div>
        </div>

        {/* Room 2 */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-5 shadow-md flex flex-col justify-between">
          <div>
            <div className="flex items-center justify-between mb-2">
              <span className="text-xs uppercase font-bold text-amber-400 tracking-wider">
                ⚡ Room 2: Puzzle / Hazard / Trap
              </span>
              <button onClick={() => setR2Index((p) => p + 1)} className="text-xs text-purple-400 hover:underline">
                Re-roll
              </button>
            </div>
            <h4 className="text-base font-bold text-white mb-1.5">{r2.name}</h4>
            <div className="text-xs font-mono text-amber-300 mb-2 bg-amber-500/10 px-2 py-0.5 rounded border border-amber-500/20 inline-block">
              {r2.dc}
            </div>
            <p className="text-slate-300 text-sm leading-relaxed">{r2.desc}</p>
          </div>
        </div>

        {/* Room 3 */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-5 shadow-md flex flex-col justify-between">
          <div>
            <div className="flex items-center justify-between mb-2">
              <span className="text-xs uppercase font-bold text-red-400 tracking-wider">
                ⚔️ Room 3: Setback &amp; Guardians
              </span>
              <button onClick={() => setR3Index((p) => p + 1)} className="text-xs text-purple-400 hover:underline">
                Re-roll
              </button>
            </div>
            <h4 className="text-base font-bold text-white mb-1.5">{r3.name}</h4>
            <div className="text-xs font-medium text-red-300 mb-2">
              Guards: {r3.monster}
            </div>
            <p className="text-slate-300 text-sm leading-relaxed">{r3.desc}</p>
          </div>
        </div>

        {/* Room 4 */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-5 shadow-md flex flex-col justify-between md:col-span-2">
          <div>
            <div className="flex items-center justify-between mb-2">
              <span className="text-xs uppercase font-bold text-purple-400 tracking-wider">
                👑 Room 4: Boss Sanctum &amp; Climax
              </span>
              <button onClick={() => setR4Index((p) => p + 1)} className="text-xs text-purple-400 hover:underline">
                Re-roll
              </button>
            </div>
            <h4 className="text-base font-bold text-white mb-1.5">{r4.name}</h4>
            <div className="text-xs font-semibold text-purple-300 mb-1">
              Boss: {r4.boss}
            </div>
            <div className="text-xs text-slate-400 mb-2 bg-slate-900 p-2 rounded border border-slate-800">
              <strong className="text-amber-400">Lair Hazard:</strong> {r4.lairHazard}
            </div>
            <p className="text-slate-300 text-sm leading-relaxed">{r4.desc}</p>
          </div>
        </div>

        {/* Room 5 */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-5 shadow-md flex flex-col justify-between">
          <div>
            <div className="flex items-center justify-between mb-2">
              <span className="text-xs uppercase font-bold text-teal-400 tracking-wider">
                💰 Room 5: Hoard &amp; Reward
              </span>
              <button onClick={() => setR5Index((p) => p + 1)} className="text-xs text-purple-400 hover:underline">
                Re-roll
              </button>
            </div>
            <h4 className="text-base font-bold text-white mb-2">{r5.name}</h4>
            <p className="text-teal-200/90 text-sm leading-relaxed bg-teal-950/30 p-3 rounded-lg border border-teal-900/40">
              {r5.reward}
            </p>
          </div>
        </div>
      </div>
    </div>
  );
}
