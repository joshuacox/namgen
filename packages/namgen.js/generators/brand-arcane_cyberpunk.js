(function(root) {
  var arcanePrefixes = [
    "Hex", "Sigil", "Rune", "Void", "Vex", "Aether", "Astral", "Chrono",
    "Nyx", "Crypt", "Omen", "Arc", "Glyph", "Ward", "Grim", "Pyre",
    "Gloom", "Soul", "Lich", "Abyss", "Spell", "Mana", "Warp", "Veil",
    "Dusk", "Shad", "Bane", "Rift", "Pact", "Curse", "Tome", "Relic",
    "Nex", "Prism", "Orb", "Coven", "Thorn", "Kabal", "Wyrm", "Specter",
    "Sable", "Occult"
  ];
  var cyberSuffixes = [
    "grid", "stack", "frame", "node", "mesh", "pulse", "synth", "bit",
    "byte", "core", "port", "link", "flux", "wire", "vault", "cipher",
    "hash", "shunt", "loop", "shard", "ware", "bot", "chrome", "neon",
    "spark", "vec", "kern", "sock", "trace", "ping", "proxy", "gate",
    "rail", "deck", "net", "drive", "code", "matrix", "logic", "rig",
    "stream", "volt"
  ];
  var cyberPrefixes = [
    "Neon", "Cyber", "Nano", "Volt", "Zero", "Synth", "Kilo", "Hyper",
    "Data", "Proto", "Chrome", "Bit", "Net", "Grid", "Glitch", "Laser",
    "Neuro", "Quantum", "Ion", "Vector", "Pulse", "Proxy", "Chip", "Wire"
  ];
  var arcaneRoots = [
    "pakt", "rune", "hex", "sigil", "ward", "tome", "rift", "spell",
    "omen", "veil", "glyph", "crypt", "pyre", "mana", "bane", "soul",
    "lore", "craft", "cast", "spire", "grimoire", "nexus", "vault", "crest"
  ];
  function pick(arr) { return arr[Math.floor(Math.random() * arr.length)]; }
  function cap(s) { return s ? s.charAt(0).toUpperCase() + s.slice(1).toLowerCase() : s; }
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["brand-arcane_cyberpunk"] = function() {
    return Math.random() < 0.67
      ? cap(pick(arcanePrefixes) + pick(cyberSuffixes))
      : cap(pick(cyberPrefixes) + pick(arcaneRoots));
  };
})(typeof window !== "undefined" ? window : globalThis);
