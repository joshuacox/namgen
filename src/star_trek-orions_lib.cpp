#include "star_trek-orions_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_orions_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"D", "G", "H", "J", "L", "M", "N", "Ng", "R", "T", "Th", "V"};
    static constexpr std::string_view nm2[] = {"a", "i", "e", "o", "a", "ai", "ou", "aa", "a", "e", "i", "o"};
    static constexpr std::string_view nm3[] = {"g", "gg", "k", "kk", "l", "ll", "m", "mm", "r", "rr", "sr", "ss", "t", "tt", "yc", "z", "zz"};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm5[] = {"d", "h", "k", "l", "m", "n", "r", "rc", "v", "z", ""};
    static constexpr std::string_view nm6[] = {"D", "G", "H", "J", "L", "M", "N", "S", "Sh", "T", "Th", "V", "Zh"};
    static constexpr std::string_view nm7[] = {"a", "e", "i", "ee", "ai", "ay", "a", "e", "i", "a", "e", "i"};
    static constexpr std::string_view nm8[] = {"d", "dd", "g", "gg", "hn", "l", "ll", "n", "nn", "r", "rr", "rt", "s", "ss", "sh", "shk", "v", "vn", "vv"};
    static constexpr std::string_view nm9[] = {"a", "e", "i", "o", "u", "aa", "ou"};
    static constexpr std::string_view nm10[] = {"r", "s", "sh", "ss", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm11[] = {"hn", "l", "ll", "n", "nn", "s", "ss", "sh", "v"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 5) {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm7);
    rnd3 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm9);
    rnd5 = rng() % std::size(nm10);
    names = nm6[rnd] + nm7[rnd2] + nm8[rnd3] + nm9[rnd4] + nm10[rnd5];
    } else {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm7);
    rnd3 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm9);
    rnd5 = rng() % std::size(nm11);
    rnd6 = rng() % std::size(nm9);
    rnd7 = rng() % std::size(nm10);
    names = nm6[rnd] + nm7[rnd2] + nm8[rnd3] + nm9[rnd4] + nm11[rnd5] + nm9[rnd6] + nm10[rnd7];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5];
    }
    return names;
    }
}
