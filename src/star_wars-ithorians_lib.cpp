#include "star_wars-ithorians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_ithorians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "br", "ch", "cl", "d", "dr", "f", "g", "gr", "h", "j", "jh", "jw", "k", "kr", "l", "m", "n", "p", "ph", "pl", "pw", "q", "r", "s", "sn", "spr", "st", "t", "th", "tr", "v", "vl", "w", "wh", "y", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "aa", "oo", "ea", "ua", "eo", "ou", "ee", "ao", "ii", "aa", "ui", "au", "uu", "ie"};
    static constexpr std::string_view nm3[] = {"'kl", "'tr", "b", "bb", "c", "d", "dl", "ff", "g", "gg", "ggj", "h", "k", "kk", "kl", "kn", "l", "ld", "lj", "ll", "lln", "lm", "ln", "lr", "lt", "m", "mf", "ml", "mw", "n", "nc", "nd", "nf", "ngt", "nst", "nt", "nw", "pl", "r", "rf", "rgl", "rl", "rm", "rn", "rr", "rt", "rth", "s", "sh", "sh't", "sm", "ss", "sthm", "t", "th", "thw", "tr", "tt", "v", "vv", "w", "wb", "x", "xx", "z", "zl", "zz"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "b", "bb", "bs", "c", "cl", "d", "g", "gg", "hp", "j", "k", "l", "ls", "m", "mm", "n", "nk", "ph", "r", "rd", "rg", "rl", "rn", "rr", "s", "ss", "t", "th", "v", "w", "wl", "x", "z"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "b", "bh", "ch", "cw", "d", "dh", "f", "fr", "gh", "gw", "h", "kh", "kl", "l", "m", "n", "ph", "pl", "pw", "r", "rh", "s", "sh", "sw", "sl", "t", "th", "tw", "v", "vl", "vh", "w", "wh", "y"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "ee", "oo", "uu", "ii"};
    static constexpr std::string_view nm7[] = {"'sh", "'th", "bl", "ch", "dh", "dw", "f", "ff", "gh", "gw", "h", "hh", "kh", "kw", "ks", "l", "ls", "ll", "ln", "lm", "lth", "lsh", "lw", "m", "mm", "mf", "mw", "mn", "ml", "mw", "n", "nd", "ndr", "nf", "nw", "nsh", "ph", "rsh", "rs", "rf", "rl", "rh", "r", "rw", "rn", "rm", "rth", "sh", "sf", "sv", "sw", "shw", "ss", "sn", "sm", "th", "thw", "thl", "v", "w", "wh", "wl", "ws", "wsh"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "b", "f", "g", "h", "l", "m", "mm", "n", "ph", "r", "s", "sh", "ss", "th", "w"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "b", "c", "ch", "cr", "d", "fl", "fr", "h", "l", "m", "n", "nh", "p", "pw", "r", "s", "sl", "t", "v", "w", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ee", "oo", "ea", "ee", "au", "ua"};
    static constexpr std::string_view nm11[] = {"b", "bb", "bbl", "bl", "d", "dd", "f", "fl", "g", "h", "j", "k", "l", "ll", "lt", "m", "mfl", "n", "nd", "nt", "pr", "q", "r", "rk", "rt", "rtk", "s", "t", "th", "tr", "v", "w", "wm", "wr", "xl", "z"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "b", "bb", "d", "g", "hl", "k", "l", "ll", "m", "n", "ngs", "nd", "nn", "r", "rlq", "s", "t", "th", "thh", "ts", "w"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd5b = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm12);
    if (i % 3 == 0 && i % 2 != 0) {
    while (rnd7 < 3) {
    rnd7 = rng() % std::size(nm9);
    }
    while (rnd10 < 4) {
    rnd10 = rng() % std::size(nm12);
    }
    namelast = nm9[rnd7] + nm10[rnd8] + nm12[rnd10];
    } else if (i % 2 == 0) {
    rnd9 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    namelast = nm9[rnd7] + nm10[rnd8] + nm11[rnd11] + nm10[rnd9] + nm12[rnd10];
    } else {
    rnd9 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    rnd12 = rng() % std::size(nm10);
    rnd13 = rng() % std::size(nm11);
    namelast = nm9[rnd7] + nm10[rnd8] + nm11[rnd11] + nm10[rnd9] + nm11[rnd13] + nm10[rnd12] + nm12[rnd10];
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
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5b = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd5b] + nm6[rnd6] + nm8[rnd5] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 4) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + namelast;
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5b = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd5b] + nm2[rnd6] + nm4[rnd5] + "  " + namelast;
    }
    }
    return names;
    }
}
