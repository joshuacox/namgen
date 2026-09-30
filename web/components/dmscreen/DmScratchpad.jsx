'use client';

import React, { useState, useEffect } from 'react';

const STORAGE_KEY = 'namgen_dm_scratchpad';

const STARTER_NOTE = `# Session Notes: The Obsidian Reach
- Date: Campaign Session 1
- Active Objective: Infiltrate the Sunken Crypt and recover the Star-Blade.

## Combat & Encounter Notes
- [ ] Guard patrol round at midnight (DC 14 Stealth)
- [ ] Trap disarm on the iron door (DC 15 Sleight of Hand)

## NPC Interactions & Clues
- Barkeep whispered about strange blue flames in the marsh.
- Shady rogue offered map fragment for 25 gp.
`;

export default function DmScratchpad() {
  const [isOpen, setIsOpen] = useState(false);
  const [text, setText] = useState('');
  const [copied, setCopied] = useState(false);

  useEffect(() => {
    if (typeof window !== 'undefined') {
      const saved = localStorage.getItem(STORAGE_KEY);
      if (saved !== null) {
        setText(saved);
      } else {
        setText(STARTER_NOTE);
      }
    }
  }, []);

  const handleChange = (e) => {
    const val = e.target.value;
    setText(val);
    if (typeof window !== 'undefined') {
      localStorage.setItem(STORAGE_KEY, val);
    }
  };

  const copyNotes = async () => {
    await navigator.clipboard.writeText(text);
    setCopied(true);
    setTimeout(() => setCopied(false), 2000);
  };

  const downloadNotes = () => {
    const blob = new Blob([text], { type: 'text/markdown;charset=utf-8' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = `dm-scratchpad-session-${new Date().toISOString().slice(0, 10)}.md`;
    a.click();
    URL.revokeObjectURL(url);
  };

  const clearNotes = () => {
    if (window.confirm('Clear all scratchpad notes? This cannot be undone.')) {
      setText('');
      if (typeof window !== 'undefined') {
        localStorage.removeItem(STORAGE_KEY);
      }
    }
  };

  const insertSnippet = (snippet) => {
    const newText = text ? `${text}\n${snippet}` : snippet;
    setText(newText);
    if (typeof window !== 'undefined') {
      localStorage.setItem(STORAGE_KEY, newText);
    }
  };

  const wordCount = text.trim() ? text.trim().split(/\s+/).length : 0;

  return (
    <div className="fixed bottom-5 left-5 z-40">
      {/* Minimized Button */}
      {!isOpen && (
        <button
          onClick={() => setIsOpen(true)}
          className="flex items-center gap-2 px-4 py-3 bg-slate-900/90 hover:bg-slate-800 text-slate-200 font-bold rounded-full shadow-2xl border border-slate-700 hover:border-emerald-500/50 hover:scale-105 transition-all text-sm group"
          title="Open DM Scratchpad"
        >
          <span className="text-lg group-hover:scale-110 transition-transform">📝</span>
          <span>DM Scratchpad</span>
          {wordCount > 0 && (
            <span className="ml-1 px-2 py-0.5 rounded-full bg-slate-800 text-slate-400 font-mono text-xs">
              {wordCount}w
            </span>
          )}
        </button>
      )}

      {/* Expanded Modal / Floating Notepad */}
      {isOpen && (
        <div className="w-80 sm:w-[420px] h-[520px] bg-slate-950/95 border border-slate-700/80 rounded-2xl shadow-2xl backdrop-blur-xl flex flex-col overflow-hidden animate-in fade-in slide-in-from-bottom-5 duration-200">
          {/* Header */}
          <div className="flex items-center justify-between px-4 py-3 bg-slate-900/90 border-b border-slate-800">
            <div className="flex items-center gap-2">
              <span className="text-lg">📝</span>
              <span className="font-bold text-white text-sm">Live Session Scratchpad</span>
              <span className="text-[10px] text-emerald-400 font-mono bg-emerald-500/10 px-1.5 py-0.5 rounded">
                auto-saved
              </span>
            </div>
            <button
              onClick={() => setIsOpen(false)}
              className="text-slate-400 hover:text-white p-1 rounded-lg hover:bg-slate-800 transition-colors"
              title="Minimize scratchpad"
            >
              ✕
            </button>
          </div>

          {/* Quick Insert Actions */}
          <div className="px-3 py-2 bg-slate-900/40 border-b border-slate-800/80 flex items-center gap-1.5 overflow-x-auto text-[11px] font-medium text-slate-300">
            <span className="text-slate-500 text-[10px] uppercase font-bold mr-1">Insert:</span>
            <button
              onClick={() => insertSnippet(`- [ ] Task / Objective:`)}
              className="px-2 py-0.5 rounded bg-slate-800 hover:bg-slate-700 text-slate-300 transition-colors"
            >
              + Checkbox
            </button>
            <button
              onClick={() => insertSnippet(`### Encounter: \n- Enemies: \n- HP / AC: \n- Loot:`)}
              className="px-2 py-0.5 rounded bg-slate-800 hover:bg-slate-700 text-slate-300 transition-colors"
            >
              + Encounter
            </button>
            <button
              onClick={() => insertSnippet(`> **NPC Note**: [[Name]] — Attitude: Neutral, Clue: `)}
              className="px-2 py-0.5 rounded bg-slate-800 hover:bg-slate-700 text-slate-300 transition-colors"
            >
              + NPC Clue
            </button>
            <button
              onClick={() => insertSnippet(`* [${new Date().toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' })}] `)}
              className="px-2 py-0.5 rounded bg-slate-800 hover:bg-slate-700 text-slate-300 transition-colors"
            >
              + Time
            </button>
          </div>

          {/* Text Area */}
          <div className="flex-1 p-3 bg-slate-950">
            <textarea
              value={text}
              onChange={handleChange}
              placeholder="Jot down quick initiative orders, impromptu character names, hit points, or campaign secrets here..."
              className="w-full h-full bg-slate-900/60 border border-slate-800 rounded-xl p-3 text-slate-200 text-sm font-mono leading-relaxed resize-none focus:outline-none focus:border-emerald-500/50 focus:ring-1 focus:ring-emerald-500/30"
            />
          </div>

          {/* Footer Bar */}
          <div className="px-4 py-2.5 bg-slate-900/80 border-t border-slate-800 flex items-center justify-between text-xs text-slate-400">
            <div className="font-mono text-[11px]">
              {wordCount} words | {text.length} chars
            </div>
            <div className="flex items-center gap-2">
              <button
                onClick={clearNotes}
                className="hover:text-rose-400 transition-colors text-[11px] px-2 py-1 rounded hover:bg-slate-800"
                title="Clear all text"
              >
                Clear
              </button>
              <button
                onClick={copyNotes}
                className="px-2.5 py-1 bg-slate-800 hover:bg-slate-700 text-slate-200 rounded font-medium transition-colors flex items-center gap-1"
              >
                <span>{copied ? '✅' : '📋'}</span> {copied ? 'Copied' : 'Copy'}
              </button>
              <button
                onClick={downloadNotes}
                className="px-2.5 py-1 bg-emerald-500/20 hover:bg-emerald-500/30 text-emerald-300 rounded font-medium border border-emerald-500/30 transition-colors flex items-center gap-1"
                title="Download as Markdown"
              >
                <span>💾</span> Export .md
              </button>
            </div>
          </div>
        </div>
      )}
    </div>
  );
}
