#include "fantasy-cavemens_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_cavemens_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "br", "bh", "cr", "d", "dr", "dh", "fr", "g", "gr", "gn", "gh", "j", "kr", "kh", "n", "r", "t", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "a", "o", "o", "o", "ou", "oo", "aa", "oe", "ua", "uu", "ia"};
    static constexpr std::string_view nm3[] = {"cr", "cc", "ch", "d", "dd", "dr", "dh", "dv", "g", "gg", "gr", "gn", "gv", "gz", "k", "kn", "kz", "kv", "kk", "l", "ll", "lr", "lk", "mg", "mk", "n", "ng", "nk", "nd", "nr", "rg", "rd", "rb", "rl", "rr", "rz", "rv", "rk", "sk", "sg", "sv", "t", "tk", "tz", "tt", "v", "vv", "vr", "vk", "vd", "z", "zz", "zk", "zd", "zc", "zg"};
    static constexpr std::string_view nm4[] = {"", "", "b", "c", "d", "g", "h", "k", "kk", "lk", "ll", "n", "r", "rc", "rk", "rv", "t"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "b", "bh", "c", "ch", "d", "dh", "f", "fl", "gh", "gn", "h", "j", "jh", "l", "m", "n", "r", "s", "sc", "sk", "sn", "st", "t", "th", "tr", "ts", "v", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "a", "e", "i", "o", "u", "a", "e", "i", "o", "a", "e", "i", "o", "u", "a", "e", "i", "o", "a", "e", "i", "o", "u", "a", "e", "i", "o", "a", "e", "o", "aa", "ae", "ai", "ee", "oe", "ua"};
    static constexpr std::string_view nm7[] = {"b", "b", "d", "d", "g", "g", "k", "k", "l", "l", "n", "n", "r", "r", "s", "s", "t", "t", "z", "z", "b", "b", "d", "d", "g", "g", "k", "k", "l", "l", "n", "n", "r", "r", "s", "s", "t", "t", "z", "z", "b", "br", "bh", "bn", "bb", "ch", "cn", "cl", "cr", "d", "dd", "dn", "dl", "fr", "fn", "fl", "g", "gg", "gl", "gn", "gr", "gy", "k", "kk", "ky", "kl", "kn", "km", "l", "ll", "lg", "ly", "ln", "lm", "lv", "mg", "ml", "n", "nn", "ng", "nk", "nd", "nz", "r", "rr", "rb", "rl", "rt", "rth", "s", "sz", "sr", "st", "sh", "ss", "t", "ty", "yl", "yr", "yn", "yg", "yr", "vr", "vn", "vl", "vk", "z", "zh", "zn"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "h", "l", "n", "s"};
    static constexpr std::string_view nm9[] = {"", "", "", "br", "bh", "cr", "d", "dr", "dh", "fr", "g", "gr", "gn", "gh", "j", "kr", "kh", "n", "r", "t", "v", "z", "", "", "", "", "", "b", "bh", "c", "ch", "d", "dh", "f", "fl", "gh", "gn", "h", "j", "jh", "l", "m", "n", "r", "s", "sc", "sk", "sn", "st", "t", "th", "tr", "ts", "v", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "a", "o", "o", "o", "ou", "oo", "aa", "oe", "ua", "uu", "ia", "a", "e", "i", "o", "u", "a", "e", "i", "o", "a", "e", "i", "o", "u", "a", "e", "i", "o", "a", "e", "i", "o", "u", "a", "e", "i", "o", "a", "e", "i", "o", "u", "a", "e", "i", "o", "a", "e", "o", "aa", "ae", "ai", "ee", "oe", "ua"};
    static constexpr std::string_view nm11[] = {"b", "b", "d", "d", "g", "g", "k", "k", "l", "l", "n", "n", "r", "r", "s", "s", "t", "t", "z", "z", "b", "br", "bh", "bn", "bb", "ch", "cn", "cl", "cr", "d", "dd", "dn", "dl", "fr", "fn", "fl", "g", "gg", "gl", "gn", "gr", "gy", "k", "kk", "ky", "kl", "kn", "km", "l", "ll", "lg", "ly", "ln", "lm", "lv", "mg", "ml", "n", "nn", "ng", "nk", "nd", "nz", "r", "rr", "rb", "rl", "rt", "rth", "s", "sz", "sr", "st", "sh", "ss", "t", "ty", "yl", "yr", "yn", "yg", "yr", "vr", "vn", "vl", "vk", "z", "zh", "zn", "cr", "cc", "ch", "d", "dd", "dr", "dh", "dv", "g", "gg", "gr", "gn", "gv", "gz", "k", "kn", "kz", "kv", "kk", "l", "ll", "lr", "lk", "mg", "mk", "n", "ng", "nk", "nd", "nr", "rg", "rd", "rb", "rl", "rr", "rz", "rv", "rk", "sk", "sg", "sv", "t", "tk", "tz", "tt", "v", "vv", "vr", "vk", "vd", "z", "zz", "zk", "zd", "zc", "zg"};
    static constexpr std::string_view nm12[] = {"", "", "b", "c", "d", "g", "h", "k", "kk", "lk", "ll", "n", "r", "t", "", "", "", "", "h", "l", "n", "s"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5];
    } else if (type == 2) {
    rnd = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm10);
    rnd3 = rng() % std::size(nm11);
    rnd4 = rng() % std::size(nm10);
    rnd5 = rng() % std::size(nm12);
    names = nm9[rnd] + nm10[rnd2] + nm11[rnd3] + nm10[rnd4] + nm12[rnd5];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    while (rnd < 3) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 2) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5];
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    }
    }
    return names;
    }
}
