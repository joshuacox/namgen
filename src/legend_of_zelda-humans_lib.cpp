#include "legend_of_zelda-humans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_legend_of_zelda_humans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "a", "e", "i", "o", "u", "i", "a", "e"};
    static constexpr std::string_view nm2[] = {"b", "c", "d", "j", "k", "l", "m", "n", "r", "t", "z"};
    static constexpr std::string_view nm3[] = {"a", "i", "o", "u", "a", "o"};
    static constexpr std::string_view nm4[] = {"b", "g", "k", "l", "m", "ng", "r", "rr", "ss", "t", "z"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "h", "k", "l", "ll", "lph", "m", "n", "nk", "s"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o"};
    static constexpr std::string_view nm7[] = {"c", "f", "h", "m", "n", "ph", "r", "s", "sh", "th", "t"};
    static constexpr std::string_view nm8[] = {"f", "l", "m", "mb", "n", "p", "ph", "tr", "ld", "r", "s", "sh", "v"};
    static constexpr std::string_view nm9[] = {"a", "e", "i", "o", "ia", "ei", "ie", "ea", "a", "e", "i"};
    static constexpr std::string_view nm10[] = {"", "", "", "", "", "", "l", "m", "n", "s", "sh", "th"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm7);
    rnd5 = rng() % std::size(nm9);
    rnd6 = rng() % std::size(nm10);
    if (i < 5) {
    rnd4 = rng() % std::size(nm8);
    names = nm7[rnd2] + nm6[rnd] + nm8[rnd4] + nm9[rnd5] + nm10[rnd6];
    } else {
    names = nm6[rnd] + nm7[rnd2] + nm9[rnd5] + nm10[rnd6];
    }
    } else {
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm5);
    if (i < 5) {
    rnd4 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm3);
    names = nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm3[rnd6] + nm5[rnd5];
    } else {
    rnd = rng() % std::size(nm1);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm5[rnd5];
    }
    }
    return names;
    }
}
