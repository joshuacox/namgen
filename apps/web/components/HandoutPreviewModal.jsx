'use client';

import React from 'react';
import { clearPlayerHandout } from '../lib/handoutChannel';

export default function HandoutPreviewModal({ handout, onClose }) {
  if (!handout) return null;

  return (
    <div
      className="fixed inset-0 z-50 flex items-center justify-center p-4 bg-slate-950/85 backdrop-blur-sm no-print"
      onClick={onClose}
    >
      <div
        className="w-full max-w-2xl bg-slate-900 border border-amber-500/40 rounded-2xl shadow-2xl overflow-hidden"
        onClick={(e) => e.stopPropagation()}
      >
        <div className="px-5 py-3.5 bg-slate-950 border-b border-slate-800 flex items-center justify-between">
          <div>
            <span className="text-[11px] font-mono uppercase tracking-wider text-amber-400">
              Spoiler-Free Player Screen Broadcast
            </span>
            <h3 className="text-base font-bold text-white">{handout.title}</h3>
          </div>
          <div className="flex items-center gap-2">
            <a
              href="/handout"
              target="_blank"
              rel="noreferrer"
              className="px-3 py-1.5 rounded-lg bg-amber-500 hover:bg-amber-400 text-slate-950 text-xs font-bold"
            >
              Open Second Screen ↗
            </a>
            <button
              type="button"
              onClick={() => {
                clearPlayerHandout();
                onClose();
              }}
              className="px-2.5 py-1.5 rounded-lg bg-slate-800 hover:bg-slate-700 text-slate-300 text-xs"
            >
              Clear Screen
            </button>
            <button
              type="button"
              onClick={onClose}
              className="text-slate-400 hover:text-white px-2 py-1"
            >
              ✕
            </button>
          </div>
        </div>

        <div className="p-6 space-y-4 max-h-[70vh] overflow-y-auto text-sm text-slate-200">
          {handout.subtitle && (
            <p className="text-amber-300 font-semibold text-xs uppercase tracking-wider">
              {handout.subtitle}
            </p>
          )}
          {handout.body && (
            <p className="whitespace-pre-wrap leading-relaxed text-slate-200">{handout.body}</p>
          )}
          {handout.quote && (
            <blockquote className="p-3 rounded-xl bg-slate-950 border-l-4 border-amber-400 italic text-slate-300">
              {handout.quote}
            </blockquote>
          )}
          {Array.isArray(handout.items) && handout.items.length > 0 && (
            <div className="border border-slate-800 rounded-xl overflow-hidden">
              <table className="w-full text-left text-xs">
                <thead className="bg-slate-950 text-slate-400 uppercase">
                  <tr>
                    <th className="px-3 py-2">Item / Service</th>
                    <th className="px-3 py-2 text-right">Price</th>
                  </tr>
                </thead>
                <tbody className="divide-y divide-slate-800">
                  {handout.items.map((row, idx) => (
                    <tr key={idx} className="bg-slate-900/50">
                      <td className="px-3 py-2 text-slate-100">
                        <div className="font-semibold">{row.label}</div>
                        {row.detail && <div className="text-[11px] text-slate-400">{row.detail}</div>}
                      </td>
                      <td className="px-3 py-2 text-right font-mono text-amber-300 whitespace-nowrap">
                        {row.price}
                      </td>
                    </tr>
                  ))}
                </tbody>
              </table>
            </div>
          )}
          <div className="text-[11px] text-slate-500 pt-2 border-t border-slate-800">
            DM secrets, dark motives, trap DCs, monster HP totals, and rumor veracity labels are automatically excluded.
          </div>
        </div>
      </div>
    </div>
  );
}
