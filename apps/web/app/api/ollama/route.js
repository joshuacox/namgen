import { NextResponse } from 'next/server';
import namgenMeta from 'namgen.js';
import { getSettings, getVault, MASKED_SECRET } from '../../../lib/localStore';
import { rollCpp, blendCpp } from '../../../lib/cppNamgen';
import {
  discoverModels,
  chatCompletion,
  streamChatWithTools,
  extractJsonPayload,
} from '../../../lib/ollamaClient';
import { createSseStream } from '../../../lib/sse';
import { forgeNpc } from '../../../lib/dmEngine';

export const dynamic = 'force-dynamic';

function mergeRuntimeSettings(saved, overrides) {
  if (!overrides || typeof overrides !== 'object') return saved;
  return {
    ...saved,
    provider: overrides.provider || saved.provider,
    baseUrl: overrides.baseUrl || saved.baseUrl,
    model: overrides.model !== undefined ? overrides.model : saved.model,
    temperature: overrides.temperature !== undefined ? Number(overrides.temperature) : saved.temperature,
    numCtx: overrides.numCtx !== undefined ? Number(overrides.numCtx) : saved.numCtx,
    apiKey: overrides.apiKey && overrides.apiKey !== MASKED_SECRET ? overrides.apiKey : saved.apiKey,
  };
}

function rollDiceExpr(expr = '1d20') {
  const clean = String(expr || '1d20').trim().toLowerCase().replace(/\s+/g, '');
  const m = clean.match(/^(\d{1,2})d(\d{1,3})([+-]\d{1,4})?$/);
  if (!m) {
    return { expression: expr, total: Math.floor(Math.random() * 20) + 1, rolls: [], error: 'Used 1d20 fallback' };
  }
  const count = Math.min(30, Math.max(1, Number(m[1])));
  const sides = Math.min(1000, Math.max(2, Number(m[2])));
  const mod = m[3] ? Number(m[3]) : 0;
  const rolls = Array.from({ length: count }, () => Math.floor(Math.random() * sides) + 1);
  const total = rolls.reduce((a, b) => a + b, 0) + mod;
  return { expression: clean, rolls, modifier: mod, total };
}

const TOOL_SPECS = {
  'story-arc': {
    label: 'Story Arc & Campaign Weaver',
    generators: ['tabletop-plot_hooks', 'tabletop-villain_schemes', 'descriptions-quests'],
    system: 'You are a master D&D 5e Campaign Architect. Weave cohesive 3-act arcs, ticking clocks, faction tensions, and vivid secrets anchored to the campaign codex and procedural seeds provided.',
  },
  'scene-painter': {
    label: 'Sensory Boxed-Text & Scene Painter',
    generators: ['places-inns', 'places-dungeons', 'tabletop-tavern_rumors'],
    system: 'You are an atmospheric Dungeon Master. Write punchy read-aloud boxed text (sight, sound, smell, lighting) followed by 3 interactive secrets or exits for the players to investigate.',
  },
  'npc-roleplay': {
    label: 'Live NPC Roleplay & Agentic Co-DM Console',
    generators: ['dungeon_and_dragons-humans', 'descriptions-personalitys', 'tabletop-tavern_rumors'],
    system: 'You are an interactive AI Co-DM & Actor. If asked to roleplay an NPC, respond first in-character with distinctive cadence and secret agenda, plus concise DM stage directions. You can invoke tools (roll_namgen, blend_portmanteau, roll_dice, lookup_campaign_codex) whenever names, rumors, loot, or dice are needed.',
  },
  'three-clue': {
    label: 'Mystery & Three-Clue Architect',
    generators: ['tabletop-plot_hooks', 'tabletop-villain_schemes', 'tabletop-item_quirks'],
    system: 'You design tabletop mysteries using Justin Alexander\'s Three-Clue Rule: for every conclusion players must reach, embed at least 3 distinct clues (physical, testimonial, arcane) plus red herrings and fail-forward triggers.',
  },
  'boss-designer': {
    label: 'Multi-Phase Tactical Boss Designer',
    generators: ['fantasy-dragons', 'fantasy-demons', 'tabletop-dungeon_traps'],
    system: 'You are a D&D 5e Combat Encounter Tactician. Design memorable multi-phase bosses with mythic Phase 2 transitions at 50% HP, terrain hazards, lair actions on initiative 20, minion synergies, and punchy stat summaries.',
  },
  'handout-scribe': {
    label: 'In-World Handouts, Prophecies & Riddles',
    generators: ['descriptions-prophecys', 'tabletop-item_quirks', 'places-kingdoms'],
    system: 'You forge tactile in-world player handouts: cryptic prophecies, wax-sealed letters, ciphered riddles (with DM solution key at the bottom), tavern notices, or bloodstained journal pages.',
  },
  'session-recap': {
    label: 'Session Recap Chronicler & Lazy-DM Prep',
    generators: ['tabletop-plot_hooks', 'tabletop-tavern_rumors', 'fantasy-factions'],
    system: 'You turn rough session bullet notes into (1) a dramatic "Previously on..." chronicle for players, (2) 3 Strong Starts, (3) 5 Secrets & Clues, and (4) Likely Next-Session NPCs & Encounters.',
  },
};

