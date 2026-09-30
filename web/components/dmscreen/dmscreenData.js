// DM Screen & Campaign Studio Data Models and Procedural Tables

export const GENRE_PRESETS = {
  fantasy: {
    id: 'fantasy',
    name: 'High Fantasy & Forgotten Realms',
    icon: '🏰',
    themeColor: 'emerald',
    defaultFaction: 'The Sunfire Dominion',
    slots: [
      { id: 'monarch', title: 'Sovereign / Ruler', icon: '👑', generator: 'fantasy-kings_and_queens', desc: 'Monarch, Empress, or High King' },
      { id: 'mage', title: 'High Sage / Arch-Mage', icon: '🔮', generator: 'dungeon_and_dragons-wizards', desc: 'Court Advisor or Arcane Master' },
      { id: 'champion', title: 'Grand Champion', icon: '⚔️', generator: 'warhammer-knights', desc: 'First Blade of the Realm' },
      { id: 'citadel', title: 'Capital Citadel', icon: '🏰', generator: 'towns_and_cities-castles', desc: 'Seat of royal power' },
      { id: 'beast', title: 'Guardian Dragon / Titan', icon: '🐉', generator: 'fantasy-dragons', desc: 'Ancient mythic protector' },
      { id: 'relic', title: 'Sacred Relic / Blade', icon: '🗡️', generator: 'weapons-swords', desc: 'Ancestral divine weapon' },
      { id: 'flagship', title: 'Flagship Vessel', icon: '⛵', generator: 'military-naval_ships', desc: 'Royal flagship galley' },
      { id: 'tavern', title: 'Waypoint Tavern / Haven', icon: '🍺', generator: 'places-taverns', desc: 'Crossroads inn & rumor hub' },
    ],
  },
  grimdark: {
    id: 'grimdark',
    name: 'Grimdark & Eldritch Horror',
    icon: '💀',
    themeColor: 'purple',
    defaultFaction: 'The Ashen Inquisition',
    slots: [
      { id: 'monarch', title: 'Inquisitor General', icon: '⚖️', generator: 'fantasy-apocalypse_mutants', desc: 'Ruthless zealot overseer' },
      { id: 'mage', title: 'Blood Coven Witch', icon: '🩸', generator: 'fantasy-witches', desc: 'Practitioner of forbidden rites' },
      { id: 'champion', title: 'Executioner Knight', icon: '🪓', generator: 'warhammer_40k-chaos', desc: 'Heavy armored torturer' },
      { id: 'citadel', title: 'Black Iron Bastion', icon: '🪨', generator: 'descriptions-castles', desc: 'Cursed fortress in the mist' },
      { id: 'beast', title: 'Eldritch Abomination', icon: '🐙', generator: 'descriptions-aliens', desc: 'Entity from beyond the stars' },
      { id: 'relic', title: 'Soul-Tearer Blade', icon: '🗡️', generator: 'weapons-scythes', desc: 'Rune-carved cursed iron' },
      { id: 'flagship', title: 'Dread Ironclad', icon: '⚓', generator: 'military-naval_ships', desc: 'Black-sailed plague ship' },
      { id: 'tavern', title: 'Gallows Waypoint', icon: '🕯️', generator: 'places-taverns', desc: 'Bleak inn where locals whisper' },
    ],
  },
  scifi: {
    id: 'scifi',
    name: 'Space Opera & Cyberpunk',
    icon: '🚀',
    themeColor: 'cyan',
    defaultFaction: 'Helios Conglomerate & Navy',
    slots: [
      { id: 'monarch', title: 'Corporate CEO / High Admiral', icon: '🛰️', generator: 'star_wars_the_old_republic-siths', desc: 'Planetary syndicate ruler' },
      { id: 'mage', title: 'Rogue Netrunner / Tech-Sage', icon: '⚡', generator: 'star_wars_the_old_republic-cyborgs', desc: 'Cybernetic intelligence broker' },
      { id: 'champion', title: 'Exo-Commando Vanguard', icon: '🦾', generator: 'destiny-titans', desc: 'Armored shock infantry' },
      { id: 'citadel', title: 'Orbital Sky-Spire', icon: '🏙️', generator: 'descriptions-planets', desc: 'Station hovering above the smog' },
      { id: 'beast', title: 'Bio-Engineered Apex Weapon', icon: '🧬', generator: 'descriptions-aliens', desc: 'Escaped laboratory titan' },
      { id: 'relic', title: 'Prototype Gauss Core', icon: '🔋', generator: 'weapons-sci_fi_guns', desc: 'Pre-collapse particle beam' },
      { id: 'flagship', title: 'Dreadnought Battlecruiser', icon: '🛸', generator: 'star_wars-starships', desc: 'Capital warp vessel' },
      { id: 'tavern', title: 'Neon Sub-Level Dive Bar', icon: '🍸', generator: 'places-taverns', desc: 'Smuggler den in Sector 7' },
    ],
  },
  underdark: {
    id: 'underdark',
    name: 'Underdark Delve & Sunless Depths',
    icon: '🕳️',
    themeColor: 'indigo',
    defaultFaction: 'House of the Obsidian Web',
    slots: [
      { id: 'monarch', title: 'Drow Matron Mother', icon: '🕷️', generator: 'dungeon_and_dragons-drows', desc: 'High Priestess of the Spider Queen' },
      { id: 'mage', title: 'Mind Flayer Illithid Elder', icon: '🧠', generator: 'dungeon_and_dragons-githzerais', desc: 'Psionic telepath' },
      { id: 'champion', title: 'Shadowblade Assassin', icon: '🗡️', generator: 'the_witcher-elfs', desc: 'Poison-master of the dark tunnels' },
      { id: 'citadel', title: 'Stalactite Chasm Fortress', icon: '⛰️', generator: 'towns_and_cities-underwater_citys', desc: 'City suspended over a magma abyss' },
      { id: 'beast', title: 'Deep Purple Worm / Beholder', icon: '👁️', generator: 'fantasy-monsters', desc: 'Ancient subterranean terror' },
      { id: 'relic', title: 'Glow-Dagger of the Sunken Eye', icon: '💎', generator: 'weapons-daggers', desc: 'Blade weeping acid venom' },
      { id: 'flagship', title: 'Bioluminescent Skiff', icon: '🛶', generator: 'military-naval_ships', desc: 'Silent subterranean barge' },
      { id: 'tavern', title: 'Fungal Spore Haven', icon: '🍄', generator: 'places-taverns', desc: 'Smuggler cavern outpost' },
    ],
  },
  pirates: {
    id: 'pirates',
    name: 'High Seas & Swashbucklers',
    icon: '⚓',
    themeColor: 'amber',
    defaultFaction: 'The Crimson Corsair Fleet',
    slots: [
      { id: 'monarch', title: 'Pirate Commodore / King', icon: '🏴‍☠️', generator: 'military-royal_navy', desc: 'Elected pirate lord' },
      { id: 'mage', title: 'Storm-Caller Sea Shaman', icon: '🌊', generator: 'fantasy-witches', desc: 'Tide-weaver and wind-talker' },
      { id: 'champion', title: 'First Mate Duelist', icon: '🤺', generator: 'descriptions-characters', desc: 'Rapier virtuoso with flintlock' },
      { id: 'citadel', title: 'Smugglers Atoll Fortress', icon: '🏝️', generator: 'places-islands', desc: 'Hidden coral reef redoubt' },
      { id: 'beast', title: 'Kraken / Leviathan', icon: '🦑', generator: 'pets-marine_mammals', desc: 'Abyssal tentacled scourge' },
      { id: 'relic', title: 'Cursed Buccaneer Cutlass', icon: '⚔️', generator: 'weapons-swords', desc: 'Cutlass thirsting for salt-water blood' },
      { id: 'flagship', title: 'Ghost Man-o-War', icon: '⛵', generator: 'military-naval_ships', desc: 'Triple-decker flagship' },
      { id: 'tavern', title: 'Siren’s Grog Pit', icon: '🍺', generator: 'places-taverns', desc: 'Rowdy docks saloon' },
    ],
  },
  norse: {
    id: 'norse',
    name: 'Mythic Norse & Viking Sagas',
    icon: '🪓',
    themeColor: 'blue',
    defaultFaction: 'The Storm-Wolf Clan',
    slots: [
      { id: 'monarch', title: 'High Jarl of the Fjords', icon: '👑', generator: 'real-norwegians', desc: 'Gold-ring giver and warlord' },
      { id: 'mage', title: 'Rune-Seer Völva', icon: 'ᚱ', generator: 'fantasy-witches', desc: 'Caster of fateful carved bones' },
      { id: 'champion', title: 'Berserker Bear-Shirt', icon: '🪓', generator: 'warhammer-dwarfs', desc: 'Unflinching champion in fury' },
      { id: 'citadel', title: 'Great Mead-Hall of Pines', icon: '🪵', generator: 'towns_and_cities-viking_towns', desc: 'Timber fortress fortified with shields' },
      { id: 'beast', title: 'Frost Wyrm / Fenrir Brood', icon: '🐺', generator: 'fantasy-dragons', desc: 'Gargantuan beast of winter' },
      { id: 'relic', title: 'Thunor’s Thunder-Axe', icon: '⚡', generator: 'weapons-battle_axes', desc: 'Star-iron bearded war-axe' },
      { id: 'flagship', title: 'Dragon-Headed Longship', icon: '🛶', generator: 'military-naval_ships', desc: 'Oared war drakkar' },
      { id: 'tavern', title: 'Roaring Hearth Alehouse', icon: '🍻', generator: 'places-taverns', desc: 'Smoky longhouse with singing skalds' },
    ],
  },
};

