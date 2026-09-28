#include "star_wars-nautolans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_nautolans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "br", "c", "d", "f", "h", "j", "k", "kh", "kn", "l", "m", "n", "p", "r", "rh", "rr", "s", "sh", "shr", "t", "v", "w", "y", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "oo", "ey", "ei", "ea", "ee", "aa"};
    static constexpr std::string_view nm3[] = {"ch", "d", "dd", "f", "fr", "k", "kt", "kx", "l", "m", "mr", "md", "mt", "n", "nd", "ng", "nn", "nt", "ntv", "nr", "ny", "pr", "r", "rk", "rr", "s", "shn", "sn", "sp", "spr", "th", "tr", "tv", "v", "w", "x", "z"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "c", "d", "f", "g", "k", "l", "m", "n", "ng", "nn", "r", "rr", "s", "t", "x"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "", "d", "dr", "dh", "f", "fr", "g", "gh", "h", "k", "kh", "l", "m", "n", "p", "r", "rh", "s", "sh", "th", "w", "y", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "y", "ea", "ee", "ai", "ie", "ia", "oo"};
    static constexpr std::string_view nm7[] = {"b", "c", "ch", "f", "ff", "h", "hl", "l", "ll", "lm", "ln", "lr", "m", "ml", "mm", "my", "n", "nn", "nl", "nd", "ny", "r", "rr", "s", "ss", "sh", "shn", "t", "th", "w", "y"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "f", "h", "l", "n", "s", "t"};
    static constexpr std::string_view nm9[] = {"", "", "", "b", "br", "d", "dr", "f", "g", "k", "l", "m", "n", "r", "rh", "s", "st", "t", "tr", "v", "vr", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "oa", "ai", "ia", "ii", "ie", "ee", "oo"};
    static constexpr std::string_view nm11[] = {"ch", "chm", "d", "dd", "dr", "dj", "g", "gg", "gr", "gd", "gn", "j", "k", "kt", "kk", "l", "m", "mm", "md", "mp", "n", "nd", "nn", "ng", "nr", "nt", "r", "rr", "rd", "rg", "rj", "rt", "rv", "st", "t", "tr", "wch", "z"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "", "", "c", "d", "g", "k", "l", "ll", "m", "mt", "n", "ng", "nd", "nt", "r", "rk", "rr", "s", "ss", "t", "ts", "z", "zz"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd5b = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm12);
    if (i % 3 == 0 && i % 2 != 0) {
    while (rnd7 < 3) {
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
    while (rnd < 7) {
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
    if (i < 3) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 5) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + namelast;
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + "  " + namelast;
    }
    }
    return names;
    }
}
