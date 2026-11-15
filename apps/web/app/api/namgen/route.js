import { NextResponse } from 'next/server';
import { generateCombinations, formatOutput, capitalizeProperName } from 'namgen.js';
import { generateNames, composeNamesNode } from 'namgen.js/node';
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
          withLore = false,
          format = 'plain',
          capitalize = false,
        } = body;

        const safeCount = Math.min(50, Math.max(1, Number(count) || 8));
        let names = generateNames(generator, safeCount, {
          seed,
          unique,
          type: Number(type) || 0,
          matchRegex,
          alliterate,
          syllables: Number(syllables) || 0,
          withLore,
        });
        if (capitalize) {
          names = names.map(capitalizeProperName);
        }
        return NextResponse.json({
          generator,
          names,
          formatted: formatOutput(names, format),
        });
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
