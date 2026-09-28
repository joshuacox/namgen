#include "legend_of_zelda-fairys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_legend_of_zelda_fairys_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"B", "C", "D", "F", "G", "H", "K", "L", "M", "N", "P", "R", "S", "T", "V", "W", "Z"};
    static constexpr std::string_view nm2[] = {"ea", "ae", "ai", "ao", "aa", "au", "ei", "ee", "ia", "ie", "io", "oo", "oa"};
    static constexpr std::string_view nm3[] = {"f", "k", "l", "m", "n", "r", "s"};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ie", "ia", "ea", "ae", "io", "eo", "ai"};
    static constexpr std::string_view nm5[] = {"w", "r", "t", "l", "k", "h", "g", "f", "d", "s", "m", "n", "v", "c"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "", "", "t", "h", "s", "l", "n", "m"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm7);
    names = nm1[rnd] + nm4[rnd2] + nm5[rnd3] + nm6[rnd4] + nm7[rnd5];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3];
    }
    return names;
    }
}
