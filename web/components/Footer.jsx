'use client';

import React from 'react';

export default function Footer() {
  return (
    <footer className="w-full bg-slate-950 border-t border-slate-800 text-slate-400 py-12">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div className="grid grid-cols-1 md:grid-cols-4 gap-8 mb-8">
          {/* Brand Info */}
          <div className="md:col-span-2">
            <div className="flex items-center gap-2.5 font-bold text-xl text-white mb-3">
              <span className="flex items-center justify-center w-8 h-8 rounded-lg bg-emerald-500/10 border border-emerald-500/30 text-emerald-400">
                ⚡
              </span>
              <span>namgen</span>
            </div>
            <p className="text-sm text-slate-400 max-w-sm mb-4 leading-relaxed">
              An ultra-fast, zero-allocation procedural name generator in pure C++17 with 907 modules spanning 40 universes.
            </p>
            <div className="text-xs text-slate-500">
              Released under the <a href="https://github.com/joshuacox/namgen/blob/main/LICENSE" className="text-slate-400 hover:text-white underline">GNU General Public License v3.0</a>.
            </div>
          </div>

          {/* Quick Links */}
          <div>
            <h4 className="text-sm font-bold uppercase tracking-wider text-slate-200 mb-3">Documentation</h4>
            <ul className="space-y-2 text-sm">
              <li><a href="#simulator" className="hover:text-emerald-400 transition-colors">Simulator</a></li>
              <li><a href="#installation" className="hover:text-emerald-400 transition-colors">Installation</a></li>
              <li><a href="#options" className="hover:text-emerald-400 transition-colors">CLI Options</a></li>
              <li><a href="#generators" className="hover:text-emerald-400 transition-colors">907 Generators</a></li>
              <li><a href="#architecture" className="hover:text-emerald-400 transition-colors">C++ Architecture</a></li>
            </ul>
          </div>

          {/* Project & Community */}
          <div>
            <h4 className="text-sm font-bold uppercase tracking-wider text-slate-200 mb-3">Project</h4>
            <ul className="space-y-2 text-sm">
              <li>
                <a
                  href="https://github.com/joshuacox/namgen"
                  target="_blank"
                  rel="noreferrer"
                  className="hover:text-emerald-400 transition-colors flex items-center gap-1.5"
                >
                  <span>GitHub Repository</span>
                  <span>↗</span>
                </a>
              </li>
              <li>
                <a
                  href="https://github.com/joshuacox/namgen/issues"
                  target="_blank"
                  rel="noreferrer"
                  className="hover:text-emerald-400 transition-colors flex items-center gap-1.5"
                >
                  <span>Issue Tracker</span>
                  <span>↗</span>
                </a>
              </li>
              <li>
                <a
                  href="https://github.com/joshuacox/namgen/blob/main/man/namgen.1"
                  target="_blank"
                  rel="noreferrer"
                  className="hover:text-emerald-400 transition-colors flex items-center gap-1.5"
                >
                  <span>Unix Manual Page</span>
                  <span>↗</span>
                </a>
              </li>
            </ul>
          </div>
        </div>

        <div className="pt-8 border-t border-slate-800/80 flex flex-col sm:flex-row items-center justify-between text-xs text-slate-500 gap-4">
          <div>
            © {new Date().getFullYear()} Joshua Cox & namgen contributors.
          </div>
          <div className="flex items-center gap-4">
            <span>Written in C++17</span>
            <span>•</span>
            <span>100% Zero-Allocation Tables</span>
            <span>•</span>
            <span>907 Modules</span>
          </div>
        </div>
      </div>
    </footer>
  );
}
