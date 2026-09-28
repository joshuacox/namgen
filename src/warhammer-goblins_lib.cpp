#include "warhammer-goblins_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_goblins_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"c", "ch", "cr", "g", "gh", "gr", "gn", "k", "kr", "kn", "r", "sk", "sc", "sm", "sn", "st", "str", "skr", "t", "tr", "z", "zr"};
    static constexpr std::string_view nm2[] = {"a", "i", "o", "a", "i", "o", "a", "i", "o", "e", "u"};
    static constexpr std::string_view nm3[] = {"c", "cc", "cl", "cr", "cn", "gl", "gr", "gn", "gg", "g", "gd", "gdr", "gs", "gt", "gtr", "k", "kk", "kt", "kr", "ktr", "ks", "kz", "kv", "ng", "nz", "nr", "nk", "nkz", "nks", "rc", "rk", "rg", "rgr", "rkr", "rs", "rsn", "rsm", "rz", "rt", "rtr", "rsl", "sn", "str", "sk", "sc", "str", "skr", "sz", "tr", "tkr", "tn", "tv", "vr", "vl"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "c", "k", "n", "m", "mm", "r", "rr", "rk", "s", "sk", "sz", "x", "z"};
    static constexpr std::string_view nm5[] = {"c", "ch", "d", "g", "gh", "k", "kh", "r", "sr", "sc", "sk", "sn", "sl", "t", "th", "tr", "v", "x", "z"};
    static constexpr std::string_view nm6[] = {"i", "a", "i", "a", "i", "a", "i", "a", "e", "e", "e", "o", "u"};
    static constexpr std::string_view nm7[] = {"c", "ch", "cc", "g", "gg", "gr", "gtr", "gn", "gz", "k", "kr", "kz", "kt", "l", "ll", "lc", "lk", "lz", "lg", "n", "nn", "nr", "nt", "nk", "r", "rr", "rl", "rk", "rn", "rm", "t", "tt", "th", "tr", "tz", "tzr", "tsr", "tg", "v", "vr", "z", "zr", "zz", "zg", "zk", "zn"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    if (i < 4) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4];
    } else {
    rnd5 = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd5] + nm6[rnd6];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 4) {
    while (rnd5 < 4) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5];
    } else {
    rnd4 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    }
    }
    return names;
    }
}
