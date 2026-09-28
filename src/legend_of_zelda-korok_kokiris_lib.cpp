#include "legend_of_zelda-korok_kokiris_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_legend_of_zelda_korok_kokiris_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "b", "d", "br", "dr", "gr", "g", "h", "k", "l", "m", "r", "tr", "t"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"c", "g", "gn", "gm", "k", "kl", "l", "v", "ld", "lm", "ll", "m", "md", "n", "nd", "r", "rn", "s", "sn", "sm", "sr"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "", "h", "l", "m", "s", "r", "n", "wn", "w"};
    static constexpr std::string_view nm5[] = {"b", "d", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "z"};
    static constexpr std::string_view nm6[] = {"b", "d", "f", "g", "h", "l", "k", "m", "n", "p", "r", "s", "t", "v", "w", "z"};
    static constexpr std::string_view nm7[] = {"c", "d", "f", "g", "h", "k", "l", "m", "n", "ph", "r", "s", "t", "th", "w", "z"};
    static constexpr std::string_view nm8[] = {"a", "e", "i", "o", "u", "ai", "ae", "ea", "ei", "eo", "ia", "io", "iu", "ie", "oa", "oe", "oi", "ou", "ua", "ue", "uo", "ui"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm8);
    names = nm6[rnd] + nm2[rnd2] + nm7[rnd3] + nm8[rnd4];
    } else {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm4[rnd4];
    } else {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm2);
    names = nm5[rnd] + nm2[rnd2] + nm7[rnd3] + nm2[rnd4];
    }
    }
    return names;
    }
}
