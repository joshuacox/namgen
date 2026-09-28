#include "halo-jiralhanaes_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_halo_jiralhanaes_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"b", "br", "c", "cr", "d", "dr", "f", "g", "gr", "h", "k", "kr", "l", "m", "n", "p", "pr", "r", "s", "t", "tr", "v", "w", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "y", "u", "i", "o"};
    static constexpr std::string_view nm3[] = {"bb", "cc", "ck", "ct", "dd", "gt", "kk", "kt", "ll", "rb", "rc", "rd", "rg", "rk", "rl", "rm", "rn", "rp", "rr", "rs", "rt", "rv", "rz", "ss", "st", "b", "c", "d", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "z"};
    static constexpr std::string_view nm4[] = {"bb", "cc", "ck", "ct", "dd", "gt", "kk", "kt", "ll", "rb", "rc", "rd", "rg", "rk", "rl", "rm", "rn", "rp", "rr", "rs", "rt", "rv", "rz", "ss", "st", "b", "c", "d", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "z", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm5[] = {"us", "um", "eus", "eum", "ion", "ius", "is"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (rnd3 < 25) {
    while (rnd5 < 25) {
    rnd5 = rng() % std::size(nm4);
    }
    }
    rnd6 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + nm5[rnd6];
    return names;
    }
}