const OLLAMA_TOOLS = [
  {
    type: 'function',
    function: {
      name: 'roll_namgen',
      description: 'Generate procedural names, lore, plot hooks, taverns, weapons, or rumors using the C++17 namgen engine (917 generators).',
      parameters: {
        type: 'object',
        properties: {
          generator: { type: 'string', description: 'Generator ID e.g. fantasy-dragons, places-inns, tabletop-plot_hooks, tabletop-tavern_rumors, dungeon_and_dragons-elfs, weapons-swords' },
          count: { type: 'integer', description: 'Number of results (1-10)' },
          withLore: { type: 'boolean', description: 'Include mythic epithet/lore' },
        },
        required: ['generator'],
      },
    },
  },
  {
    type: 'function',
    function: {
      name: 'blend_portmanteau',
      description: 'Fuse keywords into original coined fantasy/cyberpunk names or titles using the C++ portmanteau synthesizer.',
      parameters: {
        type: 'object',
        properties: {
          keywords: { type: 'array', items: { type: 'string' }, description: '2-6 seed words to blend' },
          count: { type: 'integer' },
        },
        required: ['keywords'],
      },
    },
  },
  {
    type: 'function',
    function: {
      name: 'search_namgen_generators',
      description: 'Search the 917 namgen generators by keyword (e.g., dragon, tavern, demon, sword, roman, pirate).',
      parameters: {
        type: 'object',
        properties: { query: { type: 'string' } },
        required: ['query'],
      },
    },
  },
  {
    type: 'function',
    function: {
      name: 'roll_dice',
      description: 'Roll polyhedral D&D dice such as 1d20+5, 2d6+3, or 8d6.',
      parameters: {
        type: 'object',
        properties: { expression: { type: 'string' } },
        required: ['expression'],
      },
    },
  },
  {
    type: 'function',
    function: {
      name: 'lookup_campaign_codex',
      description: 'Search the active campaign party roster, saved codex entries (NPCs, towns, factions, items), and recent session notes.',
      parameters: {
        type: 'object',
        properties: { query: { type: 'string' } },
      },
    },
  },
];

async function buildPreSeeds(toolKey, preferCpp) {
  const spec = TOOL_SPECS[toolKey] || TOOL_SPECS['story-arc'];
  const seeds = [];
  for (const gen of spec.generators.slice(0, 3)) {
    const rolled = await rollCpp({ generator: gen, count: 2, preferCpp });
    seeds.push({ generator: gen, items: rolled.names, engine: rolled.engine });
  }
  return seeds;
}

