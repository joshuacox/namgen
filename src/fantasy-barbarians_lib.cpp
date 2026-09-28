#include "fantasy-barbarians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_barbarians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"ae", "au", "ei", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm2[] = {"", "", "", "b", "bl", "br", "bh", "d", "dr", "dh", "f", "fr", "g", "gh", "gr", "gl", "h", "hy", "hr", "j", "k", "kh", "kr", "l", "ll", "m", "n", "p", "pr", "r", "rh", "s", "sk", "sg", "sm", "sn", "st", "t", "th", "thr", "ty", "v", "y"};
    static constexpr std::string_view nm3[] = {"bl", "br", "d", "db", "dbr", "dd", "ddg", "dg", "dl", "dm", "dr", "dv", "f", "fd", "fgr", "fk", "fl", "fn", "fr", "fst", "fv", "g", "gb", "gd", "gf", "gg", "ggv", "gl", "gn", "gr", "gss", "gv", "k", "kk", "l", "lb", "lc", "ld", "ldr", "lf", "lfr", "lg", "lgr", "lk", "ll", "llg", "llk", "llv", "lm", "ln", "lp", "lr", "ls", "lsk", "lsn", "lst", "lsv", "lt", "lv", "m", "md", "mk", "ml", "mm", "ms", "n", "nb", "nd", "ndr", "ng", "nl", "nn", "nng", "nr", "nsk", "nt", "nv", "nw", "p", "pl", "pp", "pr", "r", "rb", "rd", "rdg", "rf", "rg", "rgr", "rk", "rkm", "rl", "rls", "rm", "rn", "rng", "rngr", "rnh", "rnk", "rns", "rnv", "rr", "rst", "rt", "rth", "rtm", "rv", "s", "sb", "sbr", "sg", "sgr", "sk", "sl", "sm", "sn", "sr", "ssk", "st", "stm", "str", "sv", "t", "tg", "th", "thg", "thn", "thr", "thv", "tm", "tr", "tt", "ttf", "tv", "v", "yv", "z", "zg", "zl", "zn"};
    static constexpr std::string_view nm4[] = {"d", "dr", "f", "g", "kr", "k", "l", "ld", "lf", "lk", "ll", "lr", "m", "mm", "n", "nd", "nn", "r", "rd", "rn", "rr", "s", "th", "t"};
    static constexpr std::string_view nm5[] = {"", "", "", "b", "br", "bh", "ch", "d", "dh", "f", "fr", "g", "gh", "gr", "gw", "gl", "h", "j", "k", "kh", "m", "n", "r", "rh", "s", "sh", "st", "sv", "t", "th", "thr", "tr", "v", "w"};
    static constexpr std::string_view nm6[] = {"ae", "ea", "ie", "ei", "io", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm7[] = {"bj", "c", "d", "dd", "df", "dl", "dr", "f", "ff", "fl", "fn", "fr", "fth", "g", "gd", "gm", "gn", "gnh", "gr", "h", "hh", "k", "l", "ld", "lf", "lfh", "lg", "lgr", "lh", "lk", "ll", "lm", "lr", "ls", "lv", "m", "mm", "n", "nd", "ndr", "ng", "ngr", "ngv", "nh", "nl", "nn", "nnh", "nr", "ns", "nt", "nv", "r", "rd", "rf", "rg", "rgh", "rgr", "rh", "rk", "rl", "rm", "rn", "rnd", "rng", "rr", "rst", "rt", "rth", "rtr", "rv", "s", "sb", "sd", "sg", "sh", "sl", "st", "stn", "str", "sv", "t", "thr", "tk", "tr", "tt", "tth", "v", "y", "yj", "ym", "yn"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "f", "g", "h", "l", "n", "nn", "s", "sh", "th", "y"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm8);
    if (i < 3) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm5);
    }
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd3];
    } else if (i < 8) {
    rnd4 = rng() % std::size(nm6);
    if (rnd2 < 5) {
    while (rnd4 < 5) {
    rnd4 = rng() % std::size(nm6);
    }
    }
    rnd5 = rng() % std::size(nm7);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd5] + nm6[rnd4] + nm8[rnd3];
    } else {
    rnd4 = rng() % std::size(nm6);
    if (rnd2 < 5) {
    while (rnd4 < 5) {
    rnd4 = rng() % std::size(nm6);
    }
    }
    rnd5 = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm6);
    if (rnd2 < 5 || rnd4 < 5) {
    while (rnd6 < 5) {
    rnd6 = rng() % std::size(nm6);
    }
    }
    rnd7 = rng() % std::size(nm7);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd5] + nm6[rnd4] + nm7[rnd7] + nm6[rnd6];
    }
    } else {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm4);
    if (i < 3) {
    names = nm2[rnd] + nm1[rnd2] + nm4[rnd3];
    } else if (i < 8) {
    rnd4 = rng() % std::size(nm1);
    if (rnd < 3) {
    while (rnd4 < 3) {
    rnd4 = rng() % std::size(nm1);
    }
    }
    rnd5 = rng() % std::size(nm3);
    names = nm2[rnd] + nm1[rnd2] + nm3[rnd5] + nm1[rnd4] + nm4[rnd3];
    } else {
    rnd4 = rng() % std::size(nm1);
    if (rnd < 3) {
    while (rnd4 < 3) {
    rnd4 = rng() % std::size(nm1);
    }
    }
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm1);
    if (rnd < 3 || rnd4 < 3) {
    while (rnd6 < 3) {
    rnd6 = rng() % std::size(nm1);
    }
    }
    rnd7 = rng() % std::size(nm3);
    names = nm2[rnd] + nm1[rnd2] + nm3[rnd5] + nm1[rnd4] + nm3[rnd7] + nm1[rnd6] + nm4[rnd3];
    }
    }
    return names;
    }
}
