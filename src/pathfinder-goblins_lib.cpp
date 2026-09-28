#include "pathfinder-goblins_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_goblins_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "b", "ch", "dr", "fl", "g", "gh", "j", "k", "kr", "l", "m", "n", "p", "r", "v", "w", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "oo", "ou", "oa"};
    static constexpr std::string_view nm3[] = {"bb", "bbl", "bm", "br", "bn", "bz", "d", "dd", "dr", "dz", "dg", "ff", "g", "ggl", "gm", "gn", "gt", "gv", "gb", "gd", "m", "md", "mb", "mz", "mg", "mk", "nth", "nz", "nd", "ng", "ngb", "ngl", "nd", "nv", "rg", "rk", "rp", "rs", "rt", "rd", "rg", "tf", "tv", "tt", "tg", "v", "vg", "vd", "vn", "vm"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "b", "ff", "g", "k", "n", "nk", "rch", "rd", "rg", "rk", "rnk", "rt", "s", "sh", "t", "wg", "z"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "ch", "f", "g", "gh", "gr", "h", "j", "kl", "l", "m", "n", "p", "r", "v", "vr", "y", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "e", "i", "o", "a", "e", "i", "o", "u", "e", "i", "o", "a", "e", "i", "o", "u", "e", "i", "o", "ee", "ie", "oo"};
    static constexpr std::string_view nm7[] = {"ck", "dl", "dg", "dr", "dn", "dk", "g", "gl", "gn", "gm", "gl", "k", "kk", "kl", "kn", "km", "kch", "kt", "lk", "ld", "lg", "lv", "lb", "ll", "mb", "ml", "mp", "md", "mk", "mr", "nb", "nch", "nd", "ng", "nk", "p", "ph", "phr", "phl", "rk", "rg", "rd", "rb", "rbl", "s", "sh", "ss", "sk", "st", "t", "tr", "tl", "tch", "vv", "x"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "b", "h", "l", "k", "n", "ns", "ms", "s", "sh", "th"};
    static constexpr std::string_view nm9[] = {"Amber", "Ash", "Bear", "Blade", "Blood", "Bone", "Boulder", "Cask", "Claw", "Crag", "Crow", "Crystal", "Dead", "Dew", "Dog", "Doom", "Ear", "Earth", "Elf", "Ember", "Far", "Finger", "Fire", "Fist", "Flame", "Flint", "Forest", "Frost", "Fuse", "Gloom", "Gold", "Gore", "Grass", "Gut", "Hallow", "Hard", "Haze", "Heart", "Heavy", "Hell", "High", "Hill", "Hog", "Horse", "Ice", "Iron", "Keen", "Long", "Man", "Marble", "Marsh", "Meadow", "Moon", "Moss", "Nettle", "Nose", "Orb", "Pine", "Plain", "Poke", "Rage", "Rain", "Raven", "Rip", "River", "Rock", "Rough", "Shadow", "Silver", "Skull", "Snake", "Snow", "Spider", "Stab", "Star", "Steel", "Stern", "Stone", "Storm", "Strong", "Stump", "Swamp", "Toe", "Tree", "Water", "Wild", "Wind", "Wold", "Wood"};
    static constexpr std::string_view nm10[] = {"bane", "bash", "basher", "belly", "bender", "binder", "bite", "biter", "blazer", "bleeder", "blight", "brace", "brand", "breaker", "breath", "brew", "brook", "brow", "bumper", "caller", "chaser", "chew", "chewer", "chopper", "cleaver", "cooker", "crag", "crest", "crusher", "cut", "cutter", "dancer", "draft", "dreamer", "dust", "eye", "fall", "fang", "flaw", "flayer", "force", "fury", "gloom", "grip", "gripper", "guard", "gut", "hammerer", "horn", "hunter", "jumper", "killer", "lasher", "mark", "mauler", "maw", "more", "nugget", "part", "parts", "pike", "punch", "puncher", "rage", "rager", "reaper", "reaver", "rip", "ripper", "roar", "rock", "scar", "scream", "seeker", "shard", "shield", "shooter", "shot", "singer", "slaver", "slayer", "snacker", "snarl", "snouth", "spark", "spear", "splitter", "stalk", "stalker", "steel", "stick", "stomper", "strike", "striker", "surge", "taker", "tracker", "trapper", "wad", "walker", "watcher", "wound"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 2) {
    rnd = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm10);
    names = std::string(nm9[rnd]) + std::string(nm10[rnd2]);
    } else if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm8);
    if (i < 6) {
    names = std::string(nm5[rnd]) + std::string(nm2[rnd2]) + std::string(nm7[rnd3]) + std::string(nm2[rnd4]) + std::string(nm8[rnd5]);
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm2);
    names = std::string(nm5[rnd]) + std::string(nm2[rnd2]) + std::string(nm7[rnd3]) + std::string(nm2[rnd4]) + std::string(nm7[rnd6]) + std::string(nm2[rnd7]) + std::string(nm8[rnd5]);
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 4) {
    while (rnd < 4) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 5) {
    rnd5 = rng() % std::size(nm4);
    }
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm4[rnd5]);
    } else if (i < 8) {
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm4[rnd5]);
    } else {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm3[rnd6]) + std::string(nm2[rnd7]) + std::string(nm4[rnd5]);
    }
    }
    return names;
    }
}
