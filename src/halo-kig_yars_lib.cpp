#include "halo-kig_yars_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_halo_kig_yars_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm2[] = {"b", "c", "d", "g", "j", "n", "k", "m", "r", "t", "th", "y", "z", "zh"};
    static constexpr std::string_view nm3[] = {"b", "c", "d", "g", "k", "m", "n", "p", "q", "r", "th", "x", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm3);
    names = nm2[rnd] + nm1[rnd2] + nm3[rnd3];
    } else {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm1);
    rnd6 = rng() % std::size(nm3);
    names = nm2[rnd] + nm1[rnd2] + nm3[rnd3] + " " + nm2[rnd4] + nm1[rnd5] + nm3[rnd6];
    }
    return names;
    }
}
