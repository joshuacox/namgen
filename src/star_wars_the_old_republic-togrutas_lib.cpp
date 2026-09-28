#include "star_wars_the_old_republic-togrutas_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_the_old_republic_togrutas_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm0[] = {"", "", "", "", "", "", "", "", "", "a", "o", "u"};
    static constexpr std::string_view nm1[] = {"b", "c", "d", "h", "k", "m", "r", "s", "t", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "o", "u"};
    static constexpr std::string_view nm3[] = {"b", "br", "d", "k", "kr", "ky", "l", "n", "nz", "r", "rh", "s", "sht", "t", "vr", "z"};
    static constexpr std::string_view nm4[] = {"a", "aa", "ee", "i", "o", "y"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "", "hd", "k", "n", "m", "r", "s", "sh"};
    static constexpr std::string_view nm6[] = {"", "", "", "", "a", "a", "o", "a"};
    static constexpr std::string_view nm7[] = {"b", "c", "d", "h", "k", "l", "m", "n", "r", "s", "sh", "z"};
    static constexpr std::string_view nm8[] = {"a", "aa", "e", "o"};
    static constexpr std::string_view nm9[] = {"d", "hn", "hl", "hs", "k", "l", "m", "mn", "n", "r", "rl", "rsh", "rn", "s", "ss", "sh", "shl", "t", "th", "tt"};
    static constexpr std::string_view nm10[] = {"a", "aa", "a", "a", "o"};
    static constexpr std::string_view nm11[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "n", "m", "h", "s", "sh"};
    static constexpr std::string_view nm12[] = {"b", "d", "h", "k", "l", "m", "n", "ph", "r", "s", "t", "v", "z"};
    static constexpr std::string_view nm13[] = {"a", "y", "aa", "i", "e"};
    static constexpr std::string_view nm14[] = {"br", "d", "k", "kr", "l", "m", "n", "r", "rn", "rl", "s", "ss", "sh", "shr", "vr", "w", "z"};
    static constexpr std::string_view nm15[] = {"a", "aa", "e", "u", "y", "a", "e", "u", "i", "o", "o", "ii", "ua", "ee"};
    static constexpr std::string_view nm16[] = {"", "", "", "", "ks", "l", "n", "m", "r", "s", "sh"};

    std::string lName; std::string names; size_t rnd = 0; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm12);
    rnd2 = rng() % std::size(nm13);
    rnd3 = rng() % std::size(nm14);
    rnd4 = rng() % std::size(nm15);
    rnd5 = rng() % std::size(nm16);
    lName = nm12[rnd] + nm13[rnd2] + nm14[rnd3] + nm15[rnd4] + nm16[rnd5];
    } else {
    rnd = rng() % std::size(nm12);
    rnd2 = rng() % std::size(nm13);
    rnd5 = rng() % std::size(nm16);
    lName = nm12[rnd] + nm13[rnd2] + nm16[rnd5];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm7);
    rnd3 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm9);
    rnd5 = rng() % std::size(nm10);
    rnd6 = rng() % std::size(nm11);
    names = nm6[rnd] + nm7[rnd2] + nm8[rnd3] + nm9[rnd4] + nm10[rnd5] + nm11[rnd6] + " " + lName;
    } else {
    rnd = rng() % std::size(nm0);
    rnd1 = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    names = nm0[rnd] + nm1[rnd1] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + " " + lName;
    }
    return names;
    }
}
