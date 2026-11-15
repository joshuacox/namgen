'use client';

import React, { useState, useEffect } from 'react';
import { PARTY_TIERS, ENCOUNTER_ENVIRONMENTS } from 'namgen.js/dnd';

export default function AdventureForgePanel({
  partyTier = 1,
  onChangeTier,
  onSaveCodex,
  onSendToCombat,
  onRevealHandout,
  onWeaveWithAi,
  onNotify,
}) {
  const [subMode, setSubMode] = useState('dungeon');
  const [envId, setEnvId] = useState('road');
  const [seed, setSeed] = useState('');

  const [dungeon, setDungeon] = useState(null);
  const [encounter, setEncounter] = useState(null);
  const [loot, setLoot] = useState(null);
  const [loading, setLoading] = useState(false);

  const runAction = async (action, extra = {}) => {
    setLoading(true);
    try {
      const res = await fetch('/api/namgen', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          action,
          tier: partyTier,
          seed,
          ...extra,
        }),
      });
      const data = await res.json();
      if (action === 'dungeon' && data.dungeon) setDungeon(data.dungeon);
      if (action === 'encounter' && data.encounter) setEncounter(data.encounter);
      if (action === 'loot' && data.loot) setLoot(data.loot);
    } catch (err) {
      onNotify?.(`Generation error: ${err.message}`);
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => {
    runAction('dungeon');
    runAction('encounter', { envId: 'road' });
    runAction('loot');
  }, []);

  const tierInfo = PARTY_TIERS[partyTier] || PARTY_TIERS[1];

  return (
    <div className="space-y-5">
      {/* Top Tier Selector + Mode Tabs */}
      <section className="bg-slate-900/80 border border-slate-800 rounded-2xl p-4 space-y-3">
        <div className="flex flex-wrap items-center justify-between gap-3">
          <div className="flex flex-wrap gap-1.5">
            {[
              { id: 'dungeon', label: '🏰 5-Room Dungeon' },
              { id: 'encounter', label: '🧭 Encounters & Prophecies' },
              { id: 'loot', label: '💎 Treasure & Relic Hoard' },
            ].map((tab) => (
              <button
                key={tab.id}
                type="button"
                onClick={() => setSubMode(tab.id)}
                className={`px-3.5 py-2 rounded-xl text-xs font-bold border transition-colors ${
                  subMode === tab.id
                    ? 'bg-emerald-500/20 border-emerald-500/60 text-emerald-200'
                    : 'bg-slate-950 border-slate-800 text-slate-300 hover:text-white'
                }`}
              >
                {tab.label}
              </button>
            ))}
          </div>

          <div className="flex flex-wrap items-center gap-2">
            <input
              type="text"
              value={seed}
              onChange={(e) => setSeed(e.target.value)}
              placeholder="Optional seed..."
              className="bg-slate-950 border border-slate-800 rounded-xl px-3 py-1.5 text-xs text-slate-100 placeholder-slate-600 w-36"
            />
            <button
              type="button"
              disabled={loading}
              onClick={() => runAction(subMode, subMode === 'encounter' ? { envId } : {})}
              className="px-4 py-2 rounded-xl bg-amber-500 hover:bg-amber-400 disabled:opacity-50 text-slate-950 text-xs font-bold"
            >
              {loading ? 'Forging...' : '⚡ Roll Fresh'}
            </button>
          </div>
        </div>

        {/* Party Tier Scaling Pills */}
        <div className="flex flex-wrap items-center gap-2 pt-2 border-t border-slate-800/80">
          <span className="text-[11px] font-mono uppercase text-slate-400">Party Tier Scaling:</span>
          {[1, 2, 3, 4].map((t) => {
            const info = PARTY_TIERS[t];
            return (
              <button
                key={t}
                type="button"
                onClick={() => onChangeTier?.(t)}
                className={`px-2.5 py-1 rounded-lg text-xs border transition-colors ${
                  Number(partyTier) === t
                    ? 'bg-amber-500/20 border-amber-500/60 text-amber-200 font-semibold'
                    : 'bg-slate-950 border-slate-800 text-slate-400 hover:text-white'
                }`}
              >
                {info.label}
              </button>
            );
          })}
          <span className="text-[11px] font-mono text-slate-500 ml-auto">
            DC {tierInfo.dc} • Trap {tierInfo.trapDamage} • {tierInfo.rarity}
          </span>
        </div>
      </section>

      {/* Mode 1: 5-Room Dungeon */}
      {subMode === 'dungeon' && dungeon && (
        <section className="bg-slate-900/80 border border-slate-800 rounded-2xl p-5 space-y-4">
          <div className="flex flex-wrap items-start justify-between gap-3 pb-3 border-b border-slate-800">
            <div>
              <span className="text-xs font-mono text-amber-400 uppercase">{dungeon.tierLabel}</span>
              <h2 className="text-2xl font-extrabold text-white">{dungeon.title}</h2>
              <p className="text-xs text-slate-400 mt-1">
                Base Check DC {dungeon.recommendedDc} • Typical Trap Damage: {dungeon.trapDamage}
              </p>
            </div>
            <div className="flex flex-wrap gap-1.5">
              <button
                type="button"
                onClick={() =>
                  onSaveCodex?.({
                    kind: 'dungeon',
                    title: dungeon.title,
                    subtitle: `5-Room Dungeon (${dungeon.tierLabel})`,
                    status: 'Rumored',
                    tags: ['dungeon', `tier-${dungeon.tier}`],
                    summary: dungeon.loreExcerpt,
                    dmNotes: `Hazard: ${dungeon.rooms.hazard.name} (${dungeon.rooms.hazard.scaledDc}) | Guard: ${dungeon.rooms.setback.captainName} | Boss: ${dungeon.rooms.bossSanctum.namedBoss} | Hoard Relic: ${dungeon.rooms.hoard.relicName}`,
                    data: dungeon,
                  })
                }
                className="px-2.5 py-1.5 rounded-lg bg-emerald-500/20 hover:bg-emerald-500/30 border border-emerald-500/40 text-xs font-semibold text-emerald-300"
              >
                + Save Dungeon to Codex
              </button>
              <button
                type="button"
                onClick={() =>
                  onSendToCombat?.([
                    {
                      name: `${dungeon.rooms.setback.captainName} (Guardian)`,
                      side: 'enemy',
                      ac: 14 + Number(partyTier),
                      maxHp: 22 * Number(partyTier),
                      hp: 22 * Number(partyTier),
                      tempHp: 0,
                      initBonus: 2,
                      notes: dungeon.rooms.setback.monster,
                    },
                    {
                      name: dungeon.rooms.bossSanctum.namedBoss,
                      side: 'enemy',
                      ac: 15 + Number(partyTier),
                      maxHp: 45 * Number(partyTier),
                      hp: 45 * Number(partyTier),
                      tempHp: 0,
                      initBonus: 3,
                      notes: dungeon.rooms.bossSanctum.lairHazard,
                    },
                  ])
                }
                className="px-2.5 py-1.5 rounded-lg bg-rose-500/20 hover:bg-rose-500/30 border border-rose-500/40 text-xs font-semibold text-rose-300"
              >
                ⚔️ Send Boss &amp; Guard to Combat
              </button>
              <button
                type="button"
                onClick={() =>
                  onRevealHandout?.({
                    kind: 'dungeon',
                    title: dungeon.rooms.hoard.relicName,
                    subtitle: `Discovered within ${dungeon.title} (${dungeon.rooms.hoard.rarity})`,
                    body: dungeon.rooms.hoard.relicDesc || dungeon.rooms.hoard.reward,
                  })
                }
                className="px-2.5 py-1.5 rounded-lg bg-amber-500/20 hover:bg-amber-500/30 border border-amber-500/40 text-xs font-semibold text-amber-300"
              >
                📺 Reveal Hoard Relic
              </button>
            </div>
          </div>

          <p className="text-sm text-slate-300 whitespace-pre-line bg-slate-950/60 border border-slate-800 rounded-xl p-3.5">
            {dungeon.loreExcerpt}
          </p>

          <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-3 text-xs">
            <div className="bg-slate-950 border border-slate-800 rounded-xl p-3.5 space-y-1.5">
              <span className="text-[10px] font-mono uppercase text-emerald-400">Room 1 — Entrance</span>
              <h3 className="text-sm font-bold text-white">{dungeon.rooms.entrance.name}</h3>
              <p className="text-slate-300">{dungeon.rooms.entrance.desc}</p>
            </div>

            <div className="bg-slate-950 border border-amber-500/30 rounded-xl p-3.5 space-y-1.5">
              <span className="text-[10px] font-mono uppercase text-amber-400">Room 2 — Puzzle / Hazard</span>
              <h3 className="text-sm font-bold text-white">{dungeon.rooms.hazard.name}</h3>
              <div className="text-amber-300 font-mono text-[11px]">{dungeon.rooms.hazard.scaledDc}</div>
              <p className="text-slate-300">{dungeon.rooms.hazard.desc}</p>
            </div>

            <div className="bg-slate-950 border border-orange-500/30 rounded-xl p-3.5 space-y-1.5">
              <span className="text-[10px] font-mono uppercase text-orange-400">Room 3 — Setback &amp; Captain</span>
              <h3 className="text-sm font-bold text-white">{dungeon.rooms.setback.name}</h3>
              <div className="text-orange-300 font-semibold">
                {dungeon.rooms.setback.captainName} • {dungeon.rooms.setback.monster}
              </div>
              <p className="text-slate-300">{dungeon.rooms.setback.desc}</p>
            </div>

            <div className="bg-rose-950/20 border border-rose-500/40 rounded-xl p-3.5 space-y-1.5 md:col-span-2 lg:col-span-2">
              <span className="text-[10px] font-mono uppercase text-rose-400">Room 4 — Climax &amp; Boss Sanctum</span>
              <h3 className="text-sm font-bold text-white">{dungeon.rooms.bossSanctum.name}</h3>
              <div className="text-rose-200 font-bold">{dungeon.rooms.bossSanctum.namedBoss}</div>
              <p className="text-slate-300">{dungeon.rooms.bossSanctum.desc}</p>
              <div className="text-[11px] text-rose-300 bg-slate-950/70 px-2.5 py-1.5 rounded border border-rose-500/30">
                Lair Action ({dungeon.rooms.bossSanctum.scaledLairDc}): {dungeon.rooms.bossSanctum.lairHazard}
              </div>
            </div>

            <div className="bg-emerald-950/20 border border-emerald-500/40 rounded-xl p-3.5 space-y-1.5">
              <span className="text-[10px] font-mono uppercase text-emerald-400">Room 5 — Reward &amp; Relic</span>
              <h3 className="text-sm font-bold text-white">{dungeon.rooms.hoard.name}</h3>
              <div className="font-mono text-amber-300">
                ~{dungeon.rooms.hoard.scaledGold} gp + {dungeon.rooms.hoard.relicName}
              </div>
              <p className="text-slate-300">{dungeon.rooms.hoard.reward}</p>
              {dungeon.rooms.hoard.relicDesc && (
                <p className="text-slate-400 italic whitespace-pre-line">{dungeon.rooms.hoard.relicDesc}</p>
              )}
            </div>
          </div>
        </section>
      )}

      {/* Mode 2: Encounters & Prophecies */}
      {subMode === 'encounter' && (
        <div className="space-y-4">
          <div className="flex flex-wrap gap-2">
            {Object.values(ENCOUNTER_ENVIRONMENTS).map((env) => (
              <button
                key={env.id}
                type="button"
                onClick={() => {
                  setEnvId(env.id);
                  runAction('encounter', { envId: env.id });
                }}
                className={`px-3 py-1.5 rounded-xl text-xs font-semibold border flex items-center gap-1.5 ${
                  envId === env.id
                    ? 'bg-amber-500/20 border-amber-500/60 text-amber-200'
                    : 'bg-slate-900 border-slate-800 text-slate-300 hover:text-white'
                }`}
              >
                <span>{env.icon}</span>
                <span>{env.label}</span>
              </button>
            ))}
          </div>

          {encounter && (
            <section className="bg-slate-900/80 border border-slate-800 rounded-2xl p-5 space-y-4">
              <div className="flex flex-wrap items-start justify-between gap-3 pb-3 border-b border-slate-800">
                <div>
                  <span className="text-xs font-mono text-amber-400 uppercase">{encounter.tierLabel}</span>
                  <h2 className="text-xl font-extrabold text-white flex items-center gap-2">
                    <span>{encounter.icon}</span>
                    <span>{encounter.environment}</span>
                  </h2>
                  <p className="text-xs text-slate-400 mt-1">
                    Recommended Environmental / Skill DC {encounter.recommendedDc}
                  </p>
                </div>

                <div className="flex flex-wrap gap-1.5">
                  <button
                    type="button"
                    onClick={() =>
                      onSendToCombat?.(
                        encounter.monsters.map((mName) => ({
                          name: mName,
                          side: 'enemy',
                          ac: 13 + Number(partyTier),
                          maxHp: 18 * Number(partyTier),
                          hp: 18 * Number(partyTier),
                          tempHp: 0,
                          initBonus: 2,
                          notes: `${encounter.environment} encounter (${encounter.monsterGenerator})`,
                        }))
                      )
                    }
                    className="px-2.5 py-1.5 rounded-lg bg-rose-500/20 hover:bg-rose-500/30 border border-rose-500/40 text-xs font-semibold text-rose-300"
                  >
                    ⚔️ Send {encounter.monsters.length} Foes to Combat
                  </button>
                  <button
                    type="button"
                    onClick={() =>
                      onSaveCodex?.({
                        kind: 'encounter',
                        title: `${encounter.environment} Scene`,
                        subtitle: encounter.tierLabel,
                        status: 'Rumored',
                        tags: ['encounter', encounter.envId],
                        summary: `${encounter.twist}\nNPCs: ${encounter.npcs.join(', ')}\nFoes: ${encounter.monsters.join(', ')}`,
                        dmNotes: `Hook: ${encounter.questHook}\nProphecy: ${encounter.prophecy}`,
                        data: encounter,
                      })
                    }
                    className="px-2.5 py-1.5 rounded-lg bg-emerald-500/20 hover:bg-emerald-500/30 border border-emerald-500/40 text-xs font-semibold text-emerald-300"
                  >
                    + Save to Codex
                  </button>
                  <button
                    type="button"
                    onClick={() =>
                      onRevealHandout?.({
                        kind: 'prophecy',
                        title: `Omen & Sighting — ${encounter.environment}`,
                        subtitle: 'Spoken Prophetic Warning',
                        body: encounter.twist,
                        quote: encounter.prophecy || 'The mists part to reveal an uncertain omen.',
                      })
                    }
                    className="px-2.5 py-1.5 rounded-lg bg-amber-500/20 hover:bg-amber-500/30 border border-amber-500/40 text-xs font-semibold text-amber-300"
                  >
                    📺 Reveal Prophecy
                  </button>
                  {onWeaveWithAi && (
                    <button
                      type="button"
                      onClick={() =>
                        onWeaveWithAi({
                          tool: 'boss-designer',
                          title: `Encounter: ${encounter.environment}`,
                          prompt: `Expand this ${encounter.tierLabel} encounter in ${encounter.environment} into a multi-phase tactical fight with Phase 2 escalation, lair hazard triggers, and boxed text.`,
                          contextText: `Twist: ${encounter.twist}\nFoes: ${encounter.monsters.join(', ')}\nHook: ${encounter.questHook}`,
                        })
                      }
                      className="px-2.5 py-1.5 rounded-lg bg-amber-500/20 hover:bg-amber-500/30 border border-amber-500/50 text-xs font-semibold text-amber-200"
                    >
                      ✨ Weave with AI
                    </button>
                  )}
                </div>
              </div>

              <div className="bg-amber-950/20 border border-amber-500/30 rounded-xl p-3.5 text-sm text-amber-100">
                <span className="text-[10px] font-mono uppercase text-amber-400 block mb-1">
                  Battlefield Twist / Environmental Hazard
                </span>
                {encounter.twist}
              </div>

              <div className="grid grid-cols-1 md:grid-cols-2 gap-4 text-xs">
                <div className="bg-slate-950 border border-slate-800 rounded-xl p-3.5 space-y-2">
                  <span className="text-[10px] font-mono uppercase text-emerald-400 block">
                    Named Bystanders / Allies ({encounter.npcGenerator})
                  </span>
                  <div className="flex flex-wrap gap-1.5">
                    {encounter.npcs.map((n, i) => (
                      <span key={i} className="px-2.5 py-1 rounded-lg bg-slate-900 border border-slate-700 text-slate-100 font-semibold">
                        {n}
                      </span>
                    ))}
                  </div>
                </div>

                <div className="bg-slate-950 border border-slate-800 rounded-xl p-3.5 space-y-2">
                  <span className="text-[10px] font-mono uppercase text-rose-400 block">
                    Named Adversaries ({encounter.monsterGenerator})
                  </span>
                  <div className="flex flex-wrap gap-1.5">
                    {encounter.monsters.map((m, i) => (
                      <span key={i} className="px-2.5 py-1 rounded-lg bg-rose-950/40 border border-rose-500/40 text-rose-200 font-semibold">
                        {m}
                      </span>
                    ))}
                  </div>
                </div>

                {encounter.questHook && (
                  <div className="bg-slate-950 border border-slate-800 rounded-xl p-3.5 space-y-1">
                    <span className="text-[10px] font-mono uppercase text-sky-400 block">Complication / Quest Hook</span>
                    <p className="text-slate-300 whitespace-pre-line leading-relaxed">{encounter.questHook}</p>
                  </div>
                )}

                {encounter.prophecy && (
                  <div className="bg-slate-950 border border-slate-800 rounded-xl p-3.5 space-y-1">
                    <span className="text-[10px] font-mono uppercase text-purple-400 block">Whispered Prophecy</span>
                    <p className="text-purple-100 italic whitespace-pre-line leading-relaxed">{encounter.prophecy}</p>
                  </div>
                )}
              </div>
            </section>
          )}
        </div>
      )}

      {/* Mode 3: Treasure & Relic Hoard */}
      {subMode === 'loot' && loot && (
        <section className="bg-slate-900/80 border border-slate-800 rounded-2xl p-5 space-y-4">
          <div className="flex flex-wrap items-start justify-between gap-3 pb-3 border-b border-slate-800">
            <div>
              <span className="text-xs font-mono text-amber-400 uppercase">
                {loot.tierLabel} • {loot.rarity}
              </span>
              <h2 className="text-2xl font-extrabold text-white">{loot.relic.name}</h2>
            </div>

            <div className="flex flex-wrap gap-1.5">
              <button
                type="button"
                onClick={() =>
                  onSaveCodex?.({
                    kind: 'item',
                    title: loot.relic.name,
                    subtitle: `${loot.rarity} Relic (${loot.relic.value})`,
                    status: 'Active',
                    tags: ['loot', 'magic-item'],
                    summary: `${loot.relic.enchantment}\n${loot.relic.lore}`,
                    dmNotes: `Coins: ${loot.coins.pp} pp, ${loot.coins.gp} gp, ${loot.coins.sp} sp | Scroll: ${loot.spellScroll}`,
                    data: loot,
                  })
                }
                className="px-2.5 py-1.5 rounded-lg bg-emerald-500/20 hover:bg-emerald-500/30 border border-emerald-500/40 text-xs font-semibold text-emerald-300"
              >
                + Save Relic to Codex
              </button>
              <button
                type="button"
                onClick={() =>
                  onRevealHandout?.({
                    kind: 'loot',
                    title: `Treasure Claimed: ${loot.relic.name}`,
                    subtitle: `${loot.rarity} • Est. Value ${loot.relic.value}`,
                    body: `${loot.relic.enchantment}\n\n${loot.relic.lore}`,
                    items: [
                      {
                        label: 'Coined Coinage',
                        detail: 'Split among the party',
                        price: `${loot.coins.pp} pp, ${loot.coins.gp} gp, ${loot.coins.sp} sp`,
                      },
                      ...loot.potions.map((p) => ({
                        label: p.name,
                        detail: `${p.color} — ${p.benefit}`,
                        price: 'Potion',
                      })),
                      ...loot.gems.map((g) => ({
                        label: g.item,
                        detail: 'Appraised gem / curio',
                        price: g.val,
                      })),
                    ],
                  })
                }
                className="px-2.5 py-1.5 rounded-lg bg-amber-500/20 hover:bg-amber-500/30 border border-amber-500/40 text-xs font-semibold text-amber-300"
              >
                📺 Reveal Hoard to Players
              </button>
            </div>
          </div>

          <div className="grid grid-cols-1 md:grid-cols-3 gap-4 text-xs">
            {/* Coins & Relic */}
            <div className="bg-slate-950 border border-amber-500/30 rounded-xl p-4 space-y-2.5">
              <div className="flex items-center justify-between">
                <span className="text-[10px] font-mono uppercase text-amber-400">Signature Relic</span>
                <span className="font-mono text-amber-300 font-bold">{loot.relic.value}</span>
              </div>
              <div className="text-sm font-bold text-white">{loot.relic.name}</div>
              <div className="text-emerald-300 font-semibold">{loot.relic.enchantment}</div>
              <p className="text-slate-300 whitespace-pre-line">{loot.relic.lore}</p>

              <div className="pt-2 border-t border-slate-800 font-mono text-amber-200 flex gap-3">
                <span>{loot.coins.pp} pp</span>
                <span>{loot.coins.gp} gp</span>
                <span>{loot.coins.sp} sp</span>
              </div>
            </div>

            {/* Potions & Alchemy */}
            <div className="bg-slate-950 border border-slate-800 rounded-xl p-4 space-y-2.5">
              <span className="text-[10px] font-mono uppercase text-emerald-400 block">Potions &amp; Elixirs</span>
              {loot.potions.map((p, i) => (
                <div key={i} className="bg-slate-900/70 border border-slate-800 rounded-lg p-2.5">
                  <div className="font-bold text-white">{p.name}</div>
                  <div className="text-[11px] text-amber-300">{p.color}</div>
                  <p className="text-slate-300 mt-1">{p.benefit}</p>
                  {p.quirk && <p className="text-slate-500 italic mt-0.5">{p.quirk}</p>}
                </div>
              ))}
              {loot.potionRecipe && (
                <div className="text-[11px] text-slate-400 whitespace-pre-line pt-1 border-t border-slate-800">
                  {loot.potionRecipe}
                </div>
              )}
            </div>

            {/* Gems, Curios & Spell Scroll */}
            <div className="bg-slate-950 border border-slate-800 rounded-xl p-4 space-y-2.5">
              <span className="text-[10px] font-mono uppercase text-sky-400 block">Gems, Curios &amp; Scroll</span>
              <div className="space-y-1.5">
                {loot.gems.map((g, i) => (
                  <div
                    key={i}
                    className="flex items-center justify-between bg-slate-900/70 border border-slate-800 rounded-lg px-2.5 py-1.5"
                  >
                    <span className="text-slate-200">{g.item}</span>
                    <span className="font-mono text-amber-300">{g.val}</span>
                  </div>
                ))}
              </div>
              {loot.spellScroll && (
                <div className="bg-purple-950/20 border border-purple-500/30 rounded-lg p-2.5 mt-2">
                  <span className="text-[10px] font-mono uppercase text-purple-300 block mb-1">
                    Inscribed Spell Scroll
                  </span>
                  <p className="text-slate-200 whitespace-pre-line">{loot.spellScroll}</p>
                </div>
              )}
            </div>
          </div>
        </section>
      )}
    </div>
  );
}
