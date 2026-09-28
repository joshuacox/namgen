#include "the_witcher-humans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_the_witcher_humans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "br", "c", "ch", "d", "dr", "f", "gr", "g", "h", "k", "kr", "l", "m", "n", "r", "s", "st", "str", "t", "th", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ui", "ea", "ei", "ie", "ai", "ua", "ei", "eo", "ia", "aa", "ee"};
    static constexpr std::string_view nm3[] = {"b", "b", "br", "bl", "cl", "c", "c", "cr", "d", "d", "dl", "dr", "g", "g", "gr", "gn", "k", "k", "kr", "kn", "l", "l", "lc", "ll", "lm", "lt", "lw", "m", "m", "mn", "mr", "n", "n", "nc", "ndl", "nh", "nn", "ns", "nz", "r", "r", "rd", "rk", "rn", "rs", "rv", "ry", "s", "s", "st", "sk", "sr", "str", "t", "th", "tr", "tn", "t", "thm", "v", "v", "z", "z"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ui", "ea", "ei", "ie", "ai", "ua", "ei", "eo", "ia", "aa", "ee"};
    static constexpr std::string_view nm5[] = {"", "b", "b", "br", "bl", "cl", "c", "c", "cr", "d", "d", "dl", "dr", "g", "g", "gr", "gn", "k", "k", "kr", "kn", "l", "l", "lc", "ll", "lm", "lt", "lw", "m", "m", "mn", "mr", "n", "n", "nc", "ndl", "nh", "nn", "ns", "nz", "r", "r", "rd", "rk", "rn", "rs", "rv", "ry", "s", "s", "st", "sk", "sr", "str", "t", "th", "tr", "tn", "t", "thm", "v", "v", "z", "z"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "b", "c", "ck", "d", "k", "l", "ld", "ll", "lt", "n", "nd", "r", "s", "st", "y"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "br", "c", "d", "dh", "f", "gl", "gr", "gw", "k", "l", "m", "n", "ph", "r", "s", "sh", "t", "th", "tr", "v", "y"};
    static constexpr std::string_view nm9[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ai", "io", "ei", "ea", "ae", "ia", "ue", "ua"};
    static constexpr std::string_view nm10[] = {"br", "b", "dh", "d", "dd", "f", "ff", "fr", "g", "gh", "gg", "k", "l", "ll", "lm", "ln", "lv", "n", "nc", "nfr", "nn", "pp", "ph", "pr", "r", "rg", "rr", "s", "ss", "sh", "tt", "th", "v", "zk", "z"};
    static constexpr std::string_view nm11[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ai", "io", "ei", "ea", "ae", "ia", "ue", "ua"};
    static constexpr std::string_view nm12[] = {"", "br", "b", "dh", "d", "dd", "f", "ff", "fr", "g", "gh", "gg", "k", "l", "ll", "lm", "ln", "lv", "n", "nc", "nfr", "nn", "pp", "ph", "pr", "r", "rg", "rr", "s", "ss", "sh", "tt", "th", "v", "zk", "z"};
    static constexpr std::string_view nm14[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "s", "n", "h", "l", "th"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm9);
    rnd3 = rng() % std::size(nm10);
    rnd6 = rng() % std::size(nm9);
    rnd7 = rng() % std::size(nm14);
    if (i < 5) {
    names = nm8[rnd] + nm9[rnd2] + nm10[rnd3] + nm9[rnd6] + nm14[rnd7];
    } else {
    rnd4 = rng() % std::size(nm11);
    rnd5 = rng() % std::size(nm12);
    if (rnd4 < 20) {
    rnd5 = 0;
    rnd6 = 0;
    } else {
    while (rnd5 == 0) {
    rnd5 = rng() % std::size(nm12);
    }
    }
    names = nm8[rnd] + nm9[rnd2] + nm10[rnd3] + nm11[rnd4] + nm12[rnd5] + nm9[rnd6] + nm14[rnd7];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm7);
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd6] + nm7[rnd7];
    } else {
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    if (rnd4 < 40) {
    rnd5 = 0;
    rnd6 = 0;
    } else {
    while (rnd5 == 0) {
    rnd5 = rng() % std::size(nm5);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm2[rnd6] + nm7[rnd7];
    }
    }
    return names;
    }
}
