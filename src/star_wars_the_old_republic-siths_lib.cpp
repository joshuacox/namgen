#include "star_wars_the_old_republic-siths_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_the_old_republic_siths_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"a", "i", "o", "u", "â", "û", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"ch", "d", "dz", "h", "j", "k", "kr", "kh", "m", "n", "l", "q", "r", "rh", "s", "sh", "sr", "t", "ts", "w", "wr", "wh", "y", "z", "zh", "zr", "ch", "d", "h", "j", "k", "m", "n", "l", "q", "r", "s", "t", "w", "y", "z"};
    static constexpr std::string_view nm3[] = {"a", "i", "o", "u", "ai", "oi", "a", "i", "o", "u", "a", "i", "o", "u", "â", "û"};
    static constexpr std::string_view nm4[] = {"d", "h", "j", "k", "l", "m", "n", "sh", "q", "r", "s", "t", "ts", "w", "y", "z"};
    static constexpr std::string_view nm5[] = {"d", "h", "j", "k", "l", "m", "n", "sh", "q", "r", "s", "t", "ts", "w", "y", "z", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm6[] = {"a", "û", "â", "i", "o", "u", "ai", "oi"};
    static constexpr std::string_view nm7[] = {"r", "t", "s", "sh", "z", "n", "m", "ts", "l", "w", "", "", "", ""};
    static constexpr std::string_view nm8[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm9[] = {"b", "bh", "br", "c", "ch", "cl", "d", "dr", "dh", "g", "gr", "gh", "j", "k", "kh", "m", "n", "p", "pl", "q", "r", "rh", "s", "sl", "sh", "t", "tr", "v", "vl", "vr", "w", "wr", "wh", "x", "y", "z", "zh", "zr", "b", "c", "d", "g", "j", "k", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "ae", "ea", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm11[] = {"d", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "x"};
    static constexpr std::string_view nm12[] = {"b", "c", "d", "g", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "z", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm13[] = {"a", "e", "i", "o", "u", "iu", "ae", "ia", "ua", "uo", "ea", "iu", "ae", "ia", "ua"};
    static constexpr std::string_view nm14[] = {"th", "s", "sh", "n", "m", "x", "l", "wr", "sy", "ty", "tiur", "tiuth", "siuth", "ny", "nyr", "lyr", "rius", "", "", "", "", "", "", "", "", "", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm9);
    rnd3 = rng() % std::size(nm10);
    rnd4 = rng() % std::size(nm11);
    rnd5 = rng() % std::size(nm12);
    rnd6 = rng() % std::size(nm13);
    rnd7 = rng() % std::size(nm14);
    names = nm8[rnd] + nm9[rnd2] + nm10[rnd3] + nm11[rnd4] + nm12[rnd5] + nm13[rnd6] + nm14[rnd7];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm6[rnd6] + nm7[rnd7];
    }
    return names;
    }
}
