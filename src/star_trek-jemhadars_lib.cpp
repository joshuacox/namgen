#include "star_trek-jemhadars_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_jemhadars_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"a", "i", "o", "", "", ""};
    static constexpr std::string_view nm2[] = {"d", "g", "k", "l", "m", "n", "r", "s", "t", "v", "y", "z"};
    static constexpr std::string_view nm3[] = {"a", "u", "o", "i", "e", "a"};
    static constexpr std::string_view nm4[] = {"d", "g", "k", "l", "m", "n", "r", "s", "t", "z"};
    static constexpr std::string_view nm5[] = {"", "", "d", "g", "k", "n", "t"};
    static constexpr std::string_view nm6[] = {"a", "", "", "", ""};
    static constexpr std::string_view nm7[] = {"i", "a", "e", "o", "u", "a", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm8[] = {"d", "g", "k", "l", "m", "n", "r", "s", "t", "v", "x", "y", "z", "kl", "cl"};
    static constexpr std::string_view nm9[] = {"i", "a", "e", "o", "u", "a", "", "", "", "", "", "", "", ""};

    std::string names; std::string names1; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm5);
    names1 = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm3[rnd3] + nm5[rnd6];
    } else {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    if (rnd5 < 2) {
    rnd6 = 1;
    }
    names1 = nm2[rnd] + nm3[rnd2] + nm4[rnd3] + nm3[rnd4] + nm5[rnd5] + nm6[rnd6];
    }
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    rnd9 = rng() % std::size(nm3);
    rnd10 = rng() % std::size(nm4);
    rnd11 = rng() % std::size(nm9);
    rnd12 = rng() % std::size(nm5);
    if (rnd7 < 6) {
    rnd11 = 7;
    rnd12 = 0;
    }
    if (rnd11 > 5) {
    rnd12 = 0;
    }
    names = names1 + "'" + nm7[rnd7] + nm8[rnd8] + nm3[rnd9] + nm4[rnd10] + nm7[rnd11] + nm5[rnd12];
    return names;
    }
}
