#include "star_wars-jawas_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_jawas_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "bl", "brr", "ch", "d", "h", "hr", "j", "k", "kl", "kr", "kt", "m", "mn", "n", "nb", "p", "pl", "pr", "r", "rk", "sn", "sq", "t", "th", "tt", "ts", "v", "w", "wr", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "oe", "ee", "ii", "ee", "ia", "ui", "eo"};
    static constexpr std::string_view nm3[] = {"b", "bb", "bl", "bw", "d", "g", "j", "k", "k't", "k'ch", "k'k", "kch", "kk", "kt", "kth", "l", "lh", "lv", "m", "n", "ng", "nz", "pt", "r", "rk", "s", "ss", "t", "th", "thch", "tj", "tk", "tt", "ttj", "z", "zj", "zz"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "c", "dt", "g", "h", "k", "kk", "kth", "l", "n", "nk", "nt", "pp", "r", "s", "t", "th", "tk", "w", "x", "zz"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "b", "bh", "bl", "ch", "dh", "d", "h", "k", "kh", "kw", "kl", "kn", "l", "m", "n", "p", "pl", "r", "rh", "rw", "s", "sh", "sn", "sl", "th", "ts", "tw", "v", "vl", "w", "wh"};
    static constexpr std::string_view nm7[] = {"b", "d", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "c", "d", "h", "k", "l", "m", "n", "s", "t"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "b'", "b", "d'n", "d", "f", "h", "j", "k", "k'", "kl", "kr", "kk", "l", "m", "m'", "nk", "n", "p", "pt", "q", "q'", "s", "t", "tl", "th", "w"};
    static constexpr std::string_view nm11[] = {"c", "d", "g", "h", "j", "k", "l", "m", "n", "q", "r", "s", "t", "v", "z"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "c", "d", "hs", "k", "kt", "kth", "l", "m", "n", "r", "s", "y", "z"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd5b = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm2);
    rnd10 = rng() % std::size(nm12);
    if (i % 3 == 0 && i % 2 != 0) {
    while (rnd7 < 4) {
    rnd7 = rng() % std::size(nm9);
    }
    while (rnd10 < 5) {
    rnd10 = rng() % std::size(nm12);
    }
    namelast = nm9[rnd7] + nm2[rnd8] + nm12[rnd10];
    } else if (i % 2 == 0) {
    rnd9 = rng() % std::size(nm2);
    rnd11 = rng() % std::size(nm11);
    namelast = nm9[rnd7] + nm2[rnd8] + nm11[rnd11] + nm2[rnd9] + nm12[rnd10];
    } else {
    rnd9 = rng() % std::size(nm2);
    rnd11 = rng() % std::size(nm11);
    rnd12 = rng() % std::size(nm2);
    rnd13 = rng() % std::size(nm11);
    namelast = nm9[rnd7] + nm2[rnd8] + nm11[rnd11] + nm2[rnd9] + nm11[rnd13] + nm2[rnd12] + nm12[rnd10];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm8);
    if (i < 6) {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm2);
    names = nm5[rnd] + nm2[rnd2] + nm7[rnd3] + nm2[rnd4] + nm8[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm2);
    rnd5b = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm2);
    names = nm5[rnd] + nm2[rnd2] + nm7[rnd3] + nm2[rnd4] + nm7[rnd5b] + nm2[rnd6] + nm8[rnd5] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 4) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + namelast;
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5b = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd5b] + nm2[rnd6] + nm4[rnd5] + "  " + namelast;
    }
    }
    return names;
    }
}
