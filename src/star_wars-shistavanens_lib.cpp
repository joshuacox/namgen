#include "star_wars-shistavanens_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_shistavanens_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"b", "bl", "c", "d", "g", "h", "k", "l", "m", "n", "phl", "r", "s", "t", "v", "y"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "u", "o", "a", "a", "e", "i", "o", "u", "u", "o", "a", "oo", "aa", "uu"};
    static constexpr std::string_view nm3[] = {"cv", "cd", "dv", "dr", "d", "dd", "gv", "gr", "gg", "g", "gn", "k", "kk", "kv", "kl", "kr", "kt", "kd", "lv", "lr", "mr", "mv", "nv", "nr", "nd", "ndr", "nst", "r", "rd", "rt", "vr", "v", "vr", "vg", "vgr", "vd"};
    static constexpr std::string_view nm4[] = {"", "c", "d", "f", "gg", "k", "l", "m", "n", "q", "r", "s", "tt", "v", "z"};
    static constexpr std::string_view nm5[] = {"c", "d", "f", "g", "h", "k", "l", "m", "n", "r", "s", "sh", "t", "th", "v", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "ae", "ea", "ie"};
    static constexpr std::string_view nm8[] = {"c", "f", "ft", "l", "m", "n", "nn", "r", "s", "sh", "t", "v", "z"};
    static constexpr std::string_view nm9[] = {"b", "br", "c", "cr", "d", "dr", "dh", "f", "g", "gr", "k", "kr", "l", "m", "n", "r", "s", "sh", "shr", "s", "v", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "ie", "oa", "ae", "oo", "aa"};
    static constexpr std::string_view nm11[] = {"c", "d", "dr", "dv", "h", "hr", "hx", "hv", "kv", "kr", "kd", "n", "r", "rr", "v", "vr", "vg", "x", "z"};
    static constexpr std::string_view nm12[] = {"", "c", "d", "ft", "g", "k", "l", "m", "n", "nn", "p", "q", "r", "rr", "t", "v", "vl"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm12);
    if (i % 2 != 0) {
    while (rnd10 == 0) {
    rnd10 = rng() % std::size(nm12);
    }
    namelast = nm9[rnd7] + nm10[rnd8] + nm12[rnd10];
    } else {
    rnd9 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    namelast = nm9[rnd7] + nm10[rnd8] + nm11[rnd11] + nm10[rnd9] + nm12[rnd10];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd5] + "  " + namelast;
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 6) {
    while (rnd5 == 0) {
    rnd5 = rng() % std::size(nm4);
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
