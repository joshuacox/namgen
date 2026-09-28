#include "legend_of_zelda-gerudos_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_legend_of_zelda_gerudos_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"B", "C", "D", "G", "H", "K", "M", "R", "T"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"b", "d", "f", "g", "l", "m", "n", "r", "t", "v", "z", "b", "d", "f", "g", "l", "m", "n", "r", "t", "v", "z", "b", "d", "f", "g", "l", "m", "n", "r", "t", "v", "z", "b", "d", "f", "g", "l", "m", "n", "r", "t", "v", "z", "b", "d", "f", "g", "l", "m", "n", "r", "t", "v", "z", "br", "bl", "dr", "dl", "fl", "fn", "fm", "fr", "gr", "gn", "gm", "lb", "ld", "lg", "lm", "ln", "lr", "lt", "lz", "mb", "md", "ml", "mn", "mr", "nb", "nd", "ng", "nl", "nm", "nr", "nz", "rb", "rd", "rg", "rl", "rm", "rn", "rt", "rs", "tl", "tm", "tn", "tr", "vl", "vm", "zl"};
    static constexpr std::string_view nm4[] = {"g", "l", "lm", "ln", "m", "n", "r", "rf", "rg", "rn", "rm", "rt", "ng"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "k", "n", "m", "l", "t", "s", "f", "g", "h", "r"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ei", "ea", "eo", "oa", "ou", "oo", "ae", "ai", "au"};
    static constexpr std::string_view nm7[] = {"v", "m", "k", "b", "r", "f", "g", "l", "n", "s", "t"};
    static constexpr std::string_view nm8[] = {"m", "k", "r", "f", "g", "l", "n", "s", "t"};
    static constexpr std::string_view nm9[] = {"a", "e", "i", "o", "u", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    rnd6 = rng() % std::size(nm9);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + nm9[rnd6];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm3[rnd6] + nm2[rnd7] + nm4[rnd4];
    }
    return names;
    }
}
