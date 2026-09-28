#include "legend_of_zelda-zoras_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_legend_of_zelda_zoras_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "h", "j", "k", "m", "n", "p", "t", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "i", "o", "e"};
    static constexpr std::string_view nm3[] = {"j", "k", "l", "p", "r", "t", "v"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "m", "n", "s", "r"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "l", "n", "r", "m", "h", "f"};
    static constexpr std::string_view nm6[] = {"a", "u", "o", "e"};
    static constexpr std::string_view nm7[] = {"r", "t", "l", "n", "r", "t", "l", "ph", "v", "m"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "n", "h"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm8);
    rnd5 = rng() % std::size(nm6);
    if (i < 5) {
    if (rnd < 4) {
    while (rnd4 < 6) {
    rnd4 = rng() % std::size(nm8);
    }
    }
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd5] + nm8[rnd4];
    } else {
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd5] + nm7[rnd7] + nm6[rnd6] + nm8[rnd4];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm2);
    if (i < 5) {
    if (rnd < 5) {
    while (rnd4 < 5) {
    rnd4 = rng() % std::size(nm4);
    }
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm4[rnd4];
    }
    return names;
    }
}
