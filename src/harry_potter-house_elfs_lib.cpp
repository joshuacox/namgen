#include "harry_potter-house_elfs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_harry_potter_house_elfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"B", "C", "D", "F", "G", "H", "J", "K", "L", "M", "N", "P", "R", "S", "T", "V", "W", "Z"};
    static constexpr std::string_view nm2[] = {"oo", "a", "o"};
    static constexpr std::string_view nm3[] = {"", "d", "n", "r", "l", "b", "k"};
    static constexpr std::string_view nm4[] = {"b", "d", "k", "p", "r"};
    static constexpr std::string_view nm5[] = {"y", "ey"};
    static constexpr std::string_view nm6[] = {"ee", "i", "o"};
    static constexpr std::string_view nm7[] = {"", "n", "s", "l", "b", "m", "p"};
    static constexpr std::string_view nm8[] = {"k", "n", "s", "l", "m", "p"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    if (rnd2 == 0) {
    rnd3 = 0;
    } else {
    while (rnd3 == 0) {
    rnd3 = rng() % std::size(nm7);
    }
    }
    rnd4 = rng() % std::size(nm8);
    rnd5 = rng() % std::size(nm5);
    names = nm1[rnd] + nm6[rnd2] + nm7[rnd3] + nm8[rnd4] + nm5[rnd5];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    if (rnd2 == 0) {
    rnd3 = 0;
    } else {
    while (rnd3 == 0) {
    rnd3 = rng() % std::size(nm3);
    }
    }
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5];
    }
    return names;
    }
}
