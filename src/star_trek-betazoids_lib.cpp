#include "star_trek-betazoids_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_betazoids_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"a", "e", "i", "o", "u", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"b", "c", "d", "g", "k", "l", "m", "n", "r", "s", "t"};
    static constexpr std::string_view nm3[] = {"a", "e", "i", "o", "u", "ei", "aa", "oa"};
    static constexpr std::string_view nm4[] = {"b", "c", "d", "g", "k", "l", "m", "n", "r", "s", "t", "b", "c", "d", "g", "k", "l", "m", "n", "r", "s", "t", "br", "cr", "dr", "gr", "kr", "mr", "nr", "tr", "sb", "sd", "sl", "sm", "sn", "sr", "str", "ndr", "nd", "ng", "nk", "nl", "nt", "tt", "rr", "bb", "dd", "gg"};
    static constexpr std::string_view nm5[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm6[] = {"m", "n", "s", "d", "h", "l"};
    static constexpr std::string_view nm7[] = {"d", "h", "j", "k", "l", "lw", "m", "n", "st", "t", "r", "rw", "v"};
    static constexpr std::string_view nm8[] = {"a", "e", "i", "o", "u", "ea", "ee", "ia"};
    static constexpr std::string_view nm9[] = {"d", "h", "l", "ll", "nn", "mm", "n", "m", "rr", "r", "s", "ss", "str", "v", "vr", "x", "y"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o"};
    static constexpr std::string_view nm11[] = {"d", "h", "l", "n", "m", "r", "s", "v", "x", "y"};
    static constexpr std::string_view nm12[] = {"t", "h", "w", "n", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm13[] = {"a", "e", "i", "o", "u", "", "", "", "", "", ""};
    static constexpr std::string_view nm14[] = {"b", "d", "g", "h", "k", "m", "n", "r", "s", "t", "v", "z", "gr", "dr", "tr", "br", "ch"};
    static constexpr std::string_view nm15[] = {"a", "e", "i", "o", "u", "oi", "aa", "ea", "ai", "ei"};
    static constexpr std::string_view nm16[] = {"b", "c", "d", "g", "k", "l", "lbr", "m", "n", "r", "s", "str", "t", "v", "x", "z"};
    static constexpr std::string_view nm17[] = {"x", "n", "r", "l", "m", "k", "d", "t", "", "", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 5) {
    rnd = rng() % std::size(nm7);
    rnd2 = rng() % std::size(nm8);
    rnd3 = rng() % std::size(nm9);
    rnd4 = rng() % std::size(nm10);
    rnd5 = rng() % std::size(nm12);
    rnd6 = rng() % std::size(nm13);
    rnd7 = rng() % std::size(nm14);
    rnd8 = rng() % std::size(nm15);
    rnd9 = rng() % std::size(nm16);
    rnd10 = rng() % std::size(nm5);
    rnd11 = rng() % std::size(nm17);
    names = nm7[rnd] + nm8[rnd2] + nm9[rnd3] + nm10[rnd4] + nm12[rnd5] + " " + nm13[rnd6] + nm14[rnd7] + nm15[rnd8] + nm16[rnd9] + nm5[rnd10] + nm17[rnd11];
    } else {
    rnd = rng() % std::size(nm7);
    rnd2 = rng() % std::size(nm8);
    rnd3 = rng() % std::size(nm9);
    rnd4 = rng() % std::size(nm10);
    rnd5 = rng() % std::size(nm11);
    rnd6 = rng() % std::size(nm10);
    rnd7 = rng() % std::size(nm12);
    rnd8 = rng() % std::size(nm13);
    rnd9 = rng() % std::size(nm14);
    rnd10 = rng() % std::size(nm15);
    rnd12 = rng() % std::size(nm17);
    names = nm7[rnd] + nm8[rnd2] + nm9[rnd3] + nm10[rnd4] + nm11[rnd5] + nm10[rnd6] + nm12[rnd7] + " " + nm13[rnd8] + nm14[rnd9] + nm15[rnd10] + nm17[rnd12];
    }
    } else {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm13);
    rnd8 = rng() % std::size(nm14);
    rnd9 = rng() % std::size(nm15);
    rnd11 = rng() % std::size(nm17);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm6[rnd6] + " " + nm13[rnd7] + nm14[rnd8] + nm15[rnd9] + nm17[rnd11];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    rnd4 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm13);
    rnd7 = rng() % std::size(nm14);
    rnd8 = rng() % std::size(nm15);
    rnd9 = rng() % std::size(nm16);
    rnd10 = rng() % std::size(nm5);
    rnd11 = rng() % std::size(nm17);
    names = nm3[rnd] + nm4[rnd2] + nm5[rnd3] + nm6[rnd4] + " " + nm13[rnd6] + nm14[rnd7] + nm15[rnd8] + nm16[rnd9] + nm5[rnd10] + nm17[rnd11];
    }
    }
    return names;
    }
}