// Procedural Tables for the "Walk into the Tavern" Generator
export const TAVERN_DATA = {
  atmospheres: [
    'A roaring central peat fire fills the room with rich birch smoke; muddy cloaks hang from iron wall hooks, and the wooden floor is strewn with fragrant pine needles.',
    'Lanterns in iron cages swing gently from oak rafters; the air is thick with roasted cumin, pipe-weed, and the rowdy strumming of a three-string lute.',
    'Dim amber candles gutter inside melted wax skulls; a tense silence lingers as cloaked sellswords exchange wary glances over foaming tankards.',
    'A bustling roadside post house where traveling merchants, caravan guards, and weary clerics huddle around long trestle tables sharing warm spiced cider.',
    'Rain batters the leaded glass windows; a cozy brick hearth crackles warmly, and an elderly dwarf bakes honeyed biscuits behind a polished copper bar.',
    'Water drips into buckets from a leaking thatched roof; sailors sing bawdy shanties as dice rattle across grease-stained walnut barrels.',
  ],
  barkeepPersonalities: [
    'A scarred retired legionnaire who polishing tankards with deliberate slowness, missing one ear and sizing up everyone who touches a weapon.',
    'A jovial stout grandmother with flour on her apron who addresses hardened mercenaries as "my ducklings" while keeping a heavy iron club under the counter.',
    'A sly half-elf with nervous darting eyes and gold rings on every finger, eager to trade drinks for gossip about nobility.',
    'A hulking half-orc with a warm baritone laugh, known for breaking up bar brawls by bodily lifting instigators through the front door.',
    'A taciturn tiefling with obsidian horns wrapped in silver wire, who speaks only in short grunts but serves exceptionally fine dwarven vintage.',
  ],
  serverPersonalities: [
    'A nimble halfling darting between tables carrying six foaming flagons at once while whistling a fast jig.',
    'A sleepy teenage farm boy who keeps dropping wooden spoons and apologizing profusely.',
    'A sharp-tongued tiefling girl who charges double for anyone who snaps their fingers at her.',
    'An aspiring bard who dramatically recites today\'s specials as if they were tragic epic poems.',
  ],
  houseSpecials: [
    { food: 'Braised Owlbear with Fire-Pepper Chutney', brew: 'Moon-Lily Golden Ale', price: '6 sp' },
    { food: 'Wild Boar Ribs glazed in Honeyed Pine Resin', brew: 'Dwarven Gutbuster Dark Stout', price: '8 sp' },
    { food: 'River Trout stuffed with Leeks and Hazelnuts', brew: 'Elderberry Spiced Mead', price: '4 sp' },
    { food: 'Venison & Morel Mushroom Pie with Flaky Suet Crust', brew: 'Dragon\'s Breath Rye Whiskey', price: '1 gp' },
    { food: 'Roasted Root Stew with Hard Mountain Cheese', brew: 'Sour Apple Cider', price: '2 sp' },
  ],
  rumors: {
    trueRumors: [
      'The old watermill at the edge of Blackfen marsh has been lit by green witch-lights at midnight; farm animals nearby are being born with two heads.',
      'A royal courier\'s horse arrived riderless at the south gate two mornings ago with its saddlebags sliced open and bearing imperial seals.',
      'The stone seal on the crypt beneath St. Jude\'s chapel cracked open during the full moon; monks haven\'t dared descend the cellar stairs since.',
    ],
    halfTrueRumors: [
      'They say the sunken vault of Lord Karas holds chests of gold coins—but nobody mentions the guardian water elemental that drowns trespassers in armor.',
      'A band of goblins in the crags wants to trade rare silver gems for livestock, though scouts claim they are being bullied by an exiled hill giant.',
      'The apothecary is paying top coin for silverleaf moss from Dead Man\'s Grotto, conveniently forgetting to mention the cave is home to blinding cave bats.',
    ],
    falseRumors: [
      'If you drop three copper pennies into the village well at dawn, an ancient spirit will grant your weapon a permanent lightning enchantment.',
      'The local baron was secretly replaced by a shapeshifting doppelgänger three months ago during the harvest festival.',
      'Elves from the northern forest are poisoning the flour shipments to force the town into signing away their logging rights.',
    ],
  },
  shadyPatrons: [
    {
      name: 'Vesper the Left-Handed',
      hook: 'Needs four mercenaries to escort a sealed lead box past the city night watch before sunrise. Asks no questions, pays 50 gp each upfront.',
    },
    {
      name: 'Sister Maeve of the Shrouded Veil',
      hook: 'Her order\'s holy relic was stolen by apostate acolytes who fled into the spider-infested catacombs; offers a potion of cure wounds as a retainer.',
    },
    {
      name: 'Captain Torvald Ironbrow',
      hook: 'His merchant vessel ran aground on the reef; he seeks divers brave enough to recover his family strongbox before the tide rises or sahuagin arrive.',
    },
  ],
};

