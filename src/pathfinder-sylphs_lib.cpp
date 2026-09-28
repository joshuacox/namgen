#include "pathfinder-sylphs_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_sylphs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "c", "d", "f", "g", "h", "j", "l", "m", "n", "s", "v", "w", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "u", "a", "e", "i", "u", "a", "e", "i", "u", "a", "e", "i", "u", "a", "e", "i", "u", "aa", "uu", "ii"};
    static constexpr std::string_view nm3[] = {"d", "f", "g", "j", "k", "l", "m", "n", "s", "v", "w", "z"};
    static constexpr std::string_view nm4[] = {"d", "l", "m", "n", "sh"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "d", "f", "h", "k", "l", "m", "n", "r", "s", "t", "v", "w", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "a", "a", "ee", "aa"};
    static constexpr std::string_view nm7[] = {"d", "f", "ff", "h", "l", "ll", "m", "mm", "n", "nn", "s", "ss", "v", "y", "w"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "h", "m", "n", "sh"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    if (i < 5) {
    rnd5 = rng() % std::size(nm8);
    names = std::string(nm5[rnd]) + std::string(nm6[rnd2]) + std::string(nm7[rnd3]) + std::string(nm6[rnd4]) + std::string(nm8[rnd5]);
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = std::string(nm5[rnd]) + std::string(nm6[rnd2]) + std::string(nm7[rnd3]) + std::string(nm6[rnd4]) + std::string(nm7[rnd6]) + std::string(nm6[rnd7]);
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm4[rnd5]);
    }
    return names;
    }
}
