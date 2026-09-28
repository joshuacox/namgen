#include "star_trek-pakleds_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_pakleds_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"B", "D", "G", "H", "K", "L", "N", "M", "P", "R"};
    static constexpr std::string_view nm2[] = {"a", "e", "o", "i", "u"};
    static constexpr std::string_view nm3[] = {"b", "d", "g", "h", "k", "l", "n", "m", "p", "r"};
    static constexpr std::string_view nm4[] = {"b", "d", "g", "h", "k", "l", "n", "m", "p", "r", "", ""};
    static constexpr std::string_view nm5[] = {"b", "d", "g", "k", "l", "m", "p", "r", "gg", "kk", "ll", "rr"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    while (rnd4 == rnd3) {
    rnd4 = rng() % std::size(nm4);
    }
    rnd5 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm4);
    while (rnd6 == rnd7) {
    rnd7 = rng() % std::size(nm4);
    }
    rnd8 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm2[rnd5] + nm3[rnd6] + nm4[rnd7] + nm2[rnd8];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    while (rnd4 == rnd3) {
    rnd4 = rng() % std::size(nm4);
    }
    rnd5 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm4);
    while (rnd6 == rnd7) {
    rnd7 = rng() % std::size(nm4);
    }
    rnd8 = rng() % std::size(nm2);
    rnd9 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm2[rnd5] + nm3[rnd6] + nm4[rnd7] + nm2[rnd8] + nm5[rnd5];
    }
    return names;
    }
}
