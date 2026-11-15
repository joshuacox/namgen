import { NextResponse } from 'next/server';
import { nameChecker } from 'namgen.js/node';
import {
  getSettings,
  listOracleRuns,
  getOracleRun,
  saveOracleRun,
  deleteOracleRun,
  MASKED_SECRET,
} from '../../../lib/localStore';
import { oraclePoolCpp } from '../../../lib/cppNamgen';
import { chatCompletion, extractJsonPayload } from '../../../lib/ollamaClient';
import { createSseStream } from '../../../lib/sse';

export const dynamic = 'force-dynamic';

const DEFAULT_ARCHETYPES = [
  { name: 'Arcane/Cyberpunk', description: 'Evocative dark/runic tech-fusions (e.g., Hexgrid, Sigilcast, Neonpakt)' },
  { name: 'Classical Etymology', description: 'Latin/Greek roots built for gravitas (e.g., Bellumancy, Locuspact, Aegisdeck)' },
  { name: 'Punchy Portmanteaus', description: 'Snappy fused concept blends (e.g., Deckbrawl, Spellclash, Summonrift)' },
  { name: 'Functional Minimalist', description: 'Crisp two-word plain nouns/verbs (e.g., Draftlane, Cardrift, Pactline)' },
  { name: 'Sovereign Neologisms', description: 'Zero-collision coined phonetic names (e.g., Vexora, Kaelith, Orvaxis)' },
];

function heuristicTailoredArchetypes(pitch) {
  const low = String(pitch || '').toLowerCase();
  if (low.includes('cli') || low.includes('dev') || low.includes('sdk') || low.includes('api')) {
    return [
      { name: 'Systems Brutalism', description: 'Tight infra & compiler roots (e.g., Forkgrid, Kernlock, Byteweave)' },
      { name: 'Classical Etymology', description: 'Precision Latin/Greek tech nouns (e.g., Nexarith, Logica, Vectrix)' },
      { name: 'Punchy Portmanteaus', description: 'Verb + tool blends (e.g., Shipforge, Lintsnap, Diffcraft)' },
      { name: 'Functional Minimalist', description: 'Zero-fluff utility compounds (e.g., Tracekit, Pipehub, Runbox)' },
      { name: 'Sovereign Neologisms', description: 'Clean trademarkable coinages (e.g., Vexor, Kaelis, Zynix)' },
    ];
  }
  return DEFAULT_ARCHETYPES;
}

function parseCustomCandidateList(rawText, defaultArchetype = 'Custom') {
  const lines = String(rawText || '').split(/\r?\n/);
  const list = [];
  for (const line of lines) {
    const trimmed = line.trim();
    if (!trimmed) continue;
    if (/^name[\t,; ]+archetype/i.test(trimmed)) continue;
    const parts = trimmed.split(/[\t,;]+/).map((p) => p.trim()).filter(Boolean);
    if (parts.length === 2 && !trimmed.includes(' ')) {
      list.push({ name: parts[0], archetype: parts[1] });
    } else if (trimmed.includes(',') && parts.length === 2) {
      list.push({ name: parts[0], archetype: parts[1] });
    } else {
      for (const token of parts) {
        if (token.length >= 2) list.push({ name: token, archetype: defaultArchetype });
      }
    }
  }
  return list;
}

export async function GET(request) {
  try {
    const { searchParams } = new URL(request.url);
    const id = searchParams.get('id');
    if (id) {
      const run = await getOracleRun(id);
      if (!run) return NextResponse.json({ error: 'Run not found' }, { status: 404 });
      return NextResponse.json({ run });
    }
    const runs = await listOracleRuns();
    return NextResponse.json({ runs });
  } catch (err) {
    return NextResponse.json({ error: err?.message || 'Failed to read oracle runs' }, { status: 500 });
  }
}

export async function DELETE(request) {
  try {
    const { searchParams } = new URL(request.url);
    const id = searchParams.get('id');
    if (!id) return NextResponse.json({ error: 'Missing id' }, { status: 400 });
    const removed = await deleteOracleRun(id);
    return NextResponse.json({ removed });
  } catch (err) {
    return NextResponse.json({ error: err?.message || 'Failed to delete oracle run' }, { status: 500 });
  }
}

