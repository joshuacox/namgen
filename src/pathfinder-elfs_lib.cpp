#include "pathfinder-elfs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_elfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "c", "d", "f", "g", "h", "k", "kr", "l", "m", "n", "s", "t", "th", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "o", "o", "e", "e", "ae", "ia", "ie", "ea", "ei", "io"};
    static constexpr std::string_view nm3[] = {"ch", "cl", "cv", "dr", "dv", "g", "g", "g", "gl", "gr", "ghr", "ght", "h", "h", "h", "j", "j", "l", "l", "l", "l", "l", "l", "lm", "ln", "ldr", "lvr", "ld", "ldl", "ll", "ls", "lth", "lv", "m", "m", "m", "m", "mr", "mv", "n", "n", "n", "n", "nr", "nv", "nvr", "nth", "nd", "ndl", "ndr", "nl", "r", "r", "r", "r", "r", "rl", "rgr", "rg", "rd", "rdl", "rdr", "s", "s", "s", "s", "sh", "shn", "st", "sv", "sr", "sth", "t", "t", "t", "th", "th", "v", "v", "v", "vr", "y", "y", "y"};
    static constexpr std::string_view nm4[] = {"", "l", "m", "n", "r", "s", "ss", "l", "m", "n", "r", "s", "ss"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "d", "f", "h", "j", "k", "l", "m", "n", "ph", "s", "sh", "t", "th", "v", "y"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "o", "o", "e", "e", "ie", "ia", "ea", "au", "aa", "ao", "eae", "ou", "ae"};
    static constexpr std::string_view nm7[] = {"c", "c", "c", "cl", "cn", "cm", "d", "d", "d", "dr", "dn", "dm", "g", "g", "g", "gn", "gh", "gy", "h", "h", "h", "h", "hh", "hh", "hn", "hl", "hr", "l", "l", "l", "l", "l", "ll", "ll", "lm", "ln", "lhr", "lhn", "lv", "ls", "lsh", "ly", "ll", "m", "m", "m", "m", "mm", "mm", "mh", "mn", "mr", "n", "n", "n", "nn", "nn", "nd", "ndl", "ndr", "nn", "nr", "nth", "ns", "nl", "nh", "ny", "r", "r", "r", "rr", "rr", "rdl", "rl", "rn", "rv", "rs", "s", "s", "s", "ss", "ss", "sh", "shr", "sl", "th", "v", "v", "v", "y", "y", "y"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "", "h", "l", "n", "s", "ss"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "c", "d", "f", "g", "gr", "h", "j", "k", "l", "m", "n", "s", "sh", "t", "th", "v", "w", "y", "z", "zh"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "e", "e", "o", "o", "ai", "ee", "ei", "ia", "ie", "ae", "io"};
    static constexpr std::string_view nm11[] = {"cl", "d", "d", "d", "dn", "dr", "g", "g", "g", "gh", "gl", "gr", "h", "h", "h", "hh", "j", "k", "k", "k", "l", "l", "l", "l", "l", "ll", "ll", "ll", "ld", "ldl", "ldr", "lf", "lhn", "lhr", "ll", "llm", "llv", "lm", "ln", "ls", "lv", "lvr", "m", "m", "m", "mm", "mm", "mn", "mr", "mv", "n", "n", "n", "nn", "n", "nd", "ndl", "ndr", "nl", "nn", "nr", "ns", "nth", "nv", "ph", "r", "r", "r", "rr", "rd", "rdl", "rg", "rl", "rm", "rr", "s", "s", "s", "ss", "ss", "sh", "sl", "ss", "st", "th", "tl", "v", "v", "v", "y", "y", "y"};
    static constexpr std::string_view nm12[] = {"", "", "h", "l", "m", "n", "r", "s"};

    std::string nameLast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

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
    while (rnd12 < 2) {
    rnd12 = rng() % std::size(nm12);
    }
    nameLast = nm9[rnd10] + nm10[rnd11] + nm12[rnd12];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 4) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + " " + nameLast;
    } else if (i < 8) {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm8[rnd5] + " " + nameLast;
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    rnd8 = rng() % std::size(nm7);
    rnd9 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm7[rnd8] + nm6[rnd9] + nm8[rnd5] + " " + nameLast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 3) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 == 0) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + nameLast;
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + nameLast;
    } else if (i < 9) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + " " + nameLast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm3);
    rnd9 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm3[rnd8] + nm2[rnd9] + nm4[rnd5] + " " + nameLast;
    }
    }
    return names;
    }
}
