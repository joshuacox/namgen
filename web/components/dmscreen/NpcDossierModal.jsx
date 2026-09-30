'use client';

import React, { useState } from 'react';
import { NPC_DATA } from './dmscreenData';

export default function NpcDossierModal({ character, onClose, onRerollName }) {
  const [dossierIndex, setDossierIndex] = useState(0);
  const [copied, setCopied] = useState(false);

  if (!character) return null;

  const appearance = NPC_DATA.appearances[dossierIndex % NPC_DATA.appearances.length];
  const trait = NPC_DATA.personalityTraits[dossierIndex % NPC_DATA.personalityTraits.length];
  const flaw = NPC_DATA.flaws[dossierIndex % NPC_DATA.flaws.length];
  const secret = NPC_DATA.darkSecrets[dossierIndex % NPC_DATA.darkSecrets.length];
  const quote = NPC_DATA.dialogueHooks[dossierIndex % NPC_DATA.dialogueHooks.length];

  const rerollTraits = () => {
    setDossierIndex((prev) => prev + 1);
    if (onRerollName) onRerollName(character.id);
  };

  const speak = (text) => {
    if (typeof window !== 'undefined' && 'speechSynthesis' in window && text) {
      window.speechSynthesis.cancel();
      const utterance = new SpeechSynthesisUtterance(text);
      utterance.rate = 0.85;
      window.speechSynthesis.speak(utterance);
    }
  };

  const copyMarkdown = async () => {
    let md = `### [[${character.name}]] — ${character.title}\n`;
    md += `* **Module Generator**: \`--${character.generator}\`\n`;
    md += `* **Appearance**: ${appearance}\n`;
    md += `* **Personality**: ${trait}\n`;
    md += `* **Flaw**: ${flaw}\n`;
    md += `* **Dark Secret / Hidden Motive**: ${secret}\n`;
    md += `* **Dialogue Hook**: *${quote}*\n`;

    await navigator.clipboard.writeText(md);
    setCopied(true);
    setTimeout(() => setCopied(false), 2000);
  };

  return (
    <div className="fixed inset-0 z-50 flex items-center justify-center p-4 bg-slate-950/80 backdrop-blur-sm animate-in fade-in duration-200">
      <div className="bg-slate-900 border border-slate-700/80 rounded-2xl shadow-2xl max-w-2xl w-full p-6 text-slate-100 relative max-h-[90vh] overflow-y-auto">
        {/* Header */}
        <div className="flex items-start justify-between border-b border-slate-800 pb-4 mb-5">
          <div className="flex items-center gap-3">
            <span className="text-4xl p-2 rounded-xl bg-slate-800/80 border border-slate-700">
              {character.icon}
            </span>
            <div>
              <span className="text-xs uppercase tracking-wider font-bold text-emerald-400">
                {character.title}
              </span>
              <h3 className="text-2xl font-extrabold text-white flex items-center gap-2">
                {character.name}
                <button
                  type="button"
                  onClick={() => speak(character.name)}
                  className="p-1 text-sm rounded bg-slate-800 hover:bg-slate-700 text-slate-300 hover:text-emerald-400 transition-colors"
                  title="Pronounce with speech synthesis"
                >
                  🔊
                </button>
              </h3>
            </div>
          </div>
          <button
            onClick={onClose}
            className="text-slate-400 hover:text-white p-1 rounded-lg hover:bg-slate-800 transition-colors text-lg"
          >
            ✕
          </button>
        </div>

        {/* Content Grid */}
        <div className="space-y-4 text-sm">
          {/* Visual Appearance */}
          <div className="bg-slate-950/60 border border-slate-800 rounded-xl p-3.5">
            <span className="text-xs uppercase font-bold text-slate-400 tracking-wider block mb-1">
              👁️ Visual Appearance &amp; Bearing
            </span>
            <p className="text-slate-200 leading-relaxed">{appearance}</p>
          </div>

          {/* Personality & Flaw */}
          <div className="grid grid-cols-1 sm:grid-cols-2 gap-3">
            <div className="bg-slate-950/60 border border-slate-800 rounded-xl p-3.5">
              <span className="text-xs uppercase font-bold text-teal-400 tracking-wider block mb-1">
                🎭 Personality Trait
              </span>
              <p className="text-slate-300">{trait}</p>
            </div>
            <div className="bg-slate-950/60 border border-slate-800 rounded-xl p-3.5">
              <span className="text-xs uppercase font-bold text-amber-400 tracking-wider block mb-1">
                ⚠️ Fatal Flaw / Quirk
              </span>
              <p className="text-slate-300">{flaw}</p>
            </div>
          </div>

          {/* Dark Secret / Plot Hook */}
          <div className="bg-red-950/20 border border-red-900/40 rounded-xl p-3.5">
            <span className="text-xs uppercase font-bold text-red-400 tracking-wider block mb-1">
              🗝️ Dark Secret / Campaign Motive
            </span>
            <p className="text-red-200/90 leading-relaxed">{secret}</p>
          </div>

          {/* Dialogue Hook */}
          <div className="bg-slate-950/60 border border-slate-800 rounded-xl p-3.5 italic text-slate-300">
            <span className="text-xs uppercase font-bold text-slate-400 not-italic tracking-wider block mb-1">
              💬 Opening Dialogue Hook
            </span>
            {quote}
          </div>
        </div>

        {/* Actions Footer */}
        <div className="mt-6 pt-4 border-t border-slate-800 flex flex-wrap items-center justify-between gap-3">
          <button
            type="button"
            onClick={rerollTraits}
            className="px-3.5 py-2 rounded-lg bg-emerald-500/10 hover:bg-emerald-500/20 text-emerald-400 font-semibold border border-emerald-500/30 transition-all flex items-center gap-1.5 text-xs sm:text-sm"
          >
            <span>🎲</span> Re-roll Dossier &amp; Name
          </button>

          <div className="flex items-center gap-2">
            <button
              type="button"
              onClick={copyMarkdown}
              className="px-3.5 py-2 rounded-lg bg-slate-800 hover:bg-slate-700 text-slate-200 text-xs sm:text-sm font-semibold border border-slate-700 transition-all flex items-center gap-1.5"
            >
              <span>{copied ? '✅' : '📋'}</span> {copied ? 'Copied Obsidian Note!' : 'Copy Obsidian Note'}
            </button>
            <button
              type="button"
              onClick={onClose}
              className="px-4 py-2 rounded-lg bg-slate-800 hover:bg-slate-700 text-slate-300 text-xs sm:text-sm font-medium transition-colors"
            >
              Close
            </button>
          </div>
        </div>
      </div>
    </div>
  );
}