// Procedural Tables for 5-Room Dungeon Delver
export const DUNGEON_DATA = {
  room1Entrance: [
    { name: 'The Weeping Archway', desc: 'A collapsed fissure framed by moss-choked elven relief carvings. Stale air smelling of rotten wet copper drafts upward from the abyss below.' },
    { name: 'The Submerged Portcullis', desc: 'Knee-deep murky black water lapping against rusted iron bars. Skulls carved into the stone lintel warn travelers in archaic Draconic: "Turn back or join the choir."' },
    { name: 'The Sunken Crypt Steps', desc: 'Slick marble steps descending into absolute darkness. Scorch marks along the walls indicate someone fought desperately on their way out.' },
  ],
  room2Hazards: [
    { name: 'Crushing Pendulum Hallway', dc: 'DC 14 Dexterity (Acrobatics) or DC 13 Investigation', desc: 'Pressure plates disguised as floral mosaics trigger rusted scythe blades swinging through the corridor.' },
    { name: 'The Choking Gas Basin', dc: 'DC 13 Constitution saving throw or DC 15 Thieves\' Tools', desc: 'A sunken floor filled with dense violet sulfur gas that ignites if brought into contact with an open torch flame.' },
    { name: 'The Riddle of the Broken Mirror', dc: 'DC 14 Intelligence (Arcana or Investigation)', desc: 'A silvered reflective gate that only unlocks when all light sources are extinguished and darkness is embraced.' },
  ],
  room3Setbacks: [
    { name: 'Gargoyle Watchpost', monster: '3 Stone Gargoyles & 1 Hobgoblin Sentry', desc: 'Perched high in shadowed vaulted niches, raining down stone debris before diving onto spellcasters in the rear rank.' },
    { name: 'The Slime-Filled Pit Enclosure', monster: '1 Ochre Jelly & 2 Skeletal Guardians', desc: 'The floor gives way into a sticky containment pit where ancient guardians rise from calcified bones.' },
    { name: 'The Drow Ambuscade', monster: '2 Drow Scouts with poisoned hand crossbows', desc: 'Using darkness spells and web snares to pin adventurers while retreating toward the inner sanctum.' },
  ],
  room4BossSanctums: [
    { name: 'The Obsidian Altar of the Blood Moon', boss: 'Malakor the Bone-Carver (Cult Fanatic)', lairHazard: 'At initiative count 20, blood erupts from floor channels, forcing DC 13 Str saves to avoid being swept prone.', desc: 'A cavernous circular temple illuminated by bowls of emerald fire; a chained prisoner hangs above an altar of black glass.' },
    { name: 'The Frozen Throne of the Frost Wight', boss: 'Wight Commander & 4 Ice Skeletons', lairHazard: 'Frigid winds impose disadvantage on ranged attack rolls and extinguish non-magical torches.', desc: 'Icicles like cathedral pillars hang from the ceiling; frost coats the shattered armor of fallen heroes.' },
    { name: 'The Dragon\'s Geode Hollow', boss: 'Young Shadow Drake', lairHazard: 'Sulfuric steam geysers erupt on random hexes, dealing 2d6 fire damage on failed DC 12 Dex saves.', desc: 'Crystalline stalagmites vibrate with arcane resonance as a scaly silhouette coils around a mound of tarnished silver.' },
  ],
  room5Hoards: [
    { name: 'The Gilded Reliquary', reward: '350 gp, 1,200 sp, a pearl-inlaid jewelry box (150 gp), and a sealed ivory scroll case containing a Spell Scroll of Misty Step.' },
    { name: 'The Sarcophagus of the Forgotten King', reward: '500 gp in ancient stamped platinum coins, a Potion of Greater Healing, and the Sun-Forged Battleaxe (+1).' },
    { name: 'The Alchemist\'s Hidden Stash', reward: '2 Potion of Invisibility, an uncut star sapphire (300 gp), and a curious silver pocket watch that runs backward.' },
  ],
};

