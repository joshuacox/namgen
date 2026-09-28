#include "fantasy-nagas_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_nagas_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "ch", "d", "dh", "dhr", "h", "hr", "j", "jy", "k", "kh", "kr", "ksh", "l", "m", "n", "p", "pr", "s", "sr", "t", "v", "vr"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "a", "a", "a", "a", "a", "i", "i"};
    static constexpr std::string_view nm3[] = {"bh", "d", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "y", "bh", "d", "dg", "dh", "dhy", "dm", "dr", "g", "h", "hl", "hy", "j", "k", "kh", "ksh", "ky", "l", "lm", "lw", "m", "mkh", "mv", "mvr", "n", "nd", "ndh", "ng", "nj", "nkh", "nm", "nshtr", "nt", "nth", "p", "pt", "r", "rd", "rk", "rm", "rn", "rt", "ry", "s", "sh", "shk", "shm", "shn", "shp", "shth", "shtr", "sr", "st", "sth", "sw", "t", "th", "tr", "tt", "ttr", "ty", "v", "vy", "y", "yl"};
    static constexpr std::string_view nm4[] = {"a", "a", "a", "a", "a", "a", "a", "a", "a", "i", "u", "as", "at"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "", "", "", "", "c", "cr", "ch", "d", "h", "k", "kr", "kh", "l", "r", "s", "s", "s", "sh", "sz", "sc", "sy", "sz", "sh", "t", "th", "x", "y", "z", "zs", "zh"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "aa", "ai", "ee", "ei", "ie"};
    static constexpr std::string_view nm7[] = {"c", "d", "dh", "k", "kh", "l", "r", "s", "sh", "t", "th", "x", "xh", "z", "zh", "c", "d", "k", "l", "r", "s", "t", "x", "z", "c", "d", "k", "l", "r", "s", "t", "x", "z", "s", "s", "sh", "sh", "cc", "ch", "ck", "cs", "csh", "cz", "dh", "dj", "kk", "kh", "ks", "ksh", "kz", "ll", "lh", "lz", "ls", "rr", "rc", "rg", "rh", "rj", "rs", "rsh", "rz", "rsz", "rt", "rth", "rc", "rk", "ss", "sc", "sh", "sk", "sz", "sy", "th", "tr", "ts", "tz", "tsh", "xh", "xs", "xz", "zh", "zs", "zz", "zs"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "", "kh", "l", "r", "s", "sj", "ss", "sh", "sz", "t", "th", "x", "z", "zs"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 2) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5];
    } else if (i < 4) {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd7] + nm7[rnd6] + nm6[rnd4] + nm8[rnd5];
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    if (i < 7) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4];
    } else if (i < 9) {
    rnd5 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm3[rnd6] + nm4[rnd4];
    } else {
    rnd5 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm3);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm3[rnd6] + nm2[rnd7] + nm3[rnd8] + nm4[rnd4];
    }
    }
    return names;
    }
}
