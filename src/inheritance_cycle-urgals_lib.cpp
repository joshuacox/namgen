#include "inheritance_cycle-urgals_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_inheritance_cycle_urgals_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "b", "d", "g", "kh", "k", "r", "sk", "skg", "t", "y", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "o", "u"};
    static constexpr std::string_view nm3[] = {"b", "br", "bv", "bgr", "bdr", "d", "dv", "dz", "dzgr", "dgr", "gr", "gn", "gz", "hgr", "hr", "lk", "lv", "r", "rg", "rd", "rb", "rv", "rtv", "rzhv", "tv", "tr", "thb", "tz", "zg", "zb", "zr", "ztr", "zhgr"};
    static constexpr std::string_view nm4[] = {"c", "g", "k", "sz", "shz", "zh", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm4);
    if (i < 3) {
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd4];
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm4[rnd4];
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm3[rnd6] + nm2[rnd7] + nm4[rnd4];
    }
    return names;
    }
}
