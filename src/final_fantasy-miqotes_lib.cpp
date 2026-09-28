#include "final_fantasy-miqotes_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_final_fantasy_miqotes_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"A'", "B'", "C'", "D'", "E'", "F'", "G'", "H'", "I'", "J'", "K'", "L'", "M'", "N'", "O'", "P'", "Q'", "R'", "S'", "T'", "U'", "V'", "W'", "X'", "Y'", "Z'"};
    static constexpr std::string_view nm2[] = {"b", "c", "d", "f", "g", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z"};
    static constexpr std::string_view nm3[] = {"a", "e", "o", "i", "u"};
    static constexpr std::string_view nm4[] = {"", "", "", "a", "e", "o", "i", "u"};
    static constexpr std::string_view nm5[] = {"", "h"};
    static constexpr std::string_view nm6[] = {"b", "c", "d", "f", "g", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "bb", "cc", "dd", "ff", "gg", "kk", "ll", "mm", "nn", "pp", "rr", "ss", "tt", "ww", "zz", "cb", "gb", "lb", "mb", "nb", "rb", "bd", "cd", "gd", "ld", "md", "nd", "sd", "rd", "bf", "df", "kf", "lf", "mf", "nf", "pf", "rf", "sf", "tf", "bg", "dg", "lg", "mg", "ng", "rg", "sg", "ck", "lk", "mk", "nk", "pk", "rk", "sk", "tk", "bl", "dl", "fl", "gl", "kl", "ml", "nl", "pl", "rl", "sl", "tl", "bm", "dm", "fm", "gm", "km", "lm", "nm", "pm", "rm", "sm", "tm", "bn", "dn", "fn", "gn", "kn", "mn", "ln", "pn", "rn", "sn", "tn", "br", "cr", "dr", "fr", "gr", "kr", "lr", "mr", "nr", "pr", "sr", "tr", "vr", "wr", "zr", "bs", "cs", "ds", "fs", "gs", "ks", "ls", "ms", "ns", "ps", "rs", "ts", "bt", "ct", "kt", "lt", "mt", "nt", "pt", "rt", "st", "by", "cy", "dy", "fy", "gy", "ky", "ly", "my", "ny", "py", "ry", "sy", "ty"};
    static constexpr std::string_view nm7[] = {"ei", "au", "aa", "ee", "oo", "aia", "a", "e", "o", "i", "u", "a", "e", "o", "i", "u", "a", "e", "o", "i", "u", "a", "e", "o", "i", "u", "a", "e", "o", "i", "u"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "b", "c", "d", "f", "g", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "b", "c", "d", "f", "g", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z"};
    static constexpr std::string_view nm10[] = {"", "a", "e", "o", "i", "u"};
    static constexpr std::string_view nm11[] = {"'a", "'to", "'li", "'sae", "'ra", "'ir", "'wo", "'ya", "'zi", "'tan"};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd17 = 0; size_t rnd18 = 0; size_t rnd19 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd10 = rng() % std::size(nm2);
    rnd11 = rng() % std::size(nm5);
    rnd12 = rng() % std::size(nm7);
    rnd13 = rng() % std::size(nm6);
    rnd14 = rng() % std::size(nm5);
    if (rnd11 == 1) {
    rnd14 = 0;
    }
    rnd15 = rng() % std::size(nm7);
    if (rnd12 < 6) {
    while (rnd15 < 6) {
    rnd15 = rng() % std::size(nm7);
    }
    }
    rnd16 = rng() % std::size(nm9);
    rnd17 = rng() % std::size(nm5);
    if (rnd11 == 1 || rnd14 == 1) {
    rnd17 = 0;
    }
    rnd18 = rng() % std::size(nm10);
    if (rnd16 < 16) {
    rnd17 = 0;
    rnd18 = 0;
    } else {
    while (rnd18 == 0) {
    rnd18 = rng() % std::size(nm10);
    }
    }
    rnd19 = rng() % std::size(nm11);
    names = nm1[rnd] + nm6[rnd10] + nm5[rnd11] + nm7[rnd12] + nm6[rnd13] + nm5[rnd14] + nm7[rnd15] + nm9[rnd16] + nm5[rnd17] + nm10[rnd18];
    } else {
    rnd2 = rng() % std::size(nm8);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm5);
    rnd7 = rng() % std::size(nm5);
    rnd8 = rng() % std::size(nm5);
    if (rnd8 < 5) {
    rnd6 = 0;
    while (rnd5 < 3) {
    rnd5 = rng() % std::size(nm4);
    }
    }
    if (rnd6 == 1) {
    rnd7 = 0;
    }
    if (rnd5 < 3) {
    rnd8 = 0;
    }
    rnd10 = rng() % std::size(nm2);
    rnd11 = rng() % std::size(nm5);
    rnd12 = rng() % std::size(nm7);
    rnd13 = rng() % std::size(nm6);
    rnd14 = rng() % std::size(nm5);
    if (rnd11 == 1) {
    rnd14 = 0;
    }
    rnd15 = rng() % std::size(nm7);
    if (rnd12 < 6) {
    while (rnd15 < 6) {
    rnd15 = rng() % std::size(nm7);
    }
    }
    rnd16 = rng() % std::size(nm9);
    rnd17 = rng() % std::size(nm5);
    if (rnd11 == 1 || rnd14 == 1) {
    rnd17 = 0;
    }
    rnd18 = rng() % std::size(nm10);
    if (rnd16 < 16) {
    rnd17 = 0;
    rnd18 = 0;
    } else {
    while (rnd18 == 0) {
    rnd18 = rng() % std::size(nm10);
    }
    }
    names = nm8[rnd2] + nm5[rnd6] + nm3[rnd3] + nm5[rnd7] + nm2[rnd4] + nm4[rnd5] + nm5[rnd8] + " " + nm6[rnd10] + nm5[rnd11] + nm7[rnd12] + nm6[rnd13] + nm5[rnd14] + nm7[rnd15] + nm9[rnd16] + nm5[rnd17] + nm10[rnd18];
    }
    } else {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm5);
    rnd7 = rng() % std::size(nm5);
    rnd8 = rng() % std::size(nm5);
    if (rnd6 == 1) {
    rnd7 = 0;
    }
    if (rnd5 < 3) {
    rnd8 = 0;
    }
    names = nm1[rnd] + nm2[rnd2] + nm5[rnd6] + nm3[rnd3] + nm5[rnd7] + nm2[rnd4] + nm4[rnd5] + nm5[rnd8];
    } else {
    rnd2 = rng() % std::size(nm8);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm5);
    rnd7 = rng() % std::size(nm5);
    rnd8 = rng() % std::size(nm5);
    if (rnd8 < 5) {
    rnd6 = 0;
    while (rnd5 < 3) {
    rnd5 = rng() % std::size(nm4);
    }
    }
    if (rnd6 == 1) {
    rnd7 = 0;
    }
    if (rnd5 < 3) {
    rnd8 = 0;
    }
    rnd10 = rng() % std::size(nm2);
    rnd11 = rng() % std::size(nm5);
    rnd12 = rng() % std::size(nm7);
    rnd13 = rng() % std::size(nm6);
    rnd14 = rng() % std::size(nm5);
    if (rnd11 == 1) {
    rnd14 = 0;
    }
    rnd15 = rng() % std::size(nm7);
    if (rnd12 < 6) {
    while (rnd15 < 6) {
    rnd15 = rng() % std::size(nm7);
    }
    }
    rnd16 = rng() % std::size(nm9);
    rnd17 = rng() % std::size(nm5);
    if (rnd11 == 1 || rnd14 == 1) {
    rnd17 = 0;
    }
    rnd18 = rng() % std::size(nm10);
    if (rnd16 < 16) {
    rnd17 = 0;
    rnd18 = 0;
    } else {
    while (rnd18 == 0) {
    rnd18 = rng() % std::size(nm10);
    }
    }
    rnd19 = rng() % std::size(nm11);
    names = nm8[rnd2] + nm5[rnd6] + nm3[rnd3] + nm5[rnd7] + nm2[rnd4] + nm4[rnd5] + nm5[rnd8] + nm11[rnd19] + " " + nm6[rnd10] + nm5[rnd11] + nm7[rnd12] + nm6[rnd13] + nm5[rnd14] + nm7[rnd15] + nm9[rnd16] + nm5[rnd17] + nm10[rnd18];
    }
    }
    return names;
    }
}
