#include "star_wars_the_old_republic-twileks_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_the_old_republic_twileks_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"i", "a", "o", "e", "u", "y", "aa", "ai", "ao", "ae", "au", "ia", "io", "ie", "iu", "oi", "oa", "oo", "oe", "ou", "ui", "ua", "uu", "uo", "ue", "i", "a", "o", "e", "u", "i", "a", "o", "e", "u", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"b", "c", "cr", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "sr", "t", "v", "w", "z"};
    static constexpr std::string_view nm3[] = {"i", "a", "o", "e", "u"};
    static constexpr std::string_view nm4[] = {"b", "c", "d", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "w", "z"};
    static constexpr std::string_view nm5[] = {"'", "", ""};
    static constexpr std::string_view nm6[] = {"b", "c", "cr", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "z"};
    static constexpr std::string_view nm7[] = {"c", "d", "f", "g", "k", "l", "m", "n", "q", "r", "s", "t", "w", "y", "z", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm8[] = {"i", "a", "o", "e", "u", "aa", "ai", "ao", "ae", "au", "ia", "io", "ie", "iu", "oi", "oa", "oo", "oe", "ou", "ui", "ua", "uu", "uo", "ue", "i", "a", "o", "e", "u", "i", "a", "o", "e", "u", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm9[] = {"b", "c", "ch", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "sh", "t", "v", "w", "y", "y", "y", "z"};
    static constexpr std::string_view nm10[] = {"c", "f", "g", "h", "l", "m", "n", "p", "r", "s", "t", "w", "y", "z", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm3);
    rnd8 = rng() % std::size(nm6);
    rnd9 = rng() % std::size(nm3);
    if (type == 1) {
    rnd = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm10);
    names = nm8[rnd] + nm9[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm6[rnd6] + nm3[rnd7] + nm6[rnd8] + nm3[rnd9] + nm10[rnd10];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd10 = rng() % std::size(nm7);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm6[rnd6] + nm3[rnd7] + nm6[rnd8] + nm3[rnd9] + nm7[rnd10];
    }
    return names;
    }
}
