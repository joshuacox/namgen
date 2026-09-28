#include "places-dimensions_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_dimensions_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "ch", "cw", "cr", "cy", "cl", "br", "by", "bl", "dr", "dy", "dl", "fr", "fy", "fl", "gr", "gy", "gl", "gn", "gh", "kr", "kh", "kl", "ky", "kn", "lh", "ly", "my", "ny", "ph", "pr", "pl", "py", "pn", "rh", "ry", "sh", "sr", "str", "st", "sn", "sm", "sl", "sw", "th", "tr", "thr"};
    static constexpr std::string_view names2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ea", "eo", "eu", "ei", "ee", "ia", "io", "iu", "ie", "ae", "ao", "ai", "aa", "ua", "ui", "ue", "oi", "oo", "ou", "oe"};
    static constexpr std::string_view names3[] = {"sh", "ch", "ph", "br", "cr", "dr", "gr", "st", "str", "cl", "gl", "kl", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "bb", "cc", "dd", "gg", "kk", "ll", "mm", "nn", "pp", "rr", "ss", "tt"};
    static constexpr std::string_view names4[] = {"bith", "ch", "cyl", "cyn", "cys", "cire", "din", "dynn", "dale", "dea", "dor", "dore", "dath", "dag", "gath", "gor", "glyn", "gwyn", "ghon", "gor", "gaz", "jax", "gax", "glin", "lax", "lix", "lan", "lahr", "lyn", "lag", "laq", "myn", "myhr", "myth", "mix", "myx", "max", "maq", "mhaz", "nos", "noth", "nix", "nith", "nyl", "nif", "nor", "nore", "nox", "noxis", "phis", "phas", "phara", "phere", "phire", "phaire", "pix", "para", "pale", "pea", "prea", "qir", "qira", "qur", "que", "qia", "qin", "qis", "qith", "qoth", "rire", "roth", "raz", "riq", "raq", "raqa", "rhan", "ril", "rix", "riz", "roth", "rath", "syn", "sh", "six", "san", "sol", "sos", "sox", "th", "x", "pis", "pith", "tea", "tix", "toq", "tire", "tore", "tale", "thal", "tis", "til", "tur", "tig", "vys", "vyn", "vox", "via", "vil", "xin", "xas", "xar", "zal", "zar"};
    static constexpr std::string_view names5[] = {"Ageless", "Amber", "Amnesia", "Ancestral", "Ancient", "Angel", "Anima", "Ash", "Astral", "Autumn", "Barbaric", "Barren", "Behemoth", "Berserk", "Blessed", "Blind", "Blood", "Blood Magic", "Bone", "Brutal", "Burning", "Cannibal", "Celestial", "Cerulean", "Clone", "Cosmic", "Cosmos", "Crimson", "Cyber", "Dark", "Dark Magic", "Day", "Daydream", "Dead", "Death", "Deception", "Demon", "Deranged", "Desolate", "Destiny", "Diabolical", "Divine", "Doom", "Dragon", "Dream", "Ebon", "Echo", "Elder", "Elemental", "Elysian", "Emerald", "Empty", "Eternal", "Ethereal", "Fade", "Fallow", "False", "Fire", "First", "Flame", "Forged", "Forsaken", "Fossil", "Freak", "Free", "Frozen", "Fury", "Future", "Gateway", "Ghost", "Giants", "Gloom", "God", "Godly", "Golden", "Gray", "Green", "Grim", "Hallowed", "Hallucination", "Healing", "Heaven", "Hell", "Hollow", "Holy", "Horror", "Hungry", "Hysteria", "Ice", "Illusion", "Immortal", "Impure", "Infernal", "Inferno", "Infinite", "Insane", "Isolated", "Ivory", "Last", "Legend", "Lifeless", "Light", "Limbo", "Lonely", "Lost", "Lunar", "Mad", "Magic", "Malevolent", "Master", "Maze", "Mime", "Mimic", "Mind", "Miracle", "Mirage", "Mirror", "Mist", "Monster", "Mortal", "Mutant", "Mystery", "Myth", "Mythical", "Necrotic", "Nether", "Night", "Nightmare", "Oblivion", "Obsidian", "Oracle", "Outcast", "Pandora", "Parallel", "Peace", "Phantom", "Placid", "Plague", "Portal", "Primal", "Prime", "Primeval", "Pristine", "Pure", "Rage", "Rainbow", "Reflection", "Relic", "Rogue", "Ruined", "Sacred", "Sanctuary", "Sanguine", "Sapphire", "Savage", "Serene", "Shade", "Shadow", "Shattered", "Silver", "Skeletal", "Snow", "Solar", "Solitary", "Solstice", "Soul", "Soulless", "Spirit", "Spring", "Starfall", "Storm", "Summer", "Temporal", "Terror", "Thunder", "Time Lost", "Timeless", "Titan", "Tranquil", "Trickster", "Twilight", "Twin", "Unborn", "Undead", "Universe", "Unstable", "Utopian", "Vacuum", "Virtual", "Vision", "Voiceless", "Void", "War", "Water", "Whisper", "White", "Wicked", "Winter", "Wish", "Wither"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (i < 3) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd5 = rng() % std::size(names4);
    names = names1[rnd] + names2[rnd2] + names4[rnd5];
    } else if (i < 5) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    rnd4 = rng() % std::size(names2);
    rnd5 = rng() % std::size(names4);
    names = names1[rnd] + names2[rnd2] + names3[rnd3] + names2[rnd4] + names4[rnd5];
    } else {
    rnd = rng() % std::size(names5);
    names = "The " + names5[rnd] + " Dimension";
    }
    return names;
    }
}
