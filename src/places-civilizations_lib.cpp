#include "places-civilizations_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_civilizations_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "", "", "", "", "", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "br", "cr", "dr", "fr", "gr", "kr", "pr", "sr", "tr", "vr", "wr", "str", "st", "bl", "cl", "fl", "gl", "kl", "sl", "vl", "ch", "ph", "sh", "sch", "gn", "kn", "sn", "sm", "sw", "tw", "sc", "wh", "th", "thr", "sph", "spr"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ee", "eu", "eo", "ea", "ei", "aa", "ai", "au", "ae", "io", "ia", "iu", "ie", "oo", "oa", "ou", "oe", "oi", "uu", "ua", "ue", "ui", "uo"};
    static constexpr std::string_view nm4[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "t", "w", "z"};
    static constexpr std::string_view nm5[] = {"", "", "", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "w", "z"};
    static constexpr std::string_view nm6[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "t", "w", "z", "bb", "cc", "ch", "ck", "cq", "cr", "cs", "ct", "cth", "cz", "dd", "dg", "dh", "dn", "dr", "fd", "ff", "fk", "fl", "fn", "fr", "gb", "gg", "gh", "gm", "gn", "gr", "hg", "hh", "hk", "hm", "hn", "hq", "hr", "kd", "kh", "kk", "kl", "kn", "kr", "ks", "ksh", "kt", "kth", "kz", "lb", "lc", "ld", "lf", "lg", "lh", "lk", "ll", "lm", "ln", "lp", "lph", "lq", "lr", "ls", "lsh", "lst", "lt", "lth", "lw", "lz", "mb", "md", "mh", "mk", "ml", "mm", "mn", "mp", "mph", "mq", "mr", "ms", "msh", "mt", "mth", "mst", "mz", "nb", "nc", "nd", "nf", "ng", "nh", "nk", "nl", "nm", "nn", "np", "nph", "nq", "nr", "ns", "nsh", "nst", "nt", "nth", "nw", "nz", "ph", "pm", "pn", "pp", "pq", "pr", "phr", "phl", "phm", "phn", "pth", "pt", "ps", "pz", "rb", "rc", "rd", "rf", "rg", "rh", "rk", "rl", "rm", "rn", "rp", "rph", "rq", "rr", "rs", "rsh", "rst", "rt", "rth", "rw", "rz", "sb", "sc", "sd", "sh", "sk", "sl", "sm", "sn", "sp", "sph", "sr", "ss", "st", "str", "sth", "sz", "th", "tl", "tm", "tn", "tr", "thr", "thn", "thm", "tch"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "", "", "", "", "c", "g", "h", "k", "l", "ll", "m", "n", "nd", "q", "r", "s", "sh", "t", "th", "x"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    if (i < 3) {
    rnd2 = rng() % std::size(nm5);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm7);
    names = nm5[rnd2] + nm3[rnd3] + nm4[rnd4] + nm3[rnd5] + nm7[rnd6];
    } else if (i < 6) {
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm7);
    names = nm1[rnd] + nm3[rnd2] + nm6[rnd3] + nm3[rnd4] + nm7[rnd5];
    } else if (i < 8) {
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm7);
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd3] + nm5[rnd4] + nm3[rnd5] + nm7[rnd6];
    } else {
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm7);
    while (rnd5 < 8) {
    rnd5 = rng() % std::size(nm7);
    }
    rnd6 = rng() % std::size(nm3);
    names = nm1[rnd] + nm3[rnd2] + nm6[rnd3] + nm3[rnd4] + nm7[rnd5] + nm3[rnd6];
    }
    return names;
    }
}
