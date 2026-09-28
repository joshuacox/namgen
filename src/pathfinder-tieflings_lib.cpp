#include "pathfinder-tieflings_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_tieflings_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "cr", "d", "g", "h", "k", "kr", "m", "r", "s", "sh", "t", "v", "y", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "ia", "io"};
    static constexpr std::string_view nm3[] = {"c", "cr", "cn", "d", "dr", "g", "gr", "gg", "k", "kr", "l", "ldr", "lv", "ll", "m", "nst", "nv", "nr", "r", "rn", "rd", "rk", "rrd", "rt", "rv", "s", "sr", "sk", "t", "tr", "v", "c", "d", "g", "k", "l", "m", "n", "r", "s", "t", "v"};
    static constexpr std::string_view nm4[] = {"", "", "", "c", "k", "n", "r", "s", "t", "th"};
    static constexpr std::string_view nm5[] = {"d", "f", "h", "k", "kh", "l", "m", "n", "r", "s", "sh", "str", "t", "th", "v", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "a", "a", "e", "a", "e", "i", "o", "a", "a", "e", "a", "o", "e", "a", "o", "e", "i", "i", "ei", "ia", "ea", "ai"};
    static constexpr std::string_view nm7[] = {"d", "dr", "f", "fr", "ff", "l", "ll", "ld", "ldr", "lr", "ln", "ls", "m", "mr", "mdr", "ms", "nd", "ndr", "nn", "n", "nz", "r", "rdr", "rr", "rs", "rz", "s", "sh", "sz", "sr", "t", "tr", "v", "vr", "y", "zs", "d", "f", "l", "m", "n", "r", "s", "t", "v", "y"};
    static constexpr std::string_view nm8[] = {"h", "l", "n", "s", "th"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "b", "br", "d", "dr", "f", "g", "h", "l", "m", "n", "p", "r", "s", "sh", "t", "v", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "a", "e", "i", "o", "a", "e", "i", "o", "a", "e", "i", "o", "a", "e", "i", "o", "a", "e", "i", "o", "a", "a", "e", "e", "i", "aa", "ae", "ia", "ea"};
    static constexpr std::string_view nm11[] = {"b", "br", "c", "d", "dr", "fr", "g", "gg", "gr", "gv", "k", "l", "ll", "lr", "lv", "ldr", "m", "mm", "mr", "mdr", "n", "nd", "ng", "ndr", "nst", "nv", "nr", "r", "rh", "rv", "rr", "rz", "rd", "rdr", "s", "ss", "sr", "sh", "st", "t", "tr", "v", "vr", "b", "c", "d", "g", "k", "l", "m", "n", "r", "s", "t", "v"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "", "", "", "", "", "d", "ld", "lt", "m", "n", "nd", "r", "rd", "s", "t", "th"};

    std::string lastName; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd8 = rng() % std::size(nm9);
    rnd9 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm11);
    rnd11 = rng() % std::size(nm10);
    rnd12 = rng() % std::size(nm12);
    if (i % 2 == 0) {
    lastName = nm9[rnd8] + nm10[rnd9] + nm11[rnd10] + nm10[rnd11] + nm12[rnd12];
    } else {
    rnd13 = rng() % std::size(nm11);
    rnd14 = rng() % std::size(nm10);
    lastName = nm9[rnd8] + nm10[rnd9] + nm11[rnd10] + nm10[rnd11] + nm11[rnd13] + nm10[rnd14] + nm12[rnd12];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 5) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + " " + lastName;
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm8[rnd5] + " " + lastName;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + lastName;
    } else {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + " " + lastName;
    }
    }
    return names;
    }
}
