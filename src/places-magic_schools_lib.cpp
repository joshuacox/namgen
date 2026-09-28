#include "places-magic_schools_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_magic_schools_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"a", "e", "i", "o", "u", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view names2[] = {"b", "d", "k", "l", "m", "n", "p", "r", "s", "t", "b", "d", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "br", "dr", "gr", "kr", "pr", "str", "tr", "bl", "cl", "fl", "gl", "kl", "pl", "sl"};
    static constexpr std::string_view names3[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ae", "ea", "ou", "au", "a", "e", "o"};
    static constexpr std::string_view names4[] = {"d", "f", "g", "k", "l", "m", "n", "p", "r", "s", "t", "x"};
    static constexpr std::string_view names5[] = {"w", "n", "s", "m", "r", "", "", "", "", "", "", ""};
    static constexpr std::string_view names6[] = {"any", "arry", "arth", "arths", "arts", "elts", "erra", "erry", "erth", "eth", "iams", "ia", "iara", "ine", "inns", "iths", "iton", "ity", "onia", "ons", "ora", "ore", "orth", "orths", "ose", "yce"};
    static constexpr std::string_view names7[] = {"Academy of Sorcery", "Academy of Spells", "Academy of Magics", "Academy of Witchcraft", "Academy of Wizardry", "Academy of the Arcane", "Institute of Magics", "Institute of Wizardy", "Institute of the Arcane", "School of Magics", "School of Sorcery", "School of Witchcraft", "School of Wizardry", "School of Wizards", "School of the Arcane"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    rnd4 = rng() % std::size(names4);
    rnd5 = rng() % std::size(names5);
    rnd6 = rng() % std::size(names6);
    rnd7 = rng() % std::size(names7);
    if (i < 5) {
    names = names1[rnd] + names2[rnd2] + names3[rnd3] + names4[rnd4] + names5[rnd5] + names6[rnd6];
    } else {
    names = names1[rnd] + names2[rnd2] + names3[rnd3] + names4[rnd4] + names5[rnd5] + names6[rnd6] + ", " + names7[rnd7];
    }
    return names;
    }
}
