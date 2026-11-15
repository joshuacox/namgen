'use client';

import { useEffect, useRef, useState } from 'react';

const STORY_TOOLS = [
  {
    id: 'story-arc',
    label: 'Story Arc Weaver',
    icon: '🕸️',
    placeholder: 'Describe a quest seed, antagonist faction, or frontier conflict to weave into a 3-act campaign arc...',
    defaultPrompt: 'Weave a 3-act adventure arc in our current campaign setting involving a sunken star-forge, a splintered guild, and a ticking clock before the solstice.',
  },
  {
    id: 'scene-painter',
    label: 'Sensory Boxed-Text',
    icon: '🕯️',
    placeholder: 'Describe the room, tavern, street, or dungeon threshold you want read-aloud boxed text for...',
    defaultPrompt: 'Paint vivid read-aloud boxed text for players stepping into a rain-lashed harbor tavern lit by emerald alchemical lanterns, plus 3 interactive secrets hidden in the room.',
  },
  {
    id: 'npc-roleplay',
    label: 'Live NPC Roleplay & Co-DM',
    icon: '🎭',
    placeholder: 'Speak to the NPC in-character or ask the Agentic Co-DM to improvise names, rumors, or dice checks...',
    defaultPrompt: 'Take the persona of a weary dwarven locksmith hiding a secret guild ledger. Greet the party suspiciously, offer a bargain, and whisper a tavern rumor.',
  },
  {
    id: 'three-clue',
    label: 'Mystery & Three-Clue',
    icon: '🔍',
    placeholder: 'Describe the crime, conspiracy, or locked-room mystery to structure with 3-clue redundancy...',
    defaultPrompt: 'Build a solvable Three-Clue investigation around the disappearance of the town magistrate during the harvest festival, with physical, testimonial, and arcane clues.',
  },
  {
    id: 'boss-designer',
    label: 'Multi-Phase Boss',
    icon: '🐉',
    placeholder: 'Specify party tier, monster theme, terrain hazards, or boss concept...',
    defaultPrompt: 'Design a Level 5-7 two-phase tactical boss encounter inside a flooding clockwork belltower, complete with Phase 2 Bloodied transformation, Lair Actions on Init 20, and minion synergy.',
  },
  {
    id: 'handout-scribe',
    label: 'Handouts & Prophecies',
    icon: '📜',
    placeholder: 'Describe the letter, bounty notice, riddle, or prophecy you want drafted in-world...',
    defaultPrompt: 'Draft an ominous prophecy fragment etched onto cracked obsidian plus a three-stanza rhyming door riddle (and include a DM solution key at the very bottom).',
  },
  {
    id: 'session-recap',
    label: 'Recap & Lazy-DM Prep',
    icon: '📓',
    placeholder: 'Paste rough bullet notes from last session to generate a dramatic recap and Lazy-DM prep kit...',
    defaultPrompt: 'Turn rough session bullets into a "Previously on..." chronicle, 3 Strong Starts for tonight, and 5 discoverable Secrets & Clues.',
  },
];

