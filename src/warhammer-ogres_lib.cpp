#include "warhammer-ogres_lib.h"

#include <vector>
#include <string>

std::string generate_warhammer_ogres_name(std::mt19937& rng) {
    const std::vector<std::string> nm1 = {"b", "br", "cr", "d", "dr", "g", "gr", "gl", "k", "kr", "n", "q", "qr", "r", "skr", "sk", "sg", "sgr", "tr", "v", "vr", "z", "zr"};
    const std::vector<std::string> nm2 = {"a", "o", "u", "a", "o", "u", "a", "o", "u", "a", "o", "u", "a", "o", "u", "e", "e", "ea", "ao", "ua", "au"};
    const std::vector<std::string> nm3 = {"cl", "cr", "dgr", "ddr", "dz", "g", "gz", "gdr", "gbr", "gr", "gk", "gkr", "k", "kr", "kgz", "kg", "kgr", "kdr", "kb", "lgr", "lkf", "lgf", "", "ldr", "lgb", "lgd", "lgdr", "lzr", "lz", "ng", "ngr", "nd", "ndr", "nk", "nkz", "r", "rg", "rgr", "rgz", "rz", "s", "sgr", "sd", "sfl", "sgl"};
    const std::vector<std::string> nm4 = {"c", "d", "dd", "g", "gg", "k", "kk", "s"};
    const std::vector<std::string> nm5 = {"barb", "beast", "bitter", "black", "blood", "blunt", "bone", "boulder", "brick", "bristle", "bronze", "brown", "cask", "chain", "chest", "coal", "cold", "dark", "dew", "dim", "dirt", "dust", "earth", "ember", "fern", "fire", "flame", "flint", "frost", "froth", "gold", "gore", "granite", "gravel", "green", "gut", "guts", "hill", "horn", "horse", "iron", "keg", "krag", "lone", "long", "man", "metal", "molten", "mud", "oat", "orb", "ore", "pebble", "rage", "rain", "rock", "simple", "slate", "snow", "stone", "stout", "strong", "tusk", "wild"};
    const std::vector<std::string> nm6 = {"back", "bane", "bash", "basher", "beard", "belly", "belt", "bender", "bite", "biter", "bone", "brace", "branch", "breaker", "breath", "bringer", "brow", "buckle", "buster", "chaser", "chew", "chewer", "cleaver", "crush", "crusher", "cut", "cutter", "dig", "digger", "eater", "eye", "eyes", "feet", "fist", "foot", "force", "gaze", "gazer", "grip", "hammer", "hand", "head", "hunter", "mark", "maul", "maw", "might", "munch", "muncher", "pelt", "punch", "ripper", "seeker", "shoulder", "slayer", "snarl", "spine", "splinter", "splitter", "strength", "stride", "strider", "striker", "teeth", "tooth", "watcher"};

    // Random values
    int i = static_cast<int>(rng() % 10);
    size_t rnd  = rng() % nm1.size();
    size_t rnd2 = rng() % nm2.size();
    size_t rnd5 = rng() % nm4.size();
    size_t rnd3 = rng() % nm5.size();
    size_t rnd4 = rng() % nm6.size();

    // Ensure the suffix parts are not identical
    while (nm5[rnd3] == nm6[rnd4]) {
        rnd4 = rng() % nm6.size();
    }

    std::string lName = " " + nm5[rnd3] + nm6[rnd4];
    std::string name;

    if (i < 5) {
        name = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + lName;
    } else {
        rnd3 = rng() % nm3.size();
        rnd4 = rng() % nm2.size();   // reuse nm2 for the extra vowel part
        name = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + lName;
    }

    return name;
}
