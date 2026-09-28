#include "halo-unggoys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_halo_unggoys_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"a", "i", "u"};
    static constexpr std::string_view nm2[] = {"d", "f", "k", "l", "m", "s", "w", "p", "y", "z"};
    static constexpr std::string_view nm3[] = {"fl", "kl", "sl", "sm", "pl", "zl", "d", "f", "k", "l", "m", "s", "w", "p", "y", "z"};
    static constexpr std::string_view nm4[] = {"fl", "kl", "sl", "sm", "pl", "zl"};

    std::string names; size_t rnd = 0; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm2);
    names = nm2[rnd] + nm1[rnd2] + nm2[rnd3] + nm1[rnd2] + nm2[rnd4];
    } else if (i < 7) {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm1);
    rnd1 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    if (rnd < 6) {
    while (rnd3 < 6) {
    rnd3 = rng() % std::size(nm3);
    }
    }
    rnd4 = rng() % std::size(nm1);
    rnd5 = rng() % std::size(nm2);
    names = nm3[rnd] + nm1[rnd2] + nm2[rnd1] + nm3[rnd3] + nm1[rnd4] + nm2[rnd5];
    } else {
    rnd = rng() % std::size(nm4);
    rnd2 = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm2);
    names = nm4[rnd] + nm1[rnd2] + nm2[rnd3];
    }
    return names;
    }
}
