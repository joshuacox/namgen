#include "descriptions-pokemons_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <algorithm>
#include <cstdint>

struct PokemonBase {
    std::string_view name;
    std::string_view habitats[3];
    uint8_t num_habitats;
    std::string_view coverings[2];
    uint8_t num_coverings;
    std::string_view limbs[2];
    uint8_t num_limbs;
    std::string_view head;
    std::string_view tail;
    std::string_view ear;
};

struct PokemonTypeTables {
    std::string_view type_name;
    ArrayView skin;
    ArrayView legs;
    ArrayView arms;
    ArrayView wings;
    ArrayView mouth;
    ArrayView beak;
    ArrayView snout;
    ArrayView ears;
    ArrayView horns;
    ArrayView tail;
    ArrayView places;
    ArrayView attks;
};

static constexpr std::string_view pers[] = {"aggressive", "apprehensive", "attentive", "carefree", "cautious", "cheerful", "comical", "cordial", "disruptive", "distrustful", "easygoing", "energetic", "fearful", "fidgety", "friendly", "gentle", "hostile", "impish", "inhospitable", "irritable", "jittery", "laid-back", "lively", "mischievous", "placid", "playful", "precarious", "quiet", "receptive", "relaxed", "serene", "shy", "skittish", "sociable", "spiteful", "threatening", "timid", "volatile", "wary", "watchful", "whimsical"};
static constexpr std::string_view amnt[] = {"all around you", "alone or alongside one or two others", "alongside a few others", "alongside other Pokemon", "among many other kinds of Pokemon", "hidden away and on their own", "hiding with several others", "in huge groups", "in small groups", "lurking about and on their own", "lurking with several others", "on their own", "only after giving up your search for them", "only by accident"};
static constexpr std::string_view wtr[] = {"dark", "dragon", "ghost", "ice", "poison", "psychic", "water"};
static constexpr std::string_view lnd[] = {"bug", "dark", "electric", "fairy", "fighting", "fire", "ghost", "grass", "ground", "ice", "normal", "poison", "psychic", "rock", "steel"};
static constexpr std::string_view air[] = {"bug", "dark", "dragon", "electric", "fairy", "fire", "flying", "ghost", "normal", "poison", "psychic"};
static constexpr std::string_view evo[] = {"could still evolve, but it requires a special stone", "could still evolve, but only under rare circumstances", "has already evolved once, but can still evolve one more time", "has evolve once and can still evolve into one of two potential evolutions", "has evolved once and can evolve no more", "has evolved twice and can evolve no more", "has evolved twice, but can still evolve once more", "hasn't evolved yet and there are no known evolutions", "hasn't evolved yet, but could do so once", "hasn't evolved yet, but could do so twice"};
static constexpr std::string_view rsm[] = {"bears resemblance to", "closely resembles", "faintly looks like", "is similar to", "looks a little like", "looks a lot like", "shares features with", "slightly resembles", "somewhat resembles"};
static constexpr std::string_view bugSkin[] = {"bioluminescent", "phosphorescent", "fluorescent", "camouflaged", "dark", "fluff covered", "glowing", "hair covered", "light", "patterned", "thick armored", "thorny", "translucent"};
static constexpr std::string_view bugLegs[] = {"ridged", "armored", "thick, fluffy", "hair covered", "thin, long", "thorn covered", "camouflaged", "small", "powerful"};
static constexpr std::string_view bugArms[] = {"bladed", "pincer-like", "flexible", "strong", "stinger-like", "claw-like", "tiny", "hidden"};
static constexpr std::string_view bugWings[] = {"angular", "bioluminescent", "phosphorescent", "fluorescent", "petal-like", "camouflaged", "cloak-like", "dark", "double paired", "giant", "glowing", "light", "patterned", "powerful", "razor sharp", "ribbon-like", "small", "translucent"};
static constexpr std::string_view bugMouth[] = {"tusked", "seemingly invisible", "giant", "powerful", "little", "toothed", "sharp toothed", "pincer-like", "seemingly smiling", "seemingly frowning"};
static constexpr std::string_view placeBug[] = {"in labyrinths", "during summer", "in national parks", "in bushes", "in farmlands", "in fields", "in forests", "in gardens", "in grassy fields", "in meadows", "in parks", "in pastures", "in tree tops", "in valleys", "in vineyards"};
static constexpr std::string_view bugAttk[] = {"Attack Order", "Bug Bite", "Bug Buzz", "Defend Order", "Fell Stinger", "Fury Cutter", "Heal Order", "Infestation", "Leech Life", "Megahorn", "Pin Missile", "Powder", "Quiver Dance", "Rage Powder", "Signal Beam", "Silver Wind", "Spider Web", "Steamroller", "Sticky Web", "String Shot", "Struggle Bug", "Tail Glow", "Twineedle", "U-turn", "X-Scissor"};
static constexpr std::string_view darkSkin[] = {"black", "black and crimson", "black and gray", "black and white", "blue and crimson", "blue and purple", "dark", "dark blue", "dark glowing", "deep purple", "gray", "red and black", "shadowy", "white and blue"};
static constexpr std::string_view darkLegs[] = {"ridged", "armored", "thick", "powerful", "shaded", "smoke-like", "patterned", "an extra pair of", "gem encrusted"};
static constexpr std::string_view darkArms[] = {"ridged", "folded", "shielded", "strong", "enormous", "elongated", "bladed", "barbed", "muscled"};
static constexpr std::string_view darkWings[] = {"angular", "smoke-like", "cloak-like", "dark", "double paired", "giant", "glowing", "patterned", "powerful", "razor sharp", "translucent", "ribbon-like", "overgrown", "barbed", "reflective"};
static constexpr std::string_view darkMouth[] = {"tusked", "seemingly invisible", "giant", "powerful", "sharp toothed", "seemingly smirking", "seemingly frowning", "distinct lack of a visible", "cavernous", "toothed"};
static constexpr std::string_view darkBeak[] = {"crescent", "reinforced", "razor sharp", "crystal-like", "thick obsidian", "solid onyx", "sharp, crimson", "terrifying", "mighty", "enlarged", "rugged"};
static constexpr std::string_view darkSnout[] = {"tusked", "horned", "pointed", "giant", "stubby", "sharp toothed", "seemingly smirking", "seemingly frowning", "fuming", "abyssal", "toothed"};
static constexpr std::string_view darkEars[] = {"horn-like", "wing-like", "pointy", "flappy", "flabby", "huge", "jagged", "ribbon-like", "fan-like", "stubby", "nimble", "enormous"};
static constexpr std::string_view darkHorns[] = {"ridged", "a crown of", "a row of", "blade-like", "crystal", "curved", "glowing", "obsidian", "onyx", "pulsing", "scythe-like", "sharp", "thin", "two sets of"};
static constexpr std::string_view darkTail[] = {"a tail much like a whip", "a tail that ends in a barbed tip", "a pair of tails instead of one", "several tails instead of one", "a tail with the appearance of flowing smoke", "a tail that ends in a sharp, blade-like curve", "a tail that ends in a fan-like shape", "a tail that seems to shimmer in light", "an incredibly fluffy tail", "a tail covered in armored plates", "a tail that visibly holds the Pokemon's powers", "a tail charged with dark energies", "a tail that wraps itself around the body when in rest", "a tail decorated by the Pokemon", "a tail that pulses with energy during attacks", "a tail with odd, dark pulsing symbols", "a tail that seems to distort light behind and around the Pokemon"};
static constexpr std::string_view placeDark[] = {"in labyrinths", "in dark caves", "at midnight", "in caverns", "in caves", "in chasms", "in dark forests", "in dens", "in grottoes", "in ruins", "in shadowy places", "in the early morning", "in the evening", "in the middle of the night", "in thick forests"};
static constexpr std::string_view darkAttk[] = {"Assurance", "Beat Up", "Bite", "Crunch", "Dark Pulse", "Dark Void", "Embargo", "Fake Tears", "Feint Attack", "Flatter", "Fling", "Foul Play", "Hone Claws", "Hyperspace Fury", "Knock Off", "Memento", "Nasty Plot", "Night Daze", "Night Slash", "Parting Shot", "Payback", "Punishment", "Pursuit", "Quash", "Snarl", "Snatch", "Sucker Punch", "Switcheroo", "Taunt", "Thief", "Topsy-Turvy", "Torment"};
static constexpr std::string_view dragonSkin[] = {"aerodynamic", "armor plated", "barbed", "bioluminescent", "phosphorescent", "fluorescent", "boulder-like", "cloud-like", "crystal-like", "fiery looking", "glowing", "metal", "scaled", "smooth", "soft", "thick", "translucent"};
static constexpr std::string_view dragonLegs[] = {"ridged", "an extra pair of", "armored", "barbed", "crystal-like", "curved", "enormous", "massive", "powerful", "stubby", "thick", "two extra pairs of"};
static constexpr std::string_view dragonArms[] = {"ridged", "folded", "armored", "barbed", "bat-like", "blade-like", "clawed", "fiery", "jagged", "stocky", "strong", "winged"};
static constexpr std::string_view dragonWings[] = {"cloud-like", "rainbow", "fiery", "angelic", "barbed", "bioluminescent", "phosphorescent", "fluorescent", "crystal", "energy pulsing", "enormous", "fan-like", "giant", "glowing", "humongous", "jagged", "ridged", "translucent", "two pairs of"};
static constexpr std::string_view dragonMouth[] = {"tusked", "bearded", "blade toothed", "boulder-like", "cavernous", "crystal toothed", "fiery", "metal-like", "powerful", "seemingly ever angry", "seemingly smiling", "sharp toothed", "small", "smoldering"};
static constexpr std::string_view dragonEars[] = {"armored", "bone-like", "coiling", "crystal", "enormous", "hammer-like", "horn-like", "no visible", "pointy", "round", "smoldering", "wing-like"};
static constexpr std::string_view dragonHorns[] = {"ridged", "a crown of", "a row of", "antler-like", "crystal", "curved", "fan-like", "glowing", "hammer-like", "mohawk-like", "pulsing", "sharp", "stubby", "thin", "two sets of"};
static constexpr std::string_view dragonTail[] = {"a barbed tail", "a bladed tail", "a cloud-like tail", "a crystal adorned tail", "a curling tail", "a fan-like tail", "a pair of tails", "a rainbow tail", "a segmented tail", "a stubby tail", "a tail ending in a hammer", "a tail ending in double barbs", "a tail like a whip", "a thick tail", "an armor plated tail", "an incredibly long tail", "an incredibly powerful tail", "several tails"};
static constexpr std::string_view placeDragon[] = {"during heavy clouded weather", "during periods of heavy winds", "high up in the air", "in canyons", "in massive caves", "in mountainous areas", "in ruins", "in towers", "on deserted islands", "on mountain tops"};
static constexpr std::string_view dragonAttk[] = {"Draco Meteor", "Dragon Breath", "Dragon Claw", "Dragon Dance", "Dragon Pulse", "Dragon Rage", "Dragon Rush", "Dragon Tail", "Dual Chop", "Outrage", "Roar of Time", "Spacial Rend", "Twister"};
static constexpr std::string_view elecSkin[] = {"yellow", "orange", "black and yellow", "blue and yellow", "yellow and white", "statically charged", "electrifying", "charged", "electrically charged", "magnetized", "jagged", "sharp", "sharply jagged", "barbed"};
static constexpr std::string_view elecLegs[] = {"ridged", "agile", "bolt-like", "energy laden", "energy pulsing", "fast", "magnetized", "nimble", "powerful", "spiked", "tiny"};
static constexpr std::string_view elecArms[] = {"ridged", "folded", "bolt-like", "energy laden", "energy pulsing", "magnetized", "swift", "strong", "small", "electrifying", "an extra pair of", "orb-like"};
static constexpr std::string_view elecWings[] = {"angular", "bolt-like", "cloak-like", "electrically laden", "energized", "jagged", "layered", "magnetic", "pulsing", "tiny", "two pairs of"};
static constexpr std::string_view elecMouth[] = {"bearded", "gigantic", "jagged", "sharp toothed", "small", "tiny", "toothed", "seemingly lack of a", "seemingly invisible", "hidden"};
static constexpr std::string_view elecBeak[] = {"crescent", "bolt-like", "bright yellow", "glowing", "jagged", "powerful", "pulsing", "razor sharp"};
static constexpr std::string_view elecSnout[] = {"tusked", "horned", "jagged", "pointed", "seemingly frowning", "seemingly smirking", "sharp toothed", "small", "smiling", "stubby", "thick"};
static constexpr std::string_view elecEars[] = {"bolt-like", "coiling", "oscillating", "electrically charged", "big, round", "tiny", "orb-like", "magnetized", "blade-like", "flappy", "flabby", "stubby", "glowing"};
static constexpr std::string_view elecHorns[] = {"ridged", "pulsing", "magnetized", "orb-like", "coiled", "bolt-like", "sharp", "jagged", "curved", "a row of", "mohawk-like", "stubby", "two sets of"};
static constexpr std::string_view elecTail[] = {"a coiling tail", "a jagged tail", "a jagged, fan-like tail", "a lightning bolt tail", "a magnetized tail", "a pair of tails", "a positively and a negatively charged tail", "a sharp blade-like tail", "a stubby orb-like tail", "a tail ending in a charged orb", "a tail ending in a magnet", "a tail full of charged orbs", "a tail laden with electric charges", "a tail pulsing with electricity", "several tails"};
static constexpr std::string_view placeElectric[] = {"in labyrinths", "after thunderstorms", "during the day", "during the night", "during thunderstorms", "in dark caves", "in ruins", "in valleys", "near power facilities", "near power plants"};
static constexpr std::string_view electricAttk[] = {"Bolt Strike", "Charge", "Charge Beam", "Discharge", "Eerie Impulse", "Electric Terrain", "Electrify", "Electro Ball", "Electroweb", "Fusion Bolt", "Ion Deluge", "Magnet Rise", "Magnetic Flux", "Nuzzle", "Parabolic Charge", "Shock Wave", "Spark", "Thunder", "Thunder Fang", "Thunder Wave", "Thunderbolt", "Thunder Punch", "Thunder Shock", "Volt Switch", "Volt Tackle", "Wild Charge", "Zap Cannon"};
static constexpr std::string_view fairySkin[] = {"blushy", "coral", "fluffy", "glistening", "glossy", "glowing", "luminous", "pink", "rose", "shiny", "silken", "soft", "sparkling", "velvety"};
static constexpr std::string_view fairyLegs[] = {"covered", "feathery", "fluffy", "glowing", "lean", "shrouded", "slender", "slim", "small", "soft", "stubby", "tiny", "wispy"};
static constexpr std::string_view fairyArms[] = {"cloak-like", "elongated", "fat", "fluffy", "folded", "lean", "ribbon-like", "slim", "small", "smooth", "stubby", "tiny"};
static constexpr std::string_view fairyWings[] = {"angelic", "bioluminescent", "bow-like", "cloud-like", "enormous", "fan-like", "floating", "fluffy", "glowing", "layered", "ribbon-like", "smooth", "soft, feathery", "tiny", "two sets of"};
static constexpr std::string_view fairyMouth[] = {"bearded", "blunt toothed", "broad", "cavernous", "grinning", "hidden", "lack of a", "shrouded", "small", "smiling", "smirking", "tiny", "veiled"};
static constexpr std::string_view fairyBeak[] = {"blunt", "broad", "crescent", "curved", "glowing", "huge", "pointy", "shining", "smiling", "sparkling"};
static constexpr std::string_view fairySnout[] = {"bearded", "broad", "fluffy", "glossy", "glowing", "huge", "pointy", "rounded", "shining", "shrouded", "small", "sparkling", "stubby", "tiny", "veiled"};
static constexpr std::string_view fairyEars[] = {"bow-like", "cloud-like", "enormous", "flabby", "flappy", "fluffy", "hidden", "huge", "pointy", "puffy", "ribbon-like", "short", "stubby", "veiled"};
static constexpr std::string_view fairyHorns[] = {"antenna-like", "antler-like", "coiling", "crescent", "curling", "curving", "decorated", "looping", "painted", "pointy", "short", "smooth", "stubby"};
static constexpr std::string_view fairyTail[] = {"a bioluminescent tail", "a decorated tail", "a fan-like tail", "a fluffy tail", "a glowing tail", "a long tail wrapped around its body", "a long, floating tail", "a long, forked tail", "a ribbon-like tail", "a short, stubby tail", "a sparkling tail", "several tails instead of one", "two tails instead of one"};
static constexpr std::string_view placeFairy[] = {"in dense forests", "in hilly areas", "in labyrinths", "in large cave systems", "in large forests", "in the early morning", "in the late evening hours", "near mountains", "near sanctuaries", "near shrines"};
static constexpr std::string_view fairyAttk[] = {"Aromatic Mist", "Baby-Doll Eyes", "Charm", "Crafty Shield", "Dazzling Gleam", "Disarming Voice", "Draining Kiss", "Fairy Lock", "Fairy Wind", "Flower Shield", "Geomancy", "Light of Ruin", "Misty Terrain", "Moonblast", "Moonlight", "Play Rough", "Sweet Kiss"};
static constexpr std::string_view fightSkin[] = {"armor-like", "bruised", "camouflaged", "coarse", "decorated", "deflective", "nimble", "patterned", "smooth", "stone-like", "strengthened", "thick"};
static constexpr std::string_view fightLegs[] = {"ridged", "agile", "armored", "broad", "clothed", "decorated", "dexterous", "muscled", "nimble", "patterned", "powerful", "strengthened", "two sets of"};
static constexpr std::string_view fightArms[] = {"ridged", "folded", "armored", "barbed", "blade-like", "composed", "energetic", "hammer-like", "relaxed", "robust", "slim", "strong", "toned", "two sets of"};
static constexpr std::string_view fightWings[] = {"angular", "angelic", "armored", "blade-like", "broad", "cloak-like", "fan-like", "honed", "jagged", "ribbon-like", "robe-like", "sharp", "strong"};
static constexpr std::string_view fightMouth[] = {"tusked", "foaming", "focused looking", "frowning", "giant", "lack of a", "raging", "seemingly angry", "seemingly smirking", "serious looking", "smiling", "content looking", "tranquil looking", "seemingly arrogantly smiling"};
static constexpr std::string_view fightBeak[] = {"crescent", "reinforced", "barbed", "blade-like", "broad", "decorated", "jagged", "powerful", "razor sharp", "sharp", "talon-like", "thin"};
static constexpr std::string_view fightSnout[] = {"tusked", "horned", "broad", "bruised", "decorated", "fierce looking", "flattened", "frowning", "pointy", "protected", "seemingly arrogantly smiling", "seemingly broken", "seemingly smirking", "serious looking", "sharp", "shielded", "stubby"};
static constexpr std::string_view fightEars[] = {"a lack of", "bolt-like", "broken", "fan-like", "flappy", "flabby", "hat-like", "helmet-like", "jagged", "mohawk-like", "protective", "ribbon-like", "round", "smoothened", "stubby"};
static constexpr std::string_view fightHorns[] = {"ridged", "a crown of", "a row of", "aerodynamic", "antler-like", "blade-like", "curled", "curved", "mohawk-like", "pointed", "ridge", "rounded", "sharp", "spiral", "stubby"};
static constexpr std::string_view fightTail[] = {"a leg-like tail", "a long tail used for superior balance", "a muscular tail", "a nimble and strong tail", "a prehensile tail", "a ribbon-like tail", "a set of prehensile tails", "a set of tails like a fan", "a set of two powerful tails", "a tail ending in a fist-like extremity", "a tail ending in a hammer", "a tail like a whip", "a tail that wraps around the body like a belt"};
static constexpr std::string_view placeFighting[] = {"in cave systems", "in dense forests", "in hilly areas", "in labyrinths", "in mountain caves", "in open fields", "in rocky hill areas", "in towers", "near cliffs", "near mountain tops", "near ruins"};
static constexpr std::string_view fightingAttk[] = {"Arm Thrust", "Aura Sphere", "Brick Break", "Bulk Up", "Circle Throw", "Close Combat", "Counter", "Cross Chop", "Detect", "Double Kick", "Drain Punch", "Dynamic Punch", "Final Gambit", "Flying Press", "Focus Blast", "Focus Punch", "Force Palm", "Hammer Arm", "High Jump Kick", "Jump Kick", "Karate Chop", "Low Kick", "Low Sweep", "Mach Punch", "Mat Block", "Power-Up Punch", "Quick Guard", "Revenge", "Reversal", "Rock Smash", "Rolling Kick", "Sacred Sword", "Secret Sword", "Seismic Toss", "Sky Uppercut", "Storm Throw", "Submission", "Superpower", "Triple Kick", "Vacuum Wave", "Vital Throw", "Wake-Up Slap"};
static constexpr std::string_view fireSkin[] = {"incandescent", "burning", "crimson", "fiery", "flaming", "fuming", "gleaming", "glowing", "lava-like", "luminous", "orange", "red", "red and orange", "sanguine", "smoking", "smoldering", "white and orange"};
static constexpr std::string_view fireLegs[] = {"ridged", "an extra set of", "ashen", "black", "boulder-like", "dark", "fiery hot", "glowing", "lava stone", "muscular", "obsidian", "powerful", "smoking", "strong"};
static constexpr std::string_view fireArms[] = {"ridged", "folded", "agile", "ashen", "dark", "little", "muscular", "nimble", "obsidian", "slim", "smoldering", "strong", "stubby"};
static constexpr std::string_view fireWings[] = {"angular", "ashen", "black", "burning", "cloak-like", "crimson", "dark", "enormous", "fan-like", "fiery", "flame-like", "fuming", "glowing", "layered", "luminescent", "obsidian", "ribbon-like", "robe-like", "smoldering", "steaming"};
static constexpr std::string_view fireMouth[] = {"cavernous", "fiery", "frowning", "fuming", "serious looking", "sharp toothed", "small", "smiling", "smirking", "steaming"};
static constexpr std::string_view fireBeak[] = {"crescent", "black", "curved", "fiery", "fuming", "glowing", "luminescent", "dark", "razor-sharp", "sharp", "steaming"};
static constexpr std::string_view fireSnout[] = {"tusked", "horned", "fierce looking", "bearded", "black", "broad", "glowing", "black", "protected", "smoldering", "steaming", "stubby", "stumpy", "thin"};
static constexpr std::string_view fireEars[] = {"enormous", "wing-like", "flame shaped", "flappy", "flabby", "furnace-like", "horn-like", "huge", "pointy", "rounded", "small", "steaming", "stumpy", "tiny", "big"};
static constexpr std::string_view fireHorns[] = {"ridged", "enormous", "curved", "furnace-like", "stubby", "huge", "pointy", "rounded", "small", "steaming", "stumpy", "tiny", "jagged"};
static constexpr std::string_view fireTail[] = {"a burning tail", "a flame-like tail", "a fluffy flame patterned tail", "a lava-like tail", "a literal flame as a tail", "a muscular", "a smoldering tail", "a stubby tail", "a tail like a fan", "a tail that ends in fire", "a tailpipe-like tail", "an obsidian tail", "several tails in a fan-like pattern"};
static constexpr std::string_view placeFire[] = {"after forest fires", "during summer", "in cave systems", "in deep caves", "in deserty areas", "near hot springs", "near ruins", "near volcanoes", "on deserted islands", "on hot summer days", "on volcanic islands"};
static constexpr std::string_view fireAttk[] = {"Blast Burn", "Blaze Kick", "Blue Flare", "Ember", "Eruption", "Fiery Dance", "Fire Blast", "Fire Fang", "Fire Pledge", "Fire Punch", "Fire Spin", "Flame Burst", "Flame Charge", "Flame Wheel", "Flamethrower", "Flare Blitz", "Fusion Flare", "Heat Crash", "Heat Wave", "Incinerate", "Inferno", "Lava Plume", "Magma Storm", "Mystical Fire", "Overheat", "Sacred Fire", "Searing Shot", "Sunny Day", "V-create", "Will-O-Wisp"};
static constexpr std::string_view flySkin[] = {"armored", "bioluminescent", "phosphorescent", "fluorescent", "brightly colored", "camouflaged", "light", "patterned", "rough", "smooth", "soft", "thorny", "translucent"};
static constexpr std::string_view flyLegs[] = {"an extra pair of", "armored", "broad", "clawed", "decorated", "delicate", "fluffy", "long", "muscular", "nimble", "powerful", "slim", "tiny"};
static constexpr std::string_view flyWings[] = {"angular", "angelic", "armored", "bioluminescent", "phosphorescent", "fluorescent", "blade-like", "clawed", "cloak-like", "cloud-like", "enormous", "fan-like", "gigantic", "huge", "layered", "patterned", "rainbow", "shield-like", "translucent", "two pairs of"};
static constexpr std::string_view flyMouth[] = {"broad", "cavernous", "frowning", "hidden", "huge", "lack of a", "mischievous", "pointed", "seemingly angry", "seemingly expressionless", "seemingly invisible", "small", "smiling", "tiny", "toothed", "tranquil looking"};
static constexpr std::string_view flyBeak[] = {"crescent", "reinforced", "broad", "crooked", "curved", "decorated", "glowing", "jagged", "black", "painted", "patterned", "pointy", "powerful", "razor sharp", "seemingly frowning", "seemingly smiling", "seemingly smirking", "sharp"};
static constexpr std::string_view flyEars[] = {"an extra pair of", "wing-like", "antenna-like", "antler-like", "fan-like", "feather-like", "fluffy", "hidden", "horn-like", "huge", "orb-like", "pointy", "puffy", "rounded", "seemingly invisible", "tiny"};
static constexpr std::string_view flyHorns[] = {"ridged", "blade-like", "curled", "curved", "jagged", "mohawk-like", "pointy", "rounded", "sharp", "small", "stubby"};
static constexpr std::string_view flyTail[] = {"a barbed tail", "a cloak-like tail", "a cloud-like tail", "a fan-like tail", "a muscular tail", "a powerful tail", "a puffy, round tail", "a rainbow colored tail", "a rather small tail", "a ribbon-like tail", "a set of tails", "an elongated tail", "an incredibly long, ribbon-like tail", "several tails in a fan-like shape", "two tails instead of one"};
static constexpr std::string_view placeFlying[] = {"high in the sky", "in dense forests", "in gardens", "in large forests", "in meadows", "in national parks", "in open fields", "in parks", "in summer", "in tall grass", "in the evening hours", "in the morning hours", "in tree tops", "in winter"};
static constexpr std::string_view flyingAttk[] = {"Acrobatics", "Aerial Ace", "Aeroblast", "Air Cutter", "Air Slash", "Bounce", "Brave Bird", "Chatter", "Defog", "Dragon Ascent", "Drill Peck", "Feather Dance", "Fly", "Gust", "Hurricane", "Mirror Move", "Oblivion Wing", "Peck", "Pluck", "Roost", "Sky Attack", "Sky Drop", "Tailwind", "Wing Attack"};
static constexpr std::string_view ghostSkin[] = {"bioluminescent", "phosphorescent", "fluorescent", "black", "black and crimson", "blue and black", "crimson", "dark", "dark blue", "gaseous", "glowing", "hazy", "luminous", "purple", "see through", "translucent"};
static constexpr std::string_view ghostLegs[] = {"elongated", "gaseous", "hanging", "hidden", "hovering", "ribbon-like", "shrouded", "stumpy", "suspended", "tiny", "veiled", "wavy"};
static constexpr std::string_view ghostArms[] = {"folded", "bioluminescent", "phosphorescent", "fluorescent", "blade-like", "cloak-like", "dangling", "floating", "glowing", "hanging", "often invisible", "ribbon-like", "shield-like", "stretched", "stubby", "wavy"};
static constexpr std::string_view ghostWings[] = {"angular", "angelic", "bioluminescent", "phosphorescent", "fluorescent", "cloak-like", "cloth-like", "cloud-like", "enormous", "gaseous", "glowing", "inflatable", "poncho-like", "powerful", "ribbon-like", "shield-like", "shrouded", "two pairs of"};
static constexpr std::string_view ghostMouth[] = {"tusked", "cavernous", "frowning", "grinning", "hidden", "huge", "serious looking", "shrouded", "smiling", "smirking", "sneering", "toothed", "veiled"};
static constexpr std::string_view ghostBeak[] = {"crescent", "barbed", "black", "blade-like", "crooked", "curved", "dark", "pointy", "razor sharp", "sharp", "shrouded", "smirking", "sneering", "veiled"};
static constexpr std::string_view ghostSnout[] = {"tusked", "horned", "bearded", "black", "dark", "frowning", "grinning", "lack of a", "mostly hidden", "partially hidden", "serious looking", "shrouded", "smiling", "smirking", "veiled"};
static constexpr std::string_view ghostEars[] = {"antenna-like", "wing-like", "broad", "broken", "curved", "floppy", "hat-like", "horn-like", "inflatable", "pointy", "rounded", "stubby", "stumpy", "tiny"};
static constexpr std::string_view ghostHorns[] = {"ridged", "a crown of", "antler-like", "bioluminescent", "phosphorescent", "fluorescent", "broken", "curled", "curved", "flame-like", "glowing", "mohawk-like", "moon-shaped", "several rows", "sharp", "two pairs of"};
static constexpr std::string_view ghostTail[] = {"a broad tail, ribbon-like tail", "a fan-like tail", "a gaseous tail", "a hovering tail", "a long tail floating gently in the air", "a long tail wrapped around its body", "a long, ribbon-like tail", "a spiky tail", "a tail like a cape", "several ribbon-like tails", "several tails instead of one", "two tails instead of one"};
static constexpr std::string_view placeGhost[] = {"near temples", "near shrines", "near sanctuaries", "at night", "in abandoned buildings", "in abandoned towers", "in clock towers", "in dark caves", "in dark forests", "in dense forests", "in labyrinths", "in the middle of the night", "near graveyards", "near ruins"};
static constexpr std::string_view ghostAttk[] = {"Astonish", "Confuse Ray", "Curse", "Destiny Bond", "Grudge", "Hex", "Lick", "Night Shade", "Nightmare", "Ominous Wind", "Phantom Force", "Shadow Ball", "Shadow Claw", "Shadow Force", "Shadow Punch", "Shadow Sneak", "Spite", "Trick-or-Treat"};
static constexpr std::string_view grassSkin[] = {"bark-like", "bioluminescent", "phosphorescent", "fluorescent", "blossoming", "camouflaged", "emerald", "glowing", "grass-like", "green", "jade", "leafy", "lush", "mossy", "sprouting", "thorny", "verdigris", "vine-like", "viridian"};
static constexpr std::string_view grassLegs[] = {"ridged", "an extra pair of", "bark-like", "brown", "elongated", "flower covered", "leaf covered", "leaf shrouded", "lean", "root-like", "seed shaped", "slim", "stumpy", "thick", "trunk-like", "veiled"};
static constexpr std::string_view grassArms[] = {"ridged", "folded", "stalk-like", "blossoming", "broccoli-like", "fan-like", "leaf", "leaf-like", "petal", "ribbon-like", "small", "sprouting", "stumpy", "thick", "thorny", "vine"};
static constexpr std::string_view grassWings[] = {"angular", "blade-like", "blossoming", "budding", "fan-like", "flowering", "leaf", "leaf-like", "needle", "petal", "ribbon-like", "sprouting", "stalk-like", "two sets of"};
static constexpr std::string_view grassMouth[] = {"bark-like", "hidden", "huge", "lack of a", "prickly", "sharp toothed", "smiling", "smirking", "thorny", "tiny"};
static constexpr std::string_view grassBeak[] = {"crescent", "bark-like", "blossoming", "broad", "curved", "humongous", "leaf shaped", "needle", "mostly overgrown", "sharp", "shining", "stubby", "thorn-like", "thorny"};
static constexpr std::string_view grassSnout[] = {"tusked", "horned", "bearded", "blossoming", "broad", "flower covered", "gentle", "huge", "leaf covered", "leaf shrouded", "mossy", "mostly overgrown", "pointy", "sharp", "smiling", "stubby", "thorny"};
static constexpr std::string_view grassEars[] = {"blossoming", "wing-like", "flower", "flowery", "fluffy", "huge", "leaf-like", "leafy", "mushroom", "mushroom-like", "needle-like", "pollen-like", "round", "sprouting", "thorny", "tiny", "vine-like"};
static constexpr std::string_view grassHorns[] = {"ridged", "a crown of", "blossoming", "curled", "curved", "flowering", "hidden", "mushroom shaped", "needle", "overgrown", "pointy", "rounded", "sharp", "spiky", "spotted"};
static constexpr std::string_view grassTail[] = {"a bioluminescent tail", "a blossoming tail", "a fan-like tail", "a leafy tail", "a moss covered tail", "a mostly overgrown tail", "a mushroom as a tail", "a needle-like tail", "a stubby tail", "a tail full of flowers", "a thorny tail", "a trunk-like tail", "a vine-like tail", "an evergrowing tail", "several vine-like tails"};
static constexpr std::string_view placeGrass[] = {"in bushes", "in dense forests", "in farmlands", "in fields", "in flowery meadows", "in forests", "in gardens", "in grassy fields", "in meadows", "in national parks", "in open fields", "in parks", "in pastures", "in summer", "in the early morning", "in the evening hours", "in tree tops", "in valleys", "in vineyards"};
static constexpr std::string_view grassAttk[] = {"Absorb", "Aromatherapy", "Bullet Seed", "Cotton Guard", "Cotton Spore", "Energy Ball", "Forest's Curse", "Frenzy Plant", "Giga Drain", "Grass Knot", "Grass Pledge", "Grass Whistle", "Grassy Terrain", "Horn Leech", "Ingrain", "Leaf Blade", "Leaf Storm", "Leaf Tornado", "Leech Seed", "Magical Leaf", "Mega Drain", "Needle Arm", "Petal Blizzard", "Petal Dance", "Power Whip", "Razor Leaf", "Seed Bomb", "Seed Flare", "Sleep Powder", "Solar Beam", "Spiky Shield", "Spore", "Stun Spore", "Synthesis", "Vine Whip", "Wood Hammer", "Worry Seed"};
static constexpr std::string_view groundSkin[] = {"amber", "brown", "brown and gray", "bulky", "camouflaged", "coarse", "compact", "dark", "dull", "dusty", "gray", "hazel", "muddy", "plated", "sandy", "sepia", "shielded", "solid", "thick"};
static constexpr std::string_view groundLegs[] = {"ridged", "an extra pair of", "armored", "coarse", "elongated", "fluffy", "heavy", "huge", "muscular", "powerful", "protected", "robust", "short", "stumpy", "thick"};
static constexpr std::string_view groundArms[] = {"ridged", "blade-like", "clawed", "dig-efficient", "drill-like", "elongated", "fluffy", "folded", "lean", "muscular", "short", "shovel-like", "strong", "stumpy", "thick"};
static constexpr std::string_view groundMouth[] = {"bearded", "broad", "cavernous", "frowning", "grinning", "huge", "lack of a", "pointy", "powerful", "seemingly expressionless", "shrouded", "small", "smiling", "tiny", "tusked", "veiled"};
static constexpr std::string_view groundBeak[] = {"blunt", "bone-like", "broad", "crescent", "curved", "horn-like", "huge", "humongous", "jagged", "large", "reinforced", "sharp", "small", "stone", "stubby"};
static constexpr std::string_view groundSnout[] = {"bearded", "broad", "coarse", "flat", "frowning", "grinning", "horned", "large", "pointy", "protected", "reinforced", "sharp toothed", "shielded", "small", "smiling", "smirking", "stubby", "tusked"};
static constexpr std::string_view groundEars[] = {"antenna-like", "bone-like", "broken", "coarse", "flabby", "flappy", "horn-like", "huge", "jagged", "orb-like", "pointy", "rounded", "stubby", "thorny", "wing-like"};
static constexpr std::string_view groundHorns[] = {"ridged", "a crown of", "blunt", "broad", "broken", "coarse", "curled", "curved", "drill-like", "mohawk-like", "orb-like", "sharp", "shield-like", "shovel-like", "stubby"};
static constexpr std::string_view groundTail[] = {"a barbed tail", "a bony tail", "a broad tail", "a bruised tail", "a fab-like tail", "a forked tail", "a long, thin tail", "a muscular tail", "a powerful tail", "a short, stubby tail", "a shovel-like tail", "a strong and nimble tail", "a stubby tail", "a tail suitable for digging", "an armor plated tail", "several tails instead of one", "two tails instead of one"};
static constexpr std::string_view placeGround[] = {"at night", "in cave systems", "in caves", "in dense forests", "in deserty areas", "in hilly areas", "in labyrinths", "in mountainous areas", "in national parks", "in rocky hill areas", "near cliffs", "near ruins", "on rocky paths", "on sandy paths"};
static constexpr std::string_view groundAttk[] = {"Bone Club", "Bone Rush", "Bonemerang", "Bulldoze", "Dig", "Drill Run", "Earth Power", "Earthquake", "Fissure", "Land's Wrath", "Magnitude", "Mud Bomb", "Mud Shot", "Mud Sport", "Mud-Slap", "Precipice Blades", "Rototiller", "Sand Tomb", "Sand Attack", "Spikes", "Thousand Arrows", "Thousand Waves"};
static constexpr std::string_view iceSkin[] = {"azure", "blue", "blue and white", "cobalt", "frost covered", "frosty", "glacial", "ice cold", "icy", "ivory", "reflective", "sapphire", "silvery", "smooth", "thick", "pure white"};
static constexpr std::string_view iceLegs[] = {"ridged", "an extra pair of", "fat", "fluffy", "ice covered", "muscular", "powerful", "short", "snowy", "stout", "strong", "stubby", "thick"};
static constexpr std::string_view iceArms[] = {"ridged", "folded", "cloak-like", "fan-like", "fat", "fluffy", "icicle-like", "lean", "muscular", "ribbon-like", "scarf-like", "strong", "stubby", "warming"};
static constexpr std::string_view iceWings[] = {"angular", "cloak-like", "enormous", "frost covered", "frosty", "gigantic", "icy", "reflective", "ribbon-like", "scarf-like", "shield-like", "shimmering", "shivering", "sleeted", "smooth", "stalactite covered", "glowing"};
static constexpr std::string_view iceMouth[] = {"bearded", "broad", "cavernous", "crystal", "frowning", "fur covered", "hidden", "icicle covered", "icicle toothed", "serious looking", "smiling", "smirking", "sparkling", "tiny"};
static constexpr std::string_view iceBeak[] = {"crescent", "broad", "crystal", "curved", "frost covered", "large, icicle-like", "pointy", "reflective", "rimy", "sapphire", "sharp", "silvery", "sleeted", "small, icicle-like"};
static constexpr std::string_view iceSnout[] = {"tusked", "horned", "bearded", "broad", "densely icicle-covered", "fluffy", "frost covered", "frosty", "frowning", "fur covered", "smiling", "smirking", "stubby", "thinly icicle-covered", "tranquil looking"};
static constexpr std::string_view iceEars[] = {"crystal-like", "fluffy", "frosty", "furry", "fuzzy", "huge", "ice-like", "icicle", "icy", "pointy", "reflective", "round", "snowball-like", "snowflake-like", "tiny"};
static constexpr std::string_view iceHorns[] = {"ridged", "a crown of", "antler-like", "broad", "crystal", "curved", "diamond shaped", "freezing", "frosty", "ice-like", "icicle", "icy, crystal-like", "pointy", "reflective", "short", "sleeted", "stubby"};
static constexpr std::string_view iceTail[] = {"a broad, fan-like tail", "a fluffy tail", "a frost covered tail", "a frosty tail", "a long, fluffy tail wrapped around its body", "a ribbon-like tail", "a short and stubby tail", "a tail wrapped around its body like a scarf", "an icicle covered tail", "an icicle-like tail", "an icy, reflective tail", "several tails instead of one", "two tails instead of one"};
static constexpr std::string_view placeIce[] = {"after a blizzard", "after a snow storm", "during a blizzard", "during snowy weather", "in icy cave systems", "in snowlands", "in snowy mountain peaks", "in taigas", "in tundras", "in winter", "on cold mountain peaks", "on frozen lakes", "on frozen rivers", "on icy plains"};
static constexpr std::string_view iceAttk[] = {"Aurora Beam", "Avalanche", "Blizzard", "Freeze-Dry", "Freeze Shock", "Frost Breath", "Glaciate", "Hail", "Haze", "Ice Ball", "Ice Beam", "Ice Burn", "Ice Fang", "Ice Punch", "Ice Shard", "Icicle Crash", "Icicle Spear", "Icy Wind", "Mist", "Powder Snow", "Sheer Cold"};
static constexpr std::string_view normSkin[] = {"bioluminescent", "phosphorescent", "fluorescent", "coarse", "dirt covered", "dull", "glossy", "glowing", "luminous", "lustrous", "messy", "radiant", "silky", "smooth", "unkempt", "velvety", "vibrant", "vivid"};
static constexpr std::string_view normLegs[] = {"ridged", "an extra pair of", "armored", "elongated", "enlarged", "huge", "lean", "muscular", "powerful", "short", "stour", "stubby", "thick", "tiny", "withdrawn"};
static constexpr std::string_view normArms[] = {"ridged", "folded", "armored", "cloak-like", "elongated", "fat", "fluffy", "lean", "little", "long", "slim", "small", "strong", "stubby", "tiny"};
static constexpr std::string_view normWings[] = {"angular", "broad", "cloak-like", "elongated", "enormous", "fluffy", "humongous", "layered", "pointy", "ribbon-like", "sharp", "slender", "smooth", "thick", "two pairs of"};
static constexpr std::string_view normMouth[] = {"bearded", "blunt toothed", "broad", "cavernous", "frowning", "grinning", "hidden", "humongous", "serious looking", "sharp toothed", "small", "smiling", "smirking", "tiny", "veiled"};
static constexpr std::string_view normBeak[] = {"crescent", "blunt", "broad", "crooked", "curved", "flattened", "huge", "sharp", "slim", "thin", "needle-like"};
static constexpr std::string_view normSnout[] = {"tusked", "horned", "bearded", "bioluminescent", "phosphorescent", "fluorescent", "broad", "fluffy", "frowning", "glowing", "large", "pointy", "smiling", "smirking", "stubby"};
static constexpr std::string_view normEars[] = {"enlarged", "wing-like", "enormous", "flabby", "flappy", "fluffy", "horn-like", "humongous", "large", "little", "pointy", "rounded", "stubby", "tiny"};
static constexpr std::string_view normHorns[] = {"ridged", "a crown of", "antler-like", "blade-like", "broken", "curled", "curved", "fan-like", "mohawk-like", "pointy", "rounded", "sharp", "spiked", "stubby", "stumpy"};
static constexpr std::string_view normTail[] = {"a fluffy tail", "a forked tail", "a glowing tail", "a long tail wrapped around its body", "a ribbon-like tail", "a short, rounded tail", "a stubby little tail", "a thick fluffy tail", "an elongated tail", "several tails instead of one", "two tails instead of one"};
static constexpr std::string_view placeNormal[] = {"all around", "at night", "during the day", "in farmlands", "in fields", "in forests", "in gardens", "in hilly areas", "in national parks", "in parks", "in quiet towns", "in the early morning", "in the evening hours", "near beaches", "near ruins", "near sanctuaries", "near temples", "on forest paths"};
static constexpr std::string_view normalAttk[] = {"Acupressure", "After You", "Assist", "Attract", "Barrage", "Baton Pass", "Belly Drum", "Bestow", "Bide", "Bind", "Block", "Body Slam", "Boomburst", "Camouflage", "Captivate", "Celebrate", "Chip Away", "Comet Punch", "Confide", "Constrict", "Conversion", "Conversion 2", "Copycat", "Covet", "Crush Claw", "Crush Grip", "Cut", "Defense Curl", "Disable", "Dizzy Punch", "Double Hit", "Double Slap", "Double Team", "Double-Edge", "Echoed Voice", "Encore", "Endeavor", "Endure", "Entrainment", "Explosion", "Extreme Speed", "Facade", "Fake Out", "False Swipe", "Feint", "Flail", "Flash", "Focus Energy", "Follow Me", "Foresight", "Frustration", "Fury Attack", "Fury Swipes", "Giga Impact", "Glare", "Growl", "Growth", "Guillotine", "Happy Hour", "Harden", "Head Charge", "Headbutt", "Heal Bell", "Helping Hand", "Hidden Power", "Hold Back", "Hold Hands", "Horn Attack", "Horn Drill", "Howl", "Hyper Beam", "Hyper Fang", "Hyper Voice", "Judgment", "Last Resort", "Leer", "Lock-On", "Lovely Kiss", "Lucky Chant", "Me First", "Mean Look", "Mega Kick", "Mega Punch", "Metronome", "Milk Drink", "Mimic", "Mind Reader", "Minimize", "Morning Sun", "Natural Gift", "Nature Power", "Noble Roar", "Odor Sleuth", "Pain Split", "Pay Day", "Perish Song", "Play Nice", "Pound", "Present", "Protect", "Psych Up", "Quick Attack", "Rage", "Rapid Spin", "Razor Wind", "Recover", "Recycle", "Reflect Type", "Refresh", "Relic Song", "Retaliate", "Return", "Roar", "Rock Climb", "Round", "Safeguard", "Scary Face", "Scratch", "Screech", "Secret Power", "Self-Destruct", "Sharpen", "Shell Smash", "Simple Beam", "Sing", "Sketch", "Skull Bash", "Slack Off", "Slam", "Slash", "Sleep Talk", "Smelling Salts", "Smokescreen", "Snore", "Soft-Boiled", "Sonic Boom", "Spike Cannon", "Spit Up", "Splash", "Stockpile", "Stomp", "Strength", "Struggle", "Substitute", "Super Fang", "Supersonic", "Swagger", "Swallow", "Sweet Scent", "Swift", "Swords Dance", "Tackle", "Tail Slap", "Tail Whip", "Take Down", "Techno Blast", "Teeter Dance", "Thrash", "Tickle", "Transform", "Tri Attack", "Trump Card", "Uproar", "Vice Grip", "Weather Ball", "Whirlwind", "Wish", "Work Up", "Wrap", "Wring Out", "Yawn"};
static constexpr std::string_view poisonSkin[] = {"armored", "bioluminescent", "phosphorescent", "fluorescent", "camouflaged", "dark", "darkened", "glossy", "glowing", "grimy", "luminous", "magenta", "purple", "shiny", "silky", "smooth", "vibrant", "violet", "vivid"};
static constexpr std::string_view poisonLegs[] = {"ridged", "an extra pair of", "armored", "elongated", "hidden", "lean", "long", "muscular", "powerful", "scaly", "skinny", "slimy", "stumpy", "thin"};
static constexpr std::string_view poisonArms[] = {"ridged", "folded", "armored", "barbed", "broad", "clawed", "elongated", "fat", "lean", "little", "muscular", "ribbon-like", "small", "strong", "stubby", "thorny"};
static constexpr std::string_view poisonWings[] = {"angular", "barbed", "bioluminescent", "phosphorescent", "fluorescent", "blade-like", "cloak-like", "elongated", "enormous", "glowing", "layered", "pointy", "reflective", "ribbon-like", "scaly", "sharp", "smooth", "thin", "thorny", "translucent"};
static constexpr std::string_view poisonMouth[] = {"tusked", "cavernous", "grinning", "hidden", "huge", "lack of a", "noxious", "sharp toothed", "shrouded", "smirking", "thorny", "tiny", "veiled", "venomous"};
static constexpr std::string_view poisonBeak[] = {"crescent", "blunt", "broad", "curved", "hidden", "noxious", "pointy", "razor sharp", "sharp", "smirking", "toothed", "veiled", "venomous"};
static constexpr std::string_view poisonSnout[] = {"bearded", "bioluminescent", "phosphorescent", "fluorescent", "fluffy", "glowing", "grimy", "horned", "luminous", "noxious", "protected", "shrouded", "slimy", "stubby", "tusked", "veiled", "venomous"};
static constexpr std::string_view poisonEars[] = {"a lack of", "wing-like", "chimney-like", "fan-like", "flabby", "flappy", "fluffy", "gooey", "hairy", "horn-like", "huge", "mucky", "pointy", "spiky", "stubby", "vent-like"};
static constexpr std::string_view poisonHorns[] = {"ridged", "a crown of", "antler-like", "barbed", "blade-like", "broken", "chimney-like", "curled", "curved", "ejectable", "fan-like", "looping", "mohawk-like", "spiky", "stinger-like", "thorny", "venomous", "vent-like"};
static constexpr std::string_view poisonTail[] = {"a barbed tail", "a bioluminescent tail", "a forked tail", "a glowing tail", "a long tail wrapped around its body", "a long, whip-like tail", "a rattling tail", "a slimy tail", "a spiky tail", "a spring-like tail", "a tail with a stinger at the end", "a thorny tail", "a venomous tail", "several tails instead of one", "two tails instead of one"};
static constexpr std::string_view placePoison[] = {"during summer", "hiding in bushes", "hiding in forests", "hiding in tree tops", "in dense forests", "in gardens", "in grassy fields", "in labyrinths", "in meadows", "in parks", "in valleys", "near cliffs"};
static constexpr std::string_view poisonAttk[] = {"Acid", "Acid Armor", "Acid Spray", "Belch", "Clear Smog", "Coil", "Cross Poison", "Gastro Acid", "Gunk Shot", "Poison Fang", "Poison Gas", "Poison Jab", "Poison Powder", "Poison Sting", "Poison Tail", "Sludge", "Sludge Bomb", "Sludge Wave", "Smog", "Toxic", "Toxic Spikes", "Venom Drench", "Venoshock"};
static constexpr std::string_view psySkin[] = {"armored", "bioluminescent", "phosphorescent", "fluorescent", "black and white", "camouflaged", "dark", "darkened", "glossy", "glowing", "luminous", "obsidian", "pink and purple", "pink and white", "purple", "smooth", "vermilion", "white"};
static constexpr std::string_view psyLegs[] = {"an extra pair of", "broad", "elongated", "fat", "hidden", "hovering", "lean", "muscular", "patterned", "powerful", "short", "shrouded", "stubby", "thick", "thin", "veiled"};
static constexpr std::string_view psyArms[] = {"armored", "cloak-like", "elongated", "fan-like", "fat", "folded", "lean", "long", "muscular", "ribbon-like", "shrouded", "slender", "stumpy"};
static constexpr std::string_view psyWings[] = {"angelic", "angular", "armored", "blade-like", "body wrapping", "cloak-like", "darkened", "enormous", "gaseous", "glossy", "huge", "reflective", "ribbon-like", "shadowy", "smooth"};
static constexpr std::string_view psyMouth[] = {"bearded", "broad", "frowning", "grinning", "hidden", "lack of a", "pointy", "seemingly expressionless", "serene looking", "shrouded", "smiling", "smirking", "tiny", "tusked", "veiled"};
static constexpr std::string_view psyBeak[] = {"crescent", "blunt", "crooked", "curved", "flat", "metal", "razor sharp", "sharp", "shrouded", "smirking", "thorny", "toothed", "veiled"};
static constexpr std::string_view psySnout[] = {"bearded", "bioluminescent", "phosphorescent", "fluorescent", "broad", "flat", "fluffy", "glowing", "hairy", "horned", "huge", "humongous", "large", "long", "protected", "shrouded", "small", "stubby", "tiny", "tusked", "veiled"};
static constexpr std::string_view psyEars[] = {"antenna-like", "wing-like", "elongated", "enormous", "fan-like", "flabby", "flappy", "fuzzy", "hidden", "horn-like", "long", "pointy", "rounded", "shrouded", "stubby", "two sets of", "veiled"};
static constexpr std::string_view psyHorns[] = {"ridged", "a crown of", "antenna-like", "antler-like", "barbed", "blade-like", "broken", "connected", "curled", "curved", "huge", "looping", "pointy", "sharp", "thick", "two sets of"};
static constexpr std::string_view psyTail[] = {"a barbed tail", "a bioluminescent tail", "a forked tail", "a long, decorated tail", "a long, muscular tail", "a ribbon-like tail", "a spiky tail", "a tail ending in a crescent shape", "a tail that ends in a fan-like shape", "a tail that ends in an orb shape", "a tail that has been tied into a knot", "a tail that hovers gently in the air", "a tail that wraps completely around its body", "a tail with a crystal on its tip", "a tail with a gem on its tip", "an armored tail", "an incredibly long tail", "several tails instead of one", "two tails instead of one"};
static constexpr std::string_view placePsychic[] = {"in abandoned buildings", "in abandoned towers", "in cave systems", "in dark caves", "in dense forests", "in the middle of the night", "near ruins", "near sanctuaries", "near shrines", "near temples", "on deserted islands"};
static constexpr std::string_view psychicAttk[] = {"Agility", "Ally Switch", "Amnesia", "Barrier", "Calm Mind", "Confusion", "Cosmic Power", "Dream Eater", "Extrasensory", "Future Sight", "Gravity", "Guard Split", "Guard Swap", "Heal Block", "Heal Pulse", "Healing Wish", "Heart Stamp", "Heart Swap", "Hyperspace Hole", "Hypnosis", "Imprison", "Kinesis", "Light Screen", "Lunar Dance", "Luster Purge", "Magic Coat", "Magic Room", "Meditate", "Miracle Eye", "Mirror Coat", "Mist Ball", "Power Split", "Power Swap", "Power Trick", "Psybeam", "Psychic", "Psycho Boost", "Psycho Cut", "Psycho Shift", "Psyshock", "Psystrike", "Psywave", "Reflect", "Rest", "Role Play", "Skill Swap", "Stored Power", "Synchronoise", "Telekinesis", "Teleport", "Trick", "Trick Room", "Wonder Room", "Zen Headbutt"};
static constexpr std::string_view rockSkin[] = {"crystal", "gem encrusted", "amber", "armored", "boulder-like", "brown", "brown and gray", "bulky", "compact", "dark", "dusty", "gray", "hard", "hazel", "muddy", "plated", "rock-like", "sandy", "sepia", "shielded", "solid", "thick"};
static constexpr std::string_view rockLegs[] = {"ridged", "an extra pair of", "armor plated", "armored", "coarse", "heavy", "huge", "muscular", "powerful", "protected", "robust", "rock-like", "short", "stone covered", "stumpy"};
static constexpr std::string_view rockArms[] = {"ridged", "folded", "armor plated", "armored", "elongated", "gem adorned", "lean", "muscular", "rocky", "rough textured", "short", "stalagmite-like", "strong", "stumpy", "thick", "two sets of"};
static constexpr std::string_view rockMouth[] = {"broad", "cavernous", "crystal", "crystal toothed", "frowning", "grinning", "powerful", "seemingly expressionless", "small", "stalactite toothed", "stalgmite and stalactite toothed", "stone", "tusked"};
static constexpr std::string_view rockBeak[] = {"crescent", "reinforced", "blunt", "bone-like", "broad", "crystal", "curved", "gem-like", "jagged", "sharp", "stone", "stubby"};
static constexpr std::string_view rockSnout[] = {"tusked", "horned", "bone covered", "broad", "coarse", "crystal", "flat", "hardened", "protected", "shielded", "stubby", "large", "small"};
static constexpr std::string_view rockEars[] = {"bone-like", "boulder-like", "broken", "coarse", "crystal", "diamond", "flappy", "flabby", "gem encrusted", "horn-like", "huge", "pointy", "rock-like", "rounded", "shield-like", "stone", "stubby"};
static constexpr std::string_view rockHorns[] = {"ridged", "a crown of", "blunt", "broad", "broken", "coarse", "crystal", "curled", "curved", "diamond", "drill-like", "gem encrusted", "metal", "obsidian", "sharp", "stone"};
static constexpr std::string_view rockTail[] = {"a broad tail", "a bruised tail", "a gem encrusted tail", "a hammer-like tail", "a muscular tail", "a powerful tail", "a shovel-like tail", "a strong and nimble tail", "a stubby tail", "a tail full of stalactites", "a tail like a stalactite", "a tail like a stalagmite", "a tail suitable for digging", "an armor plated tail"};
static constexpr std::string_view placeRock[] = {"in cave systems", "in caverns", "in caves", "in deep cavern systems", "in labyrinths", "in mountain caves", "in mountainous areas", "in rocky hill areas", "in rocky mountains", "near cliffs", "on and near hillsides", "on and near mountains", "on mountain peaks", "on rocky paths"};
static constexpr std::string_view rockAttk[] = {"Ancient Power", "Diamond Storm", "Head Smash", "Power Gem", "Rock Blast", "Rock Polish", "Rock Slide", "Rock Throw", "Rock Tomb", "Rock Wrecker", "Rollout", "Sandstorm", "Smack Down", "Stealth Rock", "Stone Edge", "Wide Guard"};
static constexpr std::string_view steelSkin[] = {"armored", "bronze", "copper", "glistening", "golden", "gray", "heavily armored", "incredibly thick", "iron", "jagged", "layered", "magnetic", "metal", "reflective", "sharp", "shiny", "silvery", "smooth", "spiky"};
static constexpr std::string_view steelLegs[] = {"ridged", "an extra pair of", "armor plated", "armored", "blade-like", "glistening", "heavy set", "honed", "huge", "magnetic", "powerful", "reflective", "sharpened", "shielded", "smooth", "spiked", "steel-plated", "thick"};
static constexpr std::string_view steelArms[] = {"ridged", "folded", "armored", "blade-like", "elongated", "energized", "lean", "metal-plated", "pincer-like", "reinforced", "shielded", "smooth", "spiky", "stubby", "sturdy", "thick"};
static constexpr std::string_view steelWings[] = {"armored", "blade-like", "enormous", "fan-like", "honed", "humongous", "layered", "magnetized", "powerful", "reflective", "reinforced", "sharp", "shield-like", "smooth", "thick", "thin"};
static constexpr std::string_view steelMouth[] = {"broad", "frowning", "hidden", "huge", "jagged", "lack of a", "powerful", "reinforced", "seemingly expressionless", "sharp", "sharp toothed", "shrouded", "smiling", "smirking", "tusked"};
static constexpr std::string_view steelBeak[] = {"crescent", "crooked", "curved", "glistening", "glowing", "huge", "humongous", "luminous", "metal", "pincer-like", "pointy", "razor sharp", "reinforced", "sharp", "shiny", "smooth", "steel plated"};
static constexpr std::string_view steelSnout[] = {"bearded", "broadened", "hidden", "metal", "metal covered", "metal plated", "metal toothed", "metal tusked", "powerful", "protective", "reinforced", "shrouded", "spiky", "stubby", "tusked"};
static constexpr std::string_view steelEars[] = {"a lack of", "antenna-like", "blade-like", "cog-shaped", "covered", "enormous", "fan-like", "helmet-like", "huge", "jagged", "pointy", "shielded", "spiky", "thick", "tiny", "u-shaped"};
static constexpr std::string_view steelHorns[] = {"ridged", "a crown of", "antenna-like", "antler-like", "barbed", "coil-like", "curled", "curved", "enormous", "forked", "honed", "keen", "looping", "mohawk-like", "needle-like", "pointy", "razor sharp", "spiky", "stubby", "u-shaped magnet"};
static constexpr std::string_view steelTail[] = {"a blade-like tail", "a fan-like tail", "a forked, blade-like tail", "a glowing, bioluminescent tail", "a glowing, metallic tail", "a long tail wrapped around its body", "a long, energized tail", "a long, spiky tail", "a magnetized tail", "a metal scaled tail", "a short, spike-like tail", "a short, stumpy tail", "a tail ending in a massive orb-like shape", "a tail ending in a u-shape magnet", "a thick, reflective tail", "an armor plated tail", "an elongated tail", "several tails instead of one", "two tails instead of one"};
static constexpr std::string_view placeSteel[] = {"after meteor showers", "in cave systems", "in caverns", "in dark caves", "in deep cavern systems", "in labyrinths", "near cliffs", "near construction works", "near mines", "near shrines"};
static constexpr std::string_view steelAttk[] = {"Autotomize", "Bullet Punch", "Doom Desire", "Flash Cannon", "Gear Grind", "Gyro Ball", "Heavy Slam", "Iron Defense", "Iron Head", "Iron Tail", "King's Shield", "Magnet Bomb", "Metal Burst", "Metal Claw", "Metal Sound", "Meteor Mash", "Mirror Shot", "Shift Gear", "Steel Wing"};
static constexpr std::string_view waterSkin[] = {"azure", "bioluminescent", "cerulean", "coral", "darkened", "fluorescent", "glistening", "glossy", "phosphorescent", "salmon", "sapphire", "shimmering", "shiny", "silky", "smooth", "sparkling", "teal", "turquoise", "ultramarine", "velvety", "white and blue"};
static constexpr std::string_view waterLegs[] = {"ridged", "an extra pair of", "coral encrusted", "elongated", "fat", "fatty", "firm", "lean", "muscular", "scaly", "shell covered", "shiny", "smooth", "steady", "stubby", "thick"};
static constexpr std::string_view waterArms[] = {"an extra pair of", "coral encrusted", "elongated", "fat", "folded", "long", "pincer-like", "ribbon-like", "ridged", "scaly", "shell covered", "short", "slim", "smooth", "stubby"};
static constexpr std::string_view waterWings[] = {"angelic", "bioluminescent", "cloak-like", "enormous", "fin-like", "flipper-like", "fluorescent", "glistening", "glowing", "layered", "phosphorescent", "ribbon-like", "scaly", "shimmering", "smooth"};
static constexpr std::string_view waterMouth[] = {"bearded", "blunt toothed", "broad", "cavernous", "frowning", "grinning", "pointy", "sharp toothed", "shrouded", "small", "smiling", "smirking", "tusked"};
static constexpr std::string_view waterBeak[] = {"bioluminescent", "blunt", "broad", "crescent", "curved", "glistening", "glowing", "pointy", "sapphire", "seemingly smiling", "shell-like", "shiny", "stubby", "wavy"};
static constexpr std::string_view waterSnout[] = {"bearded", "bioluminescent", "broad", "coral covered", "flat", "fluffy", "horned", "huge", "pointy", "shell covered", "smooth", "sparkling", "stubby", "trumpet-like", "tusked"};
static constexpr std::string_view waterEars[] = {"antenna-like", "curled", "enormous", "fin-like", "flabby", "flappy", "flipper-like", "orb-like", "shell covered", "shell-like", "short", "shrouded", "stubby", "two sets of", "wavy"};
static constexpr std::string_view waterHorns[] = {"antler-like", "a crown of", "antenna-like", "bioluminescent", "coral covered", "coral-like", "curled", "curved", "fin-like", "flipper-like", "glowing", "looping", "ridged", "shell-like", "short", "smooth", "stubby", "wavy"};
static constexpr std::string_view waterTail[] = {"a bioluminescent tail", "a broad, fan-like tail", "a coral covered tail", "a forked tail", "a glowing tail", "a huge, cloak-like tail", "a long, curled up tail", "a long, ribbon-like tail", "a long, smooth tail", "a long, wavy tail", "a ridged tail", "a shell covered tail", "a short and tiny tail", "a strong, muscular tail", "a stubby, fin-like tail", "several tails instead of one", "two tails instead of one"};
static constexpr std::string_view placeWater[] = {"around harbors", "around high tides", "around low tides", "in forest lakes", "in gentle creeks", "in lagoons", "in large canals", "in park lakes", "in rivers", "in serene lakes", "in swampy areas", "in wild water rapids", "near beaches", "near calm shores", "near coral reefs", "near ocean fronts", "near sea fronts", "near steep coastal areas", "near waterfalls", "on oceanic islands"};
static constexpr std::string_view waterAttk[] = {"Aqua Jet", "Aqua Ring", "Aqua Tail", "Brine", "Bubble", "Bubble Beam", "Clamp", "Crabhammer", "Dive", "Hydro Cannon", "Hydro Pump", "Muddy Water", "Octazooka", "Origin Pulse", "Rain Dance", "Razor Shell", "Scald", "Steam Eruption", "Soak", "Surf", "Water Gun", "Water Pledge", "Water Pulse", "Water Shuriken", "Water Sport", "Water Spout", "Waterfall", "Whirlpool", "Withdraw"};

