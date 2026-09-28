#include "star_wars-grans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_grans_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "br", "c", "dr", "f", "g", "gr", "h", "j", "k", "kh", "kl", "kr", "l", "m", "n", "p", "ph", "r", "rh", "s", "sh", "shm", "t", "th", "tw", "v", "y", "z", "zh"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ee", "aa", "oe", "ie", "ia", "ea"};
    static constexpr std::string_view nm3[] = {"b", "c", "d", "f", "g", "gg", "gh", "k", "kg", "kk", "ks", "l", "ll", "lv", "m", "mm", "n", "nch", "nl", "nn", "ns", "p", "ph", "r", "rb", "rg", "rh", "rl", "rr", "rv", "s", "sk", "ss", "t", "th", "tt", "w", "wh", "y", "yc"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "b", "c", "d", "f", "ff", "g", "gh", "j", "k", "ks", "kz", "l", "ls", "m", "n", "nd", "ps", "r", "rch", "rg", "s", "sk", "ss", "th", "wz", "x", "yk", "z"};
    static constexpr std::string_view nm5[] = {"ee", "aa", "oe", "ie", "ia", "ea", "ei"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm1);
    rnd7 = rng() % std::size(nm5);
    rnd8 = rng() % std::size(nm4);
    if (rnd6 < 5) {
    while (rnd8 < 5) {
    rnd8 = rng() % std::size(nm4);
    }
    }
    if (i % 2 == 0) {
    namelast = nm1[rnd6] + nm5[rnd7] + nm4[rnd8];
    } else {
    rnd9 = rng() % std::size(nm3);
    rnd11 = rng() % std::size(nm2);
    namelast = nm1[rnd6] + nm5[rnd7] + nm3[rnd9] + nm2[rnd11] + nm4[rnd8];
    }
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm4);
    if (i < 5) {
    if (rnd < 5) {
    while (rnd4 < 5) {
    rnd4 = rng() % std::size(nm4);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd4] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm4[rnd4] + "  " + namelast;
    }
    return names;
    }
}
