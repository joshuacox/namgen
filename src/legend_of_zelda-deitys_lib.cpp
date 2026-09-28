#include "legend_of_zelda-deitys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_legend_of_zelda_deitys_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "b", "c", "d", "j", "k", "l", "m", "n", "r", "t", "v", "z"};
    static constexpr std::string_view nm2[] = {"y", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"b", "br", "cl", "d", "g", "gr", "gn", "h", "k", "kr", "l", "ld", "ll", "ln", "lm", "m", "mn", "n", "ph", "r", "v", "vr", "z", "zr", "b", "d", "h", "k", "l", "m", "n", "r", "v", "z", "b", "d", "h", "k", "l", "m", "n", "r", "v", "z"};
    static constexpr std::string_view nm4[] = {"u", "oo", "ia", "a", "e", "ai", "i", "o"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "n", "m", "r", "s"};
    static constexpr std::string_view nm6[] = {"b", "c", "d", "f", "h", "l", "n", "m", "ph", "s", "sh", "t", "v"};
    static constexpr std::string_view nm7[] = {"a", "e", "o", "i", "y", "ay", "ie", "ia", "ea"};
    static constexpr std::string_view nm8[] = {"h", "l", "m", "n", "ph", "r", "rd", "s", "th", "v", "r"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "n", "h"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm7);
    rnd3 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm7);
    if (rnd2 > 4) {
    while (rnd4 > 4) {
    rnd4 = rng() % std::size(nm7);
    }
    }
    rnd5 = rng() % std::size(nm9);
    if (i < 5) {
    names = nm6[rnd] + nm7[rnd2] + nm8[rnd3] + nm7[rnd4] + nm9[rnd5];
    } else {
    rnd6 = rng() % std::size(nm7);
    if (rnd2 > 4 || rnd4 > 4) {
    while (rnd6 > 4) {
    rnd6 = rng() % std::size(nm7);
    }
    }
    rnd7 = rng() % std::size(nm8);
    names = nm6[rnd] + nm7[rnd2] + nm8[rnd3] + nm7[rnd6] + nm8[rnd7] + nm7[rnd4] + nm9[rnd5];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5];
    } else {
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm3);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd6] + nm3[rnd7] + nm4[rnd4] + nm5[rnd5];
    }
    }
    return names;
    }
}
