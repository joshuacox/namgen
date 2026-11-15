'use client';

import React, { useState } from 'react';
import { CONDITIONS_5E, NPC_ARCHETYPES_5E } from 'namgen.js/dnd';

const CONDITION_COLOR_STYLES = {
  red: 'bg-red-500/20 border-red-500/50 text-red-200',
  pink: 'bg-pink-500/20 border-pink-500/50 text-pink-200',
  slate: 'bg-slate-500/20 border-slate-400/50 text-slate-200',
  purple: 'bg-purple-500/20 border-purple-500/50 text-purple-200',
  orange: 'bg-orange-500/20 border-orange-500/50 text-orange-200',
  cyan: 'bg-cyan-500/20 border-cyan-500/50 text-cyan-200',
  rose: 'bg-rose-500/20 border-rose-500/50 text-rose-200',
  emerald: 'bg-emerald-500/20 border-emerald-500/50 text-emerald-200',
  yellow: 'bg-yellow-500/20 border-yellow-500/50 text-yellow-200',
  indigo: 'bg-indigo-500/20 border-indigo-500/50 text-indigo-200',
  sky: 'bg-sky-500/20 border-sky-500/50 text-sky-200',
};

function d20() {
  return Math.floor(Math.random() * 20) + 1;
}

function enemyStatusLabel(hp, maxHp) {
  if (hp <= 0) return 'Defeated';
  const ratio = maxHp > 0 ? hp / maxHp : 1;
  if (ratio <= 0.2) return 'Critical';
  if (ratio <= 0.5) return 'Bloodied';
  return 'Healthy';
}

