#include "star_wars-weequays_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_weequays_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "br", "c", "ch", "d", "f", "g", "gr", "gw", "h", "j", "k", "kr", "l", "m", "n", "p", "pl", "pr", "q", "s", "sh", "t", "tr", "v", "w", "y"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "a", "o", "u", "ia", "ie", "ea", "ei", "ee", "aa", "ai"};
    static constexpr std::string_view nm3[] = {"-m", "-n", "-h", "-l", "-v", "b", "b-r", "bl", "b-d", "b-z", "d", "d-r", "d-z", "dl", "ds", "dd", "g", "g-r", "gg", "gr", "gd", "gl", "h", "j", "k-b", "k-r", "kd", "k-z", "kn", "kr", "kb", "km", "l", "ll", "ln", "m", "mb", "nm-b", "mr", "n-d", "nd", "nl", "nn", "ns", "r", "r-z", "r-b", "r-g", "r-d", "rg", "rr", "rs", "rt", "s-d", "s-b", "s-l", "s-g", "t", "tt", "v", "z"};
    static constexpr std::string_view nm3b[] = {"b", "bl", "d", "dl", "ds", "dd", "g", "gg", "gr", "gd", "gl", "h", "j", "kd", "kn", "kr", "kb", "km", "l", "ll", "ln", "m", "mb", "mr", "nd", "nl", "nn", "ns", "r", "rg", "rr", "rs", "rt", "t", "tt", "v", "z"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "bl", "c", "g", "h", "k", "kk", "l", "m", "mbl", "mm", "n", "nn", "r", "rb", "rg", "rk", "rm", "rs", "rt", "s", "sk", "t", "ts", "v", "wn", "y", "z"};
    static constexpr std::string_view nm5[] = {"b", "c", "f", "g", "h", "k", "p", "q", "r", "s", "t", "v", "x", "z"};
    static constexpr std::string_view nm6[] = {"a", "a", "e", "o", "i", "u", "o", "a", "a", "e", "o", "i", "u", "o", "a", "a", "e", "o", "i", "u", "o", "a", "a", "e", "o", "i", "u", "o", "a", "a", "e", "o", "i", "u", "o", "a", "e", "o", "i", "u", "o", "a", "ie", "ii", "ee", "ei"};
    static constexpr std::string_view nm7[] = {"c", "cr", "cn", "cm", "g", "gg", "gm", "gr", "gs", "h", "hm", "hn", "hr", "hs", "km", "kn", "kr", "kl", "ks", "l", "ll", "lm", "lk", "lc", "lr", "ls", "mk", "mr", "n", "mm", "m", "nn", "nd", "nk", "r", "rk", "rm", "rr", "s", "ss", "sk", "sm"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "c", "g", "h", "k", "l", "m", "n", "r", "s", "t", "x", "z"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "", "b", "bl", "br", "d", "dr", "dl", "f", "fr", "fl", "g", "gr", "gl", "gh", "k", "kr", "kl", "kh", "l", "m", "n", "r", "s", "sh", "st", "sv", "sw", "sl", "t", "th", "tr", "tl", "v", "vr", "vl"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "au", "ee", "ie", "ei", "oo"};
    static constexpr std::string_view nm11[] = {"bk", "b", "bb", "bg", "br", "d", "dd", "dk", "dr", "ff", "f", "fk", "g", "gr", "gg", "gl", "hn", "hm", "hk", "hl", "k", "kk", "kr", "kl", "kd", "kb", "l", "ls", "lm", "ld", "lg", "m", "mk", "mt", "mm", "nk", "nd", "ng", "nn", "nt", "r", "rk", "rs", "rt", "rtr", "s", "sk", "sr", "st", "str", "t", "tr"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "", "", "", "c", "d", "g", "k", "lq", "lk", "lc", "mk", "m", "mz", "n", "nk", "nd", "nc", "nz", "q", "r", "rd", "s", "sh", "sk", "x", "y"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm12);
    if (i % 2 != 0) {
    if (rnd7 < 6) {
    while (rnd10 < 8) {
    rnd10 = rng() % std::size(nm12);
    }
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
    if (i < 5) {
    while (rnd5 < 10) {
    rnd5 = rng() % std::size(nm8);
    }
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm7);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd4] + nm6[rnd3] + nm8[rnd5] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 4) {
    if (rnd < 5) {
    while (rnd5 < 4) {
    rnd5 = rng() % std::size(nm4);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + namelast;
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd5] + nm2[rnd6] + "  " + namelast;
    }
    }
    return names;
    }
}
