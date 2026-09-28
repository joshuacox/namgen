#include "star_wars-gands_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_gands_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "c", "c'n", "d", "d'k", "k", "l", "n", "r'k", "r", "s", "s'z", "t", "t'r", "v", "v'l", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "y", "aa", "oo", "uu", "ee", "ay", "ai", "ey", "ya", "yu", "yi"};
    static constexpr std::string_view nm3[] = {"b", "ck", "d", "dn", "ff", "fn", "fl", "g", "gn", "gl", "k", "kk", "kn", "kl", "l", "ll", "ln", "ls", "ld", "nl", "nf", "q", "r", "rn", "rl", "s", "ss", "sl", "ssl", "t", "z", "zl"};
    static constexpr std::string_view nm4[] = {"", "d", "k", "l", "n", "r", "sh", "ss", "x"};
    static constexpr std::string_view nm5[] = {"cr", "cn", "d", "dr", "k", "kr", "l", "n", "p", "pr", "pn", "q", "qr", "sr", "shr", "tr", "v", "vr", "z"};
    static constexpr std::string_view nm6[] = {"ck", "cl", "d", "ff", "fr", "gg", "gl", "k", "kk", "kr", "q", "ql", "qr", "rr", "rn", "rl", "sl", "th", "t", "tr", "z", "zz", "zl"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "", "", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "aa", "oo", "uu", "ee", "ay", "ai", "ey", "ya", "yu", "yi"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm5);
    rnd7 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm6);
    rnd9 = rng() % std::size(nm7);
    namelast = nm5[rnd6] + nm2[rnd7] + nm6[rnd8] + nm7[rnd9];
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm4);
    if (i < 5) {
    while (rnd4 < 2) {
    rnd4 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd4] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm4[rnd4] + "  " + namelast;
    }
    return names;
    }
}
