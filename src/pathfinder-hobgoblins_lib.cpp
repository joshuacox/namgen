#include "pathfinder-hobgoblins_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_hobgoblins_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "b", "d", "dr", "f", "g", "gr", "h", "k", "kr", "m", "n", "p", "pr", "r", "s", "t", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"d", "dr", "gl", "gr", "gt", "gh", "kr", "kt", "kh", "kl", "l", "lgr", "lt", "ld", "ldr", "lg", "lb", "lbr", "ll", "r", "rg", "rd", "rt", "rdr", "rgr", "rk", "rl", "th", "tt", "tr", "thr", "vl", "vr", "vt"};
    static constexpr std::string_view nm4[] = {"", "d", "g", "k", "m", "n", "ng", "r", "t"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "b", "c", "d", "f", "h", "k", "m", "n", "ph", "r", "s", "t", "v", "w", "z"};
    static constexpr std::string_view nm7[] = {"cl", "cn", "cm", "cd", "f", "ff", "fn", "fm", "fl", "kl", "kr", "kn", "km", "kd", "kt", "ks", "l", "lz", "ln", "lm", "ld", "lg", "m", "mz", "ms", "mr", "md", "mg", "mk", "n", "ns", "nd", "nr", "ng", "ns", "nk", "r", "rm", "rg", "rn", "rd", "rk", "s", "sm", "st", "ss", "sz", "sm", "sn", "sd", "sg", "th", "tr", "tn", "tz", "ts", "yd", "yn", "yg", "yk", "yr", "yz"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "f", "h", "l", "m", "n", "s", "t"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm8);
    if (i < 8) {
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
    while (rnd5 == 0) {
    rnd5 = rng() % std::size(nm4);
    }
    }
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm4[rnd5]);
    }
    return names;
    }
}
