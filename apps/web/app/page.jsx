'use client';

import React, { useState, useEffect, useRef, useCallback } from 'react';
import { getGenerator, generators as allGenerators } from 'namgen.js';
import NpcForgePanel from '../components/NpcForgePanel';
import CombatTrackerPanel from '../components/CombatTrackerPanel';
import EstablishmentsPanel from '../components/EstablishmentsPanel';
import AdventureForgePanel from '../components/AdventureForgePanel';
import WorldMatrixPanel from '../components/WorldMatrixPanel';
import CampaignCodexPanel from '../components/CampaignCodexPanel';
import GeneratorStudioPanel from '../components/GeneratorStudioPanel';
import GlobalSettingsModal from '../components/GlobalSettingsModal';
import NamespaceOracleWorkspace from '../components/NamespaceOracleWorkspace';
import AiStorytellerWorkspace from '../components/AiStorytellerWorkspace';
import QuickRollModal from '../components/QuickRollModal';
import HandoutPreviewModal from '../components/HandoutPreviewModal';
import DiceRollerDrawer from '../components/DiceRollerDrawer';
import { broadcastPlayerHandout } from '../lib/handoutChannel';

const TABS = [
  { id: 'npc', label: 'NPC Forge', icon: '🧙' },
  { id: 'combat', label: 'Combat & Initiative', icon: '⚔️' },
  { id: 'shops', label: 'Taverns & Shops', icon: '🍺' },
  { id: 'adventure', label: 'Dungeons & Loot', icon: '🏰' },
  { id: 'world', label: 'Factions & Realms', icon: '🗺️' },
  { id: 'codex', label: 'Codex & Journal', icon: '📚' },
  { id: 'studio', label: `${allGenerators.length} Generator Studio`, icon: '🎲' },
];

