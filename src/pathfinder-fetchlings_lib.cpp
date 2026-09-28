#include "pathfinder-fetchlings_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_fetchlings_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "br", "dr", "gr", "j", "m", "n", "q", "qr", "r", "s", "tr", "x", "y", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"c", "d", "g", "h", "j", "k", "l", "m", "n", "r", "s", "t", "v", "z"};
    static constexpr std::string_view nm4[] = {"", "", "", "c", "h", "l", "m", "n", "r", "t", "x"};
    static constexpr std::string_view nm5[] = {"c", "f", "g", "h", "l", "m", "n", "q", "r", "s", "t", "th", "v", "y", "z"};
    static constexpr std::string_view nm7[] = {"c", "fz", "fn", "g", "gv", "gn", "gz", "h", "hn", "hv", "hz", "l", "lv", "lr", "ls", "lz", "m", "mr", "mv", "mz", "nv", "nz", "nr", "r", "rr", "rs", "rz", "rh", "rv", "sc", "sh", "sr", "sv", "th", "thr", "tv", "tn"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "h", "l", "m", "n", "s", "x"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm8);
    if (i < 6) {
    names = std::string(nm5[rnd]) + std::string(nm2[rnd2]) + std::string(nm7[rnd3]) + std::string(nm2[rnd4]) + std::string(nm8[rnd5]);
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm2);
    names = std::string(nm5[rnd]) + std::string(nm2[rnd2]) + std::string(nm7[rnd3]) + std::string(nm2[rnd4]) + std::string(nm7[rnd6]) + std::string(nm2[rnd7]) + std::string(nm8[rnd5]);
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (rnd < 3) {
    while (rnd5 < 3) {
    rnd5 = rng() % std::size(nm4);
    }
    }
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm4[rnd5]);
    }
    return names;
    }
}
