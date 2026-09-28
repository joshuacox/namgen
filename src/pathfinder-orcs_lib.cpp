#include "pathfinder-orcs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_orcs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "br", "c", "cr", "dr", "f", "gr", "h", "kr", "kz", "m", "n", "pr", "r", "t", "tr", "v", "vr"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"b", "br", "bd", "bz", "d", "dd", "dr", "dz", "g", "gh", "gr", "gn", "gz", "k", "kk", "kd", "kz", "kn", "l", "ld", "lkz", "ll", "lz", "lr", "lg", "lk", "m", "mg", "mz", "mr", "n", "ng", "nr", "nk", "r", "rd", "rk", "rn", "rr", "rg", "rz", "rv", "s", "sr", "sk", "sg", "sc", "v", "vr", "vk", "vz", "z", "zr", "zk", "zn", "zm", "zc"};
    static constexpr std::string_view nm4[] = {"", "", "", "ch", "g", "hn", "hk", "hm", "hd", "k", "kk", "lk", "lkk", "lt", "ld", "m", "n", "r", "rd", "rk", "rg", "rn", "sh", "sk", "t"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "b", "c", "ch", "d", "g", "gr", "f", "g", "gr", "k", "kr", "l", "m", "n", "r", "t", "tr", "v", "vr"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "ya", "oa", "ia", "ua"};
    static constexpr std::string_view nm7[] = {"b", "bb", "bg", "d", "dd", "dg", "dj", "dr", "ff", "gg", "gj", "gd", "gr", "gn", "gm", "hj", "hm", "hn", "hr", "k", "kd", "kb", "kr", "kk", "l", "lb", "lg", "llg", "ld", "lld", "lk", "lr", "llr", "m", "mr", "mj", "mg", "mk", "ng", "nj", "n", "nn", "nr", "r", "rg", "rj", "rr", "rv", "sgr", "sg", "sh", "sk", "z", "zn"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "c", "d", "g", "k", "m", "n", "ng", "s", "ss", "t"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "b", "br", "ch", "cr", "d", "dh", "f", "g", "gh", "gr", "k", "kr", "kh", "m", "n", "r", "t", "th", "v", "vh", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "uu", "aa", "ua"};
    static constexpr std::string_view nm11[] = {"d", "dd", "dr", "fr", "fn", "g", "gg", "gd", "gn", "gm", "gz", "hm", "hj", "hm", "k", "kk", "kd", "kn", "ld", "lb", "lk", "lz", "lg", "lk", "ll", "lr", "m", "mg", "mk", "n", "nn", "ng", "nr", "nk", "r", "rr", "rg", "rk", "rn", "rm", "rv", "sg", "ss", "s", "sr", "sk", "sn", "v", "vr", "vn", "vk", "z", "zk", "zn", "zm"};
    static constexpr std::string_view nm12[] = {"d", "hn", "hd", "k", "l", "m", "n", "r", "s", "sh", "t", "th"};

    std::string nameLast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd8 = rng() % std::size(nm9);
    rnd9 = rng() % std::size(nm10);
    rnd12 = rng() % std::size(nm12);
    if (i % 2 == 0) {
    while (rnd8 < 5) {
    rnd8 = rng() % std::size(nm9);
    }
    nameLast = nm9[rnd8] + nm10[rnd9] + nm12[rnd12];
    } else {
    rnd10 = rng() % std::size(nm11);
    rnd11 = rng() % std::size(nm10);
    nameLast = nm9[rnd8] + nm10[rnd9] + nm11[rnd10] + nm10[rnd11] + nm12[rnd12];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm8);
    if (i < 2) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm5);
    }
    while (rnd5 < 10) {
    rnd5 = rng() % std::size(nm8);
    }
    names = nm5[rnd] + nm2[rnd2] + nm8[rnd5] + " " + nameLast;
    } else if (i < 8) {
    names = nm5[rnd] + nm2[rnd2] + nm7[rnd3] + nm2[rnd4] + nm8[rnd5] + " " + nameLast;
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm2);
    names = nm5[rnd] + nm2[rnd2] + nm7[rnd3] + nm2[rnd4] + nm7[rnd6] + nm2[rnd7] + nm8[rnd5] + " " + nameLast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 3) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + " " + nameLast;
    } else {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + nameLast;
    }
    }
    return names;
    }
}
