'use client';

import React, { useState, useEffect } from 'react';
import { DND_ANCESTRIES, HUMAN_CULTURES, NPC_ARCHETYPES_5E } from 'namgen.js/dnd';

const LOCKABLE_FIELDS = [
  'name',
  'occupation',
  'voice',
  'portrait',
  'clothing',
  'personality',
  'ideal',
  'bond',
  'flaw',
  'secret',
  'pocketLoot',
  'archetype',
];

function LockButton({ field, locked, onToggle, label }) {
  return (
    <button
      type="button"
      onClick={() => onToggle(field)}
      title={locked ? `Unlock ${label || field}` : `Lock ${label || field} across rerolls`}
      className={`text-[11px] px-1.5 py-0.5 rounded border transition-colors ${
        locked
          ? 'bg-amber-500/20 border-amber-500/50 text-amber-300'
          : 'bg-slate-900 border-slate-800 text-slate-500 hover:text-slate-300'
      }`}
    >
      {locked ? '🔒 Locked' : '🔓 Lock'}
    </button>
  );
}

export default function NpcForgePanel({
  onSaveCodex,
  onSendToCombat,
  onAppendSessionNote,
  onRevealHandout,
  onWeaveWithAi,
  onNotify,
}) {
  // Quick Name Matrix state
  const [quickAncestryId, setQuickAncestryId] = useState('elf');
  const [quickCultureId, setQuickCultureId] = useState('');
  const [quickGenderType, setQuickGenderType] = useState(0);
  const [quickNames, setQuickNames] = useState([]);
  const [quickLoading, setQuickLoading] = useState(false);

  // Deep NPC Dossier state
  const [ancestryId, setAncestryId] = useState('random');
  const [cultureId, setCultureId] = useState('none');
  const [genderType, setGenderType] = useState(0);
  const [archetypeId, setArchetypeId] = useState('random');
  const [seed, setSeed] = useState('');
  const [lockedFields, setLockedFields] = useState({});
  const [npc, setNpc] = useState(null);
  const [npcLoading, setNpcLoading] = useState(false);

  const selectedQuickAncestry =
    DND_ANCESTRIES.find((a) => a.id === quickAncestryId) || DND_ANCESTRIES[0];

  const rollQuickMatrix = async (
    nextAncestryId = quickAncestryId,
    nextCultureId = quickCultureId,
    nextGenderType = quickGenderType
  ) => {
    const anc = DND_ANCESTRIES.find((a) => a.id === nextAncestryId) || DND_ANCESTRIES[0];
    const cul = nextCultureId ? HUMAN_CULTURES.find((c) => c.id === nextCultureId) : null;
    const generator = cul ? cul.generator : anc.generator;

    setQuickLoading(true);
    try {
      const res = await fetch('/api/namgen', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          action: 'roll',
          generator,
          count: 12,
          unique: true,
          type: Number(nextGenderType) || 0,
          capitalize: true,
        }),
      });
      const data = await res.json();
      setQuickNames(data.names || []);
    } catch (err) {
      onNotify?.(`Failed to roll ancestry names: ${err.message}`);
    } finally {
      setQuickLoading(false);
    }
  };

  const forgeDossier = async (overrides = {}) => {
    setNpcLoading(true);
    const nextLocked = overrides.lockedFields ?? lockedFields;
    const nextCurrent = overrides.currentNpc ?? npc;
    const nextAncestry = overrides.ancestryId ?? ancestryId;
    const nextCulture = overrides.cultureId ?? cultureId;
    const nextGender = overrides.genderType ?? genderType;
    const nextArch = overrides.archetypeId ?? archetypeId;
    const nextSeed = overrides.seed ?? seed;

    try {
      const res = await fetch('/api/namgen', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          action: 'npc',
          ancestryId: nextAncestry,
          cultureId: nextCulture,
          genderType: Number(nextGender) || 0,
          archetypeId: nextArch,
          seed: nextSeed,
          lockedFields: nextLocked,
          currentNpc: nextCurrent,
        }),
      });
      const data = await res.json();
      if (data.npc) {
        setNpc(data.npc);
      } else {
        onNotify?.(data.error || 'Could not forge NPC dossier');
      }
    } catch (err) {
      onNotify?.(`NPC generation failed: ${err.message}`);
    } finally {
      setNpcLoading(false);
    }
  };

  useEffect(() => {
    rollQuickMatrix('elf', '', 0);
    forgeDossier();
  }, []);

  const toggleLock = (field) => {
    setLockedFields((prev) => ({ ...prev, [field]: !prev[field] }));
  };

  const unlockAll = () => setLockedFields({});

  const copyText = (text, label = 'Copied') => {
    if (typeof navigator !== 'undefined' && navigator.clipboard) {
      navigator.clipboard.writeText(text);
    }
    onNotify?.(`${label}: ${text}`);
  };

  const speakName = (text) => {
    if (typeof window === 'undefined' || !('speechSynthesis' in window)) {
      onNotify?.('Web Speech synthesis unavailable in this browser');
      return;
    }
    window.speechSynthesis.cancel();
    const utter = new SpeechSynthesisUtterance(text);
    utter.rate = 0.92;
    window.speechSynthesis.speak(utter);
  };

  const promoteQuickName = (rolledName) => {
    const nextLocked = { ...lockedFields, name: true };
    const seededCurrent = { ...(npc || {}), name: rolledName };
    setLockedFields(nextLocked);
    if (quickCultureId) {
      setCultureId(quickCultureId);
    } else {
      setCultureId('none');
      setAncestryId(quickAncestryId);
    }
    forgeDossier({
      ancestryId: quickAncestryId,
      cultureId: quickCultureId || 'none',
      genderType: quickGenderType,
      lockedFields: nextLocked,
      currentNpc: seededCurrent,
    });
  };

  const activeLockCount = LOCKABLE_FIELDS.filter((f) => lockedFields[f]).length;

  return (
    <div className="grid grid-cols-1 xl:grid-cols-12 gap-5">
      {/* Left Column: 30 Ancestry + 10 Human Culture Quick Name Matrix */}
      <section className="xl:col-span-5 bg-slate-900/80 border border-slate-800 rounded-2xl p-4 flex flex-col gap-4">
        <div className="flex items-start justify-between gap-2">
          <div>
            <h2 className="text-base font-bold text-white flex items-center gap-2">
              <span>🧬</span>
              <span>Ancestry &amp; Culture Name Matrix</span>
            </h2>
            <p className="text-xs text-slate-400">
              30 D&amp;D 5e lineages &amp; 10 human cultures. Promote any name into a full NPC dossier.
            </p>
          </div>
          <button
            type="button"
            onClick={() => rollQuickMatrix()}
            disabled={quickLoading}
            className="px-3 py-1.5 rounded-lg bg-emerald-500 hover:bg-emerald-400 disabled:opacity-50 text-slate-950 text-xs font-bold whitespace-nowrap"
          >
            {quickLoading ? 'Rolling...' : '🎲 Roll 12'}
          </button>
        </div>

        {/* Culture + Gender Controls */}
        <div className="grid grid-cols-1 sm:grid-cols-2 gap-2.5 bg-slate-950/70 p-2.5 rounded-xl border border-slate-800">
          <div>
            <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">
              Human Culture Override
            </label>
            <select
              value={quickCultureId}
              onChange={(e) => {
                const val = e.target.value;
                setQuickCultureId(val);
                rollQuickMatrix(quickAncestryId, val, quickGenderType);
              }}
              className="w-full bg-slate-900 border border-slate-700 rounded-lg px-2.5 py-1.5 text-xs text-slate-100 focus:outline-none focus:border-emerald-500"
            >
              <option value="">Use Selected Ancestry</option>
              {HUMAN_CULTURES.map((c) => (
                <option key={c.id} value={c.id}>
                  {c.label}
                </option>
              ))}
            </select>
          </div>

          <div>
            <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">
              Naming Style / Gender Type
            </label>
            <div className="grid grid-cols-3 gap-1">
              {[
                { val: 0, label: 'Default' },
                { val: 1, label: 'Fem.' },
                { val: 2, label: 'Alt' },
              ].map((opt) => (
                <button
                  key={opt.val}
                  type="button"
                  onClick={() => {
                    setQuickGenderType(opt.val);
                    rollQuickMatrix(quickAncestryId, quickCultureId, opt.val);
                  }}
                  className={`py-1.5 rounded-lg text-xs font-medium border transition-colors ${
                    quickGenderType === opt.val
                      ? 'bg-emerald-500/20 border-emerald-500/50 text-emerald-300'
                      : 'bg-slate-900 border-slate-800 text-slate-400 hover:text-white'
                  }`}
                >
                  {opt.label}
                </button>
              ))}
            </div>
          </div>
        </div>

        {/* 30 Ancestry Pills */}
        <div className="flex flex-wrap gap-1.5 max-h-44 overflow-y-auto pr-1">
          {DND_ANCESTRIES.map((anc) => {
            const active = !quickCultureId && quickAncestryId === anc.id;
            return (
              <button
                key={anc.id}
                type="button"
                onClick={() => {
                  setQuickAncestryId(anc.id);
                  setQuickCultureId('');
                  rollQuickMatrix(anc.id, '', quickGenderType);
                }}
                className={`px-2 py-1 rounded-lg text-xs border flex items-center gap-1 transition-colors ${
                  active
                    ? 'bg-amber-500/20 border-amber-500/60 text-amber-200 font-semibold'
                    : 'bg-slate-950 border-slate-800 text-slate-300 hover:border-slate-700 hover:text-white'
                }`}
              >
                <span>{anc.icon}</span>
                <span>{anc.label}</span>
              </button>
            );
          })}
        </div>

        {/* Selected Ancestry Trait Helper */}
        {!quickCultureId && selectedQuickAncestry && (
          <div className="text-[11px] bg-slate-950/60 border border-slate-800/80 rounded-lg px-3 py-1.5 text-slate-400">
            <span className="text-amber-300 font-semibold">
              {selectedQuickAncestry.icon} {selectedQuickAncestry.label}:
            </span>{' '}
            {selectedQuickAncestry.traits}
          </div>
        )}

        {/* 12 Rolled Name Cards */}
        <div className="grid grid-cols-1 sm:grid-cols-2 gap-2">
          {quickNames.map((name, idx) => (
            <div
              key={`${name}_${idx}`}
              className="group bg-slate-950 border border-slate-800 hover:border-emerald-500/40 rounded-xl p-2.5 flex items-center justify-between gap-2"
            >
              <button
                type="button"
                onClick={() => copyText(name, 'Copied NPC name')}
                className="text-left text-sm font-medium text-slate-100 hover:text-emerald-300 truncate flex-1"
                title="Click to copy name"
              >
                {name}
              </button>
              <div className="flex items-center gap-1 shrink-0">
                <button
                  type="button"
                  onClick={() => speakName(name)}
                  title="Pronounce name aloud"
                  className="px-1.5 py-1 rounded bg-slate-900 hover:bg-slate-800 text-xs text-slate-300"
                >
                  🔊
                </button>
                <button
                  type="button"
                  onClick={() => promoteQuickName(name)}
                  title="Forge full 5e NPC dossier around this name"
                  className="px-2 py-1 rounded bg-emerald-500/15 hover:bg-emerald-500/30 border border-emerald-500/40 text-[11px] font-semibold text-emerald-300"
                >
                  Forge →
                </button>
              </div>
            </div>
          ))}
        </div>
      </section>

      {/* Right Column: Deep 5e NPC Dossier Forge */}
      <section className="xl:col-span-7 bg-slate-900/80 border border-slate-800 rounded-2xl p-4 flex flex-col gap-4">
        {/* Controls */}
        <div className="flex flex-wrap items-end justify-between gap-3 pb-3 border-b border-slate-800">
          <div>
            <h2 className="text-base font-bold text-white flex items-center gap-2">
              <span>🧙</span>
              <span>Deep 5e NPC Dossier Forge</span>
            </h2>
            <p className="text-xs text-slate-400">
              Lock any field (`🔒`) to keep it while re-rolling the rest. Player-safe vs. DM-secret blocks stay separated.
            </p>
          </div>
          <div className="flex items-center gap-2">
            {activeLockCount > 0 && (
              <button
                type="button"
                onClick={unlockAll}
                className="px-2.5 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 text-xs text-amber-300"
              >
                Unlock All ({activeLockCount})
              </button>
            )}
            <button
              type="button"
              onClick={() => forgeDossier()}
              disabled={npcLoading}
              className="px-4 py-2 rounded-xl bg-amber-500 hover:bg-amber-400 disabled:opacity-50 text-slate-950 text-xs font-bold shadow-lg shadow-amber-500/10"
            >
              {npcLoading ? 'Forging...' : '⚡ Forge NPC'}
            </button>
          </div>
        </div>

        {/* Selectors */}
        <div className="grid grid-cols-2 sm:grid-cols-4 gap-2.5">
          <div>
            <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Ancestry</label>
            <select
              value={ancestryId}
              onChange={(e) => setAncestryId(e.target.value)}
              className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-xs text-slate-100"
            >
              <option value="random">Random 5e Lineage</option>
              {DND_ANCESTRIES.map((a) => (
                <option key={a.id} value={a.id}>
                  {a.icon} {a.label}
                </option>
              ))}
            </select>
          </div>

          <div>
            <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Human Culture</label>
            <select
              value={cultureId}
              onChange={(e) => setCultureId(e.target.value)}
              className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-xs text-slate-100"
            >
              <option value="none">None (Ancestry Default)</option>
              {HUMAN_CULTURES.map((c) => (
                <option key={c.id} value={c.id}>
                  {c.label}
                </option>
              ))}
            </select>
          </div>

          <div>
            <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">5e Archetype</label>
            <select
              value={archetypeId}
              onChange={(e) => setArchetypeId(e.target.value)}
              className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-xs text-slate-100"
            >
              <option value="random">Random Stat Block</option>
              {NPC_ARCHETYPES_5E.map((arch) => (
                <option key={arch.id} value={arch.id}>
                  {arch.name} (CR {arch.cr})
                </option>
              ))}
            </select>
          </div>

          <div>
            <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Optional Seed</label>
            <input
              type="text"
              value={seed}
              onChange={(e) => setSeed(e.target.value)}
              placeholder="e.g. waterdeep-04"
              className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-xs text-slate-100 placeholder-slate-600"
            />
          </div>
        </div>

        {/* Dossier Output */}
        {npc && (
          <div className="space-y-4">
            {/* Header & Primary Action Buttons */}
            <div className="bg-slate-950 border border-slate-800 rounded-xl p-4 flex flex-col sm:flex-row sm:items-center justify-between gap-3">
              <div>
                <div className="flex flex-wrap items-center gap-2">
                  <span className="text-xl">{npc.ancestryIcon || '🧝'}</span>
                  <h3 className="text-xl font-extrabold text-white">{npc.name}</h3>
                  <LockButton field="name" locked={!!lockedFields.name} onToggle={toggleLock} />
                  <button
                    type="button"
                    onClick={() => speakName(npc.name)}
                    className="px-2 py-0.5 rounded bg-slate-900 border border-slate-800 text-xs text-slate-300 hover:text-white"
                  >
                    🔊
                  </button>
                </div>
                <div className="mt-1 flex flex-wrap items-center gap-2 text-xs text-slate-400">
                  <span className="text-amber-300 font-semibold">{npc.ancestry}</span>
                  {npc.culture && <span className="text-slate-500">• {npc.culture}</span>}
                  <span>•</span>
                  <span className="text-emerald-300 font-medium">{npc.occupation}</span>
                  <LockButton field="occupation" locked={!!lockedFields.occupation} onToggle={toggleLock} />
                </div>
                {npc.ancestryTraits && (
                  <p className="text-[11px] text-slate-500 mt-1">{npc.ancestryTraits}</p>
                )}
              </div>

              <div className="flex flex-wrap gap-1.5">
                <button
                  type="button"
                  onClick={() =>
                    onSaveCodex?.({
                      kind: 'npc',
                      title: npc.name,
                      subtitle: `${npc.ancestry} ${npc.occupation} (${npc.archetype.name}, CR ${npc.archetype.cr})`,
                      status: 'Met',
                      tags: [npc.ancestry.toLowerCase(), 'npc'],
                      summary: `${npc.portrait}\n${npc.clothing}\nVoice: ${npc.voice}`,
                      dmNotes: `Secret: ${npc.secret} | Ideal: ${npc.ideal} | Bond: ${npc.bond} | Flaw: ${npc.flaw} | Pocket: ${npc.pocketLoot}`,
                      data: npc,
                    })
                  }
                  className="px-2.5 py-1.5 rounded-lg bg-emerald-500/20 hover:bg-emerald-500/30 border border-emerald-500/40 text-xs font-semibold text-emerald-300"
                >
                  + Save to Codex
                </button>
                <button
                  type="button"
                  onClick={() =>
                    onSendToCombat?.([
                      {
                        name: npc.name,
                        side: 'npc',
                        ac: npc.archetype.ac,
                        maxHp: npc.archetype.hp,
                        hp: npc.archetype.hp,
                        tempHp: 0,
                        initBonus: 1,
                        notes: `${npc.archetype.name} • ${npc.archetype.attack}`,
                      },
                    ])
                  }
                  className="px-2.5 py-1.5 rounded-lg bg-rose-500/15 hover:bg-rose-500/25 border border-rose-500/40 text-xs font-semibold text-rose-300"
                >
                  ⚔️ Send to Combat
                </button>
                <button
                  type="button"
                  onClick={() =>
                    onAppendSessionNote?.(
                      `- Met **[[${npc.name}]]** (${npc.ancestry} ${npc.occupation}) — *${npc.voice}*. Hook: "${npc.dialogueHook}"`
                    )
                  }
                  className="px-2.5 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 text-xs text-slate-200"
                >
                  📝 Log to Session
                </button>
                <button
                  type="button"
                  onClick={() =>
                    onRevealHandout?.({
                      kind: 'npc',
                      title: npc.name,
                      subtitle: `${npc.ancestry} • ${npc.occupation}`,
                      body: `${npc.portrait}\n\n${npc.clothing}`,
                      quote: `"${npc.dialogueHook.replace(/^"|"$/g, '')}"`,
                    })
                  }
                  className="px-2.5 py-1.5 rounded-lg bg-amber-500/20 hover:bg-amber-500/30 border border-amber-500/40 text-xs font-semibold text-amber-300"
                >
                  📺 Reveal to Players
                </button>
                {onWeaveWithAi && (
                  <button
                    type="button"
                    onClick={() =>
                      onWeaveWithAi({
                        tool: 'npc-roleplay',
                        title: `Roleplay: ${npc.name}`,
                        prompt: `Step into character as ${npc.name} (${npc.ancestry} ${npc.occupation}). Voice/cadence: ${npc.voice}. Secret agenda (DM eyes only): ${npc.secretAgenda}. Deliver an opening greeting and a veiled threat or hook.`,
                        contextText: JSON.stringify(npc, null, 2),
                      })
                    }
                    className="px-2.5 py-1.5 rounded-lg bg-amber-500/20 hover:bg-amber-500/30 border border-amber-500/50 text-xs font-semibold text-amber-200"
                  >
                    ✨ Weave with AI
                  </button>
                )}
              </div>
            </div>

            {/* Public / Player-Visible Read-Aloud Section */}
            <div className="bg-slate-950/70 border border-slate-800 rounded-xl p-3.5 space-y-3">
              <div className="text-[11px] font-mono uppercase tracking-wider text-emerald-400">
                Player-Facing Appearance &amp; Roleplay Cue
              </div>
              <div className="grid grid-cols-1 md:grid-cols-2 gap-3 text-xs">
                <div className="bg-slate-900/70 border border-slate-800 rounded-lg p-2.5 space-y-1">
                  <div className="flex items-center justify-between">
                    <span className="font-semibold text-slate-300">Appearance</span>
                    <LockButton field="portrait" locked={!!lockedFields.portrait} onToggle={toggleLock} />
                  </div>
                  <p className="text-slate-300 whitespace-pre-line leading-relaxed">{npc.portrait}</p>
                </div>

                <div className="bg-slate-900/70 border border-slate-800 rounded-lg p-2.5 space-y-1">
                  <div className="flex items-center justify-between">
                    <span className="font-semibold text-slate-300">Attire &amp; Gear</span>
                    <LockButton field="clothing" locked={!!lockedFields.clothing} onToggle={toggleLock} />
                  </div>
                  <p className="text-slate-300 whitespace-pre-line leading-relaxed">{npc.clothing}</p>
                </div>

                <div className="bg-slate-900/70 border border-slate-800 rounded-lg p-2.5 space-y-1">
                  <div className="flex items-center justify-between">
                    <span className="font-semibold text-slate-300">Mannerism &amp; Personality</span>
                    <LockButton field="personality" locked={!!lockedFields.personality} onToggle={toggleLock} />
                  </div>
                  <p className="text-slate-300 whitespace-pre-line leading-relaxed">{npc.personality}</p>
                </div>

                <div className="bg-slate-900/70 border border-slate-800 rounded-lg p-2.5 space-y-1">
                  <span className="font-semibold text-amber-300 block">Opening Line</span>
                  <p className="italic text-slate-200 leading-relaxed">{npc.dialogueHook}</p>
                </div>
              </div>
            </div>

            {/* DM-Only Eyes Only Section */}
            <div className="bg-slate-950/90 border border-rose-500/30 rounded-xl p-3.5 space-y-3">
              <div className="flex items-center justify-between">
                <span className="text-[11px] font-mono uppercase tracking-wider text-rose-400">
                  DM Screen Only — Secrets, Voice &amp; 5e Stat Block
                </span>
                <span className="text-[10px] text-slate-500">Never sent to /handout</span>
              </div>

              <div className="grid grid-cols-1 md:grid-cols-2 gap-2.5 text-xs">
                <div className="bg-slate-900/80 border border-slate-800 rounded-lg p-2.5 space-y-1">
                  <div className="flex items-center justify-between">
                    <span className="font-semibold text-sky-300">Voice &amp; Cadence</span>
                    <LockButton field="voice" locked={!!lockedFields.voice} onToggle={toggleLock} />
                  </div>
                  <p className="text-slate-300">{npc.voice}</p>
                </div>

                <div className="bg-slate-900/80 border border-slate-800 rounded-lg p-2.5 space-y-1">
                  <div className="flex items-center justify-between">
                    <span className="font-semibold text-amber-300">Pocket Loot</span>
                    <LockButton field="pocketLoot" locked={!!lockedFields.pocketLoot} onToggle={toggleLock} />
                  </div>
                  <p className="text-slate-300">{npc.pocketLoot}</p>
                </div>

                <div className="bg-slate-900/80 border border-slate-800 rounded-lg p-2.5 space-y-1">
                  <div className="flex items-center justify-between">
                    <span className="font-semibold text-emerald-300">Ideal</span>
                    <LockButton field="ideal" locked={!!lockedFields.ideal} onToggle={toggleLock} />
                  </div>
                  <p className="text-slate-300">{npc.ideal}</p>
                </div>

                <div className="bg-slate-900/80 border border-slate-800 rounded-lg p-2.5 space-y-1">
                  <div className="flex items-center justify-between">
                    <span className="font-semibold text-indigo-300">Bond</span>
                    <LockButton field="bond" locked={!!lockedFields.bond} onToggle={toggleLock} />
                  </div>
                  <p className="text-slate-300">{npc.bond}</p>
                </div>

                <div className="bg-slate-900/80 border border-slate-800 rounded-lg p-2.5 space-y-1">
                  <div className="flex items-center justify-between">
                    <span className="font-semibold text-orange-300">Exploitable Flaw</span>
                    <LockButton field="flaw" locked={!!lockedFields.flaw} onToggle={toggleLock} />
                  </div>
                  <p className="text-slate-300">{npc.flaw}</p>
                </div>

                <div className="bg-rose-950/30 border border-rose-500/40 rounded-lg p-2.5 space-y-1">
                  <div className="flex items-center justify-between">
                    <span className="font-bold text-rose-300">Dark Secret</span>
                    <LockButton field="secret" locked={!!lockedFields.secret} onToggle={toggleLock} />
                  </div>
                  <p className="text-rose-100">{npc.secret}</p>
                </div>
              </div>

              {npc.backstory && (
                <div className="bg-slate-900/60 border border-slate-800 rounded-lg p-2.5 text-xs">
                  <span className="font-semibold text-slate-300 block mb-1">Backstory Sketch</span>
                  <p className="text-slate-400 whitespace-pre-line">{npc.backstory}</p>
                </div>
              )}

              {/* 5e Stat Block Card */}
              {npc.archetype && (
                <div className="bg-slate-900 border border-slate-700/80 rounded-xl p-3">
                  <div className="flex flex-wrap items-center justify-between gap-2 mb-2">
                    <div className="flex items-center gap-2">
                      <span className="text-sm font-bold text-white">{npc.archetype.name}</span>
                      <span className="px-2 py-0.5 rounded bg-rose-500/20 text-rose-300 text-[11px] font-mono">
                        CR {npc.archetype.cr}
                      </span>
                      <span className="text-xs text-slate-400 italic">{npc.archetype.vibe}</span>
                    </div>
                    <LockButton field="archetype" locked={!!lockedFields.archetype} onToggle={toggleLock} />
                  </div>
                  <div className="grid grid-cols-2 sm:grid-cols-5 gap-2 text-xs font-mono">
                    <div className="bg-slate-950 rounded-lg px-2.5 py-1.5 border border-slate-800">
                      <span className="text-slate-500 block text-[10px]">AC</span>
                      <span className="text-white font-bold">{npc.archetype.ac}</span>
                    </div>
                    <div className="bg-slate-950 rounded-lg px-2.5 py-1.5 border border-slate-800">
                      <span className="text-slate-500 block text-[10px]">HP</span>
                      <span className="text-emerald-300 font-bold">
                        {npc.archetype.hp} ({npc.archetype.hitDice})
                      </span>
                    </div>
                    <div className="bg-slate-950 rounded-lg px-2.5 py-1.5 border border-slate-800">
                      <span className="text-slate-500 block text-[10px]">Speed</span>
                      <span className="text-slate-200">{npc.archetype.speed}</span>
                    </div>
                    <div className="bg-slate-950 rounded-lg px-2.5 py-1.5 border border-slate-800">
                      <span className="text-slate-500 block text-[10px]">Passive Perc</span>
                      <span className="text-amber-300 font-bold">{npc.archetype.passivePerc}</span>
                    </div>
                    <div className="col-span-2 sm:col-span-1 bg-slate-950 rounded-lg px-2.5 py-1.5 border border-slate-800">
                      <span className="text-slate-500 block text-[10px]">Generator</span>
                      <span className="text-slate-400 truncate block">{npc.generatorUsed}</span>
                    </div>
                  </div>
                  <div className="mt-2 text-xs text-slate-300 bg-slate-950/60 px-2.5 py-1.5 rounded border border-slate-800">
                    <span className="font-semibold text-amber-300">Primary Action:</span> {npc.archetype.attack}
                  </div>
                </div>
              )}
            </div>
          </div>
        )}
      </section>
    </div>
  );
}
