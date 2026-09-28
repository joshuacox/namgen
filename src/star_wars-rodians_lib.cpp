#include "star_wars-rodians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_rodians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "", "", "", "", "b", "bl", "br", "c", "ch", "chr", "cl", "cr", "d", "dh", "dr", "dw", "f", "fr", "g", "gl", "gr", "gw", "h", "j", "k", "kl", "kn", "kr", "l", "m", "n", "p", "ph", "pr", "prw", "q", "r", "s", "sh", "sk", "sl", "sn", "sp", "st", "t", "th", "tr", "ts", "tw", "v", "vl", "vr", "w", "x", "z"};
    static constexpr std::string_view nm2[] = {"a", "o", "e", "i", "a", "e", "i", "o", "u", "a", "o", "e", "i", "a", "e", "i", "o", "u", "a", "o", "e", "i", "a", "e", "i", "o", "u", "a", "o", "e", "i", "a", "e", "i", "o", "u", "a", "o", "e", "i", "a", "e", "i", "o", "u", "a", "o", "e", "i", "a", "e", "i", "o", "u", "ee", "ee", "ee", "ee", "ee", "ee", "ee", "ee", "ee", "ee", "ee", "ee", "ee", "aa", "ei", "oi", "oo", "ii", "iu", "ae", "ea", "ou", "uu", "ya", "ye", "yi", "ua", "ae", "ay", "ey", "ei"};
    static constexpr std::string_view nm3[] = {"b", "bb", "bd", "bl", "bn", "c", "ch", "d", "dd", "dj", "dl", "dr", "f", "ff", "g", "gr", "gv", "gw", "h", "hd", "hm", "j", "k", "kd", "kk", "kl", "ks", "ksl", "ksr", "kw", "l", "lb", "lg", "lk", "lks", "ll", "llk", "lr", "ls", "lt", "lv", "m", "mb", "mtr", "n", "nc", "nd", "ndr", "ng", "nk", "nm", "nn", "nnd", "nnt", "nq", "ns", "nt", "nw", "p", "pd", "ph", "pl", "pp", "q", "r", "rb", "rd", "rg", "rgr", "rh", "rm", "rn", "rr", "rrt", "rsh", "rss", "rth", "rv", "rz", "s", "sd", "sh", "sk", "ss", "st", "t", "th", "ts", "v", "vl", "vv", "w", "x", "z", "zn", "zw", "zz"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "bb", "c", "ch", "ck", "d", "dd", "f", "g", "gg", "gn", "h", "k", "kk", "l", "ld", "ll", "m", "n", "ng", "nn", "ns", "nst", "nt", "p", "pp", "q", "r", "rk", "rl", "rm", "rmm", "rn", "rtt", "s", "sh", "sk", "ss", "ssk", "t", "tch", "tz", "v", "w", "x", "xl", "z", "zz"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "", "", "", "", "b", "bl", "bh", "c", "ch", "cl", "d", "dh", "dr", "f", "fl", "g", "gl", "gh", "gr", "h", "hr", "j", "k", "kh", "kl", "l", "m", "n", "ph", "phr", "r", "s", "sh", "sl", "sn", "sm", "t", "th", "thr", "tr", "tw", "v", "vl", "vr", "vh", "w", "wr", "wh", "z", "zh", "zn", "zm", "zl"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "a", "e", "i", "a", "e", "i", "o", "u", "a", "a", "e", "i", "a", "e", "i", "o", "u", "a", "a", "e", "i", "a", "e", "i", "o", "u", "a", "a", "e", "i", "a", "e", "i", "o", "u", "a", "a", "e", "i", "a", "e", "i", "o", "u", "a", "a", "e", "i", "ee", "ee", "ee", "ii", "ii", "ii", "ee", "ee", "ee", "ee", "ii", "ii", "ii", "ii", "ee", "ii", "oo", "ea", "ee", "ei", "eea", "ii", "oa", "uu", "ia"};
    static constexpr std::string_view nm7[] = {"b", "bb", "bl", "bs", "bn", "bm", "c", "cn", "cm", "d", "dh", "dl", "dn", "dm", "f", "ff", "fl", "fn", "fm", "fr", "g", "gg", "ht", "hn", "k", "l", "ll", "ls", "ln", "lm", "lb", "lk", "lk", "ll", "lv", "lw", "lr", "m", "mn", "mm", "md", "ms", "mz", "n", "nz", "nr", "nb", "nd", "ndr", "nnr", "nt", "nm", "nh", "ns", "ph", "phl", "phr", "phn", "r", "rs", "rz", "rl", "rd", "rf", "rm", "rn", "rp", "rr", "s", "sh", "ss", "t", "thm", "th", "thn", "thl", "ths", "tz", "ts", "tt", "v", "w", "z", "zl"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "f", "h", "k", "l", "ll", "m", "n", "ph", "s", "ss", "th", "w", "z"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "", "", "", "", "", "b", "bl", "br", "c", "ch", "d", "dr", "f", "g", "gh", "gr", "h", "j", "jc", "k", "khz", "kr", "l", "m", "n", "p", "pl", "pr", "r", "s", "sh", "sw", "t", "th", "tr", "v", "vl", "w", "x", "xr", "z", "zs", "zt"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "a", "o", "e", "a", "e", "i", "o", "u", "a", "a", "o", "e", "a", "e", "i", "o", "u", "a", "a", "o", "e", "a", "e", "i", "o", "u", "a", "a", "o", "e", "a", "e", "i", "o", "u", "a", "a", "o", "e", "ee", "ee", "ee", "ee", "ee", "ee", "ee", "ee", "ai", "ee", "oo", "iee", "eaa", "ia", "io", "aa", "uo", "y", "ii", "oa", "yo", "yi", "ye"};
    static constexpr std::string_view nm11[] = {"b", "c", "ch", "d", "fr", "g", "gg", "j", "k", "kc", "kk", "ks", "l", "ld", "lk", "ln", "lz", "m", "ml", "n", "nc", "nck", "nd", "ng", "nk", "nn", "np", "nt", "nw", "p", "pk", "pp", "r", "rm", "rr", "rt", "s", "sk", "sm", "ss", "st", "t", "tr", "v", "vr", "w", "y", "z"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "c", "ch", "d", "ff", "gg", "ggs", "gs", "h", "hn", "hnt", "ht", "k", "l", "lb", "ll", "ls", "m", "n", "ng", "nk", "nn", "ntt", "nx", "p", "q", "r", "rk", "rn", "ro", "rr", "rs", "s", "sh", "t", "th", "w", "x", "z"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd5b = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm12);
    if (i % 3 == 0 && i % 2 != 0) {
    while (rnd7 < 10) {
    rnd7 = rng() % std::size(nm9);
    }
    namelast = nm9[rnd7] + nm10[rnd8] + nm12[rnd10];
    } else if (i % 2 == 0) {
    rnd9 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    namelast = nm9[rnd7] + nm10[rnd8] + nm11[rnd11] + nm10[rnd9] + nm12[rnd10];
    } else {
    rnd9 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    rnd12 = rng() % std::size(nm10);
    rnd13 = rng() % std::size(nm11);
    namelast = nm9[rnd7] + nm10[rnd8] + nm11[rnd11] + nm10[rnd9] + nm11[rnd13] + nm10[rnd12] + nm12[rnd10];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 4) {
    while (rnd < 10) {
    rnd = rng() % std::size(nm5);
    }
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd5] + "  " + namelast;
    } else if (i < 8) {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5b = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd5b] + nm6[rnd6] + nm8[rnd5] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 4) {
    while (rnd < 10) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 40) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + namelast;
    } else if (i < 8) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + "  " + namelast;
    }
    }
    return names;
    }
}
