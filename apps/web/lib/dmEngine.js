const {
  createSeededRandom,
  capitalizeProperName,
  getGenerator,
} = require('namgen.js');
const {
  generateNames,
  composeNamesNode,
} = require('namgen.js/node');
const {
  DND_ANCESTRIES,
  HUMAN_CULTURES,
  GENRE_PRESETS,
  NPC_ARCHETYPES_5E,
  NPC_VOICES,
  NPC_IDEALS,
  NPC_BONDS,
  NPC_POCKETS,
  NPC_DATA,
  SHOP_TYPES,
  TAVERN_DATA,
  DUNGEON_DATA,
  LOOT_DATA,
  PARTY_TIERS,
  ENCOUNTER_ENVIRONMENTS,
} = require('namgen.js/dnd');

function pick(arr, rng = Math.random) {
  return arr[Math.floor(rng() * arr.length)];
}

function rollOne(genId, { seed = '', type = 0, fallback = 'Unnamed', capitalize = false } = {}) {
  try {
    const names = generateNames(genId, 1, { seed, type });
    const raw = (names && names[0] ? names[0] : fallback).trim();
    return capitalize ? capitalizeProperName(raw) : raw;
  } catch (_) {
    return fallback;
  }
}

function formatSnippet(raw, maxLines = 4) {
  return String(raw || '')
    .split('\n')
    .map((l) => l.trim())
    .filter(Boolean)
    .slice(0, maxLines)
    .join('\n');
}

function forgeNpc(options = {}) {
  const {
    ancestryId = 'random',
    cultureId = '',
    genderType = 0,
    archetypeId = 'random',
    seed = '',
    lockedFields = {},
    currentNpc = null,
  } = options;

  const rng = createSeededRandom(seed);
  const ancestry =
    ancestryId && ancestryId !== 'random'
      ? DND_ANCESTRIES.find((a) => a.id === ancestryId) || pick(DND_ANCESTRIES, rng)
      : pick(DND_ANCESTRIES, rng);

  const culture =
    cultureId && cultureId !== 'none'
      ? HUMAN_CULTURES.find((c) => c.id === cultureId) || null
      : null;

  const nameGen = culture ? culture.generator : ancestry.generator;
  const parsedType = Number.isFinite(Number(genderType)) ? Number(genderType) : 0;

  let generatedName = rollOne(nameGen, { type: parsedType, capitalize: true, fallback: 'Alden Vale' });
  if (ancestry.surnameGenerator && !culture && !generatedName.includes(' ')) {
    const surname = rollOne(ancestry.surnameGenerator, { capitalize: true, fallback: '' });
    if (surname) generatedName = `${generatedName} ${surname}`;
  }

  const archetype =
    archetypeId && archetypeId !== 'random'
      ? NPC_ARCHETYPES_5E.find((a) => a.id === archetypeId) || pick(NPC_ARCHETYPES_5E, rng)
      : pick(NPC_ARCHETYPES_5E, rng);

  const occupation = capitalizeProperName(
    rollOne('miscellaneous-professions', { fallback: 'Guild Merchant' })
  );
  const portrait = formatSnippet(
    rollOne('descriptions-characters', { fallback: pick(NPC_DATA.appearances, rng) }),
    3
  );
  const clothing = formatSnippet(
    rollOne('descriptions-medieval_clothings', { fallback: 'Wears weathered travel leathers over fine wool.' }),
    2
  );
  const personality = formatSnippet(
    rollOne('descriptions-personalitys', { fallback: pick(NPC_DATA.personalityTraits, rng) }),
    2
  );
  const backstory = formatSnippet(
    rollOne('descriptions-backstorys', { fallback: 'Trained in a borderland guild before striking out alone.' }),
    3
  );

  const keep = (key, fresh) =>
    lockedFields && lockedFields[key] && currentNpc && currentNpc[key] !== undefined
      ? currentNpc[key]
      : fresh;

  const resolvedAncestry = keep('ancestry', ancestry.label);
  const resolvedArchetype = keep('archetype', archetype);

  return {
    id: (currentNpc && currentNpc.id) || `npc_${Date.now()}`,
    name: keep('name', generatedName),
    ancestry: resolvedAncestry,
    ancestryId: ancestry.id,
    ancestryIcon: ancestry.icon,
    ancestryTraits: ancestry.traits,
    culture: culture ? culture.label : null,
    generatorUsed: nameGen,
    occupation: keep('occupation', occupation),
    voice: keep('voice', pick(NPC_VOICES, rng)),
    portrait: keep('portrait', portrait),
    clothing: keep('clothing', clothing),
    personality: keep('personality', personality),
    backstory: keep('backstory', backstory),
    ideal: keep('ideal', pick(NPC_IDEALS, rng)),
    bond: keep('bond', pick(NPC_BONDS, rng)),
    flaw: keep('flaw', pick(NPC_DATA.flaws, rng)),
    secret: keep('secret', pick(NPC_DATA.darkSecrets, rng)),
    dialogueHook: keep('dialogueHook', pick(NPC_DATA.dialogueHooks, rng)),
    pocketLoot: keep('pocketLoot', pick(NPC_POCKETS, rng)),
    archetype: resolvedArchetype,
  };
}

