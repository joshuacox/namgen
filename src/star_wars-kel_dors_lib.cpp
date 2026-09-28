#include "star_wars-kel_dors_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_kel_dors_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "ch", "d", "gn", "h", "j", "k", "n", "p", "pl", "r", "s", "sh", "t", "tr", "v", "w", "x", "y", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "o", "y", "a", "e", "i", "o", "u", "a", "o", "y", "a", "o", "a", "e", "i", "o", "u", "a", "o", "y", "a", "e", "i", "o", "u", "a", "o", "y", "a", "o", "ee", "aa", "oo", "ia", "ea"};
    static constexpr std::string_view nm3[] = {"'r", "c", "c'", "chk", "h", "'h", "k", "'k", "kr", "l'", "ll", "ls", "r", "r'", "rr", "rv", "'s", "s", "st", "tch", "t'", "tchk", "z", "z'", "'z"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "l", "ln", "lt", "m", "n", "r", "rn", "rs", "rss", "s", "ss", "st"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "bh", "ch", "dh", "dr", "gh", "g", "h", "kr", "m", "n", "p", "r", "s", "sh", "t", "th", "y", "v", "w"};
    static constexpr std::string_view nm6[] = {"a", "i", "u", "a", "i", "a", "i", "u", "e", "a", "i", "o", "ee"};
    static constexpr std::string_view nm7[] = {"'c", "ch", "h", "'h", "k", "kh", "'k", "'l", "l", "q", "'q", "qr", "r", "'r", "rr", "rz", "st", "s'", "sz", "th", "t'", "'z"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "l", "m", "n", "s", "th"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "b", "br", "ch", "d", "dr", "g", "h", "k", "m", "n", "p", "r", "s", "sh", "t", "tl", "v", "y", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "a", "e", "i", "o", "u", "a", "a", "e", "i", "o", "u", "a", "a", "e", "i", "o", "u", "a", "a", "e", "i", "o", "u", "a", "ii", "ai", "oo", "aa", "uu"};
    static constexpr std::string_view nm11[] = {"c", "ch", "g", "hr", "k", "kr", "l", "lr", "mn", "n", "nd", "r", "rr", "rv", "s", "sz", "st", "t", "tch", "z"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "", "", "", "c", "k", "l", "ln", "mm", "n", "ng", "r", "s", "ss", "w", "zz"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd5b = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm12);
    if (i % 3 == 0 && i % 2 != 0) {
    while (rnd7 < 5) {
    rnd7 = rng() % std::size(nm9);
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
    while (rnd < 4) {
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
    if (i < 5) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    }
    }
    return names;
    }
}
