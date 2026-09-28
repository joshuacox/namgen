#include "star_wars-korunnais_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_korunnais_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "b", "br", "d", "g", "gr", "k", "l", "m", "n", "pr", "r", "s", "t", "th", "tr", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "io", "ii", "ou"};
    static constexpr std::string_view nm3[] = {"c", "d", "ff", "g", "k", "l", "ll", "mm", "n", "nn", "r", "rr", "s", "ss", "th", "v", "z"};
    static constexpr std::string_view nm4[] = {"c", "g", "k", "l", "m", "n", "r", "rz", "s", "sh", "th", "z"};
    static constexpr std::string_view nm5[] = {"d", "dh", "f", "g", "h", "k", "l", "m", "n", "r", "s", "sh", "t", "th", "w", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ia", "ie", "ea", "ae", "eo"};
    static constexpr std::string_view nm7[] = {"c", "dd", "f", "ff", "g", "h", "l", "ll", "m", "mm", "n", "nn", "r", "rr", "s", "ss", "sh", "t", "th", "v", "w", "z"};
    static constexpr std::string_view nm9[] = {"d", "g", "gr", "h", "l", "m", "n", "r", "s", "t", "th", "tr", "v", "w", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm11[] = {"dd", "dn", "dl", "fn", "fl", "fd", "gn", "gm", "gd", "gl", "gg", "hn", "hm", "hd", "hv", "ll", "ln", "ld", "lm", "lv", "mm", "mn", "md", "ml", "mv", "mt", "nd", "nn", "nv", "nl", "ng", "nd", "nf", "nt", "pt", "pp", "pn", "pm", "pd", "pt", "st", "ss", "sn", "sm", "tn", "tm", "tv", "vv", "vd", "vn", "vl", "vm"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "", "", "l", "m", "n", "r", "s"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd7 = 0; size_t rnd8 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm11);
    rnd11 = rng() % std::size(nm10);
    rnd12 = rng() % std::size(nm12);
    namelast = nm9[rnd7] + nm10[rnd8] + nm11[rnd10] + nm10[rnd11] + nm12[rnd12];
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + " " + namelast;
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    while (rnd < 4) {
    rnd = rng() % std::size(nm1);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + namelast;
    } else if (i < 8) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + "  " + namelast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    }
    }
    return names;
    }
}
