#include "star_wars-duross_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_duross_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "c", "d", "f", "g", "h", "j", "l", "m", "n", "r", "s", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ei", "aa", "ai", "oo"};
    static constexpr std::string_view nm3[] = {"d", "dw", "hw", "l", "lz", "ls", "ld", "lw", "m", "ms", "mz", "n", "ns", "nz", "nss", "nt", "rw", "z", "d", "l", "m", "n", "z"};
    static constexpr std::string_view nm4[] = {"d", "l", "m", "n", "r"};
    static constexpr std::string_view nm5[] = {"ch", "d", "f", "h", "j", "l", "m", "n", "r", "s", "t", "z"};
    static constexpr std::string_view nm6[] = {"ch", "d", "dw", "h", "hl", "hn", "hm", "m", "mm", "mn", "md", "ms", "n", "nd", "nl", "nw", "ns", "nt", "nn", "rl", "sl", "d", "h", "m", "n", "l", "ll"};
    static constexpr std::string_view nm7[] = {"b", "d", "h", "j", "k", "l", "m", "s", "st", "t", "tr", "v", "zh"};
    static constexpr std::string_view nm8[] = {"b", "bb", "c", "ch", "ggl", "gw", "gl", "gn", "gg", "g", "h", "kt", "ll", "lm", "lw", "md", "m", "mp", "nw", "nd", "nt", "ns", "n", "rd", "rl", "rr", "z"};
    static constexpr std::string_view nm9[] = {"", "d", "g", "ks", "l", "lt", "m", "n", "s"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd3b = 0; size_t rnd4 = 0; size_t rnd4b = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm9);
    if (i % 2 == 0) {
    namelast = nm7[rnd6] + nm2[rnd7] + nm9[rnd8];
    } else {
    rnd9 = rng() % std::size(nm8);
    rnd10 = rng() % std::size(nm2);
    namelast = nm7[rnd6] + nm2[rnd7] + nm8[rnd9] + nm2[rnd10] + nm9[rnd8];
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
    rnd5 = rng() % std::size(nm4);
    if (i < 4) {
    while (rnd < 3) {
    rnd = rng() % std::size(nm1);
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
