#include "star_trek-trills_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_trills_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "b", "c", "d", "g", "gr", "h", "j", "k", "m", "n", "r", "s", "t", "v", "vr", "y"};
    static constexpr std::string_view nm2[] = {"ia", "aa", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"b", "d", "dr", "g", "hj", "j", "l", "m", "mbl", "n", "r", "rv", "rz", "rj"};
    static constexpr std::string_view nm4[] = {"", "d", "g", "l", "m", "n", "r", "ss"};
    static constexpr std::string_view nm5[] = {"", "b", "d", "g", "h", "j", "k", "l", "m", "n", "s", "r", "v", "y"};
    static constexpr std::string_view nm6[] = {"au", "ia", "ee", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm7[] = {"b", "dr", "dz", "l", "ll", "m", "n", "nh", "r", "s", "ss", "sr", "z", "zr"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "d", "h", "l", "ll", "m", "n", "s"};
    static constexpr std::string_view nm9[] = {"b", "d", "gr", "k", "l", "m", "n", "p", "pr", "r", "t", "v"};
    static constexpr std::string_view nm10[] = {"", "", "ee", "ia", "au", "aa", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm11[] = {"", "", "", "", "", "", "", "", "b", "d", "g", "gr", "gn", "l", "ll", "m", "n", "rr", "r", "s", "tn", "v", "z"};
    static constexpr std::string_view nm12[] = {"d", "g", "hn", "hl", "l", "m", "n", "r", "rs", "s", "x"};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    rnd6 = rng() % std::size(nm9);
    rnd7 = rng() % std::size(nm10);
    while (rnd7 < 2) {
    rnd7 = rng() % std::size(nm10);
    }
    rnd8 = rng() % std::size(nm11);
    rnd9 = rng() % std::size(nm10);
    if (rnd8 < 4) {
    while (rnd9 > 1) {
    rnd9 = rng() % std::size(nm10);
    }
    } else {
    while (rnd9 < 2) {
    rnd9 = rng() % std::size(nm10);
    }
    }
    rnd10 = rng() % std::size(nm12);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + " " + nm9[rnd6] + nm10[rnd7] + nm11[rnd8] + nm10[rnd9] + nm12[rnd10];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    if (rnd2 < 2) {
    while (rnd4 < 2) {
    rnd4 = rng() % std::size(nm2);
    }
    }
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm9);
    rnd7 = rng() % std::size(nm10);
    while (rnd7 < 2) {
    rnd7 = rng() % std::size(nm10);
    }
    rnd8 = rng() % std::size(nm11);
    rnd9 = rng() % std::size(nm10);
    if (rnd8 < 4) {
    while (rnd9 > 1) {
    rnd9 = rng() % std::size(nm10);
    }
    } else {
    while (rnd9 < 2) {
    rnd9 = rng() % std::size(nm10);
    }
    }
    rnd10 = rng() % std::size(nm12);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + nm9[rnd6] + nm10[rnd7] + nm11[rnd8] + nm10[rnd9] + nm12[rnd10];
    }
    return names;
    }
}
