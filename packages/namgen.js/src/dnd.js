/**
 * D&D 5e & Tabletop RPG Datasets for namgen.js
 * Every generator ID referenced here is verified against data/generators.json.
 */

const DND_ANCESTRIES = [
  { id: 'human', label: 'Human', icon: '🧑', generator: 'dungeon_and_dragons-humans', surnameGenerator: 'fantasy-fantasy_surnames', supportsGenderType: true, traits: 'Versatile, ambitious, varied naming traditions across realms.' },
  { id: 'elf', label: 'Elf', icon: '🧝', generator: 'dungeon_and_dragons-elfs', surnameGenerator: 'fantasy-fantasy_surnames', supportsGenderType: true, traits: 'Long-lived sylvan folk with melodic, vowel-rich names.' },
  { id: 'eladrin', label: 'High Eladrin (Fey)', icon: '✨', generator: 'dungeon_and_dragons-eladrins', surnameGenerator: null, supportsGenderType: true, traits: 'Feywild elves tied to the four seasons and shifting moods.' },
  { id: 'drow', label: 'Drow (Dark Elf)', icon: '🕷️', generator: 'dungeon_and_dragons-drows', surnameGenerator: null, supportsGenderType: true, traits: 'Underdark noble houses with sharp, sibilant house names.' },
  { id: 'dwarf', label: 'Dwarf', icon: '⛏️', generator: 'dungeon_and_dragons-dwarfs', surnameGenerator: null, supportsGenderType: true, traits: 'Clan-proud smiths and delvers with hard consonant names.' },
  { id: 'halfling', label: 'Halfling', icon: '🍀', generator: 'dungeon_and_dragons-halflings', surnameGenerator: 'fantasy-fantasy_surnames', supportsGenderType: true, traits: 'Hospitable hearthfolk bearing warm, rustic family names.' },
  { id: 'gnome', label: 'Gnome', icon: '⚙️', generator: 'dungeon_and_dragons-gnomes', surnameGenerator: null, supportsGenderType: true, traits: 'Curious tinkerers and illusionists known for many nicknames.' },
  { id: 'dragonborn', label: 'Dragonborn', icon: '🐲', generator: 'dungeon_and_dragons-dragonborns', surnameGenerator: null, supportsGenderType: true, traits: 'Clan-first draconic warriors with resonant syllables.' },
  { id: 'tiefling', label: 'Tiefling', icon: '😈', generator: 'dungeon_and_dragons-tieflings', surnameGenerator: null, supportsGenderType: true, traits: 'Infernal bloodlines bearing ancient names or chosen virtues.' },
  { id: 'half_elf', label: 'Half-Elf', icon: '🌿', generator: 'dungeon_and_dragons-half_elfs', surnameGenerator: 'fantasy-fantasy_surnames', supportsGenderType: true, traits: 'Bridging two worlds with blended human and elven cadence.' },
  { id: 'half_orc', label: 'Half-Orc', icon: '🪓', generator: 'dungeon_and_dragons-half_orcs', surnameGenerator: null, supportsGenderType: true, traits: 'Fierce frontier survivors with guttural, punchy names.' },
  { id: 'goliath', label: 'Goliath', icon: '🏔️', generator: 'dungeon_and_dragons-goliaths', surnameGenerator: null, supportsGenderType: true, traits: 'Mountain nomads given earned deed-names alongside clan names.' },
  { id: 'aasimar', label: 'Aasimar', icon: '🕊️', generator: 'pathfinder-aasimars', surnameGenerator: null, supportsGenderType: true, traits: 'Celestial-touched mortals bearing luminous, solemn names.' },
  { id: 'deva', label: 'Deva (Celestial)', icon: '🌟', generator: 'dungeon_and_dragons-devas', surnameGenerator: null, supportsGenderType: true, traits: 'Reincarnating astral spirits carrying memories of past lives.' },
  { id: 'tabaxi', label: 'Tabaxi / Catfolk', icon: '🐆', generator: 'pathfinder-catfolks', surnameGenerator: null, supportsGenderType: true, traits: 'Wandering curiosity-seekers inspired by stories and omens.' },
  { id: 'kenku', label: 'Kenku / Tengu', icon: '🪶', generator: 'pathfinder-tengus', surnameGenerator: null, supportsGenderType: true, traits: 'Corvid tricksters and mimics of city alleys and rooftops.' },
  { id: 'minotaur', label: 'Minotaur', icon: '🐂', generator: 'dungeon_and_dragons-minotaurs', surnameGenerator: null, supportsGenderType: true, traits: 'Labyrinthine mariners and shock-troops of ancient horns.' },
  { id: 'shifter', label: 'Shifter', icon: '🐺', generator: 'dungeon_and_dragons-shifters', surnameGenerator: null, supportsGenderType: false, traits: 'Lycanthrope-descended hunters named after seasons and beasts.' },
  { id: 'githzerai', label: 'Githzerai', icon: '🔮', generator: 'dungeon_and_dragons-githzerais', surnameGenerator: null, supportsGenderType: true, traits: 'Astral Sea psionic monks tempered in Limbo chaos.' },
  { id: 'genasi_fire', label: 'Fire Genasi (Ifrit)', icon: '🔥', generator: 'pathfinder-ifrits', surnameGenerator: null, supportsGenderType: true, traits: 'Plane-touched embers with crackling, fierce names.' },
  { id: 'genasi_earth', label: 'Earth Genasi (Oread)', icon: '🪨', generator: 'pathfinder-oreads', surnameGenerator: null, supportsGenderType: true, traits: 'Stoic stone-blooded crafters with grounded names.' },
  { id: 'genasi_air', label: 'Air Genasi (Sylph)', icon: '💨', generator: 'pathfinder-sylphs', surnameGenerator: null, supportsGenderType: true, traits: 'Breezy, swift observers with whispering names.' },
  { id: 'genasi_water', label: 'Water Genasi (Undine)', icon: '🌊', generator: 'pathfinder-undines', surnameGenerator: null, supportsGenderType: true, traits: 'Tidal wanderers with flowing, fluid syllables.' },
  { id: 'goblin', label: 'Goblin', icon: '👺', generator: 'fantasy-goblins', surnameGenerator: null, supportsGenderType: false, traits: 'Cunning cavern scavengers and ambushers.' },
  { id: 'kobold', label: 'Kobold', icon: '🦎', generator: 'pathfinder-kobolds', surnameGenerator: null, supportsGenderType: false, traits: 'Trap-setting dragon-worshippers with yipping monosyllables.' },
  { id: 'orc', label: 'Orc', icon: '💀', generator: 'fantasy-orcs', surnameGenerator: null, supportsGenderType: false, traits: 'Warband raiders honoring scars, thunder, and strength.' },
  { id: 'dragon', label: 'Dragon', icon: '🐉', generator: 'fantasy-dragons', surnameGenerator: null, supportsGenderType: false, traits: 'Ancient wyrms bearing millennia-old Draconic titles.' },
  { id: 'demon', label: 'Fiend / Demon', icon: '🔥', generator: 'fantasy-demons', surnameGenerator: null, supportsGenderType: false, traits: 'Abyssal and infernal true names best whispered softly.' },
  { id: 'vampire', label: 'Vampire Noble', icon: '🦇', generator: 'fantasy-vampires', surnameGenerator: 'miscellaneous-noble_houses', supportsGenderType: true, traits: 'Aristocratic immortals of midnight courts.' },
  { id: 'lich', label: 'Lich / Arch-Undead', icon: '☠️', generator: 'fantasy-lichs', surnameGenerator: null, supportsGenderType: false, traits: 'Phylactery-bound sorcerers forgotten by mortal kingdoms.' },
];

