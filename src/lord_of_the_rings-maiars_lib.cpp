#include "lord_of_the_rings-maiars_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_lord_of_the_rings_maiars_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"f", "l", "m", "n", "ph", "s", "sh", "w", "y", "z", "", ""};
    static constexpr std::string_view nm2[] = {"a", "e", "o", "i", "u", "ó", "é", "ie", "ui", "ia", "ea", "ae", "ua"};
    static constexpr std::string_view nm3[] = {"l", "lm", "ln", "ls", "n", "nn", "ph", "r", "s", "sh", "ss", "th"};
    static constexpr std::string_view nm4[] = {"r", "n", "s", "th", "l", "m"};
    static constexpr std::string_view nm5[] = {"a", "e", "ë", "é", "ó", "", "", "", "", ""};
    static constexpr std::string_view nm6[] = {"c", "k", "l", "m", "n", "p", "r", "s", "t", "th", "", ""};
    static constexpr std::string_view nm7[] = {"a", "e", "o", "i", "u", "ó", "é", "ai", "eo", "io", "eö", "uo", "ua"};
    static constexpr std::string_view nm8[] = {"l", "ll", "lm", "ln", "ls", "m", "md", "n", "nd", "nm", "nw", "r", "s", "ss", "t", "w"};
    static constexpr std::string_view nm9[] = {"l", "m", "n", "nd", "r", "s", "t", "th"};
    static constexpr std::string_view nm10[] = {"o", "e", "ë", "ó", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    if (rnd2 > 6) {
    while (rnd4 > 6) {
    rnd4 = rng() % std::size(nm2);
    }
    }
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm5);
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm4[rnd5]) + std::string(nm5[rnd6]);
    } else {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm7);
    rnd3 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm7);
    if (rnd2 > 6) {
    while (rnd4 > 6) {
    rnd4 = rng() % std::size(nm7);
    }
    }
    rnd5 = rng() % std::size(nm9);
    rnd6 = rng() % std::size(nm10);
    names = std::string(nm6[rnd]) + std::string(nm7[rnd2]) + std::string(nm8[rnd3]) + std::string(nm7[rnd4]) + std::string(nm9[rnd5]) + std::string(nm10[rnd6]);
    }
    return names;
    }
}
