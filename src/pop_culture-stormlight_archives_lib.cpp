#include "pop_culture-stormlight_archives_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pop_culture_stormlight_archives_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "b", "bl", "c", "d", "g", "gr", "h", "j", "k", "l", "m", "n", "r", "s", "t", "th", "v", "w", "y"};
    static constexpr std::string_view nm2[] = {"a", "e", "o", "a", "e", "o", "a", "e", "o", "a", "a", "a", "e", "i", "o", "u", "a", "e", "i", "o", "oa", "ea", "ia", "ai", "io"};
    static constexpr std::string_view nm3[] = {"b", "br", "d", "k", "l", "lh", "ll", "m", "mm", "n", "r", "rf", "rr", "rt", "sh", "st", "t", "th", "v"};
    static constexpr std::string_view nm4[] = {"", "", "", "b", "ds", "ft", "h", "ks", "l", "lds", "lp", "m", "n", "nn", "r", "rd", "rks", "rl", "s", "sh", "st", "t", "th", "v", "w", "z"};
    static constexpr std::string_view nm5[] = {"", "", "", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "w"};
    static constexpr std::string_view nm6[] = {"a", "ee", "ae", "ia", "ai", "i", "e", "a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "a", "a", "a"};
    static constexpr std::string_view nm7[] = {"d", "l", "lh", "ll", "m", "mm", "n", "nk", "nl", "r", "rh", "sm", "s", "sh", "sn", "t", "th", "v", "w"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "d", "h", "l", "m", "n", "s", "t", "th", "v"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "c", "d", "g", "h", "k", "kh", "l", "m", "n", "r", "s", "st", "t", "v", "w"};
    static constexpr std::string_view nm10[] = {"a", "e", "o", "i", "a", "a", "e", "o", "i", "a", "a", "e", "o", "i", "a", "io", "ea"};
    static constexpr std::string_view nm11[] = {"d", "g", "k", "l", "m", "n", "p", "r", "s", "sh", "st", "t", "th", "v"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "", "a", "e", "o", "i", "a", "a", "e", "o", "i", "a", "a", "e", "o", "i", "a", "io", "ea"};
    static constexpr std::string_view nm13[] = {"", "", "", "", "", "", "d", "g", "k", "l", "m", "n", "p", "r", "s", "sh", "st", "t", "th", "v"};
    static constexpr std::string_view nm14[] = {"c", "d", "g", "m", "n", "s", "t", "th", "v", "w"};
    static constexpr std::string_view nm15[] = {"", "", "", "b", "d", "h", "j", "l", "m", "n", "p", "r", "v", "w"};
    static constexpr std::string_view nm16[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "ue", "ia"};
    static constexpr std::string_view nm17[] = {"d", "j", "k", "kk", "l", "m", "n", "r", "sh", "s", "ss", "t", "v"};
    static constexpr std::string_view nm18[] = {"", "", "", "d", "l", "n", "m", "r", "s", "sh", "t"};
    static constexpr std::string_view nm19[] = {"", "", "", "f", "h", "l", "m", "n", "s", "sh", "t", "th", "v", "w"};
    static constexpr std::string_view nm20[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "ue", "ia"};
    static constexpr std::string_view nm21[] = {"d", "f", "j", "h", "l", "ll", "m", "n", "r", "ss", "s", "t"};
    static constexpr std::string_view nm22[] = {"", "", "", "", "", "", "l", "n", "m", "r", "s", "sh", "th"};
    static constexpr std::string_view nm23[] = {"b", "d", "g", "h", "j", "k", "l", "m", "n", "r", "s", "t"};
    static constexpr std::string_view nm24[] = {"a", "e", "i"};
    static constexpr std::string_view nm25[] = {"f", "h", "j", "k", "l", "ll", "lm", "m", "n", "r", "v"};
    static constexpr std::string_view nm26[] = {"", "a", "e", "i"};
    static constexpr std::string_view nm27[] = {"", "f", "h", "j", "k", "l", "ll", "lm", "m", "n", "r", "v"};
    static constexpr std::string_view nm28[] = {"d", "l", "n", "r"};
    static constexpr std::string_view nm29[] = {"cn", "cl", "dv", "dvl", "dr", "gm", "gl", "gv", "km", "kl", "k", "mn", "mst", "mv", "mw", "mr", "nm", "nr", "nst", "nv", "nw", "nl", "tr", "ts", "tv", "tm", "tn", "t", "tvl", "vl", "vm", "vn", "vst"};
    static constexpr std::string_view nm30[] = {"a", "e", "o", "i", "y"};
    static constexpr std::string_view nm31[] = {"cv", "cl", "cn", "km", "kn", "krn", "k", "kv", "lm", "ln", "lrn", "ll", "lb", "nm", "nr", "nd", "nt", "m", "mt", "mrn", "md", "rn", "lrm", "rm"};
    static constexpr std::string_view nm32[] = {"", "", "", "", "", "hs", "hsh", "hth", "htn", "kn", "km", "ks", "kst", "kh", "lm", "ln", "ll", "lb", "lst", "ls", "lt", "nm", "nr", "nd", "nt", "m", "mt", "ms", "msh", "msl", "md", "shlv", "sn"};
    static constexpr std::string_view nm33[] = {"a", "e", "o", "i", "y"};
    static constexpr std::string_view nm34[] = {"cl", "dv", "dr", "dh", "dl", "gh", "gl", "gm", "gn", "h", "hr", "hl", "kl", "kh", "kn", "km", "kv", "l", "ln", "lm", "ls", "mn", "mw", "mh", "nw", "nl", "nh", "th", "thr", "trh", "ts", "tw", "tm", "tn", "vl", "vn", "r"};

    std::string lname; std::string names; std::string sname; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (i < 4) {
    rnd = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm10);
    rnd3 = rng() % std::size(nm11);
    rnd4 = rng() % std::size(nm10);
    rnd5 = rng() % std::size(nm11);
    rnd6 = rng() % std::size(nm12);
    rnd7 = rng() % std::size(nm13);
    if (rnd6 < 6) {
    rnd7 = 0;
    } else {
    while (rnd7 < 6) {
    rnd7 = rng() % std::size(nm13);
    }
    }
    rnd8 = rng() % std::size(nm10);
    rnd9 = rng() % std::size(nm14);
    lname = nm9[rnd] + nm10[rnd2] + nm11[rnd3] + nm10[rnd4] + nm11[rnd5] + nm12[rnd6] + nm13[rnd7] + nm10[rnd8] + nm14[rnd9];
    } else if (i < 7) {
    rnd = rng() % std::size(nm23);
    rnd2 = rng() % std::size(nm24);
    rnd3 = rng() % std::size(nm25);
    rnd4 = rng() % std::size(nm24);
    rnd5 = rng() % std::size(nm25);
    rnd6 = rng() % std::size(nm26);
    rnd7 = rng() % std::size(nm27);
    if (rnd6 < 1) {
    rnd7 = 0;
    } else {
    while (rnd7 < 1) {
    rnd7 = rng() % std::size(nm27);
    }
    }
    rnd8 = rng() % std::size(nm24);
    rnd9 = rng() % std::size(nm28);
    sname = nm23[rnd] + nm24[rnd2] + nm25[rnd3] + nm24[rnd4] + nm25[rnd5] + nm26[rnd6] + nm27[rnd7] + nm24[rnd8] + nm28[rnd9];
    }
    if (type == 1) {
    if (i < 2) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm8);
    while (rnd < 3) {
    rnd = rng() % std::size(nm5);
    }
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd3] + " " + lname;
    } else if (i < 4) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + " " + lname;
    } else if (i < 6) {
    rnd = rng() % std::size(nm19);
    rnd2 = rng() % std::size(nm20);
    rnd3 = rng() % std::size(nm22);
    while (rnd < 3) {
    rnd = rng() % std::size(nm19);
    }
    while (rnd3 < 6) {
    rnd3 = rng() % std::size(nm22);
    }
    rnd4 = rng() % std::size(nm20);
    names = nm19[rnd] + nm20[rnd2] + nm22[rnd3] + nm20[rnd4] + " " + sname;
    } else if (i < 7) {
    rnd = rng() % std::size(nm19);
    rnd2 = rng() % std::size(nm20);
    rnd3 = rng() % std::size(nm21);
    rnd4 = rng() % std::size(nm20);
    rnd5 = rng() % std::size(nm22);
    names = nm19[rnd] + nm20[rnd2] + nm21[rnd3] + nm20[rnd4] + nm22[rnd5] + " " + sname;
    } else {
    rnd = rng() % std::size(nm32);
    rnd2 = rng() % std::size(nm33);
    rnd3 = rng() % std::size(nm34);
    names = nm32[rnd] + nm33[rnd2] + nm34[rnd3];
    }
    } else {
    if (i < 2) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm4);
    if (rnd < 3) {
    while (rnd3 < 3) {
    rnd3 = rng() % std::size(nm4);
    }
    } else {
    while (rnd3 < 3) {
    rnd3 = rng() % std::size(nm4);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd3] + " " + lname;
    } else if (i < 4) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + lname;
    } else if (i < 6) {
    rnd = rng() % std::size(nm15);
    rnd2 = rng() % std::size(nm16);
    rnd3 = rng() % std::size(nm18);
    if (rnd < 3) {
    while (rnd3 < 3) {
    rnd3 = rng() % std::size(nm18);
    }
    } else {
    while (rnd3 < 3) {
    rnd3 = rng() % std::size(nm18);
    }
    }
    names = nm15[rnd] + nm16[rnd2] + nm18[rnd3] + " " + sname;
    } else if (i < 7) {
    rnd = rng() % std::size(nm15);
    rnd2 = rng() % std::size(nm16);
    rnd3 = rng() % std::size(nm17);
    rnd4 = rng() % std::size(nm16);
    rnd5 = rng() % std::size(nm18);
    names = nm15[rnd] + nm16[rnd2] + nm17[rnd3] + nm16[rnd4] + nm18[rnd5] + " " + sname;
    } else {
    rnd = rng() % std::size(nm29);
    rnd2 = rng() % std::size(nm30);
    rnd3 = rng() % std::size(nm31);
    names = nm29[rnd] + nm30[rnd2] + nm31[rnd3];
    }
    }
    return names;
    }
}
