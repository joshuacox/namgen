#include "star_wars-niktos_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_niktos_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "b", "bh", "br", "c", "ch", "d", "dr", "f", "fh", "g", "gr", "h", "j", "kl", "l", "m", "n", "p", "r", "s", "sr", "sl", "t", "ts", "v", "wl"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "au", "oo", "io", "ia", "ou", "aa", "ai", "oi", "ea"};
    static constexpr std::string_view nm3[] = {"b", "bb", "bd", "d", "dd", "dr", "dg", "dr", "g", "gr", "gg", "gb", "k", "kt", "kr", "kn", "kh", "l", "lf", "ll", "lv", "m", "n", "nd", "ndl", "ndr", "ng", "ns", "nt", "r", "rd", "rk", "rsk", "s", "sh", "ss", "t", "th", "v", "x", "z"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "ch", "d", "gg", "k", "kk", "kt", "l", "m", "n", "nc", "nn", "r", "rsk", "s", "sh", "sk", "t", "th", "v", "wl", "x"};
    static constexpr std::string_view nm5[] = {"b'r", "d'r", "d'w", "f'w", "f'r", "g'r", "g'w", "g'l", "g'n", "k'w", "k'r", "k'l", "m'tr", "n'r", "n'tr", "s'r", "s'v", "t'r", "t'sr", "v'r", "b", "bh", "br", "c", "ch", "d", "dr", "f", "fh", "g", "gr", "h", "j", "kl", "l", "m", "n", "p", "r", "s", "sr", "sl", "t", "ts", "v", "wl"};
    static constexpr std::string_view nm6[] = {"'b", "'d", "b'd", "b'r", "d'r", "d'g", "d'gr", "g'b", "g'r", "'g", "'j", "'k", "k'tr", "k'r", "k'n", "l'v", "l'm", "l'r", "'m", "'n", "n'dr", "n'd", "'p", "'r", "r'r", "r'kr", "r's", "s'sh", "s'th", "'t", "t'r", "t'v", "b", "bb", "bd", "d", "dd", "dr", "dg", "dr", "g", "gr", "gg", "gb", "k", "kt", "kr", "kn", "kh", "l", "lf", "ll", "lv", "m", "n", "nd", "ndl", "ndr", "ng", "ns", "nt", "r", "rd", "rk", "rsk", "s", "sh", "ss", "t", "th", "v", "x", "z"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "b", "ch", "d", "f", "g", "h", "j", "k", "m", "n", "p", "q", "r", "s", "sh", "t", "v", "w", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ee", "oo", "uu", "au", "ou", "oi", "ai", "ei"};
    static constexpr std::string_view nm11[] = {"b", "cc", "g", "g", "gg", "gt", "gn", "gm", "gl", "gt", "gr", "k", "kt", "kk", "kn", "km", "kl", "m", "mk", "mp", "mpl", "n", "nd", "nk", "ng", "nt", "p", "pl", "pt", "r", "rc", "rk", "rd", "rt", "rs", "s", "st", "t", "z"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "c", "g", "k", "l", "n", "nn", "nk", "m", "mk", "rch", "rk", "rg", "rc", "rr", "s", "sh", "sk", "t", "th", "tt", "x"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd3b = 0; size_t rnd4 = 0; size_t rnd4b = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm12);
    if (i % 2 == 0) {
    while (rnd7 < 4) {
    rnd7 = rng() % std::size(nm9);
    }
    while (rnd10 < 5) {
    rnd10 = rng() % std::size(nm12);
    }
    namelast = nm9[rnd7] + nm10[rnd8] + nm12[rnd10];
    } else {
    rnd9 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    namelast = nm9[rnd7] + nm10[rnd8] + nm11[rnd11] + nm10[rnd9] + nm12[rnd10];
    }
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 3) {
    while (rnd < 4) {
    rnd = rng() % std::size(nm1);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + namelast;
    } else if (i < 6) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    } else if (i < 8) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm2);
    rnd3b = rng() % std::size(nm6);
    rnd4b = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm5);
    if (rnd6 < 20 && rnd3 < 32) {
    while (rnd3b < 32) {
    rnd3b = rng() % std::size(nm6);
    }
    }
    if (rnd6 > 19 || rnd3 > 31) {
    while (rnd3b > 31) {
    rnd3b = rng() % std::size(nm6);
    }
    }
    names = nm5[rnd6] + nm2[rnd2] + nm6[rnd3] + nm2[rnd4] + nm6[rnd3b] + nm2[rnd4b] + nm4[rnd5] + "  " + namelast;
    }
    return names;
    }
}
