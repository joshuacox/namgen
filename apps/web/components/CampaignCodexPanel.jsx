'use client';

import React, { useState, useMemo } from 'react';

const CODEX_KINDS = [
  { id: 'all', label: 'All Entries' },
  { id: 'npc', label: 'NPCs' },
  { id: 'place', label: 'Places & Shops' },
  { id: 'dungeon', label: 'Dungeons' },
  { id: 'faction', label: 'Factions' },
  { id: 'item', label: 'Relics & Items' },
  { id: 'encounter', label: 'Encounters' },
];

const STATUS_OPTIONS = ['Met', 'Ally', 'Rival', 'Visited', 'Rumored', 'Active', 'Alive', 'Dead'];

export default function CampaignCodexPanel({
  campaign,
  storageInfo,
  onUpdateCodex,
  onUpdateSessionNotes,
  onRevealHandout,
  onNotify,
}) {
  const [subView, setSubView] = useState('codex');
  const [search, setSearch] = useState('');
  const [kindFilter, setKindFilter] = useState('all');

  const codex = Array.isArray(campaign?.codex) ? campaign.codex : [];
  const sessionNotes = Array.isArray(campaign?.sessionNotes) ? campaign.sessionNotes : [];

  const [selectedCodexId, setSelectedCodexId] = useState(codex[0]?.id || null);
  const [selectedSessionId, setSelectedSessionId] = useState(sessionNotes[0]?.id || null);

  const filteredCodex = useMemo(() => {
    const q = search.trim().toLowerCase();
    return codex.filter((entry) => {
      if (kindFilter !== 'all' && entry.kind !== kindFilter) return false;
      if (!q) return true;
      const hay = `${entry.title} ${entry.subtitle} ${entry.summary} ${entry.dmNotes} ${(entry.tags || []).join(' ')}`.toLowerCase();
      return hay.includes(q);
    });
  }, [codex, search, kindFilter]);

  const activeEntry =
    codex.find((e) => e.id === selectedCodexId) || filteredCodex[0] || null;

  const activeSession =
    sessionNotes.find((s) => s.id === selectedSessionId) || sessionNotes[0] || null;

  const createCodexEntry = () => {
    const newEntry = {
      id: `codex_${Date.now()}`,
      kind: kindFilter === 'all' ? 'npc' : kindFilter,
      title: 'Untitled Lore Entry',
      subtitle: 'Custom campaign record',
      status: 'Active',
      tags: ['custom'],
      summary: '',
      dmNotes: '',
      data: null,
      createdAt: new Date().toISOString(),
    };
    onUpdateCodex?.([newEntry, ...codex]);
    setSelectedCodexId(newEntry.id);
    onNotify?.('Added new entry to Campaign Codex');
  };

  const updateCodexField = (id, field, value) => {
    onUpdateCodex?.(
      codex.map((entry) => (entry.id === id ? { ...entry, [field]: value } : entry))
    );
  };

  const deleteCodexEntry = (id) => {
    const next = codex.filter((e) => e.id !== id);
    onUpdateCodex?.(next);
    if (selectedCodexId === id) {
      setSelectedCodexId(next[0]?.id || null);
    }
    onNotify?.('Removed entry from Codex');
  };

  // Session Journal handlers
  const createSessionNote = () => {
    const num = sessionNotes.length + 1;
    const today = new Date().toISOString().slice(0, 10);
    const nextNote = {
      id: `sess_${Date.now()}`,
      title: `Session ${num} — Untitled Chronicle`,
      date: today,
      content: `# Session ${num}: Untitled Chronicle (${today})\n\n## Strong Start\n- \n\n## Key Scenes & Encounters\n- \n\n## Clues, Secrets & Loose Ends\n- \n`,
    };
    onUpdateSessionNotes?.([nextNote, ...sessionNotes]);
    setSelectedSessionId(nextNote.id);
    onNotify?.(`Created Session ${num} journal page`);
  };

  const updateSessionField = (id, field, value) => {
    onUpdateSessionNotes?.(
      sessionNotes.map((s) => (s.id === id ? { ...s, [field]: value } : s))
    );
  };

  const deleteSessionNote = (id) => {
    const next = sessionNotes.filter((s) => s.id !== id);
    onUpdateSessionNotes?.(next);
    if (selectedSessionId === id) {
      setSelectedSessionId(next[0]?.id || null);
    }
    onNotify?.('Deleted session log');
  };

  const insertIntoActiveSession = (snippet) => {
    if (!activeSession) return;
    const current = activeSession.content || '';
    const glue = current && !current.endsWith('\n') ? '\n' : '';
    updateSessionField(activeSession.id, 'content', `${current}${glue}${snippet}`);
  };

  return (
    <div className="space-y-5">
      {/* Local Disk Vault Status Banner */}
      <section className="bg-slate-900/90 border border-emerald-500/30 rounded-2xl p-4 flex flex-wrap items-center justify-between gap-3">
        <div className="space-y-1 text-xs">
          <div className="flex items-center gap-2 font-bold text-emerald-300">
            <span>💾</span>
            <span>Local Private Disk Vault (Auto-Synced Offline)</span>
          </div>
          <div className="font-mono text-[11px] text-slate-400 break-all">
            JSON Vault: <span className="text-slate-200">{storageInfo?.vaultFile || 'apps/web/.namgen-dm/vault.json'}</span>
            {' • '}
            Markdown Mirror: <span className="text-slate-200">{storageInfo?.markdownDir || 'apps/web/.namgen-dm/markdown'}</span>
          </div>
        </div>

        <div className="flex flex-wrap items-center gap-2">
          <a
            href={`/api/campaigns/${campaign.id}/export?format=md`}
            className="px-3 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 border border-slate-700 text-xs font-semibold text-amber-300"
          >
            ⬇ Export .md
          </a>
          <a
            href={`/api/campaigns/${campaign.id}/export?format=json`}
            className="px-3 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 border border-slate-700 text-xs font-semibold text-emerald-300"
          >
            ⬇ Export .json
          </a>
        </div>
      </section>

      {/* Sub-view Switcher */}
      <div className="flex items-center gap-2">
        <button
          type="button"
          onClick={() => setSubView('codex')}
          className={`px-4 py-2 rounded-xl text-xs font-bold border ${
            subView === 'codex'
              ? 'bg-amber-500/20 border-amber-500/60 text-amber-200'
              : 'bg-slate-900 border-slate-800 text-slate-400 hover:text-white'
          }`}
        >
          📚 Campaign Codex ({codex.length})
        </button>
        <button
          type="button"
          onClick={() => setSubView('journal')}
          className={`px-4 py-2 rounded-xl text-xs font-bold border ${
            subView === 'journal'
              ? 'bg-emerald-500/20 border-emerald-500/60 text-emerald-200'
              : 'bg-slate-900 border-slate-800 text-slate-400 hover:text-white'
          }`}
        >
          📓 Markdown Session Journal ({sessionNotes.length})
        </button>
      </div>

      {/* Sub-view 1: Codex Lorebook */}
      {subView === 'codex' && (
        <div className="grid grid-cols-1 xl:grid-cols-12 gap-5">
          {/* Left List */}
          <section className="xl:col-span-4 bg-slate-900/80 border border-slate-800 rounded-2xl p-4 space-y-3">
            <div className="flex items-center gap-2">
              <input
                type="text"
                value={search}
                onChange={(e) => setSearch(e.target.value)}
                placeholder="Search NPCs, shops, relics..."
                className="flex-1 bg-slate-950 border border-slate-800 rounded-xl px-3 py-1.5 text-xs text-slate-100 placeholder-slate-600"
              />
              <button
                type="button"
                onClick={createCodexEntry}
                className="px-3 py-1.5 rounded-xl bg-emerald-500 hover:bg-emerald-400 text-slate-950 text-xs font-bold whitespace-nowrap"
              >
                + New
              </button>
            </div>

            <div className="flex flex-wrap gap-1">
              {CODEX_KINDS.map((k) => (
                <button
                  key={k.id}
                  type="button"
                  onClick={() => setKindFilter(k.id)}
                  className={`px-2 py-0.5 rounded text-[11px] border ${
                    kindFilter === k.id
                      ? 'bg-amber-500/20 border-amber-500/50 text-amber-200'
                      : 'bg-slate-950 border-slate-800 text-slate-400 hover:text-white'
                  }`}
                >
                  {k.label}
                </button>
              ))}
            </div>

            <div className="space-y-1.5 max-h-[520px] overflow-y-auto pr-1">
              {filteredCodex.length === 0 ? (
                <div className="text-center py-8 text-xs text-slate-500">
                  No matching Codex entries. Save NPCs, shops, dungeons, or relics from the tabs above!
                </div>
              ) : (
                filteredCodex.map((entry) => {
                  const selected = activeEntry?.id === entry.id;
                  return (
                    <button
                      key={entry.id}
                      type="button"
                      onClick={() => setSelectedCodexId(entry.id)}
                      className={`w-full text-left p-2.5 rounded-xl border transition-colors ${
                        selected
                          ? 'bg-slate-950 border-amber-500/60'
                          : 'bg-slate-950/60 border-slate-800 hover:border-slate-700'
                      }`}
                    >
                      <div className="flex items-center justify-between gap-2">
                        <span className="font-bold text-xs text-white truncate">{entry.title}</span>
                        <span className="text-[10px] font-mono px-1.5 py-0.5 rounded bg-slate-900 border border-slate-700 text-amber-300 shrink-0">
                          {entry.status || entry.kind}
                        </span>
                      </div>
                      <div className="text-[11px] text-slate-400 truncate mt-0.5">{entry.subtitle}</div>
                    </button>
                  );
                })
              )}
            </div>
          </section>

          {/* Right Editor */}
          <section className="xl:col-span-8 bg-slate-900/80 border border-slate-800 rounded-2xl p-5">
            {!activeEntry ? (
              <div className="text-center py-16 text-sm text-slate-500">
                Select a Codex entry on the left or click <strong>+ New</strong> to create one.
              </div>
            ) : (
              <div className="space-y-4">
                <div className="flex flex-wrap items-center justify-between gap-2 pb-3 border-b border-slate-800">
                  <div className="flex-1 min-w-[220px]">
                    <input
                      type="text"
                      value={activeEntry.title}
                      onChange={(e) => updateCodexField(activeEntry.id, 'title', e.target.value)}
                      className="w-full bg-transparent text-xl font-extrabold text-white border-b border-transparent focus:border-amber-500 focus:outline-none pb-0.5"
                    />
                    <input
                      type="text"
                      value={activeEntry.subtitle || ''}
                      onChange={(e) => updateCodexField(activeEntry.id, 'subtitle', e.target.value)}
                      placeholder="Subtitle or role..."
                      className="w-full bg-transparent text-xs text-slate-400 mt-1 border-b border-transparent focus:border-slate-700 focus:outline-none"
                    />
                  </div>

                  <div className="flex flex-wrap items-center gap-2">
                    <button
                      type="button"
                      onClick={() =>
                        onRevealHandout?.({
                          kind: activeEntry.kind,
                          title: activeEntry.title,
                          subtitle: activeEntry.subtitle || activeEntry.status,
                          body: activeEntry.summary || 'No public details recorded.',
                        })
                      }
                      className="px-3 py-1.5 rounded-lg bg-amber-500/20 hover:bg-amber-500/30 border border-amber-500/40 text-xs font-semibold text-amber-300"
                    >
                      📺 Reveal Summary to Players
                    </button>
                    <button
                      type="button"
                      onClick={() => deleteCodexEntry(activeEntry.id)}
                      className="px-3 py-1.5 rounded-lg bg-rose-500/20 hover:bg-rose-500/30 border border-rose-500/40 text-xs text-rose-300"
                    >
                      Delete
                    </button>
                  </div>
                </div>

                <div className="grid grid-cols-1 sm:grid-cols-3 gap-3 text-xs">
                  <div>
                    <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Category</label>
                    <select
                      value={activeEntry.kind || 'npc'}
                      onChange={(e) => updateCodexField(activeEntry.id, 'kind', e.target.value)}
                      className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-slate-100"
                    >
                      {CODEX_KINDS.filter((k) => k.id !== 'all').map((k) => (
                        <option key={k.id} value={k.id}>
                          {k.label}
                        </option>
                      ))}
                    </select>
                  </div>

                  <div>
                    <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">Status</label>
                    <select
                      value={activeEntry.status || 'Active'}
                      onChange={(e) => updateCodexField(activeEntry.id, 'status', e.target.value)}
                      className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-slate-100"
                    >
                      {STATUS_OPTIONS.map((st) => (
                        <option key={st} value={st}>
                          {st}
                        </option>
                      ))}
                    </select>
                  </div>

                  <div>
                    <label className="block text-[10px] font-mono uppercase text-slate-400 mb-1">
                      Tags (comma separated)
                    </label>
                    <input
                      type="text"
                      value={(activeEntry.tags || []).join(', ')}
                      onChange={(e) =>
                        updateCodexField(
                          activeEntry.id,
                          'tags',
                          e.target.value
                            .split(',')
                            .map((t) => t.trim())
                            .filter(Boolean)
                        )
                      }
                      className="w-full bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-slate-200"
                    />
                  </div>
                </div>

                <div className="space-y-1 text-xs">
                  <label className="block text-[10px] font-mono uppercase text-emerald-400">
                    Public / Player-Safe Summary
                  </label>
                  <textarea
                    rows={4}
                    value={activeEntry.summary || ''}
                    onChange={(e) => updateCodexField(activeEntry.id, 'summary', e.target.value)}
                    placeholder="What the party knows or observed..."
                    className="w-full bg-slate-950 border border-slate-800 rounded-xl p-3 text-slate-200 focus:outline-none focus:border-emerald-500"
                  />
                </div>

                <div className="space-y-1 text-xs">
                  <label className="block text-[10px] font-mono uppercase text-rose-400">
                    DM-Only Secrets, Stats &amp; Prep Notes
                  </label>
                  <textarea
                    rows={5}
                    value={activeEntry.dmNotes || ''}
                    onChange={(e) => updateCodexField(activeEntry.id, 'dmNotes', e.target.value)}
                    placeholder="Hidden motives, DC thresholds, conspiracies, stats..."
                    className="w-full bg-rose-950/15 border border-rose-500/30 rounded-xl p-3 text-rose-100 focus:outline-none focus:border-rose-400"
                  />
                </div>
              </div>
            )}
          </section>
        </div>
      )}

      {/* Sub-view 2: Markdown Session Journal */}
      {subView === 'journal' && (
        <div className="grid grid-cols-1 xl:grid-cols-12 gap-5">
          <section className="xl:col-span-4 bg-slate-900/80 border border-slate-800 rounded-2xl p-4 space-y-3">
            <div className="flex items-center justify-between">
              <h3 className="text-sm font-bold text-white">Session Pages</h3>
              <button
                type="button"
                onClick={createSessionNote}
                className="px-3 py-1.5 rounded-xl bg-emerald-500 hover:bg-emerald-400 text-slate-950 text-xs font-bold"
              >
                + New Session
              </button>
            </div>

            <div className="space-y-1.5 max-h-[520px] overflow-y-auto">
              {sessionNotes.map((s) => (
                <button
                  key={s.id}
                  type="button"
                  onClick={() => setSelectedSessionId(s.id)}
                  className={`w-full text-left p-3 rounded-xl border transition-colors ${
                    activeSession?.id === s.id
                      ? 'bg-slate-950 border-emerald-500/60'
                      : 'bg-slate-950/60 border-slate-800 hover:border-slate-700'
                  }`}
                >
                  <div className="font-bold text-xs text-white truncate">{s.title}</div>
                  <div className="text-[11px] font-mono text-slate-400 mt-0.5">{s.date}</div>
                </button>
              ))}
            </div>
          </section>

          <section className="xl:col-span-8 bg-slate-900/80 border border-slate-800 rounded-2xl p-5 space-y-3">
            {!activeSession ? (
              <div className="text-center py-16 text-sm text-slate-500">
                Click <strong>+ New Session</strong> to start your session log.
              </div>
            ) : (
              <>
                <div className="flex flex-wrap items-center justify-between gap-2 pb-3 border-b border-slate-800">
                  <div className="flex-1 min-w-[220px] flex flex-wrap gap-2">
                    <input
                      type="text"
                      value={activeSession.title}
                      onChange={(e) => updateSessionField(activeSession.id, 'title', e.target.value)}
                      className="flex-1 bg-slate-950 border border-slate-800 rounded-lg px-3 py-1.5 text-sm font-bold text-white"
                    />
                    <input
                      type="date"
                      value={activeSession.date || ''}
                      onChange={(e) => updateSessionField(activeSession.id, 'date', e.target.value)}
                      className="bg-slate-950 border border-slate-800 rounded-lg px-2.5 py-1.5 text-xs font-mono text-slate-300"
                    />
                  </div>
                  <button
                    type="button"
                    onClick={() => deleteSessionNote(activeSession.id)}
                    className="px-3 py-1.5 rounded-lg bg-rose-500/20 hover:bg-rose-500/30 border border-rose-500/40 text-xs text-rose-300"
                  >
                    Delete Page
                  </button>
                </div>

                {/* Quick Snippets & Codex [[WikiLink]] Chips */}
                <div className="flex flex-wrap items-center gap-1.5 text-[11px]">
                  <span className="font-mono text-slate-500 uppercase mr-1">Insert:</span>
                  <button
                    type="button"
                    onClick={() => insertIntoActiveSession('\n## Scene: \n- Sensory cue: \n- Stakes: \n')}
                    className="px-2 py-0.5 rounded bg-slate-800 hover:bg-slate-700 text-amber-300"
                  >
                    + Scene Header
                  </button>
                  <button
                    type="button"
                    onClick={() => insertIntoActiveSession('\n## Loot & Coin Awarded\n- GP: \n- Magic Items: \n')}
                    className="px-2 py-0.5 rounded bg-slate-800 hover:bg-slate-700 text-emerald-300"
                  >
                    + Loot Log
                  </button>
                  <button
                    type="button"
                    onClick={() => insertIntoActiveSession('\n## Clocks & Loose Ends\n- [ ] Threat Clock (0/4): \n')}
                    className="px-2 py-0.5 rounded bg-slate-800 hover:bg-slate-700 text-sky-300"
                  >
                    + Clocks &amp; Loose Ends
                  </button>
                </div>

                {codex.length > 0 && (
                  <div className="flex flex-wrap items-center gap-1 text-[11px] bg-slate-950/60 border border-slate-800 rounded-xl p-2">
                    <span className="font-mono text-slate-500 uppercase mr-1">Link Codex:</span>
                    {codex.slice(0, 12).map((entry) => (
                      <button
                        key={entry.id}
                        type="button"
                        onClick={() => insertIntoActiveSession(`[[${entry.title}]] `)}
                        className="px-2 py-0.5 rounded bg-slate-900 hover:bg-slate-800 border border-slate-700 text-emerald-300 font-mono"
                      >
                        [[{entry.title}]]
                      </button>
                    ))}
                  </div>
                )}

                <textarea
                  rows={16}
                  value={activeSession.content || ''}
                  onChange={(e) => updateSessionField(activeSession.id, 'content', e.target.value)}
                  placeholder="Write session prep, secrets, or live notes in Markdown..."
                  className="w-full bg-slate-950 border border-slate-800 rounded-xl p-4 font-mono text-xs leading-relaxed text-slate-200 focus:outline-none focus:border-emerald-500"
                />
              </>
            )}
          </section>
        </div>
      )}
    </div>
  );
}
