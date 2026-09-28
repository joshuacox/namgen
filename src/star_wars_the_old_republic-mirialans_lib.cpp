#include "star_wars_the_old_republic-mirialans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_the_old_republic_mirialans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"i", "a", "o", "e", "u", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"b", "c", "ch", "d", "f", "fl", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "sh", "t", "v", "v", "w", "y", "z", "z"};
    static constexpr std::string_view nm3[] = {"i", "a", "o", "e", "u"};
    static constexpr std::string_view nm4[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "v", "w", "y", "z", "z"};
    static constexpr std::string_view nm5[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "v", "w", "y", "z", "z", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm6[] = {"i", "a", "o", "e", "u", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm7[] = {"b", "c", "ch", "d", "f", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "sh", "t", "v", "v", "w", "y", "z", "z", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm8[] = {"b", "c", "ch", "d", "f", "fl", "g", "h", "i", "j", "k", "l", "m", "n", "p", "q", "r", "s", "sh", "t", "v", "w", "y", "z"};
    static constexpr std::string_view nm9[] = {"b", "c", "ch", "d", "f", "g", "h", "i", "k", "l", "m", "n", "p", "q", "r", "s", "sh", "t", "v", "v", "w", "y", "z", "z", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm10[] = {"i", "a", "o", "e", "u", "", ""};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    if (type == 1) {
    rnd2 = rng() % std::size(nm8);
    rnd9 = rng() % std::size(nm10);
    rnd7 = rng() % std::size(nm9);
    names = nm1[rnd] + nm8[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm6[rnd6] + nm9[rnd7] + nm10[rnd9];
    } else {
    rnd2 = rng() % std::size(nm2);
    rnd9 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm6[rnd6] + nm7[rnd7] + nm6[rnd9];
    }
    return names;
    }
}
