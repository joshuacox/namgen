#include "star_wars-gamorreans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_gamorreans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "bl", "bn", "br", "c", "d", "dr", "g", "gh", "gl", "gr", "grr", "grt", "h", "j", "k", "kl", "kr", "l", "m", "n", "p", "r", "sc", "sh", "sl", "sn", "sq", "st", "t", "th", "tr", "v", "vr", "w", "x", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ea", "eu", "au", "ee", "oo", "uu", "ou", "ua"};
    static constexpr std::string_view nm3[] = {"b", "bn", "br", "d", "dbr", "fn", "g", "gb", "ggt", "gh", "gl", "gn", "gr", "gt", "gz", "kt", "l", "lg", "ll", "lr", "m", "mb", "mm", "mr", "n", "nf", "ngf", "nt", "nth", "r", "rg", "rk", "rl", "rm", "rn", "rt", "sh", "ss", "t", "th", "thm", "v", "zz"};
    static constexpr std::string_view nm4[] = {"b", "c", "ck", "ckt", "f", "ff", "g", "gg", "gh", "k", "kk", "l", "lk", "m", "n", "ng", "nn", "nt", "r", "rc", "rg", "rk", "rn", "rp", "rrp", "rrt", "rt", "rth", "s", "ss", "t", "th", "tt", "z"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "", "", "b", "bl", "bn", "br", "c", "d", "dr", "g", "gh", "gl", "gr", "grr", "grt", "h", "j", "k", "kl", "kr", "l", "m", "n", "p", "r", "sc", "sh", "sl", "sn", "sq", "st", "t", "th", "tr", "v", "vr", "w", "x", "z"};
    static constexpr std::string_view nm6[] = {"b", "bn", "br", "d", "dv", "fbr", "fn", "g", "gb", "gg", "gh", "gl", "gm", "gn", "gr", "gsh", "gv", "km", "l", "ll", "lly", "ln", "lr", "m", "mm", "mr", "mv", "n", "ndr", "nf", "ng", "nr", "nth", "r", "rg", "rk", "rl", "rm", "rn", "rr", "shr", "sn", "sr", "t", "th", "thn", "tr", "vn", "zs"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "b", "c", "cz", "cs", "f", "ff", "g", "gg", "gh", "k", "ks", "l", "ms", "m", "n", "ns", "nn", "ng", "r", "rc", "rf", "rn", "rq", "rs", "rr", "rm", "rth", "s", "ss", "t", "th", "sh", "sz", "z"};
    static constexpr std::string_view nm8[] = {"b", "bn", "br", "d", "dbr", "dv", "fbr", "fn", "g", "gb", "gg", "ggt", "gh", "gl", "gm", "gn", "gr", "gsh", "gt", "gv", "gz", "km", "kt", "l", "lg", "ll", "lly", "ln", "lr", "m", "mb", "mm", "mr", "mv", "n", "ndr", "nf", "ng", "ngf", "nr", "nt", "nth", "r", "rg", "rk", "rl", "rm", "rn", "rr", "rt", "sh", "shr", "sn", "sr", "ss", "t", "th", "thm", "thn", "tr", "v", "vn", "zs", "zz"};
    static constexpr std::string_view nm9[] = {"b", "c", "ck", "ckt", "cs", "cz", "f", "ff", "g", "gg", "gh", "k", "kk", "ks", "l", "lk", "m", "ms", "n", "ng", "nn", "ns", "nt", "r", "rc", "rf", "rg", "rk", "rm", "rn", "rp", "rq", "rr", "rrp", "rrt", "rs", "rt", "rth", "s", "sh", "ss", "sz", "t", "th", "tt", "z"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm1);
    rnd7 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm9);
    if (i % 2 == 0) {
    namelast = nm1[rnd6] + nm2[rnd7] + nm9[rnd8];
    } else {
    rnd9 = rng() % std::size(nm8);
    rnd11 = rng() % std::size(nm2);
    namelast = nm1[rnd6] + nm2[rnd7] + nm8[rnd9] + nm2[rnd11] + nm9[rnd8];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm7);
    rnd3 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm2);
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3] + nm2[rnd5] + nm7[rnd4] + "  " + namelast;
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm4);
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd4] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm4[rnd4] + "  " + namelast;
    }
    }
    return names;
    }
}