export default function DmCommandCenterPage({ initialWorkspace = '' }) {
  const [vault, setVault] = useState(null);
  const [storageInfo, setStorageInfo] = useState(null);
  const [activeTab, setActiveTab] = useState('npc');
  const [saveState, setSaveState] = useState('idle'); // idle | saving | saved | error
  const [toast, setToast] = useState('');

  // Workspace Launchpad & AI/Oracle Settings
  const [workspace, setWorkspace] = useState(
    initialWorkspace === 'storyteller' || initialWorkspace === 'oracle' ? initialWorkspace : 'dm'
  );
  const [settings, setSettings] = useState(null);
  const [cppEngine, setCppEngine] = useState(null);
  const [settingsModalOpen, setSettingsModalOpen] = useState(false);
  const [handoffContext, setHandoffContext] = useState(null);

  // Floating Modals & Tools
  const [quickRollOpen, setQuickRollOpen] = useState(false);
  const [diceOpen, setDiceOpen] = useState(false);
  const [previewHandout, setPreviewHandout] = useState(null);
  const [newCampModalOpen, setNewCampModalOpen] = useState(false);
  const [newCampName, setNewCampName] = useState('');
  const [newCampSetting, setNewCampSetting] = useState('Forgotten Realms');
  const [newCampTier, setNewCampTier] = useState(1);

  // Pinned Quick-Roll Popover
  const [pinnedResult, setPinnedResult] = useState(null); // { genId, label, names }

  const dirtyRef = useRef(false);
  const saveTimerRef = useRef(null);
  const toastTimerRef = useRef(null);

  const notify = useCallback((msg) => {
    setToast(msg);
    if (toastTimerRef.current) clearTimeout(toastTimerRef.current);
    toastTimerRef.current = setTimeout(() => setToast(''), 3200);
  }, []);

  const switchWorkspace = useCallback((next) => {
    setWorkspace(next);
    try {
      localStorage.setItem('namgen_active_workspace', next);
    } catch {}
  }, []);

  const handleWeaveWithAi = useCallback(
    (ctx) => {
      setHandoffContext(ctx || null);
      switchWorkspace('storyteller');
    },
    [switchWorkspace]
  );

  // Restore saved/query workspace & load Global AI/Oracle Settings on mount
  useEffect(() => {
    if (!initialWorkspace) {
      try {
        const param = new URLSearchParams(window.location.search).get('workspace');
        const saved = localStorage.getItem('namgen_active_workspace');
        const target = param || saved;
        if (target === 'dm' || target === 'storyteller' || target === 'oracle') {
          setWorkspace(target);
        }
      } catch {}
    }

    let cancelled = false;
    (async () => {
      try {
        const res = await fetch('/api/settings');
        const data = await res.json();
        if (!cancelled && res.ok) {
          setSettings(data.settings || null);
          setCppEngine(data.cppEngine || null);
        }
      } catch {}
    })();
    return () => {
      cancelled = true;
    };
  }, [initialWorkspace]);

  // Load Vault on mount
  useEffect(() => {
    let cancelled = false;
    (async () => {
      try {
        const res = await fetch('/api/campaigns');
        const data = await res.json();
        if (!cancelled && data.vault) {
          setVault(data.vault);
          setStorageInfo(data.storage || null);
          setSaveState('saved');
        }
      } catch (err) {
        if (!cancelled) {
          setSaveState('error');
          notify(`Failed to load local vault: ${err.message}`);
        }
      }
    })();
    return () => {
      cancelled = true;
    };
  }, [notify]);

  const activeCampaign =
    vault?.campaigns?.find((c) => c.id === vault.activeCampaignId) ||
    vault?.campaigns?.[0] ||
    null;

  // Debounced auto-save whenever dirty activeCampaign changes
  useEffect(() => {
    if (!dirtyRef.current || !activeCampaign) return;
    setSaveState('saving');
    if (saveTimerRef.current) clearTimeout(saveTimerRef.current);

    saveTimerRef.current = setTimeout(async () => {
      try {
        const res = await fetch('/api/campaigns', {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify({ action: 'save', campaign: activeCampaign }),
        });
        if (!res.ok) throw new Error(`HTTP ${res.status}`);
        dirtyRef.current = false;
        setSaveState('saved');
      } catch (err) {
        setSaveState('error');
        notify(`Auto-save failed: ${err.message}`);
      }
    }, 500);

    return () => {
      if (saveTimerRef.current) clearTimeout(saveTimerRef.current);
    };
  }, [activeCampaign, notify]);

  // Global keyboard shortcuts (Ctrl+K / Cmd+K for Quick Roll, Esc to close modals)
  useEffect(() => {
    const onKeyDown = (e) => {
      if ((e.ctrlKey || e.metaKey) && e.key.toLowerCase() === 'k') {
        e.preventDefault();
        setQuickRollOpen((v) => !v);
      } else if (e.key === 'Escape') {
        setQuickRollOpen(false);
        setPreviewHandout(null);
        setPinnedResult(null);
        setNewCampModalOpen(false);
        setSettingsModalOpen(false);
      }
    };
    window.addEventListener('keydown', onKeyDown);
    return () => window.removeEventListener('keydown', onKeyDown);
  }, []);

  const mutateActiveCampaign = useCallback((updater) => {
    dirtyRef.current = true;
    setVault((prev) => {
      if (!prev) return prev;
      const nextCampaigns = prev.campaigns.map((camp) => {
        if (camp.id !== prev.activeCampaignId) return camp;
        const patch = typeof updater === 'function' ? updater(camp) : updater;
        return { ...camp, ...patch, updatedAt: new Date().toISOString() };
      });
      return { ...prev, campaigns: nextCampaigns };
    });
  }, []);

  // Cross-panel integration handlers
  const handleSaveCodex = (entry) => {
    mutateActiveCampaign((camp) => ({
      codex: [
        {
          id: `codex_${Date.now()}`,
          createdAt: new Date().toISOString(),
          ...entry,
        },
        ...(camp.codex || []),
      ],
    }));
    notify(`Saved "${entry.title}" to Campaign Codex`);
  };

  const handleSendToCombat = (incoming) => {
    const stamped = incoming.map((c, idx) => {
      const initBonus = Number(c.initBonus) || 0;
      const roll = Math.floor(Math.random() * 20) + 1 + initBonus;
      return {
        id: `cmb_${Date.now()}_${idx}`,
        side: c.side || 'enemy',
        ac: Number(c.ac) || 12,
        maxHp: Number(c.maxHp) || 10,
        hp: Number(c.hp ?? c.maxHp) || 10,
        tempHp: Number(c.tempHp) || 0,
        initBonus,
        initiative: c.initiative ?? roll,
        conditions: Array.isArray(c.conditions) ? c.conditions : [],
        ...c,
      };
    });

    mutateActiveCampaign((camp) => {
      const existing = camp.combat?.combatants || [];
      const merged = [...existing, ...stamped].sort((a, b) => (b.initiative || 0) - (a.initiative || 0));
      return {
        combat: {
          round: camp.combat?.round || 1,
          turnIndex: camp.combat?.turnIndex || 0,
          combatants: merged,
        },
      };
    });
    notify(`Added ${stamped.length} combatant(s) to Initiative Tracker`);
  };

  const handleAppendSessionNote = (markdownLine) => {
    mutateActiveCampaign((camp) => {
      const notes = Array.isArray(camp.sessionNotes) ? [...camp.sessionNotes] : [];
      if (notes.length === 0) {
        const today = new Date().toISOString().slice(0, 10);
        notes.push({
          id: `sess_${Date.now()}`,
          title: 'Session 1 — Chronicle',
          date: today,
          content: `# Session 1 (${today})\n\n${markdownLine}\n`,
        });
      } else {
        const latest = notes[0];
        const glue = latest.content && !latest.content.endsWith('\n') ? '\n' : '';
        notes[0] = { ...latest, content: `${latest.content || ''}${glue}${markdownLine}\n` };
      }
      return { sessionNotes: notes };
    });
    notify('Appended entry to active Session Journal');
  };

  const handleRevealHandout = (payload) => {
    const packet = broadcastPlayerHandout(payload);
    setPreviewHandout(packet);
    notify(`Sent spoiler-free handout "${payload.title}" to /handout`);
  };

  const handleTogglePin = (genId) => {
    mutateActiveCampaign((camp) => {
      const cur = Array.isArray(camp.pinnedGenerators) ? camp.pinnedGenerators : [];
      const exists = cur.includes(genId);
      const next = exists ? cur.filter((id) => id !== genId) : [...cur, genId];
      notify(exists ? `Unpinned ${genId}` : `Pinned ${genId} to quick-roll bar`);
      return { pinnedGenerators: next };
    });
  };

  const rollPinned = async (genId) => {
    try {
      const res = await fetch('/api/namgen', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          action: 'roll',
          generator: genId,
          count: 6,
          unique: true,
          capitalize: true,
        }),
      });
      const data = await res.json();
      setPinnedResult({
        genId,
        label: getGenerator(genId)?.name || genId,
        names: data.names || [],
      });
    } catch (err) {
      notify(`Quick roll failed: ${err.message}`);
    }
  };

  // Campaign Vault switching / creation
  const switchCampaign = async (campaignId) => {
    try {
      dirtyRef.current = false;
      const res = await fetch('/api/campaigns', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ action: 'switch', campaignId }),
      });
      const data = await res.json();
      if (data.vault) {
        setVault(data.vault);
        setSaveState('saved');
        notify('Switched campaign vault');
      }
    } catch (err) {
      notify(`Switch failed: ${err.message}`);
    }
  };

  const createCampaign = async (e) => {
    e.preventDefault();
    if (!newCampName.trim()) return;
    try {
      dirtyRef.current = false;
      const res = await fetch('/api/campaigns', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          action: 'create',
          name: newCampName.trim(),
          setting: newCampSetting.trim(),
          partyLevelTier: Number(newCampTier) || 1,
        }),
      });
      const data = await res.json();
      if (data.vault) {
        setVault(data.vault);
        setNewCampName('');
        setNewCampModalOpen(false);
        setSaveState('saved');
        notify('Created new local campaign');
      }
    } catch (err) {
      notify(`Create failed: ${err.message}`);
    }
  };

  const deleteActiveCampaign = async () => {
    if (!activeCampaign || !vault || vault.campaigns.length <= 1) return;
    try {
      dirtyRef.current = false;
      const res = await fetch('/api/campaigns', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ action: 'delete', campaignId: activeCampaign.id }),
      });
      const data = await res.json();
      if (data.vault) {
        setVault(data.vault);
        setSaveState('saved');
        notify(`Deleted campaign "${activeCampaign.name}"`);
      }
    } catch (err) {
      notify(`Delete failed: ${err.message}`);
    }
  };

  if (!activeCampaign) {
    return (
      <main className="min-h-screen flex items-center justify-center text-slate-300 font-mono text-sm">
        Loading Local DM Command Center Vault...
      </main>
    );
  }

  const combatCount = activeCampaign.combat?.combatants?.length || 0;
  const codexCount = activeCampaign.codex?.length || 0;

  return (
    <div className="min-h-screen flex flex-col">
      {/* Top Command Header */}
      <header className="sticky top-0 z-30 bg-slate-950/90 backdrop-blur-md border-b border-slate-800 no-print">
        <div className="max-w-[1440px] mx-auto px-4 py-2.5 flex flex-wrap items-center justify-between gap-3">
          {/* Brand, Launchpad Workspace Switcher & Campaign Switcher */}
          <div className="flex flex-wrap items-center gap-3">
            <div className="flex items-center gap-2">
              <span className="w-8 h-8 rounded-xl bg-gradient-to-br from-emerald-500 to-amber-500 flex items-center justify-center text-slate-950 font-black text-sm">
                {workspace === 'oracle' ? '🔮' : workspace === 'storyteller' ? '✨' : '🐉'}
              </span>
              <div>
                <div className="text-sm font-extrabold text-white leading-none">
                  namgen{' '}
                  <span
                    className={
                      workspace === 'oracle'
                        ? 'text-cyan-400'
                        : workspace === 'storyteller'
                        ? 'text-fuchsia-400'
                        : 'text-amber-400'
                    }
                  >
                    {workspace === 'oracle'
                      ? 'Namespace Oracle'
                      : workspace === 'storyteller'
                      ? 'AI Storyteller'
                      : 'DM Vault'}
                  </span>
                </div>
                <div className="text-[10px] font-mono text-slate-400 mt-0.5">
                  {allGenerators.length} Engines • C++17 + Local Ollama
                </div>
              </div>
            </div>

            {/* Unified Multi-Workspace Switcher */}
            <div className="flex items-center gap-1 p-1 rounded-xl bg-slate-900 border border-slate-800">
              {[
                { id: 'dm', label: 'DM Vault', icon: '🐉', activeCls: 'bg-amber-500/20 text-amber-200 border-amber-500/40' },
                { id: 'storyteller', label: 'AI Storyteller', icon: '✨', activeCls: 'bg-fuchsia-500/20 text-fuchsia-200 border-fuchsia-500/40' },
                { id: 'oracle', label: 'Namespace Oracle', icon: '🔮', activeCls: 'bg-cyan-500/20 text-cyan-200 border-cyan-500/40' },
              ].map((ws) => (
                <button
                  key={ws.id}
                  type="button"
                  onClick={() => switchWorkspace(ws.id)}
                  className={`px-2.5 py-1 rounded-lg text-xs font-bold border transition-colors flex items-center gap-1.5 ${
                    workspace === ws.id
                      ? ws.activeCls
                      : 'border-transparent text-slate-400 hover:text-white hover:bg-slate-800/60'
                  }`}
                >
                  <span>{ws.icon}</span>
                  <span>{ws.label}</span>
                </button>
              ))}
            </div>

            <div className="flex items-center gap-1.5 pl-2 border-l border-slate-800">
              <select
                value={activeCampaign.id}
                onChange={(e) => switchCampaign(e.target.value)}
                className="bg-slate-900 border border-slate-700 rounded-lg px-2.5 py-1.5 text-xs font-semibold text-white max-w-[200px]"
              >
                {vault.campaigns.map((camp) => (
                  <option key={camp.id} value={camp.id}>
                    {camp.name} (Tier {camp.partyLevelTier || 1})
                  </option>
                ))}
              </select>
              <button
                type="button"
                onClick={() => setNewCampModalOpen(true)}
                className="px-2.5 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 text-xs font-semibold text-emerald-300"
                title="Create new local campaign"
              >
                + Campaign
              </button>
              {vault.campaigns.length > 1 && (
                <button
                  type="button"
                  onClick={deleteActiveCampaign}
                  className="px-2 py-1.5 rounded-lg bg-slate-900 hover:bg-rose-950/60 border border-slate-800 text-xs text-rose-400"
                  title="Delete current campaign"
                >
                  ✕
                </button>
              )}
            </div>
          </div>

          {/* Global DM Utilities */}
          <div className="flex flex-wrap items-center gap-2">
            {cppEngine?.available && (
              <span
                className="px-2 py-1 rounded-full text-[11px] font-mono border border-emerald-500/40 bg-emerald-500/15 text-emerald-300"
                title={cppEngine.binaryPath || 'Native C++17 engine enabled'}
              >
                ⚡ C++17
              </span>
            )}

            <button
              type="button"
              onClick={() => setSettingsModalOpen(true)}
              className="px-2.5 py-1.5 rounded-lg bg-slate-900 hover:bg-slate-800 border border-cyan-500/35 text-xs font-semibold text-cyan-200 flex items-center gap-1.5"
              title="Configure Ollama URL, model, GitHub PAT, and USPTO bulk CSV"
            >
              <span>⚙️ AI & Oracle</span>
              <span className="px-1.5 py-0.5 rounded bg-slate-950 text-[10px] font-mono text-slate-300 max-w-[110px] truncate">
                {settings?.model || 'Configure AI'}
              </span>
            </button>

            <span
              className={`px-2.5 py-1 rounded-full text-[11px] font-mono border ${
                saveState === 'saving'
                  ? 'bg-amber-500/15 border-amber-500/40 text-amber-300'
                  : saveState === 'error'
                  ? 'bg-rose-500/15 border-rose-500/40 text-rose-300'
                  : 'bg-emerald-500/15 border-emerald-500/40 text-emerald-300'
              }`}
            >
              {saveState === 'saving'
                ? '● Saving...'
                : saveState === 'error'
                ? '▲ Save Error'
                : '✓ Saved'}
            </span>

            <button
              type="button"
              onClick={() => setQuickRollOpen(true)}
              className="px-3 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 border border-slate-700 text-xs font-semibold text-slate-100 flex items-center gap-1.5"
            >
              <span>⚡ Quick Roll</span>
              <kbd className="px-1.5 py-0.5 rounded bg-slate-950 text-[10px] font-mono text-amber-300">
                Ctrl+K
              </kbd>
            </button>

            <a
              href="/handout"
              target="_blank"
              rel="noreferrer"
              className="px-3 py-1.5 rounded-lg bg-amber-500/20 hover:bg-amber-500/30 border border-amber-500/40 text-xs font-bold text-amber-300"
            >
              📺 Player Screen ↗
            </a>

            <button
              type="button"
              onClick={() => window.print()}
              className="px-2.5 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 text-xs text-slate-300"
              title="Print current DM view"
            >
              🖨 Print
            </button>
          </div>
        </div>

        {/* DM Vault Pinned Quick-Roll Bar & Navigation Tabs */}
        {workspace === 'dm' && (
          <>
            <div className="bg-slate-900/70 border-t border-slate-800/80">
              <div className="max-w-[1440px] mx-auto px-4 py-1.5 flex flex-wrap items-center gap-1.5 text-xs">
                <span className="text-[10px] font-mono uppercase text-slate-500 mr-1">
                  Pinned Rolls:
                </span>
                {(activeCampaign.pinnedGenerators || []).map((genId) => {
                  const meta = getGenerator(genId);
                  return (
                    <button
                      key={genId}
                      type="button"
                      onClick={() => rollPinned(genId)}
                      className={`px-2 py-0.5 rounded-lg border text-[11px] transition-colors ${
                        pinnedResult?.genId === genId
                          ? 'bg-amber-500/20 border-amber-500/60 text-amber-200 font-semibold'
                          : 'bg-slate-950 border-slate-800 text-slate-300 hover:border-emerald-500/50 hover:text-emerald-200'
                      }`}
                    >
                      🎲 {meta?.name || genId}
                    </button>
                  );
                })}
              </div>
            </div>

            <nav className="max-w-[1440px] mx-auto px-4 pt-2 flex gap-1 overflow-x-auto">
              {TABS.map((tab) => {
                const active = activeTab === tab.id;
                return (
                  <button
                    key={tab.id}
                    type="button"
                    onClick={() => setActiveTab(tab.id)}
                    className={`px-3.5 py-2 rounded-t-xl text-xs font-bold whitespace-nowrap flex items-center gap-1.5 border-t border-x transition-colors ${
                      active
                        ? 'bg-slate-900 border-slate-800 text-amber-300'
                        : 'bg-transparent border-transparent text-slate-400 hover:text-white'
                    }`}
                  >
                    <span>{tab.icon}</span>
                    <span>{tab.label}</span>
                    {tab.id === 'combat' && combatCount > 0 && (
                      <span className="px-1.5 py-0.2 rounded-full bg-rose-500/25 text-rose-200 font-mono text-[10px]">
                        {combatCount}
                      </span>
                    )}
                    {tab.id === 'codex' && (
                      <span className="px-1.5 py-0.2 rounded-full bg-slate-800 text-slate-300 font-mono text-[10px]">
                        {codexCount}
                      </span>
                    )}
                  </button>
                );
              })}
            </nav>
          </>
        )}
      </header>

      {/* Pinned Roll Popover Strip */}
      {workspace === 'dm' && pinnedResult && (
        <div className="max-w-[1440px] w-full mx-auto px-4 pt-3 no-print">
          <div className="bg-slate-900 border border-amber-500/40 rounded-2xl p-3 flex flex-wrap items-center justify-between gap-2 shadow-xl">
            <div className="flex flex-wrap items-center gap-2">
              <span className="text-xs font-bold text-amber-300">{pinnedResult.label}:</span>
              {pinnedResult.names.map((nm, i) => (
                <button
                  key={i}
                  type="button"
                  onClick={() => {
                    if (typeof navigator !== 'undefined' && navigator.clipboard) {
                      navigator.clipboard.writeText(nm);
                    }
                    notify(`Copied: ${nm}`);
                  }}
                  className="px-2.5 py-1 rounded-lg bg-slate-950 hover:bg-slate-800 border border-slate-700 text-xs text-slate-100"
                >
                  {nm}
                </button>
              ))}
            </div>
            <div className="flex items-center gap-1.5">
              <button
                type="button"
                onClick={() => rollPinned(pinnedResult.genId)}
                className="px-2.5 py-1 rounded-lg bg-emerald-500 text-slate-950 text-xs font-bold"
              >
                🎲 Reroll
              </button>
              <button
                type="button"
                onClick={() => setPinnedResult(null)}
                className="px-2 py-1 text-slate-400 hover:text-white text-xs"
              >
                ✕
              </button>
            </div>
          </div>
        </div>
      )}

      {/* Active Panel */}
      <main className="flex-1 max-w-[1440px] w-full mx-auto p-4 pb-20">
        {workspace === 'dm' && (
          <>
            {activeTab === 'npc' && (
              <NpcForgePanel
                onSaveCodex={handleSaveCodex}
                onSendToCombat={handleSendToCombat}
                onAppendSessionNote={handleAppendSessionNote}
                onRevealHandout={handleRevealHandout}
                onWeaveWithAi={handleWeaveWithAi}
                onNotify={notify}
              />
            )}

            {activeTab === 'combat' && (
              <CombatTrackerPanel
                party={activeCampaign.party || []}
                combat={activeCampaign.combat || { round: 1, turnIndex: 0, combatants: [] }}
                onUpdateParty={(party) => mutateActiveCampaign({ party })}
                onUpdateCombat={(combat) => mutateActiveCampaign({ combat })}
                onRevealHandout={handleRevealHandout}
                onWeaveWithAi={handleWeaveWithAi}
                onNotify={notify}
              />
            )}

            {activeTab === 'shops' && (
              <EstablishmentsPanel
                onSaveCodex={handleSaveCodex}
                onAppendSessionNote={handleAppendSessionNote}
                onRevealHandout={handleRevealHandout}
                onWeaveWithAi={handleWeaveWithAi}
                onNotify={notify}
              />
            )}

            {activeTab === 'adventure' && (
              <AdventureForgePanel
                partyTier={activeCampaign.partyLevelTier || 1}
                onChangeTier={(tier) => mutateActiveCampaign({ partyLevelTier: tier })}
                onSaveCodex={handleSaveCodex}
                onSendToCombat={handleSendToCombat}
                onRevealHandout={handleRevealHandout}
                onWeaveWithAi={handleWeaveWithAi}
                onNotify={notify}
              />
            )}

            {activeTab === 'world' && (
              <WorldMatrixPanel
                onSaveCodex={handleSaveCodex}
                onWeaveWithAi={handleWeaveWithAi}
                onNotify={notify}
              />
            )}

            {activeTab === 'codex' && (
              <CampaignCodexPanel
                campaign={activeCampaign}
                storageInfo={storageInfo}
                onUpdateCodex={(codex) => mutateActiveCampaign({ codex })}
                onUpdateSessionNotes={(sessionNotes) => mutateActiveCampaign({ sessionNotes })}
                onRevealHandout={handleRevealHandout}
                onWeaveWithAi={handleWeaveWithAi}
                onNotify={notify}
              />
            )}

            {activeTab === 'studio' && (
              <GeneratorStudioPanel
                pinnedGenerators={activeCampaign.pinnedGenerators || []}
                onTogglePin={handleTogglePin}
                onSaveCodex={handleSaveCodex}
                onNotify={notify}
              />
            )}
          </>
        )}

        {workspace === 'storyteller' && (
          <AiStorytellerWorkspace
            settings={settings}
            handoffContext={handoffContext}
            onClearHandoff={() => setHandoffContext(null)}
            onOpenSettings={() => setSettingsModalOpen(true)}
            onSaveCodex={handleSaveCodex}
            onAppendSessionNote={handleAppendSessionNote}
            onRevealHandout={handleRevealHandout}
            onSendToCombat={handleSendToCombat}
            onNotify={notify}
          />
        )}

        {workspace === 'oracle' && (
          <NamespaceOracleWorkspace
            settings={settings}
            cppEngine={cppEngine}
            onOpenSettings={() => setSettingsModalOpen(true)}
            onSaveCodex={handleSaveCodex}
            onNotify={notify}
          />
        )}
      </main>

      {/* New Campaign Modal */}
      {newCampModalOpen && (
        <div
          className="fixed inset-0 z-50 flex items-center justify-center p-4 bg-slate-950/80 backdrop-blur-sm no-print"
          onClick={() => setNewCampModalOpen(false)}
        >
          <form
            onSubmit={createCampaign}
            onClick={(e) => e.stopPropagation()}
            className="w-full max-w-md bg-slate-900 border border-slate-700 rounded-2xl p-5 space-y-4 shadow-2xl"
          >
            <h3 className="text-base font-bold text-white">Create Local Campaign Vault</h3>
            <div className="space-y-3 text-xs">
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">
                  Campaign Title
                </label>
                <input
                  type="text"
                  required
                  value={newCampName}
                  onChange={(e) => setNewCampName(e.target.value)}
                  placeholder="e.g. Curse of the Obsidian Crown"
                  className="w-full bg-slate-950 border border-slate-800 rounded-xl px-3 py-2 text-white"
                />
              </div>
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">
                  Setting / Realm
                </label>
                <input
                  type="text"
                  value={newCampSetting}
                  onChange={(e) => setNewCampSetting(e.target.value)}
                  className="w-full bg-slate-950 border border-slate-800 rounded-xl px-3 py-2 text-white"
                />
              </div>
              <div>
                <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">
                  Starting Party Tier
                </label>
                <select
                  value={newCampTier}
                  onChange={(e) => setNewCampTier(Number(e.target.value))}
                  className="w-full bg-slate-950 border border-slate-800 rounded-xl px-3 py-2 text-white"
                >
                  <option value={1}>Tier 1 (Levels 1–4)</option>
                  <option value={2}>Tier 2 (Levels 5–10)</option>
                  <option value={3}>Tier 3 (Levels 11–16)</option>
                  <option value={4}>Tier 4 (Levels 17–20)</option>
                </select>
              </div>
            </div>
            <div className="flex justify-end gap-2">
              <button
                type="button"
                onClick={() => setNewCampModalOpen(false)}
                className="px-3 py-1.5 rounded-lg bg-slate-800 text-xs text-slate-300"
              >
                Cancel
              </button>
              <button
                type="submit"
                className="px-4 py-1.5 rounded-lg bg-emerald-500 hover:bg-emerald-400 text-slate-950 text-xs font-bold"
              >
                Create Vault
              </button>
            </div>
          </form>
        </div>
      )}

      {/* Floating Utilities */}
      <QuickRollModal
        isOpen={quickRollOpen}
        onClose={() => setQuickRollOpen(false)}
        pinnedGenerators={activeCampaign.pinnedGenerators || []}
        onTogglePin={handleTogglePin}
        onNotify={notify}
      />

      <GlobalSettingsModal
        isOpen={settingsModalOpen}
        onClose={() => setSettingsModalOpen(false)}
        initialSettings={settings}
        cppEngine={cppEngine}
        onSaved={(nextSettings, nextCpp) => {
          setSettings(nextSettings);
          if (nextCpp) setCppEngine(nextCpp);
        }}
        onNotify={notify}
      />

      <HandoutPreviewModal
        handout={previewHandout}
        onClose={() => setPreviewHandout(null)}
      />

      <DiceRollerDrawer
        isOpen={diceOpen}
        onToggle={() => setDiceOpen((v) => !v)}
      />

      {/* Floating Toast */}
      {toast && (
        <div className="fixed bottom-4 left-4 z-50 px-4 py-2.5 rounded-xl bg-slate-900 border border-emerald-500/50 text-xs font-semibold text-emerald-200 shadow-2xl no-print">
          {toast}
        </div>
      )}
    </div>
  );
}
