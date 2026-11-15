(function(root) {
  var roots = [
    "Anim", "Bellum", "Locus", "Myth", "Aegis", "Pact", "Chrono", "Vita",
    "Nex", "Lex", "Vox", "Velo", "Astra", "Sol", "Lun", "Ignis",
    "Ferr", "Cor", "Lux", "Noct", "Veri", "Ars", "Magn", "Omni",
    "Ordo", "Virt", "Fide", "Aura", "Kinet", "Logos", "Ethos", "Pathos",
    "Thalass", "Pyro", "Cryo", "Helio", "Morph", "Praxis", "Telos", "Vexil",
    "Arcan", "Dom"
  ];
  var suffixes = [
    "mancy", "craft", "pact", "arch", "deck", "arium", "orium", "ex",
    "axis", "alis", "ia", "ica", "ius", "on", "um", "is",
    "nomia", "logia", "cracy", "scope", "sphere", "guard", "forge", "script",
    "spire", "nexus", "codex", "fex", "trix", "vor", "ward", "dom",
    "os", "gen", "lith", "thesis"
  ];
  function isVowel(c) { return "aeiouy".indexOf((c || "").toLowerCase()) !== -1; }
  function pick(arr) { return arr[Math.floor(Math.random() * arr.length)]; }
  function cap(s) { return s ? s.charAt(0).toUpperCase() + s.slice(1).toLowerCase() : s; }
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["brand-classical_etymology"] = function() {
    var head = pick(roots);
    var tail = pick(suffixes);
    if (head && tail && head.slice(-1).toLowerCase() === tail.charAt(0).toLowerCase() && isVowel(tail.charAt(0))) {
      head = head.slice(0, -1);
    }
    return cap(head + tail);
  };
})(typeof window !== "undefined" ? window : globalThis);
