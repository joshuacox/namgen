#include "pathfinder-tengus_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_tengus_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "ch", "gr", "j", "k", "kr", "p", "pr", "q", "qr", "r", "s", "t", "tr", "tch", "x", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "o", "u", "a", "e", "o", "u", "a", "e", "o", "u", "a", "e", "o", "u", "i", "i", "a", "e", "o", "u", "au", "ai", "oi", "ou"};
    static constexpr std::string_view nm3[] = {"ch", "j", "k", "kk", "l", "ll", "m", "n", "nn", "p", "pp", "q", "r", "rr", "s", "t", "v", "y", "x", "z", "zz"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "", "", "", "ck", "gh", "k", "l", "n", "r"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "ch", "d", "g", "gh", "k", "kh", "m", "n", "p", "q", "r", "s", "sh", "t", "th", "v", "z", "zh"};
    static constexpr std::string_view nm6[] = {"a", "e", "o", "u", "a", "e", "o", "u", "a", "e", "o", "u", "a", "e", "o", "u", "i", "i", "a", "e", "o", "u", "ai", "io", "ee", "ae"};
    static constexpr std::string_view nm7[] = {"b", "ch", "g", "j", "k", "ky", "lk", "l", "ll", "ly", "m", "mk", "nk", "ny", "p", "py", "r", "rr", "rk", "s", "t", "ty", "tch", "v", "vy", "z", "zz"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "k", "l", "n", "r"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "b", "ch", "d", "g", "j", "k", "kr", "m", "n", "p", "pr", "q", "r", "s", "t", "tch", "v", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "o", "e", "a", "o", "e", "u"};
    static constexpr std::string_view nm11[] = {"ch", "g", "j", "k", "kk", "ky", "l", "ll", "m", "n", "ng", "nk", "p", "pp", "q", "r", "rr", "s", "t", "tch", "v", "y", "z", "zz"};
    static constexpr std::string_view nm12[] = {"", "", "ck", "k", "l", "n", "r", "t"};

    std::string lastName; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd8 = rng() % std::size(nm9);
    rnd9 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm11);
    rnd11 = rng() % std::size(nm10);
    rnd12 = rng() % std::size(nm12);
    lastName = nm9[rnd8] + nm10[rnd9] + nm11[rnd10] + nm10[rnd11] + nm12[rnd12];
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 3) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm5);
    }
    while (rnd5 < 10) {
    rnd5 = rng() % std::size(nm8);
    }
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd5] + " " + lastName;
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + " " + lastName;
    } else {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm8[rnd5] + " " + lastName;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 3) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 10) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + " " + lastName;
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + lastName;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + " " + lastName;
    }
    }
    return names;
    }
}
