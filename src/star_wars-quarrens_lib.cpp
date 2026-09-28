#include "star_wars-quarrens_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_quarrens_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "b", "c", "ch", "chr", "d", "dh", "f", "fr", "g", "gr", "j", "k", "kr", "l", "m", "n", "nr", "p", "ph", "pw", "q", "r", "s", "sh", "sq", "t", "th", "tr", "ts", "v", "w", "wh", "y", "z"};
    static constexpr std::string_view nm2[] = {"y", "y", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "au", "io", "oe", "ue", "ui", "ua", "ea"};
    static constexpr std::string_view nm3[] = {"b", "bk", "ck", "ct", "d", "dk", "dg", "dl", "dm", "dr", "g", "gg", "gk", "k", "kk", "l", "lb", "lg", "ll", "lm", "lp", "lw", "m", "mt", "n", "ndr", "nt", "p", "pp", "q", "r", "rgl", "rh", "rl", "rr", "rrh", "rth", "rz", "sq", "ss", "ssth", "st", "sth", "w"};
    static constexpr std::string_view nm4[] = {"", "", "", "d", "f", "g", "hlg", "k", "l", "lg", "mp", "n", "nn", "q", "r", "rg", "rgg", "rl", "rn", "rr", "rsk", "s", "sh", "sk", "t", "z"};
    static constexpr std::string_view nm5[] = {"", "", "", "b", "c", "ch", "d", "fr", "g", "gr", "j", "k", "kr", "l", "m", "n", "pr", "r", "pr", "sl", "sq", "sll", "t", "th", "tr", "ts", "v", "w", "y", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "i", "o", "u", "a", "e", "i", "o", "u", "au", "ee", "aa"};
    static constexpr std::string_view nm7[] = {"bn", "br", "c", "ck", "cp", "cm", "dk", "dm", "g", "gg", "hl", "k", "kk", "kr", "km", "l", "lb", "lp", "lg", "lm", "nm", "n", "nn", "nd", "nr", "nt", "p", "pp", "q", "r", "rk", "rr", "rt", "rh", "rz", "s", "ss", "st", "sm", "sq", "t", "v", "w", "wm"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "d", "dd", "ff", "g", "k", "l", "lg", "ll", "ls", "m", "n", "nk", "nx", "q", "r", "rg", "rn", "rv", "s", "sk", "t", "z"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm5);
    rnd8 = rng() % std::size(nm6);
    rnd10 = rng() % std::size(nm8);
    if (i % 2 == 0) {
    while (rnd7 < 3) {
    rnd7 = rng() % std::size(nm5);
    }
    namelast = nm5[rnd7] + nm6[rnd8] + nm8[rnd10];
    } else {
    rnd9 = rng() % std::size(nm6);
    rnd11 = rng() % std::size(nm7);
    namelast = nm5[rnd7] + nm6[rnd8] + nm7[rnd11] + nm6[rnd9] + nm8[rnd10];
    }
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm4);
    if (i < 5) {
    while (rnd < 3) {
    rnd = rng() % std::size(nm1);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd3] + "  " + namelast;
    } else {
    rnd4 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd4] + nm2[rnd5] + nm4[rnd3] + "  " + namelast;
    }
    return names;
    }
}
