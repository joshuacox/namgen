'use client';

import React, { useState } from 'react';

export default function Hero() {
  const [copied, setCopied] = useState(false);
  const installCmd = 'curl -s https://raw.githubusercontent.com/joshuacox/namgen/refs/heads/main/scripts/install.sh | sh';

  const copyToClipboard = () => {
    navigator.clipboard.writeText(installCmd);
    setCopied(true);
    setTimeout(() => setCopied(false), 2000);
  };

  return (
    <section className="relative overflow-hidden pt-12 pb-16 lg:pt-20 lg:pb-24 border-b border-slate-800">
      {/* Background glow effects */}
      <div className="absolute top-1/4 left-1/2 -translate-x-1/2 -translate-y-1/2 w-[600px] h-[350px] bg-emerald-500/10 rounded-full blur-3xl pointer-events-none -z-10" />
      <div className="absolute top-1/3 right-1/4 w-[400px] h-[250px] bg-cyan-500/10 rounded-full blur-3xl pointer-events-none -z-10" />

      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 text-center">
        {/* Release Tag */}
        <div className="inline-flex items-center gap-2 px-3 py-1 rounded-full text-xs sm:text-sm font-medium bg-emerald-500/10 border border-emerald-500/30 text-emerald-400 mb-6 shadow-inner">
          <span className="flex h-2 w-2 rounded-full bg-emerald-400 animate-pulse" />
          <span>v2.0 Released: 100% C++17 Conversion Complete</span>
        </div>

        {/* Main Heading */}
        <h1 className="text-4xl sm:text-5xl lg:text-6xl font-extrabold tracking-tight text-white max-w-4xl mx-auto leading-tight sm:leading-none">
          Zero-Allocation Name Generation for <span className="text-transparent bg-clip-text bg-gradient-to-r from-emerald-400 via-teal-300 to-cyan-400">Every Universe</span>
        </h1>

        {/* Subtitle */}
        <p className="mt-6 text-lg sm:text-xl text-slate-300 max-w-3xl mx-auto font-normal leading-relaxed">
          <strong className="text-white font-semibold">namgen</strong> is a high-performance command-line generator written in pure modern C++17. Combine customizable adjective and noun wordlists with custom casing, or invoke any of the <span className="text-emerald-400 font-semibold">907 built-in procedural generators</span> spanning 40 fantasy, sci-fi, historical, and gaming universes.
        </p>

        {/* Metrics Grid */}
        <div className="mt-8 grid grid-cols-2 sm:grid-cols-4 gap-3 sm:gap-4 max-w-3xl mx-auto">
          <div className="p-3.5 rounded-xl bg-slate-900/80 border border-slate-800 text-center">
            <div className="text-2xl sm:text-3xl font-bold text-emerald-400">907</div>
            <div className="text-xs text-slate-400 mt-1 uppercase font-semibold tracking-wider">Generators</div>
          </div>
          <div className="p-3.5 rounded-xl bg-slate-900/80 border border-slate-800 text-center">
            <div className="text-2xl sm:text-3xl font-bold text-cyan-400">40</div>
            <div className="text-xs text-slate-400 mt-1 uppercase font-semibold tracking-wider">Universes / Themes</div>
          </div>
          <div className="p-3.5 rounded-xl bg-slate-900/80 border border-slate-800 text-center">
            <div className="text-2xl sm:text-3xl font-bold text-emerald-400">0 B</div>
            <div className="text-xs text-slate-400 mt-1 uppercase font-semibold tracking-wider">Heap Allocations</div>
          </div>
          <div className="p-3.5 rounded-xl bg-slate-900/80 border border-slate-800 text-center">
            <div className="text-2xl sm:text-3xl font-bold text-cyan-400">18s</div>
            <div className="text-xs text-slate-400 mt-1 uppercase font-semibold tracking-wider">907 Batch Execution</div>
          </div>
        </div>

        {/* Quick Install Bar */}
        <div className="mt-8 max-w-xl mx-auto">
          <div className="flex items-center justify-between gap-3 p-2.5 sm:p-3 rounded-xl bg-slate-900/90 border border-slate-800 shadow-xl font-mono text-xs sm:text-sm">
            <div className="flex items-center gap-2 text-slate-300 overflow-x-auto whitespace-nowrap scrollbar-none pl-2">
              <span className="text-emerald-400 select-none">$</span>
              <span className="text-slate-200">{installCmd}</span>
            </div>
            <button
              type="button"
              onClick={copyToClipboard}
              className="flex-shrink-0 inline-flex items-center gap-1.5 px-3 py-1.5 rounded-lg text-xs font-medium bg-emerald-500 hover:bg-emerald-400 text-slate-950 transition-colors font-sans shadow"
            >
              {copied ? (
                <>
                  <svg className="w-3.5 h-3.5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                    <path strokeLinecap="round" strokeLinejoin="round" strokeWidth={2.5} d="M5 13l4 4L19 7" />
                  </svg>
                  <span>Copied!</span>
                </>
              ) : (
                <>
                  <svg className="w-3.5 h-3.5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                    <path strokeLinecap="round" strokeLinejoin="round" strokeWidth={2} d="M8 16H6a2 2 0 01-2-2V6a2 2 0 012-2h8a2 2 0 012 2v2m-6 12h8a2 2 0 002-2v-8a2 2 0 00-2-2h-8a2 2 0 00-2 2v8a2 2 0 002 2z" />
                  </svg>
                  <span>Copy</span>
                </>
              )}
            </button>
          </div>
        </div>

        {/* CTA Buttons */}
        <div className="mt-6 flex flex-wrap items-center justify-center gap-4">
          <a
            href="#simulator"
            className="inline-flex items-center gap-2 px-6 py-3 rounded-xl text-sm font-semibold bg-emerald-500 hover:bg-emerald-400 text-slate-950 transition-all shadow-lg shadow-emerald-500/20"
          >
            <span>Launch Simulator</span>
            <span>→</span>
          </a>
          <a
            href="#generators"
            className="inline-flex items-center gap-2 px-6 py-3 rounded-xl text-sm font-semibold bg-slate-900 hover:bg-slate-800 text-slate-200 border border-slate-700 hover:border-slate-600 transition-all"
          >
            <span>Explore 907 Generators</span>
          </a>
        </div>

        {/* Hero Graphic Frame */}
        <div className="mt-12 max-w-4xl mx-auto rounded-2xl overflow-hidden border border-emerald-500/30 shadow-2xl shadow-emerald-500/10 bg-slate-900/80">
          <div className="px-4 py-2.5 bg-slate-900 border-b border-slate-800 flex items-center justify-between text-xs text-slate-400 font-mono">
            <div className="flex items-center gap-2">
              <span className="w-2.5 h-2.5 rounded-full bg-red-500/80" />
              <span className="w-2.5 h-2.5 rounded-full bg-yellow-500/80" />
              <span className="w-2.5 h-2.5 rounded-full bg-green-500/80" />
              <span className="ml-2">namgen v2.0 // Procedural Universe Engine</span>
            </div>
            <span className="text-emerald-400 text-[11px]">C++17 • .rodata • Zero-Allocation</span>
          </div>
          <img
            src={`${process.env.NEXT_PUBLIC_BASE_PATH || ''}/images/hero-banner.jpg`}
            alt="namgen Procedural Fantasy and Sci-Fi Name Generator Interface"
            className="w-full h-auto object-cover"
            loading="eager"
          />
        </div>
      </div>
    </section>
  );
}
