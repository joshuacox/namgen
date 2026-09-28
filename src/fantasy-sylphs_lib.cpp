#include "fantasy-sylphs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_sylphs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"c", "ch", "l", "m", "n", "ph", "s", "th", "v", "w", "y"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ae", "ea", "ei", "ia", "ie", "ue", "ua", "aei", "aea", "eae"};
    static constexpr std::string_view nm3[] = {"bh", "c", "ch", "h", "y", "hl", "hm", "hy", "l", "lm", "ln", "ls", "lt", "lth", "lv", "ll", "m", "mm", "mn", "mh", "ms", "mth", "n", "nh", "nn", "nl", "nt", "ns", "nth", "nv", "nf", "nm", "nh", "nhr", "ph", "phr", "r", "rd", "rph", "rs", "rth", "rh", "rn", "rm", "rv", "ss", "sn", "sh", "st", "t", "th", "thr", "v", "w"};
    static constexpr std::string_view nm4[] = {"f", "l", "m", "n", "s", "th", "f", "ff", "h", "l", "m", "n", "ph", "s", "sh", "th", "y"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "dh", "f", "h", "l", "m", "n", "ph", "s", "sh", "th", "w", "y"};
    static constexpr std::string_view nm6[] = {"c", "h", "y", "hl", "hn", "hm", "hsh", "hph", "hy", "hth", "ht", "l", "ll", "lsh", "lf", "ln", "lph", "ls", "lth", "m", "mn", "mh", "ms", "n", "nh", "nl", "nsh", "nt", "ns", "nth", "nph", "nf", "nm", "nh", "nhr", "ph", "phn", "phl", "r", "rd", "rph", "rsh", "rs", "rth", "rh", "rn", "rm", "ss", "sn", "shn", "sh", "st", "sht", "t", "th", "thr", "v", "w"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "f", "ff", "h", "l", "m", "n", "ph", "s", "sh", "y", "f", "ff", "h", "ph", "s", "sh", "y"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "c", "dh", "f", "h", "l", "m", "n", "ph", "s", "sh", "th", "v", "w", "y"};
    static constexpr std::string_view nm9[] = {"ch", "h", "hl", "hn", "hm", "hsh", "hph", "ht", "hth", "l", "lsh", "lf", "lm", "ln", "lph", "ls", "lt", "lth", "lv", "m", "mm", "mn", "mh", "ms", "msh", "mth", "mf", "n", "nh", "nl", "nsh", "nt", "ns", "nth", "nph", "nv", "nf", "nm", "nh", "nhr", "ph", "phr", "phn", "phl", "r", "rd", "rph", "rsh", "rs", "rth", "rh", "rn", "rm", "ss", "sn", "shn", "sh", "st", "sht", "t", "th", "thr", "v", "w", "y"};
    static constexpr std::string_view nm10[] = {"f", "ff", "h", "l", "m", "n", "ph", "s", "sh", "th", "y"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm2);
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd3 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm7);
    if (i < 5) {
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3] + nm2[rnd4] + nm7[rnd5];
    } else if (i < 8) {
    rnd6 = rng() % std::size(nm2);
    while (rnd5 < 4) {
    rnd5 = rng() % std::size(nm7);
    }
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3] + nm2[rnd4] + nm7[rnd5] + nm2[rnd6];
    } else {
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm6);
    rnd8 = rng() % std::size(nm2);
    names = nm2[rnd2] + nm6[rnd3] + nm2[rnd4] + nm6[rnd7] + nm2[rnd8] + nm7[rnd5] + nm2[rnd6];
    while (names.length() > 10) {
    rnd = rng() % std::size(nm5);
    rnd3 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm2);
    names = nm8[rnd] + nm2[rnd2] + nm9[rnd3] + nm2[rnd6] + nm9[rnd7] + nm2[rnd4] + nm10[rnd5];
    }
    }
    } else if (type == 2) {
    rnd = rng() % std::size(nm8);
    rnd3 = rng() % std::size(nm9);
    rnd5 = rng() % std::size(nm10);
    if (i < 7) {
    names = nm8[rnd] + nm2[rnd2] + nm9[rnd3] + nm2[rnd4] + nm10[rnd5];
    } else {
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm9);
    names = nm8[rnd] + nm2[rnd2] + nm9[rnd3] + nm2[rnd6] + nm9[rnd7] + nm2[rnd4] + nm10[rnd5];
    while (names.length() > 10) {
    rnd = rng() % std::size(nm8);
    rnd3 = rng() % std::size(nm9);
    rnd5 = rng() % std::size(nm10);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm2);
    names = nm8[rnd] + nm2[rnd2] + nm9[rnd3] + nm2[rnd6] + nm9[rnd7] + nm2[rnd4] + nm10[rnd5];
    }
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm4);
    if (i < 7) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    } else {
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm3);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd6] + nm3[rnd7] + nm2[rnd4] + nm4[rnd5];
    while (names.length() > 10) {
    rnd = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm2);
    names = nm8[rnd] + nm2[rnd2] + nm9[rnd3] + nm2[rnd6] + nm9[rnd7] + nm2[rnd4] + nm10[rnd5];
    }
    }
    }
    return names;
    }
}