const HUMAN_CULTURES = [
  { id: 'norse', label: 'Northern Fjords (Norse)', generator: 'real-norwegians' },
  { id: 'celtic', label: 'Highland Clans (Celtic)', generator: 'real-celtics' },
  { id: 'roman', label: 'Imperial Republic (Roman)', generator: 'real-romans' },
  { id: 'greek', label: 'City-States (Ancient Greek)', generator: 'real-ancient_greeks' },
  { id: 'egyptian', label: 'Sun Kingdoms (Egyptian)', generator: 'real-egyptians' },
  { id: 'persian', label: 'Silk Empire (Persian)', generator: 'real-persians' },
  { id: 'japanese', label: 'Island Shogunate (Japanese)', generator: 'real-japaneses' },
  { id: 'french', label: 'Chivalric Court (French)', generator: 'real-frenchs' },
  { id: 'russian', label: 'Frost Tsardom (Russian)', generator: 'real-russians' },
  { id: 'anglo', label: 'Old Shires (Anglo-Saxon)', generator: 'real-anglo_saxons' },
];

/**
 * 6 Campaign Genre Faction Matrices — every slot generator verified against generators.json.
 */
const GENRE_PRESETS = {
  fantasy: {
    id: 'fantasy',
    name: 'High Fantasy & Forgotten Realms',
    icon: '🏰',
    themeColor: 'emerald',
    defaultFaction: 'The Sunfire Dominion',
    slots: [
      { id: 'monarch', title: 'Sovereign / Noble House', icon: '👑', generator: 'miscellaneous-noble_houses', desc: 'Ruling dynasty or crown house' },
      { id: 'mage', title: 'High Sage / Arch-Mage', icon: '🔮', generator: 'fantasy-wizards', desc: 'Court advisor or arcane master' },
      { id: 'champion', title: 'Grand Champion', icon: '⚔️', generator: 'fantasy-knights', desc: 'First Blade of the Realm' },
      { id: 'citadel', title: 'Capital Citadel', icon: '🏰', generator: 'places-castles', desc: 'Seat of royal power' },
      { id: 'beast', title: 'Guardian Dragon / Titan', icon: '🐉', generator: 'fantasy-dragons', desc: 'Ancient mythic protector' },
      { id: 'relic', title: 'Sacred Relic / Blade', icon: '🗡️', generator: 'weapons-swords', desc: 'Ancestral divine weapon' },
      { id: 'flagship', title: 'Flagship Vessel', icon: '⛵', generator: 'miscellaneous-ships', desc: 'Royal flagship galleon' },
      { id: 'tavern', title: 'Waypoint Tavern / Inn', icon: '🍺', generator: 'places-inns', desc: 'Crossroads inn & rumor hub' },
    ],
  },
  grimdark: {
    id: 'grimdark',
    name: 'Grimdark & Eldritch Horror',
    icon: '💀',
    themeColor: 'purple',
    defaultFaction: 'The Ashen Inquisition',
    slots: [
      { id: 'monarch', title: 'Inquisitor / Zealot', icon: '⚖️', generator: 'fantasy-apocalypse_mutants', desc: 'Ruthless zealot overseer' },
      { id: 'mage', title: 'Blood Coven Witch', icon: '🩸', generator: 'fantasy-witchs', desc: 'Practitioner of forbidden rites' },
      { id: 'champion', title: 'Executioner Knight', icon: '🪓', generator: 'warhammer_40k-chaos', desc: 'Heavy armored torturer' },
      { id: 'citadel', title: 'Black Iron Bastion', icon: '🪨', generator: 'places-castles', desc: 'Cursed fortress in the mist' },
      { id: 'beast', title: 'Eldritch Abomination', icon: '🐙', generator: 'fantasy-monsters', desc: 'Entity from beyond the veil' },
      { id: 'relic', title: 'Soul-Tearer Scythe', icon: '🗡️', generator: 'weapons-scythes', desc: 'Rune-carved cursed iron' },
      { id: 'flagship', title: 'Dread Ironclad', icon: '⚓', generator: 'miscellaneous-ships', desc: 'Black-sailed plague ship' },
      { id: 'tavern', title: 'Gallows Waypoint', icon: '🕯️', generator: 'places-inns', desc: 'Bleak inn where locals whisper' },
    ],
  },
  scifi: {
    id: 'scifi',
    name: 'Spelljammer & Space Opera',
    icon: '🚀',
    themeColor: 'cyan',
    defaultFaction: 'Helios Conglomerate & Navy',
    slots: [
      { id: 'monarch', title: 'Syndicate Lord / Sith', icon: '🛰️', generator: 'star_wars_the_old_republic-siths', desc: 'Planetary syndicate ruler' },
      { id: 'mage', title: 'Rogue Netrunner / Cyborg', icon: '⚡', generator: 'star_wars_the_old_republic-cyborgs', desc: 'Cybernetic intelligence broker' },
      { id: 'champion', title: 'Exo-Commando Vanguard', icon: '🦾', generator: 'destiny-exos', desc: 'Armored shock infantry' },
      { id: 'citadel', title: 'Orbital Sky-Spire', icon: '🏙️', generator: 'places-space_colonys', desc: 'Station hovering above the smog' },
      { id: 'beast', title: 'Void Leviathan / Alien', icon: '🧬', generator: 'fantasy-aliens', desc: 'Astral void predator' },
      { id: 'relic', title: 'Prototype Gauss Core', icon: '🔋', generator: 'weapons-sci_fi_guns', desc: 'Pre-collapse particle beam' },
      { id: 'flagship', title: 'Dreadnought Battlecruiser', icon: '🛸', generator: 'miscellaneous-spaceships', desc: 'Capital warp vessel' },
      { id: 'tavern', title: 'Neon Sub-Level Dive Bar', icon: '🍸', generator: 'places-nightclubs', desc: 'Smuggler den in Sector 7' },
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
      { id: 'mage', title: 'Psionic Telepath Elder', icon: '🧠', generator: 'dungeon_and_dragons-githzerais', desc: 'Master of unseen mind arts' },
      { id: 'champion', title: 'Shadowblade Assassin', icon: '🗡️', generator: 'the_witcher-elfs', desc: 'Poison-master of the dark tunnels' },
      { id: 'citadel', title: 'Stalactite Chasm City', icon: '⛰️', generator: 'towns_and_cities-underwater_citys', desc: 'City suspended over a magma abyss' },
      { id: 'beast', title: 'Deep Cavern Terror', icon: '👁️', generator: 'fantasy-monsters', desc: 'Ancient subterranean beast' },
      { id: 'relic', title: 'Venom Fang Dagger', icon: '💎', generator: 'weapons-daggers', desc: 'Blade weeping acid venom' },
      { id: 'flagship', title: 'Sunless Sea Barge', icon: '🛶', generator: 'miscellaneous-ships', desc: 'Silent subterranean skiff' },
      { id: 'tavern', title: 'Fungal Spore Outpost', icon: '🍄', generator: 'places-inns', desc: 'Smuggler cavern tavern' },
    ],
  },
  pirates: {
    id: 'pirates',
    name: 'High Seas & Swashbucklers',
    icon: '⚓',
    themeColor: 'amber',
    defaultFaction: 'The Crimson Corsair Fleet',
    slots: [
      { id: 'monarch', title: 'Pirate Commodore', icon: '🏴‍☠️', generator: 'fantasy-pirates', desc: 'Elected pirate lord' },
      { id: 'mage', title: 'Storm-Caller Sea Witch', icon: '🌊', generator: 'fantasy-witchs', desc: 'Tide-weaver and wind-talker' },
      { id: 'champion', title: 'First Mate Duelist', icon: '🤺', generator: 'military-royal_navy', desc: 'Rapier virtuoso with flintlock' },
      { id: 'citadel', title: 'Smugglers Atoll Fortress', icon: '🏝️', generator: 'places-islands', desc: 'Hidden coral reef redoubt' },
      { id: 'beast', title: 'Kraken / Sea Leviathan', icon: '🦑', generator: 'pets-marine_mammals', desc: 'Abyssal tentacled scourge' },
      { id: 'relic', title: 'Cursed Buccaneer Cutlass', icon: '⚔️', generator: 'weapons-swords', desc: 'Cutlass thirsting for salt-water blood' },
      { id: 'flagship', title: 'Ghost Man-o-War', icon: '⛵', generator: 'miscellaneous-pirate_ships', desc: 'Triple-decker flagship' },
      { id: 'tavern', title: 'Siren’s Grog Pit', icon: '🍺', generator: 'places-pirate_coves', desc: 'Rowdy docks hideout' },
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
      { id: 'mage', title: 'Rune-Seer Völva', icon: 'ᚱ', generator: 'fantasy-witchs', desc: 'Caster of fateful carved bones' },
      { id: 'champion', title: 'Berserker Bear-Shirt', icon: '🪓', generator: 'warhammer-dwarfs', desc: 'Unflinching champion in fury' },
      { id: 'citadel', title: 'Great Mead-Hall of Pines', icon: '🪵', generator: 'towns_and_cities-viking_towns', desc: 'Timber fortress fortified with shields' },
      { id: 'beast', title: 'Frost Wyrm / Fenrir Brood', icon: '🐺', generator: 'fantasy-dragons', desc: 'Gargantuan beast of winter' },
      { id: 'relic', title: 'Thunor’s Thunder-Axe', icon: '⚡', generator: 'weapons-battle_axes', desc: 'Star-iron bearded war-axe' },
      { id: 'flagship', title: 'Dragon-Headed Longship', icon: '🛶', generator: 'miscellaneous-ships', desc: 'Oared war drakkar' },
      { id: 'tavern', title: 'Roaring Hearth Alehouse', icon: '🍻', generator: 'places-inns', desc: 'Smoky longhouse with singing skalds' },
    ],
  },
};

