(function(root) {
  var onsets = [
    "V", "K", "Z", "Th", "Or", "X", "Dr", "Br", "Kr", "Vr",
    "Ny", "Ly", "Syl", "R", "T", "M", "N", "S", "Al", "El",
    "Val", "Mal", "Sol", "Vor", "Cor", "Tor", "Kal", "Zor", "Ryn", "Fen",
    "Cael", "Vyr", "Oph", "Ael"
  ];
  var nuclei = ["a", "e", "i", "o", "ae", "ai", "au", "ei", "ia", "io", "ou", "y"];
  var codas = ["", "x", "v", "l", "n", "r", "th", "z", "k", "m", "s", "nd", "lt", "st", "rk", "nx"];
  var endings = [
    "ora", "ith", "ar", "is", "ax", "ix", "on", "ia",
    "en", "os", "um", "ara", "yra", "eon", "eth", "orn",
    "ane", "ova", "ux", "el", "ir", "alis", "oris", "axis"
  ];
  function isVowel(c) { return "aeiouy".indexOf((c || "").toLowerCase()) !== -1; }
  function pick(arr) { return arr[Math.floor(Math.random() * arr.length)]; }
  function cap(s) { return s ? s.charAt(0).toUpperCase() + s.slice(1).toLowerCase() : s; }
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["brand-sovereign_neologisms"] = function() {
    var onset = pick(onsets);
    var nucleus = isVowel(onset.slice(-1)) ? "" : pick(nuclei);
    var coda = pick(codas);
    var ending = pick(endings);
    if (!coda && isVowel(ending.charAt(0))) {
      coda = codas[1 + Math.floor(Math.random() * 10)];
    }
    return cap((onset + nucleus + coda + ending).replace(/(.)\1\1+/gi, "$1$1"));
  };
})(typeof window !== "undefined" ? window : globalThis);
