'use client';

import React, { useEffect, useState } from 'react';
import { CHANNEL_NAME, STORAGE_KEY, readLatestHandout } from '../../lib/handoutChannel';

export default function PlayerHandoutPage() {
  const [handout, setHandout] = useState(null);

  useEffect(() => {
    setHandout(readLatestHandout());

    let channel = null;
    if ('BroadcastChannel' in window) {
      channel = new BroadcastChannel(CHANNEL_NAME);
      channel.onmessage = (evt) => {
        if (evt.data) setHandout(evt.data);
      };
    }

    const onStorage = (evt) => {
      if (evt.key === STORAGE_KEY && evt.newValue) {
        try {
          setHandout(JSON.parse(evt.newValue));
        } catch (_) {}
      }
    };
    window.addEventListener('storage', onStorage);

    return () => {
      if (channel) channel.close();
      window.removeEventListener('storage', onStorage);
    };
  }, []);

  if (!handout || handout.kind === 'idle') {
    return (
      <main className="min-h-screen flex flex-col items-center justify-center p-8 text-center">
        <div className="max-w-xl p-10 rounded-3xl bg-slate-900/70 border border-slate-800 shadow-2xl space-y-4">
          <div className="text-5xl">📜</div>
          <h1 className="text-3xl font-extrabold text-amber-300 tracking-tight">
            Player Handout Screen
          </h1>
          <p className="text-slate-300 text-sm leading-relaxed">
            Connected to your DM&apos;s private local table. Whenever the Dungeon Master clicks{' '}
            <strong className="text-white">Reveal to Players</strong> on an NPC, Tavern Menu, Relic,
            Prophecy, or Initiative Order, it appears here automatically with all DM secrets hidden.
          </p>
        </div>
      </main>
    );
  }

  return (
    <main className="min-h-screen flex flex-col items-center justify-center p-6 sm:p-12">
      <div className="w-full max-w-4xl p-8 sm:p-10 rounded-3xl bg-slate-900/85 border border-amber-500/30 shadow-2xl space-y-6">
        <div className="border-b border-slate-800 pb-5">
          {handout.subtitle && (
            <div className="text-xs font-mono uppercase tracking-widest text-amber-400 mb-2">
              {handout.subtitle}
            </div>
          )}
          <h1 className="text-3xl sm:text-5xl font-extrabold text-white tracking-tight">
            {handout.title}
          </h1>
        </div>

        {handout.body && (
          <p className="text-lg text-slate-200 leading-relaxed whitespace-pre-wrap">
            {handout.body}
          </p>
        )}

        {handout.quote && (
          <blockquote className="p-5 rounded-2xl bg-slate-950/90 border-l-4 border-amber-400 text-lg italic text-amber-100">
            {handout.quote}
          </blockquote>
        )}

        {Array.isArray(handout.items) && handout.items.length > 0 && (
          <div className="border border-slate-800 rounded-2xl overflow-hidden bg-slate-950/70">
            <table className="w-full text-left text-base">
              <thead className="bg-slate-950 text-slate-400 text-xs uppercase">
                <tr>
                  <th className="px-5 py-3">Entry</th>
                  <th className="px-5 py-3 text-right">Details</th>
                </tr>
              </thead>
              <tbody className="divide-y divide-slate-800">
                {handout.items.map((row, idx) => (
                  <tr key={idx} className={row.active ? 'bg-emerald-500/15' : ''}>
                    <td className="px-5 py-3 font-semibold text-white">
                      {row.active && <span className="text-emerald-400 mr-2">▶</span>}
                      {row.label}
                      {row.detail && (
                        <div className="text-xs font-normal text-slate-400 mt-0.5">{row.detail}</div>
                      )}
                    </td>
                    <td className="px-5 py-3 text-right font-mono text-amber-300 whitespace-nowrap">
                      {row.price}
                    </td>
                  </tr>
                ))}
              </tbody>
            </table>
          </div>
        )}
      </div>
    </main>
  );
}