const NPC_ARCHETYPES_5E = [
  { id: 'commoner', name: 'Townsfolk / Commoner', cr: '0 (10 XP)', ac: 10, hp: 4, hitDice: '1d8', speed: '30 ft.', attack: 'Club (+2, 1d4 bludgeoning)', passivePerc: 10, vibe: 'Ordinary citizen caught in extraordinary events' },
  { id: 'noble', name: 'Noble / Guild Diplomat', cr: '1/8 (25 XP)', ac: 15, hp: 9, hitDice: '2d8', speed: '30 ft.', attack: 'Rapier (+3, 1d8+1 piercing)', passivePerc: 12, vibe: 'Silver-tongued schemer with retinue & Parry reaction' },
  { id: 'guard', name: 'City Watch / Guard', cr: '1/8 (25 XP)', ac: 16, hp: 11, hitDice: '2d8+2', speed: '30 ft.', attack: 'Spear (+3, 1d6+1 piercing)', passivePerc: 12, vibe: 'Suspicious patrolman looking for bribes or trouble' },
  { id: 'bandit', name: 'Scout / Highway Cutpurse', cr: '1/2 (100 XP)', ac: 13, hp: 16, hitDice: '3d8+3', speed: '30 ft.', attack: 'Shortsword / Longbow (+4, 1d8+2)', passivePerc: 15, vibe: 'Sharp-eyed ambush spotter with Keen Hearing & Sight' },
  { id: 'acolyte', name: 'Temple Priest / Cultist', cr: '2 (450 XP)', ac: 13, hp: 27, hitDice: '5d8+5', speed: '30 ft.', attack: 'Mace (+2, 1d6) • Spell Save DC 13 (Spirit Guardians)', passivePerc: 13, vibe: 'Devout zealot wielding divine wards & cure wounds' },
  { id: 'veteran', name: 'Battle-Scarred Veteran', cr: '3 (700 XP)', ac: 17, hp: 58, hitDice: '9d8+18', speed: '30 ft.', attack: 'Multiattack x2 Longsword (+5, 1d8+3)', passivePerc: 12, vibe: 'Mercenary sergeant or grizzled bodyguard' },
  { id: 'mage', name: 'Arcane Mage / Court Wizard', cr: '6 (2,300 XP)', ac: 12, hp: 40, hitDice: '9d8', speed: '30 ft.', attack: 'Fireball / Counterspell • Spell Save DC 14 (+6)', passivePerc: 11, vibe: 'Obsessive scholar guarding arcane reagents' },
  { id: 'assassin', name: 'Guild Assassin', cr: '8 (3,900 XP)', ac: 15, hp: 78, hitDice: '12d8+24', speed: '30 ft.', attack: 'Multiattack Shortsword (+6, +7d6 poison, DC 15 Con)', passivePerc: 13, vibe: 'Lethal shadow broker who never misses an opening' },
  { id: 'archmage', name: 'Archmage / High Arcanist', cr: '12 (8,400 XP)', ac: 12, hp: 99, hitDice: '18d8+18', speed: '30 ft.', attack: 'Time Stop / Cone of Cold • Spell Save DC 17 (+9)', passivePerc: 12, vibe: 'Reality-bending master of an ancient tower' },
];

