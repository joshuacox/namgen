#include "miscellaneous-languages_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_languages_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "bh", "bl", "br", "ch", "cl", "cr", "cy", "dh", "dr", "fh", "fl", "fr", "gh", "gn", "gl", "gr", "kh", "kl", "kn", "kr", "mh", "my", "nh", "ph", "pl", "pr", "pn", "rh", "sc", "sh", "sl", "sm", "sn", "sp", "sr", "st", "str", "th", "tr", "ty", "vh", "wh", "zh", };
    static constexpr std::string_view nm2[] = {"a", "e", "o", "i", "u", "a", "e", "o", "i", "u", "a", "e", "o", "i", "u", "a", "e", "o", "i", "u", "ae", "ao", "ai", "au", "ea", "eo", "ei", "eu", "oa", "oe", "oi", "ou", "ia", "ie", "io", "iu", "ua", "ue", "uo", "ui", "aa", "ee", "oo", "uu"};
    static constexpr std::string_view nm3[] = {"b", "c", "d", "f", "g", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "bb", "cc", "dd", "ff", "gg", "kk", "ll", "mm", "nn", "pp", "rr", "ss", "tt", "ww", "zz", "cb", "lb", "nb", "bd", "zb", "cd", "gd", "ld", "md", "nd", "sd", "rd", "zd", "lf", "mf", "nf", "sf", "tf", "lg", "mg", "ng", "rg", "sg", "zg", "yg", "ck", "lk", "mk", "str", "nk", "sk", "tk", "zk", "fl", "gl", "kl", "pl", "sl", "tl", "dm", "fm", "gm", "km", "lm", "nm", "sm", "tm", "xm", "zm", "yn", "dn", "fn", "gn", "kn", "mn", "pn", "sn", "tn", "xn", "zn", "np", "sp", "tp", "xp", "fr", "gr", "kr", "pr", "tr", "gs", "ks", "ls", "ms", "ns", "ps", "ts", "xs", "ct", "kt", "lt", "mt", "nt", "pt", "rt", "st", "xt", "yt"};
    static constexpr std::string_view nm4[] = {"abi", "ada", "ali", "an", "esh", "ash", "ani", "ano", "arhi", "ari", "aric", "arin", "asy", "athi", "ati", "ean", "ekhi", "eno", "eesh", "ese", "esh", "ethi", "eti", "ian", "ic", "ili", "in", "ina", "ish", "iya", "oshi", "oni", "osa", "uin", "un", "uni", "uri"};

    std::string name; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (i < 3) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    name = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4];
    } else if (i < 6) {
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    name = nm2[rnd2] + nm3[rnd3] + nm4[rnd4];
    } else if (i < 8) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    if (rnd2 > 19) {
    while (rnd4 > 19) {
    rnd4 = rng() % std::size(nm2);
    }
    }
    rnd5 = rng() % std::size(nm3);
    if (rnd3 > 80) {
    while (rnd5 > 80) {
    rnd5 = rng() % std::size(nm3);
    }
    }
    rnd6 = rng() % std::size(nm4);
    name = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd5] + nm4[rnd6];
    } else {
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    if (rnd2 > 19) {
    while (rnd4 > 19) {
    rnd4 = rng() % std::size(nm2);
    }
    }
    rnd5 = rng() % std::size(nm3);
    if (rnd3 > 80) {
    while (rnd5 > 80) {
    rnd5 = rng() % std::size(nm3);
    }
    }
    rnd6 = rng() % std::size(nm4);
    name = nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd5] + nm4[rnd6];
    }
    return name;
    }
}
