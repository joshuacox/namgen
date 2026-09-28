#include "doctor_who-zygons_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_doctor_who_zygons_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"B", "Br", "Cr", "D", "Dr", "G", "Gr", "K", "Kr", "R", "S", "Sr", "Str", "St", "T", "Tr", "V", "Vr"};
    static constexpr std::string_view nm2[] = {"e", "a", "o"};
    static constexpr std::string_view nm3[] = {"d", "g", "k", "l", "m", "n", "s", "t", "v", "w", "z"};
    static constexpr std::string_view nm4[] = {"l", "m", "n", "r", "rm", "rn", "s", "st"};

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
