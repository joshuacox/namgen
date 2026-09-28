#include "star_wars-ewoks_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_ewoks_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "b", "ch", "c", "d", "gr", "g", "k", "kr", "l", "m", "n", "p", "r", "t", "tr", "w"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "ee", "oo", "aa", "y"};
    static constexpr std::string_view nm3[] = {"b", "ck", "d", "dr", "gr", "gl", "g", "k", "kk", "l", "ll", "m", "n", "pl", "rf", "rp", "rph", "rr", "st", "str"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "c", "ck", "k", "l", "m", "n", "ng", "t"};
    static constexpr std::string_view nm5[] = {"", "", "b", "ch", "d", "f", "g", "gl", "gn", "k", "kn", "l", "m", "n", "p", "r", "t", "tr"};
    static constexpr std::string_view nm6[] = {"ck", "d", "gr", "gl", "gn", "k", "l", "ll", "m", "n", "p", "pr", "r", "rph", "rp", "rr", "s", "sh", "st", "t", "zz"};
    static constexpr std::string_view nm7[] = {"b", "d", "f", "g", "gr", "gl", "j", "k", "kr", "l", "m", "n", "r", "t", "tr", "w", "z"};
    static constexpr std::string_view nm8[] = {"dr", "dd", "gr", "k", "kk", "l", "ll", "lr", "m", "mr", "mn", "n", "nr", "nl", "nt", "r", "rr", "rl", "st", "str"};
    static constexpr std::string_view nm9[] = {"c", "ck", "k", "l", "m", "n", "ng", "t"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm8);
    rnd10 = rng() % std::size(nm2);
    if (i % 2 == 0) {
    rnd9 = rng() % std::size(nm9);
    namelast = nm7[rnd6] + nm2[rnd7] + nm8[rnd8] + nm2[rnd10] + nm9[rnd9];
    } else {
    rnd9 = rng() % std::size(nm8);
    rnd11 = rng() % std::size(nm2);
    namelast = nm7[rnd6] + nm2[rnd7] + nm8[rnd8] + nm2[rnd10] + nm8[rnd9] + nm2[rnd11];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm2);
    if (i < 6) {
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3] + nm2[rnd4] + "  " + namelast;
    } else {
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm2);
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3] + nm2[rnd4] + nm6[rnd5] + nm2[rnd6] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    }
    return names;
    }
}
