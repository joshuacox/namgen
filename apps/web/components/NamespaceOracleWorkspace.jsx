'use client';

import { useEffect, useMemo, useRef, useState } from 'react';

const PITCH_PRESETS = [
  {
    label: 'Creature Deck-Building MOBA',
    pitch: 'A deck-building game where you collect creatures and powers and then have them battle in a tactical MOBA arena.',
    keywords: 'deck, creature, moba, rift, spell, summon, arena, brawl',
  },
  {
    label: 'Dark Fantasy TTRPG Vault',
    pitch: 'A grimdark tabletop RPG campaign manager, procedural dungeon generator, and lore codex for Dungeon Masters.',
    keywords: 'crypt, rune, sigil, dungeon, vault, lore, codex, grimoire',
  },
  {
    label: 'Developer CLI & Infrastructure SDK',
    pitch: 'An ultra-fast systems observability CLI and zero-dependency pipeline orchestrator for edge infrastructure.',
    keywords: 'trace, pipe, kernel, shard, node, mesh, pulse, fork',
  },
  {
    label: 'Indie Game Studio Brand',
    pitch: 'An independent game studio crafting tactile strategy rogues, procedural worlds, and systemic sandboxes.',
    keywords: 'forge, vex, prism, locus, spark, myth, clockwork, studio',
  },
];

const DEFAULT_ARCHETYPES = [
  { name: 'Arcane/Cyberpunk', description: 'Evocative dark/runic tech fusions (Hexgrid, Sigilcast, Neonpakt)' },
  { name: 'Classical Etymology', description: 'Latin & Greek roots (Bellumancy, Locuspact, Aegisdeck)' },
  { name: 'Punchy Portmanteaus', description: 'Fused high-energy blends (Deckbrawl, Spellclash, Summonrift)' },
  { name: 'Functional Minimalist', description: 'Direct ultra-clean compounds (Draftlane, Cardrift, Pactline)' },
  { name: 'Sovereign Neologisms', description: 'Distinctive trademarkable coinages (Vexora, Kaelith, Orvaxis)' },
];

const ALL_TLDS = ['com', 'io', 'dev', 'org', 'gg', 'ai', 'app', 'net', 'games', 'xyz'];
const ALL_REGISTRIES = ['github', 'npm', 'pypi', 'crates', 'homebrew', 'dockerhub'];

function statusBadgeClass(status) {
  if (status === 'FREE' || status === 'CLEAR') return 'border-emerald-500/40 bg-emerald-500/15 text-emerald-300';
  if (status === 'TAKEN' || status === 'RESERVED' || String(status).startsWith('COLLISION')) {
    return 'border-rose-500/40 bg-rose-500/15 text-rose-300';
  }
  return 'border-slate-700 bg-slate-800/80 text-slate-400';
}

function speakWord(word) {
  if (typeof window === 'undefined' || !window.speechSynthesis) return;
  try {
    window.speechSynthesis.cancel();
    const u = new SpeechSynthesisUtterance(word);
    u.rate = 0.92;
    window.speechSynthesis.speak(u);
  } catch {}
}