function forgeEstablishment(options = {}) {
  const { shopType = 'tavern', seed = '' } = options;
  const rng = createSeededRandom(seed);
  const config = SHOP_TYPES[shopType] || SHOP_TYPES.tavern;

  const title = capitalizeProperName(
    rollOne(config.nameGenerator, { fallback: 'The Gilded Lantern' })
  );
  const description = formatSnippet(
    rollOne(config.descGenerator, { fallback: pick(TAVERN_DATA.atmospheres, rng) }),
    4
  );

  const proprietor = forgeNpc({
    archetypeId: shopType === 'magic_shop' ? 'mage' : shopType === 'temple' ? 'acolyte' : 'commoner',
  });
  proprietor.occupation = config.proprietorTitle;

  const dynamicItems = [];
  for (let i = 0; i < 4; i++) {
    const gen = config.itemGenerators[i % config.itemGenerators.length];
    const itemName = capitalizeProperName(rollOne(gen, { fallback: 'Curious Trinket' }));
    const gp = shopType === 'tavern'
      ? `${Math.floor(rng() * 8) + 2} sp`
      : shopType === 'magic_shop'
      ? `${(Math.floor(rng() * 9) + 1) * 50} gp`
      : `${(Math.floor(rng() * 12) + 2) * 5} gp`;
    dynamicItems.push({
      category: getGenerator(gen)?.name || 'Specialty',
      item: itemName,
      price: gp,
      note: `Generated via --${gen}`,
    });
  }

  const special = pick(TAVERN_DATA.houseSpecials, rng);
  const foodSpecial = capitalizeProperName(rollOne('miscellaneous-foods', { fallback: special.food }));
  const brewSpecial = capitalizeProperName(rollOne('miscellaneous-drinks', { fallback: special.brew }));
  const shadyName = capitalizeProperName(rollOne('dungeon_and_dragons-tieflings', { fallback: 'Vesper' }));
  const questHook = formatSnippet(
    rollOne('descriptions-quests', { fallback: pick(TAVERN_DATA.shadyPatrons, rng).hook }),
    5
  );

  return {
    id: `est_${Date.now()}`,
    shopType: config.id,
    shopLabel: config.label,
    icon: config.icon,
    name: title,
    atmosphere: pick(TAVERN_DATA.atmospheres, rng),
    description,
    proprietor,
    houseSpecial: {
      food: foodSpecial,
      brew: brewSpecial,
      price: special.price,
    },
    inventory: [...config.baseItems, ...dynamicItems],
    rumors: {
      trueRumor: pick(TAVERN_DATA.rumors.trueRumors, rng),
      halfRumor: pick(TAVERN_DATA.rumors.halfTrueRumors, rng),
      falseRumor: pick(TAVERN_DATA.rumors.falseRumors, rng),
    },
    patron: {
      name: shadyName,
      hook: questHook,
    },
  };
}

