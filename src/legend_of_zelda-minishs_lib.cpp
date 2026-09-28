#include "legend_of_zelda-minishs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_legend_of_zelda_minishs_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"B", "D", "F", "G", "H", "J", "K", "L", "M", "N", "P", "T"};
    static constexpr std::string_view nm2[] = {"e", "i", "o", "e", "i", "o", "a", "u"};
    static constexpr std::string_view nm3[] = {"b", "d", "f", "g", "k", "l", "m", "n", "p", "r", "s", "t"};
    static constexpr std::string_view nm4[] = {"ari", "tari", "rari"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4];
    return names;
    }
}
