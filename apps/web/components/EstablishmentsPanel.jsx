'use client';

import React, { useState, useEffect } from 'react';
import { SHOP_TYPES } from 'namgen.js/dnd';

export default function EstablishmentsPanel({
  onSaveCodex,
  onAppendSessionNote,
  onRevealHandout,
  onWeaveWithAi,
  onNotify,
}) {
  const shopKeys = Object.keys(SHOP_TYPES);
  const [shopType, setShopType] = useState('tavern');
  const [seed, setSeed] = useState('');
  const [establishment, setEstablishment] = useState(null);
  const [loading, setLoading] = useState(false);

  const generateEstablishment = async (nextType = shopType, nextSeed = seed) => {
    setLoading(true);
    try {
      const res = await fetch('/api/namgen', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          action: 'establishment',
          shopType: nextType,
          seed: nextSeed,
        }),
      });
      const data = await res.json();
      if (data.establishment) {
        setEstablishment(data.establishment);
      } else {
        onNotify?.(data.error || 'Could not generate establishment');
      }
    } catch (err) {
      onNotify?.(`Establishment generation error: ${err.message}`);
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => {
    generateEstablishment('tavern', '');
  }, []);

  const est = establishment;

  const revealToPlayers = () => {
    if (!est) return;
    const menuItems = [
      {
        label: `House Special: ${est.houseSpecial.food} & ${est.houseSpecial.brew}`,
        detail: 'Featured specialty on the chalkboard',
        price: est.houseSpecial.price,
      },
      ...est.inventory.map((row) => ({
        label: row.item,
        detail: `${row.category}${row.note ? ` — ${row.note}` : ''}`,
        price: row.price,
      })),
    ];

    onRevealHandout?.({
      kind: 'establishment',
      title: est.name,
      subtitle: `${est.shopLabel} • ${est.proprietor?.name || 'Proprietor'}`,
      body: `${est.atmosphere}\n\n${est.description}`,
      items: menuItems,
    });
  };

  return (
    <div className="space-y-5">
      {/* Controls Bar */}
      <section className="bg-slate-900/80 border border-slate-800 rounded-2xl p-4 flex flex-wrap items-center justify-between gap-3">
        <div className="flex flex-wrap gap-2">
          {shopKeys.map((key) => {
            const cfg = SHOP_TYPES[key];
            const active = shopType === key;
            return (
              <button
                key={key}
                type="button"
                onClick={() => {
                  setShopType(key);
                  generateEstablishment(key, seed);
                }}
                className={`px-3 py-2 rounded-xl text-xs font-semibold border flex items-center gap-1.5 transition-colors ${
                  active
                    ? 'bg-amber-500/20 border-amber-500/60 text-amber-200'
                    : 'bg-slate-950 border-slate-800 text-slate-300 hover:border-slate-700 hover:text-white'
                }`}
              >
                <span>{cfg.icon}</span>
                <span>{cfg.label}</span>
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
            onClick={() => generateEstablishment(shopType, seed)}
            disabled={loading}
            className="px-4 py-2 rounded-xl bg-amber-500 hover:bg-amber-400 disabled:opacity-50 text-slate-950 text-xs font-bold"
          >
            {loading ? 'Generating...' : '🍺 Generate Establishment'}
          </button>
        </div>
      </section>

      {est && (
        <div className="grid grid-cols-1 xl:grid-cols-12 gap-5">
          {/* Left: Signboard, Menu & Inventory */}
          <section className="xl:col-span-7 bg-slate-900/80 border border-slate-800 rounded-2xl p-5 space-y-4">
            <div className="flex flex-wrap items-start justify-between gap-3 pb-3 border-b border-slate-800">
              <div>
                <div className="flex items-center gap-2 text-xs font-mono uppercase text-amber-400">
                  <span>{est.icon}</span>
                  <span>{est.shopLabel}</span>
                </div>
                <h2 className="text-2xl font-extrabold text-white mt-0.5">{est.name}</h2>
                <p className="text-xs text-emerald-300 mt-1">{est.atmosphere}</p>
              </div>

              <div className="flex flex-wrap gap-1.5">
                <button
                  type="button"
                  onClick={() =>
                    onSaveCodex?.({
                      kind: 'place',
                      title: est.name,
                      subtitle: `${est.shopLabel} • Proprietor: ${est.proprietor?.name}`,
                      status: 'Visited',
                      tags: [est.shopType, 'shop'],
                      summary: `${est.atmosphere}\n${est.description}`,
                      dmNotes: `Proprietor Secret: ${est.proprietor?.secret} | Patron: ${est.patron?.name} — ${est.patron?.hook}`,
                      data: est,
                    })
                  }
                  className="px-2.5 py-1.5 rounded-lg bg-emerald-500/20 hover:bg-emerald-500/30 border border-emerald-500/40 text-xs font-semibold text-emerald-300"
                >
                  + Save Place to Codex
                </button>
                <button
                  type="button"
                  onClick={() =>
                    onAppendSessionNote?.(
                      `- Visited **[[${est.name}]]** (${est.shopLabel}), run by **[[${est.proprietor?.name}]]**. House special: ${est.houseSpecial.food} & ${est.houseSpecial.brew} (${est.houseSpecial.price}).`
                    )
                  }
                  className="px-2.5 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 text-xs text-slate-200"
                >
                  📝 Log Visit
                </button>
                <button
                  type="button"
                  onClick={revealToPlayers}
                  className="px-2.5 py-1.5 rounded-lg bg-amber-500/20 hover:bg-amber-500/30 border border-amber-500/40 text-xs font-semibold text-amber-300"
                >
                  📺 Reveal Menu to Players
                </button>
                {onWeaveWithAi && (
                  <button
                    type="button"
                    onClick={() =>
                      onWeaveWithAi({
                        tool: 'scene-painter',
                        title: est.name,
                        prompt: `Paint vivid sensory read-aloud boxed text as players enter ${est.name} (${est.shopLabel}) run by ${est.proprietor?.name}, plus 3 overheard tavern rumors and 2 hidden hooks.`,
                        contextText: `${est.atmosphere}\n${est.description}\nProprietor Secret: ${est.proprietor?.secret}\nPatron Hook: ${est.patron?.name} — ${est.patron?.hook}`,
                      })
                    }
                    className="px-2.5 py-1.5 rounded-lg bg-amber-500/20 hover:bg-amber-500/30 border border-amber-500/50 text-xs font-semibold text-amber-200"
                  >
                    ✨ Weave with AI
                  </button>
                )}
              </div>
            </div>

            <p className="text-sm text-slate-300 leading-relaxed whitespace-pre-line bg-slate-950/60 border border-slate-800 rounded-xl p-3.5">
              {est.description}
            </p>

            {/* House Special */}
            <div className="bg-amber-950/20 border border-amber-500/30 rounded-xl p-3 flex flex-wrap items-center justify-between gap-2">
              <div>
                <span className="text-[10px] font-mono uppercase tracking-wider text-amber-400 block">
                  House Special
                </span>
                <span className="text-sm font-bold text-white">
                  {est.houseSpecial.food} &amp; {est.houseSpecial.brew}
                </span>
              </div>
              <span className="px-2.5 py-1 rounded-lg bg-slate-950 border border-amber-500/40 font-mono text-xs text-amber-300">
                {est.houseSpecial.price}
              </span>
            </div>

            {/* Priced 5e Inventory Table */}
            <div>
              <h3 className="text-xs font-mono uppercase tracking-wider text-slate-400 mb-2">
                Available Wares, Rooms &amp; Specialty Stock
              </h3>
              <div className="border border-slate-800 rounded-xl overflow-hidden">
                <table className="w-full text-left text-xs">
                  <thead className="bg-slate-950 text-slate-400 font-mono text-[10px] uppercase">
                    <tr>
                      <th className="px-3 py-2">Category</th>
                      <th className="px-3 py-2">Item / Service</th>
                      <th className="px-3 py-2 text-right">Price</th>
                    </tr>
                  </thead>
                  <tbody className="divide-y divide-slate-800/80">
                    {est.inventory.map((row, i) => (
                      <tr key={i} className="bg-slate-950/40 hover:bg-slate-900/60">
                        <td className="px-3 py-2 text-slate-400 font-mono text-[11px]">{row.category}</td>
                        <td className="px-3 py-2">
                          <div className="font-semibold text-slate-100">{row.item}</div>
                          {row.note && <div className="text-[11px] text-slate-500">{row.note}</div>}
                        </td>
                        <td className="px-3 py-2 text-right font-mono text-amber-300 whitespace-nowrap">
                          {row.price}
                        </td>
                      </tr>
                    ))}
                  </tbody>
                </table>
              </div>
            </div>
          </section>

          {/* Right: Proprietor, Rumor Board & Shady Patron */}
          <section className="xl:col-span-5 space-y-4">
            {/* Proprietor Mini-Dossier */}
            {est.proprietor && (
              <div className="bg-slate-900/80 border border-slate-800 rounded-2xl p-4 space-y-2.5">
                <div className="flex items-start justify-between gap-2">
                  <div>
                    <span className="text-[10px] font-mono uppercase text-emerald-400">Proprietor</span>
                    <h3 className="text-lg font-bold text-white">
                      {est.proprietor.ancestryIcon} {est.proprietor.name}
                    </h3>
                    <p className="text-xs text-slate-400">
                      {est.proprietor.ancestry} • {est.proprietor.occupation}
                    </p>
                  </div>
                  <button
                    type="button"
                    onClick={() =>
                      onSaveCodex?.({
                        kind: 'npc',
                        title: est.proprietor.name,
                        subtitle: `${est.proprietor.ancestry} ${est.proprietor.occupation} at ${est.name}`,
                        status: 'Met',
                        tags: ['proprietor', est.shopType],
                        summary: `${est.proprietor.personality}\nVoice: ${est.proprietor.voice}`,
                        dmNotes: `Secret: ${est.proprietor.secret}`,
                        data: est.proprietor,
                      })
                    }
                    className="px-2.5 py-1 rounded-lg bg-emerald-500/15 hover:bg-emerald-500/25 border border-emerald-500/40 text-[11px] font-semibold text-emerald-300"
                  >
                    + Save NPC
                  </button>
                </div>

                <div className="text-xs space-y-2">
                  <div className="bg-slate-950 border border-slate-800 rounded-lg p-2.5">
                    <span className="text-sky-300 font-semibold block">Voice Cue</span>
                    <span className="text-slate-300">{est.proprietor.voice}</span>
                  </div>
                  <div className="bg-slate-950 border border-slate-800 rounded-lg p-2.5">
                    <span className="text-slate-300 font-semibold block">Mannerism</span>
                    <span className="text-slate-400 whitespace-pre-line">{est.proprietor.personality}</span>
                  </div>
                  <div className="bg-rose-950/30 border border-rose-500/40 rounded-lg p-2.5">
                    <span className="text-rose-300 font-bold block">DM Secret</span>
                    <span className="text-rose-100">{est.proprietor.secret}</span>
                  </div>
                </div>
              </div>
            )}

            {/* 3-Tier Rumor Board */}
            <div className="bg-slate-900/80 border border-slate-800 rounded-2xl p-4 space-y-2.5">
              <h3 className="text-sm font-bold text-white flex items-center gap-2">
                <span>🗣️</span>
                <span>Overheard Rumor Board</span>
              </h3>
              <div className="space-y-2 text-xs">
                <div className="bg-emerald-950/25 border border-emerald-500/35 rounded-xl p-2.5">
                  <span className="inline-block px-1.5 py-0.5 rounded bg-emerald-500/20 text-emerald-300 font-mono text-[10px] font-bold mb-1">
                    TRUE
                  </span>
                  <p className="text-slate-200">{est.rumors.trueRumor}</p>
                </div>
                <div className="bg-amber-950/25 border border-amber-500/35 rounded-xl p-2.5">
                  <span className="inline-block px-1.5 py-0.5 rounded bg-amber-500/20 text-amber-300 font-mono text-[10px] font-bold mb-1">
                    PARTIAL TRUTH
                  </span>
                  <p className="text-slate-200">{est.rumors.halfRumor}</p>
                </div>
                <div className="bg-rose-950/25 border border-rose-500/35 rounded-xl p-2.5">
                  <span className="inline-block px-1.5 py-0.5 rounded bg-rose-500/20 text-rose-300 font-mono text-[10px] font-bold mb-1">
                    FALSE / MISDIRECTION
                  </span>
                  <p className="text-slate-200">{est.rumors.falseRumor}</p>
                </div>
              </div>
            </div>

            {/* Shady Patron Quest Hook */}
            <div className="bg-slate-900/80 border border-slate-800 rounded-2xl p-4 space-y-2">
              <div className="flex items-center justify-between">
                <h3 className="text-sm font-bold text-white flex items-center gap-2">
                  <span>🕯️</span>
                  <span>Corner Table Patron: {est.patron.name}</span>
                </h3>
              </div>
              <p className="text-xs text-slate-300 whitespace-pre-line leading-relaxed bg-slate-950 border border-slate-800 rounded-xl p-3">
                {est.patron.hook}
              </p>
            </div>
          </section>
        </div>
      )}
    </div>
  );
}
