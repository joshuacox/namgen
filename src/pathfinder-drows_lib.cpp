#include "pathfinder-drows_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_drows_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "br", "bh", "c", "dh", "dr", "f", "g", "gr", "gh", "j", "k", "kr", "kh", "m", "n", "ph", "q", "r", "s", "t", "v", "w", "x", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "y", "y", "io", "ae", "ou", "ie", "ui", "yi", "ey"};
    static constexpr std::string_view nm3[] = {"bn", "bs", "bz", "c", "cn", "cm", "cr", "dr", "dn", "g", "gn", "gv", "gg", "k", "kr", "kz", "kn", "kq", "l", "lf", "lm", "lr", "lq", "lc", "lv", "m", "mm", "mr", "mz", "ml", "mdr", "n", "ndr", "nd", "nz", "nc", "nq", "r", "rc", "rn", "rr", "rz", "rdr", "rq", "t", "tr", "v", "vr", "vdr"};
    static constexpr std::string_view nm4[] = {"", "", "", "c", "d", "g", "n", "r", "rn", "ss", "v", "x"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "b", "c", "d", "f", "g", "h", "j", "l", "m", "n", "p", "ph", "q", "r", "s", "sc", "t", "th", "tr", "v", "w", "x", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "ia", "ae", "ie", "ei", "ya", "ee", "ai"};
    static constexpr std::string_view nm7[] = {"b", "b", "b", "bv", "br", "c", "c", "c", "cr", "cs", "cn", "d", "d", "d", "dr", "dh", "dv", "fr", "h", "h", "h", "kr", "kn", "kl", "kv", "ksh", "l", "l", "l", "ll", "ll", "lm", "lv", "lr", "lq", "lsh", "mbr", "mr", "mv", "n", "n", "n", "nn", "nd", "nsh", "ns", "nz", "nv", "nr", "p", "p", "p", "ph", "phr", "r", "r", "r", "rn", "rsh", "rq", "s", "s", "s", "ss", "sh", "shr", "sc", "str", "v", "v", "vvn", "vr"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "h", "l", "n", "nth", "s", "ss"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "b", "c", "d", "g", "j", "k", "m", "n", "p", "q", "r", "s", "shr", "t", "th", "v", "w", "x", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "y", "y", "y", "ae", "iu", "ei", "ie", "ia", "ai", "ee"};
    static constexpr std::string_view nm11[] = {"d", "dr", "g", "gn", "gr", "ld", "lr", "ldr", "lv", "lz", "m", "mr", "n", "nd", "nn", "ng", "nr", "ndr", "nz", "nvr", "r", "rq", "rdr", "rz", "rv", "s", "sr", "shr", "str", "vr", "vn", "x", "xr", "zr", "z"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "c", "d", "h", "n", "rc", "s", "sh", "t", "th", "v", "x"};

    std::string nameLast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd10 = rng() % std::size(nm9);
    rnd11 = rng() % std::size(nm10);
    rnd12 = rng() % std::size(nm12);
    rnd13 = rng() % std::size(nm11);
    rnd14 = rng() % std::size(nm10);
    if (i % 2 == 0) {
    rnd15 = rng() % std::size(nm11);
    rnd16 = rng() % std::size(nm10);
    nameLast = nm9[rnd10] + nm10[rnd11] + nm11[rnd13] + nm10[rnd14] + nm11[rnd15] + nm10[rnd16] + nm12[rnd12];
    } else {
    nameLast = nm9[rnd10] + nm10[rnd11] + nm11[rnd13] + nm10[rnd14] + nm12[rnd12];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 4) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + " " + nameLast;
    } else if (i < 8) {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm8[rnd5] + " " + nameLast;
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    rnd8 = rng() % std::size(nm7);
    rnd9 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm7[rnd8] + nm6[rnd9] + nm8[rnd5] + " " + nameLast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 2) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 3) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + nameLast;
    } else if (i < 7) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + nameLast;
    } else {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + " " + nameLast;
    }
    }
    return names;
    }
}