const NPC_VOICES = [
  'Speaks in measured, breathy whispers that force listeners to lean in closely.',
  'Booming gravelly baritone punctuated by hearty belly laughs and table-slaps.',
  'Crisp, clipped aristocratic cadence; pronounces every syllable like an accusation.',
  'Rambles quickly with nervous throat-clearing and frequent glances over their shoulder.',
  'Slow, hypnotic drawl; pauses for three full seconds before answering any question.',
  'Warm, singsong merchant patter peppered with outdated tavern idioms.',
  'Monotone and eerily calm even when blades are drawn.',
  'Raspy, smoke-ruined voice with a dry wheezing chuckle at dark jokes.',
  'Melodic, overly formal phrasing as if reciting an epic poem.',
  'Blunt and gravelly, using three-word sentences whenever possible.',
];

const NPC_IDEALS = [
  'Preservation: Ancient relics and secrets belong safely hidden, not in reckless adventurers\' hands.',
  'Coin & Leverage: Gold fades, but favors owed by desperate heroes last a lifetime.',
  'Honor Bound: A sworn oath outlives kings, borders, and mortal death.',
  'Unbridled Curiosity: No locked door or sealed tome should remain unopened.',
  'Quiet Sanctuary: Keep the local ward safe and fed, no matter which tyrant wears the crown.',
  'Retribution: Someone high in power owes a blood debt that has not yet been collected.',
];

const NPC_BONDS = [
  'Keeps a battered brass locket hiding a miniature portrait of a missing sibling.',
  'Owes a steep blood-debt to a Thieves\' Guild lieutenant operating out of the docks.',
  'Secretly tends to an injured planar creature hidden beneath their cellar floor.',
  'Guards the only surviving key to a long-flooded dwarven vault.',
  'Once served beside one of the party\'s mentors before a disastrous siege.',
  'Is fiercely protective of an orphaned apprentice who unknowingly carries latent wild magic.',
];

const NPC_POCKETS = [
  '14 sp, a half-melted wax seal bearing a raven crest, and a stale honeycake.',
  '3 gp, three loaded bone dice, and a folded tavern debt-note signed in red ink.',
  'A tarnished silver holy symbol, a vial of cheap peppermint oil, and 8 cp.',
  '22 gp, an illegible charcoal map of local sewer grates, and an iron skeleton key.',
  'A smooth river stone warm to the touch, 5 sp, and dried lavender sprigs.',
  '1 pp wrapped in oiled silk, a poisoner\'s needle hidden in a hollow quill, and 4 gp.',
];

