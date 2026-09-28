#include "star_wars-wookiees_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_wookiees_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "b", "bl", "c", "ch", "chr", "d", "drrl", "dr", "drl", "f", "fr", "g", "gr", "grr", "grrw", "gw", "h", "hr", "j", "k", "kh", "kk", "kr", "krr", "krrs", "l", "m", "mr", "n", "q", "r", "rh", "rr", "s", "sh", "sn", "snr", "snrr", "snrl", "sp", "st", "t", "tr", "tvr", "tvrr", "trr", "v", "vr", "w", "wh", "wr", "wrh", "wrrl", "wrr", "z", "zh"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "aa", "aaa", "ae", "ai", "ao", "aoa", "au", "ay", "ayy", "ee", "eee", "eeo", "eo", "eu", "ia", "iaa", "ie", "ii", "ioe", "iya", "iyy", "oa", "oo", "ooa", "ooo", "ou", "oua", "ua", "uaa", "uu", "uy", "y", "ya", "yi", "yy", "yyy"};
    static constexpr std::string_view nm3[] = {"b", "bb", "br", "c", "cc", "ch", "d", "dd", "f", "ff", "fr", "g", "gg", "ggl", "gh", "ghr", "gr", "h", "hnch", "hr", "j", "jj", "k", "kch", "kk", "kt", "l", "lb", "lgh", "lghr", "ll", "llffw", "lm", "ln", "lp", "lrr", "lw", "m", "mb", "mc", "mgr", "mm", "mn", "mp", "n", "nch", "nd", "ng", "nh", "nl", "nn", "nnk", "ns", "nt", "p", "pp", "r", "rb", "rc", "rch", "rd", "rdr", "rf", "rff", "rfh", "rg", "rk", "rkk", "rl", "rr", "rrf", "rrfh", "rrr", "rrw", "rt", "rv", "rw", "rww", "s", "sch", "sh", "sht", "sn", "ssh", "st", "t", "tb", "tc", "tch", "th", "thk", "thr", "thrr", "thrrr", "tt", "tw", "v", "vg", "vv", "w", "wb", "wd", "whhr", "whr", "wk", "wr", "wrr", "wrrh", "ww", "y", "zn", "zz"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "c", "ch", "ck", "drr", "drrl", "h", "hn", "hr", "hrr", "k", "kk", "kk", "kkk", "l", "ll", "m", "n", "nch", "nk", "r", "rd", "rk", "rl", "rm", "rph", "rr", "rrr", "s", "sch", "sh", "shk", "ss", "st", "t", "v", "vv", "w", "wk", "wl", "wn", "wr"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "", "", "", "", "", "b", "br", "bh", "c", "d", "dr", "dh", "dhr", "f", "fr", "g", "gch", "ghr", "gr", "gw", "h", "hw", "hwr", "j", "k", "kr", "kh", "l", "m", "n", "p", "r", "rr", "rh", "rhr", "s", "shr", "t", "w", "wh", "wr", "whr"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ie", "ia", "oe", "ay", "ayy", "ua", "aaa", "aa", "y", "ay", "yo", "ae", "aa", "yy", "eu", "oo"};
    static constexpr std::string_view nm7[] = {"b", "bb", "bh", "c", "cc", "ch", "d", "dd", "g", "gg", "gh", "ghr", "h", "hl", "hb", "hlb", "ht", "k", "kk", "kh", "kl", "l", "lr", "lg", "ld", "ll", "lm", "ln", "m", "mb", "mc", "mm", "mn", "n", "nch", "ng", "ngl", "nb", "nm", "nn", "p", "pr", "r", "rc", "rgl", "rr", "rrl", "rrr", "rrs", "s", "sst", "st", "t", "thn", "tm", "tt", "v", "vv", "w", "wl", "wr"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ck", "gn", "gnh", "k", "kk", "l", "ll", "m", "n", "nh", "r", "rl", "rr", "rrl", "s", "sh", "shk", "w"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    if (i < 4) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5];
    } else if (i < 7) {
    rnd7 = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd7] + nm6[rnd6] + nm8[rnd5];
    } else {
    rnd7 = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm6);
    rnd8 = rng() % std::size(nm7);
    rnd9 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd7] + nm6[rnd6] + nm7[rnd8] + nm6[rnd9] + nm8[rnd5];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 2) {
    while (rnd < 15) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 15) {
    rnd5 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5];
    } else if (i < 5) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    } else if (i < 8) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd7] + nm2[rnd6] + nm4[rnd5];
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm3);
    rnd9 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd7] + nm2[rnd6] + nm3[rnd8] + nm2[rnd9] + nm4[rnd5];
    }
    }
    return names;
    }
}
