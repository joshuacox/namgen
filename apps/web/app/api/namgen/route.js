import { NextResponse } from 'next/server';
import { generateCombinations, formatOutput, capitalizeProperName } from 'namgen.js';
import { generateNames, composeNamesNode } from 'namgen.js/node';
import { getSettings } from '../../../lib/localStore';
import {
  getCppEngineStatus,
  rollCpp,
  markovCpp,
  blendCpp,
  oraclePoolCpp,
} from '../../../lib/cppNamgen';
import {
  forgeNpc,
  forgeEstablishment,
  forgeDungeon,
  forgeLootHoard,
  forgeEncounter,
  forgeFaction,
  generateMinionNames,
} from '../../../lib/dmEngine';

export const dynamic = 'force-dynamic';

export async function POST(request) {
  try {
    const body = await request.json();
    const { action = 'roll' } = body || {};

    switch (action) {
      case 'engine-info': {
        return NextResponse.json({ cppEngine: getCppEngineStatus() });
      }

      case 'roll': {
        const {
          generator = 'fantasy-dragons',
          count = 8,
          seed = '',
          unique = true,
          type = 0,
          matchRegex = '',
          alliterate = false,
          syllables = 0,
          minSyllables = 0,
          maxSyllables = 0,
          withLore = false,
          format = 'plain',
          capitalize = false,
        } = body;

        const safeCount = Math.min(200, Math.max(1, Number(count) || 8));
        const settings = await getSettings();
        let names;
        let engine = 'js-fallback';

        if (!matchRegex && !Number(type) && settings.preferCppBinary) {
          const res = await rollCpp({
            generator,
            count: safeCount,
            seed,
            unique,
            alliterate,
            minSyllables: Number(minSyllables) || Number(syllables) || 0,
            maxSyllables: Number(maxSyllables) || Number(syllables) || 0,
            withLore,
            preferCpp: true,
          });
          names = res.names;
          engine = res.engine;
        } else {
          names = generateNames(generator, safeCount, {
            seed,
            unique,
            type: Number(type) || 0,
            matchRegex,
            alliterate,
            syllables: Number(syllables) || 0,
            withLore,
          });
        }
        if (capitalize) {
          names = names.map(capitalizeProperName);
        }
        return NextResponse.json({
          generator,
          engine,
          names,
          formatted: formatOutput(names, format),
        });
      }

      case 'markov': {
        const settings = await getSettings();
        const res = await markovCpp({
          generators: body.generators || body.generator || ['fantasy-elfs'],
          keywords: body.keywords || [],
          order: body.order || 3,
          count: body.count || 15,
          seed: body.seed,
          minSyllables: body.minSyllables || 0,
          maxSyllables: body.maxSyllables || 0,
          preferCpp: settings.preferCppBinary,
        });
        return NextResponse.json({
          ...res,
          formatted: formatOutput(res.names, body.format || 'plain'),
        });
      }

      case 'blend': {
        const settings = await getSettings();
        const res = await blendCpp({
          keywords: body.keywords || [],
          generator: body.generator || '',
          count: body.count || 15,
          seed: body.seed,
          preferCpp: settings.preferCppBinary,
        });
        return NextResponse.json({
          ...res,
          formatted: formatOutput(res.names, body.format || 'plain'),
        });
      }

      case 'oracle-pool': {
        const settings = await getSettings();
        const res = await oraclePoolCpp({
          count: body.count || 50,
          keywords: body.keywords || [],
          archetypes: body.archetypes,
          seed: body.seed,
          minSyllables: body.minSyllables || 0,
          maxSyllables: body.maxSyllables || 0,
          preferCpp: settings.preferCppBinary,
        });
        return NextResponse.json(res);
      }

      case 'combinator': {
        const names = generateCombinations(body);
        return NextResponse.json({
          names,
          formatted: formatOutput(names, body.format || 'plain'),
        });
      }

      case 'compose': {
        const { generators = ['fantasy-dragons', 'places-castles'], template = '{1} of {2}', count = 5, seed = '', unique = true } = body;
        const names = composeNamesNode(generators, template, Math.min(30, Math.max(1, Number(count) || 5)), { seed, unique });
        return NextResponse.json({ names });
      }

      case 'npc':
        return NextResponse.json({ npc: forgeNpc(body) });

      case 'establishment':
        return NextResponse.json({ establishment: forgeEstablishment(body) });

      case 'dungeon':
        return NextResponse.json({ dungeon: forgeDungeon(body) });

      case 'loot':
        return NextResponse.json({ loot: forgeLootHoard(body) });

      case 'encounter':
        return NextResponse.json({ encounter: forgeEncounter(body) });

      case 'faction':
        return NextResponse.json({ faction: forgeFaction(body) });

      case 'minion-names':
        return NextResponse.json(generateMinionNames(body));

      default:
        return NextResponse.json({ error: `Unknown action: ${action}` }, { status: 400 });
    }
  } catch (err) {
    console.error('[namgen API] error:', err);
    return NextResponse.json(
      { error: err?.message || 'Failed to execute namgen generation' },
      { status: 500 }
    );
  }
}