static constexpr PokemonBase pkm_all[] = {
    {"an aardvark", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"an albatross", {"air", "water", ""}, 2, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"an alligator", {"land", "water", ""}, 2, {"skin", "scales"}, 2, {"legs", ""}, 1, "snout", "tail", "none"},
    {"an alpaca", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"an ant", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "none", "none"},
    {"an anteater", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"an antelope", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"an ape", {"land", "", ""}, 1, {"skin", "fur"}, 2, {"legs", ""}, 1, "mouth", "none", "ears"},
    {"an armadillo", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a baboon", {"land", "", ""}, 1, {"skin", "fur"}, 2, {"legs", ""}, 1, "mouth", "none", "ears"},
    {"a badger", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a barracuda", {"water", "", ""}, 1, {"scales", ""}, 1, {"fins", ""}, 1, "mouth", "none", "none"},
    {"a bat", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "ears"},
    {"a bear", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "ears"},
    {"a beaver", {"land", "water", ""}, 2, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a bee", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a bird", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a bison", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a boar", {"land", "", ""}, 1, {"skin", "hide"}, 2, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a buffalo", {"land", "water", ""}, 2, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a butterfly", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a camel", {"land", "", ""}, 1, {"hide", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a caribou", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "ears"},
    {"a cassowary", {"air", "land", ""}, 2, {"feathers", ""}, 1, {"legs", "wings"}, 2, "beak", "none", "none"},
    {"a cat", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"a caterpillar", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "none", "none"},
    {"a cheetah", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"a chicken", {"air", "land", ""}, 2, {"feathers", ""}, 1, {"legs", "wings"}, 2, "beak", "none", "none"},
    {"a chimpanzee", {"land", "", ""}, 1, {"skin", "fur"}, 2, {"legs", ""}, 1, "mouth", "none", "ears"},
    {"a chinchilla", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "ears"},
    {"a cobra", {"land", "", ""}, 1, {"skin", "scales"}, 2, {"body", ""}, 1, "mouth", "tail", "none"},
    {"a cockroach", {"land", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a cod", {"water", "", ""}, 1, {"scales", ""}, 1, {"fins", ""}, 1, "mouth", "none", "none"},
    {"a cow", {"land", "", ""}, 1, {"skin", "hide"}, 2, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a coyote", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a crab", {"land", "water", ""}, 2, {"armor", ""}, 1, {"legs", ""}, 1, "mouth", "none", "none"},
    {"a crane", {"air", "land", "water"}, 3, {"feathers", ""}, 1, {"legs", "wings"}, 2, "beak", "none", "none"},
    {"a crocodile", {"land", "water", ""}, 2, {"skin", "scales"}, 2, {"legs", ""}, 1, "mouth", "tail", "none"},
    {"a crow", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a deer", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "horns"},
    {"a dinosaur", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "snout", "tail", "none"},
    {"a dog", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a dolphin", {"water", "", ""}, 1, {"skin", ""}, 1, {"fins", ""}, 1, "mouth", "none", "none"},
    {"a donkey", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a dove", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a dragonfly", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a duck", {"air", "land", "water"}, 3, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"an eagle", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"an eel", {"water", "", ""}, 1, {"skin", ""}, 1, {"body", ""}, 1, "mouth", "tail", "none"},
    {"an eland", {"land", "", ""}, 1, {"skin", "fur"}, 2, {"legs", ""}, 1, "snout", "tail", "horns"},
    {"an elephant", {"land", "water", ""}, 2, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "none", "ears"},
    {"an elk", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "ears"},
    {"an emu", {"air", "land", ""}, 2, {"feathers", ""}, 1, {"legs", "wings"}, 2, "beak", "none", "none"},
    {"a falcon", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a ferret", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a fish", {"water", "", ""}, 1, {"scales", ""}, 1, {"fins", ""}, 1, "mouth", "none", "none"},
    {"a flamingo", {"air", "land", "water"}, 3, {"feathers", ""}, 1, {"legs", "wings"}, 2, "beak", "tail", "none"},
    {"a fly", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a fox", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a frog", {"land", "water", ""}, 2, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "none", "none"},
    {"a gazelle", {"land", "", ""}, 1, {"hide", ""}, 1, {"legs", ""}, 1, "snout", "tail", "horns"},
    {"a gerbil", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a giraffe", {"land", "", ""}, 1, {"skin", "hide"}, 2, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a gnu", {"land", "", ""}, 1, {"hide", ""}, 1, {"legs", ""}, 1, "snout", "tail", "horns"},
    {"a goat", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "horns"},
    {"a goose", {"air", "water", ""}, 2, {"feathers", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a gorilla", {"land", "", ""}, 1, {"skin", "fur"}, 2, {"legs", ""}, 1, "mouth", "none", "ears"},
    {"a grasshopper", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "none", "none"},
    {"a guinea pig", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "none", "ears"},
    {"a gull", {"air", "land", "water"}, 3, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a hamster", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "none", "ears"},
    {"a hare", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "none", "ears"},
    {"a hawk", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "none", "none"},
    {"a hedgehog", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "ears"},
    {"a herring", {"water", "", ""}, 1, {"scales", ""}, 1, {"fins", ""}, 1, "mouth", "none", "none"},
    {"a hippopotamus", {"land", "water", ""}, 2, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"a hornet", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a horse", {"land", "", ""}, 1, {"hide", "hair"}, 2, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"a hummingbird", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "none", "none"},
    {"a hyena", {"land", "", ""}, 1, {"fur", "hair"}, 2, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"an ibex", {"land", "", ""}, 1, {"hide", ""}, 1, {"legs", ""}, 1, "snout", "none", "horns"},
    {"an ibis", {"air", "land", "water"}, 3, {"feathers", ""}, 1, {"legs", "wings"}, 2, "beak", "tail", "none"},
    {"a jackal", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a jaguar", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"a jellyfish", {"water", "", ""}, 1, {"skin", ""}, 1, {"tentacles", ""}, 1, "mouth", "none", "none"},
    {"a kangaroo", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a koala", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "ears"},
    {"a komodo dragon", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "snout", "tail", "none"},
    {"a kudu", {"land", "", ""}, 1, {"hide", ""}, 1, {"legs", ""}, 1, "snout", "tail", "horns"},
    {"a lark", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a lemur", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"a leopard", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"a lion", {"land", "", ""}, 1, {"fur", "hair"}, 2, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"a llama", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "ears"},
    {"a lobster", {"water", "", ""}, 1, {"armor", ""}, 1, {"arms", ""}, 1, "mouth", "tail", "none"},
    {"a locust", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "none", "none"},
    {"a lyrebird", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a magpie", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a mammoth", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"a manatee", {"water", "", ""}, 1, {"skin", ""}, 1, {"fins", ""}, 1, "snout", "none", "none"},
    {"a mandrill", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "none", "ears"},
    {"a mole", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "ears"},
    {"a mongoose", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a monkey", {"land", "", ""}, 1, {"skin", "fur"}, 2, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"a moose", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "horns"},
    {"a mosquito", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a mouse", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a narwhal", {"water", "", ""}, 1, {"skin", ""}, 1, {"fins", ""}, 1, "mouth", "none", "none"},
    {"a newt", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "none"},
    {"a nightingale", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"an octopus", {"water", "", ""}, 1, {"skin", ""}, 1, {"tentacles", ""}, 1, "mouth", "none", "ears"},
    {"an okapi", {"land", "", ""}, 1, {"hide", ""}, 1, {"legs", ""}, 1, "snout", "tail", "none"},
    {"an opossum", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"an ostrich", {"air", "land", ""}, 2, {"feathers", ""}, 1, {"legs", "wings"}, 2, "beak", "tail", "none"},
    {"an otter", {"land", "water", ""}, 2, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"an owl", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a panda", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "ears"},
    {"a panther", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"a parrot", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a partridge", {"air", "land", ""}, 2, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a pelican", {"air", "water", ""}, 2, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a penguin", {"land", "water", ""}, 2, {"skin", ""}, 1, {"legs", "wings"}, 2, "beak", "none", "none"},
    {"a pheasant", {"air", "land", ""}, 2, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a pig", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a pigeon", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a pony", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a porcupine", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "none"},
    {"a prairie dog", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "ears"},
    {"a quail", {"air", "land", ""}, 2, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a rabbit", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"a raccoon", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a ram", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "none", "horns"},
    {"a rat", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a raven", {"air", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a reindeer", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "horns"},
    {"a rhinoceros", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"a salamander", {"land", "water", ""}, 2, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "none"},
    {"a salmon", {"water", "", ""}, 1, {"scales", ""}, 1, {"fins", ""}, 1, "mouth", "none", "none"},
    {"a sardine", {"water", "", ""}, 1, {"scales", ""}, 1, {"fins", ""}, 1, "mouth", "none", "none"},
    {"a sea lion", {"water", "", ""}, 1, {"skin", ""}, 1, {"fins", ""}, 1, "mouth", "none", "none"},
    {"a seahorse", {"water", "", ""}, 1, {"skin", ""}, 1, {"fins", ""}, 1, "snout", "tail", "ears"},
    {"a seal", {"land", "water", ""}, 2, {"skin", ""}, 1, {"fins", ""}, 1, "mouth", "none", "none"},
    {"a shark", {"water", "", ""}, 1, {"skin", ""}, 1, {"fins", ""}, 1, "mouth", "none", "none"},
    {"a sheep", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "ears"},
    {"a skunk", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a sloth", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "none"},
    {"a snake", {"land", "water", ""}, 2, {"scales", ""}, 1, {"body", ""}, 1, "mouth", "tail", "none"},
    {"a spider", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "none", "none"},
    {"a squirrel", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a swan", {"water", "", ""}, 1, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "none", "none"},
    {"a tapir", {"land", "", ""}, 1, {"hide", ""}, 1, {"legs", ""}, 1, "snout", "none", "ears"},
    {"a tarsier", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "none", "ears"},
    {"a termite", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "none", "none"},
    {"a tiger", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "ears"},
    {"a toad", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "none", "none"},
    {"a turkey", {"air", "land", ""}, 2, {"feathers", ""}, 1, {"wings", ""}, 1, "beak", "tail", "none"},
    {"a turtle", {"land", "water", ""}, 2, {"shell", "skin"}, 2, {"fins", ""}, 1, "mouth", "tail", "none"},
    {"a tortoise", {"land", "", ""}, 1, {"shell", "skin"}, 2, {"legs", ""}, 1, "mouth", "tail", "none"},
    {"a wallaby", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a walrus", {"land", "water", ""}, 2, {"skin", ""}, 1, {"fins", ""}, 1, "mouth", "none", "none"},
    {"a wasp", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a weasel", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a whale", {"water", "", ""}, 1, {"skin", ""}, 1, {"fins", ""}, 1, "mouth", "none", "none"},
    {"a wolf", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a wolverine", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a wombat", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "ears"},
    {"a yak", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "none", "horns"},
    {"a zebra", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
};

static constexpr PokemonBase pkm_bug[] = {
    {"an ant", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "none", "none"},
    {"a bee", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a butterfly", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a caterpillar", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "none", "none"},
    {"a cockroach", {"land", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a dragonfly", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a fly", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a grasshopper", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "none", "none"},
    {"a hornet", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a locust", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "none", "none"},
    {"a mosquito", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"a termite", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "none", "none"},
    {"a wasp", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
};

static constexpr PokemonBase pkm_dragon[] = {
    {"an alligator", {"land", "water", ""}, 2, {"skin", "scales"}, 2, {"legs", ""}, 1, "snout", "tail", "none"},
    {"an armadillo", {"land", "", ""}, 1, {"fur", ""}, 1, {"legs", ""}, 1, "snout", "tail", "ears"},
    {"a cobra", {"land", "", ""}, 1, {"skin", "scales"}, 2, {"body", ""}, 1, "mouth", "tail", "none"},
    {"a crocodile", {"land", "water", ""}, 2, {"skin", "scales"}, 2, {"legs", ""}, 1, "mouth", "tail", "none"},
    {"a dragonfly", {"air", "", ""}, 1, {"skin", ""}, 1, {"wings", ""}, 1, "mouth", "none", "none"},
    {"an eel", {"water", "", ""}, 1, {"skin", ""}, 1, {"body", ""}, 1, "mouth", "tail", "none"},
    {"a komodo dragon", {"land", "", ""}, 1, {"skin", ""}, 1, {"legs", ""}, 1, "snout", "tail", "none"},
    {"a narwhal", {"water", "", ""}, 1, {"skin", ""}, 1, {"fins", ""}, 1, "mouth", "none", "none"},
    {"a salamander", {"land", "water", ""}, 2, {"skin", ""}, 1, {"legs", ""}, 1, "mouth", "tail", "none"},
    {"a seahorse", {"water", "", ""}, 1, {"skin", ""}, 1, {"fins", ""}, 1, "snout", "tail", "ears"},
    {"a snake", {"land", "water", ""}, 2, {"scales", ""}, 1, {"body", ""}, 1, "mouth", "tail", "none"},
};

static const PokemonTypeTables type_tables[] = {
    {"bug", make_view(bugSkin), make_view(bugLegs), make_view(bugArms), make_view(bugWings), make_view(bugMouth), ArrayView{}, ArrayView{}, ArrayView{}, ArrayView{}, ArrayView{}, make_view(placeBug), make_view(bugAttk)},
    {"dark", make_view(darkSkin), make_view(darkLegs), make_view(darkArms), make_view(darkWings), make_view(darkMouth), make_view(darkBeak), make_view(darkSnout), make_view(darkEars), make_view(darkHorns), make_view(darkTail), make_view(placeDark), make_view(darkAttk)},
    {"dragon", make_view(dragonSkin), make_view(dragonLegs), make_view(dragonArms), make_view(dragonWings), make_view(dragonMouth), ArrayView{}, ArrayView{}, make_view(dragonEars), make_view(dragonHorns), make_view(dragonTail), make_view(placeDragon), make_view(dragonAttk)},
    {"electric", make_view(elecSkin), make_view(elecLegs), make_view(elecArms), make_view(elecWings), make_view(elecMouth), make_view(elecBeak), make_view(elecSnout), make_view(elecEars), make_view(elecHorns), make_view(elecTail), make_view(placeElectric), make_view(electricAttk)},
    {"fairy", make_view(fairySkin), make_view(fairyLegs), make_view(fairyArms), make_view(fairyWings), make_view(fairyMouth), make_view(fairyBeak), make_view(fairySnout), make_view(fairyEars), make_view(fairyHorns), make_view(fairyTail), make_view(placeFairy), make_view(fairyAttk)},
    {"fighting", make_view(fightSkin), make_view(fightLegs), make_view(fightArms), make_view(fightWings), make_view(fightMouth), make_view(fightBeak), make_view(fightSnout), make_view(fightEars), make_view(fightHorns), make_view(fightTail), make_view(placeFighting), make_view(fightingAttk)},
    {"fire", make_view(fireSkin), make_view(fireLegs), make_view(fireArms), make_view(fireWings), make_view(fireMouth), make_view(fireBeak), make_view(fireSnout), make_view(fireEars), make_view(fireHorns), make_view(fireTail), make_view(placeFire), make_view(fireAttk)},
    {"flying", make_view(flySkin), make_view(flyLegs), ArrayView{}, make_view(flyWings), make_view(flyMouth), make_view(flyBeak), ArrayView{}, make_view(flyEars), make_view(flyHorns), make_view(flyTail), make_view(placeFlying), make_view(flyingAttk)},
    {"ghost", make_view(ghostSkin), make_view(ghostLegs), make_view(ghostArms), make_view(ghostWings), make_view(ghostMouth), make_view(ghostBeak), make_view(ghostSnout), make_view(ghostEars), make_view(ghostHorns), make_view(ghostTail), make_view(placeGhost), make_view(ghostAttk)},
    {"grass", make_view(grassSkin), make_view(grassLegs), make_view(grassArms), make_view(grassWings), make_view(grassMouth), make_view(grassBeak), make_view(grassSnout), make_view(grassEars), make_view(grassHorns), make_view(grassTail), make_view(placeGrass), make_view(grassAttk)},
    {"ground", make_view(groundSkin), make_view(groundLegs), make_view(groundArms), ArrayView{}, make_view(groundMouth), make_view(groundBeak), make_view(groundSnout), make_view(groundEars), make_view(groundHorns), make_view(groundTail), make_view(placeGround), make_view(groundAttk)},
    {"ice", make_view(iceSkin), make_view(iceLegs), make_view(iceArms), make_view(iceWings), make_view(iceMouth), make_view(iceBeak), make_view(iceSnout), make_view(iceEars), make_view(iceHorns), make_view(iceTail), make_view(placeIce), make_view(iceAttk)},
    {"normal", make_view(normSkin), make_view(normLegs), make_view(normArms), make_view(normWings), make_view(normMouth), make_view(normBeak), make_view(normSnout), make_view(normEars), make_view(normHorns), make_view(normTail), make_view(placeNormal), make_view(normalAttk)},
    {"poison", make_view(poisonSkin), make_view(poisonLegs), make_view(poisonArms), make_view(poisonWings), make_view(poisonMouth), make_view(poisonBeak), make_view(poisonSnout), make_view(poisonEars), make_view(poisonHorns), make_view(poisonTail), make_view(placePoison), make_view(poisonAttk)},
    {"psychic", make_view(psySkin), make_view(psyLegs), make_view(psyArms), make_view(psyWings), make_view(psyMouth), make_view(psyBeak), make_view(psySnout), make_view(psyEars), make_view(psyHorns), make_view(psyTail), make_view(placePsychic), make_view(psychicAttk)},
    {"rock", make_view(rockSkin), make_view(rockLegs), make_view(rockArms), ArrayView{}, make_view(rockMouth), make_view(rockBeak), make_view(rockSnout), make_view(rockEars), make_view(rockHorns), make_view(rockTail), make_view(placeRock), make_view(rockAttk)},
    {"steel", make_view(steelSkin), make_view(steelLegs), make_view(steelArms), make_view(steelWings), make_view(steelMouth), make_view(steelBeak), make_view(steelSnout), make_view(steelEars), make_view(steelHorns), make_view(steelTail), make_view(placeSteel), make_view(steelAttk)},
    {"water", make_view(waterSkin), make_view(waterLegs), make_view(waterArms), make_view(waterWings), make_view(waterMouth), make_view(waterBeak), make_view(waterSnout), make_view(waterEars), make_view(waterHorns), make_view(waterTail), make_view(placeWater), make_view(waterAttk)},
};

std::string generate_descriptions_pokemons_name(std::mt19937& rng) {
    size_t rnPers = rng() % std::size(pers);
    size_t rnAmnt = rng() % std::size(amnt);
    size_t rnEvo = rng() % std::size(evo);
    size_t rnRsm = rng() % std::size(rsm);

    size_t rnd1 = rng() % std::size(pkm_all);
    const PokemonBase* chosen_pkm = &pkm_all[rnd1];

    size_t rnd2 = rng() % chosen_pkm->num_habitats;
    std::string_view habitat = chosen_pkm->habitats[rnd2];

    std::string_view pkType;
    if (habitat == "land") {
        pkType = lnd[rng() % std::size(lnd)];
    } else if (habitat == "water") {
        pkType = wtr[rng() % std::size(wtr)];
    } else {
        pkType = air[rng() % std::size(air)];
    }

    if (pkType == "bug") {
        rnd1 = rng() % std::size(pkm_bug);
        chosen_pkm = &pkm_bug[rnd1];
    } else if (pkType == "dragon") {
        rnd1 = rng() % std::size(pkm_dragon);
        chosen_pkm = &pkm_dragon[rnd1];
    }

    std::string_view candidates[5];
    size_t num_candidates = 0;
    candidates[num_candidates++] = chosen_pkm->coverings[rng() % chosen_pkm->num_coverings];
    candidates[num_candidates++] = chosen_pkm->limbs[rng() % chosen_pkm->num_limbs];
    if (!chosen_pkm->head.empty() && chosen_pkm->head != "none") {
        candidates[num_candidates++] = chosen_pkm->head;
    }
    if (!chosen_pkm->tail.empty() && chosen_pkm->tail != "none") {
        candidates[num_candidates++] = chosen_pkm->tail;
    }
    if (!chosen_pkm->ear.empty() && chosen_pkm->ear != "none") {
        candidates[num_candidates++] = chosen_pkm->ear;
    }

    for (size_t i = 0; i < 3 && i < num_candidates; ++i) {
        size_t j = i + (rng() % (num_candidates - i));
        std::swap(candidates[i], candidates[j]);
    }
    std::string_view traits[3] = { candidates[0], candidates[1], candidates[2] };

    const PokemonTypeTables* cur_tables = nullptr;
    for (const auto& tbl : type_tables) {
        if (tbl.type_name == pkType) {
            cur_tables = &tbl;
            break;
        }
    }

    std::string descrs[3];
    for (int i = 0; i < 3; ++i) {
        std::string_view t = traits[i];
        if (t == "skin" || t == "shell" || t == "hair" || t == "feathers" || t == "hide" || t == "fur" || t == "armor" || t == "scales") {
            descrs[i] = std::string(cur_tables->skin[rng() % cur_tables->skin.size()]) + " " + std::string(t);
        } else if (t == "wings") {
            ArrayView w = cur_tables->wings.empty() ? cur_tables->legs : cur_tables->wings;
            descrs[i] = std::string(w[rng() % w.size()]) + " " + std::string(t);
        } else if (t == "body") {
            ArrayView w = cur_tables->wings.empty() ? cur_tables->legs : cur_tables->wings;
            descrs[i] = "the added bonus of " + std::string(w[rng() % w.size()]) + " wings";
        } else if (t == "legs" || t == "fins") {
            descrs[i] = std::string(cur_tables->legs[rng() % cur_tables->legs.size()]) + " " + std::string(t);
        } else if (t == "arms" || t == "tentacles") {
            ArrayView a = cur_tables->arms.empty() ? cur_tables->legs : cur_tables->arms;
            descrs[i] = std::string(a[rng() % a.size()]) + " " + std::string(t);
        } else if (t == "mouth") {
            descrs[i] = "a " + std::string(cur_tables->mouth[rng() % cur_tables->mouth.size()]) + " " + std::string(t);
        } else if (t == "beak") {
            ArrayView b = cur_tables->beak.empty() ? cur_tables->mouth : cur_tables->beak;
            descrs[i] = "a " + std::string(b[rng() % b.size()]) + " " + std::string(t);
        } else if (t == "snout") {
            ArrayView s = cur_tables->snout.empty() ? cur_tables->mouth : cur_tables->snout;
            descrs[i] = "a " + std::string(s[rng() % s.size()]) + " " + std::string(t);
        } else if (t == "ears") {
            ArrayView e = cur_tables->ears.empty() ? cur_tables->mouth : cur_tables->ears;
            descrs[i] = std::string(e[rng() % e.size()]) + " " + std::string(t);
        } else if (t == "horns") {
            ArrayView h = cur_tables->horns.empty() ? cur_tables->mouth : cur_tables->horns;
            descrs[i] = std::string(h[rng() % h.size()]) + " " + std::string(t);
        } else if (t == "tail") {
            ArrayView tl = cur_tables->tail.empty() ? cur_tables->legs : cur_tables->tail;
            descrs[i] = std::string(tl[rng() % tl.size()]);
        }
    }

    std::string_view place = cur_tables->places[rng() % cur_tables->places.size()];
    size_t attk1 = rng() % cur_tables->attks.size();
    size_t attk2 = rng() % cur_tables->attks.size();
    while (attk1 == attk2) {
        attk2 = rng() % cur_tables->attks.size();
    }
    std::string_view atkOne = cur_tables->attks[attk1];
    std::string_view atkTwo = cur_tables->attks[attk2];

    std::string name = "This Pokemon is a " + std::string(pkType) + "-type Pokemon and " + std::string(rsm[rnRsm]) + " " + std::string(chosen_pkm->name) + ". It has " + descrs[0] + ", " + descrs[1] + " and " + descrs[2] + ".";
    std::string name2 = " They're generally " + std::string(pers[rnPers]) + " by nature and can often be found " + std::string(place) + ". If you're out looking for them they can often be seen " + std::string(amnt[rnAmnt]) + ".";
    std::string name3 = "It tends to attack with " + std::string(atkOne) + " and " + std::string(atkTwo) + ". It " + std::string(evo[rnEvo]) + ".";

    return name + name2 + "\n" + name3;
}