// Procedural Tables for Magic Item & Loot Hoard Forge
export const LOOT_DATA = {
  weapons: [
    { name: 'Sun-Forged Longsword', type: 'Longsword (+1)', lore: 'Forged during the Siege of the Sunken Spire. Emits sunlight in a 10-foot radius when unsheathed.', val: '1,200 gp' },
    { name: 'Whispering Shadow-Dagger', type: 'Dagger (+1)', lore: 'Carried by the royal assassins of Karas. Deals an extra 1d4 psychic damage against targets surprised in dim light.', val: '950 gp' },
    { name: 'Thunder-Strike Warhammer', type: 'Warhammer (+1)', lore: 'Crafted from a fallen meteor by deep dwarven smiths. Deals max damage against stone objects and constructs.', val: '1,400 gp' },
    { name: 'Gilded Gale Bow', type: 'Longbow (+1)', lore: 'Fletcher-carved from sacred heartwood. Arrows fired suffer no penalty from non-magical gale winds.', val: '1,100 gp' },
  ],
  potions: [
    { name: 'Elixir of the Cat’s Grace', benefit: 'Advantage on Dexterity checks and fall damage halved for 1 hour.', quirk: 'User’s eyes become vertical slit pupils and purrs softly when stroked.', color: 'Iridescent Amber' },
    { name: 'Draft of Mountain Fortitude', benefit: 'Grants 15 temporary hit points and resistance to poison for 1 hour.', quirk: 'User’s skin temporarily takes on the rough texture and weight of granite.', color: 'Chalky Gray' },
    { name: 'Vial of the Zephyr Step', benefit: 'Increases walking speed by 10 ft and allows dashing as a bonus action for 10 minutes.', quirk: 'User leaves faint wisps of white morning mist in their footprints.', color: 'Pale Sky-Blue' },
    { name: 'Philter of True Sight', benefit: 'Advantage on Perception checks to detect hidden illusions for 1 hour.', quirk: 'User speaks every thought in rhyming couplets for the duration.', color: 'Glowing Violet' },
  ],
  curios: [
    { item: 'Carved ivory comb depicting a griffon hunt', val: '75 gp' },
    { item: 'Silver ceremonial chalice set with four lapis lazuli gemstones', val: '220 gp' },
    { item: 'A velvet pouch holding 12 polished bloodstone gaming dice', val: '110 gp' },
    { item: 'Ancient bronze pocket astrolabe that accurately tracks planar alignments', val: '350 gp' },
    { item: 'Embroidered silk tapestry depicting the fall of an elven kingdom', val: '400 gp' },
  ],
};

