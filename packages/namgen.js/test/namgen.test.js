const test = require('node:test');
const assert = require('node:assert/strict');
const namgen = require('../src/index');
const nodeApi = require('../src/node');
const dnd = require('../src/dnd');

test('metadata loads all 917 generators and categories', () => {
  assert.equal(namgen.generators.length, 917);
  assert.ok(namgen.categories.length >= 42);
  assert.ok(namgen.words.adjectives.length > 0);
  assert.ok(namgen.words.nouns.length > 0);
});

test('getGenerator resolves canonical IDs, CLI flags, and natural spelling aliases', () => {
  assert.equal(namgen.getGenerator('fantasy-dragons')?.id, 'fantasy-dragons');
  assert.equal(namgen.getGenerator('--fantasy-dragons')?.id, 'fantasy-dragons');
  assert.equal(namgen.getGenerator('elf')?.id, 'lord_of_the_rings-elfs');
  assert.equal(namgen.getGenerator('descriptions-backstories')?.id, 'descriptions-backstorys');
  assert.equal(namgen.getGenerator('descriptions-cities')?.id, 'descriptions-citys');
  assert.equal(namgen.getGenerator('towns_and_cities-cities')?.id, 'towns_and_cities-citys');
  assert.equal(namgen.getGenerator('nonexistent-xyz-gen'), null);
});

test('all 917 procedural JS generators execute and emit non-empty output in Node', () => {
  for (const gen of namgen.generators) {
    const out = nodeApi.generateNames(gen.id, 1);
    assert.equal(out.length, 1, `Expected 1 result for ${gen.id}`);
    assert.ok(out[0].trim().length > 0, `Empty output for ${gen.id}`);
  }
});

test('all generator IDs referenced in D&D dataset exist in generators.json', () => {
  for (const ancestry of dnd.DND_ANCESTRIES) {
    assert.ok(
      namgen.hasGenerator(ancestry.generator),
      `Invalid ancestry generator: ${ancestry.generator}`
    );
    if (ancestry.surnameGenerator) {
      assert.ok(
        namgen.hasGenerator(ancestry.surnameGenerator),
        `Invalid surnameGenerator: ${ancestry.surnameGenerator}`
      );
    }
  }

  for (const culture of dnd.HUMAN_CULTURES) {
    assert.ok(
      namgen.hasGenerator(culture.generator),
      `Invalid culture generator: ${culture.generator}`
    );
  }

  for (const preset of Object.values(dnd.GENRE_PRESETS)) {
    for (const slot of preset.slots) {
      assert.ok(
        namgen.hasGenerator(slot.generator),
        `Invalid GENRE_PRESETS[${preset.id}] slot generator: ${slot.generator}`
      );
    }
  }

  for (const shop of Object.values(dnd.SHOP_TYPES)) {
    assert.ok(namgen.hasGenerator(shop.nameGenerator), `Invalid shop nameGenerator: ${shop.nameGenerator}`);
    assert.ok(namgen.hasGenerator(shop.descGenerator), `Invalid shop descGenerator: ${shop.descGenerator}`);
    for (const itemGen of shop.itemGenerators) {
      assert.ok(namgen.hasGenerator(itemGen), `Invalid shop itemGenerator: ${itemGen}`);
    }
  }

  for (const env of Object.values(dnd.ENCOUNTER_ENVIRONMENTS)) {
    for (const g of [...env.npcGenerators, ...env.monsterGenerators]) {
      assert.ok(namgen.hasGenerator(g), `Invalid encounter generator: ${g}`);
    }
  }
});

test('combinator supports deterministic seeds, casing, separators, uniqueness, and formatting', () => {
  const a = namgen.generateCombinations({ count: 5, seed: 42, casing: 'cap', separator: '_' });
  const b = namgen.generateCombinations({ count: 5, seed: 42, casing: 'cap', separator: '_' });
  assert.deepEqual(a, b);
  assert.equal(a.length, 5);
  assert.ok(a.every((x) => x.includes('_')));

  const slug = namgen.formatOutput(['Eldoria Prime', "Kor'vath!"], 'slug');
  assert.equal(slug, 'eldoria-prime\nkor-vath');

  const csv = namgen.formatOutput(['Alpha "Red"'], 'csv');
  assert.equal(csv, '"name"\n"Alpha ""Red"""');
});

