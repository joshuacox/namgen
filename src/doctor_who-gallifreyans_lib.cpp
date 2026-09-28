#include "doctor_who-gallifreyans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_doctor_who_gallifreyans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "c", "ch", "d", "dr", "f", "g", "gl", "gr", "h", "j", "k", "l", "m", "n", "p", "pr", "q", "r", "s", "st", "t", "th", "tr", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ia"};
    static constexpr std::string_view nm3[] = {"bl", "br", "bj", "d", "ff", "g", "gn", "gr", "kk", "kl", "kr", "lj", "l", "lg", "ll", "lr", "lm", "ly", "lp", "m", "mr", "md", "mt", "nd", "ndr", "nc", "ng", "nn", "ns", "nt", "nz", "p", "pp", "r", "rn", "rb", "rt", "rl", "rkh", "rv", "sb", "sm", "sp", "ss", "sk", "t", "th", "tth", "v", "vl", "vr", "w", "wtr", "x", "xr", "xt", "zm"};
    static constexpr std::string_view nm4[] = {"c", "d", "f", "k", "l", "ld", "ll", "n", "nd", "r", "rg", "s", "sh", "th", "t", "w", "x"};
    static constexpr std::string_view nm5[] = {"br", "dr", "g", "gr", "gl", "k", "kl", "kr", "m", "n", "p", "r", "s", "t", "tr", "v", "z"};
    static constexpr std::string_view nm6[] = {"br", "cr", "ctr", "dr", "dd", "d", "gr", "gl", "gg", "g", "l", "ll", "lgr", "lsr", "lbr", "lk", "ldr", "m", "mr", "ms", "n", "ng", "ngr", "nt", "ntr", "ndr", "p", "pr", "phr", "r", "rd", "rth", "s", "sk", "str", "sr", "v", "vr"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "d", "l", "ll", "m", "m", "n", "nn", "s", "ss", "st", "th", "tkh"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "c", "ch", "cl", "d", "dh", "dr", "f", "gl", "h", "j", "kh", "kr", "l", "m", "n", "p", "ph", "pr", "q", "r", "s", "sh", "sc", "t", "th", "v", "z"};
    static constexpr std::string_view nm9[] = {"br", "d", "ff", "gn", "gl", "hr", "hn", "k", "kr", "l", "ll", "ly", "lm", "ln", "lph", "lt", "lr", "m", "mn", "mm", "n", "nn", "nd", "ns", "nt", "nz", "ndr", "nt", "p", "pp", "pr", "r", "rr", "ry", "rl", "rs", "rk", "sf", "sm", "sn", "sh", "sp", "st", "tth", "th", "v", "vy", "vr", "y"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "ia", "oie", "ea"};
    static constexpr std::string_view nm11[] = {"br", "bl", "dv", "dh", "dr", "f", "ff", "gl", "gr", "h", "l", "lm", "ln", "m", "n", "pr", "ph", "q", "r", "rr", "rl", "s", "st", "sr", "sh", "th", "tr", "x"};
    static constexpr std::string_view nm12[] = {"bv", "ch", "c", "dr", "d", "dd", "dv", "gr", "gl", "gg", "g", "nm", "hn", "h", "l", "ll", "lm", "lt", "ls", "lz", "m", "mm", "mr", "nd", "ng", "nt", "ns", "nl", "nph", "p", "pp", "ph", "phr", "q", "r", "rh", "rl", "rm", "st", "sv", "str", "tr", "th", "v"};
    static constexpr std::string_view nm13[] = {"", "", "", "", "", "d", "l", "ll", "m", "m", "n", "nn", "r", "s", "ss", "sh", "th"};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 4) {
    rnd = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm9);
    rnd4 = rng() % std::size(nm10);
    rnd5 = rng() % std::size(nm11);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm12);
    rnd8 = rng() % std::size(nm2);
    rnd9 = rng() % std::size(nm12);
    rnd10 = rng() % std::size(nm2);
    rnd11 = rng() % std::size(nm13);
    names = nm8[rnd] + nm2[rnd2] + nm9[rnd3] + nm10[rnd4] + nm11[rnd5] + nm2[rnd6] + nm12[rnd7] + nm2[rnd8] + nm12[rnd9] + nm2[rnd10] + nm13[rnd11];
    } else if (i < 7) {
    rnd = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm9);
    rnd4 = rng() % std::size(nm10);
    rnd5 = rng() % std::size(nm11);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm12);
    rnd8 = rng() % std::size(nm2);
    rnd9 = rng() % std::size(nm12);
    rnd10 = rng() % std::size(nm2);
    rnd11 = rng() % std::size(nm12);
    rnd12 = rng() % std::size(nm2);
    rnd13 = rng() % std::size(nm13);
    names = nm8[rnd] + nm2[rnd2] + nm9[rnd3] + nm10[rnd4] + nm11[rnd5] + nm2[rnd6] + nm12[rnd7] + nm2[rnd8] + nm12[rnd9] + nm2[rnd10] + nm12[rnd11] + nm2[rnd12] + nm13[rnd13];
    } else {
    rnd = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm9);
    rnd4 = rng() % std::size(nm10);
    rnd5 = rng() % std::size(nm11);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm12);
    rnd8 = rng() % std::size(nm2);
    rnd9 = rng() % std::size(nm12);
    rnd10 = rng() % std::size(nm2);
    rnd11 = rng() % std::size(nm12);
    rnd12 = rng() % std::size(nm2);
    rnd13 = rng() % std::size(nm12);
    rnd14 = rng() % std::size(nm2);
    rnd15 = rng() % std::size(nm13);
    names = nm8[rnd] + nm2[rnd2] + nm9[rnd3] + nm10[rnd4] + nm11[rnd5] + nm2[rnd6] + nm12[rnd7] + nm2[rnd8] + nm12[rnd9] + nm2[rnd10] + nm12[rnd11] + nm2[rnd12] + nm12[rnd13] + nm2[rnd14] + nm13[rnd15];
    }
    } else {
    if (i < 4) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm5);
    rnd8 = rng() % std::size(nm2);
    rnd9 = rng() % std::size(nm6);
    rnd10 = rng() % std::size(nm2);
    rnd11 = rng() % std::size(nm7);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + nm2[rnd6] + nm5[rnd7] + nm2[rnd8] + nm6[rnd9] + nm2[rnd10] + nm7[rnd11];
    } else if (i < 7) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm5);
    rnd8 = rng() % std::size(nm2);
    rnd9 = rng() % std::size(nm6);
    rnd10 = rng() % std::size(nm2);
    rnd11 = rng() % std::size(nm6);
    rnd12 = rng() % std::size(nm2);
    rnd13 = rng() % std::size(nm7);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + nm2[rnd6] + nm5[rnd7] + nm2[rnd8] + nm6[rnd9] + nm2[rnd10] + nm6[rnd11] + nm2[rnd12] + nm7[rnd13];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm5);
    rnd8 = rng() % std::size(nm2);
    rnd9 = rng() % std::size(nm6);
    rnd10 = rng() % std::size(nm2);
    rnd11 = rng() % std::size(nm6);
    rnd12 = rng() % std::size(nm2);
    rnd13 = rng() % std::size(nm6);
    rnd14 = rng() % std::size(nm2);
    rnd15 = rng() % std::size(nm7);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + nm2[rnd6] + nm5[rnd7] + nm2[rnd8] + nm6[rnd9] + nm2[rnd10] + nm6[rnd11] + nm2[rnd12] + nm6[rnd13] + nm2[rnd14] + nm7[rnd15];
    }
    }
    return names;
    }
}