export async function POST(request) {
  try {
    const body = await request.json();
    const { action = 'stream-run' } = body || {};
    const savedSettings = await getSettings();
    const settings = {
      ...savedSettings,
      provider: body.provider || savedSettings.provider,
      baseUrl: body.baseUrl || savedSettings.baseUrl,
      model: body.model || savedSettings.model,
      apiKey: body.apiKey && body.apiKey !== MASKED_SECRET ? body.apiKey : savedSettings.apiKey,
      temperature: body.temperature !== undefined ? Number(body.temperature) : savedSettings.temperature,
      numCtx: body.numCtx !== undefined ? Number(body.numCtx) : savedSettings.numCtx,
    };

    if (action === 'tailor-archetypes') {
      const pitch = String(body.pitch || '').trim();
      try {
        const res = await chatCompletion(settings, {
          jsonMode: true,
          messages: [
            {
              role: 'system',
              content:
                'Return strictly valid JSON: {"archetypes":[{"name":string,"description":string,"keywords":[string]}]}. Design exactly 5 distinct lexical archetypes tailored for naming the user\'s concept.',
            },
            { role: 'user', content: `Concept Pitch:\n${pitch || 'A deck-building creature-collecting MOBA game'}` },
          ],
        });
        const parsed = extractJsonPayload(res.content);
        if (parsed && Array.isArray(parsed.archetypes) && parsed.archetypes.length >= 3) {
          return NextResponse.json({ archetypes: parsed.archetypes.slice(0, 5), fallback: false });
        }
      } catch {}
      return NextResponse.json({ archetypes: heuristicTailoredArchetypes(pitch), fallback: true });
    }

    if (action === 'stream-run') {
      return createSseStream(request, async ({ send, signal }) => {
        const pitch = String(body.pitch || 'A deck-building game where you collect creatures and powers and battle in a MOBA').trim();
        const title = String(body.title || pitch.slice(0, 60) || 'Namespace Oracle Run').trim();
        const mode = ['hybrid', 'cpp', 'custom'].includes(body.mode) ? body.mode : 'hybrid';
        const poolSize = Math.max(5, Math.min(777, Number(body.poolSize) || 50));
        const llmShare = mode === 'hybrid' ? Math.max(0, Math.min(100, Number(body.llmShare ?? 40))) : 0;
        const archetypes = Array.isArray(body.archetypes) && body.archetypes.length > 0
          ? body.archetypes
          : DEFAULT_ARCHETYPES;
        const keywords = Array.isArray(body.keywords)
          ? body.keywords
          : String(body.keywords || '').split(/[\s,;]+/).map((s) => s.trim()).filter(Boolean);
        const minSyllables = Number(body.minSyllables) || 0;
        const maxSyllables = Number(body.maxSyllables) || 0;
        const tlds = Array.isArray(body.tlds) ? body.tlds : nameChecker.DEFAULT_TLDS;
        const registries = Array.isArray(body.registries) ? body.registries : nameChecker.DEFAULT_REGISTRIES;
        const marketChecks = body.marketChecks !== false;
        const githubRepoSearch = Boolean(body.githubRepoSearch);
        const enableAiCritique = body.enableAiCritique !== false && mode !== 'cpp';

        send('phase', { phase: 'generating', message: `Synthesizing ${poolSize} candidate names (${mode.toUpperCase()})...` });

        let rawPool = [];
        const seenSlugs = new Set();
        let notice = '';

        if (mode === 'custom') {
          rawPool = parseCustomCandidateList(body.customCandidatesText || '').slice(0, 777);
          if (rawPool.length === 0) {
            throw new Error('Custom list contained no valid candidate names.');
          }
        } else {
          // 1. Optional LLM batch synthesis
          const targetLlmCount = Math.round((poolSize * llmShare) / 100);
          if (targetLlmCount > 0) {
            const perArch = Math.max(5, Math.ceil(targetLlmCount / archetypes.length));
            for (const arch of archetypes) {
              if (signal.aborted || rawPool.length >= targetLlmCount) break;
              const batchNeed = Math.min(40, Math.max(4, Math.min(perArch, targetLlmCount - rawPool.length)));
              try {
                const res = await chatCompletion(settings, {
                  jsonMode: true,
                  signal,
                  messages: [
                    {
                      role: 'system',
                      content:
                        'You are a computational namer and phonoaesthetician. Output ONLY JSON: {"names":[{"name":string,"rationale":string}]}. Names MUST be crisp single-token or tight compound brandable names (1-4 syllables, letters only, no spaces or punctuation). Invent distinctive, obscure-enough names likely to be unclaimed on .com/GitHub.',
                    },
                    {
                      role: 'user',
                      content: `Concept: ${pitch}\nArchetype: ${arch.name} (${arch.description || ''})\nKeywords: ${keywords.join(', ') || 'none'}\nGenerate ${batchNeed} distinct candidate names.`,
                    },
                  ],
                });
                const parsed = extractJsonPayload(res.content);
                const items = Array.isArray(parsed) ? parsed : (parsed?.names || []);
                for (const item of items) {
                  const candidateName = typeof item === 'string' ? item : item?.name;
                  const clean = String(candidateName || '').replace(/[^a-zA-Z0-9]/g, '');
                  const slug = nameChecker.toSlug(clean);
                  if (clean.length < 3 || !slug || seenSlugs.has(slug)) continue;
                  const syl = nameChecker.countSyllables(clean);
                  if (minSyllables && syl < minSyllables) continue;
                  if (maxSyllables && syl > maxSyllables) continue;
                  seenSlugs.add(slug);
                  rawPool.push({
                    name: clean.charAt(0).toUpperCase() + clean.slice(1),
                    archetype: arch.name,
                    syllables: syl,
                    sigil: nameChecker.pronunciationSigil(clean),
                    rationale: typeof item === 'object' ? String(item.rationale || '') : '',
                    source: 'llm',
                  });
                }
                send('generation_progress', { current: rawPool.length, target: poolSize, source: 'llm', archetype: arch.name });
              } catch (err) {
                notice = `LLM generation skipped/fell back to C++17 engine (${err?.message || 'LLM unreachable'}).`;
                send('notice', { level: 'warn', message: notice });
                break;
              }
            }
          }

          // 2. Backfill remainder (or 100%) via C++17 --oracle-pool
          const remaining = poolSize - rawPool.length;
          if (remaining > 0 && !signal.aborted) {
            const cppRes = await oraclePoolCpp({
              count: remaining + 20,
              keywords,
              archetypes: archetypes.map((a) => a.name),
              minSyllables,
              maxSyllables,
              preferCpp: savedSettings.preferCppBinary,
            });
            for (const c of cppRes.candidates) {
              if (rawPool.length >= poolSize) break;
              const slug = nameChecker.toSlug(c.name);
              if (!slug || seenSlugs.has(slug)) continue;
              seenSlugs.add(slug);
              rawPool.push({ ...c, source: cppRes.engine });
            }
            send('generation_progress', { current: rawPool.length, target: poolSize, source: cppRes.engine });
          }
        }

        const byArchetype = {};
        for (const c of rawPool) {
          byArchetype[c.archetype] = (byArchetype[c.archetype] || 0) + 1;
        }
        send('pool_ready', { total: rawPool.length, byArchetype, notice });

        // Phase 3: Live Registry Verification
        send('phase', { phase: 'verifying', message: `Running DNS/RDAP/WHOIS, GitHub, NPM/PyPI/Crates & Store checks across ${rawPool.length} candidates...` });

        const githubToken = (body.githubToken && body.githubToken !== MASKED_SECRET)
          ? body.githubToken
          : savedSettings.githubToken;
        const usptoCsvPath = body.usptoCsvPath !== undefined ? body.usptoCsvPath : savedSettings.usptoCsvPath;

        const verification = await nameChecker.verifyCandidatePool(rawPool, {
          tlds,
          registries,
          marketChecks,
          githubToken,
          githubRepoSearch,
          usptoCsvPath,
          concurrency: rawPool.length > 100 ? 6 : 5,
          signal,
          onProgress: (ev) => {
            if (ev.type === 'uspto_done') send('uspto_done', ev);
            else if (ev.type === 'candidate_stage1') send('candidate_stage1', ev);
            else if (ev.type === 'stage2_start') send('stage2_start', ev);
            else if (ev.type === 'candidate_stage2') send('candidate_stage2', ev);
          },
        });

        // Phase 4: Optional AI Executive Critique on verified top survivors
        let aiSummary = '';
        let aiTopPicks = [];
        if (enableAiCritique && !signal.aborted && verification.results.length > 0) {
          send('phase', { phase: 'critique', message: 'Requesting AI Phonoaesthetic & Brand Critique on top survivors...' });
          const finalists = verification.results.slice(0, 15).map((r) => ({
            rank: r.rank,
            name: r.name,
            archetype: r.archetype,
            score: r.score,
            sigil: r.sigil,
            tm: r.tmProbability,
            recommendation: r.recommendation,
          }));
          try {
            const res = await chatCompletion(settings, {
              jsonMode: true,
              signal,
              messages: [
                {
                  role: 'system',
                  content:
                    'You are a Principal Brand Strategist. Respond with JSON ONLY: {"executiveSummary":string,"topPicks":[{"name":string,"whyItWins":string,"positioningTagline":string}]}. Pick up to 5 winning names strictly from the provided verified finalists.',
                },
                {
                  role: 'user',
                  content: `Concept Pitch: ${pitch}\nVerified Top Finalists:\n${JSON.stringify(finalists, null, 2)}`,
                },
              ],
            });
            const parsed = extractJsonPayload(res.content);
            if (parsed && parsed.executiveSummary) {
              aiSummary = String(parsed.executiveSummary);
              aiTopPicks = Array.isArray(parsed.topPicks) ? parsed.topPicks.slice(0, 5) : [];
            }
          } catch {
            // Silently ignore critique if LLM is unavailable
          }
        }

        const aiMarkdownBlock = aiSummary
          ? `${aiSummary}\n\n${aiTopPicks.map((p, i) => `${i + 1}. **${p.name}** — *${p.positioningTagline || ''}*: ${p.whyItWins || ''}`).join('\n')}`
          : '';

        const markdown = nameChecker.renderSurvivalReportMarkdown(verification, {
          title,
          pitch,
          aiSummary: aiMarkdownBlock,
        });

        const saved = await saveOracleRun({
          title,
          pitch,
          mode,
          keywords,
          archetypes,
          ...verification,
          aiSummary,
          aiTopPicks,
          markdown,
          notice,
        });

        send('complete', { run: saved });
      });
    }

    return NextResponse.json({ error: `Unknown action: ${action}` }, { status: 400 });
  } catch (err) {
    return NextResponse.json({ error: err?.message || 'Oracle API failed' }, { status: 500 });
  }
}
