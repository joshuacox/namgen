#include "star_wars-toydarians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_toydarians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "br", "d", "dr", "f", "g", "gl", "k", "l", "m", "n", "p", "q", "r", "t", "v", "w", "z", "zl"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "oo", "ua", "uu", "ue", "ey", "oy"};
    static constexpr std::string_view nm3[] = {"b", "bb", "d", "dd", "f", "g", "gg", "ll", "m", "mg", "mr", "mt", "n", "ng", "nd", "nk", "nm", "pp", "r", "rg", "rd", "rf", "rp", "rr", "rt", "ssc", "ss", "sg", "sc", "st", "t", "tt", "tw"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "", "b", "bb", "d", "g", "l", "lg", "m", "n"};
    static constexpr std::string_view nm5[] = {"b", "d", "f", "g", "k", "l", "m", "n", "q", "r", "s", "t", "v", "w", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm7[] = {"b", "bb", "bl", "d", "dl", "f", "ff", "fl", "fn", "fm", "ffl", "g", "gg", "gl", "gm", "gn", "l", "ll", "lb", "ld", "lt", "m", "mt", "md", "n", "nt", "nl", "p", "pp", "r", "rr", "rg", "rl", "rt", "rz", "rb", "s", "ss", "sg", "st", "sl", "sb", "tt", "t", "tl", "tr", "v", "z"};
    static constexpr std::string_view nm9[] = {"b", "d", "f", "g", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "aa", "uu", "oo"};
    static constexpr std::string_view nm11[] = {"b", "bb", "d", "g", "l", "lg", "m", "n"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    if (i % 2 != 0) {
    rnd9 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm7);
    namelast = nm9[rnd7] + nm10[rnd8] + nm7[rnd10] + nm10[rnd9];
    } else {
    rnd9 = rng() % std::size(nm11);
    namelast = nm9[rnd7] + nm10[rnd8] + nm11[rnd9];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    if (i < 5) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + "  " + namelast;
    } else {
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd5] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 4) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 8) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + namelast;
    } else if (i < 8) {
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
