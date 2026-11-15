'use strict';

function normalizeBaseUrl(rawUrl, provider) {
  let clean = String(rawUrl || 'http://127.0.0.1:11434').trim().replace(/\/+$/, '');
  if (provider === 'ollama') {
    clean = clean.replace(/\/v1$/i, '');
  }
  return clean || 'http://127.0.0.1:11434';
}

function buildAuthHeaders(settings) {
  const headers = { 'Content-Type': 'application/json' };
  if (settings?.customHeaders && typeof settings.customHeaders === 'object') {
    for (const [k, v] of Object.entries(settings.customHeaders)) {
      if (k && v !== undefined && v !== null) {
        headers[String(k)] = String(v);
      }
    }
  }
  if (settings?.apiKey) {
    headers.Authorization = `Bearer ${settings.apiKey}`;
  }
  return headers;
}

function stripThinkingBlocks(text) {
  if (!text) return '';
  let out = String(text).replace(/<think>[\s\S]*?<\/think>/gi, '');
  // Also trim an unclosed <think> tail if a model stopped mid-thought
  out = out.replace(/<think>[\s\S]*$/gi, '');
  return out.trim();
}

function extractJsonPayload(rawText) {
  const cleaned = stripThinkingBlocks(rawText)
    .replace(/```json\s*/gi, '')
    .replace(/```\s*/g, '')
    .trim();

  try {
    return JSON.parse(cleaned);
  } catch {}

  const objStart = cleaned.indexOf('{');
  const arrStart = cleaned.indexOf('[');
  let start = -1;
  let openCh = '{';
  let closeCh = '}';
  if (arrStart !== -1 && (objStart === -1 || arrStart < objStart)) {
    start = arrStart;
    openCh = '[';
    closeCh = ']';
  } else if (objStart !== -1) {
    start = objStart;
  }
  if (start === -1) return null;

  let depth = 0;
  let inStr = false;
  let escaped = false;
  for (let i = start; i < cleaned.length; i++) {
    const ch = cleaned[i];
    if (inStr) {
      if (escaped) escaped = false;
      else if (ch === '\\') escaped = true;
      else if (ch === '"') inStr = false;
      continue;
    }
    if (ch === '"') {
      inStr = true;
    } else if (ch === openCh) {
      depth++;
    } else if (ch === closeCh) {
      depth--;
      if (depth === 0) {
        const slice = cleaned.slice(start, i + 1);
        try {
          return JSON.parse(slice);
        } catch {
          break;
        }
      }
    }
  }
  return null;
}

async function discoverModels(settings, signal) {
  const provider = settings?.provider === 'openai' ? 'openai' : 'ollama';
  const baseUrl = normalizeBaseUrl(settings?.baseUrl, provider);
  const headers = buildAuthHeaders(settings);
  const started = Date.now();
  const endpoint = provider === 'openai'
    ? (baseUrl.endsWith('/v1') ? `${baseUrl}/models` : `${baseUrl}/v1/models`)
    : `${baseUrl}/api/tags`;

  const controller = new AbortController();
  const timer = setTimeout(() => controller.abort(new Error('Timeout connecting to LLM endpoint')), 8000);
  if (signal) {
    signal.addEventListener('abort', () => controller.abort(new Error('Aborted')), { once: true });
  }

  try {
    const res = await fetch(endpoint, { method: 'GET', headers, signal: controller.signal });
    const text = await res.text();
    let json = null;
    try { json = JSON.parse(text); } catch {}
    if (!res.ok) {
      return {
        ok: false,
        provider,
        baseUrl,
        latencyMs: Date.now() - started,
        models: [],
        error: `Endpoint returned HTTP ${res.status}: ${text.slice(0, 200)}`,
      };
    }

    const models = [];
    if (provider === 'ollama' && json && Array.isArray(json.models)) {
      for (const m of json.models) {
        models.push({
          name: m.name || m.model,
          size: m.size || 0,
          family: m.details?.family || '',
          parameterSize: m.details?.parameter_size || '',
        });
      }
    } else if (json && Array.isArray(json.data)) {
      for (const m of json.data) {
        models.push({
          name: m.id,
          size: 0,
          family: m.owned_by || '',
          parameterSize: '',
        });
      }
    }
    return {
      ok: true,
      provider,
      baseUrl,
      latencyMs: Date.now() - started,
      models,
      error: null,
    };
  } catch (err) {
    const msg = err?.cause?.code === 'ECONNREFUSED'
      ? `Connection refused at ${endpoint}. Start Ollama (\`ollama serve\`) or update the Base URL in Settings.`
      : (err?.message || `Failed to reach ${endpoint}`);
    return {
      ok: false,
      provider,
      baseUrl,
      latencyMs: Date.now() - started,
      models: [],
      error: msg,
    };
  } finally {
    clearTimeout(timer);
  }
}

