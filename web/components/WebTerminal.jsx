'use client';

import React, { useState, useEffect, useRef } from 'react';

export default function WebTerminal() {
  const [history, setHistory] = useState([
    { type: 'system', text: 'namgen WebAssembly Runtime initialized (v1.0.0, 907 C++17 generators).' },
    { type: 'system', text: 'Type "namgen --help" or click any preset below to run real WebAssembly in your browser.' },
  ]);
  const [inputVal, setInputVal] = useState('');
  const [cmdHistory, setCmdHistory] = useState(['namgen --fantasy-dragons -c 3', 'namgen --help']);
  const [historyIdx, setHistoryIdx] = useState(-1);
  const [wasmModule, setWasmModule] = useState(null);
  const [loading, setLoading] = useState(true);
  const [statusText, setStatusText] = useState('Loading WebAssembly runtime...');

  const terminalEndRef = useRef(null);
  const inputRef = useRef(null);

  // Load Emscripten WASM module
  useEffect(() => {
    let isMounted = true;

    async function loadWasm() {
      try {
        if (!window.createNamgen) {
          // Dynamically load the /wasm/namgen.js script
          const script = document.createElement('script');
          script.src = '/wasm/namgen.js';
          script.async = true;
          document.body.appendChild(script);

          await new Promise((resolve, reject) => {
            script.onload = resolve;
            script.onerror = () => reject(new Error('Failed to load /wasm/namgen.js'));
          });
        }

        if (window.createNamgen && isMounted) {
          const mod = await window.createNamgen({
            locateFile: (file) => `/wasm/${file}`,
            noInitialRun: true,
          });
          if (isMounted) {
            setWasmModule(mod);
            setLoading(false);
            setStatusText('namgen.wasm Ready (14MB / 907 engines in Memory)');
          }
        }
      } catch (err) {
        console.error('Failed to initialize namgen WASM:', err);
        if (isMounted) {
          setStatusText('WASM Error: ' + err.message);
          setLoading(false);
        }
      }
    }

    loadWasm();

    return () => {
      isMounted = false;
    };
  }, []);

  useEffect(() => {
    terminalEndRef.current?.scrollIntoView({ behavior: 'smooth' });
  }, [history]);

  const executeCommand = (cmdStr) => {
    const trimmed = cmdStr.trim();
    if (!trimmed) return;

    // Add command line to terminal output
    const newLines = [{ type: 'input', text: `$ ${trimmed}` }];

    if (trimmed === 'clear') {
      setHistory([]);
      setInputVal('');
      return;
    }

    if (!wasmModule) {
      newLines.push({ type: 'error', text: 'Error: WebAssembly module is still loading...' });
      setHistory((prev) => [...prev, ...newLines]);
      setInputVal('');
      return;
    }

    // Parse arguments
    let args = [];
    if (trimmed.startsWith('namgen')) {
      const matchRegex = /[^\s"']+|"([^"]*)"|'([^']*)'/g;
      let match;
      const parsed = [];
      while ((match = matchRegex.exec(trimmed.slice(6).trim())) !== null) {
        parsed.push(match[1] || match[2] || match[0]);
      }
      args = parsed;
    } else {
      newLines.push({ type: 'error', text: `bash: ${trimmed}: command not found (try "namgen [options]")` });
      setHistory((prev) => [...prev, ...newLines]);
      setInputVal('');
      return;
    }

    // Capture stdout and stderr
    const outputBuffer = [];
    const origPrint = wasmModule.print;
    const origPrintErr = wasmModule.printErr;

    wasmModule.print = (text) => outputBuffer.push({ type: 'output', text });
    wasmModule.printErr = (text) => outputBuffer.push({ type: 'error', text });

    try {
      wasmModule.callMain(args);
    } catch (e) {
      if (e && e.name !== 'ExitStatus') {
        outputBuffer.push({ type: 'error', text: String(e) });
      }
    } finally {
      wasmModule.print = origPrint;
      wasmModule.printErr = origPrintErr;
    }

    setHistory((prev) => [...prev, ...newLines, ...outputBuffer]);
    setCmdHistory((prev) => [trimmed, ...prev.filter((c) => c !== trimmed)]);
    setHistoryIdx(-1);
    setInputVal('');
  };

  const handleKeyDown = (e) => {
    if (e.key === 'Enter') {
      executeCommand(inputVal);
    } else if (e.key === 'ArrowUp') {
      e.preventDefault();
      if (cmdHistory.length > 0 && historyIdx + 1 < cmdHistory.length) {
        const nextIdx = historyIdx + 1;
        setHistoryIdx(nextIdx);
        setInputVal(cmdHistory[nextIdx]);
      }
    } else if (e.key === 'ArrowDown') {
      e.preventDefault();
      if (historyIdx > 0) {
        const nextIdx = historyIdx - 1;
        setHistoryIdx(nextIdx);
        setInputVal(cmdHistory[nextIdx]);
      } else if (historyIdx === 0) {
        setHistoryIdx(-1);
        setInputVal('');
      }
    }
  };

  const presets = [
    'namgen --fantasy-dragons -c 4',
    'namgen --compose "fantasy-dragons,places-castles" -c 3',
    'namgen --match "^[A-Z][a-z]+th$" --fantasy-dragons -c 4',
    'namgen --fantasy-elfs -c 3 --json',
    'namgen -c 3 --slug',
    'clear',
  ];

  return (
    <section id="terminal" className="py-20 border-b border-slate-800 bg-slate-950/70">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div className="text-center max-w-3xl mx-auto mb-10">
          <div className="inline-flex items-center gap-2 px-3 py-1 rounded-full text-xs font-semibold bg-emerald-500/10 text-emerald-400 border border-emerald-500/20 mb-3">
            <span className="w-2 h-2 rounded-full bg-emerald-400 animate-pulse" />
            Zero-Install In-Browser CLI
          </div>
          <h2 className="text-3xl sm:text-4xl font-extrabold text-white">
            Interactive WebAssembly Terminal
          </h2>
          <p className="mt-3 text-slate-400 text-sm sm:text-base">
            Execute real C++17 <code className="text-emerald-400">namgen</code> commands directly inside your browser. No terminal, compiler, or server round-trip required.
          </p>
        </div>

        {/* Preset buttons */}
        <div className="flex flex-wrap items-center justify-center gap-2 mb-6">
          <span className="text-xs font-semibold text-slate-500 uppercase tracking-wider mr-2">Try Presets:</span>
          {presets.map((preset) => (
            <button
              key={preset}
              type="button"
              onClick={() => executeCommand(preset)}
              className="px-3 py-1.5 rounded-lg text-xs font-mono bg-slate-900 border border-slate-800 text-emerald-400 hover:border-emerald-500/50 hover:bg-slate-800 transition-all"
            >
              {preset}
            </button>
          ))}
        </div>

        {/* Terminal Window */}
        <div className="max-w-4xl mx-auto rounded-2xl bg-slate-950 border border-slate-800 shadow-2xl overflow-hidden">
          {/* Title Bar */}
          <div className="flex items-center justify-between px-4 py-3 bg-slate-900/90 border-b border-slate-800">
            <div className="flex items-center gap-2">
              <span className="w-3 h-3 rounded-full bg-red-500/80" />
              <span className="w-3 h-3 rounded-full bg-yellow-500/80" />
              <span className="w-3 h-3 rounded-full bg-green-500/80" />
              <span className="ml-2 text-xs font-mono text-slate-400">wasm-sh — namgen.wasm (C++17 Emscripten)</span>
            </div>
            <div className="text-xs font-mono text-slate-400 flex items-center gap-1.5">
              <span className={`w-2 h-2 rounded-full ${loading ? 'bg-amber-400 animate-pulse' : 'bg-emerald-400'}`} />
              {statusText}
            </div>
          </div>

          {/* Console Area */}
          <div
            className="p-6 font-mono text-xs sm:text-sm h-96 overflow-y-auto space-y-1 bg-black/60 select-text"
            onClick={() => inputRef.current?.focus()}
          >
            {history.map((item, idx) => (
              <div
                key={idx}
                className={
                  item.type === 'input'
                    ? 'text-emerald-400 font-bold'
                    : item.type === 'error'
                    ? 'text-red-400'
                    : item.type === 'system'
                    ? 'text-slate-500 italic'
                    : 'text-slate-200'
                }
              >
                {item.text}
              </div>
            ))}
            <div ref={terminalEndRef} />
          </div>

          {/* Input Prompt */}
          <div className="flex items-center px-4 py-3 bg-slate-900 border-t border-slate-800 gap-2">
            <span className="text-emerald-400 font-mono font-bold">$</span>
            <input
              ref={inputRef}
              type="text"
              value={inputVal}
              onChange={(e) => setInputVal(e.target.value)}
              onKeyDown={handleKeyDown}
              placeholder="namgen --fantasy-dragons -c 5 (or 'namgen --help')"
              className="flex-1 bg-transparent text-white font-mono text-sm focus:outline-none placeholder-slate-600"
              disabled={loading}
            />
            <button
              type="button"
              onClick={() => executeCommand(inputVal)}
              disabled={loading || !inputVal.trim()}
              className="px-3 py-1 bg-emerald-500 hover:bg-emerald-400 disabled:opacity-40 text-slate-950 font-bold rounded text-xs transition-colors"
            >
              Run
            </button>
          </div>
        </div>
      </div>
    </section>
  );
}
