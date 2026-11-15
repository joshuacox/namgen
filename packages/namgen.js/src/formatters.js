/**
 * Formatting, linguistics, and lore helpers for namgen.js.
 * Mirrors the C++17 Linguistics and Lore modules.
 */

const EPITHET_PREFIXES = [
  'Dawn', 'Void', 'Iron', 'Moon', 'Star', 'Shadow', 'Flame', 'Wind',
  'Storm', 'Frost', 'Silent', 'Sun', 'Blood', 'Silver', 'Night', 'Rune',
  'Ash', 'Thunder', 'Ember', 'Dusk', 'Golden', 'Mist', 'Deep', 'Ghost',
];

const EPITHET_SUFFIXES = [
  'Stalker', 'Walker', 'Forged', 'Touched', 'Weaver', 'Bane', 'Warden',
  'Rider', 'Bringer', 'Bitten', 'Watcher', 'Caller', 'Strider', 'Seeker',
  'Blade', 'Heart', 'Giver', 'Singer', 'Fang', 'Breaker', 'Shield', 'Sworn',
];

const CULTURES = [
  'Sindarin', 'High Valyrian', 'Old Norse', 'Ancient Terran', 'Draconic',
  'Elder Tongue', 'Proto-Elven', 'Dwarven Runes', 'Celestial', 'Abyssal',
  'First Language', 'Aethelgardian', 'Githzerai Glyphs', 'Common Proverb',
];

const MEANING_ROOTS = [
  'Beacon of the Pale Horizon', 'Unyielding as the Mountain', 'Born of Dragonfire',
  'Shadow in the Autumn Mist', 'Keeper of the Arcane Gates', 'Song of the Golden Leaf',
  'Hammer of the Deep Stone', 'Eye of the Astral Sea', 'Whisper in the High Pines',
  'Child of the Eclipse', 'Defender of the Silent Citadel', 'Blade That Cuts the Wind',
  'Flame That Never Dies', 'Echo of the Ancient Stars', 'Tide That Swallows Kings',
  'Sovereign of the Frozen Veil', 'Light Across the Void', 'Pledge of the Eternal Oath',
];

/**
 * Create a deterministic PRNG function returning floats in [0, 1).
 * Falls back to Math.random when seed is empty/null/undefined/0.
 */
function createSeededRandom(seed) {
  if (seed === undefined || seed === null || seed === '' || seed === 0 || seed === '0') {
    return Math.random;
  }
  let s = 0;
  const seedStr = String(seed);
  for (let i = 0; i < seedStr.length; i++) {
    s = (s * 31 + seedStr.charCodeAt(i)) >>> 0;
  }
  if (s === 0) s = 1;
  return () => {
    s = (1664525 * s + 1013904223) >>> 0;
    return s / 4294967296;
  };
}

/**
 * Execute a callback while temporarily overriding Math.random with a seeded PRNG.
 */
function withSeededRandom(seed, callback) {
  if (seed === undefined || seed === null || seed === '' || seed === 0 || seed === '0') {
    return callback(Math.random);
  }
  const rng = createSeededRandom(seed);
  const oldRandom = Math.random;
  Math.random = rng;
  try {
    return callback(rng);
  } finally {
    Math.random = oldRandom;
  }
}

/**
 * Convert any string into a lowercase URL-friendly kebab-case slug.
 */
function toSlug(str) {
  return String(str || '')
    .toLowerCase()
    .replace(/[^a-z0-9]+/g, '-')
    .replace(/^-+|-+$/g, '');
}

/**
 * Format an array of generated names as plain text, JSON, CSV, or slug lines.
 */
function formatOutput(names, format = 'plain') {
  const list = Array.isArray(names) ? names : [String(names)];
  if (format === 'json') {
    return JSON.stringify(list, null, 2);
  }
  if (format === 'csv') {
    const rows = list.map((n) => `"${String(n).replace(/"/g, '""')}"`);
    return ['"name"', ...rows].join('\n');
  }
  if (format === 'slug') {
    return list.map((n) => toSlug(n)).join('\n');
  }
  return list.join('\n');
}

function isVowel(c) {
  return 'aeiouy'.includes(c.toLowerCase());
}

function countWordSyllables(rawWord) {
  const word = String(rawWord || '').replace(/[^a-zA-Z]/g, '').toLowerCase();
  if (!word) return 0;
  if (word.length <= 3) return 1;

  let syllables = 0;
  let prevIsVowel = false;
  for (let i = 0; i < word.length; i++) {
    const currentIsVowel = isVowel(word[i]);
    if (currentIsVowel && !prevIsVowel) {
      syllables++;
    }
    prevIsVowel = currentIsVowel;
  }

  if (word.endsWith('e')) {
    if (!(word.length > 2 && word[word.length - 2] === 'l' && !isVowel(word[word.length - 3]))) {
      syllables--;
    }
  }

  if (word.length > 3 && word.endsWith('ed')) {
    const beforeEd = word[word.length - 3];
    if (beforeEd !== 'd' && beforeEd !== 't') {
      syllables--;
    }
  }

  return Math.max(1, syllables);
}

/**
 * Estimate syllable count across all alphabetic tokens in a name.
 */
function countSyllables(name) {
  const tokens = String(name || '').match(/[a-zA-Z]+/g) || [];
  let total = 0;
  for (const tok of tokens) {
    total += countWordSyllables(tok);
  }
  return Math.max(1, total);
}

/**
 * Check if a multi-word name starts every alphabetic token with the same letter.
 */
function isAlliterative(name) {
  const tokens = String(name || '').match(/[a-zA-Z]+/g) || [];
  if (tokens.length < 2) return false;
  const first = tokens[0][0].toLowerCase();
  return tokens.every((t) => t[0].toLowerCase() === first);
}

function generateEpithet(rng = Math.random) {
  const p = EPITHET_PREFIXES[Math.floor(rng() * EPITHET_PREFIXES.length)];
  const s = EPITHET_SUFFIXES[Math.floor(rng() * EPITHET_SUFFIXES.length)];
  return `the ${p}-${s}`;
}

function generateMeaning(rng = Math.random) {
  const c = CULTURES[Math.floor(rng() * CULTURES.length)];
  const m = MEANING_ROOTS[Math.floor(rng() * MEANING_ROOTS.length)];
  return `${c}: "${m}"`;
}

function formatWithLore(name, rng = Math.random) {
  return `${name} ${generateEpithet(rng)} [${generateMeaning(rng)}]`;
}

/**
 * Normalize lowercase-heavy generator outputs into proper title casing
 * while preserving existing mixed-case tokens (e.g. Teken'sek, McAllister).
 */
function capitalizeProperName(name) {
  const str = String(name || '').trim();
  if (!str) return str;
  return str
    .split(/(\s+)/)
    .map((part) => {
      if (/^\s+$/.test(part)) return part;
      return part
        .split(/(-)/)
        .map((sub) => {
          if (sub === '-' || !sub) return sub;
          // Only capitalize if all lowercase or starts with lowercase letter
          if (/^[a-z]/.test(sub)) {
            return sub.charAt(0).toUpperCase() + sub.slice(1);
          }
          return sub;
        })
        .join('');
    })
    .join('');
}

module.exports = {
  createSeededRandom,
  withSeededRandom,
  toSlug,
  formatOutput,
  countSyllables,
  isAlliterative,
  generateEpithet,
  generateMeaning,
  formatWithLore,
  capitalizeProperName,
};
