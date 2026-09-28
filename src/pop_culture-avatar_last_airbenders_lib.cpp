#include "pop_culture-avatar_last_airbenders_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pop_culture_avatar_last_airbenders_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"g", "h", "l", "m", "n", "gy", "p", "r", "s", "t"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o"};
    static constexpr std::string_view nm3[] = {"h", "l", "ll", "m", "n", "ng", "nz", "r", "s", "sh", "ts"};
    static constexpr std::string_view nm4[] = {"", "hn", "l", "ng", "n"};
    static constexpr std::string_view nm5[] = {"", "h", "l", "n", "m", "p", "r", "s", "y"};
    static constexpr std::string_view nm6[] = {"h", "l", "m", "ng", "n", "sh", "r", "rr"};
    static constexpr std::string_view nm7[] = {"", "", "hn", "h", "n"};
    static constexpr std::string_view nm8[] = {"h", "r", "s", "t", "v", "z"};
    static constexpr std::string_view nm9[] = {"a", "i", "o"};
    static constexpr std::string_view nm10[] = {"cc", "dd", "kk", "lr", "sr", "nr", "rr", "vr"};
    static constexpr std::string_view nm11[] = {"", "", "ck", "k", "r", "m", "n", "s"};
    static constexpr std::string_view nm12[] = {"h", "k", "r", "t", "v", "y", "z"};
    static constexpr std::string_view nm13[] = {"a", "i", "o"};
    static constexpr std::string_view nm14[] = {"h", "k", "l", "ll", "m", "n", "nn", "r", "rr", "s", "t"};
    static constexpr std::string_view nm15[] = {"ch", "b", "f", "g", "h", "l", "m", "p", "r", "sh", "x"};
    static constexpr std::string_view nm16[] = {"ao", "uo", "aa", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm17[] = {"h", "l", "m", "n", "sh", "t"};
    static constexpr std::string_view nm18[] = {"", "", "", "h", "ng", "n", "r"};
    static constexpr std::string_view nm19[] = {"", "", "b", "f", "g", "h", "k", "l", "n", "m", "s", "sh", "t", "w"};
    static constexpr std::string_view nm19b[] = {"b", "f", "g", "h", "k", "l", "n", "m", "s", "sh", "t", "w"};
    static constexpr std::string_view nm20[] = {"k", "l", "m", "n", "r", "sh", "v", "y"};
    static constexpr std::string_view nm21[] = {"", "", "ph", "h", "ng", "n"};
    static constexpr std::string_view nm22[] = {"", "", "ch", "d", "j", "m", "r", "s", "sh", "t", "y", "z"};
    static constexpr std::string_view nm23[] = {"d", "g", "k", "m", "r", "z"};
    static constexpr std::string_view nm24[] = {"", "", "h", "k", "m", "n", "ng", "w"};
    static constexpr std::string_view nm25[] = {"", "", "ch", "h", "l", "m", "n", "s", "sh", "t", "y", "z"};
    static constexpr std::string_view nm26[] = {"k", "l", "rs", "s", "z"};
    static constexpr std::string_view nm27[] = {"", "", "ch", "h", "l", "m", "n", "s", "sh", "t", "y", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 12; {
    if (type == 1) {
    if (i < 3) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm7);
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3] + nm2[rnd4] + nm7[rnd5];
    } else if (i < 4) {
    rnd = rng() % std::size(nm12);
    rnd2 = rng() % std::size(nm13);
    rnd3 = rng() % std::size(nm14);
    rnd4 = rng() % std::size(nm13);
    rnd5 = rng() % std::size(nm14);
    rnd6 = rng() % std::size(nm13);
    names = nm12[rnd] + nm13[rnd2] + nm14[rnd3] + nm13[rnd4] + nm14[rnd5] + nm13[rnd6];
    } else if (i < 6) {
    rnd = rng() % std::size(nm12);
    rnd2 = rng() % std::size(nm13);
    rnd3 = rng() % std::size(nm14);
    rnd4 = rng() % std::size(nm13);
    names = nm12[rnd] + nm13[rnd2] + nm14[rnd3] + nm13[rnd4];
    } else if (i < 7) {
    rnd = rng() % std::size(nm19);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm20);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm21);
    names = nm19[rnd] + nm2[rnd2] + nm20[rnd3] + nm2[rnd4] + nm21[rnd5];
    } else if (i < 9) {
    rnd = rng() % std::size(nm19b);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm21);
    names = nm19b[rnd] + nm2[rnd2] + nm21[rnd3];
    } else if (i < 10) {
    rnd = rng() % std::size(nm25);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm26);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm26);
    rnd6 = rng() % std::size(nm2);
    names = nm25[rnd] + nm2[rnd2] + nm26[rnd3] + nm2[rnd4] + nm26[rnd5] + nm2[rnd6];
    } else {
    rnd = rng() % std::size(nm27);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm2);
    names = nm25[rnd] + nm2[rnd2] + nm2[rnd3];
    }
    } else {
    if (i < 3) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    } else if (i < 6) {
    rnd = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm9);
    rnd3 = rng() % std::size(nm10);
    rnd4 = rng() % std::size(nm9);
    rnd5 = rng() % std::size(nm11);
    names = nm8[rnd] + nm9[rnd2] + nm10[rnd3] + nm9[rnd4] + nm11[rnd5];
    } else if (i < 7) {
    rnd = rng() % std::size(nm15);
    rnd2 = rng() % std::size(nm16);
    rnd3 = rng() % std::size(nm17);
    rnd4 = rng() % std::size(nm16);
    if (rnd2 < 3) {
    while (rnd4 < 3) {
    rnd4 = rng() % std::size(nm16);
    }
    }
    rnd5 = rng() % std::size(nm18);
    names = nm15[rnd] + nm16[rnd2] + nm17[rnd3] + nm16[rnd4] + nm18[rnd5];
    } else if (i < 9) {
    rnd = rng() % std::size(nm15);
    rnd2 = rng() % std::size(nm16);
    rnd3 = rng() % std::size(nm18);
    names = nm15[rnd] + nm16[rnd2] + nm18[rnd3];
    } else {
    rnd = rng() % std::size(nm22);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm23);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm24);
    if (rnd < 2) {
    while (rnd5 < 2) {
    rnd5 = rng() % std::size(nm24);
    }
    }
    names = nm22[rnd] + nm2[rnd2] + nm23[rnd3] + nm2[rnd4] + nm24[rnd5];
    }
    }
    return names;
    }
}