async function resolveModelName(settings, signal) {
  if (settings?.model && String(settings.model).trim()) {
    return String(settings.model).trim();
  }
  const probe = await discoverModels(settings, signal);
  if (probe.ok && probe.models.length > 0) {
    return probe.models[0].name;
  }
  throw new Error(probe.error || 'No model configured and model auto-discovery returned none. Set a Model in Settings.');
}

async function chatCompletion(settings, { messages, temperature, jsonMode = false, signal } = {}) {
  const provider = settings?.provider === 'openai' ? 'openai' : 'ollama';
  const baseUrl = normalizeBaseUrl(settings?.baseUrl, provider);
  const headers = buildAuthHeaders(settings);
  const model = await resolveModelName(settings, signal);
  const temp = temperature !== undefined ? Number(temperature) : (Number(settings?.temperature) || 0.75);
  const numCtx = Number(settings?.numCtx) || 8192;

  const controller = new AbortController();
  const timer = setTimeout(() => controller.abort(new Error('LLM request timed out')), 90000);
  if (signal) {
    signal.addEventListener('abort', () => controller.abort(new Error('Aborted')), { once: true });
  }

  try {
    if (provider === 'ollama') {
      const body = {
        model,
        messages,
        stream: false,
        options: { temperature: temp, num_ctx: numCtx },
      };
      if (jsonMode) body.format = 'json';
      const res = await fetch(`${baseUrl}/api/chat`, {
        method: 'POST',
        headers,
        body: JSON.stringify(body),
        signal: controller.signal,
      });
      const data = await res.json();
      if (!res.ok) throw new Error(data?.error || `Ollama error HTTP ${res.status}`);
      const raw = data?.message?.content || '';
      return {
        model,
        rawText: raw,
        content: stripThinkingBlocks(raw),
      };
    }

    const endpoint = baseUrl.endsWith('/v1') ? `${baseUrl}/chat/completions` : `${baseUrl}/v1/chat/completions`;
    const body = { model, messages, temperature: temp, stream: false };
    if (jsonMode) body.response_format = { type: 'json_object' };
    const res = await fetch(endpoint, {
      method: 'POST',
      headers,
      body: JSON.stringify(body),
      signal: controller.signal,
    });
    const data = await res.json();
    if (!res.ok) throw new Error(data?.error?.message || `OpenAI-compat error HTTP ${res.status}`);
    const raw = data?.choices?.[0]?.message?.content || '';
    return {
      model,
      rawText: raw,
      content: stripThinkingBlocks(raw),
    };
  } finally {
    clearTimeout(timer);
  }
}

/**
 * Splits a streaming delta sequence into visible text vs <think>...</think> reasoning.
 */
