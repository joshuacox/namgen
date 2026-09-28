#include "warhammer-wood_elfs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_wood_elfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "c", "d", "dh", "g", "k", "kh", "sc", "str", "t", "th", "tr", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "i", "o", "u", "a", "i", "o", "u", "a", "i", "o", "u", "a", "a", "o", "o", "a", "o", "o", "a", "io", "aa", "ae", "ia"};
    static constexpr std::string_view nm3[] = {"c", "d", "k", "l", "r", "c", "d", "k", "l", "r", "c", "cc", "cr", "dr", "d", "k", "kk", "lc", "lg", "lk", "ll", "lt", "lv", "l", "r", "rl", "rt", "rc", "rg", "rn", "sc", "sr", "st", "sl", "th", "tr", "tt", "zc", "zk", "zl"};
    static constexpr std::string_view nm4[] = {"", "", "", "c", "n", "s", "t", "th"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "d", "dh", "dr", "f", "h", "l", "m", "n", "ph", "q", "s", "th", "v", "y"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "y", "a", "e", "i", "y", "a", "e", "i", "y", "a", "e", "a", "a", "e", "e", "ie", "ae"};
    static constexpr std::string_view nm7[] = {"c", "cc", "ch", "d", "dd", "dr", "h", "hh", "lc", "ll", "lv", "ls", "lt", "lth", "ln", "lm", "l", "n", "nn", "nr", "nv", "nd", "ph", "r", "rl", "rr", "rv", "rl", "s", "ss", "sh", "st", "str", "sv", "t", "th", "tr", "v"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "f", "h", "l", "n", "s", "th"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 5) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5];
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm8[rnd5];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    } else {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5];
    }
    }
    return names;
    }
}
