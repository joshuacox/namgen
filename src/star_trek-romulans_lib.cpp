#include "star_trek-romulans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_romulans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"b", "ch", "c", "d", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "th", "v", "vr", "x", "", ""};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"b", "c", "chr", "j", "k", "l", "j", "k", "l", "lm", "ld", "m", "m", "ns", "nd", "ncl", "r", "r", "rr", "t", "t", "v"};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u", "ai", "ee", "iu"};
    static constexpr std::string_view nm5[] = {"", "b", "hk", "k", "l", "m", "n", "r", "s", "t", "th", "x"};
    static constexpr std::string_view nm6[] = {"", "a", "e", "o", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm7[] = {"b", "c", "d", "h", "k", "l", "m", "n", "p", "r", "s", "t", "th", "v"};
    static constexpr std::string_view nm8[] = {"h", "k", "l", "ll", "m", "n", "r", "rr", "t", "tr", "th", "v"};
    static constexpr std::string_view nm9[] = {"a", "e", "i", "o", "u", "au", "ee"};
    static constexpr std::string_view nm10[] = {"", "k", "l", "m", "n", "s", "th"};
    static constexpr std::string_view nm11[] = {"", "a", "a"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm7);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm9);
    rnd5 = rng() % std::size(nm10);
    rnd6 = rng() % std::size(nm11);
    if (rnd5 == 0) {
    rnd6 = 0;
    }
    names = nm7[rnd] + nm2[rnd2] + nm8[rnd3] + nm9[rnd4] + nm10[rnd5] + nm11[rnd6];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    if (rnd5 == 0) {
    rnd6 = 0;
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm6[rnd6];
    }
    return names;
    }
}