export default function AiStorytellerWorkspace({
  settings,
  handoffContext,
  onClearHandoff,
  onOpenSettings,
  onSaveCodex,
  onAppendSessionNote,
  onRevealHandout,
  onSendToCombat,
  onNotify,
}) {
  const [activeTool, setActiveTool] = useState('story-arc');
  const [prompt, setPrompt] = useState(STORY_TOOLS[0].defaultPrompt);
  const [contextTitle, setContextTitle] = useState('');
  const [focusedContext, setFocusedContext] = useState('');
  const [includeVaultContext, setIncludeVaultContext] = useState(true);

  const [streaming, setStreaming] = useState(false);
  const [forging, setForging] = useState(false);
  const [activeModel, setActiveModel] = useState('');
  const [seeds, setSeeds] = useState([]);
  const [toolEvents, setToolEvents] = useState([]);
  const [thinkingText, setThinkingText] = useState('');
  const [messages, setMessages] = useState([]);
  const [errorBanner, setErrorBanner] = useState('');
  const abortRef = useRef(null);

  useEffect(() => {
    if (!handoffContext) return;
    if (handoffContext.tool) setActiveTool(handoffContext.tool);
    if (handoffContext.title) setContextTitle(handoffContext.title);
    if (handoffContext.prompt) setPrompt(handoffContext.prompt);
    if (handoffContext.contextText) setFocusedContext(handoffContext.contextText);
    setErrorBanner('');
  }, [handoffContext]);

  const currentSpec = STORY_TOOLS.find((t) => t.id === activeTool) || STORY_TOOLS[0];
  const latestAssistantText = [...messages].reverse().find((m) => m.role === 'assistant')?.content || '';

  async function handleRerollSeedsOnly() {
    const map = {
      'story-arc': ['tabletop-plot_hooks', 'tabletop-villain_schemes'],
      'scene-painter': ['places-inns', 'tabletop-tavern_rumors'],
      'npc-roleplay': ['descriptions-personalitys', 'tabletop-tavern_rumors'],
      'three-clue': ['tabletop-plot_hooks', 'tabletop-item_quirks'],
      'boss-designer': ['fantasy-dragons', 'tabletop-dungeon_traps'],
      'handout-scribe': ['descriptions-prophecys', 'tabletop-item_quirks'],
      'session-recap': ['tabletop-plot_hooks', 'fantasy-factions'],
    };
    const gens = map[activeTool] || ['tabletop-plot_hooks', 'tabletop-tavern_rumors'];
    try {
      const next = [];
      for (const gen of gens) {
        const res = await fetch('/api/namgen', {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify({ action: 'roll', generator: gen, count: 2 }),
        });
        const data = await res.json();
        if (data.names) next.push({ generator: gen, items: data.names, engine: data.engine });
      }
      setSeeds(next);
      onNotify?.('Refreshed C++17 procedural sparks.');
    } catch {}
  }

  async function runGeneration(customPrompt, keepHistory = false) {
    const userText = (customPrompt !== undefined ? customPrompt : prompt).trim();
    if (!userText || streaming) return;

    const ctrl = new AbortController();
    abortRef.current = ctrl;
    setStreaming(true);
    setErrorBanner('');
    setThinkingText('');

    const priorMsgs = keepHistory ? messages : [];
    const nextUserMsg = { role: 'user', content: userText };
    const nextConversation = [...priorMsgs, nextUserMsg];
    setMessages([...nextConversation, { role: 'assistant', content: '' }]);
    if (!keepHistory) setToolEvents([]);
    if (keepHistory) setPrompt('');

    try {
      const res = await fetch('/api/ollama', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        signal: ctrl.signal,
        body: JSON.stringify({
          action: 'chat-stream',
          tool: activeTool,
          prompt: userText,
          messages: nextConversation,
          campaignContext: focusedContext,
          includeVaultContext,
        }),
      });
      if (!res.ok) {
        const err = await res.json().catch(() => ({}));
        throw new Error(err.error || `HTTP ${res.status}`);
      }

      const reader = res.body.getReader();
      const decoder = new TextDecoder();
      let buf = '';
      let accText = '';

      const handleEvent = (ev, dataStr) => {
        let data = {};
        try { data = JSON.parse(dataStr); } catch { return; }
        if (ev === 'seeds' && Array.isArray(data.seeds)) {
          setSeeds(data.seeds);
        } else if (ev === 'model' && data.model) {
          setActiveModel(data.model);
        } else if (ev === 'token' && data.delta) {
          accText += data.delta;
          setMessages((prev) => {
            const copy = [...prev];
            copy[copy.length - 1] = { role: 'assistant', content: accText };
            return copy;
          });
        } else if (ev === 'thinking' && data.delta) {
          setThinkingText((t) => t + data.delta);
        } else if (ev === 'tool_call') {
          setToolEvents((prev) => [...prev, { type: 'call', name: data.name, args: data.args }]);
        } else if (ev === 'tool_result') {
          setToolEvents((prev) => [...prev, { type: 'result', name: data.name, result: data.result }]);
        } else if (ev === 'error') {
          setErrorBanner(data.message || 'Failed to connect to Ollama/LLM endpoint.');
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
          let lines = [];
          for (const line of chunk.split('\n')) {
            if (line.startsWith('event:')) ev = line.slice(6).trim();
            else if (line.startsWith('data:')) lines.push(line.slice(5).trim());
          }
          if (lines.length > 0) handleEvent(ev, lines.join('\n'));
        }
      }
    } catch (err) {
      if (err?.name !== 'AbortError') {
        setErrorBanner(err?.message || 'LLM request failed.');
      }
    } finally {
      setStreaming(false);
      abortRef.current = null;
    }
  }

  async function handleStructuredImport(kind) {
    if (!latestAssistantText.trim()) return;
    setForging(true);
    try {
      const res = await fetch('/api/ollama', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          action: 'structured-forge',
          kind,
          title: contextTitle || currentSpec.label,
          text: latestAssistantText,
        }),
      });
      const out = await res.json();
      if (!res.ok || !out.data) throw new Error(out.error || 'Import failed');

      if (kind === 'codex') {
        onSaveCodex?.({
          title: out.data.title || contextTitle || currentSpec.label,
          type: out.data.type || 'Lore',
          tags: Array.isArray(out.data.tags) ? out.data.tags : ['ai-storyteller'],
          summary: out.data.summary || latestAssistantText.slice(0, 1200),
        });
        onNotify?.(`Saved "${out.data.title || 'Story Note'}" to Campaign Codex.`);
      } else if (kind === 'handout') {
        onRevealHandout?.({
          title: out.data.title || contextTitle || 'Recovered Missive',
          subtitle: out.data.subtitle || 'Campaign Handout',
          body: out.data.body || latestAssistantText,
        });
      } else if (kind === 'combat') {
        const b = out.data.boss || {};
        const bossCombatant = {
          name: b.name || contextTitle || 'Phase Boss',
          side: 'enemy',
          ac: Number(b.ac) || 16,
          hp: Number(b.maxHp) || 120,
          maxHp: Number(b.maxHp) || 120,
          initiative: Number(b.init) || 14,
          initBonus: 2,
          notes: [b.phases, b.actions].filter(Boolean).join(' | '),
          conditions: [],
        };
        const minionCombatants = (out.data.minions || []).flatMap((m) =>
          Array.from({ length: Math.min(6, Number(m.count) || 1) }, (_, idx) => ({
            name: `${m.label || 'Minion'} #${idx + 1}`,
            side: 'enemy',
            ac: Number(m.ac) || 13,
            hp: Number(m.hp) || 24,
            maxHp: Number(m.hp) || 24,
            initiative: 10 + Math.floor(Math.random() * 6),
            conditions: [],
          }))
        );
        onSendToCombat?.([bossCombatant, ...minionCombatants]);
        onNotify?.(`Sent ${bossCombatant.name} (+${minionCombatants.length} minions) to Combat Tracker.`);
      }
    } catch (err) {
      onNotify?.(err?.message || 'Failed structured import', 'error');
    } finally {
      setForging(false);
    }
  }

  return (
    <div className="grid gap-6 lg:grid-cols-[260px_1fr]">
      {/* Left Sidebar: 7 DM AI Tools + Handoff Context */}
      <div className="space-y-4">
        <div className="rounded-2xl border border-slate-800 bg-slate-900/70 p-3">
          <div className="mb-2 px-1 text-[11px] font-bold uppercase tracking-wider text-slate-400">
            7 AI Dungeon Master Modes
          </div>
          <div className="space-y-1">
            {STORY_TOOLS.map((t) => (
              <button
                key={t.id}
                type="button"
                onClick={() => {
                  setActiveTool(t.id);
                  if (!focusedContext) setPrompt(t.defaultPrompt);
                }}
                className={`flex w-full items-center gap-2 rounded-xl px-3 py-2 text-left text-xs font-semibold transition ${
                  activeTool === t.id
                    ? 'border border-amber-500/50 bg-amber-500/15 text-amber-300'
                    : 'border border-transparent text-slate-300 hover:bg-slate-800/70 hover:text-white'
                }`}
              >
                <span>{t.icon}</span>
                <span>{t.label}</span>
              </button>
            ))}
          </div>
        </div>

        <div className="space-y-2 rounded-2xl border border-slate-800 bg-slate-900/70 p-4 text-xs">
          <div className="flex items-center justify-between">
            <span className="font-bold text-slate-200">Vault Context Grounding</span>
            <input
              type="checkbox"
              checked={includeVaultContext}
              onChange={(e) => setIncludeVaultContext(e.target.checked)}
              className="accent-amber-500"
            />
          </div>
          <p className="text-[11px] text-slate-400">
            Automatically shares active party roster & Codex highlights with Ollama for lore continuity.
          </p>
          <button
            type="button"
            onClick={onOpenSettings}
            className="mt-1 w-full rounded-lg border border-slate-700 bg-slate-950 px-3 py-1.5 text-left text-[11px] text-slate-300 hover:border-amber-500/50"
          >
            Model: {activeModel || settings?.model || 'Auto'} ({settings?.provider || 'ollama'})
          </button>
        </div>

        {focusedContext && (
          <div className="space-y-2 rounded-2xl border border-emerald-500/40 bg-emerald-500/10 p-3 text-xs">
            <div className="flex items-center justify-between font-bold text-emerald-300">
              <span>Vault Handoff: {contextTitle || 'Entity'}</span>
              <button
                type="button"
                onClick={() => {
                  setFocusedContext('');
                  setContextTitle('');
                  onClearHandoff?.();
                }}
                className="text-slate-400 hover:text-white"
              >
                ×
              </button>
            </div>
            <pre className="max-h-32 overflow-y-auto whitespace-pre-wrap font-sans text-[11px] text-slate-300">
              {focusedContext}
            </pre>
          </div>
        )}
      </div>

      {/* Main Co-DM Storyteller Pane */}
      <div className="space-y-4">
        {/* C++17 Procedural Seed Strip */}
        <div className="rounded-2xl border border-slate-800 bg-slate-900/70 p-4">
          <div className="mb-2 flex flex-wrap items-center justify-between gap-2">
            <div className="text-xs font-bold text-emerald-300">
              ⚡ C++17 Procedural Sparks ({currentSpec.label})
            </div>
            <button
              type="button"
              onClick={handleRerollSeedsOnly}
              className="rounded-lg border border-emerald-500/40 bg-emerald-500/15 px-3 py-1 text-xs font-medium text-emerald-300 hover:bg-emerald-500/25"
            >
              🎲 Re-Roll C++17 Seeds (No LLM Needed)
            </button>
          </div>
          {seeds.length === 0 ? (
            <p className="text-xs text-slate-400">
              Click <strong>Re-Roll C++17 Seeds</strong> or <strong>Invoke AI</strong> to auto-inject fresh plot hooks, tavern rumors, item quirks, or lore before generation.
            </p>
          ) : (
            <div className="grid gap-2 sm:grid-cols-2">
              {seeds.map((s) => (
                <div key={s.generator} className="rounded-xl border border-slate-800 bg-slate-950/70 p-2.5 text-xs">
                  <div className="mb-1 font-mono text-[10px] uppercase text-slate-400">
                    --{s.generator} ({s.engine})
                  </div>
                  <ul className="space-y-1 text-slate-200">
                    {s.items.map((item, idx) => (
                      <li key={idx}>• {item}</li>
                    ))}
                  </ul>
                </div>
              ))}
            </div>
          )}
        </div>

        {/* Error banner */}
        {errorBanner && (
          <div className="flex flex-wrap items-center justify-between gap-2 rounded-xl border border-rose-500/40 bg-rose-500/10 px-4 py-3 text-xs text-rose-200">
            <div>
              <strong>LLM Endpoint Unreachable:</strong> {errorBanner}
            </div>
            <button
              type="button"
              onClick={onOpenSettings}
              className="rounded-lg border border-rose-400/50 bg-slate-900 px-3 py-1 font-semibold text-white hover:bg-slate-800"
            >
              Configure Ollama URL
            </button>
          </div>
        )}

        {/* Agentic Tool Execution Log */}
        {toolEvents.length > 0 && (
          <div className="rounded-2xl border border-slate-800 bg-slate-950/70 p-3 text-xs">
            <div className="mb-1.5 font-mono text-[10px] font-bold uppercase text-amber-300">
              Live Co-DM Agentic Tool Calls
            </div>
            <div className="flex flex-wrap gap-2">
              {toolEvents.map((ev, i) => (
                <span key={i} className="rounded-lg border border-slate-800 bg-slate-900 px-2.5 py-1 font-mono text-[11px] text-slate-300">
                  {ev.type === 'call' ? `⚙ ${ev.name}(${JSON.stringify(ev.args)})` : `✓ ${ev.name} done`}
                </span>
              ))}
            </div>
          </div>
        )}

        {/* Transcript / Output Area */}
        <div className="min-h-[300px] space-y-4 rounded-2xl border border-slate-800 bg-slate-900/70 p-5">
          {messages.length === 0 ? (
            <div className="flex h-48 flex-col items-center justify-center text-center text-xs text-slate-500">
              <div className="mb-2 text-2xl">{currentSpec.icon}</div>
              <p className="max-w-md">
                Enter your creative prompt below or launch directly into <strong>{currentSpec.label}</strong>.
                Outputs stream live with agentic C++17 dice, Codex lookup, and namgen synthesis.
              </p>
            </div>
          ) : (
            <div className="space-y-4">
              {messages.map((m, idx) => (
                <div
                  key={idx}
                  className={`rounded-xl border p-4 text-sm leading-relaxed ${
                    m.role === 'user'
                      ? 'border-slate-800 bg-slate-950/80 text-slate-300'
                      : 'border-amber-500/30 bg-slate-950/40 text-slate-100'
                  }`}
                >
                  <div className="mb-1 font-mono text-[10px] uppercase tracking-wider text-slate-400">
                    {m.role === 'user' ? 'Dungeon Master' : `AI Co-DM (${activeModel || settings?.model || 'Ollama'})`}
                  </div>
                  <div className="whitespace-pre-wrap">{m.content || (streaming && idx === messages.length - 1 ? '...' : '')}</div>
                </div>
              ))}
              {thinkingText && (
                <details className="rounded-xl border border-slate-800 bg-slate-950/60 p-3 text-xs text-slate-400">
                  <summary className="cursor-pointer font-semibold text-slate-300">Model Reasoning Trace</summary>
                  <pre className="mt-2 whitespace-pre-wrap font-mono text-[11px]">{thinkingText}</pre>
                </details>
              )}
            </div>
          )}

          {/* Action Bar for latest AI output */}
          {latestAssistantText && !streaming && (
            <div className="flex flex-wrap items-center gap-2 border-t border-slate-800 pt-3 text-xs">
              <button
                type="button"
                disabled={forging}
                onClick={() => handleStructuredImport('codex')}
                className="rounded-lg border border-emerald-500/40 bg-emerald-500/15 px-3 py-1.5 font-semibold text-emerald-300 hover:bg-emerald-500/25 disabled:opacity-50"
              >
                📚 Save to Codex
              </button>
              <button
                type="button"
                onClick={() => {
                  onAppendSessionNote?.(`### ${contextTitle || currentSpec.label}\n\n${latestAssistantText}`);
                  onNotify?.('Appended output to Session Journal.');
                }}
                className="rounded-lg border border-slate-700 bg-slate-800 px-3 py-1.5 font-semibold text-slate-200 hover:border-emerald-500"
              >
                📓 Append to Session Notes
              </button>
              <button
                type="button"
                disabled={forging}
                onClick={() => handleStructuredImport('handout')}
                className="rounded-lg border border-amber-500/40 bg-amber-500/15 px-3 py-1.5 font-semibold text-amber-300 hover:bg-amber-500/25 disabled:opacity-50"
              >
                📜 Reveal `/handout`
              </button>
              <button
                type="button"
                disabled={forging}
                onClick={() => handleStructuredImport('combat')}
                className="rounded-lg border border-rose-500/40 bg-rose-500/15 px-3 py-1.5 font-semibold text-rose-300 hover:bg-rose-500/25 disabled:opacity-50"
              >
                ⚔️ Forge to Combat Tracker
              </button>
              <button
                type="button"
                onClick={() => {
                  navigator.clipboard?.writeText(latestAssistantText);
                  onNotify?.('Copied Markdown output.');
                }}
                className="ml-auto rounded-lg border border-slate-700 px-3 py-1.5 text-slate-300 hover:text-white"
              >
                📋 Copy Markdown
              </button>
            </div>
          )}
        </div>

        {/* Prompt Bar */}
        <div className="space-y-2 rounded-2xl border border-slate-800 bg-slate-900/70 p-4">
          <textarea
            rows={3}
            value={prompt}
            onChange={(e) => setPrompt(e.target.value)}
            placeholder={currentSpec.placeholder}
            className="w-full rounded-xl border border-slate-700 bg-slate-950 px-3 py-2 text-sm text-white placeholder-slate-500 focus:border-amber-500 focus:outline-none"
          />
          <div className="flex flex-wrap items-center justify-between gap-2">
            <div className="text-[11px] text-slate-400">
              Optional title tag:{' '}
              <input
                type="text"
                value={contextTitle}
                onChange={(e) => setContextTitle(e.target.value)}
                placeholder="e.g. Obsidian Spire Act II"
                className="ml-1 rounded border border-slate-800 bg-slate-950 px-2 py-0.5 text-slate-200"
              />
            </div>
            <div className="flex gap-2">
              {streaming ? (
                <button
                  type="button"
                  onClick={() => abortRef.current?.abort()}
                  className="rounded-xl bg-rose-600 px-4 py-2 text-xs font-bold text-white hover:bg-rose-500"
                >
                  ⏹ Stop
                </button>
              ) : (
                <>
                  {messages.length > 0 && (
                    <button
                      type="button"
                      onClick={() => runGeneration(prompt, true)}
                      disabled={!prompt.trim()}
                      className="rounded-xl border border-amber-500/50 bg-amber-500/15 px-4 py-2 text-xs font-bold text-amber-300 hover:bg-amber-500/25 disabled:opacity-50"
                    >
                      💬 Continue Thread
                    </button>
                  )}
                  <button
                    type="button"
                    onClick={() => runGeneration(prompt, false)}
                    disabled={!prompt.trim()}
                    className="rounded-xl bg-amber-500 px-5 py-2 text-xs font-bold text-slate-950 hover:bg-amber-400 disabled:opacity-50"
                  >
                    ✨ Generate Fresh Scene
                  </button>
                </>
              )}
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}