test('composeNamesNode interpolates templates across multiple generators', () => {
  const composed = nodeApi.composeNamesNode(
    ['fantasy-dragons', 'places-castles'],
    '{1} of {2}',
    3,
    { seed: 777 }
  );
  assert.equal(composed.length, 3);
  assert.ok(composed.every((line) => line.includes(' of ')));
});

test('WASM runtime initializes and produces deterministic seeded names in Node', async () => {
  const wasm = await nodeApi.initNodeWasm();
  assert.equal(wasm.hasGenerator('--fantasy-dragons'), true);
  assert.equal(wasm.hasGenerator('--does-not-exist-xyz'), false);
  const r1 = wasm.generate('--fantasy-dragons', 3, 12345);
  const r2 = wasm.generate('--fantasy-dragons', 3, 12345);
  assert.deepEqual(r1, r2);
  assert.equal(r1.length, 3);
});

test('all 10 new brand-* and tabletop-* generators resolve and emit output', () => {
  const expectedNewIds = [
    'brand-arcane_cyberpunk',
    'brand-classical_etymology',
    'brand-punchy_portmanteaus',
    'brand-functional_minimalist',
    'brand-sovereign_neologisms',
    'tabletop-plot_hooks',
    'tabletop-tavern_rumors',
    'tabletop-item_quirks',
    'tabletop-villain_schemes',
    'tabletop-dungeon_traps',
  ];
  for (const id of expectedNewIds) {
    assert.equal(namgen.getGenerator(id)?.id, id, `Missing metadata for ${id}`);
    const results = nodeApi.generateNames(id, 3);
    assert.equal(results.length, 3);
    assert.ok(results.every((r) => typeof r === 'string' && r.trim().length > 4));
  }
});

test('nameChecker exports linguistics, USPTO CSV scanning, offline pool verification, and markdown reporting', async () => {
  const fs = require('fs');
  const os = require('os');
  const path = require('path');
  const checker = require('namgen.js/name-checker');
  assert.equal(nodeApi.nameChecker.toSlug('Locus-Pact!'), 'locuspact');
  assert.equal(checker.countSyllables('Locuspact'), 3);
  assert.match(checker.pronunciationSigil('Locuspact'), /^\/[A-Z]+.*\/$/);

  const missingCsv = await checker.scanUsptoBulkCsv(['Locuspact'], '/tmp/definitely-missing-uspto-12345.csv');
  assert.equal(missingCsv.scanned, false);
  assert.equal(missingCsv.hits.size, 0);

  const tmpCsv = path.join(os.tmpdir(), `namgen-uspto-test-${Date.now()}.csv`);
  fs.writeFileSync(tmpCsv, 'mark_id_char,serial_no,international_class\nLOCUSPACT,99000111,009\nOTHERMARK,99000222,042\n', 'utf8');
  try {
    const scanned = await checker.scanUsptoBulkCsv(['Locuspact', 'Orvaxis'], tmpCsv);
    assert.equal(scanned.scanned, true);
    assert.equal(scanned.hits.has('locuspact'), true);
    assert.equal(scanned.hits.has('orvaxis'), false);
  } finally {
    fs.rmSync(tmpCsv, { force: true });
  }

  const run = await checker.verifyCandidatePool(
    [
      { name: 'Locuspact', archetype: 'Classical Etymology' },
      { name: 'Orvaxis', archetype: 'Sovereign Neologisms' },
    ],
    {
      tlds: [],
      registries: [],
      marketChecks: false,
      signal: new AbortController().signal,
    }
  );
  assert.equal(run.results.length, 2);
  const md = checker.renderSurvivalReportMarkdown(run, { title: 'Test Matrix' });
  assert.ok(md.includes('Locuspact'));
  assert.ok(md.includes('Orvaxis'));
  assert.ok(md.includes('flowchart LR'));
});
