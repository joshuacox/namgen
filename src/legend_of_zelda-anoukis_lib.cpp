#include "legend_of_zelda-anoukis_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_legend_of_zelda_anoukis_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "b", "d", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "w", "y", "z"};
    static constexpr std::string_view nm2[] = {"a", "u", "o", "e"};
    static constexpr std::string_view nm3[] = {"u", "o", "u", "o", "u", "o", "oo"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm1);
    while (rnd4 < 4) {
    rnd4 = rng() % std::size(nm1);
    }
    names = nm1[rnd] + nm2[rnd2] + nm1[rnd4] + nm3[rnd3];
    return names;
    }
}
