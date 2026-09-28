#include "star_wars-bothans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_bothans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "b", "c", "d", "g", "gr", "h", "k", "n", "r", "tr", "v", "y", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ae", "aa", "ee", "ai", "ia"};
    static constexpr std::string_view nm3[] = {"b", "br", "c", "ct", "d", "dr", "g", "h", "kr", "k", "m", "nt", "r", "ry", "tr", "v"};
    static constexpr std::string_view nm4[] = {"c", "g", "gt", "k", "m", "n", "r", "rc", "rd", "rsk", "sc", "sk", "st", "th"};
    static constexpr std::string_view nm5[] = {"", "", "", "c", "dh", "g", "gn", "gl", "h", "k", "kn", "l", "m", "n", "s", "th", "v", "y"};
    static constexpr std::string_view nm6[] = {"c", "g", "h", "kh", "l", "m", "n", "nt", "nd", "q", "qh", "r", "rr", "s", "t", "th", "tr", "v"};
    static constexpr std::string_view nm7[] = {"h", "l", "m", "n", "nn", "r", "s", "t", "th"};
    static constexpr std::string_view nm8[] = {"bw", "d", "f", "g", "gr", "h", "k", "kr", "l", "m", "n", "s", "tr", "v"};
    static constexpr std::string_view nm9[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ae", "aa", "ee", "ai", "ia", "ua", "ea"};
    static constexpr std::string_view nm10[] = {"d", "d'h", "f'l", "'f", "h'r", "h", "'h", "k", "'k", "l", "'l", "n", "n'd", "nr", "n'q", "nd", "n'n", "q", "r", "rr", "'r", "s", "s'", "'t", "t", "th", "v'", "y'l"};
    static constexpr std::string_view nm11[] = {"h", "l", "m", "n", "r", "s", "t", "v"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "a", "e", "i", "o", "u"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm8);
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd9 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm11);
    rnd11 = rng() % std::size(nm12);
    namelast = nm8[rnd6] + nm9[rnd7] + nm10[rnd8] + nm9[rnd9] + nm11[rnd10] + nm12[rnd11];
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm7);
    if (i < 7) {
    names = nm5[rnd] + nm2[rnd2] + nm7[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm2);
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3] + nm2[rnd4] + nm7[rnd5] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 7) {
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    }
    }
    return names;
    }
}
