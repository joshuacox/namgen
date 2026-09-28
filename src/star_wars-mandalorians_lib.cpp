#include "star_wars-mandalorians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_mandalorians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "", "", "", "", "b", "br", "c", "ch", "d", "dr", "g", "gh", "gr", "h", "j", "k", "kr", "l", "ll", "m", "n", "nj", "p", "r", "rh", "s", "t", "tr", "th", "thr", "v", "vr", "w", "x", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "a", "o", "o", "o", "u", "u", "u", "a", "o", "u", "ae", "uu", "ii", "aa", "ea", "ai", "ee", "io", "oe"};
    static constexpr std::string_view nm3[] = {"b", "bb", "d", "dd", "g", "gg", "j", "k", "kk", "l", "ll", "m", "n", "nn", "p", "r", "rr", "s", "ss", "t", "v", "y", "b", "d", "g", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "y", "b", "bb", "br", "bz", "d", "dd", "dz", "dr", "g", "gg", "gb", "gd", "ht", "j", "k", "kk", "kb", "kd", "kr", "ksh", "l", "ll", "lm", "lr", "m", "mz", "n", "nd", "ng", "nn", "nt", "nz", "p", "ps", "r", "rbr", "rd", "rg", "rk", "rr", "rst", "rt", "rth", "s", "sc", "ss", "t", "ty", "v", "y", "zd"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "c", "ck", "d", "dth", "g", "gg", "gr", "j", "k", "l", "ld", "m", "n", "ng", "nk", "nn", "nx", "r", "rk", "rr", "rt", "s", "t", "th", "ts", "x", "z"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "b", "bh", "d", "f", "h", "j", "jh", "k", "kh", "l", "m", "n", "ph", "r", "s", "sh", "t", "th", "v", "vh", "w", "wh", "x", "z", "zh"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "i", "a", "e", "i", "o", "u", "a", "i", "a", "e", "i", "o", "u", "a", "i", "a", "e", "i", "o", "u", "a", "i", "aa", "ao", "ay", "oo", "ae", "ai", "ia"};
    static constexpr std::string_view nm7[] = {"b", "bb", "d", "dd", "g", "gg", "j", "k", "kk", "l", "ll", "m", "n", "nn", "p", "r", "rr", "s", "ss", "t", "v", "y", "b", "d", "g", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "y", "b", "c", "g", "k", "n", "r", "s", "t", "th", "v", "b", "c", "g", "k", "n", "r", "s", "t", "th", "v", "b", "c", "g", "k", "n", "r", "s", "t", "th", "v", "b", "bb", "c", "ch", "d", "dh", "f", "ff", "g", "h", "hh", "k", "l", "ll", "m", "mm", "mn", "mr", "ms", "n", "nr", "nm", "nt", "ph", "r", "rr", "rs", "rt", "rn", "rm", "rl", "s", "ss", "sh", "st", "sth", "sm", "sn", "sl", "sk", "t", "th", "v", "vl"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "c", "h", "k", "l", "lk", "m", "n", "rn", "s", "sh", "th"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "b", "bl", "br", "c", "ch", "cr", "d", "dr", "f", "g", "h", "j", "k", "kr", "l", "m", "n", "p", "q", "r", "s", "sh", "sk", "sp", "st", "str", "t", "tr", "v", "w", "wr", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "o", "u", "y", "a", "e", "i", "o", "u", "a", "o", "u", "y", "a", "e", "i", "o", "u", "a", "o", "u", "y", "oo", "ou", "ai", "ua", "au", "uu"};
    static constexpr std::string_view nm11[] = {"b", "bb", "d", "dd", "g", "gg", "j", "k", "kk", "l", "ll", "m", "n", "nn", "p", "r", "rr", "s", "ss", "t", "v", "y", "b", "d", "g", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "y", "b", "ch", "d", "f", "g", "gg", "gr", "h", "k", "kk", "l", "lb", "lg", "lk", "ll", "m", "n", "nk", "pm", "r", "rh", "rk", "rm", "rn", "rr", "rv", "rvh", "s", "t", "v", "vh", "x", "zl"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "c", "d", "g", "gg", "gh", "hl", "k", "l", "ll", "n", "ng", "ngh", "nch", "r", "rd", "rr", "rs", "rn", "rt", "s", "ss", "st", "t", "tt", "wr"};
    static constexpr std::string_view nm13[] = {"b", "bb", "d", "dd", "g", "gg", "j", "k", "kk", "l", "ll", "m", "n", "nn", "p", "r", "rr", "s", "ss", "t", "v", "b", "d", "g", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm12);
    if (i % 2 != 0) {
    rnd9 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    namelast = nm9[rnd7] + nm10[rnd8] + nm11[rnd11] + nm10[rnd9] + nm12[rnd10];
    } else {
    while (rnd7 < 5) {
    rnd7 = rng() % std::size(nm9);
    }
    while (rnd10 < 5) {
    rnd10 = rng() % std::size(nm12);
    }
    namelast = nm9[rnd7] + nm10[rnd8] + nm12[rnd10];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 4) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm5);
    }
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd5] + "  " + namelast;
    } else if (i < 8) {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm13);
    rnd4 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm13);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm13[rnd3] + nm6[rnd4] + nm13[rnd6] + nm6[rnd7] + nm8[rnd5] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 4) {
    while (rnd < 10) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 7) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + namelast;
    } else if (i < 8) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm13);
    rnd4 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm13);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm13[rnd3] + nm2[rnd4] + nm13[rnd6] + nm2[rnd7] + nm4[rnd5] + "  " + namelast;
    }
    }
    return names;
    }
}
