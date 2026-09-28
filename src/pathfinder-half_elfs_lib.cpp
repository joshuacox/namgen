#include "pathfinder-half_elfs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_half_elfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "c", "d", "g", "h", "j", "jh", "k", "kh", "kr", "l", "m", "n", "p", "q", "r", "s", "t", "tr", "v", "vr", "z", "zr"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "y", "y", "ai", "ae", "ia", "ue", "ie", "ui"};
    static constexpr std::string_view nm3[] = {"d", "d", "d", "dr", "dl", "dw", "g", "g", "g", "gr", "gl", "gg", "gw", "l", "l", "l", "l", "ld", "lv", "lgr", "lbr", "lc", "ldr", "lg", "lgg", "lr", "lt", "lth", "m", "m", "m", "mr", "ml", "n", "n", "n", "nc", "nn", "nr", "nd", "ngr", "nv", "nvr", "r", "r", "r", "rc", "rg", "rr", "rth", "rv", "rvr", "rl", "rd", "rdr", "rgr", "rw", "s", "s", "s", "sh", "sl", "sr", "ss", "st", "str", "svr", "t", "t", "t", "th", "tt", "tr"};
    static constexpr std::string_view nm4[] = {"", "", "", "c", "h", "k", "l", "n", "nn", "r", "s"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "c", "ch", "d", "j", "k", "kr", "l", "m", "n", "r", "s", "sh", "t", "thr", "th", "tr", "v", "vr", "vh", "z", "zr", "zh"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ia", "au", "ie", "ua", "oi", "ou", "ae"};
    static constexpr std::string_view nm7[] = {"b", "b", "br", "cl", "cr", "d", "d", "gs", "gl", "gn", "gm", "gsh", "l", "l", "l", "lm", "lr", "lsr", "ltr", "ly", "lly", "ld", "ll", "lsb", "lv", "m", "m", "m", "my", "mr", "n", "n", "n", "nd", "nr", "nw", "nn", "ns", "nv", "ny", "pt", "pr", "r", "r", "r", "r", "rg", "rr", "rl", "rv", "ry", "s", "s", "s", "ss", "sy", "str", "sw", "thr", "tr", "th", "y", "y", "y"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "h", "l", "n", "s", "ss", "th"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "b", "bl", "cl", "d", "dr", "f", "fl", "fr", "g", "gl", "gr", "h", "j", "k", "kl", "kr", "l", "m", "n", "p", "pr", "s", "sl", "sk", "st", "t", "tr", "wr", "y", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "aa", "io", "ei", "iu", "ai", "ea", "ee"};
    static constexpr std::string_view nm11[] = {"d", "d", "d", "dr", "dw", "gr", "gw", "gn", "g", "g", "gg", "h", "h", "h", "j", "j", "j", "k", "k", "k", "kr", "kl", "km", "kn", "l", "l", "ll", "l", "lr", "lg", "ld", "ldr", "lmr", "ly", "m", "mg", "mr", "m", "m", "m", "n", "n", "n", "nn", "n", "nr", "ng", "ngr", "ndr", "nd", "nsh", "ntr", "r", "r", "r", "r", "rr", "rd", "rdr", "rg", "rgr", "rl", "rm", "rt", "s", "s", "s", "sdr", "sgr", "sg", "sh", "ssr", "t", "tr", "t", "t", "th", "v", "v", "vr", "vl", "w", "xh", "xt", "y", "yh", "zm"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "", "", "ht", "l", "m", "n", "nd", "nn", "r", "rks", "rt", "s", "th", "w", "ys"};

    std::string nameLast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd10 = rng() % std::size(nm9);
    rnd11 = rng() % std::size(nm10);
    rnd12 = rng() % std::size(nm12);
    if (i % 3 == 0 && i % 2 != 0) {
    rnd13 = rng() % std::size(nm11);
    rnd14 = rng() % std::size(nm10);
    nameLast = nm9[rnd10] + nm10[rnd11] + nm11[rnd13] + nm10[rnd14] + nm12[rnd12];
    } else if (i % 2 == 0) {
    rnd13 = rng() % std::size(nm11);
    rnd14 = rng() % std::size(nm10);
    rnd15 = rng() % std::size(nm11);
    rnd16 = rng() % std::size(nm10);
    nameLast = nm9[rnd10] + nm10[rnd11] + nm11[rnd13] + nm10[rnd14] + nm11[rnd15] + nm10[rnd16] + nm12[rnd12];
    } else {
    while (rnd10 < 4) {
    rnd10 = rng() % std::size(nm9);
    }
    while (rnd12 < 7) {
    rnd12 = rng() % std::size(nm12);
    }
    nameLast = nm9[rnd10] + nm10[rnd11] + nm12[rnd12];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 3) {
    while (rnd < 4) {
    rnd = rng() % std::size(nm1);
    }
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd5] + " " + nameLast;
    } else if (i < 6) {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + " " + nameLast;
    } else {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm8[rnd5] + " " + nameLast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 3) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 3) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + nameLast;
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + nameLast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + " " + nameLast;
    }
    }
    return names;
    }
}
