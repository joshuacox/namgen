#include "star_trek-letheans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_letheans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"b", "c", "d", "g", "j", "k", "l", "m", "n", "q", "r", "s", "t", "tr", "v", "z", "", ""};
    static constexpr std::string_view nm2[] = {"oi", "ao", "ui", "ei", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"b", "c", "d", "g", "j", "k", "l", "m", "n", "p", "q", "r", "t", "v", "z", "b", "bb", "bt", "cz", "c", "d", "dl", "dz", "g", "gr", "j", "k", "kz", "kl", "kr", "l", "lt", "lv", "m", "nj", "nb", "n", "nth", "p", "q", "qr", "r", "rr", "rrn", "rn", "t", "tt", "v", "vv", "z", "zz", "ztr", "zm"};
    static constexpr std::string_view nm4[] = {"b", "c", "d", "f", "g", "k", "m", "nt", "n", "p", "q", "r", "sz", "t", "v", "z", "", ""};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm4);
    if (rnd2 < 4) {
    while (rnd4 < 4) {
    rnd4 = rng() % std::size(nm2);
    }
    while (rnd6 < 4) {
    rnd6 = rng() % std::size(nm2);
    }
    }
    if (rnd4 < 4) {
    while (rnd6 < 4) {
    rnd6 = rng() % std::size(nm2);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd5] + nm2[rnd6] + nm4[rnd7];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (rnd2 < 4) {
    while (rnd4 < 4) {
    rnd4 = rng() % std::size(nm2);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    }
    return names;
    }
}
