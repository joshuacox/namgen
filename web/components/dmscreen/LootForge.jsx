'use client';

import React, { useState } from 'react';
import { LOOT_DATA } from './dmscreenData';

export default function LootForge() {
  const [weaponIndex, setWeaponIndex] = useState(0);
  const [potion1Index, setPotion1Index] = useState(0);
  const [potion2Index, setPotion2Index] = useState(1);
  const [curio1Index, setCurio1Index] = useState(0);
  const [curio2Index, setCurio2Index] = useState(2);
  const [goldMultiplier, setGoldMultiplier] = useState(1);
  const [copied, setCopied] = useState(false);

  const weapon = LOOT_DATA.weapons[weaponIndex % LOOT_DATA.weapons.length];
  const potion1 = LOOT_DATA.potions[potion1Index % LOOT_DATA.potions.length];
  const potion2 = LOOT_DATA.potions[potion2Index % LOOT_DATA.potions.length];
  const curio1 = LOOT_DATA.curios[curio1Index % LOOT_DATA.curios.length];
  const curio2 = LOOT_DATA.curios[curio2Index % LOOT_DATA.curios.length];

  const rollFullHoard = () => {
    setWeaponIndex((p) => p + 1);
    setPotion1Index((p) => p + 1);
    setPotion2Index((p) => p + 2);
    setCurio1Index((p) => p + 1);
    setCurio2Index((p) => p + 2);
    setGoldMultiplier(Math.floor(Math.random() * 5) + 1);
  };

  const gpAmount = 350 * goldMultiplier;
  const spAmount = 1400 * goldMultiplier;
  const ppAmount = 15 * goldMultiplier;

  const copyMarkdown = async () => {
    let md = `## Encounter Treasure Hoard\n\n`;
    md += `### Signature Relic: [[${weapon.name}]] (${weapon.type})\n`;
    md += `* **Value**: ${weapon.val}\n`;
    md += `* **Lore & History**: ${weapon.lore}\n\n`;
    md += `### Potions & Alchemy\n`;
    md += `1. **[[${potion1.name}]]** (${potion1.color}): ${potion1.benefit} *Side-effect: ${potion1.quirk}*\n`;
    md += `2. **[[${potion2.name}]]** (${potion2.color}): ${potion2.benefit} *Side-effect: ${potion2.quirk}*\n\n`;
    md += `### Valuables & Art Objects\n`;
    md += `* ${curio1.item} (${curio1.val})\n`;
    md += `* ${curio2.item} (${curio2.val})\n\n`;
    md += `### Coinage\n`;
    md += `* **Gold**: ${gpAmount} gp | **Silver**: ${spAmount} sp | **Platinum**: ${ppAmount} pp\n`;

    await navigator.clipboard.writeText(md);
    setCopied(true);
    setTimeout(() => setCopied(false), 2000);
  };

  return (
    <div className="space-y-6">
      {/* Header */}
      <div className="bg-slate-950/80 border border-slate-800 rounded-2xl p-6 backdrop-blur-md shadow-xl flex flex-col sm:flex-row items-center justify-between gap-4">
        <div className="flex items-center gap-3 w-full sm:w-auto">
          <span className="text-3xl p-2.5 rounded-xl bg-teal-500/10 border border-teal-500/20 text-teal-400">
            💎
          </span>
          <div>
            <span className="text-xs uppercase tracking-wider font-bold text-teal-400">
              Treasure Hoard &amp; Relic Crafter
            </span>
            <h3 className="text-2xl font-extrabold text-white">
              Loot &amp; Magic Item Forge
            </h3>
          </div>
        </div>

        <div className="flex items-center gap-2.5 w-full sm:w-auto justify-end">
          <button
            onClick={rollFullHoard}
            className="px-4 py-2 bg-gradient-to-r from-teal-500 to-emerald-500 hover:from-teal-400 hover:to-emerald-400 text-slate-950 font-bold rounded-lg shadow-lg hover:shadow-teal-500/25 transition-all flex items-center gap-1.5 text-sm"
          >
            <span>🎲</span> Forge New Loot
          </button>
          <button
            onClick={copyMarkdown}
            className="px-3.5 py-2 bg-slate-800 hover:bg-slate-700 text-slate-200 text-xs sm:text-sm font-semibold rounded-lg border border-slate-700 transition-all flex items-center gap-1.5"
          >
            <span>{copied ? '✅' : '📋'}</span> {copied ? 'Copied Loot!' : 'Copy Loot Note'}
          </button>
        </div>
      </div>

      {/* Grid: Weapon & Coins */}
      <div className="grid grid-cols-1 md:grid-cols-3 gap-5">
        {/* Named Relic Weapon (2 cols) */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-5 shadow-md md:col-span-2 flex flex-col justify-between">
          <div>
            <div className="flex items-center justify-between mb-2">
              <span className="text-xs uppercase font-bold text-emerald-400 tracking-wider">
                ⚔️ Signature Magical Weapon / Armor
              </span>
              <button onClick={() => setWeaponIndex((p) => p + 1)} className="text-xs text-teal-400 hover:underline">
                Re-roll
              </button>
            </div>
            <div className="flex items-baseline gap-3 mb-2">
              <h4 className="text-xl font-extrabold text-white">{weapon.name}</h4>
              <span className="text-xs font-semibold text-emerald-400 bg-emerald-500/10 px-2 py-0.5 rounded border border-emerald-500/20">
                {weapon.type}
              </span>
            </div>
            <p className="text-slate-300 text-sm leading-relaxed mb-3">{weapon.lore}</p>
          </div>
          <div className="text-xs font-mono text-slate-400 pt-2 border-t border-slate-800/80">
            Market Value: <span className="text-amber-300 font-bold">{weapon.val}</span>
          </div>
        </div>

        {/* Coin Hoard */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-5 shadow-md flex flex-col justify-between">
          <div>
            <span className="text-xs uppercase font-bold text-amber-400 tracking-wider block mb-2">
              💰 Coinage Hoard
            </span>
            <div className="space-y-2.5 text-sm">
              <div className="flex justify-between items-center bg-slate-900/80 px-3 py-2 rounded-lg border border-slate-800">
                <span className="text-amber-300 font-semibold">Gold (GP)</span>
                <span className="font-mono text-white font-bold">{gpAmount} gp</span>
              </div>
              <div className="flex justify-between items-center bg-slate-900/80 px-3 py-2 rounded-lg border border-slate-800">
                <span className="text-slate-300 font-semibold">Silver (SP)</span>
                <span className="font-mono text-white font-bold">{spAmount} sp</span>
              </div>
              <div className="flex justify-between items-center bg-slate-900/80 px-3 py-2 rounded-lg border border-slate-800">
                <span className="text-teal-300 font-semibold">Platinum (PP)</span>
                <span className="font-mono text-white font-bold">{ppAmount} pp</span>
              </div>
            </div>
          </div>
        </div>
      </div>

      {/* Potions with Quirks & Art Curios */}
      <div className="grid grid-cols-1 md:grid-cols-2 gap-5">
        {/* Potions */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-5 shadow-md">
          <div className="flex items-center justify-between mb-3">
            <span className="text-xs uppercase font-bold text-purple-400 tracking-wider">
              🧪 2 Quirky Potions
            </span>
            <button
              onClick={() => {
                setPotion1Index((p) => p + 1);
                setPotion2Index((p) => p + 1);
              }}
              className="text-xs text-teal-400 hover:underline"
            >
              Re-roll
            </button>
          </div>
          <div className="space-y-3">
            <div className="bg-slate-900/60 p-3.5 rounded-lg border border-slate-800">
              <div className="flex justify-between items-center mb-1">
                <h5 className="font-bold text-white text-sm">{potion1.name}</h5>
                <span className="text-[10px] text-purple-300 bg-purple-500/10 px-2 py-0.5 rounded border border-purple-500/20">
                  {potion1.color}
                </span>
              </div>
              <p className="text-xs text-slate-300 mb-1">{potion1.benefit}</p>
              <p className="text-[11px] text-amber-400/90 italic">Side-effect: {potion1.quirk}</p>
            </div>

            <div className="bg-slate-900/60 p-3.5 rounded-lg border border-slate-800">
              <div className="flex justify-between items-center mb-1">
                <h5 className="font-bold text-white text-sm">{potion2.name}</h5>
                <span className="text-[10px] text-purple-300 bg-purple-500/10 px-2 py-0.5 rounded border border-purple-500/20">
                  {potion2.color}
                </span>
              </div>
              <p className="text-xs text-slate-300 mb-1">{potion2.benefit}</p>
              <p className="text-[11px] text-amber-400/90 italic">Side-effect: {potion2.quirk}</p>
            </div>
          </div>
        </div>

        {/* Curios & Art Objects */}
        <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-5 shadow-md">
          <div className="flex items-center justify-between mb-3">
            <span className="text-xs uppercase font-bold text-blue-400 tracking-wider">
              🏺 Art Objects &amp; Valuables
            </span>
            <button
              onClick={() => {
                setCurio1Index((p) => p + 1);
                setCurio2Index((p) => p + 1);
              }}
              className="text-xs text-teal-400 hover:underline"
            >
              Re-roll
            </button>
          </div>
          <div className="space-y-3">
            <div className="bg-slate-900/60 p-3.5 rounded-lg border border-slate-800 flex justify-between items-center">
              <p className="text-xs text-slate-200">{curio1.item}</p>
              <span className="font-mono text-xs font-bold text-amber-300 whitespace-nowrap ml-3">
                {curio1.val}
              </span>
            </div>
            <div className="bg-slate-900/60 p-3.5 rounded-lg border border-slate-800 flex justify-between items-center">
              <p className="text-xs text-slate-200">{curio2.item}</p>
              <span className="font-mono text-xs font-bold text-amber-300 whitespace-nowrap ml-3">
                {curio2.val}
              </span>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}
