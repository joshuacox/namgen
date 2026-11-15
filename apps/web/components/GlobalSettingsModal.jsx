'use client';

import { useEffect, useState } from 'react';

export default function GlobalSettingsModal({
  isOpen,
  onClose,
  initialSettings,
  cppEngine,
  onSaved,
  onNotify,
}) {
  const [form, setForm] = useState({
    provider: 'ollama',
    baseUrl: 'http://127.0.0.1:11434',
    model: '',
    apiKey: '',
    temperature: 0.75,
    numCtx: 8192,
    githubToken: '',
    usptoCsvPath: '',
    preferCppBinary: true,
  });
  const [models, setModels] = useState([]);
  const [testing, setTesting] = useState(false);
  const [saving, setSaving] = useState(false);
  const [testResult, setTestResult] = useState(null);

  useEffect(() => {
    if (isOpen && initialSettings) {
      setForm({
        provider: initialSettings.provider || 'ollama',
        baseUrl: initialSettings.baseUrl || 'http://127.0.0.1:11434',
        model: initialSettings.model || '',
        apiKey: initialSettings.apiKey || '',
        temperature: initialSettings.temperature ?? 0.75,
        numCtx: initialSettings.numCtx ?? 8192,
        githubToken: initialSettings.githubToken || '',
        usptoCsvPath: initialSettings.usptoCsvPath || '',
        preferCppBinary: initialSettings.preferCppBinary !== false,
      });
      setTestResult(null);
    }
  }, [isOpen, initialSettings]);

  if (!isOpen) return null;

  async function handleTestConnection() {
    setTesting(true);
    setTestResult(null);
    try {
      const res = await fetch('/api/ollama', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          action: 'test',
          provider: form.provider,
          baseUrl: form.baseUrl,
          apiKey: form.apiKey,
        }),
      });
      const data = await res.json();
      setTestResult(data);
      if (data.ok && Array.isArray(data.models)) {
        setModels(data.models);
        if (!form.model && data.models[0]?.name) {
          setForm((prev) => ({ ...prev, model: data.models[0].name }));
        }
      }
    } catch (err) {
      setTestResult({ ok: false, error: err?.message || 'Test request failed', models: [] });
    } finally {
      setTesting(false);
    }
  }

  async function handleSave(e) {
    e.preventDefault();
    setSaving(true);
    try {
      const res = await fetch('/api/settings', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(form),
      });
      const data = await res.json();
      if (!res.ok) throw new Error(data.error || 'Save failed');
      onSaved?.(data.settings, data.cppEngine);
      onNotify?.('Global AI & Oracle settings saved to local vault.');
      onClose();
    } catch (err) {
      onNotify?.(err?.message || 'Failed to save settings', 'error');
    } finally {
      setSaving(false);
    }
  }

  return (
    <div className="fixed inset-0 z-50 flex items-center justify-center bg-black/75 p-4 backdrop-blur-sm">
      <div className="max-h-[90vh] w-full max-w-2xl overflow-y-auto rounded-2xl border border-slate-700 bg-slate-900 shadow-2xl">
        <div className="sticky top-0 z-10 flex items-center justify-between border-b border-slate-800 bg-slate-900/95 px-6 py-4 backdrop-blur">
          <div>
            <h2 className="text-lg font-bold text-white">AI & Registry Oracle Settings</h2>
            <p className="text-xs text-slate-400">
              Persisted locally in <code className="text-emerald-400">.namgen-dm/settings.json</code>. Calls are proxied server-side (no browser CORS limits).
            </p>
          </div>
          <button
            type="button"
            onClick={onClose}
            className="rounded-lg border border-slate-700 px-3 py-1.5 text-xs font-medium text-slate-300 hover:bg-slate-800"
          >
            Close
          </button>
        </div>

        <form onSubmit={handleSave} className="space-y-6 p-6">
          {/* Provider & Endpoint */}
          <div className="space-y-3 rounded-xl border border-slate-800 bg-slate-950/60 p-4">
            <div className="flex flex-wrap items-center justify-between gap-2">
              <span className="text-xs font-semibold uppercase tracking-wider text-amber-400">
                1. Local / LAN LLM Connection
              </span>
              <div className="flex rounded-lg border border-slate-800 bg-slate-900 p-0.5 text-xs">
                <button
                  type="button"
                  onClick={() =>
                    setForm((p) => ({
                      ...p,
                      provider: 'ollama',
                      baseUrl: p.baseUrl.includes('/v1') ? 'http://127.0.0.1:11434' : p.baseUrl,
                    }))
                  }
                  className={`rounded-md px-3 py-1 font-medium transition ${
                    form.provider === 'ollama' ? 'bg-amber-500/20 text-amber-300' : 'text-slate-400 hover:text-white'
                  }`}
                >
                  Native Ollama (/api)
                </button>
                <button
                  type="button"
                  onClick={() =>
                    setForm((p) => ({
                      ...p,
                      provider: 'openai',
                      baseUrl: p.baseUrl === 'http://127.0.0.1:11434' ? 'http://127.0.0.1:11434/v1' : p.baseUrl,
                    }))
                  }
                  className={`rounded-md px-3 py-1 font-medium transition ${
                    form.provider === 'openai' ? 'bg-amber-500/20 text-amber-300' : 'text-slate-400 hover:text-white'
                  }`}
                >
                  OpenAI-Compatible (/v1)
                </button>
              </div>
            </div>

            <div className="grid gap-3 sm:grid-cols-[1fr_auto]">
              <div>
                <label className="mb-1 block text-xs font-medium text-slate-300">Ollama / LLM Base URL</label>
                <input
                  type="url"
                  value={form.baseUrl}
                  onChange={(e) => setForm((p) => ({ ...p, baseUrl: e.target.value }))}
                  placeholder="http://127.0.0.1:11434"
                  className="w-full rounded-lg border border-slate-700 bg-slate-900 px-3 py-2 text-sm text-slate-100 placeholder-slate-500 focus:border-amber-500 focus:outline-none"
                />
              </div>
              <div className="flex items-end">
                <button
                  type="button"
                  onClick={handleTestConnection}
                  disabled={testing}
                  className="w-full rounded-lg border border-amber-500/40 bg-amber-500/15 px-4 py-2 text-sm font-semibold text-amber-300 hover:bg-amber-500/25 disabled:opacity-50"
                >
                  {testing ? 'Probing...' : 'Test & Fetch Models'}
                </button>
              </div>
            </div>

            <div className="flex flex-wrap gap-1.5 text-[11px] text-slate-400">
              <span>Quick Presets:</span>
              <button
                type="button"
                onClick={() => setForm((p) => ({ ...p, provider: 'ollama', baseUrl: 'http://127.0.0.1:11434' }))}
                className="rounded border border-slate-700 px-2 py-0.5 hover:border-slate-500 hover:text-white"
              >
                Local Ollama (11434)
              </button>
              <button
                type="button"
                onClick={() => setForm((p) => ({ ...p, provider: 'openai', baseUrl: 'http://127.0.0.1:1234/v1' }))}
                className="rounded border border-slate-700 px-2 py-0.5 hover:border-slate-500 hover:text-white"
              >
                LM Studio (1234/v1)
              </button>
              <button
                type="button"
                onClick={() => setForm((p) => ({ ...p, provider: 'openai', baseUrl: 'http://127.0.0.1:8080/v1' }))}
                className="rounded border border-slate-700 px-2 py-0.5 hover:border-slate-500 hover:text-white"
              >
                llama.cpp Server (8080/v1)
              </button>
            </div>

            {testResult && (
              <div
                className={`rounded-lg border px-3 py-2 text-xs ${
                  testResult.ok
                    ? 'border-emerald-500/40 bg-emerald-500/10 text-emerald-300'
                    : 'border-rose-500/40 bg-rose-500/10 text-rose-300'
                }`}
              >
                {testResult.ok
                  ? `Connected in ${testResult.latencyMs}ms — found ${testResult.models.length} model(s) on ${testResult.baseUrl}.`
                  : testResult.error}
              </div>
            )}

            <div className="grid gap-3 sm:grid-cols-2">
              <div>
                <label className="mb-1 block text-xs font-medium text-slate-300">Model Selection</label>
                {models.length > 0 ? (
                  <select
                    value={form.model}
                    onChange={(e) => setForm((p) => ({ ...p, model: e.target.value }))}
                    className="w-full rounded-lg border border-slate-700 bg-slate-900 px-3 py-2 text-sm text-slate-100 focus:border-amber-500 focus:outline-none"
                  >
                    <option value="">Auto-pick first loaded model</option>
                    {models.map((m) => (
                      <option key={m.name} value={m.name}>
                        {m.name} {m.parameterSize ? `(${m.parameterSize})` : ''}
                      </option>
                    ))}
                  </select>
                ) : (
                  <input
                    type="text"
                    value={form.model}
                    onChange={(e) => setForm((p) => ({ ...p, model: e.target.value }))}
                    placeholder="e.g. llama3.2, qwen2.5:14b, mistral"
                    className="w-full rounded-lg border border-slate-700 bg-slate-900 px-3 py-2 text-sm text-slate-100 placeholder-slate-500 focus:border-amber-500 focus:outline-none"
                  />
                )}
              </div>

              <div>
                <label className="mb-1 block text-xs font-medium text-slate-300">
                  Optional Bearer API Key
                </label>
                <div className="flex gap-1.5">
                  <input
                    type="password"
                    value={form.apiKey}
                    onChange={(e) => setForm((p) => ({ ...p, apiKey: e.target.value }))}
                    placeholder="Optional (OpenAI / secured proxy)"
                    className="w-full rounded-lg border border-slate-700 bg-slate-900 px-3 py-2 text-sm text-slate-100 placeholder-slate-500 focus:border-amber-500 focus:outline-none"
                  />
                  {form.apiKey && (
                    <button
                      type="button"
                      onClick={() => setForm((p) => ({ ...p, apiKey: '' }))}
                      className="rounded-lg border border-slate-700 px-2.5 text-xs text-slate-400 hover:text-white"
                    >
                      Clear
                    </button>
                  )}
                </div>
              </div>
            </div>

            <div className="grid gap-4 sm:grid-cols-2">
              <div>
                <div className="mb-1 flex justify-between text-xs text-slate-300">
                  <span>Temperature</span>
                  <span className="font-mono text-amber-300">{form.temperature}</span>
                </div>
                <input
                  type="range"
                  min="0"
                  max="1.5"
                  step="0.05"
                  value={form.temperature}
                  onChange={(e) => setForm((p) => ({ ...p, temperature: Number(e.target.value) }))}
                  className="w-full accent-amber-500"
                />
              </div>

              <div>
                <label className="mb-1 block text-xs font-medium text-slate-300">Context Window (Ollama `num_ctx`)</label>
                <select
                  value={form.numCtx}
                  onChange={(e) => setForm((p) => ({ ...p, numCtx: Number(e.target.value) }))}
                  className="w-full rounded-lg border border-slate-700 bg-slate-900 px-3 py-1.5 text-sm text-slate-100"
                >
                  {[2048, 4096, 8192, 16384, 32768].map((n) => (
                    <option key={n} value={n}>
                      {n.toLocaleString()} tokens
                    </option>
                  ))}
                </select>
              </div>
            </div>
          </div>

          {/* Registry & Engine Settings */}
          <div className="space-y-3 rounded-xl border border-slate-800 bg-slate-950/60 p-4">
            <span className="text-xs font-semibold uppercase tracking-wider text-emerald-400">
              2. Namespace Oracle & C++17 Native Acceleration
            </span>

            <div>
              <label className="mb-1 block text-xs font-medium text-slate-300">
                GitHub PAT (<code className="text-emerald-400">GITHUB_TOKEN</code>, raises rate limit from 60/hr to 5,000/hr)
              </label>
              <div className="flex gap-1.5">
                <input
                  type="password"
                  value={form.githubToken}
                  onChange={(e) => setForm((p) => ({ ...p, githubToken: e.target.value }))}
                  placeholder="Zero-scope fine-grained PAT (optional)"
                  className="w-full rounded-lg border border-slate-700 bg-slate-900 px-3 py-2 text-sm text-slate-100 placeholder-slate-500 focus:border-emerald-500 focus:outline-none"
                />
                {form.githubToken && (
                  <button
                    type="button"
                    onClick={() => setForm((p) => ({ ...p, githubToken: '' }))}
                    className="rounded-lg border border-slate-700 px-2.5 text-xs text-slate-400 hover:text-white"
                  >
                    Clear
                  </button>
                )}
              </div>
            </div>

            <div>
              <label className="mb-1 block text-xs font-medium text-slate-300">
                Optional Local USPTO Case Files CSV Path (<code>mark_id_char</code> bulk scan)
              </label>
              <input
                type="text"
                value={form.usptoCsvPath}
                onChange={(e) => setForm((p) => ({ ...p, usptoCsvPath: e.target.value }))}
                placeholder="/path/to/uspto_case_files.csv (optional)"
                className="w-full rounded-lg border border-slate-700 bg-slate-900 px-3 py-2 text-sm text-slate-100 placeholder-slate-500 focus:border-emerald-500 focus:outline-none"
              />
            </div>

            <div className="flex items-center justify-between rounded-lg border border-slate-800 bg-slate-900/70 px-3 py-2.5">
              <div>
                <div className="text-xs font-semibold text-white">Prefer C++17 Native Binary (./namgen)</div>
                <div className="text-[11px] text-slate-400">
                  {cppEngine?.available
                    ? `Detected: ${cppEngine.binaryPath} (${cppEngine.generatorCount} generators)`
                    : 'Native ./namgen binary not built — using Node/JS engine'}
                </div>
              </div>
              <input
                type="checkbox"
                checked={form.preferCppBinary}
                onChange={(e) => setForm((p) => ({ ...p, preferCppBinary: e.target.checked }))}
                className="h-4 w-4 accent-emerald-500"
              />
            </div>
          </div>

          <div className="flex justify-end gap-3 border-t border-slate-800 pt-4">
            <button
              type="button"
              onClick={onClose}
              className="rounded-lg border border-slate-700 px-4 py-2 text-sm font-medium text-slate-300 hover:bg-slate-800"
            >
              Cancel
            </button>
            <button
              type="submit"
              disabled={saving}
              className="rounded-lg bg-emerald-600 px-5 py-2 text-sm font-semibold text-white hover:bg-emerald-500 disabled:opacity-50"
            >
              {saving ? 'Saving...' : 'Save Settings'}
            </button>
          </div>
        </form>
      </div>
    </div>
  );
}
