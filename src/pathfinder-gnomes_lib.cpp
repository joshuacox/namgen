#include "pathfinder-gnomes_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_gnomes_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "b", "br", "c", "ch", "d", "dr", "f", "g", "gr", "h", "k", "kr", "n", "p", "q", "r", "shm", "t", "tr", "v", "vr", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ie", "iu", "ou", "ee", "uo", "ua"};
    static constexpr std::string_view nm3[] = {"b", "b", "b", "br", "bn", "ck", "cr", "cd", "dp", "dq", "dw", "k", "k", "k", "kq", "kr", "kw", "l", "l", "l", "ll", "ll", "lm", "lz", "lb", "ld", "m", "m", "m", "mb", "mz", "n", "n", "n", "nn", "nd", "ndr", "ng", "nt", "nz", "nq", "p", "p", "p", "pq", "pr", "r", "r", "r", "rgr", "rn", "rw", "rz", "shm", "sht", "sn", "st", "t", "t", "t", "th", "tq", "tr", "v", "v", "v", "z", "z", "z", "zz", "zn"};
    static constexpr std::string_view nm4[] = {"", "", "", "ck", "d", "m", "n", "nt", "r", "rd", "s", "st", "t", "tt", "x"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "b", "d", "f", "g", "h", "l", "m", "n", "p", "q", "r", "s", "sn", "t", "tr", "y", "v", "w", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ue", "io", "ie", "ia", "ai"};
    static constexpr std::string_view nm7[] = {"b", "b", "b", "b", "bl", "c", "c", "c", "c", "d", "d", "d", "f", "f", "f", "ff", "ff", "fl", "fn", "fr", "fl", "g", "g", "g", "g", "gn", "gg", "h", "h", "h", "hh", "hh", "j", "j", "j", "k", "k", "k", "k", "kn", "kz", "l", "l", "l", "l", "l", "lm", "ln", "lz", "lb", "lf", "m", "m", "m", "m", "mm", "mm", "mz", "ml", "mb", "mp", "n", "n", "n", "n", "nn", "nk", "np", "nz", "nl", "ns", "nk", "p", "p", "p", "p", "ph", "pr", "pn", "r", "r", "r", "r", "rz", "rl", "rs", "rr", "s", "s", "s", "s", "sh", "sl", "sn", "sm", "t", "t", "t", "th", "thr", "tr", "v", "v", "v", "vr", "vl", "vn", "x", "x", "x", "z", "z", "z", "z", "zz", "zn", "zl"};
    static constexpr std::string_view nm8[] = {"ck", "g", "m", "n", "s", "sh", "t", "th"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "b", "bl", "ch", "d", "f", "fr", "g", "gl", "gr", "h", "j", "k", "kl", "kr", "m", "n", "p", "q", "qr", "r", "s", "sh", "t", "th", "v", "w", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "aa", "ee", "ae", "oo", "ie", "ua", "uo", "io", "ia"};
    static constexpr std::string_view nm11[] = {"b", "bbl", "bl", "br", "c", "cl", "cn", "d", "ddl", "dl", "dn", "dr", "df", "gn", "g", "gl", "ggl", "gw", "l", "lp", "lf", "lb", "ld", "ldr", "lm", "ln", "ll", "m", "mb", "nd", "n", "nc", "ngn", "ns", "nt", "nz", "p", "pl", "pp", "ppl", "pr", "pn", "psw", "r", "rl", "rnd", "rnf", "sn", "tr", "th", "tl", "ttl", "v", "vr", "w", "wl", "z", "zb", "zl"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "b", "bs", "d", "ck", "cks", "g", "h", "m", "ms", "n", "ng", "r", "sp", "ss", "st", "th"};

    std::string nameLast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd10 = rng() % std::size(nm9);
    rnd11 = rng() % std::size(nm10);
    rnd12 = rng() % std::size(nm12);
    if (i % 3 == 0 && i % 2 != 0) {
    rnd13 = rng() % std::size(nm11);
    rnd14 = rng() % std::size(nm10);
    nameLast = nm9[rnd10] + nm10[rnd11] + nm11[rnd13] + nm10[rnd14] + nm12[rnd12];
    } else if (i % 2 == 0) {
    rnd13 = rng() % std::size(nm11);
    rnd14 = rng() % std::size(nm10);
    rnd15 = rng() % std::size(nm11);
    rnd16 = rng() % std::size(nm10);
    nameLast = nm9[rnd10] + nm10[rnd11] + nm11[rnd13] + nm10[rnd14] + nm11[rnd15] + nm10[rnd16] + nm12[rnd12];
    } else {
    while (rnd10 < 5) {
    rnd10 = rng() % std::size(nm9);
    }
    while (rnd12 < 5) {
    rnd12 = rng() % std::size(nm12);
    }
    nameLast = nm9[rnd10] + nm10[rnd11] + nm12[rnd12];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 4) {
    while (rnd < 4) {
    rnd = rng() % std::size(nm5);
    }
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd5] + " " + nameLast;
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + " " + nameLast;
    } else if (i < 9) {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm8[rnd5] + " " + nameLast;
    } else {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    rnd8 = rng() % std::size(nm7);
    rnd9 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm7[rnd8] + nm6[rnd9] + nm8[rnd5] + " " + nameLast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 3) {
    while (rnd < 4) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 3) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + nameLast;
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + nameLast;
    } else if (i < 9) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + " " + nameLast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm3);
    rnd9 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm3[rnd8] + nm2[rnd9] + nm4[rnd5] + " " + nameLast;
    }
    }
    return names;
    }
}
