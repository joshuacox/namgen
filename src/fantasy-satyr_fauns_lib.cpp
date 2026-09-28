#include "fantasy-satyr_fauns_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_satyr_fauns_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "br", "c", "ch", "cr", "cl", "d", "dr", "dh", "f", "g", "gr", "gh", "gl", "gn", "h", "j", "k", "kr", "kn", "m", "n", "pr", "p", "q", "r", "rh", "s", "sh", "st", "str", "sn", "sm", "t", "tr", "v", "vr", "wr", "x", "xh", "z", "zr", "zh", "c", "d", "f", "g", "j", "j", "k", "m", "n", "p", "q", "r", "s", "t", "v", "x", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "y", "ai", "ae", "au", "aa", "ea", "eo", "ee", "ia", "ie", "io"};
    static constexpr std::string_view nm3[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "x", "z"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "", "", "b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "w", "x", "z"};
    static constexpr std::string_view nm5[] = {"c", "ck", "g", "h", "k", "l", "m", "n", "q", "r", "s", "sh", "t", "th", "x", "z"};
    static constexpr std::string_view nm6[] = {"e", "i", "u", "a", "o", "y", "ia", "ea", "ae"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    if (type == 1) {
    if (i < 5) {
    rnd4 = rng() % std::size(nm6);
    while (rnd < 3) {
    rnd = rng() % std::size(nm1);
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm6[rnd4];
    } else {
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm5);
    rnd7 = rng() % std::size(nm6);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm2[rnd5] + nm5[rnd6] + nm6[rnd7];
    }
    } else {
    if (i < 5) {
    while (rnd < 3) {
    rnd = rng() % std::size(nm1);
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3];
    } else {
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm2[rnd5] + nm5[rnd6];
    }
    }
    return names;
    }
}
