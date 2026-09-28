#include "star_wars-gotals_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_gotals_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"f", "gl", "h", "j", "k", "l", "m", "n", "s", "t", "th", "v", "vl", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "au", "aa", "uu", "ee"};
    static constexpr std::string_view nm3[] = {"'h", "hs", "h'sh", "h'l", "hx", "hk", "hk'kh", "'k", "k", "kh", "'kh", "'l", "lt", "p", "ph", "r'ph", "r", "'r", "r'l", "rl", "sk", "s'kh", "s'm", "sl", "shn", "sh'n", "sh'm", "sz", "shm", "t", "t'm", "tm", "tn", "tl", "t'n", "xs", "xz"};
    static constexpr std::string_view nm4[] = {"c", "k", "l", "m", "n", "s", "sh", "r", "rn", "tt", "th", "x"};
    static constexpr std::string_view nm5[] = {"g", "gr", "j", "k", "kr", "kl", "m", "n", "r", "s", "tr", "v", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm7[] = {"hs", "hx", "k", "kh", "l", "ll", "r", "rr", "rl", "rs", "s", "ss", "sl", "sk", "sh", "sm", "st", "t", "th", "tl", "v", "x", "z"};
    static constexpr std::string_view nm8[] = {"c", "gg", "gh", "l", "m", "n", "nth", "r", "rn", "rk", "ss", "t", "th", "x"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm5);
    rnd7 = rng() % std::size(nm6);
    rnd8 = rng() % std::size(nm8);
    if (i % 2 == 0) {
    namelast = nm5[rnd6] + nm6[rnd7] + nm8[rnd8];
    } else {
    rnd9 = rng() % std::size(nm7);
    rnd11 = rng() % std::size(nm6);
    namelast = nm5[rnd6] + nm6[rnd7] + nm7[rnd9] + nm6[rnd11] + nm8[rnd8];
    }
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm4);
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd4] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm4[rnd4] + "  " + namelast;
    }
    return names;
    }
}