function forgeDungeon(options = {}) {
  const tierNum = Math.min(4, Math.max(1, Number(options.tier) || 1));
  const tierMeta = PARTY_TIERS[tierNum];
  const rng = createSeededRandom(options.seed);

  const title = capitalizeProperName(
    rollOne('places-dungeons', { fallback: 'The Sunken Crypt of Karas' })
  );
  const loreExcerpt = formatSnippet(
    rollOne('descriptions-dungeons', { fallback: 'Cold stale air drafts upward from moss-choked stone arches.' }),
    4
  );

  const r1 = pick(DUNGEON_DATA.room1Entrance, rng);
  const r2 = pick(DUNGEON_DATA.room2Hazards, rng);
  const r3 = pick(DUNGEON_DATA.room3Setbacks, rng);
  const r4 = pick(DUNGEON_DATA.room4BossSanctums, rng);
  const r5 = pick(DUNGEON_DATA.room5Hoards, rng);

  const captainName = capitalizeProperName(rollOne('fantasy-monsters', { fallback: 'Grimjaw' }));
  const bossName = capitalizeProperName(rollOne('fantasy-demons', { fallback: r4.boss }));
  const relicName = capitalizeProperName(rollOne('weapons-magic_weapons', { fallback: 'Star-Forged Blade' }));
  const relicDesc = formatSnippet(rollOne('descriptions-weapons', { fallback: '' }), 2);

  return {
    id: `dun_${Date.now()}`,
    title,
    tier: tierNum,
    tierLabel: tierMeta.label,
    recommendedDc: tierMeta.dc,
    trapDamage: tierMeta.trapDamage,
    loreExcerpt,
    rooms: {
      entrance: r1,
      hazard: {
        ...r2,
        scaledDc: `DC ${tierMeta.dc} (${tierMeta.trapDamage} damage on fail)`,
      },
      setback: {
        ...r3,
        captainName,
      },
      bossSanctum: {
        ...r4,
        namedBoss: `${bossName} — ${r4.boss}`,
        scaledLairDc: `DC ${tierMeta.dc - 1}`,
      },
      hoard: {
        ...r5,
        scaledGold: 150 * tierMeta.goldScale,
        relicName,
        relicDesc,
        rarity: tierMeta.rarity,
      },
    },
  };
}

function forgeLootHoard(options = {}) {
  const tierNum = Math.min(4, Math.max(1, Number(options.tier) || 1));
  const tierMeta = PARTY_TIERS[tierNum];
  const rng = createSeededRandom(options.seed);
  const bonus = tierNum === 1 ? '+1' : tierNum === 2 ? '+1 / +2' : tierNum === 3 ? '+2' : '+3';

  const weaponName = capitalizeProperName(rollOne('weapons-swords', { fallback: 'Dawnbreaker' }));
  const weaponDesc = formatSnippet(
    rollOne('descriptions-weapons', { fallback: pick(LOOT_DATA.weapons, rng).lore }),
    3
  );
  const enchantment = capitalizeProperName(
    rollOne('miscellaneous-gear_enchantments', { fallback: 'of Undying Flame' })
  );

  const potion1Name = capitalizeProperName(rollOne('miscellaneous-potions', { fallback: 'Elixir of Vigor' }));
  const potion2Name = capitalizeProperName(rollOne('miscellaneous-potions', { fallback: 'Draught of Mist' }));
  const potionRecipe = formatSnippet(rollOne('descriptions-potions', { fallback: '' }), 4);

  const scrollRaw = formatSnippet(rollOne('descriptions-spells', { fallback: 'Arcane Surge' }), 3);
  const gem1 = capitalizeProperName(rollOne('miscellaneous-gem_minerals', { fallback: 'Star Sapphire' }));
  const gem2 = capitalizeProperName(rollOne('miscellaneous-gem_minerals', { fallback: 'Blood Ruby' }));

  const gp = Math.round((120 + Math.floor(rng() * 180)) * tierMeta.goldScale);
  const sp = Math.round((450 + Math.floor(rng() * 500)) * tierMeta.goldScale);
  const pp = Math.round((5 + Math.floor(rng() * 15)) * tierMeta.goldScale);

  return {
    id: `loot_${Date.now()}`,
    tier: tierNum,
    tierLabel: tierMeta.label,
    rarity: tierMeta.rarity,
    coins: { gp, sp, pp },
    relic: {
      name: `${weaponName} (${bonus})`,
      enchantment,
      lore: weaponDesc,
      value: `${500 * tierMeta.goldScale} gp`,
    },
    potions: [
      { ...pick(LOOT_DATA.potions, rng), name: potion1Name },
      { ...pick(LOOT_DATA.potions, rng), name: potion2Name },
    ],
    potionRecipe,
    spellScroll: scrollRaw,
    gems: [
      { item: gem1, val: `${50 * tierMeta.goldScale} gp` },
      { item: gem2, val: `${75 * tierMeta.goldScale} gp` },
      pick(LOOT_DATA.curios, rng),
    ],
  };
}

