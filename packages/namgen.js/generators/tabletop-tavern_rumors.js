(function(root) {
  var speakers = [
    "Two dockhands over watered ale swear",
    "The one-eyed cooper mutters that",
    "A frostbitten trapper insists",
    "Gossip by the hearth claims",
    "The stableboy whispers for a copper that",
    "An off-duty watchman boasts in his cups that",
    "A travelling tinker warns anyone listening that",
    "Old Widow Vane tells the bartender that",
    "A trio of mud-caked prospectors argue whether",
    "The bard tunes a snapped lute string and murmurs",
    "A hooded herbalist trades word that",
    "A half-asleep charcoal burner mumbles that",
    "The innkeeper's parrot keeps repeating that",
    "Notice-board loungers bet three silvers that"
  ];
  var subjects = [
    "the ruined watchtower on Crow Ridge",
    "the basement beneath the chandler's shop",
    "the old quarry ferry",
    "the magistrate's prize greyhound",
    "the moss-choked millwheel east of town",
    "Baron Kestrel's tax barge",
    "the ironbound fountain in the Old Ward",
    "every crow within five miles of the crossroads",
    "the apothecary's copper still",
    "the sunken chapel belltower",
    "a hooded stranger in velvet spurs",
    "the lantern-lighter's night shift",
    "the northern timber road",
    "the alchemist's condemned greenhouse"
  ];
  var claims = [
    "echoes with hammered anvil-strokes whenever a storm gathers",
    "changes architecture every third Tuesday after curfew",
    "swallows coin dropped near it and spits out tarnished bone keys",
    "has been quietly buying up every silver mirror in the shire",
    "was spotted moving against the river current without oars",
    "smells strongly of ozone and burnt cinnamon around twilight",
    "guides lost livestock straight to an overgrown marble staircase",
    "pays double wages to recruits who promise never to carry iron",
    "froze solid during midsummer noon without melting a single icicle",
    "speaks three words of High Draconic whenever horses pass by",
    "conceals a bricked-up tunnel leading straight under the keep",
    "marks anyone who camps there with a faint copper handprint",
    "hosts hooded card games where debts are paid in childhood memories",
    "keeps spitting blue sparks down the well shaft after moonrise"
  ];
  function pick(arr) { return arr[Math.floor(Math.random() * arr.length)]; }
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["tabletop-tavern_rumors"] = function() {
    return pick(speakers) + " " + pick(subjects) + " " + pick(claims) + ".";
  };
})(typeof window !== "undefined" ? window : globalThis);
