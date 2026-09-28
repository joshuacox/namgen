#include "star_wars-biths_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_biths_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"d", "d'r", "f", "f't", "g", "g'h", "h", "j", "k", "ph", "ph't", "r", "th"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "oo", "eu", "ia", "aa"};
    static constexpr std::string_view nm3[] = {"b", "bb", "c", "cr", "d", "dd", "g", "gr", "h", "k", "kr", "l", "lk", "ll", "mk", "m", "n", "nk", "p", "pp", "r", "z"};
    static constexpr std::string_view nm4[] = {"", "", "", "l", "m", "n", "ns", "r", "s", "ss", "w"};
    static constexpr std::string_view nm5[] = {"d", "d'h", "f", "f'h", "g", "g'h", "h", "l", "m", "n", "ph", "r", "rh", "r'h", "th"};
    static constexpr std::string_view nm6[] = {"b", "c", "d", "dh", "g", "gr", "h", "l", "lm", "ln", "ls", "m", "mn", "ml", "md", "mm", "n", "nn", "nr", "nl", "nd", "r", "s", "sh", "th", "v", "z"};
    static constexpr std::string_view nm7[] = {"", "", "", "h", "l", "m", "n", "s", "ss"};
    static constexpr std::string_view nm8[] = {"d", "d'", "f", "g", "g'h", "h", "j", "k", "k's", "l", "m", "n", "ph", "r", "rh", "r'h", "th"};
    static constexpr std::string_view nm9[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm10[] = {"b", "d", "dh", "g", "gr", "h", "l", "lr", "lm", "m", "mn", "md", "mm", "n", "nn", "nr", "nd", "nt", "r", "rt", "rl", "rd", "s", "sh", "th", "v", "z"};
    static constexpr std::string_view nm11[] = {"", "", "", "", "l", "m", "n", "r", "rn", "s", "ss"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "a", "e", "i", "o", "u"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd2b = 0; size_t rnd3 = 0; size_t rnd3b = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm8);
    rnd7 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm11);
    if (i < 5) {
    while (rnd10 < 4) {
    rnd10 = rng() % std::size(nm11);
    }
    rnd11 = rng() % std::size(nm12);
    namelast = nm8[rnd6] + nm9[rnd7] + nm11[rnd10] + nm12[rnd11];
    } else {
    rnd8 = rng() % std::size(nm10);
    rnd9 = rng() % std::size(nm9);
    namelast = nm8[rnd6] + nm9[rnd7] + nm10[rnd8] + nm9[rnd9] + nm11[rnd10];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm7);
    if (i < 8) {
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3] + nm2[rnd4] + nm7[rnd5] + "  " + namelast;
    } else {
    rnd2b = rng() % std::size(nm2);
    rnd3b = rng() % std::size(nm6);
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3] + nm2[rnd4] + nm6[rnd3b] + nm2[rnd2b] + nm7[rnd5] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 8) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    } else {
    rnd2b = rng() % std::size(nm2);
    rnd3b = rng() % std::size(nm3);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd3b] + nm2[rnd2b] + nm4[rnd5] + "  " + namelast;
    }
    }
    return names;
    }
}
