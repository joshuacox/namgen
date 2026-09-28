#include "wildstar-chuas_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_wildstar_chuas_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"b", "d", "f", "g", "j", "m", "n", "r", "sh", "t", "th", "v", "x", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ao", "oa", "ia", "ee", "ua"};
    static constexpr std::string_view nm3[] = {"br", "bn", "dr", "dh", "dg", "dz", "fr", "ff", "g", "gn", "gg", "gz", "gh", "j", "k", "kn", "kv", "kt", "kv", "kz", "lk", "lv", "lg", "ll", "n", "nn", "nk", "np", "nt", "nv", "m", "mm", "mk", "pp", "rr", "rg", "rsr", "rs", "rt", "rv", "rk", "sk", "ss", "sz", "sn", "sm", "t", "tt", "tk", "v", "vn"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "c", "h", "l", "ll", "n", "nn", "r", "rr", "s", "ss", "sh", "t", "th", "w", "x", "zz"};
    static constexpr std::string_view nm5[] = {"b", "br", "d", "dr", "f", "fr", "g", "gn", "gr", "j", "m", "n", "r", "s", "sh", "st", "t", "th", "tr", "v", "vr", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "", "", "", "c", "f", "h", "l", "ll", "m", "ms", "n", "ns", "nn", "r", "rr", "s", "ss", "sh", "t", "th", "x", "zz"};

    std::string lname; std::string name; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    if (i % 2 == 0) {
    while (rnd3 < 7) {
    rnd3 = rng() % std::size(nm7);
    }
    lname = nm5[rnd] + nm6[rnd2] + nm7[rnd3];
    } else {
    rnd4 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm6);
    lname = nm5[rnd] + nm6[rnd2] + nm3[rnd4] + nm6[rnd5] + nm7[rnd3];
    }
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    while (rnd5 < 7) {
    rnd5 = rng() % std::size(nm4);
    }
    name = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + " " + lname;
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    name = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + lname;
    }
    return name;
    }
}
