#include "star_wars-mon_calamaris_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_mon_calamaris_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "br", "c", "ch", "cr", "d", "dr", "f", "g", "gh", "gr", "h", "j", "jh", "k", "kr", "l", "m", "mx", "n", "p", "q", "r", "s", "sh", "t", "tr", "v", "vc", "vr", "y"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "aa", "oo", "ee", "oe", "io", "ua", "ae", "oa", "ie", "ai", "uu", "ea"};
    static constexpr std::string_view nm3[] = {"b", "br", "c", "ck", "ckd", "ckl", "ckr", "dr", "fw", "g", "ggr", "h", "hd", "j", "k", "kb", "kk", "kl", "km", "l", "lb", "lbr", "ld", "lk", "lkph", "ll", "lm", "lp", "lsp", "lt", "ly", "m", "mb", "mbr", "mck", "mm", "n", "nd", "ndl", "ng", "nk", "nl", "nq", "ns", "ph", "r", "rb", "rch", "rg", "rl", "rn", "rpf", "rr", "rsh", "rt", "s", "sf", "shn", "ss", "t", "th", "tr", "tt", "vr", "x", "xl", "yg", "z", "zl"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "b", "c", "ck", "ff", "h", "k", "kk", "l", "ll", "ln", "m", "n", "ns", "nt", "r", "rl", "rn", "rt", "rth", "rx", "s", "sh", "ss", "ss", "sz", "t", "th", "x", "z"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "b", "c", "ch", "d", "f", "h", "j", "jh", "k", "kl", "l", "m", "mh", "n", "nh", "r", "s", "sh", "t", "th", "v", "vr", "y"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "ea", "ie", "ue", "ee", "ia", "ae"};
    static constexpr std::string_view nm7[] = {"b", "bt", "d", "dh", "dn", "f", "fw", "fn", "fl", "hl", "hh", "hn", "hm", "hl", "k", "kh", "ky", "kl", "km", "kn", "l", "lb", "lh", "lm", "ln", "ll", "m", "mb", "mn", "md", "n", "nd", "nl", "nh", "nk", "nky", "nm", "nn", "r", "rd", "rg", "rh", "s", "sh", "sm", "so", "w", "y", "z"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "h", "l", "m", "n", "nt", "r", "s"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "b", "br", "d", "g", "gh", "gr", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "vr", "w"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ou", "ia", "ua", "ai", "oo", "aa", "ee"};
    static constexpr std::string_view nm11[] = {"b", "bb", "br", "ch", "ckb", "ckd", "d", "dd", "dl", "dr", "g", "gr", "gb", "h", "hd", "k", "kb", "l", "lb", "lk", "lg", "lgr", "lw", "ld", "m", "mg", "md", "mb", "n", "md", "mb", "ng", "p", "pt", "r", "rc", "rr", "rt", "rg", "rb", "rgr", "s", "spl", "sc", "shc", "sr", "th", "thr", "tr", "tt", "vn", "y"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "", "", "b", "bb", "c", "hb", "hd", "k", "kk", "l", "ll", "ls", "n", "r", "s", "sch", "ss", "x", "xx", "xz"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd5b = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm12);
    if (i % 3 == 0 && i % 2 != 0) {
    while (rnd7 < 4) {
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
    while (rnd < 5) {
    rnd = rng() % std::size(nm5);
    }
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd5] + " " + namelast;
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
    if (i < 3) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 5) {
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
