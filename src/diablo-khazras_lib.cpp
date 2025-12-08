#include "diablo-khazras_lib.h"
#include <vector>

std::string generate_diablo_khazras_name(std::mt19937& rng, int /*type*/) {
    static const std::vector<std::string> nm1 = {
        "", "", "", "", "b", "bl", "br", "ch", "cr", "d", "dr", "gh", "gr",
        "h", "hr", "k", "kr", "l", "m", "mw", "n", "r", "sh", "sk", "sn",
        "t", "th", "tr"
    };
    static const std::vector<std::string> nm2 = {
        "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u",
        "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o",
        "u", "oa", "ao", "au"
    };
    static const std::vector<std::string> nm3 = {
        "br", "d", "dr", "g", "gr", "ggr", "gl", "hg", "hl", "hgr", "lg",
        "lgh", "ld", "lz", "lb", "lghb", "ll", "lm", "ndr", "nd", "nz",
        "nr", "r", "rb", "rg", "rd", "rgr", "rt", "rth", "rz", "t", "wd"
    };
    static const std::vector<std::string> nm4 = {
        "", "", "", "ch", "d", "g", "gg", "k", "l", "lm", "m", "n", "nn",
        "r", "rg", "s", "sh", "t", "tch", "th", "wl"
    };

    int i = static_cast<int>(rng() % 10);
    size_t rnd  = rng() % nm1.size();
    size_t rnd2 = rng() % nm2.size();
    size_t rnd3 = rng() % nm3.size();
    size_t rnd4 = rng() % nm2.size();
    size_t rnd5 = rng() % nm4.size();

    std::string name;
    if (i < 5) {
        name = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    } else {
        size_t rnd6 = rng() % nm3.size();
        size_t rnd7 = rng() % nm2.size();
        name = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] +
               nm3[rnd6] + nm2[rnd7] + nm4[rnd5];
    }
    return name;
}