function createThinkSplitter(onToken, onThinking) {
  let buffer = '';
  let inThink = false;

  const flushSafe = (isEnd = false) => {
    while (buffer.length > 0) {
      if (!inThink) {
        const idx = buffer.toLowerCase().indexOf('<think>');
        if (idx === -1) {
          const keep = isEnd ? 0 : Math.min(6, buffer.length);
          const emit = buffer.slice(0, buffer.length - keep);
          if (emit) onToken(emit);
          buffer = buffer.slice(buffer.length - keep);
          break;
        }
        const before = buffer.slice(0, idx);
        if (before) onToken(before);
        buffer = buffer.slice(idx + 7);
        inThink = true;
      } else {
        const idx = buffer.toLowerCase().indexOf('</think>');
        if (idx === -1) {
          const keep = isEnd ? 0 : Math.min(7, buffer.length);
          const emit = buffer.slice(0, buffer.length - keep);
          if (emit && onThinking) onThinking(emit);
          buffer = buffer.slice(buffer.length - keep);
          break;
        }
        const thought = buffer.slice(0, idx);
        if (thought && onThinking) onThinking(thought);
        buffer = buffer.slice(idx + 8);
        inThink = false;
      }
    }
  };

  return {
    push(chunk) {
      if (!chunk) return;
      buffer += chunk;
      flushSafe(false);
    },
    end() {
      flushSafe(true);
    },
  };
}

async function streamSingleRound({ provider, baseUrl, headers, model, messages, temperature, numCtx, tools, onToken, onThinking, signal }) {
  const endpoint = provider === 'ollama'
    ? `${baseUrl}/api/chat`
    : (baseUrl.endsWith('/v1') ? `${baseUrl}/chat/completions` : `${baseUrl}/v1/chat/completions`);

  const buildBody = (withTools) => {
    if (provider === 'ollama') {
      const b = {
        model,
        messages,
        stream: true,
        options: { temperature, num_ctx: numCtx },
      };
      if (withTools && tools && tools.length > 0) b.tools = tools;
      return b;
    }
    const b = { model, messages, temperature, stream: true };
    if (withTools && tools && tools.length > 0) b.tools = tools;
    return b;
  };

  let res = await fetch(endpoint, {
    method: 'POST',
    headers,
    body: JSON.stringify(buildBody(Boolean(tools && tools.length > 0))),
    signal,
  });

  // Fallback without native tools if model rejects tool schema
  if (res.status === 400 && tools && tools.length > 0) {
    res = await fetch(endpoint, {
      method: 'POST',
      headers,
      body: JSON.stringify(buildBody(false)),
      signal,
    });
  }

  if (!res.ok) {
    const errText = await res.text();
    throw new Error(`LLM HTTP ${res.status}: ${errText.slice(0, 300)}`);
  }

  const reader = res.body.getReader();
  const decoder = new TextDecoder();
  let lineBuf = '';
  let rawAssistantText = '';
  const pendingToolCalls = [];
  const openAiToolMap = new Map();
  const splitter = createThinkSplitter(onToken, onThinking);

  const processLine = (line) => {
    const trimmed = line.trim();
    if (!trimmed) return;
    if (provider === 'ollama') {
      let obj = null;
      try { obj = JSON.parse(trimmed); } catch { return; }
      if (obj.error) throw new Error(obj.error);
      const msg = obj.message || {};
      if (msg.thinking && onThinking) {
        onThinking(msg.thinking);
      }
      if (msg.content) {
        rawAssistantText += msg.content;
        splitter.push(msg.content);
      }
      if (Array.isArray(msg.tool_calls)) {
        for (const tc of msg.tool_calls) {
          pendingToolCalls.push({
            id: tc.id || `tc_${pendingToolCalls.length + 1}`,
            name: tc.function?.name,
            args: tc.function?.arguments || {},
          });
        }
      }
    } else {
      if (!trimmed.startsWith('data:')) return;
      const payload = trimmed.slice(5).trim();
      if (payload === '[DONE]') return;
      let obj = null;
      try { obj = JSON.parse(payload); } catch { return; }
      const choice = obj.choices?.[0];
      const delta = choice?.delta || {};
      if (delta.content) {
        rawAssistantText += delta.content;
        splitter.push(delta.content);
      }
      if (Array.isArray(delta.tool_calls)) {
        for (const tc of delta.tool_calls) {
          const idx = tc.index ?? 0;
          if (!openAiToolMap.has(idx)) {
            openAiToolMap.set(idx, { id: tc.id || `tc_${idx}`, name: '', argStr: '' });
          }
          const rec = openAiToolMap.get(idx);
          if (tc.id) rec.id = tc.id;
          if (tc.function?.name) rec.name += tc.function.name;
          if (tc.function?.arguments) rec.argStr += tc.function.arguments;
        }
      }
    }
  };

  while (true) {
    const { done, value } = await reader.read();
    if (done) break;
    lineBuf += decoder.decode(value, { stream: true });
    let nlIdx;
    while ((nlIdx = lineBuf.indexOf('\n')) !== -1) {
      const line = lineBuf.slice(0, nlIdx);
      lineBuf = lineBuf.slice(nlIdx + 1);
      processLine(line);
    }
  }
  if (lineBuf.trim()) processLine(lineBuf);
  splitter.end();

  for (const [, rec] of openAiToolMap.entries()) {
    let parsedArgs = {};
    try { parsedArgs = JSON.parse(rec.argStr || '{}'); } catch {}
    pendingToolCalls.push({ id: rec.id, name: rec.name, args: parsedArgs });
  }

  return {
    visibleText: stripThinkingBlocks(rawAssistantText),
    toolCalls: pendingToolCalls.filter((t) => t.name),
  };
}

