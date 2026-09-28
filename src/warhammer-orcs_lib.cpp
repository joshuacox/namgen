#include "warhammer-orcs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_orcs_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "b", "br", "cr", "d", "dr", "g", "gr", "j", "k", "kr", "m", "n", "r", "v", "w", "z"};
    static constexpr std::string_view nm2[] = {"a", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"dg", "dz", "dr", "g", "gd", "gg", "gh", "gk", "gr", "gz", "hg", "hz", "hzr", "hrz", "hr", "k", "kd", "kg", "kz", "kr", "l", "ld", "lz", "lr", "ldr", "lgr", "m", "mg", "mh", "mgr", "mz", "mzr", "mdr", "md", "nd", "ndr", "nz", "nzr", "ng", "r", "rb", "rrz", "rg", "rgh", "rz", "rzr", "rk", "rl", "t", "tg", "tk", "tr", "tgr", "tz", "tzr", "z", "zh", "zn"};
    static constexpr std::string_view nm4[] = {"c", "d", "g", "k", "r", "t", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    return names;
    }
}