const NPC_DATA = {
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
    'Secretly relies on dream-dust concoctions to cope with recurring battlefield nightmares.',
    'Arrogant beyond measure; believes ordinary folk lack the capacity for grand strategy.',
    'Paranoid of being poisoned; insists on having food tasted or spells cast before dining.',
    'Compulsive gambler who will wager vital secrets on a single turn of cards or dice.',
    'Refuses to flee even when wildly outmatched, prioritizing pride over survival.',
  ],
  darkSecrets: [
    'Is secretly indebted to a devilish arch-fiend in exchange for the power that won their current station.',
    'Orchestrated the downfall of their predecessor and framed a rival faction noble.',
    'Possesses an illegal ancient spellbook containing forbidden soul-binding necromantic rites.',
    'Is secretly funding bandit raiders harassing trade roads to depress land values and buy estates cheaply.',
    'Actually died five winters ago and walks under an illusion masking an undead pact.',
    'Feeds weekly reports on visiting adventurers directly to an Underdark spy network.',
  ],
  dialogueHooks: [
    '"Speak quickly and plainly. Flattery is the language of assassins and debt-collectors."',
    '"Ah, travelers. Fate weaves our threads together, though whether into a tapestry or a hangman\'s noose remains to be seen."',
    '"Every soul has a price, friend. Some take gold; others prefer silence. Which are you buying today?"',
    '"You step into my domain carrying steel and ambition. Be careful that the latter does not dull the former."',
    '"Shut the door behind you—and check the eaves. Even the sparrows take coin in this ward."',
  ],
};

const SHOP_TYPES = {
  tavern: {
    id: 'tavern',
    label: 'Tavern & Inn',
    icon: '🍺',
    nameGenerator: 'places-inns',
    descGenerator: 'descriptions-taverns',
    proprietorTitle: 'Innkeeper / Barkeep',
    itemGenerators: ['miscellaneous-foods', 'miscellaneous-drinks'],
    baseItems: [
      { category: 'Lodging', item: 'Modest Private Room (per night)', price: '5 sp', note: 'Warm straw mattress, iron latch' },
      { category: 'Lodging', item: 'Comfortable Suite & Hot Bath', price: '2 gp', note: 'Featherbed, bolted oak door' },
      { category: 'Stable', item: 'Stabling & Feed (per mount)', price: '5 sp', note: 'Includes oats and brushing' },
      { category: 'Provisions', item: 'Trail Rations (1 day packed)', price: '5 sp', note: 'Jerky, hardtack, dried apples' },
    ],
  },
  magic_shop: {
    id: 'magic_shop',
    label: 'Arcane Curios & Magic Shop',
    icon: '🔮',
    nameGenerator: 'places-magic_shops',
    descGenerator: 'descriptions-spells',
    proprietorTitle: 'Arcane Curio Broker',
    itemGenerators: ['miscellaneous-potions', 'miscellaneous-artifacts', 'miscellaneous-gem_minerals'],
    baseItems: [
      { category: 'Components', item: 'Arcane Focus (Crystal / Wand)', price: '10 gp', note: 'Standard spellcasting focus' },
      { category: 'Components', item: 'Fine Pearl (Identify component)', price: '100 gp', note: 'Required for Identify spell' },
      { category: 'Components', item: 'Diamond Dust Pouch (Revivify)', price: '300 gp', note: 'Consumed on casting' },
      { category: 'Utility', item: 'Bag of Holding (Uncommon)', price: '450 gp', note: '64 cu. ft. / 500 lb capacity' },
    ],
  },
  blacksmith: {
    id: 'blacksmith',
    label: 'Blacksmith & Armory',
    icon: '⚒️',
    nameGenerator: 'places-shops',
    descGenerator: 'descriptions-weapons',
    proprietorTitle: 'Master Armorer',
    itemGenerators: ['weapons-swords', 'weapons-battle_axes', 'armour-shields'],
    baseItems: [
      { category: 'Armor', item: 'Chain Shirt (AC 13 + Dex max 2)', price: '50 gp', note: 'Medium armor, 20 lb' },
      { category: 'Armor', item: 'Breastplate (AC 14 + Dex max 2)', price: '400 gp', note: 'No Stealth disadvantage' },
      { category: 'Armor', item: 'Half Plate (AC 15 + Dex max 2)', price: '750 gp', note: 'Disadvantage on Stealth' },
      { category: 'Service', item: 'Silvered Weapon Coating', price: '100 gp', note: 'Bypasses lycanthrope/devil immunity' },
    ],
  },
  apothecary: {
    id: 'apothecary',
    label: 'Alchemist & Apothecary',
    icon: '🧪',
    nameGenerator: 'places-shops',
    descGenerator: 'descriptions-potions',
    proprietorTitle: 'Master Herbalist',
    itemGenerators: ['miscellaneous-potions', 'miscellaneous-herbs', 'miscellaneous-poisons'],
    baseItems: [
      { category: 'Healing', item: 'Potion of Healing (2d4 + 2 HP)', price: '50 gp', note: 'Common red glass vial' },
      { category: 'Healing', item: 'Potion of Greater Healing (4d4 + 4 HP)', price: '150 gp', note: 'Uncommon shimmering ruby' },
      { category: 'Defense', item: 'Antitoxin Vial (Adv. vs Poison 1 hr)', price: '50 gp', note: 'Bitter herbal draught' },
      { category: 'Gear', item: 'Healer\'s Kit (10 uses)', price: '5 gp', note: 'Stabilize dying creature without check' },
    ],
  },
  temple: {
    id: 'temple',
    label: 'Temple & Sanctuary',
    icon: '🏛️',
    nameGenerator: 'places-temples',
    descGenerator: 'descriptions-gods',
    proprietorTitle: 'High Cleric / Keeper',
    itemGenerators: ['miscellaneous-holy_books', 'miscellaneous-religions'],
    baseItems: [
      { category: 'Service', item: 'Lesser Restoration Casting', price: '40 gp', note: 'Ends 1 disease or condition' },
      { category: 'Service', item: 'Remove Curse / Dispel Magic', price: '90 gp', note: 'Donation to temple coffers' },
      { category: 'Service', item: 'Raise Dead Ritual (within 10 days)', price: '1,250 gp', note: 'Includes 500 gp diamond' },
      { category: 'Holy Gear', item: 'Flask of Holy Water (2d6 radiant)', price: '25 gp', note: 'Effective vs fiends & undead' },
    ],
  },
};