async function streamChatWithTools(settings, options = {}) {
  const {
    messages = [],
    tools = [],
    executeTool,
    onEvent = () => {},
    signal,
    maxToolRounds = 4,
    temperature,
  } = options;

  const provider = settings?.provider === 'openai' ? 'openai' : 'ollama';
  const baseUrl = normalizeBaseUrl(settings?.baseUrl, provider);
  const headers = buildAuthHeaders(settings);
  const model = await resolveModelName(settings, signal);
  const temp = temperature !== undefined ? Number(temperature) : (Number(settings?.temperature) || 0.75);
  const numCtx = Number(settings?.numCtx) || 8192;

  const conversation = [...messages];
  let fullVisible = '';

  onEvent({ type: 'model', model, provider, baseUrl });

  for (let round = 0; round <= maxToolRounds; round++) {
    let roundText = '';
    const roundRes = await streamSingleRound({
      provider,
      baseUrl,
      headers,
      model,
      messages: conversation,
      temperature: temp,
      numCtx,
      tools: round < maxToolRounds ? tools : [],
      onToken: (delta) => {
        roundText += delta;
        fullVisible += delta;
        onEvent({ type: 'token', delta });
      },
      onThinking: (delta) => {
        onEvent({ type: 'thinking', delta });
      },
      signal,
    });

    if (!roundRes.toolCalls.length || typeof executeTool !== 'function' || round >= maxToolRounds) {
      break;
    }

    if (roundText) fullVisible += '\n\n';
    if (provider === 'ollama') {
      conversation.push({
        role: 'assistant',
        content: roundRes.visibleText || '',
        tool_calls: roundRes.toolCalls.map((tc) => ({
          function: { name: tc.name, arguments: tc.args },
        })),
      });
    } else {
      conversation.push({
        role: 'assistant',
        content: roundRes.visibleText || null,
        tool_calls: roundRes.toolCalls.map((tc) => ({
          id: tc.id,
          type: 'function',
          function: { name: tc.name, arguments: JSON.stringify(tc.args || {}) },
        })),
      });
    }

    for (const tc of roundRes.toolCalls) {
      let args = tc.args;
      if (typeof args === 'string') {
        try { args = JSON.parse(args); } catch { args = { raw: args }; }
      }
      onEvent({ type: 'tool_call', id: tc.id, name: tc.name, args });
      let result;
      try {
        result = await executeTool(tc.name, args || {});
      } catch (err) {
        result = { error: err?.message || 'Tool execution error' };
      }
      onEvent({ type: 'tool_result', id: tc.id, name: tc.name, result });
      conversation.push(
        provider === 'ollama'
          ? { role: 'tool', content: JSON.stringify(result) }
          : { role: 'tool', tool_call_id: tc.id, content: JSON.stringify(result) }
      );
    }
  }

  onEvent({ type: 'done', fullText: fullVisible.trim(), model });
  return { fullText: fullVisible.trim(), model };
}

module.exports = {
  normalizeBaseUrl,
  stripThinkingBlocks,
  extractJsonPayload,
  discoverModels,
  chatCompletion,
  streamChatWithTools,
};
