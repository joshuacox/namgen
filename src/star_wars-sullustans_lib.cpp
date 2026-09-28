#include "star_wars-sullustans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_sullustans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "b", "bl", "br", "c", "d", "dl", "dw", "f", "fr", "g", "gr", "h", "j", "k", "kr", "l", "m", "n", "p", "q", "r", "s", "t", "tr", "v", "w", "x", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "au", "eo", "ie", "uu", "ea", "ee", "ia", "ao", "ue", "ae", "ay", "y", "ii", "ei", "iu", "ui", "oo", "ua", "yu"};
    static constexpr std::string_view nm3[] = {"b", "bb", "br", "d", "dm", "fr", "g", "ggl", "gl", "hs", "j", "kk", "l", "ll", "llr", "lth", "m", "md", "n", "nb", "nch", "nd", "ng", "nn", "nr", "pl", "r", "rg", "rk", "rl", "rn", "rr", "rth", "rw", "shr", "ss", "st", "t", "th", "w", "xt", "z"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "b", "bb", "c", "d", "dt", "gg", "k", "kk", "l", "ld", "lld", "ln", "lss", "m", "n", "nb", "nt", "pt", "r", "rm", "rs", "rt", "s", "sh", "ss", "t", "tz", "v", "vv", "x"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "", "", "", "", "b", "ch", "d", "f", "fr", "g", "h", "j", "k", "l", "m", "n", "r", "s", "t", "tr", "v", "w", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ia", "ee", "uo", "ee", "aa", "uu", "ae", "ya", "yu"};
    static constexpr std::string_view nm7[] = {"b", "bb", "f", "ff", "fr", "gr", "gg", "gl", "hl", "hn", "hm", "l", "ll", "lb", "lm", "ln", "ld", "m", "md", "mb", "ml", "mm", "n", "nb", "nm", "ng", "nd", "p", "pp", "r", "rr", "rb", "rd", "rl", "rn", "s", "st", "sth", "sd", "sh", "ss", "t", "th", "tt", "vv"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "l", "n", "nn", "r", "s", "ss", "th", "v", "x"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "b", "bd", "br", "f", "fr", "g", "gh", "h", "j", "k", "l", "m", "n", "nh", "nr", "p", "pl", "r", "s", "sch", "sn", "sq", "st", "sw", "t", "ts", "v", "vh", "w", "y", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "ia", "ie", "ei", "oo", "ee", "uu", "aa", "au", "ya", "ea", "ii", "iu", "ua"};
    static constexpr std::string_view nm11[] = {"b", "bb", "bbb", "d", "g", "gg", "gn", "hnt", "j", "kk", "l", "lk", "ll", "m", "mb", "mbl", "n", "nd", "ng", "nr", "ns", "ntr", "r", "rb", "rr", "rt", "rt", "s", "sc", "st", "tt", "v", "vn", "wn"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "b", "bb", "bbs", "bl", "c", "cb", "d", "h", "k", "l", "ll", "ls", "m", "mb", "mm", "mp", "n", "nb", "nd", "nn", "nr", "nt", "p", "pt", "r", "rb", "rl", "rr", "rs", "rss", "s", "st", "t", "th", "v", "vv", "wn", "z"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm12);
    if (i % 2 != 0) {
    while (rnd10 < 15) {
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
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm8[rnd5] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    while (rnd < 6) {
    rnd = rng() % std::size(nm1);
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
