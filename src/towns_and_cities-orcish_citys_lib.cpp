#include "towns_and_cities-orcish_citys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_towns_and_cities_orcish_citys_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "br", "bh", "ch", "d", "dr", "dh", "g", "gr", "gh", "k", "kr", "kh", "l", "m", "n", "q", "r", "v", "z", "vr", "zr"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "o", "u"};
    static constexpr std::string_view nm3[] = {"b", "cc", "d", "dd", "gg", "g", "r", "rr", "z", "zz", "b", "cc", "d", "dd", "gg", "g", "r", "rr", "z", "zz", "br", "cr", "dr", "dg", "dz", "dgr", "dk", "gr", "gh", "gk", "gz", "gm", "gn", "gv", "lb", "lg", "lgr", "ldr", "lbr", "lk", "lz", "mm", "rg", "rm", "rdr", "rbr", "rd", "rk", "rkr", "rgr", "rz", "shb", "shn", "zg", "zgr", "zd", "zr", "zdr"};
    static constexpr std::string_view nm4[] = {"", "kh", "d", "dh", "g", "gh", "l", "n", "r", "rd", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 2) {
    rnd6 = rng() % std::size(nm1);
    rnd7 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm4);
    if (rnd < 5) {
    while (rnd5 == 0) {
    rnd5 = rng() % std::size(nm4);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + nm1[rnd6] + nm2[rnd4] + nm3[rnd3] + nm2[rnd7] + nm4[rnd8];
    } else if (i < 6) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    } else if (i < 8) {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd6] + nm2[rnd7] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    } else {
    rnd6 = rng() % std::size(nm1);
    rnd7 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm4);
    if (rnd < 5) {
    while (rnd5 == 0) {
    rnd5 = rng() % std::size(nm4);
    }
    }
    names = nm1[rnd6] + nm2[rnd4] + nm3[rnd3] + nm2[rnd7] + nm4[rnd8] + "  " + nm1[rnd] + nm2[rnd2] + nm4[rnd5];
    }
    return names;
    }
}
