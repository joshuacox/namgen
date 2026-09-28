#include "star_trek-nausicaans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_nausicaans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "b", "ch", "d", "dg", "gh", "g", "gr", "h", "j", "k", "kl", "lh", "l", "m", "n", "p", "r", "s", "sh", "st", "t", "th", "tl", "tr", "v", "x", "y", "z"};
    static constexpr std::string_view nm2[] = {"ae", "ee", "ei", "ou", "uu", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"bz", "ch", "d", "g", "ggr", "gv", "h", "j", "jh", "l", "lth", "lrsh", "k", "kz", "kkz", "ktz", "m", "mmk", "n", "p", "r", "rt", "rg", "rc", "sh", "th", "t", "tz", "v", "y", "yk", "z", "zj", "zzg", "d", "g", "h", "j", "l", "k", "m", "n", "p", "r", "t", "v", "y", "z"};
    static constexpr std::string_view nm4[] = {"", "", "c", "chk", "rdz", "g", "jz", "k", "m", "n", "ng", "p", "r", "rr", "rrg", "sh", "t", "th", "tz", "tkz", "x", "z"};
    static constexpr std::string_view nm5[] = {"c", "chk", "rdz", "g", "jz", "k", "m", "n", "ng", "p", "r", "rr", "rrg", "sh", "t", "th", "tz", "tkz", "x", "z"};
    static constexpr std::string_view nm6[] = {"", "", "", "a", "e", "i", "o", "u"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (rnd2 < 5) {
    while (rnd4 < 5) {
    rnd4 = rng() % std::size(nm2);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm5[rnd3];
    }
    return names;
    }
}