export default function NamespaceOracleWorkspace({
  settings,
  cppEngine,
  onOpenSettings,
  onSaveCodex,
  onNotify,
}) {
  const [pitch, setPitch] = useState(PITCH_PRESETS[0].pitch);
  const [keywords, setKeywords] = useState(PITCH_PRESETS[0].keywords);
  const [runTitle, setRunTitle] = useState('Creature MOBA Namespace Sweep');
  const [mode, setMode] = useState('hybrid'); // 'hybrid' | 'cpp' | 'custom'
  const [poolSize, setPoolSize] = useState(50);
  const [llmShare, setLlmShare] = useState(40);
  const [syllablePreset, setSyllablePreset] = useState('any');
  const [customText, setCustomText] = useState('Locuspact\nAegisdeck\nOrvaxis\nHexgrid\nDeckbrawl\nHearthstone');
  const [archetypes, setArchetypes] = useState(DEFAULT_ARCHETYPES);
  const [tlds, setTlds] = useState(['com', 'io', 'dev', 'org']);
  const [registries, setRegistries] = useState(['github', 'npm', 'pypi', 'crates']);
  const [marketChecks, setMarketChecks] = useState(true);
  const [githubRepoSearch, setGithubRepoSearch] = useState(false);
  const [enableAiCritique, setEnableAiCritique] = useState(true);

  // Run state
  const [running, setRunning] = useState(false);
  const [tailoring, setTailoring] = useState(false);
  const [phaseMessage, setPhaseMessage] = useState('');
  const [notice, setNotice] = useState('');
  const [progress, setProgress] = useState({ stage: 'idle', done: 0, total: 0 });
  const [liveResults, setLiveResults] = useState([]);
  const [finalRun, setFinalRun] = useState(null);
  const [history, setHistory] = useState([]);
  const abortRef = useRef(null);

  // Table filter & sort state
  const [searchQuery, setSearchQuery] = useState('');
  const [archFilter, setArchFilter] = useState('ALL');
  const [cleanSweepOnly, setCleanSweepOnly] = useState(false);
  const [comFreeOnly, setComFreeOnly] = useState(false);
  const [sortBy, setSortBy] = useState('score');

  useEffect(() => {
    refreshHistory();
  }, []);

  async function refreshHistory() {
    try {
      const res = await fetch('/api/oracle');
      const data = await res.json();
      if (Array.isArray(data.runs)) setHistory(data.runs);
    } catch {}
  }

  async function handleLoadRun(id) {
    try {
      const res = await fetch(`/api/oracle?id=${encodeURIComponent(id)}`);
      const data = await res.json();
      if (data.run) {
        setFinalRun(data.run);
        setLiveResults(data.run.results || []);
        onNotify?.(`Loaded Oracle run: ${data.run.title}`);
      }
    } catch (err) {
      onNotify?.(err?.message || 'Failed to load run', 'error');
    }
  }

  async function handleDeleteRun(id) {
    try {
      await fetch(`/api/oracle?id=${encodeURIComponent(id)}`, { method: 'DELETE' });
      setHistory((prev) => prev.filter((r) => r.id !== id));
      if (finalRun?.id === id) setFinalRun(null);
    } catch {}
  }

  async function handleTailorArchetypes() {
    setTailoring(true);
    try {
      const res = await fetch('/api/oracle', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ action: 'tailor-archetypes', pitch }),
      });
      const data = await res.json();
      if (Array.isArray(data.archetypes) && data.archetypes.length >= 3) {
        setArchetypes(data.archetypes.map((a) => ({ name: a.name, description: a.description || '' })));
        onNotify?.(data.fallback ? 'Tailored archetypes using heuristics (Ollama offline).' : 'Tailored 5 archetypes with AI!');
      }
    } catch {
      onNotify?.('Failed to tailor archetypes', 'error');
    } finally {
      setTailoring(false);
    }
  }

  function handleCustomFileUpload(e) {
    const file = e.target.files?.[0];
    if (!file) return;
    const reader = new FileReader();
    reader.onload = () => {
      setCustomText(String(reader.result || ''));
      setMode('custom');
      onNotify?.(`Loaded ${file.name} into Custom Candidate List.`);
    };
    reader.readAsText(file);
  }

  function toggleTld(tld) {
    setTlds((prev) => (prev.includes(tld) ? prev.filter((t) => t !== tld) : [...prev, tld]));
  }

  function toggleRegistry(reg) {
    setRegistries((prev) => (prev.includes(reg) ? prev.filter((r) => r !== reg) : [...prev, reg]));
  }

  async function handleLaunchRun() {
    if (running) return;
    if (tlds.length === 0 && registries.length === 0 && !marketChecks) {
      onNotify?.('Enable at least one TLD, registry, or market check.', 'error');
      return;
    }
    const ctrl = new AbortController();
    abortRef.current = ctrl;
    setRunning(true);
    setFinalRun(null);
    setLiveResults([]);
    setNotice('');
    setProgress({ stage: 'generating', done: 0, total: poolSize });
    setPhaseMessage('Initializing Oracle sweep...');

    const [minSyllables, maxSyllables] =
      syllablePreset === 'any' ? [0, 0] : syllablePreset.split('-').map(Number);

    try {
      const res = await fetch('/api/oracle', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        signal: ctrl.signal,
        body: JSON.stringify({
          action: 'stream-run',
          title: runTitle,
          pitch,
          keywords,
          mode,
          customCandidatesText: customText,
          poolSize,
          llmShare,
          archetypes,
          minSyllables,
          maxSyllables,
          tlds,
          registries,
          marketChecks,
          githubRepoSearch,
          enableAiCritique,
        }),
      });

      if (!res.ok) {
        const err = await res.json().catch(() => ({}));
        throw new Error(err.error || `HTTP ${res.status}`);
      }

      const reader = res.body.getReader();
      const decoder = new TextDecoder();
      let buf = '';
      const recordMap = new Map();

      const handleEvent = (eventType, dataStr) => {
        let payload = {};
        try { payload = JSON.parse(dataStr); } catch { return; }

        if (eventType === 'phase') {
          setPhaseMessage(payload.message || payload.phase);
        } else if (eventType === 'notice') {
          setNotice(payload.message || '');
        } else if (eventType === 'generation_progress') {
          setProgress({ stage: 'generating', done: payload.current || 0, total: payload.target || poolSize });
        } else if (eventType === 'pool_ready') {
          if (payload.notice) setNotice(payload.notice);
          setProgress({ stage: 'stage1', done: 0, total: payload.total || poolSize });
        } else if (eventType === 'candidate_stage1') {
          setProgress({ stage: 'stage1', done: payload.completed || 0, total: payload.total || poolSize });
          if (payload.record) {
            recordMap.set(payload.record.slug, payload.record);
            setLiveResults(Array.from(recordMap.values()));
          }
        } else if (eventType === 'stage2_start') {
          setPhaseMessage(`Stage 2: Screening top ${payload.shortlistCount} survivors against Steam & App Store...`);
          setProgress({ stage: 'stage2', done: 0, total: payload.shortlistCount || 1 });
        } else if (eventType === 'candidate_stage2') {
          setProgress({ stage: 'stage2', done: payload.completed || 0, total: payload.total || 1 });
          if (payload.record) {
            recordMap.set(payload.record.slug, payload.record);
            setLiveResults(Array.from(recordMap.values()));
          }
        } else if (eventType === 'complete' && payload.run) {
          setFinalRun(payload.run);
          setLiveResults(payload.run.results || []);
          setPhaseMessage(`Sweep complete — ${payload.run.stats?.cleanSweep ?? 0} Clean-Sweep (Score 100) survivors.`);
          refreshHistory();
        } else if (eventType === 'error') {
          throw new Error(payload.message || 'Oracle stream error');
        }
      };

      while (true) {
        const { done, value } = await reader.read();
        if (done) break;
        buf += decoder.decode(value, { stream: true });
        let sep;
        while ((sep = buf.indexOf('\n\n')) !== -1) {
          const chunk = buf.slice(0, sep);
          buf = buf.slice(sep + 2);
          let ev = 'message';
          let dataLines = [];
          for (const line of chunk.split('\n')) {
            if (line.startsWith('event:')) ev = line.slice(6).trim();
            else if (line.startsWith('data:')) dataLines.push(line.slice(5).trim());
          }
          if (dataLines.length > 0) {
            handleEvent(ev, dataLines.join('\n'));
          }
        }
      }
    } catch (err) {
      if (err?.name === 'AbortError') {
        setPhaseMessage('Oracle sweep aborted by user.');
      } else {
        onNotify?.(err?.message || 'Oracle sweep failed', 'error');
        setPhaseMessage(err?.message || 'Failed');
      }
    } finally {
      setRunning(false);
      abortRef.current = null;
    }
  }

  function handleAbort() {
    abortRef.current?.abort();
  }

  const displayedResults = useMemo(() => {
    const q = searchQuery.trim().toLowerCase();
    const list = liveResults.filter((r) => {
      if (cleanSweepOnly && r.score !== 100) return false;
      if (comFreeOnly && r.dns?.com?.status !== 'FREE') return false;
      if (archFilter !== 'ALL' && r.archetype !== archFilter) return false;
      if (q && !r.name.toLowerCase().includes(q) && !String(r.recommendation || '').toLowerCase().includes(q)) {
        return false;
      }
      return true;
    });

    return [...list].sort((a, b) => {
      if (sortBy === 'name') return a.name.localeCompare(b.name);
      if (sortBy === 'syllables') return (a.syllables - b.syllables) || (b.score - a.score);
      return (b.score - a.score) || (a.syllables - b.syllables) || a.name.localeCompare(b.name);
    });
  }, [liveResults, searchQuery, archFilter, cleanSweepOnly, comFreeOnly, sortBy]);

  const liveStats = useMemo(() => {
    const activeTlds = finalRun?.tlds || tlds;
    const total = liveResults.length;
    const cleanSweep = liveResults.filter((r) => r.score === 100).length;
    const comFree = liveResults.filter((r) => r.dns?.com?.status === 'FREE').length;
    const ghFree = liveResults.filter((r) => !r.registries?.github || r.registries.github.status === 'FREE').length;
    const allTldsFree = liveResults.filter((r) => activeTlds.every((t) => r.dns?.[t]?.status === 'FREE')).length;
    return { total, cleanSweep, comFree, ghFree, allTldsFree };
  }, [liveResults, finalRun, tlds]);

  const uniqueArchetypesInResults = useMemo(() => {
    const s = new Set(liveResults.map((r) => r.archetype).filter(Boolean));
    return Array.from(s);
  }, [liveResults]);

  function downloadFile(content, filename, mime) {
    const blob = new Blob([content], { type: mime });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = filename;
    a.click();
    URL.revokeObjectURL(url);
  }

  function handleExportCsv() {
    const activeTlds = finalRun?.tlds || tlds;
    const activeRegs = finalRun?.registries || registries;
    const header = [
      'Rank', 'Score', 'Name', 'Archetype', 'Syllables', 'Sigil', 'TM_Estimate',
      ...activeTlds.map((t) => `.${t}`),
      ...activeRegs,
      'Market_Proxy', 'Recommendation',
    ];
    const esc = (v) => `"${String(v ?? '').replace(/"/g, '""')}"`;
    const rows = [
      header.map(esc).join(','),
      ...displayedResults.map((r, i) => [
        r.rank || i + 1,
        r.score,
        r.name,
        r.archetype,
        r.syllables,
        r.sigil,
        r.tmProbability,
        ...activeTlds.map((t) => r.dns?.[t]?.status || 'SKIP'),
        ...activeRegs.map((reg) => r.registries?.[reg]?.status || 'SKIP'),
        r.marketSummary,
        r.recommendation,
      ].map(esc).join(',')),
    ];
    downloadFile(rows.join('\n'), 'oracle_survival_matrix.csv', 'text/csv;charset=utf-8');
  }

  function handleSaveSurvivorToCodex(rec) {
    onSaveCodex?.({
      kind: 'item',
      type: 'Title',
      title: rec.name,
      subtitle: `${rec.archetype} • Score ${rec.score}/100`,
      status: 'Shortlisted',
      tags: ['namespace-oracle', rec.archetype, `score-${rec.score}`],
      summary: [
        `Archetype: ${rec.archetype} | Score: ${rec.score}/100 | Syllables: ${rec.syllables} (${rec.sigil})`,
        `TM Proxy Est.: ${rec.tmProbability} | Market: ${rec.marketSummary}`,
        `Sovereign Stack: ${rec.recommendation}`,
      ].join('\n'),
      dmNotes: '',
      data: rec,
    });
    onNotify?.(`Saved "${rec.name}" to Campaign Codex.`);
  }

  const activeTldsDisplay = finalRun?.tlds || tlds;
  const activePkgsDisplay = (finalRun?.registries || registries).filter((r) => r !== 'github');

  return (
    <div className="space-y-6">
      {/* Legal / Trademark Banner */}
      <div className="flex flex-wrap items-center justify-between gap-3 rounded-xl border border-amber-500/30 bg-amber-500/10 px-4 py-3 text-xs text-amber-200">
        <div>
          <strong className="font-semibold text-amber-300">Namespace Oracle & Automated Registrar:</strong>{' '}
          Live DoH NS, authoritative RDAP/WHOIS, GitHub, NPM/PyPI/Crates, and Steam/App Store checks are empirical availability proxies —{' '}
          <span className="underline">NOT legal trademark clearance</span>. Confirm finalists directly in Class 9 / Class 42:
        </div>
        <div className="flex shrink-0 gap-2">
          <a
            href="https://tmsearch.uspto.gov/"
            target="_blank"
            rel="noreferrer"
            className="rounded-lg border border-amber-400/40 bg-slate-900/80 px-2.5 py-1 font-medium text-amber-200 hover:bg-slate-800"
          >
            USPTO Search ↗
          </a>
          <a
            href="https://branddb.wipo.int/"
            target="_blank"
            rel="noreferrer"
            className="rounded-lg border border-amber-400/40 bg-slate-900/80 px-2.5 py-1 font-medium text-amber-200 hover:bg-slate-800"
          >
            WIPO Global Brand ↗
          </a>
        </div>
      </div>

      {/* Config + Saved History Grid */}
      <div className="grid gap-6 lg:grid-cols-[1fr_300px]">
        {/* Main Configuration Card */}
        <div className="space-y-5 rounded-2xl border border-slate-800 bg-slate-900/70 p-5">
          <div className="flex flex-wrap items-center justify-between gap-2">
            <div>
              <h2 className="text-lg font-bold text-white">1. Concept Pitch & Candidate Pool Engine</h2>
              <p className="text-xs text-slate-400">
                Combine local Ollama creativity with the zero-allocation C++17 <code>./namgen</code> synthesizer, or upload your own list.
              </p>
            </div>
            <button
              type="button"
              onClick={onOpenSettings}
              className="rounded-lg border border-slate-700 bg-slate-800/80 px-3 py-1.5 text-xs font-medium text-slate-200 hover:border-amber-500/50"
            >
              Ollama: {settings?.model || 'Auto-Detect'} ({settings?.baseUrl || '127.0.0.1:11434'})
            </button>
          </div>

          {/* Preset pills */}
          <div className="flex flex-wrap gap-1.5">
            {PITCH_PRESETS.map((p) => (
              <button
                key={p.label}
                type="button"
                onClick={() => {
                  setPitch(p.pitch);
                  setKeywords(p.keywords);
                  setRunTitle(`${p.label} Sweep`);
                }}
                className="rounded-full border border-slate-700 bg-slate-950/70 px-3 py-1 text-xs text-slate-300 hover:border-emerald-500/60 hover:text-emerald-300"
              >
                {p.label}
              </button>
            ))}
          </div>

          <div className="grid gap-3 sm:grid-cols-2">
            <div>
              <label className="mb-1 block text-xs font-medium text-slate-300">Run Title</label>
              <input
                type="text"
                value={runTitle}
                onChange={(e) => setRunTitle(e.target.value)}
                className="w-full rounded-lg border border-slate-700 bg-slate-950 px-3 py-2 text-sm text-white focus:border-emerald-500 focus:outline-none"
              />
            </div>
            <div>
              <label className="mb-1 block text-xs font-medium text-slate-300">Theme Keywords (feeds C++ Markov & Portmanteaus)</label>
              <input
                type="text"
                value={keywords}
                onChange={(e) => setKeywords(e.target.value)}
                placeholder="deck, creature, moba, rift, spell..."
                className="w-full rounded-lg border border-slate-700 bg-slate-950 px-3 py-2 text-sm text-white focus:border-emerald-500 focus:outline-none"
              />
            </div>
          </div>

          <div>
            <label className="mb-1 block text-xs font-medium text-slate-300">Concept / Product / Game Pitch</label>
            <textarea
              rows={2}
              value={pitch}
              onChange={(e) => setPitch(e.target.value)}
              className="w-full rounded-lg border border-slate-700 bg-slate-950 px-3 py-2 text-sm text-white focus:border-emerald-500 focus:outline-none"
            />
          </div>

          {/* Generation Mode & Ratio */}
          <div className="grid gap-4 rounded-xl border border-slate-800 bg-slate-950/60 p-4 sm:grid-cols-3">
            <div>
              <label className="mb-1.5 block text-xs font-semibold text-slate-300">Source Mode</label>
              <div className="flex flex-col gap-1.5 text-xs">
                {[
                  { id: 'hybrid', label: '🤖+⚡ Hybrid Ollama + C++17' },
                  { id: 'cpp', label: '⚡ Pure C++17 Engine (Instant)' },
                  { id: 'custom', label: '📋 Custom List / CSV Upload' },
                ].map((m) => (
                  <button
                    key={m.id}
                    type="button"
                    onClick={() => setMode(m.id)}
                    className={`rounded-lg border px-3 py-1.5 text-left font-medium transition ${
                      mode === m.id
                        ? 'border-emerald-500/60 bg-emerald-500/15 text-emerald-300'
                        : 'border-slate-800 bg-slate-900 text-slate-400 hover:text-white'
                    }`}
                  >
                    {m.label}
                  </button>
                ))}
              </div>
            </div>

            {mode !== 'custom' ? (
              <>
                <div>
                  <label className="mb-1.5 block text-xs font-semibold text-slate-300">
                    Candidate Pool Size: <span className="text-emerald-400">{poolSize}</span>
                  </label>
                  <div className="flex flex-wrap gap-1.5">
                    {[25, 50, 100, 250, 500, 777].map((sz) => (
                      <button
                        key={sz}
                        type="button"
                        onClick={() => setPoolSize(sz)}
                        className={`rounded-md border px-2.5 py-1 text-xs font-mono ${
                          poolSize === sz
                            ? 'border-emerald-500 bg-emerald-500/20 text-emerald-300'
                            : 'border-slate-700 bg-slate-900 text-slate-300 hover:border-slate-500'
                        }`}
                      >
                        {sz}
                      </button>
                    ))}
                  </div>
                  {poolSize >= 250 && (
                    <p className="mt-1.5 text-[11px] text-amber-300/90">
                      Tip: {poolSize} candidates takes ~{Math.ceil((poolSize * 0.8) / 60)}–{Math.ceil((poolSize * 1.4) / 60)} min with live Crates/GitHub rate limits. Add <code>GITHUB_TOKEN</code> in Settings for 5,000/hr.
                    </p>
                  )}
                </div>

                <div className="space-y-3">
                  {mode === 'hybrid' && (
                    <div>
                      <div className="mb-1 flex justify-between text-xs text-slate-300">
                        <span>Ollama LLM vs C++17 Split</span>
                        <span className="font-mono text-amber-300">{llmShare}% AI / {100 - llmShare}% C++</span>
                      </div>
                      <input
                        type="range"
                        min="0"
                        max="100"
                        step="10"
                        value={llmShare}
                        onChange={(e) => setLlmShare(Number(e.target.value))}
                        className="w-full accent-amber-500"
                      />
                    </div>
                  )}
                  <div>
                    <label className="mb-1 block text-xs font-semibold text-slate-300">Syllable Constraint</label>
                    <select
                      value={syllablePreset}
                      onChange={(e) => setSyllablePreset(e.target.value)}
                      className="w-full rounded-lg border border-slate-700 bg-slate-900 px-2.5 py-1.5 text-xs text-white"
                    >
                      <option value="any">Any Syllables</option>
                      <option value="1-2">1–2 Syllables (Ultra-Punchy)</option>
                      <option value="2-3">2–3 Syllables (Sweet Spot)</option>
                      <option value="2-4">2–4 Syllables (Evocative)</option>
                    </select>
                  </div>
                </div>
              </>
            ) : (
              <div className="space-y-2 sm:col-span-2">
                <div className="flex items-center justify-between">
                  <label className="text-xs font-semibold text-slate-300">
                    Paste Candidate Names or CSV (<code>name,archetype</code> or one per line)
                  </label>
                  <label className="cursor-pointer rounded-md border border-slate-700 bg-slate-900 px-2.5 py-1 text-xs text-emerald-300 hover:border-emerald-500">
                    Upload CSV/TXT
                    <input type="file" accept=".csv,.txt" onChange={handleCustomFileUpload} className="hidden" />
                  </label>
                </div>
                <textarea
                  rows={5}
                  value={customText}
                  onChange={(e) => setCustomText(e.target.value)}
                  className="w-full rounded-lg border border-slate-700 bg-slate-900 px-3 py-2 font-mono text-xs text-slate-200 focus:border-emerald-500 focus:outline-none"
                />
              </div>
            )}
          </div>

          {/* 5 Lexical Archetypes */}
          {mode !== 'custom' && (
            <div className="space-y-2">
              <div className="flex items-center justify-between">
                <span className="text-xs font-semibold uppercase tracking-wider text-slate-300">
                  5 Lexical Archetypes
                </span>
                <button
                  type="button"
                  onClick={handleTailorArchetypes}
                  disabled={tailoring}
                  className="rounded-lg border border-amber-500/40 bg-amber-500/15 px-3 py-1 text-xs font-medium text-amber-300 hover:bg-amber-500/25 disabled:opacity-50"
                >
                  {tailoring ? 'Tailoring...' : '✨ Tailor Archetypes with AI'}
                </button>
              </div>
              <div className="grid gap-2 sm:grid-cols-5">
                {archetypes.map((arch, idx) => (
                  <div key={idx} className="rounded-lg border border-slate-800 bg-slate-950/70 p-2">
                    <input
                      type="text"
                      value={arch.name}
                      onChange={(e) => {
                        const val = e.target.value;
                        setArchetypes((prev) => prev.map((a, i) => (i === idx ? { ...a, name: val } : a)));
                      }}
                      className="mb-1 w-full bg-transparent text-xs font-bold text-emerald-300 focus:outline-none"
                    />
                    <input
                      type="text"
                      value={arch.description}
                      onChange={(e) => {
                        const val = e.target.value;
                        setArchetypes((prev) => prev.map((a, i) => (i === idx ? { ...a, description: val } : a)));
                      }}
                      className="w-full bg-transparent text-[11px] text-slate-400 focus:outline-none"
                    />
                  </div>
                ))}
              </div>
            </div>
          )}

          {/* Verification Matrix Controls */}
          <div className="space-y-3 rounded-xl border border-slate-800 bg-slate-950/60 p-4">
            <div className="grid gap-4 sm:grid-cols-2">
              <div>
                <div className="mb-1.5 text-xs font-semibold text-slate-300">DNS + RDAP + WHOIS TLDs</div>
                <div className="flex flex-wrap gap-1.5">
                  {ALL_TLDS.map((tld) => (
                    <button
                      key={tld}
                      type="button"
                      onClick={() => toggleTld(tld)}
                      className={`rounded-md border px-2 py-1 font-mono text-xs ${
                        tlds.includes(tld)
                          ? 'border-emerald-500/60 bg-emerald-500/20 text-emerald-300'
                          : 'border-slate-800 bg-slate-900 text-slate-500'
                      }`}
                    >
                      .{tld}
                    </button>
                  ))}
                </div>
              </div>

              <div>
                <div className="mb-1.5 text-xs font-semibold text-slate-300">GitHub & Package Registries</div>
                <div className="flex flex-wrap gap-1.5">
                  {ALL_REGISTRIES.map((reg) => (
                    <button
                      key={reg}
                      type="button"
                      onClick={() => toggleRegistry(reg)}
                      className={`rounded-md border px-2 py-1 font-mono text-xs uppercase ${
                        registries.includes(reg)
                          ? 'border-emerald-500/60 bg-emerald-500/20 text-emerald-300'
                          : 'border-slate-800 bg-slate-900 text-slate-500'
                      }`}
                    >
                      {reg}
                    </button>
                  ))}
                </div>
              </div>
            </div>

            <div className="flex flex-wrap items-center justify-between gap-3 border-t border-slate-800 pt-3">
              <div className="flex flex-wrap gap-4 text-xs text-slate-300">
                <label className="flex items-center gap-1.5">
                  <input
                    type="checkbox"
                    checked={marketChecks}
                    onChange={(e) => setMarketChecks(e.target.checked)}
                    className="accent-emerald-500"
                  />
                  Steam + Apple App Store Proxy
                </label>
                <label className="flex items-center gap-1.5">
                  <input
                    type="checkbox"
                    checked={githubRepoSearch}
                    onChange={(e) => setGithubRepoSearch(e.target.checked)}
                    className="accent-emerald-500"
                  />
                  Exact GitHub Repo Count
                </label>
                {mode !== 'cpp' && (
                  <label className="flex items-center gap-1.5">
                    <input
                      type="checkbox"
                      checked={enableAiCritique}
                      onChange={(e) => setEnableAiCritique(e.target.checked)}
                      className="accent-amber-500"
                    />
                    AI Executive Critique
                  </label>
                )}
              </div>

              <div className="flex gap-2">
                {running ? (
                  <button
                    type="button"
                    onClick={handleAbort}
                    className="rounded-xl bg-rose-600 px-5 py-2.5 text-sm font-bold text-white hover:bg-rose-500"
                  >
                    ⏹ Stop Sweep
                  </button>
                ) : (
                  <button
                    type="button"
                    onClick={handleLaunchRun}
                    className="rounded-xl bg-emerald-600 px-6 py-2.5 text-sm font-bold text-white shadow-lg shadow-emerald-900/30 hover:bg-emerald-500"
                  >
                    🔮 Launch Namespace Oracle
                  </button>
                )}
              </div>
            </div>
          </div>
        </div>

        {/* Saved Oracle Runs History */}
        <div className="flex flex-col rounded-2xl border border-slate-800 bg-slate-900/70 p-4">
          <div className="mb-3 flex items-center justify-between">
            <h3 className="text-sm font-bold text-white">Saved Oracle Runs</h3>
            <span className="text-[11px] text-slate-400">{history.length} archived</span>
          </div>
          {history.length === 0 ? (
            <div className="rounded-xl border border-dashed border-slate-800 p-4 text-center text-xs text-slate-500">
              Completed Oracle sweeps are saved automatically to <code>.namgen-dm/oracle-runs/</code>.
            </div>
          ) : (
            <div className="max-h-[460px] space-y-2 overflow-y-auto pr-1">
              {history.map((item) => (
                <div
                  key={item.id}
                  className={`rounded-xl border p-2.5 text-xs transition ${
                    finalRun?.id === item.id
                      ? 'border-emerald-500/60 bg-emerald-500/10'
                      : 'border-slate-800 bg-slate-950/60 hover:border-slate-700'
                  }`}
                >
                  <div className="flex items-start justify-between gap-2">
                    <button
                      type="button"
                      onClick={() => handleLoadRun(item.id)}
                      className="text-left font-semibold text-white hover:text-emerald-300"
                    >
                      {item.title}
                    </button>
                    <button
                      type="button"
                      onClick={() => handleDeleteRun(item.id)}
                      className="text-slate-500 hover:text-rose-400"
                      title="Delete run"
                    >
                      ×
                    </button>
                  </div>
                  <div className="mt-1 flex items-center justify-between text-[11px] text-slate-400">
                    <span>{item.totalCandidates} tested</span>
                    <span className="font-semibold text-emerald-400">{item.cleanSweepCount} Score-100</span>
                  </div>
                  {item.topSurvivors?.length > 0 && (
                    <div className="mt-1.5 flex flex-wrap gap-1">
                      {item.topSurvivors.slice(0, 3).map((s) => (
                        <span key={s.name} className="rounded bg-slate-900 px-1.5 py-0.5 text-[10px] text-slate-300">
                          {s.name} ({s.score})
                        </span>
                      ))}
                    </div>
                  )}
                </div>
              ))}
            </div>
          )}
        </div>
      </div>

      {/* Live Progress & Attrition Funnel */}
      {(running || liveResults.length > 0 || notice) && (
        <div className="space-y-4 rounded-2xl border border-slate-800 bg-slate-900/70 p-5">
          <div className="flex flex-wrap items-center justify-between gap-2">
            <div>
              <div className="text-sm font-bold text-white">{phaseMessage || 'Oracle Verification'}</div>
              {notice && <div className="mt-1 text-xs text-amber-300">{notice}</div>}
            </div>
            {progress.total > 0 && (
              <div className="font-mono text-xs text-emerald-300">
                {progress.stage.toUpperCase()}: {progress.done} / {progress.total}
              </div>
            )}
          </div>

          {progress.total > 0 && (
            <div className="h-2 w-full overflow-hidden rounded-full bg-slate-800">
              <div
                className="h-full bg-gradient-to-r from-emerald-500 to-amber-400 transition-all duration-300"
                style={{ width: `${Math.min(100, Math.round((progress.done / progress.total) * 100))}%` }}
              />
            </div>
          )}

          {/* Funnel Counters */}
          <div className="grid grid-cols-2 gap-3 sm:grid-cols-5">
            {[
              { label: 'Candidates Scanned', value: liveStats.total, color: 'text-white' },
              { label: 'All Selected TLDs Free', value: liveStats.allTldsFree, color: 'text-emerald-300' },
              { label: '.com Unallocated', value: liveStats.comFree, color: 'text-cyan-300' },
              { label: 'GitHub Handle Free', value: liveStats.ghFree, color: 'text-amber-300' },
              { label: 'Clean Sweep (Score 100)', value: liveStats.cleanSweep, color: 'text-emerald-400' },
            ].map((stat) => (
              <div key={stat.label} className="rounded-xl border border-slate-800 bg-slate-950/70 p-3">
                <div className={`text-xl font-bold font-mono ${stat.color}`}>{stat.value}</div>
                <div className="text-[11px] text-slate-400">{stat.label}</div>
              </div>
            ))}
          </div>
        </div>
      )}

      {/* AI Executive Critique Card */}
      {finalRun?.aiSummary && (
        <div className="space-y-3 rounded-2xl border border-amber-500/40 bg-gradient-to-br from-slate-900 to-slate-950 p-5">
          <div className="flex items-center justify-between">
            <h3 className="text-base font-bold text-amber-300">✨ AI Sovereign Verdict & Finalist Critique</h3>
            <span className="rounded-full border border-amber-500/30 bg-amber-500/10 px-2.5 py-0.5 text-[11px] text-amber-200">
              Phonoaesthetics + Verified Availability
            </span>
          </div>
          <p className="text-sm leading-relaxed text-slate-200">{finalRun.aiSummary}</p>
          {Array.isArray(finalRun.aiTopPicks) && finalRun.aiTopPicks.length > 0 && (
            <div className="grid gap-3 pt-1 sm:grid-cols-5">
              {finalRun.aiTopPicks.map((pick, i) => (
                <div key={i} className="rounded-xl border border-slate-800 bg-slate-900/80 p-3">
                  <div className="text-sm font-bold text-emerald-300">{pick.name}</div>
                  {pick.positioningTagline && (
                    <div className="mt-0.5 text-[11px] italic text-amber-200/90">{pick.positioningTagline}</div>
                  )}
                  <p className="mt-1.5 text-xs text-slate-400">{pick.whyItWins}</p>
                </div>
              ))}
            </div>
          )}
        </div>
      )}

      {/* Survival Matrix Table */}
      {liveResults.length > 0 && (
        <div className="space-y-4 rounded-2xl border border-slate-800 bg-slate-900/70 p-5">
          <div className="flex flex-wrap items-center justify-between gap-3">
            <h3 className="text-base font-bold text-white">
              Survival Matrix ({displayedResults.length} shown of {liveResults.length})
            </h3>
            <div className="flex flex-wrap gap-2">
              {finalRun?.markdown && (
                <button
                  type="button"
                  onClick={() => downloadFile(finalRun.markdown, 'survival_matrix.md', 'text/markdown;charset=utf-8')}
                  className="rounded-lg border border-slate-700 bg-slate-800 px-3 py-1.5 text-xs font-medium text-slate-200 hover:border-emerald-500"
                >
                  Export .md
                </button>
              )}
              <button
                type="button"
                onClick={handleExportCsv}
                className="rounded-lg border border-slate-700 bg-slate-800 px-3 py-1.5 text-xs font-medium text-slate-200 hover:border-emerald-500"
              >
                Export .csv
              </button>
              <button
                type="button"
                onClick={() => downloadFile(JSON.stringify(displayedResults, null, 2), 'oracle_results.json', 'application/json')}
                className="rounded-lg border border-slate-700 bg-slate-800 px-3 py-1.5 text-xs font-medium text-slate-200 hover:border-emerald-500"
              >
                Export .json
              </button>
            </div>
          </div>

          {/* Filter & Sort Bar */}
          <div className="flex flex-wrap items-center gap-2.5 text-xs">
            <input
              type="text"
              value={searchQuery}
              onChange={(e) => setSearchQuery(e.target.value)}
              placeholder="Filter candidates..."
              className="w-48 rounded-lg border border-slate-700 bg-slate-950 px-3 py-1.5 text-white placeholder-slate-500 focus:border-emerald-500 focus:outline-none"
            />
            <select
              value={archFilter}
              onChange={(e) => setArchFilter(e.target.value)}
              className="rounded-lg border border-slate-700 bg-slate-950 px-2.5 py-1.5 text-slate-200"
            >
              <option value="ALL">All Archetypes</option>
              {uniqueArchetypesInResults.map((a) => (
                <option key={a} value={a}>{a}</option>
              ))}
            </select>
            <select
              value={sortBy}
              onChange={(e) => setSortBy(e.target.value)}
              className="rounded-lg border border-slate-700 bg-slate-950 px-2.5 py-1.5 text-slate-200"
            >
              <option value="score">Sort: Sovereign Score</option>
              <option value="syllables">Sort: Shortest Syllables</option>
              <option value="name">Sort: A–Z</option>
            </select>
            <label className="flex items-center gap-1.5 rounded-lg border border-slate-800 bg-slate-950 px-2.5 py-1.5 text-slate-300">
              <input
                type="checkbox"
                checked={cleanSweepOnly}
                onChange={(e) => setCleanSweepOnly(e.target.checked)}
                className="accent-emerald-500"
              />
              Score 100 Only
            </label>
            <label className="flex items-center gap-1.5 rounded-lg border border-slate-800 bg-slate-950 px-2.5 py-1.5 text-slate-300">
              <input
                type="checkbox"
                checked={comFreeOnly}
                onChange={(e) => setComFreeOnly(e.target.checked)}
                className="accent-emerald-500"
              />
              .com Free Only
            </label>
          </div>

          <div className="overflow-x-auto">
            <table className="w-full border-collapse text-left text-xs">
              <thead>
                <tr className="border-b border-slate-800 text-[11px] uppercase tracking-wider text-slate-400">
                  <th className="py-2 pr-3">#</th>
                  <th className="py-2 pr-3">Score</th>
                  <th className="py-2 pr-3">Name & Archetype</th>
                  <th className="py-2 pr-3">Syl / Sigil</th>
                  <th className="py-2 pr-3">TM Est.</th>
                  <th className="py-2 pr-3">DNS / RDAP / WHOIS</th>
                  <th className="py-2 pr-3">GitHub & Packages</th>
                  <th className="py-2 pr-3">Market / TM Verify</th>
                  <th className="py-2 pr-3">Recommendation</th>
                  <th className="py-2 text-right">Vault</th>
                </tr>
              </thead>
              <tbody className="divide-y divide-slate-800/70">
                {displayedResults.map((rec, idx) => (
                  <tr key={rec.slug || rec.name} className="hover:bg-slate-800/30">
                    <td className="py-2.5 pr-3 font-mono text-slate-400">{rec.rank || idx + 1}</td>
                    <td className="py-2.5 pr-3">
                      <span
                        className={`inline-block rounded-md px-2 py-0.5 font-mono font-bold ${
                          rec.score === 100
                            ? 'bg-emerald-500/20 text-emerald-300'
                            : rec.score >= 70
                            ? 'bg-amber-500/20 text-amber-300'
                            : 'bg-slate-800 text-slate-400'
                        }`}
                      >
                        {rec.score}
                      </span>
                    </td>
                    <td className="py-2.5 pr-3">
                      <div className="font-bold text-white">{rec.name}</div>
                      <div className="text-[11px] text-slate-400">{rec.archetype}</div>
                    </td>
                    <td className="py-2.5 pr-3">
                      <div className="flex items-center gap-1.5">
                        <span className="font-mono text-slate-300">{rec.syllables}s</span>
                        <span className="font-mono text-[11px] text-cyan-300">{rec.sigil}</span>
                        <button
                          type="button"
                          onClick={() => speakWord(rec.name)}
                          title="Pronounce via Web Speech"
                          className="rounded px-1 text-slate-400 hover:bg-slate-800 hover:text-white"
                        >
                          🔊
                        </button>
                      </div>
                    </td>
                    <td className="py-2.5 pr-3 text-[11px] text-slate-300">{rec.tmProbability}</td>
                    <td className="py-2.5 pr-3">
                      <div className="flex flex-wrap gap-1">
                        {activeTldsDisplay.map((t) => {
                          const st = rec.dns?.[t]?.status || 'SKIP';
                          return (
                            <span key={t} className={`rounded border px-1.5 py-0.5 font-mono text-[10px] ${statusBadgeClass(st)}`}>
                              .{t}:{st === 'FREE' ? '✓' : st === 'TAKEN' ? '✗' : '?'}
                            </span>
                          );
                        })}
                      </div>
                    </td>
                    <td className="py-2.5 pr-3">
                      <div className="flex flex-wrap gap-1">
                        {rec.registries?.github && (
                          <span className={`rounded border px-1.5 py-0.5 font-mono text-[10px] ${statusBadgeClass(rec.registries.github.status)}`}>
                            GH:{rec.registries.github.status}
                          </span>
                        )}
                        {activePkgsDisplay.map((pkg) => {
                          const st = rec.registries?.[pkg]?.status || 'SKIP';
                          return (
                            <span key={pkg} className={`rounded border px-1.5 py-0.5 font-mono text-[10px] uppercase ${statusBadgeClass(st)}`}>
                              {pkg}:{st === 'FREE' ? '✓' : st === 'TAKEN' ? '✗' : '?'}
                            </span>
                          );
                        })}
                      </div>
                    </td>
                    <td className="py-2.5 pr-3">
                      <div className="max-w-[190px] truncate text-[11px] text-slate-300" title={rec.marketSummary}>
                        {rec.marketSummary}
                      </div>
                      <div className="mt-0.5 flex gap-2 text-[10px]">
                        <a
                          href={`https://tmsearch.uspto.gov/search/search-results?query=${encodeURIComponent(rec.name)}`}
                          target="_blank"
                          rel="noreferrer"
                          className="text-amber-300 hover:underline"
                        >
                          USPTO ↗
                        </a>
                        <a
                          href={`https://branddb.wipo.int/en/quicksearch/brand/${encodeURIComponent(rec.name)}`}
                          target="_blank"
                          rel="noreferrer"
                          className="text-cyan-300 hover:underline"
                        >
                          WIPO ↗
                        </a>
                      </div>
                    </td>
                    <td className="py-2.5 pr-3 font-mono text-[11px] text-emerald-300">{rec.recommendation}</td>
                    <td className="py-2.5 text-right">
                      <button
                        type="button"
                        onClick={() => handleSaveSurvivorToCodex(rec)}
                        className="rounded-lg border border-slate-700 bg-slate-800 px-2.5 py-1 text-[11px] font-medium text-emerald-300 hover:border-emerald-500"
                      >
                        Codex +
                      </button>
                    </td>
                  </tr>
                ))}
              </tbody>
            </table>
          </div>
        </div>
      )}
    </div>
  );
}