export async function POST(request) {
  try {
    const body = await request.json();
    const { action = 'test' } = body || {};
    const savedSettings = await getSettings();
    const settings = mergeRuntimeSettings(savedSettings, body.settingsOverride || body);

    if (action === 'test') {
      const result = await discoverModels(settings);
      return NextResponse.json(result);
    }

    if (action === 'structured-forge') {
      const { kind = 'codex', text = '', title = '' } = body;
      const prompts = {
        codex: 'Convert this tabletop content into a single JSON object matching: {"title":string,"type":"NPC"|"Location"|"Faction"|"Quest"|"Item"|"Lore"|"Title","tags":string[],"summary":string}. Keep summary concise and scannable.',
        npc: 'Extract or invent an NPC JSON object matching: {"name":string,"ancestry":string,"role":string,"alignment":string,"personality":string,"quirk":string,"secretAgenda":string,"plotHook":string}.',
        combat: 'Convert this boss/encounter into JSON matching: {"title":string,"boss":{"name":string,"ac":number,"maxHp":number,"init":number,"phases":string,"actions":string},"minions":[{"label":string,"count":number,"ac":number,"hp":number}]}.',
        handout: 'Format as player-facing handout JSON: {"title":string,"subtitle":string,"body":string}. Strip any secret DM spoilers from body.',
      };

      try {
        const res = await chatCompletion(settings, {
          jsonMode: true,
          messages: [
            { role: 'system', content: prompts[kind] || prompts.codex },
            { role: 'user', content: `Title hint: ${title}\n\nSource content:\n${String(text).slice(0, 6000)}` },
          ],
        });
        const parsed = extractJsonPayload(res.content);
        if (parsed && typeof parsed === 'object') {
          return NextResponse.json({ ok: true, kind, data: parsed, fallback: false });
        }
      } catch {}

      // Deterministic fallback so Vault import works cleanly even offline
      if (kind === 'npc') {
        const fallbackNpc = forgeNpc({ name: title || 'Wandering Stranger' });
        return NextResponse.json({ ok: true, kind, data: fallbackNpc, fallback: true });
      }
      if (kind === 'combat') {
        return NextResponse.json({
          ok: true,
          kind,
          fallback: true,
          data: {
            title: title || 'Phase Encounter',
            boss: { name: title || 'Dread Champion', ac: 17, maxHp: 145, init: 2, phases: 'Mythic Phase 2 at 50% HP', actions: 'Multiattack, Aura Pulse' },
            minions: [{ label: 'Shadow Acolyte', count: 2, ac: 13, hp: 27 }],
          },
        });
      }
      if (kind === 'handout') {
        return NextResponse.json({
          ok: true,
          kind,
          fallback: true,
          data: {
            title: title || 'Recovered Chronicle',
            subtitle: 'Campaign Handout',
            body: String(text || '').slice(0, 4000),
          },
        });
      }
      return NextResponse.json({
        ok: true,
        kind: 'codex',
        fallback: true,
        data: {
          title: title || 'AI Storyteller Note',
          type: 'Lore',
          tags: ['ai-storyteller', 'namgen'],
          summary: String(text || '').slice(0, 1500),
        },
      });
    }

    if (action === 'chat-stream') {
      const {
        tool = 'story-arc',
        prompt = '',
        messages: clientMessages = [],
        campaignContext = '',
        includeVaultContext = true,
      } = body;

      return createSseStream(request, async ({ send, signal }) => {
        const spec = TOOL_SPECS[tool] || TOOL_SPECS['story-arc'];
        const seeds = await buildPreSeeds(tool, savedSettings.preferCppBinary);
        send('seeds', { tool, seeds });

        let vaultSnapshotText = '';
        if (includeVaultContext) {
          try {
            const vault = await getVault();
            const camp = vault.campaigns.find((c) => c.id === vault.activeCampaignId) || vault.campaigns[0];
            if (camp) {
              const partySummary = (camp.party || []).map((p) => `${p.name} (${p.classLevel})`).join(', ');
              const codexSummary = (camp.codex || []).slice(0, 8).map((c) => `[${c.type}] ${c.title}: ${String(c.summary || '').slice(0, 140)}`).join('\n');
              vaultSnapshotText = `Active Campaign: ${camp.name} (${camp.setting}, Tier ${camp.partyLevelTier})\nParty: ${partySummary}\nCodex Highlights:\n${codexSummary}`;
            }
          } catch {}
        }

        const seedSummary = seeds
          .map((s) => `${s.generator}: ${s.items.join(' | ')}`)
          .join('\n');

        const sysPrompt = [
          spec.system,
          vaultSnapshotText ? `\n--- CAMPAIGN VAULT CONTEXT ---\n${vaultSnapshotText}` : '',
          campaignContext ? `\n--- FOCUSED ENTITY / HANDOFF CONTEXT ---\n${campaignContext}` : '',
          seedSummary ? `\n--- C++17 NAMGEN PROCEDURAL SPARKS ---\n${seedSummary}` : '',
        ].filter(Boolean).join('\n');

        const conversation = [{ role: 'system', content: sysPrompt }];
        if (Array.isArray(clientMessages) && clientMessages.length > 0) {
          for (const m of clientMessages.slice(-16)) {
            if (m?.role && m?.content) {
              conversation.push({ role: m.role === 'assistant' ? 'assistant' : 'user', content: String(m.content) });
            }
          }
        }
        if (prompt && (!clientMessages.length || clientMessages[clientMessages.length - 1]?.content !== prompt)) {
          conversation.push({ role: 'user', content: String(prompt) });
        }

        const executeTool = async (name, args) => {
          if (name === 'roll_namgen') {
            return rollCpp({
              generator: args.generator || 'fantasy-dragons',
              count: Math.min(10, Math.max(1, Number(args.count) || 4)),
              withLore: Boolean(args.withLore),
              preferCpp: savedSettings.preferCppBinary,
            });
          }
          if (name === 'blend_portmanteau') {
            return blendCpp({
              keywords: args.keywords || [],
              count: Math.min(10, Math.max(1, Number(args.count) || 5)),
              preferCpp: savedSettings.preferCppBinary,
            });
          }
          if (name === 'search_namgen_generators') {
            return {
              matches: namgenMeta.searchGenerators(args.query || '').slice(0, 12).map((g) => ({
                id: g.id, category: g.category, sample: g.samples?.[0] || '',
              })),
            };
          }
          if (name === 'roll_dice') {
            return rollDiceExpr(args.expression || '1d20');
          }
          if (name === 'lookup_campaign_codex') {
            const vault = await getVault();
            const camp = vault.campaigns.find((c) => c.id === vault.activeCampaignId) || vault.campaigns[0];
            const q = String(args.query || '').toLowerCase();
            if (!camp) return { entries: [] };
            const matches = (camp.codex || [])
              .filter((e) => !q || e.title?.toLowerCase().includes(q) || e.summary?.toLowerCase().includes(q) || e.type?.toLowerCase().includes(q))
              .slice(0, 10);
            return { campaign: camp.name, entries: matches, party: camp.party };
          }
          return { error: `Unknown tool: ${name}` };
        };

        await streamChatWithTools(settings, {
          messages: conversation,
          tools: tool === 'npc-roleplay' || tool === 'story-arc' || tool === 'three-clue' ? OLLAMA_TOOLS : [],
          executeTool,
          signal,
          onEvent: (ev) => {
            send(ev.type, ev);
          },
        });
      });
    }

    return NextResponse.json({ error: `Unknown action: ${action}` }, { status: 400 });
  } catch (err) {
    return NextResponse.json({ error: err?.message || 'Ollama proxy error' }, { status: 500 });
  }
}