const TAVERN_DATA = {
  atmospheres: [
    'A roaring central peat fire fills the room with rich birch smoke; muddy cloaks hang from iron wall hooks, and the wooden floor is strewn with fragrant pine needles.',
    'Lanterns in iron cages swing gently from oak rafters; the air is thick with roasted cumin, pipe-weed, and the rowdy strumming of a three-string lute.',
    'Dim amber candles gutter inside melted wax skulls; a tense silence lingers as cloaked sellswords exchange wary glances over foaming tankards.',
    'A bustling roadside post house where traveling merchants, caravan guards, and weary clerics huddle around long trestle tables sharing warm spiced cider.',
    'Rain batters the leaded glass windows; a cozy brick hearth crackles warmly, and an elderly dwarf bakes honeyed biscuits behind a polished copper bar.',
    'Water drips into buckets from a leaking thatched roof; sailors sing bawdy shanties as dice rattle across grease-stained walnut barrels.',
  ],
  barkeepPersonalities: [
    'A scarred retired legionnaire polishing tankards with deliberate slowness, missing one ear and sizing up everyone who touches a weapon.',
    'A jovial stout grandmother with flour on her apron who addresses hardened mercenaries as "my ducklings" while keeping a heavy iron club under the counter.',
    'A sly half-elf with nervous darting eyes and gold rings on every finger, eager to trade drinks for gossip about nobility.',
    'A hulking half-orc with a warm baritone laugh, known for breaking up bar brawls by bodily lifting instigators through the front door.',
    'A taciturn tiefling with obsidian horns wrapped in silver wire, who speaks only in short grunts but serves exceptionally fine dwarven vintage.',
  ],
  serverPersonalities: [
    'A nimble halfling darting between tables carrying six foaming flagons at once while whistling a fast jig.',
    'A sleepy teenage farm boy who keeps dropping wooden spoons and apologizing profusely.',
    'A sharp-tongued tiefling who charges double for anyone who snaps their fingers for service.',
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
      'Caravans traveling the Old King\'s Road vanish whenever mist rises from the river valley; survivors claim lanterns walk inside the fog.',
    ],
    halfTrueRumors: [
      'They say the sunken vault of Lord Karas holds chests of gold coins—but nobody mentions the guardian water elemental that drowns trespassers in armor.',
      'A band of goblins in the crags wants to trade rare silver gems for livestock, though scouts claim they are being bullied by an exiled hill giant.',
      'The apothecary is paying top coin for silverleaf moss from Dead Man\'s Grotto, conveniently forgetting to mention the cave is home to blinding cave bats.',
      'An abandoned wizard spire outside town stands completely unguarded, though its teleportation staircase scrambles rooms at dusk.',
    ],
    falseRumors: [
      'If you drop three copper pennies into the village well at dawn, an ancient spirit will grant your weapon a permanent lightning enchantment.',
      'The local baron was secretly replaced by a shapeshifting doppelgänger three months ago during the harvest festival.',
      'Elves from the northern forest are poisoning the flour shipments to force the town into signing away their logging rights.',
      'Burying an iron horseshoe under the inn threshold grants immunity to fire breath for seven days.',
    ],
  },
  shadyPatrons: [
    {
      name: 'Vesper the Left-Handed',
      hook: 'Needs four mercenaries to escort a sealed lead box past the city night watch before sunrise. Asks no questions, pays 50 gp each upfront.',
    },
    {
      name: 'Sister Maeve of the Shrouded Veil',
      hook: 'Her order\'s holy relic was stolen by apostate acolytes who fled into the spider-infested catacombs; offers a potion of greater healing as a retainer.',
    },
    {
      name: 'Captain Torvald Ironbrow',
      hook: 'His merchant vessel ran aground on the reef; he seeks divers brave enough to recover his family strongbox before the tide rises or sahuagin arrive.',
    },
  ],
};

