#include "pop_culture-dragonriders_of_perns_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pop_culture_dragonriders_of_perns_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "b", "c", "f", "g", "gr", "h", "j", "k", "l", "m", "n", "p", "r", "s", "sh", "t", "v", "w", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "y", "y", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ea", "ee", "au", "ai", "ie", "ea", "io"};
    static constexpr std::string_view nm3[] = {"b", "c", "d", "f", "g", "k", "l", "m", "n", "p", "r", "s", "t", "v", "x", "b", "br", "c", "ch", "d", "dr", "f", "fr", "g", "k", "l", "ld", "ll", "lr", "lt", "m", "n", "nc", "nd", "ng", "ngr", "nn", "nr", "ns", "nt", "p", "r", "rbr", "rm", "rn", "rr", "rsh", "rt", "sg", "shm", "ss", "sr", "st", "t", "th", "v", "x"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "c", "d", "l", "l", "l", "l", "ll", "m", "n", "n", "n", "n", "n", "nt", "r", "rg", "rl", "s", "sh", "st", "t", "x"};
    static constexpr std::string_view nm5[] = {"b", "br", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "r", "s", "sh", "t", "th", "w", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "a", "a", "e", "i", "o", "u", "a", "e", "i", "a", "a", "e", "i", "o", "u", "a", "e", "i", "a", "a", "e", "i", "o", "u", "a", "e", "i", "a", "a", "e", "i", "o", "u", "ee", "io", "ia", "ai", "ea"};
    static constexpr std::string_view nm7[] = {"c", "d", "dn", "k", "kk", "kl", "l", "l", "l", "l", "lk", "ll", "ll", "ll", "lm", "ln", "m", "mm", "n", "nn", "r", "rdr", "rn", "rr", "s", "ss", "sn", "sl", "t", "tr", "v", "y", "z", "c", "d", "k", "l", "l", "m", "n", "r", "s", "t", "v", "y", "z", "kk", "ll", "ll", "mm", "nn", "rr", "ss"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "h", "n", "m"};
    static constexpr std::string_view nm9[] = {"b", "br", "c", "ch", "cr", "d", "f", "g", "h", "j", "k", "l", "m", "p", "r", "s", "sp", "t", "v", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "ia", "ai", "io"};
    static constexpr std::string_view nm11[] = {"dr", "g", "gr", "gl", "k", "l", "lz", "ld", "m", "n", "nd", "r", "r", "r", "r", "rr", "rm", "rn", "rt", "ss", "sr", "y", "z", "g", "k", "l", "m", "n", "r", "y", "z"};
    static constexpr std::string_view nm12[] = {"lth", "nth", "rth", "th"};
    static constexpr std::string_view nm13[] = {"b", "br", "ch", "f", "g", "h", "k", "l", "m", "n", "p", "pr", "r", "s", "t", "w", "z"};
    static constexpr std::string_view nm14[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm15[] = {"d", "d", "l", "l", "l", "l", "ll", "lm", "ln", "ls", "m", "m", "n", "n", "nl", "nr", "nm", "r", "r", "r", "rl", "r", "s", "s", "yl", "yr", "yn"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm3);
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 5) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5];
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm8[rnd5];
    }
    } else if (type == 2) {
    rnd5 = rng() % std::size(nm12);
    if (i < 5) {
    rnd = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm10);
    rnd3 = rng() % std::size(nm11);
    rnd4 = rng() % std::size(nm10);
    if (i < 3) {
    names = nm9[rnd] + nm10[rnd2] + nm11[rnd3] + nm10[rnd4] + nm12[rnd5];
    } else {
    rnd6 = rng() % std::size(nm11);
    rnd7 = rng() % std::size(nm10);
    names = nm9[rnd] + nm10[rnd2] + nm11[rnd3] + nm10[rnd4] + nm11[rnd6] + nm10[rnd7] + nm12[rnd5];
    }
    } else {
    rnd = rng() % std::size(nm13);
    rnd2 = rng() % std::size(nm14);
    rnd3 = rng() % std::size(nm15);
    rnd4 = rng() % std::size(nm14);
    if (i < 8) {
    names = nm13[rnd] + nm14[rnd2] + nm15[rnd3] + nm14[rnd4] + nm12[rnd5];
    } else {
    rnd6 = rng() % std::size(nm15);
    rnd7 = rng() % std::size(nm14);
    names = nm13[rnd] + nm14[rnd2] + nm15[rnd3] + nm14[rnd4] + nm15[rnd6] + nm14[rnd7] + nm12[rnd5];
    }
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 3) {
    while (rnd < 4) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 4) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5];
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5];
    }
    }
    return names;
    }
}