export default function CombatTrackerPanel({
  party = [],
  combat = { round: 1, turnIndex: 0, combatants: [] },
  onUpdateParty,
  onUpdateCombat,
  onRevealHandout,
  onNotify,
}) {
  const [editingParty, setEditingParty] = useState(false);
  const [minionLabel, setMinionLabel] = useState('Goblin');
  const [minionCount, setMinionCount] = useState(4);
  const [minionAc, setMinionAc] = useState(15);
  const [minionHp, setMinionHp] = useState(7);
  const [minionInitBonus, setMinionInitBonus] = useState(2);
  const [minionNotes, setMinionNotes] = useState('Scimitar +4 (1d6+2) / Shortbow +4');
  const [spawning, setSpawning] = useState(false);

  const [hpDeltas, setHpDeltas] = useState({});
  const [concReminder, setConcReminder] = useState(null);

  const combatants = Array.isArray(combat?.combatants) ? combat.combatants : [];
  const round = combat?.round || 1;
  const turnIndex = combatants.length > 0 ? Math.min(combat.turnIndex || 0, combatants.length - 1) : 0;

  const highestPassive = party.reduce((max, pc) => Math.max(max, Number(pc.passivePerc) || 10), 10);

  const updateCombat = (patch) => {
    onUpdateCombat?.({
      round,
      turnIndex,
      combatants,
      ...patch,
    });
  };

  // Party Roster operations
  const addPartyHero = () => {
    const nextHero = {
      id: `pc_${Date.now()}`,
      name: 'New Adventurer',
      player: 'Player',
      classLevel: 'Fighter 1',
      ac: 16,
      maxHp: 12,
      hp: 12,
      tempHp: 0,
      initBonus: 2,
      passivePerc: 12,
      conditions: [],
    };
    onUpdateParty?.([...party, nextHero]);
  };

  const updatePartyHero = (id, field, value) => {
    onUpdateParty?.(
      party.map((pc) => {
        if (pc.id !== id) return pc;
        const updated = { ...pc, [field]: value };
        if (field === 'maxHp' && updated.hp > Number(value)) {
          updated.hp = Number(value) || 0;
        }
        return updated;
      })
    );
  };

  const removePartyHero = (id) => {
    onUpdateParty?.(party.filter((pc) => pc.id !== id));
  };

  const loadPartyIntoEncounter = () => {
    const existingPcIds = new Set(combatants.map((c) => c.sourcePartyId).filter(Boolean));
    const existingNames = new Set(combatants.map((c) => c.name.toLowerCase()));
    const toAdd = [];

    for (const pc of party) {
      if (existingPcIds.has(pc.id) || existingNames.has(pc.name.toLowerCase())) continue;
      const bonus = Number(pc.initBonus) || 0;
      toAdd.push({
        id: `cmb_${pc.id}_${Date.now()}`,
        sourcePartyId: pc.id,
        name: pc.name,
        side: 'pc',
        ac: Number(pc.ac) || 10,
        maxHp: Number(pc.maxHp) || 10,
        hp: Number(pc.hp ?? pc.maxHp) || 10,
        tempHp: Number(pc.tempHp) || 0,
        initBonus: bonus,
        initiative: d20() + bonus,
        conditions: Array.isArray(pc.conditions) ? [...pc.conditions] : [],
        notes: `${pc.classLevel || 'Hero'} (PP ${pc.passivePerc || 10})`,
      });
    }

    if (toAdd.length === 0) {
      onNotify?.('All party heroes are already in initiative');
      return;
    }

    const merged = [...combatants, ...toAdd].sort((a, b) => (b.initiative || 0) - (a.initiative || 0));
    updateCombat({ combatants: merged });
    onNotify?.(`Loaded ${toAdd.length} party heroes into initiative`);
  };

  // Procedural Named Minion Spawner
  const spawnNamedMinions = async (e) => {
    e?.preventDefault?.();
    const safeCount = Math.min(12, Math.max(1, Number(minionCount) || 1));
    setSpawning(true);
    try {
      const res = await fetch('/api/namgen', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          action: 'minion-names',
          label: minionLabel || 'Goblin',
          count: safeCount,
        }),
      });
      const data = await res.json();
      const names = data.names || [];
      const bonus = Number(minionInitBonus) || 0;
      const maxHpVal = Math.max(1, Number(minionHp) || 1);
      const acVal = Math.max(1, Number(minionAc) || 10);

      const newMinions = names.map((nm, idx) => ({
        id: `cmb_min_${Date.now()}_${idx}`,
        name: `${nm} (${minionLabel || 'Minion'} #${idx + 1})`,
        side: 'enemy',
        ac: acVal,
        maxHp: maxHpVal,
        hp: maxHpVal,
        tempHp: 0,
        initBonus: bonus,
        initiative: d20() + bonus,
        conditions: [],
        notes: minionNotes || `Generated via ${data.generatorUsed}`,
      }));

      const merged = [...combatants, ...newMinions].sort(
        (a, b) => (b.initiative || 0) - (a.initiative || 0)
      );
      updateCombat({ combatants: merged });
      onNotify?.(`Spawned ${newMinions.length} named ${minionLabel}s (${data.generatorUsed})`);
    } catch (err) {
      onNotify?.(`Failed to spawn minions: ${err.message}`);
    } finally {
      setSpawning(false);
    }
  };

  const applyArchetypePreset = (arch) => {
    setMinionLabel(arch.name);
    setMinionAc(arch.ac);
    setMinionHp(arch.hp);
    setMinionNotes(arch.attack);
  };

  // Turn & Initiative controls
  const rollAllInitiative = () => {
    const rolled = combatants
      .map((c) => ({
        ...c,
        initiative: d20() + (Number(c.initBonus) || 0),
      }))
      .sort((a, b) => b.initiative - a.initiative);
    updateCombat({ combatants: rolled, turnIndex: 0, round: 1 });
    onNotify?.('Rolled fresh initiative for all combatants');
  };

  const sortInitiative = () => {
    const sorted = [...combatants].sort((a, b) => (b.initiative || 0) - (a.initiative || 0));
    updateCombat({ combatants: sorted, turnIndex: 0 });
  };

  const nextTurn = () => {
    if (combatants.length === 0) return;
    const nextIdx = turnIndex + 1;
    if (nextIdx >= combatants.length) {
      updateCombat({ turnIndex: 0, round: round + 1 });
    } else {
      updateCombat({ turnIndex: nextIdx });
    }
  };

  const prevTurn = () => {
    if (combatants.length === 0) return;
    if (turnIndex === 0) {
      updateCombat({
        turnIndex: combatants.length - 1,
        round: Math.max(1, round - 1),
      });
    } else {
      updateCombat({ turnIndex: turnIndex - 1 });
    }
  };

  const clearMonsters = () => {
    const kept = combatants.filter((c) => c.side === 'pc');
    updateCombat({ combatants: kept, turnIndex: 0, round: 1 });
    onNotify?.('Cleared non-PC combatants from encounter');
  };

  const resetEncounter = () => {
    updateCombat({ combatants: [], turnIndex: 0, round: 1 });
    setConcReminder(null);
    onNotify?.('Encounter tracker reset');
  };

  // Per-combatant updates
  const applyHpChange = (combatantId, rawDelta) => {
    const delta = parseInt(rawDelta, 10);
    if (!Number.isFinite(delta) || delta === 0) return;

    let concAlert = null;
    const nextList = combatants.map((c) => {
      if (c.id !== combatantId) return c;
      let hp = Number(c.hp) || 0;
      let tempHp = Number(c.tempHp) || 0;

      if (delta < 0) {
        let dmg = Math.abs(delta);
        if (tempHp > 0) {
          const absorbed = Math.min(tempHp, dmg);
          tempHp -= absorbed;
          dmg -= absorbed;
        }
        hp = Math.max(0, hp - dmg);

        const isConcentrating = Array.isArray(c.conditions) && c.conditions.includes('Concentrating');
        if (isConcentrating && Math.abs(delta) > 0) {
          const dc = Math.max(10, Math.floor(Math.abs(delta) / 2));
          concAlert = { name: c.name, damage: Math.abs(delta), dc };
        }
      } else {
        hp = Math.min(Number(c.maxHp) || hp + delta, hp + delta);
      }

      return { ...c, hp, tempHp };
    });

    updateCombat({ combatants: nextList });
    if (concAlert) {
      setConcReminder(concAlert);
      onNotify?.(
        `Concentration Check! ${concAlert.name} took ${concAlert.damage} dmg -> DC ${concAlert.dc} Con save`
      );
    }
  };

  const setCombatantField = (id, field, val) => {
    updateCombat({
      combatants: combatants.map((c) => (c.id === id ? { ...c, [field]: val } : c)),
    });
  };

  const toggleCondition = (id, condId) => {
    updateCombat({
      combatants: combatants.map((c) => {
        if (c.id !== id) return c;
        const prev = Array.isArray(c.conditions) ? c.conditions : [];
        const exists = prev.includes(condId);
        return {
          ...c,
          conditions: exists ? prev.filter((x) => x !== condId) : [...prev, condId],
        };
      }),
    });
  };

  const removeCombatant = (id) => {
    const nextList = combatants.filter((c) => c.id !== id);
    const nextIdx = nextList.length === 0 ? 0 : Math.min(turnIndex, nextList.length - 1);
    updateCombat({ combatants: nextList, turnIndex: nextIdx });
  };

  const broadcastTurnOrder = () => {
    if (combatants.length === 0) {
      onNotify?.('Add combatants before broadcasting turn order');
      return;
    }
    const sortedOrCurrent = combatants;
    const active = sortedOrCurrent[turnIndex];
    const items = sortedOrCurrent.map((c, idx) => {
      const marker = idx === turnIndex ? '▶ ' : `${idx + 1}. `;
      const condText = c.conditions?.length ? ` [${c.conditions.join(', ')}]` : '';
      const status =
        c.side === 'pc'
          ? `HP ${c.hp}/${c.maxHp}${c.tempHp > 0 ? ` (+${c.tempHp} temp)` : ''}`
          : enemyStatusLabel(c.hp, c.maxHp);
      return {
        label: `${marker}${c.name}${condText}`,
        detail: c.side === 'pc' ? 'Party Hero' : c.side === 'npc' ? 'Ally' : 'Adversary',
        price: status,
      };
    });

    onRevealHandout?.({
      kind: 'combat',
      title: `Initiative Tracker — Round ${round}`,
      subtitle: active ? `Current Turn: ${active.name}` : 'Combat Underway',
      body: 'Enemy HP totals & AC remain hidden behind the DM screen.',
      items,
    });
  };

  return (
    <div className="space-y-5">
      {/* Persistent Party Roster Strip */}
      <section className="bg-slate-900/80 border border-slate-800 rounded-2xl p-4 space-y-3">
        <div className="flex flex-wrap items-center justify-between gap-2">
          <div className="flex flex-wrap items-center gap-3">
            <h2 className="text-base font-bold text-white flex items-center gap-2">
              <span>🛡️</span>
              <span>Campaign Party Roster ({party.length})</span>
            </h2>
            <span className="px-2.5 py-0.5 rounded-full bg-amber-500/15 border border-amber-500/40 text-amber-300 text-xs font-mono">
              Highest Passive Perception: {highestPassive}
            </span>
          </div>
          <div className="flex flex-wrap items-center gap-2">
            <button
              type="button"
              onClick={loadPartyIntoEncounter}
              className="px-3 py-1.5 rounded-lg bg-emerald-500 hover:bg-emerald-400 text-slate-950 text-xs font-bold"
            >
              + Load Party into Encounter
            </button>
            <button
              type="button"
              onClick={() => setEditingParty((v) => !v)}
              className="px-3 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 text-xs text-slate-200"
            >
              {editingParty ? 'Done Editing Roster' : '✏️ Edit Party'}
            </button>
          </div>
        </div>

        {/* Party Hero Chips or Full Editor */}
        {!editingParty ? (
          <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-4 gap-2.5">
            {party.map((pc) => (
              <div
                key={pc.id}
                className="bg-slate-950 border border-slate-800 rounded-xl p-2.5 flex flex-col justify-between gap-1 text-xs"
              >
                <div className="flex items-center justify-between gap-1">
                  <span className="font-bold text-emerald-300 truncate">{pc.name}</span>
                  <span className="font-mono text-[11px] text-slate-400">AC {pc.ac}</span>
                </div>
                <div className="text-[11px] text-slate-400 truncate">
                  {pc.player} • {pc.classLevel}
                </div>
                <div className="flex items-center justify-between font-mono text-[11px] text-slate-300 pt-1">
                  <span>
                    HP {pc.hp}/{pc.maxHp}
                  </span>
                  <span>Init {pc.initBonus >= 0 ? `+${pc.initBonus}` : pc.initBonus}</span>
                  <span className="text-amber-300">PP {pc.passivePerc}</span>
                </div>
              </div>
            ))}
          </div>
        ) : (
          <div className="space-y-2">
            <div className="overflow-x-auto">
              <table className="w-full text-left text-xs">
                <thead className="text-[10px] font-mono uppercase text-slate-400 border-b border-slate-800">
                  <tr>
                    <th className="py-1.5 pr-2">Hero Name</th>
                    <th className="py-1.5 pr-2">Player</th>
                    <th className="py-1.5 pr-2">Class &amp; Lvl</th>
                    <th className="py-1.5 pr-2 w-16">AC</th>
                    <th className="py-1.5 pr-2 w-20">Max HP</th>
                    <th className="py-1.5 pr-2 w-20">Cur HP</th>
                    <th className="py-1.5 pr-2 w-16">Init+</th>
                    <th className="py-1.5 pr-2 w-16">PP</th>
                    <th className="py-1.5"></th>
                  </tr>
                </thead>
                <tbody className="divide-y divide-slate-800/70">
                  {party.map((pc) => (
                    <tr key={pc.id}>
                      <td className="py-1.5 pr-2">
                        <input
                          type="text"
                          value={pc.name}
                          onChange={(e) => updatePartyHero(pc.id, 'name', e.target.value)}
                          className="w-full bg-slate-950 border border-slate-800 rounded px-2 py-1 text-slate-100"
                        />
                      </td>
                      <td className="py-1.5 pr-2">
                        <input
                          type="text"
                          value={pc.player}
                          onChange={(e) => updatePartyHero(pc.id, 'player', e.target.value)}
                          className="w-full bg-slate-950 border border-slate-800 rounded px-2 py-1 text-slate-300"
                        />
                      </td>
                      <td className="py-1.5 pr-2">
                        <input
                          type="text"
                          value={pc.classLevel}
                          onChange={(e) => updatePartyHero(pc.id, 'classLevel', e.target.value)}
                          className="w-full bg-slate-950 border border-slate-800 rounded px-2 py-1 text-slate-300"
                        />
                      </td>
                      <td className="py-1.5 pr-2">
                        <input
                          type="number"
                          value={pc.ac}
                          onChange={(e) => updatePartyHero(pc.id, 'ac', parseInt(e.target.value, 10) || 10)}
                          className="w-full bg-slate-950 border border-slate-800 rounded px-2 py-1 font-mono"
                        />
                      </td>
                      <td className="py-1.5 pr-2">
                        <input
                          type="number"
                          value={pc.maxHp}
                          onChange={(e) =>
                            updatePartyHero(pc.id, 'maxHp', parseInt(e.target.value, 10) || 1)
                          }
                          className="w-full bg-slate-950 border border-slate-800 rounded px-2 py-1 font-mono"
                        />
                      </td>
                      <td className="py-1.5 pr-2">
                        <input
                          type="number"
                          value={pc.hp}
                          onChange={(e) => updatePartyHero(pc.id, 'hp', parseInt(e.target.value, 10) || 0)}
                          className="w-full bg-slate-950 border border-slate-800 rounded px-2 py-1 font-mono"
                        />
                      </td>
                      <td className="py-1.5 pr-2">
                        <input
                          type="number"
                          value={pc.initBonus}
                          onChange={(e) =>
                            updatePartyHero(pc.id, 'initBonus', parseInt(e.target.value, 10) || 0)
                          }
                          className="w-full bg-slate-950 border border-slate-800 rounded px-2 py-1 font-mono"
                        />
                      </td>
                      <td className="py-1.5 pr-2">
                        <input
                          type="number"
                          value={pc.passivePerc}
                          onChange={(e) =>
                            updatePartyHero(pc.id, 'passivePerc', parseInt(e.target.value, 10) || 10)
                          }
                          className="w-full bg-slate-950 border border-slate-800 rounded px-2 py-1 font-mono"
                        />
                      </td>
                      <td className="py-1.5">
                        <button
                          type="button"
                          onClick={() => removePartyHero(pc.id)}
                          className="px-2 py-1 rounded bg-rose-500/20 text-rose-300 hover:bg-rose-500/30"
                        >
                          ✕
                        </button>
                      </td>
                    </tr>
                  ))}
                </tbody>
              </table>
            </div>
            <button
              type="button"
              onClick={addPartyHero}
              className="px-3 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 text-xs text-emerald-300 font-semibold"
            >
              + Add Hero to Party
            </button>
          </div>
        )}
      </section>

      {/* Main Split: Named Minion Spawner + Live Initiative Order */}
      <div className="grid grid-cols-1 xl:grid-cols-12 gap-5">
        {/* Left: Procedural Named Minion Spawner */}
        <section className="xl:col-span-4 bg-slate-900/80 border border-slate-800 rounded-2xl p-4 space-y-3 h-fit">
          <div>
            <h3 className="text-sm font-bold text-white flex items-center gap-2">
              <span>👹</span>
              <span>Named Minion Spawner</span>
            </h3>
            <p className="text-xs text-slate-400">
              Turns boring “Goblin #1–4” into memorable named foes via `namgen` creature generators.
            </p>
          </div>

          <div className="flex flex-wrap gap-1">
            {['Goblin', 'Bandit', 'Orc', 'Kobold', 'Drow', 'Cultist', 'Guard', 'Undead'].map((preset) => (
              <button
                key={preset}
                type="button"
                onClick={() => setMinionLabel(preset)}
                className={`px-2 py-0.5 rounded text-[11px] border ${
                  minionLabel.toLowerCase() === preset.toLowerCase()
                    ? 'bg-rose-500/20 border-rose-500/50 text-rose-200'
                    : 'bg-slate-950 border-slate-800 text-slate-400 hover:text-white'
                }`}
              >
                {preset}
              </button>
            ))}
          </div>

          <form onSubmit={spawnNamedMinions} className="space-y-2.5 text-xs">
            <div className="grid grid-cols-3 gap-2">
              <div className="col-span-2">
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">
                  Creature / Faction
                </label>
                <input
                  type="text"
                  value={minionLabel}
                  onChange={(e) => setMinionLabel(e.target.value)}
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-slate-100"
                />
              </div>
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">
                  Count
                </label>
                <input
                  type="number"
                  min={1}
                  max={12}
                  value={minionCount}
                  onChange={(e) => setMinionCount(parseInt(e.target.value, 10) || 1)}
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 font-mono text-slate-100"
                />
              </div>
            </div>

            <div className="grid grid-cols-3 gap-2">
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">AC</label>
                <input
                  type="number"
                  value={minionAc}
                  onChange={(e) => setMinionAc(parseInt(e.target.value, 10) || 10)}
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 font-mono text-slate-100"
                />
              </div>
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">HP</label>
                <input
                  type="number"
                  value={minionHp}
                  onChange={(e) => setMinionHp(parseInt(e.target.value, 10) || 1)}
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 font-mono text-slate-100"
                />
              </div>
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Init +</label>
                <input
                  type="number"
                  value={minionInitBonus}
                  onChange={(e) => setMinionInitBonus(parseInt(e.target.value, 10) || 0)}
                  className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 font-mono text-slate-100"
                />
              </div>
            </div>

            <div>
              <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">
                Attack / Notes
              </label>
              <input
                type="text"
                value={minionNotes}
                onChange={(e) => setMinionNotes(e.target.value)}
                className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-slate-200"
              />
            </div>

            <div>
              <span className="block text-[10px] font-mono uppercase text-slate-500 mb-1">
                Quick-Fill from 5e Archetypes
              </span>
              <div className="flex flex-wrap gap-1 max-h-24 overflow-y-auto">
                {NPC_ARCHETYPES_5E.map((arch) => (
                  <button
                    key={arch.id}
                    type="button"
                    onClick={() => applyArchetypePreset(arch)}
                    className="px-2 py-0.5 rounded bg-slate-950 hover:bg-slate-800 border border-slate-800 text-[11px] text-slate-300"
                  >
                    {arch.name} ({arch.hp} HP)
                  </button>
                ))}
              </div>
            </div>

            <button
              type="submit"
              disabled={spawning}
              className="w-full py-2 rounded-xl bg-rose-500 hover:bg-rose-400 disabled:opacity-50 text-white font-bold text-xs"
            >
              {spawning ? 'Rolling Names...' : `⚔️ Spawn ${minionCount} Named ${minionLabel || 'Minion'}s`}
            </button>
          </form>
        </section>

        {/* Right: Initiative Order & Live Turn Tracker */}
        <section className="xl:col-span-8 bg-slate-900/80 border border-slate-800 rounded-2xl p-4 space-y-4">
          <div className="flex flex-wrap items-center justify-between gap-2 pb-3 border-b border-slate-800">
            <div className="flex items-center gap-3">
              <div className="px-3 py-1 rounded-xl bg-amber-500/15 border border-amber-500/40 text-amber-300 font-mono text-sm font-bold">
                Round {round}
              </div>
              <span className="text-xs text-slate-400">{combatants.length} Combatants</span>
            </div>

            <div className="flex flex-wrap items-center gap-1.5">
              <button
                type="button"
                onClick={prevTurn}
                className="px-2.5 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 text-xs text-slate-200"
              >
                ◀ Prev
              </button>
              <button
                type="button"
                onClick={nextTurn}
                className="px-3 py-1.5 rounded-lg bg-emerald-500 hover:bg-emerald-400 text-slate-950 text-xs font-bold"
              >
                Next Turn ▶
              </button>
              <button
                type="button"
                onClick={rollAllInitiative}
                className="px-2.5 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 text-xs text-amber-300"
              >
                🎲 Roll All Init
              </button>
              <button
                type="button"
                onClick={sortInitiative}
                className="px-2.5 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 text-xs text-slate-200"
              >
                ↕ Sort
              </button>
              <button
                type="button"
                onClick={broadcastTurnOrder}
                className="px-2.5 py-1.5 rounded-lg bg-amber-500/20 hover:bg-amber-500/30 border border-amber-500/40 text-xs font-semibold text-amber-300"
              >
                📺 Broadcast Order
              </button>
              <button
                type="button"
                onClick={clearMonsters}
                className="px-2.5 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 text-xs text-rose-300"
              >
                Clear Foes
              </button>
              <button
                type="button"
                onClick={resetEncounter}
                className="px-2.5 py-1.5 rounded-lg bg-rose-950/60 hover:bg-rose-900/60 border border-rose-500/30 text-xs text-rose-300"
              >
                Reset
              </button>
            </div>
          </div>

          {/* Concentration Check Alert Banner */}
          {concReminder && (
            <div className="bg-sky-950/70 border border-sky-400/50 rounded-xl px-3.5 py-2 flex items-center justify-between gap-2 text-xs text-sky-100">
              <div>
                <span className="font-bold text-sky-300">Concentration Check Required:</span>{' '}
                <strong>{concReminder.name}</strong> took {concReminder.damage} damage — roll{' '}
                <span className="font-mono font-bold text-amber-300">DC {concReminder.dc}</span> Constitution save!
              </div>
              <button
                type="button"
                onClick={() => setConcReminder(null)}
                className="text-sky-300 hover:text-white px-2"
              >
                ✕
              </button>
            </div>
          )}

          {/* Combatant Cards */}
          {combatants.length === 0 ? (
            <div className="text-center py-12 bg-slate-950/50 border border-dashed border-slate-800 rounded-xl text-sm text-slate-500">
              No combatants in initiative yet. Click <strong>Load Party into Encounter</strong> above or spawn named minions on the left.
            </div>
          ) : (
            <div className="space-y-2.5">
              {combatants.map((c, idx) => {
                const isTurn = idx === turnIndex;
                const hpPct = c.maxHp > 0 ? Math.max(0, Math.min(100, Math.round((c.hp / c.maxHp) * 100))) : 0;
                const deltaVal = hpDeltas[c.id] ?? '5';
                const isConcentrating = Array.isArray(c.conditions) && c.conditions.includes('Concentrating');

                const sideBadge =
                  c.side === 'pc'
                    ? 'bg-emerald-500/20 text-emerald-300 border-emerald-500/40'
                    : c.side === 'npc'
                    ? 'bg-sky-500/20 text-sky-300 border-sky-500/40'
                    : 'bg-rose-500/20 text-rose-300 border-rose-500/40';

                return (
                  <div
                    key={c.id}
                    className={`rounded-xl border p-3 transition-colors ${
                      isTurn
                        ? 'bg-slate-950 border-amber-400 shadow-lg shadow-amber-500/10'
                        : c.hp <= 0
                        ? 'bg-slate-950/40 border-slate-800/70 opacity-65'
                        : 'bg-slate-950/80 border-slate-800'
                    }`}
                  >
                    <div className="flex flex-wrap items-center justify-between gap-2">
                      {/* Init + Name + Side + AC */}
                      <div className="flex items-center gap-2.5 min-w-[200px]">
                        <div className="flex flex-col items-center">
                          <span className="text-[9px] font-mono uppercase text-slate-500">Init</span>
                          <input
                            type="number"
                            value={c.initiative}
                            onChange={(e) =>
                              setCombatantField(c.id, 'initiative', parseInt(e.target.value, 10) || 0)
                            }
                            className="w-12 text-center bg-slate-900 border border-slate-700 rounded-lg py-1 font-mono text-sm font-bold text-amber-300"
                          />
                        </div>

                        <div>
                          <div className="flex flex-wrap items-center gap-1.5">
                            {isTurn && (
                              <span className="px-1.5 py-0.5 rounded bg-amber-500 text-slate-950 text-[10px] font-extrabold uppercase">
                                Turn
                              </span>
                            )}
                            <span className={`font-bold text-sm ${c.hp <= 0 ? 'line-through text-slate-400' : 'text-white'}`}>
                              {c.name}
                            </span>
                            <span className={`px-1.5 py-0.5 rounded border text-[10px] font-mono uppercase ${sideBadge}`}>
                              {c.side}
                            </span>
                            <span className="px-1.5 py-0.5 rounded bg-slate-900 border border-slate-700 text-[11px] font-mono text-slate-300">
                              AC {c.ac}
                            </span>
                            {isConcentrating && (
                              <span className="px-1.5 py-0.5 rounded bg-sky-500/20 border border-sky-400/50 text-[10px] font-mono text-sky-200">
                                ✦ Conc.
                              </span>
                            )}
                          </div>
                          {c.notes && <p className="text-[11px] text-slate-400 mt-0.5">{c.notes}</p>}
                        </div>
                      </div>

                      {/* HP Bar & Quick Damage/Heal */}
                      <div className="flex flex-wrap items-center gap-2">
                        <div className="w-36">
                          <div className="flex items-center justify-between text-[11px] font-mono mb-0.5">
                            <span className="text-slate-200">
                              HP {c.hp}/{c.maxHp}
                              {c.tempHp > 0 && <span className="text-sky-300"> (+{c.tempHp})</span>}
                            </span>
                            <span className="text-slate-500">{hpPct}%</span>
                          </div>
                          <div className="h-2 bg-slate-900 rounded-full overflow-hidden border border-slate-800">
                            <div
                              className={`h-full transition-all ${
                                hpPct > 50 ? 'bg-emerald-500' : hpPct > 20 ? 'bg-amber-500' : 'bg-rose-500'
                              }`}
                              style={{ width: `${hpPct}%` }}
                            />
                          </div>
                        </div>

                        <div className="flex items-center gap-1">
                          <button
                            type="button"
                            onClick={() => applyHpChange(c.id, -(parseInt(deltaVal, 10) || 1))}
                            className="px-2 py-1 rounded bg-rose-500/20 hover:bg-rose-500/35 border border-rose-500/40 text-xs font-mono font-bold text-rose-200"
                            title="Apply damage"
                          >
                            -Dmg
                          </button>
                          <input
                            type="number"
                            min={1}
                            value={deltaVal}
                            onChange={(e) =>
                              setHpDeltas((prev) => ({ ...prev, [c.id]: e.target.value }))
                            }
                            className="w-12 text-center bg-slate-900 border border-slate-700 rounded py-1 text-xs font-mono text-white"
                          />
                          <button
                            type="button"
                            onClick={() => applyHpChange(c.id, parseInt(deltaVal, 10) || 1)}
                            className="px-2 py-1 rounded bg-emerald-500/20 hover:bg-emerald-500/35 border border-emerald-500/40 text-xs font-mono font-bold text-emerald-200"
                            title="Apply healing"
                          >
                            +Heal
                          </button>
                          <button
                            type="button"
                            onClick={() =>
                              setCombatantField(
                                c.id,
                                'tempHp',
                                (Number(c.tempHp) || 0) + (parseInt(deltaVal, 10) || 5)
                              )
                            }
                            className="px-2 py-1 rounded bg-sky-500/15 hover:bg-sky-500/30 border border-sky-500/40 text-[11px] font-mono text-sky-200"
                            title="Grant Temporary HP"
                          >
                            +Tmp
                          </button>
                          <button
                            type="button"
                            onClick={() => removeCombatant(c.id)}
                            className="px-2 py-1 rounded bg-slate-900 hover:bg-slate-800 text-slate-400 hover:text-rose-300 text-xs"
                            title="Remove from encounter"
                          >
                            ✕
                          </button>
                        </div>
                      </div>
                    </div>

                    {/* 5e Conditions Strip */}
                    <div className="mt-2.5 pt-2 border-t border-slate-800/70 flex flex-wrap gap-1">
                      {CONDITIONS_5E.map((cond) => {
                        const active = Array.isArray(c.conditions) && c.conditions.includes(cond.id);
                        const colorClass =
                          CONDITION_COLOR_STYLES[cond.color] ||
                          'bg-slate-700/40 border-slate-500 text-slate-200';
                        return (
                          <button
                            key={cond.id}
                            type="button"
                            title={cond.summary}
                            onClick={() => toggleCondition(c.id, cond.id)}
                            className={`px-1.5 py-0.5 rounded text-[10px] font-mono border transition-colors ${
                              active
                                ? colorClass
                                : 'bg-slate-900/50 border-slate-800/80 text-slate-500 hover:text-slate-300'
                            }`}
                          >
                            {cond.short}
                          </button>
                        );
                      })}
                    </div>
                  </div>
                );
              })}
            </div>
          )}
        </section>
      </div>
    </div>
  );
}
