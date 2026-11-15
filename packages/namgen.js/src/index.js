const generators = require('../data/generators.json');
const categories = require('../data/categories.json');
const words = require('../data/words.json');
const formatters = require('./formatters');
const combinator = require('./combinator');

function normalizeKey(input) {
  return String(input || '')
    .trim()
    .replace(/^--/, '')
    .toLowerCase()
    .replace(/-/g, '_');
}

function isConsonant(c) {
  return /[bcdfghjklmnpqrstvwxz]/i.test(c);
}

function generateSpellingVariants(key) {
  const variants = [];
  if (key.includes('citys')) variants.push(key.replace(/citys/g, 'cities'));
  if (key.includes('cities')) variants.push(key.replace(/cities/g, 'citys'));
  if (key.length >= 3 && key.endsWith('ys') && isConsonant(key[key.length - 3])) {
    variants.push(key.slice(0, -2) + 'ies');
  }
  if (key.length >= 4 && key.endsWith('ies') && isConsonant(key[key.length - 4])) {
    variants.push(key.slice(0, -3) + 'ys');
  }
  if (key.includes('elfs')) variants.push(key.replace(/elfs/g, 'elves'));
  if (key.includes('elves')) variants.push(key.replace(/elves/g, 'elfs'));
  if (key.includes('dwarfs')) variants.push(key.replace(/dwarfs/g, 'dwarves'));
  if (key.includes('dwarves')) variants.push(key.replace(/dwarves/g, 'dwarfs'));
  if (key.includes('wolfs')) variants.push(key.replace(/wolfs/g, 'wolves'));
  if (key.includes('wolves')) variants.push(key.replace(/wolves/g, 'wolfs'));
  if (key.includes('halfs')) variants.push(key.replace(/halfs/g, 'halves'));
  if (key.includes('halves')) variants.push(key.replace(/halves/g, 'halfs'));
  return variants;
}

const registryMap = new Map();

function indexGenerator(key, gen) {
  if (!key) return;
  if (!registryMap.has(key)) {
    registryMap.set(key, gen);
  }
  const norm = normalizeKey(key);
  if (!registryMap.has(norm)) {
    registryMap.set(norm, gen);
  }
  for (const variant of generateSpellingVariants(norm)) {
    if (!registryMap.has(variant)) {
      registryMap.set(variant, gen);
    }
  }
}

for (const gen of generators) {
  indexGenerator(gen.id, gen);
  indexGenerator(gen.flag, gen);
  if (Array.isArray(gen.aliases)) {
    for (const alias of gen.aliases) {
      indexGenerator(alias, gen);
    }
  }
}

// Explicit natural aliases matching C++ CLI
const extraAliases = [
  ['elf', 'lord_of_the_rings-elfs'],
  ['lotr-elf', 'lord_of_the_rings-elfs'],
  ['descriptions-backstories', 'descriptions-backstorys'],
  ['descriptions-cities', 'descriptions-citys'],
  ['towns_and_cities-cities', 'towns_and_cities-citys'],
];
for (const [alias, targetId] of extraAliases) {
  const target = registryMap.get(targetId);
  if (target) {
    indexGenerator(alias, target);
  }
}

/**
 * Look up a generator descriptor by ID, flag (--category-name), or natural alias.
 */
function getGenerator(idOrFlag) {
  if (!idOrFlag) return null;
  const raw = String(idOrFlag).trim();
  if (registryMap.has(raw)) return registryMap.get(raw);
  const norm = normalizeKey(raw);
  if (registryMap.has(norm)) return registryMap.get(norm);
  for (const variant of generateSpellingVariants(norm)) {
    if (registryMap.has(variant)) return registryMap.get(variant);
  }
  return null;
}

/**
 * Return true if the given generator ID, flag, or alias exists.
 */
function hasGenerator(idOrFlag) {
  return Boolean(getGenerator(idOrFlag));
}

/**
 * Search generators by query string and optional category ID.
 */
function searchGenerators(query = '', category = 'all', limit = 0) {
  const q = String(query || '').trim().toLowerCase();
  const qNorm = normalizeKey(q);
  const cat = String(category || 'all').trim();

  const matches = generators.filter((gen) => {
    if (cat && cat !== 'all' && gen.category !== cat) return false;
    if (!q) return true;
    return (
      gen.name.toLowerCase().includes(q) ||
      gen.id.toLowerCase().includes(q) ||
      gen.flag.toLowerCase().includes(q) ||
      gen.category.toLowerCase().includes(q) ||
      gen.categoryName.toLowerCase().includes(q) ||
      (gen.description && gen.description.toLowerCase().includes(q)) ||
      normalizeKey(gen.id).includes(qNorm) ||
      (Array.isArray(gen.aliases) && gen.aliases.some((a) => a.toLowerCase().includes(q)))
    );
  });

  return limit > 0 ? matches.slice(0, limit) : matches;
}

/**
 * Return all generators belonging to a category ID.
 */
function getGeneratorsByCategory(categoryId) {
  return generators.filter((g) => g.category === categoryId);
}

module.exports = {
  generators,
  categories,
  words,
  getGenerator,
  hasGenerator,
  searchGenerators,
  getGeneratorsByCategory,
  normalizeKey,
  ...formatters,
  ...combinator,
};
