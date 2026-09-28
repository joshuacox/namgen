#include "places-fire_lands_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_fire_lands_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Agni", "Ash", "Ashen", "Barrage", "Berserk", "Blazing", "Blister", "Blistering", "Blustering", "Boiling", "Branded", "Brimstone", "Broiling", "Burning", "Caustic", "Charcoal", "Charred", "Charring", "Cherufe", "Combustion", "Conflagration", "Crimson", "Dragon", "Dragonfire", "Ebon", "Efreet", "Ember", "Fiery", "Firewhirl", "Flaming", "Flaring", "Frenzied", "Frenzy", "Fume", "Fuming", "Furious", "Furnace", "Glowing", "Grime", "Hell", "Inferno", "Kindle", "Lampad", "Lava", "Mad", "Magma", "Nether", "Nightmare", "Obsidian", "Onyx", "Parching", "Phoenix", "Pitch", "Pyre", "Pyro", "Rabid", "Raging", "Raving", "Roasting", "Ruined", "Sanguine", "Scalding", "Scaled", "Scarlet", "Scorching", "Searing", "Singed", "Sizzling", "Smoking", "Smouldering", "Smudge", "Solar", "Soot", "Spark", "Steaming", "Sultry", "Tempest", "Thermo", "Torch", "Torment", "Torrid", "Turbulent", "Violent", "Volcanic", "Volcano", "Wicked", "Wild"};
    static constexpr std::string_view nm2[] = {"Badlands", "Barrens", "Desert", "Domain", "Dominion", "Expanse", "Field", "Fields", "Land", "Lands", "Plains", "Range", "Terrain", "Territory", "Wastes", "Wilderness", "Wilds"};
    static constexpr std::string_view nm3[] = {"b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm5[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm7[] = {"b", "d", "g", "gh", "h", "hr", "hs", "ht", "hst", "hsh", "hn", "hm", "hl", "hz", "hx", "hq", "k", "ks", "kx", "l", "ll", "lk", "ln", "lm", "lz", "lp", "lt", "ls", "lst", "lf", "m", "mn", "mm", "mt", "ms", "n", "nn", "nt", "ns", "p", "ps", "pt", "ph", "q", "r", "rs", "rt", "rst", "rq", "rk", "rc", "rf", "rb", "rd", "s", "st", "ss", "sh", "sk", "sp", "t", "th", "ts", "w", "wth", "x", "z"};
    static constexpr std::string_view nm8[] = {"Badlands", "Barrens", "Desert", "Domain", "Dominion", "Expanse", "Field", "Fields", "Land", "Lands", "Plains", "Range", "Terrain", "Territory", "Wastes", "Wilderness", "Wilds", "Fireland", "Firelands", "Fire Fields", "Flamelands", "Flame Fields", "Ashlands", "Ash Fields", "Emberlands", "Ember Lands"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = "The " + nm1[rnd] + " " + nm2[rnd2];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm8);
    names = "The " + nm3[rnd] + nm4[rnd2] + nm5[rnd3] + nm6[rnd4] + nm7[rnd5] + " " + nm8[rnd6];
    }
    return names;
    }
}
