#include "warhammer-lizardmens_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_lizardmens_name(std::mt19937& rng) {
    static constexpr std::string_view nm[] = {"c", "cr", "ch", "g", "h", "kr", "m", "n", "q", "qr", "t", "tl", "x", "xlt", "y", "z"};
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "c", "cr", "ch", "g", "h", "kr", "m", "n", "q", "qr", "t", "tl", "x", "xlt", "y", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "oa", "aui", "a'u", "o'e", "o'a", "u'a", "a'e", "e'a"};
    static constexpr std::string_view nm3[] = {"c", "cc", "ch", "cht", "chtl", "cn", "ct", "ctl", "d", "h", "hc", "hg", "hp", "ht", "htl", "htz", "k", "kt", "l", "lch", "lh", "ll", "lm", "ln", "lp", "lt", "lx", "m", "n", "nd", "nh", "nq", "nt", "ntl", "p", "q", "r", "szc", "t", "tl", "tt", "tz", "tzc", "tzp", "tzt", "x", "xc", "xch", "xt", "xtl", "xy", "y", "z", "zc", "zd", "zq", "ztl"};
    static constexpr std::string_view nm4[] = {"", "", "", "c", "ch", "cl", "k", "l", "n", "p", "r", "tl", "x"};
    static constexpr std::string_view nm5[] = {"c", "ch", "cl", "k", "l", "n", "p", "r", "tl", "x"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 3) {
    if (rnd < 5) {
    while (rnd5 < 3) {
    rnd5 = rng() % std::size(nm4);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    } else if (i < 6) {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5];
    } else if (i < 8) {
    rnd6 = rng() % std::size(nm);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "-" + nm[rnd6] + nm2[rnd7];
    } else {
    rnd = rng() % std::size(nm);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm);
    rnd7 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm5);
    names = nm[rnd] + nm2[rnd2] + nm5[rnd5] + "-" + nm[rnd6] + nm2[rnd7] + nm3[rnd3] + nm2[rnd4] + nm5[rnd8];
    }
    return names;
    }
}
