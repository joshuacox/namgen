#include "star_trek-klingons_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_klingons_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"a", "o", "u", "e"};
    static constexpr std::string_view nm2[] = {"b", "d", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "ts", "th", "tr", "st", "sh", "gr", "ch", "kr", "kl", "dr"};
    static constexpr std::string_view nm3[] = {"a", "e", "i", "o", "u", "a", "o"};
    static constexpr std::string_view nm4[] = {"k", "k", "k", "m", "t", "r", "v", "g", "p", "n", "l", "d", "z", "b", "h", "m", "t", "r", "v", "g", "p", "n", "l", "d", "z", "b", "h", "r", "r", "r", "cl", "dm", "dr", "gh", "gr", "hl", "hm", "ll", "mp", "mt", "nk", "nm", "nt", "rg", "rk", "rl", "rn", "rp", "rr", "rt", "sk", "th", "tr", "wr", "yb"};
    static constexpr std::string_view nm5[] = {"k", "k", "m", "r", "k", "l", "n", "rgh", "ng", "x", "s", "n", "th", "hk", "hl", "d", "l", "c", "gh", "ss", "z", "ll", "rrd", "rd", "t", "q", "sh", "w", "rf"};
    static constexpr std::string_view nm6[] = {"o", "a", "i", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm7[] = {"'", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm8[] = {"", "Ch'", "D'", "H'", "J'", "K'", "L'", "T'", "W'", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm9[] = {"b", "d", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "ts", "th", "tr", "st", "sh", "gr", "ch", "kr", "kl", "dr"};
    static constexpr std::string_view nm10[] = {"d", "g", "h", "k", "l", "m", "n", "r", "t", "v", "x", "z", "lk", "nn", "tb", "hl", "rs", "ll", "lkr", "km", "dr", "rl", "lk", "lg", "rg", "sk", "th", "tr", "dm", "hm", "ng", "nk", "l", "n", "l", "n", "k"};
    static constexpr std::string_view nm11[] = {"r", "nn", "l", "h", "g", "n", "ss", "s", "yr", "st", "th", "j", "m", "v", "ll", "sh", "hl", "ng", "w"};
    static constexpr std::string_view nm12[] = {"o", "a", "i", "", "", "", "", "", ""};
    static constexpr std::string_view nm13[] = {"", "", "", "b", "c", "g'g", "d", "d'gh", "dr", "f", "g'", "g", "gr", "h", "j", "k'g", "k't", "k'mp", "k", "kh", "kl", "kr", "l", "m", "mn", "mr", "mv", "n", "ng", "p", "q", "r", "rr", "s", "sh", "t", "th", "tr", "v", "vr", "w", "x", "z"};
    static constexpr std::string_view nm14[] = {"c", "ct", "ck", "ch", "b", "d", "g", "gg", "ggr", "hn", "hnr", "k", "k'M", "ll", "lk", "lv", "lm", "lt", "mm", "mmr", "m", "mp", "mr", "nn", "nk", "nl", "nj", "nz", "ndl", "ns", "n", "nt", "r", "rr", "rs", "rmd", "rn", "rp", "rtr", "rst", "rt", "rg", "rm", "rd", "rsh", "ss", "str", "sht", "tzh", "v", "wr", "x", "yg", "z", "zh"};
    static constexpr std::string_view nm15[] = {"bh", "c", "ct", "ck", "cx", "ch", "d", "dh", "j", "g", "gh", "h", "k", "l", "lt", "m", "n", "nn", "ng", "r", "rc", "rr", "rgh", "rk", "rv", "rn", "rg", "sh", "sht", "s", "ss", "t", "th", "v", "x", "z", "zh"};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 4) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm9);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm11);
    rnd5 = rng() % std::size(nm12);
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm8);
    if (rnd6 == 0) {
    rnd7 = 0;
    }
    rnd8 = rng() % std::size(nm13);
    rnd9 = rng() % std::size(nm3);
    rnd10 = rng() % std::size(nm14);
    rnd11 = rng() % std::size(nm3);
    rnd12 = rng() % std::size(nm15);
    rnd13 = rng() % std::size(nm6);
    names = nm8[rnd7] + nm1[rnd] + nm9[rnd2] + nm7[rnd6] + nm3[rnd3] + nm11[rnd4] + nm12[rnd5] + " " + nm13[rnd8] + nm3[rnd9] + nm14[rnd10] + nm3[rnd11] + nm15[rnd12] + nm6[rnd13];
    } else if (i < 8) {
    rnd = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm10);
    rnd4 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm11);
    rnd6 = rng() % std::size(nm12);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    if (rnd7 == 0) {
    rnd8 = 0;
    }
    rnd9 = rng() % std::size(nm13);
    rnd10 = rng() % std::size(nm3);
    rnd13 = rng() % std::size(nm15);
    rnd12 = rng() % std::size(nm6);
    names = nm8[rnd8] + nm9[rnd] + nm3[rnd2] + nm10[rnd3] + nm7[rnd7] + nm3[rnd4] + nm11[rnd5] + nm12[rnd6] + " " + nm13[rnd9] + nm3[rnd10] + nm15[rnd13] + nm6[rnd12];
    } else {
    rnd = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm11);
    rnd4 = rng() % std::size(nm12);
    rnd5 = rng() % std::size(nm8);
    rnd8 = rng() % std::size(nm13);
    rnd9 = rng() % std::size(nm3);
    rnd10 = rng() % std::size(nm14);
    rnd11 = rng() % std::size(nm3);
    rnd12 = rng() % std::size(nm15);
    rnd13 = rng() % std::size(nm6);
    names = nm8[rnd5] + nm9[rnd] + nm3[rnd2] + nm11[rnd3] + nm12[rnd4] + " " + nm13[rnd8] + nm3[rnd9] + nm14[rnd10] + nm3[rnd11] + nm15[rnd12] + nm6[rnd13];
    }
    } else {
    if (i < 4) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm8);
    if (rnd6 == 0) {
    rnd7 = 0;
    }
    rnd8 = rng() % std::size(nm13);
    rnd9 = rng() % std::size(nm3);
    rnd10 = rng() % std::size(nm14);
    rnd11 = rng() % std::size(nm3);
    rnd12 = rng() % std::size(nm15);
    rnd13 = rng() % std::size(nm6);
    names = nm8[rnd7] + nm1[rnd] + nm2[rnd2] + nm7[rnd6] + nm3[rnd3] + nm5[rnd4] + nm6[rnd5] + " " + nm13[rnd8] + nm3[rnd9] + nm14[rnd10] + nm3[rnd11] + nm15[rnd12] + nm6[rnd13];
    } else if (i < 8) {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    if (rnd7 == 0) {
    rnd8 = 0;
    }
    rnd9 = rng() % std::size(nm13);
    rnd10 = rng() % std::size(nm3);
    rnd13 = rng() % std::size(nm15);
    rnd12 = rng() % std::size(nm6);
    names = nm8[rnd8] + nm2[rnd] + nm3[rnd2] + nm4[rnd3] + nm7[rnd7] + nm3[rnd4] + nm5[rnd5] + nm6[rnd6] + " " + nm13[rnd9] + nm3[rnd10] + nm15[rnd13] + nm6[rnd12];
    } else {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm5);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    rnd8 = rng() % std::size(nm13);
    rnd9 = rng() % std::size(nm3);
    rnd10 = rng() % std::size(nm14);
    rnd11 = rng() % std::size(nm3);
    rnd12 = rng() % std::size(nm15);
    rnd13 = rng() % std::size(nm6);
    names = nm8[rnd5] + nm2[rnd] + nm3[rnd2] + nm5[rnd3] + nm6[rnd4] + " " + nm13[rnd8] + nm3[rnd9] + nm14[rnd10] + nm3[rnd11] + nm15[rnd12] + nm6[rnd13];
    }
    }
    return names;
    }
}
