#include "star_wars-devaronians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_devaronians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"c", "cr", "ch", "g", "gr", "h", "j", "k", "l", "m", "n", "r", "s", "t", "tr", "v", "vr", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "au", "ue", "ao", "ei", "aa"};
    static constexpr std::string_view nm3[] = {"c", "ch", "g", "gh", "gr", "k", "kr", "kh", "kl", "l", "ll", "lm", "m", "mr", "mm", "md", "n", "nd", "r", "rt", "ss", "vr", "v"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "c", "cx", "hk", "hr", "k", "kh", "lc", "lt", "n", "r", "rc", "rh", "s", "ss", "t", "th", "x"};
    static constexpr std::string_view nm5[] = {"b", "br", "bh", "c", "ch", "cr", "g", "gh", "h", "k", "l", "m", "n", "s", "t", "th", "v"};
    static constexpr std::string_view nm6[] = {"bh", "ch", "dh", "g", "gh", "gn", "h", "hn", "hs", "l", "ll", "ln", "lm", "m", "mm", "mn", "n", "nn", "nch", "r", "rh", "s", "ss", "v"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "h", "l", "m", "n", "s", "th", "y"};
    static constexpr std::string_view nm8[] = {"br", "c", "ch", "dr", "d'r", "d'v", "dh", "g", "gr", "g'v", "h", "j", "m", "n'v", "n", "r", "t", "t'v", "t'r", "v"};
    static constexpr std::string_view nm9[] = {"d", "dd", "gr", "gn", "k", "kr", "kl", "l", "lg", "ln", "ll", "lr", "m", "mm", "mr", "mn", "n", "nn", "nd", "nh", "r", "rh", "rg", "s", "sn", "ss", "x", "v", "z"};
    static constexpr std::string_view nm10[] = {"c", "ct", "g", "hrk", "hk", "k", "kt", "l", "n", "ndt", "nd", "nt", "q", "r", "rt", "rk", "s", "sk", "st", "v", "w", "z"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd3b = 0; size_t rnd4 = 0; size_t rnd4b = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm8);
    rnd7 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm10);
    if (i % 2 == 0) {
    namelast = nm8[rnd6] + nm2[rnd7] + nm10[rnd8];
    } else {
    rnd9 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm2);
    namelast = nm8[rnd6] + nm2[rnd7] + nm9[rnd9] + nm2[rnd10] + nm10[rnd8];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm7);
    if (i < 4) {
    names = nm5[rnd] + nm2[rnd2] + nm7[rnd5] + "  " + namelast;
    } else if (i < 8) {
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm2);
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3] + nm2[rnd4] + nm7[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm2);
    rnd3b = rng() % std::size(nm6);
    rnd4b = rng() % std::size(nm2);
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3] + nm2[rnd4] + nm6[rnd3b] + nm2[rnd4b] + nm7[rnd5] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 4) {
    while (rnd5 < 5) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + namelast;
    } else if (i < 8) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd3b = rng() % std::size(nm3);
    rnd4b = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd3b] + nm2[rnd4b] + nm4[rnd5] + "  " + namelast;
    }
    }
    return names;
    }
}
