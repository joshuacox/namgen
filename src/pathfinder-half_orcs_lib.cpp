#include "pathfinder-half_orcs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_half_orcs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "b", "br", "c", "cr", "d", "dr", "g", "gr", "h", "hr", "k", "m", "n", "p", "t", "th", "ts", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "o", "o", "aa", "au", "oa", "ia", "ai", "uu"};
    static constexpr std::string_view nm3[] = {"br", "b", "d", "dh", "dr", "dz", "g", "gr", "gd", "gh", "k", "kh", "kt", "kd", "kr", "lgr", "ltr", "ldr", "lr", "lkr", "nd", "ng", "ngr", "ndr", "nv", "r", "rv", "rg", "rdr", "st", "sd", "str", "tr", "v", "zr", "zz", "zv", "zvr"};
    static constexpr std::string_view nm4[] = {"", "", "", "ch", "d", "g", "k", "l", "lm", "n", "r", "rg", "rm", "rv", "s", "sk", "t", "x", "zhg"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "b", "br", "c", "d", "dr", "g", "h", "k", "m", "n", "r", "rz", "s", "sh", "str", "t", "v", "w", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "o", "o", "ay", "ou", "ai", "uo"};
    static constexpr std::string_view nm7[] = {"b", "br", "bl", "c", "cl", "cr", "d", "dl", "dr", "g", "gh", "gr", "gl", "hg", "hk", "hr", "jk", "l", "ljk", "ll", "ln", "lr", "lt", "m", "mr", "mg", "ml", "n", "ng", "nl", "nc", "r", "rg", "rl", "rd", "s", "sl", "sr", "t", "tt", "tr", "v", "vr", "z", "zr"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "h", "n", "sh", "th", "x"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "b", "c", "d", "g", "gn", "h", "j", "k", "m", "n", "r", "s", "sh", "t", "th", "v", "w", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm11[] = {"b", "br", "d", "dr", "dk", "g", "gr", "gh", "gl", "k", "kr", "l", "lk", "lgr", "ln", "lr", "lr", "m", "mk", "n", "nr", "nk", "nd", "ndr", "ng", "rg", "rv", "rk", "r", "rr", "rsh", "shk", "st", "sk", "sr", "sv", "svr", "tsk", "tk", "tr", "v", "xl", "xn", "z", "zr", "zk"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "ch", "d", "k", "ld", "lm", "m", "n", "r", "shky", "tsky", "v", "x", "z"};

    std::string nameLast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd10 = rng() % std::size(nm9);
    rnd11 = rng() % std::size(nm10);
    rnd12 = rng() % std::size(nm12);
    if (i % 3 == 0 && i % 2 != 0) {
    rnd13 = rng() % std::size(nm11);
    rnd14 = rng() % std::size(nm10);
    rnd15 = rng() % std::size(nm11);
    rnd16 = rng() % std::size(nm10);
    nameLast = nm9[rnd10] + nm10[rnd11] + nm11[rnd13] + nm10[rnd14] + nm11[rnd15] + nm10[rnd16] + nm12[rnd12];
    } else if (i % 2 == 0) {
    while (rnd10 < 5) {
    rnd10 = rng() % std::size(nm9);
    }
    while (rnd12 < 5) {
    rnd12 = rng() % std::size(nm12);
    }
    nameLast = nm9[rnd10] + nm10[rnd11] + nm12[rnd12];
    } else {
    rnd13 = rng() % std::size(nm11);
    rnd14 = rng() % std::size(nm10);
    nameLast = nm9[rnd10] + nm10[rnd11] + nm11[rnd13] + nm10[rnd14] + nm12[rnd12];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 8) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + " " + nameLast;
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm8[rnd5] + " " + nameLast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    while (rnd < 3) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 3) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + nameLast;
    } else if (i < 9) {
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