const DUNGEON_DATA = {
  room1Entrance: [
    { name: 'The Weeping Archway', desc: 'A collapsed fissure framed by moss-choked elven relief carvings. Stale air smelling of rotten wet copper drafts upward from the abyss below.' },
    { name: 'The Submerged Portcullis', desc: 'Knee-deep murky black water lapping against rusted iron bars. Skulls carved into the stone lintel warn travelers in archaic Draconic: "Turn back or join the choir."' },
    { name: 'The Sunken Crypt Steps', desc: 'Slick marble steps descending into absolute darkness. Scorch marks along the walls indicate someone fought desperately on their way out.' },
    { name: 'The Shattered Astral Gate', desc: 'Obsidian monoliths lean inward around a spiral stair etched with faded star charts that softly hum when magic is cast nearby.' },
  ],
  room2Hazards: [
    { name: 'Crushing Pendulum Hallway', baseDc: 13, dc: 'DC 14 Dexterity (Acrobatics) or DC 13 Investigation', desc: 'Pressure plates disguised as floral mosaics trigger rusted scythe blades swinging through the corridor.' },
    { name: 'The Choking Gas Basin', baseDc: 13, dc: 'DC 13 Constitution saving throw or DC 15 Thieves\' Tools', desc: 'A sunken floor filled with dense violet sulfur gas that ignites if brought into contact with an open torch flame.' },
    { name: 'The Riddle of the Broken Mirror', baseDc: 14, dc: 'DC 14 Intelligence (Arcana or Investigation)', desc: 'A silvered reflective gate that only unlocks when all light sources are extinguished and darkness is embraced.' },
    { name: 'The Rotating Gravity Bridge', baseDc: 14, dc: 'DC 14 Strength (Athletics) or DC 14 Arcana', desc: 'A narrow stone span over a chasm whose runes invert gravity every other round on initiative count 20.' },
  ],
  room3Setbacks: [
    { name: 'Gargoyle Watchpost', monster: '3 Stone Gargoyles & 1 Hobgoblin Sentry', desc: 'Perched high in shadowed vaulted niches, raining down stone debris before diving onto spellcasters in the rear rank.' },
    { name: 'The Slime-Filled Pit Enclosure', monster: '1 Ochre Jelly & 2 Skeletal Guardians', desc: 'The floor gives way into a sticky containment pit where ancient guardians rise from calcified bones.' },
    { name: 'The Drow Ambuscade', monster: '2 Drow Scouts with poisoned hand crossbows', desc: 'Using darkness spells and web snares to pin adventurers while retreating toward the inner sanctum.' },
    { name: 'The Animated Armory', monster: '2 Animated Armors & 3 Flying Swords', desc: 'Dormant suits of tarnished plate snap to attention the moment any chest or weapon rack is disturbed.' },
  ],
  room4BossSanctums: [
    { name: 'The Obsidian Altar of the Blood Moon', boss: 'Malakor the Bone-Carver (Cult Fanatic)', lairHazard: 'At initiative count 20, blood erupts from floor channels, forcing Str saves to avoid being swept prone.', desc: 'A cavernous circular temple illuminated by bowls of emerald fire; a chained prisoner hangs above an altar of black glass.' },
    { name: 'The Frozen Throne of the Frost Wight', boss: 'Wight Commander & 4 Ice Skeletons', lairHazard: 'Frigid winds impose disadvantage on ranged attack rolls and extinguish non-magical torches.', desc: 'Icicles like cathedral pillars hang from the ceiling; frost coats the shattered armor of fallen heroes.' },
    { name: 'The Dragon\'s Geode Hollow', boss: 'Young Shadow Drake', lairHazard: 'Sulfuric steam geysers erupt on random hexes, dealing fire damage on failed Dex saves.', desc: 'Crystalline stalagmites vibrate with arcane resonance as a scaly silhouette coils around a mound of tarnished silver.' },
  ],
  room5Hoards: [
    { name: 'The Gilded Reliquary', reward: '350 gp, 1,200 sp, a pearl-inlaid jewelry box (150 gp), and a sealed ivory scroll case containing a Spell Scroll of Misty Step.' },
    { name: 'The Sarcophagus of the Forgotten King', reward: '500 gp in ancient stamped platinum coins, a Potion of Greater Healing, and the Sun-Forged Battleaxe (+1).' },
    { name: 'The Alchemist\'s Hidden Stash', reward: '2 Potions of Invisibility, an uncut star sapphire (300 gp), and a curious silver pocket watch that runs backward.' },
  ],
};

const LOOT_DATA = {
  weapons: [
    { name: 'Sun-Forged Longsword', type: 'Longsword (+1)', lore: 'Forged during the Siege of the Sunken Spire. Emits sunlight in a 10-foot radius when unsheathed.', val: '1,200 gp' },
    { name: 'Whispering Shadow-Dagger', type: 'Dagger (+1)', lore: 'Carried by royal assassins. Deals an extra 1d4 psychic damage against targets surprised in dim light.', val: '950 gp' },
    { name: 'Thunder-Strike Warhammer', type: 'Warhammer (+1)', lore: 'Crafted from a fallen meteor by deep dwarven smiths. Deals max damage against stone objects and constructs.', val: '1,400 gp' },
    { name: 'Gilded Gale Bow', type: 'Longbow (+1)', lore: 'Fletcher-carved from sacred heartwood. Arrows fired suffer no penalty from non-magical gale winds.', val: '1,100 gp' },
  ],
  potions: [
    { name: 'Elixir of the Cat’s Grace', benefit: 'Advantage on Dexterity checks and fall damage halved for 1 hour.', quirk: 'User’s eyes become vertical slit pupils and they purr softly when pleased.', color: 'Iridescent Amber' },
    { name: 'Draft of Mountain Fortitude', benefit: 'Grants 15 temporary hit points and resistance to poison for 1 hour.', quirk: 'User’s skin temporarily takes on the rough texture and weight of granite.', color: 'Chalky Gray' },
    { name: 'Vial of the Zephyr Step', benefit: 'Increases walking speed by 10 ft and allows dashing as a bonus action for 10 minutes.', quirk: 'User leaves faint wisps of white morning mist in their footprints.', color: 'Pale Sky-Blue' },
    { name: 'Philter of True Sight', benefit: 'Advantage on Perception checks to detect hidden illusions for 1 hour.', quirk: 'User speaks every thought in rhyming couplets for the duration.', color: 'Glowing Violet' },
  ],
  curios: [
    { item: 'Carved ivory comb depicting a griffon hunt', val: '75 gp' },
    { item: 'Silver ceremonial chalice set with four lapis lazuli gemstones', val: '220 gp' },
    { item: 'Velvet pouch holding 12 polished bloodstone gaming dice', val: '110 gp' },
    { item: 'Ancient bronze pocket astrolabe tracking planar alignments', val: '350 gp' },
    { item: 'Embroidered silk tapestry depicting the fall of an elven kingdom', val: '400 gp' },
  ],
};

const PARTY_TIERS = {
  1: { tier: 1, label: 'Tier 1: Local Heroes (Lv 1–4)', dc: 12, trapDamage: '2d6', goldScale: 1, rarity: 'Common / Uncommon' },
  2: { tier: 2, label: 'Tier 2: Heroes of the Realm (Lv 5–10)', dc: 15, trapDamage: '4d6', goldScale: 4, rarity: 'Uncommon / Rare' },
  3: { tier: 3, label: 'Tier 3: Masters of the Realm (Lv 11–16)', dc: 17, trapDamage: '8d6', goldScale: 12, rarity: 'Rare / Very Rare' },
  4: { tier: 4, label: 'Tier 4: Masters of the World (Lv 17–20)', dc: 19, trapDamage: '12d6', goldScale: 30, rarity: 'Very Rare / Legendary' },
};

