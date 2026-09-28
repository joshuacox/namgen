'use client';

import React from 'react';

export default function OptionsReference() {
  const cliOptions = [
    {
      flags: '-c, --count COUNT',
      description: 'Number of names to generate.',
      defaultVal: 'Terminal height, or 24',
    },
    {
      flags: '-S, --seed NUM',
      description: 'Seed random number generator deterministically for reproducible runs.',
      defaultVal: 'std::random_device{}()',
    },
    {
      flags: '-u, --unique',
      description: 'Ensure no duplicate names are emitted in the generated batch.',
      defaultVal: 'false',
    },
    {
      flags: '--json',
      description: 'Output results as a structured JSON array of strings.',
      defaultVal: 'false',
    },
    {
      flags: '--csv',
      description: 'Output results in CSV format with "name" column header.',
      defaultVal: 'false',
    },
    {
      flags: '--slug, --kebab',
      description: 'Convert generated names into URL-friendly lowercase kebab-case slugs.',
      defaultVal: 'false',
    },
    {
      flags: '-s, --separator SEP',
      description: 'Custom separator string inserted between adjective and noun.',
      defaultVal: '"-"',
    },
    {
      flags: '-x, --null-separator',
      description: 'Do not print separator string; directly concatenates words.',
      defaultVal: 'false',
    },
    {
      flags: '--cap, --capcasing',
      description: 'Capitalize the first letter of both adjective and noun (PascalCase / CapWords).',
      defaultVal: 'false',
    },
    {
      flags: '--camel, --camelcasing',
      description: 'Lower-case adjective, capitalize first letter of noun (camelCase style).',
      defaultVal: 'false',
    },
    {
      flags: '-a, --adj-file, --adj FILE',
      description: 'Path to custom adjective wordlist file (newline-delimited).',
      defaultVal: 'assets/adjectives/*.list',
    },
    {
      flags: '-n, --noun-file, --noun FILE',
      description: 'Path to custom noun wordlist file (newline-delimited).',
      defaultVal: 'assets/nouns/*.list',
    },
    {
      flags: '-e, --exclude STRING',
      description: 'Characters to strip from all generated words.',
      defaultVal: '"-\'"',
    },
    {
      flags: '--debug',
      description: 'Print debug diagnostics including word source paths and counters to stderr.',
      defaultVal: 'false',
    },
    {
      flags: '-h, --help',
      description: 'Display usage instructions and dynamically enumerate all 907 procedural generators.',
      defaultVal: '—',
    },
  ];

  const envOptions = [
    {
      name: 'SEED',
      description: 'Sets numeric seed for deterministic random number generation across runs.',
      defaultVal: 'None',
    },
    {
      name: 'SEPARATOR',
      description: 'Sets the default separator string (e.g. export SEPARATOR="_").',
      defaultVal: '"-"',
    },
    {
      name: 'NULL_SEPARATOR',
      description: 'When set to "true", disables the separator.',
      defaultVal: '"false"',
    },
    {
      name: 'CAPCASING',
      description: 'When set to "true", forces CapWords capitalization on both words.',
      defaultVal: '"false"',
    },
    {
      name: 'CAMELCASING',
      description: 'When set to "true", forces camelCase casing.',
      defaultVal: '"false"',
    },
    {
      name: 'COUNT',
      description: 'Overrides default count of generated names.',
      defaultVal: 'Terminal height',
    },
    {
      name: 'ADJ_FILE',
      description: 'Path to default adjective file.',
      defaultVal: 'Random pick from ADJ_FOLDER',
    },
    {
      name: 'NOUN_FILE',
      description: 'Path to default noun file.',
      defaultVal: 'Random pick from NOUN_FOLDER',
    },
    {
      name: 'ADJ_FOLDER',
      description: 'Directory path containing adjective wordlists.',
      defaultVal: '/usr/local/share/namgen/assets/adjectives',
    },
    {
      name: 'NOUN_FOLDER',
      description: 'Directory path containing noun wordlists.',
      defaultVal: '/usr/local/share/namgen/assets/nouns',
    },
    {
      name: 'EXCLUDE',
      description: 'Characters to strip from words.',
      defaultVal: '"-\'"',
    },
    {
      name: 'DEBUG',
      description: 'When set to "true", enables diagnostic stderr output.',
      defaultVal: '"false"',
    },
  ];

  return (
    <section id="options" className="py-20 border-b border-slate-800">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div className="text-center max-w-3xl mx-auto mb-16">
          <h2 className="text-xs uppercase font-bold tracking-wider text-emerald-400">CLI & Environment</h2>
          <p className="mt-2 text-3xl sm:text-4xl font-extrabold text-white">Options & Configuration Reference</p>
          <p className="mt-4 text-slate-300">
            Fine-tune output format, casing, and word sources through command flags or shell environment variables.
          </p>
        </div>

        {/* CLI Options Table */}
        <div className="mb-14">
          <h3 className="text-xl font-bold text-white mb-4 flex items-center gap-2">
            <span>Command-Line Options</span>
          </h3>
          <div className="overflow-x-auto rounded-2xl border border-slate-800 bg-slate-900/60 shadow-xl">
            <table className="w-full text-left text-sm text-slate-200">
              <thead className="bg-slate-950/80 text-xs uppercase font-semibold text-slate-400 border-b border-slate-800">
                <tr>
                  <th className="px-6 py-4">Option Flag</th>
                  <th className="px-6 py-4">Description</th>
                  <th className="px-6 py-4">Default</th>
                </tr>
              </thead>
              <tbody className="divide-y divide-slate-800/60 font-mono text-xs sm:text-sm">
                {cliOptions.map((opt, i) => (
                  <tr key={i} className="hover:bg-slate-800/40 transition-colors">
                    <td className="px-6 py-3.5 font-bold text-emerald-400 whitespace-nowrap">
                      {opt.flags}
                    </td>
                    <td className="px-6 py-3.5 font-sans text-slate-300 text-xs sm:text-sm">
                      {opt.description}
                    </td>
                    <td className="px-6 py-3.5 text-slate-400 whitespace-nowrap font-mono text-xs">
                      {opt.defaultVal}
                    </td>
                  </tr>
                ))}
              </tbody>
            </table>
          </div>
        </div>

        {/* Environment Variables Table */}
        <div>
          <h3 className="text-xl font-bold text-white mb-4 flex items-center gap-2">
            <span>Shell Environment Variables</span>
          </h3>
          <div className="overflow-x-auto rounded-2xl border border-slate-800 bg-slate-900/60 shadow-xl">
            <table className="w-full text-left text-sm text-slate-200">
              <thead className="bg-slate-950/80 text-xs uppercase font-semibold text-slate-400 border-b border-slate-800">
                <tr>
                  <th className="px-6 py-4">Variable Name</th>
                  <th className="px-6 py-4">Description</th>
                  <th className="px-6 py-4">Default Value</th>
                </tr>
              </thead>
              <tbody className="divide-y divide-slate-800/60 font-mono text-xs sm:text-sm">
                {envOptions.map((env, i) => (
                  <tr key={i} className="hover:bg-slate-800/40 transition-colors">
                    <td className="px-6 py-3.5 font-bold text-cyan-400 whitespace-nowrap">
                      ${env.name}
                    </td>
                    <td className="px-6 py-3.5 font-sans text-slate-300 text-xs sm:text-sm">
                      {env.description}
                    </td>
                    <td className="px-6 py-3.5 text-slate-400 font-mono text-xs">
                      {env.defaultVal}
                    </td>
                  </tr>
                ))}
              </tbody>
            </table>
          </div>
        </div>
      </div>
    </section>
  );
}
