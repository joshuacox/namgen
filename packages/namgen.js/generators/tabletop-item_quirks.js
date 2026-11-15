(function(root) {
  var origins = [
    "Forged by a sleepless dwarven smith to settle a wager,",
    "Salvaged from an astral galleon's ballast,",
    "Engraved in spiral Runic by a penitent warlock,",
    "Steeped for seventy winters in volcanic springwater,",
    "Stolen from the dowry of a cloud-giant duchess,",
    "Bound in pale wyvern vellum and stitched with silver wire,",
    "Etched with microscopic constellations across the pommel,",
    "Pried from the gauntlet of a petrified paladin,",
    "Cooled in moonlight rather than hearthwater,",
    "Bartered from a blind ferryman on the Styx,",
    "Fused together after two rival wands misfired,",
    "Blessed under a double eclipse by a heretic abbot,",
    "Inlaid with sea-glass from an unreachable trench,",
    "Carved from the heartwood of a lightning-split treant,"
  ];
  var tells = [
    "it grows perceptibly warmer whenever an oath is broken nearby",
    "it softly hums a sea shanty during rainstorms",
    "it refuses to cast a shadow under open starlight",
    "its reflection in water looks tarnished and centuries older",
    "it leaves tiny frost crystals on stone tables",
    "it gently vibrates toward the nearest unspent gold coin",
    "it smells faintly of pine smoke and wet slate after combat",
    "its weight doubles if carried by someone hiding a lie",
    "it quietly ticks like a pocketwatch when danger waits beyond a door",
    "spiders weave tiny geometric sigils across it overnight",
    "candles within ten feet burn with an emerald core",
    "any ink spilled near it spells out the wielder's birthplace",
    "it sheds harmless copper-colored sparks on a critical hit",
    "it becomes weightless for one heartbeat at midnight"
  ];
  var quirks = [
    "and stubbornly compels its owner to tip innkeepers generously.",
    "and demands a polished pebble be tucked beside it each camp.",
    "and whistles indignantly whenever drawn against beasts smaller than a wolf.",
    "and turns common vinegar into tolerable spiced cider once per dusk.",
    "and remembers the true name of every previous wielder in brief dreams.",
    "and cannot abide the sound of poorly tuned brass horns.",
    "and leaves harmless chalk arrows pointing north when dropped.",
    "and causes horses to eye the bearer with unearned respect.",
    "and resets nearby hourglasses if tapped twice against oak.",
    "and grants crisp clarity to whispered prayers.",
    "and faintly tints spilled tea blue for an hour.",
    "and stubbornly rolls uphill if left unattended on slopes."
  ];
  function pick(arr) { return arr[Math.floor(Math.random() * arr.length)]; }
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["tabletop-item_quirks"] = function() {
    return pick(origins) + " " + pick(tells) + " " + pick(quirks);
  };
})(typeof window !== "undefined" ? window : globalThis);
