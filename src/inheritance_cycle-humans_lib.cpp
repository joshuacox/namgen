#include "inheritance_cycle-humans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_inheritance_cycle_humans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "b", "br", "c", "cl", "cr", "d", "dr", "f", "fl", "fr", "g", "gr", "h", "j", "k", "kn", "kr", "l", "m", "n", "p", "q", "r", "s", "sl", "sv", "t", "th", "tr", "v", "w", "y"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ie", "ae", "oo", "ai", "ea", "aa", "ei", "ui", "uo", "oa"};
    static constexpr std::string_view nm3[] = {"b", "br", "ch", "d", "db", "dg", "dl", "dr", "fr", "ft", "g", "gl", "gm", "h", "hw", "j", "k", "l", "lb", "lbr", "lc", "ld", "lf", "lh", "lk", "ll", "lm", "lr", "lst", "lt", "lw", "m", "mb", "mbl", "mpt", "n", "nbr", "nc", "nd", "nds", "ng", "ngr", "ngv", "ngw", "nn", "ns", "r", "rc", "rd", "rdl", "rdr", "rds", "rgr", "rk", "rm", "rmm", "rmn", "rn", "rr", "rs", "rsh", "rt", "rth", "rtl", "rtr", "rv", "rw", "rz", "s", "sb", "sl", "sth", "str", "stv", "t", "tch", "th", "thlb", "thm", "v", "vr", "w", "wl", "yn"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "c", "ch", "ck", "d", "f", "g", "gh", "l", "ld", "lf", "ll", "lt", "m", "mb", "n", "nd", "ng", "nt", "r", "rd", "rn", "rr", "rst", "rt", "rth", "s", "sk", "st", "t", "th", "w", "y"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "b", "br", "c", "d", "dr", "f", "fr", "g", "gr", "gl", "h", "j", "k", "kh", "l", "m", "n", "pr", "ph", "s", "sl", "sh", "sr", "t", "th", "tr", "w", "y"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ai", "ia", "ua", "ae", "ee", "ie", "ea"};
    static constexpr std::string_view nm7[] = {"bb", "br", "c", "d", "dd", "dn", "f", "ff", "fr", "fn", "gn", "g", "gg", "hr", "hn", "nl", "l", "ld", "ll", "lm", "ln", "lb", "ls", "lv", "m", "mm", "mn", "n", "ng", "nn", "nm", "nd", "nw", "ns", "p", "ph", "r", "rd", "rn", "rl", "rm", "rr", "rs", "rw", "rg", "rtr", "s", "sn", "sl", "sh", "sm", "ss", "t", "th", "tr", "tn", "v", "w"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "l", "ld", "n", "s", "t"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (rnd5 < 5) {
    rnd4 = 0;
    }
    if (i < 6) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5];
    } else {
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd6] + nm7[rnd7] + nm6[rnd4] + nm8[rnd5];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm4);
    if (i < 3) {
    if (rnd < 4) {
    while (rnd4 < 5) {
    rnd4 = rng() % std::size(nm4);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd4];
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm4[rnd4];
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm3[rnd6] + nm2[rnd7] + nm4[rnd4];
    }
    }
    return names;
    }
}