function forgeEncounter(options = {}) {
  const { envId = 'road', tier = 1, seed = '' } = options;
  const rng = createSeededRandom(seed);
  const env = ENCOUNTER_ENVIRONMENTS[envId] || ENCOUNTER_ENVIRONMENTS.road;
  const tierMeta = PARTY_TIERS[Math.min(4, Math.max(1, Number(tier) || 1))];

  const npcGen = pick(env.npcGenerators, rng);
  const monGen = pick(env.monsterGenerators, rng);
  const npcNames = generateNames(npcGen, 2, { unique: true }).map(capitalizeProperName);
  const monNames = generateNames(monGen, 3, { unique: true }).map(capitalizeProperName);
  const quest = formatSnippet(rollOne('descriptions-quests', { fallback: '' }), 4);
  const prophecy = formatSnippet(rollOne('descriptions-prophecys', { fallback: '' }), 2);

  return {
    id: `enc_${Date.now()}`,
    environment: env.label,
    envId: env.id,
    icon: env.icon,
    tierLabel: tierMeta.label,
    recommendedDc: tierMeta.dc,
    twist: pick(env.twists, rng),
    npcs: npcNames,
    monsters: monNames,
    npcGenerator: npcGen,
    monsterGenerator: monGen,
    questHook: quest,
    prophecy,
  };
}

function forgeFaction(options = {}) {
  const { genreId = 'fantasy', seed = '' } = options;
  const preset = GENRE_PRESETS[genreId] || GENRE_PRESETS.fantasy;
  const factionTitle = capitalizeProperName(
    rollOne('miscellaneous-guilds', { fallback: preset.defaultFaction })
  );
  const coatOfArms = formatSnippet(
    rollOne('descriptions-coat_of_arms', { fallback: 'A silver wolf rampant upon an obsidian field.' }),
    3
  );
  const law = formatSnippet(
    rollOne('descriptions-laws', { fallback: 'Carrying unsheathed steel within the inner keep is punishable by steep fines.' }),
    3
  );
  const slots = preset.slots.map((slot) => ({
    ...slot,
    name: capitalizeProperName(rollOne(slot.generator, { seed, fallback: slot.title })),
  }));

  return {
    id: `fac_${Date.now()}`,
    genreId: preset.id,
    genreName: preset.name,
    icon: preset.icon,
    factionName: factionTitle,
    coatOfArms,
    law,
    slots,
  };
}

function guessGeneratorForCreature(label = '') {
  const q = String(label || '').toLowerCase();
  if (q.includes('goblin')) return 'fantasy-goblins';
  if (q.includes('orc')) return 'fantasy-orcs';
  if (q.includes('kobold')) return 'pathfinder-kobolds';
  if (q.includes('drow')) return 'dungeon_and_dragons-drows';
  if (q.includes('dragon')) return 'fantasy-dragons';
  if (q.includes('demon') || q.includes('fiend') || q.includes('devil')) return 'fantasy-demons';
  if (q.includes('vampire')) return 'fantasy-vampires';
  if (q.includes('lich')) return 'fantasy-lichs';
  if (q.includes('zombie') || q.includes('skeleton') || q.includes('undead')) return 'fantasy-zombie_types';
  if (q.includes('bandit') || q.includes('cult') || q.includes('pirate')) return 'fantasy-bandits';
  if (q.includes('knight') || q.includes('guard')) return 'fantasy-knights';
  if (q.includes('elf')) return 'dungeon_and_dragons-elfs';
  if (q.includes('dwarf')) return 'dungeon_and_dragons-dwarfs';
  return 'fantasy-monsters';
}

function generateMinionNames({ label = 'Goblin', generatorId = '', count = 4, seed = '' }) {
  const gen = generatorId || guessGeneratorForCreature(label);
  const safeCount = Math.min(20, Math.max(1, Number(count) || 4));
  const names = generateNames(gen, safeCount, { unique: true, seed });
  return {
    generatorUsed: gen,
    names: names.map(capitalizeProperName),
  };
}

module.exports = {
  forgeNpc,
  forgeEstablishment,
  forgeDungeon,
  forgeLootHoard,
  forgeEncounter,
  forgeFaction,
  generateMinionNames,
  composeNamesNode,
};
