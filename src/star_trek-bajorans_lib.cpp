#include "star_trek-bajorans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_bajorans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "ch", "sh", "br", "pr", "tr", "dr", "kr", "vr", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "aa", "ee"};
    static constexpr std::string_view nm3[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "nj", "mj", "nt", "mt", "ct", "kt", "ny", "cy", "gy", "ky", "my", "py", "sy", "ty", "ry", "rm", "rb", "rc", "rd", "rj", "rk", "rm", "rn", "rp", "rs", "rt", "rv", "rw", "rz", "sh", "ch", "th", "ll", "dd", "gg", "kk", "rr", "zk", "sk", "lk", "tk", "tr", "dr"};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm5[] = {"n", "ld", "k", "s", "r", "sh", "t", "m", "lb", "hl", "l", "d", "ld", "g", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm6[] = {"b", "ch", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "kr", "tr", "rh", "sh", "", "", "", ""};
    static constexpr std::string_view nm7[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ai", "aie", "ue", "oa", "aa", "ee"};
    static constexpr std::string_view nm8[] = {"b", "c", "d", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "b", "c", "d", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "ln", "lb", "lz", "lg", "lk", "ltr", "zk", "zd", "rk", "rd", "rg", "rn", "rt", "yr", "yd", "mm", "rr", "ss", "nn", "tt", "br", "kr", "gd", "nd", "nt"};
    static constexpr std::string_view nm9[] = {"m", "s", "r", "n", "g", "l", "th", "rn", "c"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm11[] = {"b", "bl", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "w", "x", "y", "z", "gr", "gl", "sh", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm12[] = {"a", "e", "i", "a", "e", "i", "o", "o", "u", "ee", "ai", "oa"};
    static constexpr std::string_view nm13[] = {"b", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "w", "x", "y", "z", "sh", "pr", "rd", "lr", "gh", "rj", "lk"};
    static constexpr std::string_view nm14[] = {"a", "e", "i", "o", "a", "e", "u", "a", "e", "i", "o", "ia", "ea"};
    static constexpr std::string_view nm15[] = {"h", "l", "m", "n", "r", "s", "t", "w", "y", "z"};
    static constexpr std::string_view nm16[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "ia", "ea", "", "", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    if (i < 5) {
    rnd6 = rng() % std::size(nm11);
    rnd7 = rng() % std::size(nm12);
    rnd8 = rng() % std::size(nm13);
    rnd9 = rng() % std::size(nm14);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + " " + nm11[rnd6] + nm12[rnd7] + nm13[rnd8] + nm14[rnd9];
    } else {
    rnd6 = rng() % std::size(nm11);
    rnd7 = rng() % std::size(nm12);
    rnd8 = rng() % std::size(nm13);
    rnd9 = rng() % std::size(nm14);
    rnd10 = rng() % std::size(nm15);
    rnd11 = rng() % std::size(nm16);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + " " + nm11[rnd6] + nm12[rnd7] + nm13[rnd8] + nm14[rnd9] + nm15[rnd10] + nm16[rnd11];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    if (i < 5) {
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    rnd9 = rng() % std::size(nm10);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + " " + nm6[rnd6] + nm7[rnd7] + nm8[rnd8] + nm10[rnd9];
    } else {
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    rnd9 = rng() % std::size(nm4);
    rnd10 = rng() % std::size(nm9);
    rnd11 = rng() % std::size(nm10);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + " " + nm6[rnd6] + nm7[rnd7] + nm8[rnd8] + nm4[rnd9] + nm9[rnd10] + nm10[rnd11];
    }
    }
    return names;
    }
}
