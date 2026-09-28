#include "star_wars-trandoshans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_trandoshans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "", "", "", "", "b", "bh", "bl", "br", "c", "ch", "cl", "cr", "d", "dh", "dr", "fr", "g", "gh", "gr", "grr", "gwh", "h", "hr", "hss", "j", "k", "khr", "kl", "kr", "l", "m", "mr", "n", "nr", "nrr", "p", "pr", "q", "r", "s", "sh", "sk", "sl", "ss", "ssk", "sstr", "st", "thr", "t", "tr", "tsh", "tss", "v", "vr", "w", "x", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "y", "y", "uu", "ee", "aa", "oo", "ai", "ui", "ey"};
    static constexpr std::string_view nm3[] = {"ch", "cr", "d", "dfr", "dg", "g", "gg", "gr", "hhm", "hs", "k", "khss", "kk", "kr", "ks", "kt", "l", "ld", "lf", "ll", "lt", "m", "mr", "n", "nd", "ng", "nk", "nn", "nt", "nv", "ph", "qz", "r", "rd", "rk", "rn", "rr", "rth", "rtsn", "s", "sd", "sh", "sn", "ss", "sskr", "t", "tl", "tt", "v", "vr", "z", "zzm"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "", "", "", "b", "c", "d", "ff", "g", "gg", "h", "hk", "hssk", "k", "kk", "kss", "kt", "l", "ll", "mx", "n", "nk", "pp", "q", "r", "rg", "rj", "rk", "rkh", "rq", "rr", "rrng", "rrsk", "rsk", "rssk", "rst", "rt", "rth", "s", "sh", "shk", "sk", "ss", "ssc", "ssh", "ssk", "sskk", "sst", "t", "tch", "tt", "v", "w", "x", "xx", "z"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "", "", "", "", "b", "bh", "bl", "cl", "ch", "cr", "dh", "dr", "f", "fr", "fl", "g", "gh", "gr", "h", "hs", "k", "kh", "kl", "kn", "km", "l", "m", "ms", "mss", "mh", "n", "ns", "nh", "p", "pr", "q", "r", "rh", "s", "sh", "ss", "sl", "sm", "st", "t", "th", "tr", "ts", "v", "w", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "y", "y", "uu", "ee", "aa", "oo", "ai"};
    static constexpr std::string_view nm7[] = {"ch", "d", "dw", "f", "ff", "g", "gg", "gl", "h", "hh", "hr", "hs", "hss", "k", "ks", "khs", "l", "ls", "lss", "ll", "lf", "lm", "ln", "ld", "m", "ml", "n", "nl", "nd", "nc", "ph", "r", "rs", "rl", "rt", "rth", "rg", "sl", "ss", "sh", "st", "t", "th", "tt", "tl", "v", "z"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "c", "d", "f", "ff", "h", "k", "kss", "l", "m", "n", "nn", "rkh", "s", "ss", "sh", "ssh", "t", "th"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "", "", "b", "br", "d", "dr", "f", "g", "gr", "h", "hs", "hss", "hsk", "j", "jh", "jhc", "k", "kl", "m", "n", "r", "s", "ss", "sm", "st", "sv", "t", "tr", "ts", "v", "vl", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "y", "y", "ea", "aa", "oo", "eo", "ee", "au"};
    static constexpr std::string_view nm11[] = {"br", "b", "cr", "cd", "d", "dg", "dm", "dr", "dr", "g", "gg", "gr", "gs", "gl", "k", "kk", "kr", "ks", "kl", "l", "ll", "ls", "m", "mm", "mr", "ms", "n", "nn", "ns", "nl", "ng", "q", "r", "rs", "rz", "rd", "rr", "s", "ss", "sd", "sl", "sg", "tn", "v", "vv"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "", "", "", "", "", "c", "gg", "gh", "hk", "k", "kt", "l", "n", "r", "rn", "rs", "s", "sss", "st", "ssk", "sch", "ss", "t", "tch", "z"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm12);
    if (i % 2 != 0) {
    while (rnd10 < 7) {
    rnd10 = rng() % std::size(nm12);
    }
    namelast = nm9[rnd7] + nm10[rnd8] + nm12[rnd10];
    } else {
    rnd9 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    namelast = nm9[rnd7] + nm10[rnd8] + nm11[rnd11] + nm10[rnd9] + nm12[rnd10];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 3) {
    while (rnd < 10) {
    rnd = rng() % std::size(nm5);
    }
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    while (rnd5 < 10) {
    rnd5 = rng() % std::size(nm4);
    }
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