const CONDITIONS_5E = [
  { id: 'Blinded', short: 'Blinded', color: 'amber', summary: 'Fails sight checks. Attacks have disadvantage; attacks against have advantage.' },
  { id: 'Charmed', short: 'Charmed', color: 'pink', summary: 'Cannot attack charmer. Charmer has advantage on social checks.' },
  { id: 'Deafened', short: 'Deafened', color: 'slate', summary: 'Cannot hear; automatically fails checks requiring hearing.' },
  { id: 'Frightened', short: 'Frightened', color: 'purple', summary: 'Disadvantage on checks & attacks while source is visible; cannot move closer.' },
  { id: 'Grappled', short: 'Grappled', color: 'orange', summary: 'Speed becomes 0; ends if grappler is incapacitated or moved apart.' },
  { id: 'Incapacitated', short: 'Incapacitated', color: 'red', summary: 'Cannot take actions or reactions.' },
  { id: 'Invisible', short: 'Invisible', color: 'cyan', summary: 'Unseen without magic/sense; attacks have advantage, incoming attacks have disadvantage.' },
  { id: 'Paralyzed', short: 'Paralyzed', color: 'rose', summary: 'Incapacitated, auto-fails Str/Dex saves, melee hits within 5 ft are auto-crits.' },
  { id: 'Poisoned', short: 'Poisoned', color: 'emerald', summary: 'Disadvantage on attack rolls and ability checks.' },
  { id: 'Prone', short: 'Prone', color: 'yellow', summary: 'Crawl costs extra speed; melee attacks within 5 ft have advantage, ranged have disadvantage.' },
  { id: 'Restrained', short: 'Restrained', color: 'indigo', summary: 'Speed 0, Dex save disadvantage, incoming attacks have advantage.' },
  { id: 'Stunned', short: 'Stunned', color: 'red', summary: 'Incapacitated, cannot move, speaks falteringly, fails Str/Dex saves, hits have advantage.' },
  { id: 'Unconscious', short: 'Unconscious', color: 'rose', summary: 'Incapacitated, drops held items, falls prone, melee hits within 5 ft are crits.' },
  { id: 'Concentrating', short: 'Conc.', color: 'sky', summary: 'Maintaining spell: DC 10 or half damage Con save whenever damaged.' },
];

const ENCOUNTER_ENVIRONMENTS = {
  road: {
    id: 'road',
    label: 'King’s Road & Frontier Trail',
    icon: '🛤️',
    npcGenerators: ['fantasy-bandits', 'dungeon_and_dragons-humans', 'dungeon_and_dragons-halflings'],
    monsterGenerators: ['fantasy-goblins', 'fantasy-orcs'],
    twists: [
      'A broken axle blocks the narrow stone bridge during a sudden thunderstorm.',
      'Toll-collectors flying fresh royal banners demand coin, though their tabards are stained with dried blood.',
      'A covered merchant wagon stands deserted with warm tea still steaming beside the campfire.',
    ],
  },
  forest: {
    id: 'forest',
    label: 'Ancient Sylvan Forest',
    icon: '🌲',
    npcGenerators: ['dungeon_and_dragons-elfs', 'dungeon_and_dragons-eladrins', 'fantasy-witchs'],
    monsterGenerators: ['fantasy-monsters', 'fantasy-goblins'],
    twists: [
      'Silver mist turns every compass backward; footsteps echo five seconds after each step.',
      'Ancient oak trunks weep luminescent amber sap prized by alchemists.',
      'A ring of standing moss-stones hums softly whenever a spellcaster steps inside.',
    ],
  },
  underdark: {
    id: 'underdark',
    label: 'Underdark Cavern & Abyss',
    icon: '🕳️',
    npcGenerators: ['dungeon_and_dragons-drows', 'dungeon_and_dragons-githzerais'],
    monsterGenerators: ['fantasy-monsters', 'fantasy-demons'],
    twists: [
      'Phosphorescent fungi flare bright violet when loud noises echo, alerting tunnel stalkers.',
      'A narrow rope bridge sways above an underground river carrying glowing magma shards.',
      'Faerzress wild magic causes every 1st-level or higher spell to trigger an eerie minor illusion.',
    ],
  },
  urban: {
    id: 'urban',
    label: 'City Alley & Rooftop Ward',
    icon: '🏙️',
    npcGenerators: ['fantasy-knights', 'dungeon_and_dragons-tieflings', 'dungeon_and_dragons-gnomes'],
    monsterGenerators: ['fantasy-vampires', 'fantasy-bandits'],
    twists: [
      'City Watch bells toll across the canal, locking down bridges in three rounds.',
      'A parade of masked festival revelers floods the cobblestone plaza, creating heavy crowd cover.',
      'Laundry lines and slate roof tiles offer daring high-ground shortcuts above the melee.',
    ],
  },
  high_seas: {
    id: 'high_seas',
    label: 'Stormy Coast & Open Sea',
    icon: '⛵',
    npcGenerators: ['fantasy-pirates', 'military-royal_navy'],
    monsterGenerators: ['fantasy-monsters', 'fantasy-dragons'],
    twists: [
      'Slick waves rock the deck: creatures failing a DC 12 Dex save slide 10 ft toward the rail.',
      'Sargasso kelp snags the rudder, slowing the vessel while something circles below.',
      'Ghostly blue St. Elmo’s fire dances along the rigging, illuminating stealthy boarders.',
    ],
  },
};

module.exports = {
  DND_ANCESTRIES,
  HUMAN_CULTURES,
  GENRE_PRESETS,
  NPC_ARCHETYPES_5E,
  NPC_VOICES,
  NPC_IDEALS,
  NPC_BONDS,
  NPC_POCKETS,
  NPC_DATA,
  SHOP_TYPES,
  TAVERN_DATA,
  DUNGEON_DATA,
  LOOT_DATA,
  PARTY_TIERS,
  CONDITIONS_5E,
  ENCOUNTER_ENVIRONMENTS,
};