// Procedural Tables for Deep NPC Dossier Modal
export const NPC_DATA = {
  appearances: [
    'Tall and poised with silver-streaked hair swept back, wearing high-collared velvet robes lined with ermine fur and possessing an intense piercing gaze.',
    'Weather-beaten and scarred across the left cheek, dressed in oilcloth travel leathers adorned with bone talismans and smelling of salt and pipe smoke.',
    'Stocky and muscular with intricate runic tattoos trailing up their neck; carries themselves with the heavy deliberate stride of someone used to plate armor.',
    'Slender and youthful with sharp inquisitive eyes; wears immaculate silk tunics with concealed wrist-sheaths and speaks with a melodious courtly accent.',
  ],
  personalityTraits: [
    'Speaks in measured, deliberate whispers that force everyone in the room to lean forward.',
    'Fiercely protective of subordinates; remembers every promise and slight with stubborn clarity.',
    'Obsessively collects antique keys and mechanisms, fiddling with them when nervous.',
    'Dryly sarcastic under pressure, treating dire mortal perils as minor social inconveniences.',
  ],
  flaws: [
    'Deeply superstitious about ravens and the phase of the moon; refuses to sign agreements after sunset.',
    'Secretly addicted to dream-dust concoctions to cope with recurring battlefield nightmares.',
    'Arrogant beyond measure; believes ordinary peasants lack the capacity for moral judgment.',
    'Paranoid of being poisoned; insists on having food tasted or spells cast before dining.',
  ],
  darkSecrets: [
    'Is secretly indebted to a devilish arch-fiend in exchange for the power that won their current station.',
    'Orchestrated the assassination of their predecessor and framed a rival faction noble.',
    'Possesses an illegal ancient spellbook containing forbidden soul-binding necromantic rites.',
    'Is secretly funding the bandit raiders harassing the trade roads to depress land values and buy estates cheaply.',
  ],
  dialogueHooks: [
    '"Speak quickly and plainly. Flattery is the language of assassins and debt-collectors."',
    '"Ah, travelers. Fate weaves our threads together, though whether into a tapestry or a hangman\'s noose remains to be seen."',
    '"Every man has his price, friend. Some take gold; others prefer silence. Which are you buying today?"',
    '"You step into my domain carrying steel and ambition. Be careful that the latter does not dull the former."',
  ],
};
