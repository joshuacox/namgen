#include "star_wars-neimoidians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_neimoidians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "bl", "br", "c", "ch", "d", "dr", "f", "g", "gr", "h", "j", "k", "kl", "kr", "l", "m", "n", "p", "pr", "r", "s", "sm", "t", "th", "v", "y", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "i", "u", "i", "u", "u", "u", "ai", "au", "oo", "ee", "ui", "oa", "uu"};
    static constexpr std::string_view nm3[] = {"b", "bm", "d", "dm", "dml", "dr", "f", "g", "gr", "hv", "k", "kv", "l", "lf", "lv", "lr", "lt", "m", "md", "mv", "n", "nv", "nd", "ndd", "nj", "nr", "nt", "p", "r", "rg", "rl", "rr", "sh", "shr", "ss", "t", "th", "w", "z"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "b", "f", "gh", "hn", "k", "l", "lb", "ll", "n", "nd", "p", "ph", "r", "rs", "s", "sk", "t", "th", "tt", "v", "x", "y"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "b", "bl", "f", "h", "l", "m", "n", "p", "pl", "ph", "r", "s", "sh", "sn", "sm", "t", "th", "v", "y", "z"};
    static constexpr std::string_view nm6[] = {"a", "a", "e", "i", "o", "u", "i", "u", "a", "e", "i", "o", "u", "i", "u", "e", "i", "o", "u", "i", "u", "a", "e", "i", "o", "u", "i", "u", "uu", "ia", "ai", "ee", "ue", "ui"};
    static constexpr std::string_view nm7[] = {"d", "f", "ff", "fn", "g", "gg", "h", "hv", "l", "ll", "m", "mm", "mv", "md", "n", "nn", "nv", "nd", "ph", "s", "sh", "ss", "th", "r", "rr", "rh", "rv", "rl", "rs", "v", "w", "z"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "b", "f", "ff", "h", "l", "ll", "n", "ph", "rn", "s", "ss", "th", "y"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "b", "br", "c", "ch", "d", "dr", "dr", "f", "g", "gr", "k", "kr", "kh", "m", "n", "p", "pr", "pl", "r", "s", "sr", "sh", "t", "tr", "v", "z", "zr"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "i", "o", "a", "a", "e", "i", "o", "u", "i", "o", "a", "a", "e", "i", "o", "u", "i", "o", "a", "a", "e", "i", "o", "u", "i", "o", "a", "a", "e", "i", "o", "u", "i", "o", "a", "ii", "io", "ai", "ui", "iu", "ee"};
    static constexpr std::string_view nm11[] = {"f", "ff", "fr", "fd", "g", "gg", "gr", "gn", "gb", "k", "kk", "kv", "kr", "ll", "lv", "lr", "my", "m", "md", "mm", "mv", "mr", "n", "nn", "nv", "nd", "nk", "nkk", "rt", "tb", "tr", "th", "t", "tt", "tz", "tg", "tf"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "", "", "", "", "", "b", "d", "m", "n", "p", "r", "s", "t", "th", "y", "x"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm12);
    rnd9 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    namelast = nm9[rnd7] + nm10[rnd8] + nm11[rnd11] + nm10[rnd9] + nm12[rnd10];
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 5) {
    while (rnd < 4) {
    rnd = rng() % std::size(nm5);
    }
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 4) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 5) {
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
