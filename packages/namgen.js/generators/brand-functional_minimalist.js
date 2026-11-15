(function(root) {
  var heads = [
    "Draft", "Card", "Deck", "Lane", "Pact", "Cast", "Turn", "Hand",
    "Tile", "Board", "Grid", "Edge", "Core", "Base", "Node", "Line",
    "Path", "Gate", "Key", "Slot", "Stack", "Queue", "Seed", "Root",
    "Loop", "Beat", "Step", "Rank", "Tier", "Role", "Plan", "Form",
    "Mode", "Play", "Draw", "Flip", "Swap", "Mark"
  ];
  var tails = [
    "lane", "rift", "arena", "line", "draft", "card", "deck", "cast",
    "work", "kit", "lab", "hub", "box", "pad", "bay", "dock",
    "yard", "port", "desk", "bench", "room", "post", "way", "track",
    "trail", "band", "frame", "grid", "map", "set", "flow", "sync",
    "pipe", "sort", "mark", "lock", "point", "works"
  ];
  function pick(arr) { return arr[Math.floor(Math.random() * arr.length)]; }
  function cap(s) { return s ? s.charAt(0).toUpperCase() + s.slice(1).toLowerCase() : s; }
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["brand-functional_minimalist"] = function() {
    var head = pick(heads).toLowerCase();
    var tail = pick(tails).toLowerCase();
    for (var i = 0; i < 6 && head === tail; i++) tail = pick(tails).toLowerCase();
    return cap(head + tail);
  };
})(typeof window !== "undefined" ? window : globalThis);
