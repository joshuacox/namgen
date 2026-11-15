const wordsData = require('../data/words.json');
const {
  withSeededRandom,
  countSyllables,
  isAlliterative,
  formatWithLore,
} = require('./formatters');

/**
 * Generate adjective + noun combinations with CLI-compatible formatting and filters.
 */
function generateCombinations(options = {}) {
  const {
    count = 5,
    seed = '',
    unique = false,
    separator = '-',
    nullSeparator = false,
    casing = 'normal',
    exclude = "-'",
    matchRegex = '',
    alliterate = false,
    syllables = 0,
    minLen = 0,
    maxLen = 0,
    withLore = false,
    adjectives = wordsData.adjectives,
    nouns = wordsData.nouns,
  } = options;

  const excludeSet = new Set(String(exclude || '').split(''));
  const filterWord = (w) =>
    String(w)
      .split('')
      .filter((c) => !excludeSet.has(c))
      .join('');

  let regexObj = null;
  if (matchRegex) {
    try {
      regexObj = new RegExp(matchRegex);
    } catch (_) {
      regexObj = null;
    }
  }

  return withSeededRandom(seed, (rng) => {
    const results = [];
    const seen = new Set();
    let attempts = 0;
    const maxAttempts = count * 120 + 500;

    while (results.length < count && attempts < maxAttempts) {
      attempts++;
      let adj = adjectives[Math.floor(rng() * adjectives.length)] || 'silent';
      let noun = nouns[Math.floor(rng() * nouns.length)] || 'forest';

      adj = filterWord(adj);
      noun = filterWord(noun);
      if (!adj || !noun) continue;

      if (casing === 'cap') {
        adj = adj.charAt(0).toUpperCase() + adj.slice(1).toLowerCase();
        noun = noun.charAt(0).toUpperCase() + noun.slice(1).toLowerCase();
      } else if (casing === 'camel') {
        adj = adj.toLowerCase();
        noun = noun.charAt(0).toUpperCase() + noun.slice(1).toLowerCase();
      } else {
        adj = adj.toLowerCase();
        noun = noun.toLowerCase();
      }

      const sep = nullSeparator ? '' : separator;
      let candidate = `${adj}${sep}${noun}`;

      if (minLen > 0 && candidate.length < minLen) continue;
      if (maxLen > 0 && candidate.length > maxLen) continue;
      if (syllables > 0 && countSyllables(candidate) !== syllables) continue;
      if (alliterate && !isAlliterative(candidate)) continue;
      if (regexObj && !regexObj.test(candidate)) continue;

      if (withLore) {
        candidate = formatWithLore(candidate, rng);
      }

      if (unique) {
        if (!seen.has(candidate)) {
          seen.add(candidate);
          results.push(candidate);
        }
      } else {
        results.push(candidate);
      }
    }

    return results;
  });
}

/**
 * Check whether a generated string matches active linguistic/regex constraints.
 */
function passesConstraints(val, options = {}) {
  const {
    matchRegex = '',
    alliterate = false,
    syllables = 0,
    minLen = 0,
    maxLen = 0,
  } = options;

  if (minLen > 0 && val.length < minLen) return false;
  if (maxLen > 0 && val.length > maxLen) return false;
  if (syllables > 0 && countSyllables(val) !== syllables) return false;
  if (alliterate && !isAlliterative(val)) return false;
  if (matchRegex) {
    try {
      const re = new RegExp(matchRegex);
      if (!re.test(val)) return false;
    } catch (_) {
      // Ignore invalid user-entered regex mid-typing
    }
  }
  return true;
}

/**
 * Execute a procedural generator function (type?: number) => string with seed, uniqueness, and filters.
 */
function executeGeneratorFn(fn, count = 1, options = {}) {
  const {
    seed = '',
    unique = false,
    type = 0,
    withLore = false,
  } = options;

  return withSeededRandom(seed, (rng) => {
    const results = [];
    const seen = new Set();
    let attempts = 0;
    const maxAttempts = count * 80 + 300;

    while (results.length < count && attempts < maxAttempts) {
      attempts++;
      let val;
      try {
        const raw = fn(type);
        val = typeof raw === 'string' ? raw.trim() : String(raw || '').trim();
      } catch (err) {
        break;
      }
      if (!val) continue;
      if (!passesConstraints(val, options)) continue;

      const finalVal = withLore ? formatWithLore(val, rng) : val;
      if (unique) {
        if (!seen.has(finalVal)) {
          seen.add(finalVal);
          results.push(finalVal);
        }
      } else {
        results.push(finalVal);
      }
    }

    return results;
  });
}

/**
 * Compose multiple generator functions using a template like "{1} of {2}".
 */
function composeGenerators(fns, template = '{1} {2}', count = 1, options = {}) {
  if (!Array.isArray(fns) || fns.length === 0) return [];
  const { seed = '', unique = false, type = 0, withLore = false } = options;

  return withSeededRandom(seed, (rng) => {
    const results = [];
    const seen = new Set();
    let attempts = 0;
    const maxAttempts = count * 80 + 300;

    while (results.length < count && attempts < maxAttempts) {
      attempts++;
      const parts = fns.map((fn) => {
        try {
          const raw = fn(type);
          return (typeof raw === 'string' ? raw : String(raw || '')).trim();
        } catch (_) {
          return '';
        }
      });
      if (parts.some((p) => !p)) continue;

      let out = template;
      parts.forEach((part, idx) => {
        out = out.split(`{${idx + 1}}`).join(part);
      });
      out = out.trim();
      if (!passesConstraints(out, options)) continue;

      const finalVal = withLore ? formatWithLore(out, rng) : out;
      if (unique) {
        if (!seen.has(finalVal)) {
          seen.add(finalVal);
          results.push(finalVal);
        }
      } else {
        results.push(finalVal);
      }
    }

    return results;
  });
}

module.exports = {
  generateCombinations,
  executeGeneratorFn,
  composeGenerators,
  passesConstraints,
};
