#include "star_wars-falleens_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_falleens_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"c", "cz", "h", "j", "k", "s", "t", "th", "tr", "x", "xz", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "uu", "ee"};
    static constexpr std::string_view nm3[] = {"b", "h", "j", "n", "nn", "m", "mr", "mn", "mm", "rr", "sh", "sz", "t", "z", "zz"};
    static constexpr std::string_view nm4[] = {"", "", "", "l", "n", "nn", "r", "s", "st", "t", "x"};
    static constexpr std::string_view nm5[] = {"", "", "b", "d", "f", "g", "gl", "k", "kr", "l", "m", "n", "s", "th", "x", "z"};
    static constexpr std::string_view nm6[] = {"d", "dv", "f", "ff", "ll", "m", "mm", "ml", "n", "nl", "nr", "r", "rr", "s", "ss", "st", "sn", "sm", "sv", "t", "v"};
    static constexpr std::string_view nm7[] = {"", "", "", "bs", "l", "m", "n", "s", "t"};
    static constexpr std::string_view nm8[] = {"br", "b", "d", "dr", "g", "gr", "k", "kr", "l", "m", "s", "t", "w", "x", "z"};
    static constexpr std::string_view nm9[] = {"d", "dv", "dr", "f", "g", "gr", "gn", "l", "ll", "m", "mm", "mr", "ms", "nr", "nn", "n", "ns", "s", "ss", "st", "sm", "sn", "sv", "rr", "t", "tr", "thr", "v", "vr", "z"};
    static constexpr std::string_view nm10[] = {"c", "d", "j", "l", "m", "n", "r", "ss", "t", "x"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm8);
    rnd7 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm10);
    if (i % 2 == 0) {
    namelast = nm8[rnd6] + nm2[rnd7] + nm10[rnd8];
    } else {
    rnd9 = rng() % std::size(nm9);
    rnd11 = rng() % std::size(nm2);
    namelast = nm8[rnd6] + nm2[rnd7] + nm9[rnd9] + nm2[rnd11] + nm10[rnd8];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm7);
    if (i < 5) {
    while (rnd4 < 3) {
    rnd4 = rng() % std::size(nm7);
    }
    names = nm5[rnd] + nm2[rnd2] + nm7[rnd4] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm2);
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3] + nm2[rnd5] + nm7[rnd4] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm4);
    if (i < 5) {
    while (rnd4 < 3) {
    rnd4 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd4] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm4[rnd4] + "  " + namelast;
    }
    }
    return names;
    }
}
