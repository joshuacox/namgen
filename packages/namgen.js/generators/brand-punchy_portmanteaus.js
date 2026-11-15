(function(root) {
  var heads = [
    "Deck", "Spell", "Summon", "Mana", "Draft", "Rune", "Card", "Crit",
    "Quest", "Hex", "Blade", "Shield", "Guild", "Crest", "Moba", "Arena",
    "Lane", "Turn", "Hand", "Draw", "Buff", "Raid", "Boss", "Craft",
    "Forge", "Brawl", "Clash", "Blitz", "Snap", "Flip", "Spark", "Surge",
    "Pulse", "Dash", "Strike", "Vault", "Tower", "Loot", "Pact", "Charm"
  ];
  var tails = [
    "brawl", "clash", "rift", "cast", "deck", "craft", "moba", "pact",
    "lock", "drop", "roll", "stack", "forge", "blast", "rush", "leap",
    "guard", "ward", "link", "swap", "flip", "grid", "zone", "ring",
    "run", "duel", "brew", "meld", "splice", "spark", "wave", "shift",
    "spike", "vault", "keep", "gate", "core", "surge", "strike", "deck"
  ];
  function pick(arr) { return arr[Math.floor(Math.random() * arr.length)]; }
  function cap(s) { return s ? s.charAt(0).toUpperCase() + s.slice(1).toLowerCase() : s; }
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["brand-punchy_portmanteaus"] = function() {
    var head = pick(heads).toLowerCase();
    var tail = pick(tails).toLowerCase();
    for (var i = 0; i < 6 && head === tail; i++) tail = pick(tails).toLowerCase();
    if (head.length >= 3 && tail.length >= 3 && head.slice(-2) === tail.slice(0, 2)) {
      return cap(head + tail.slice(2));
    }
    if (head.length >= 3 && tail.length >= 3 && head.slice(-1) === tail.charAt(0)) {
      return cap(head + tail.slice(1));
    }
    return cap(head + tail);
  };
})(typeof window !== "undefined" ? window : globalThis);
