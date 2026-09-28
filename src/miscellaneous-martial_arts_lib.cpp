#include "miscellaneous-martial_arts_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_martial_arts_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "b", "d", "g", "h", "l", "m", "n", "ng", "s", "t", "w"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "aa", "ai", "oa", "oe"};
    static constexpr std::string_view nm3[] = {"b", "gw", "hn", "hl", "ht", "l", "mb", "n", "nt", "nd", "ng", "ngw", "r", "rm", "s"};
    static constexpr std::string_view nm4[] = {"", "", "b", "br", "c", "cr", "ch", "d", "g", "gr", "h", "j", "k", "m", "n", "sh", "st", "v", "w"};
    static constexpr std::string_view nm5[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "oei", "ou", "ee", "oo", "ea", "eo", "ue", "ua", "ia"};
    static constexpr std::string_view nm6[] = {"c", "ch", "d", "gr", "j", "k", "l", "m", "mp", "n", "nch", "nd", "nz", "nt", "nk", "p", "q", "st", "r", "rt", "t", "v"};
    static constexpr std::string_view nm7[] = {"", "", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "oei", "ou", "ee", "oo", "ea", "eo", "ue", "ua", "ia"};
    static constexpr std::string_view nm8[] = {"", "", "c", "ch", "d", "gr", "j", "k", "l", "m", "mp", "n", "nch", "nd", "nz", "nt", "nk", "p", "q", "st", "r", "rt", "t", "v"};
    static constexpr std::string_view nm9[] = {" ", "-"};
    static constexpr std::string_view nm10[] = {"b", "d", "f", "h", "k", "khr", "s", "t", "m", "n", "p", "q", "v"};
    static constexpr std::string_view nm11[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm12[] = {"c", "d", "df", "dh", "fr", "g", "j", "ht", "k", "kh", "l", "nh", "m", "p", "r", "rs", "sw", "sth", "st", "z"};
    static constexpr std::string_view nm13[] = {"", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm14[] = {"", "", "c", "d", "df", "dh", "fr", "g", "j", "ht", "k", "kh", "l", "nh", "m", "p", "r", "rs", "sw", "sth", "st", "z"};
    static constexpr std::string_view nm15[] = {"", "", "b", "f", "g", "h", "hr", "hn", "k", "m", "n", "p", "r", "sh"};
    static constexpr std::string_view nm16[] = {"", "", "", "", "b", "ch", "c", "g", "gw", "gy", "h", "hw", "j", "k", "kb", "kr", "ky", "l", "m", "nh", "ny", "p", "pr", "sh", "s", "t", "th", "v", "w", "y"};
    static constexpr std::string_view nm17[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "oi", "ae", "eo", "ua", "ai", "ia", "ei", "oo", "aa", "ou", "ee"};
    static constexpr std::string_view nm18[] = {"b", "by", "chk", "ch", "d", "ddh", "dh", "hlw", "hw", "j", "k", "km", "kn", "kw", "ky", "l", "lg", "ll", "mb", "md", "mp", "n", "nb", "nd", "ng", "ngd", "nj", "nk", "nsh", "nt", "p", "pk", "pp", "r", "rn", "s", "sh", "st", "t", "th", "thw", "tk", "ts", "tt", "y"};
    static constexpr std::string_view nm19[] = {"", "", "", "", "", "", "", "", "", "", "", "", "k", "l", "m", "n", "ng", "r", "s", "t", "w", "y"};

    std::string names; std::string nm20; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (i < 2) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    if (rnd2 > 4) {
    while (rnd4 > 4) {
    rnd4 = rng() % std::size(nm2);
    }
    }
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm2);
    if (rnd2 > 4 || rnd4 > 4) {
    while (rnd6 > 4) {
    rnd6 = rng() % std::size(nm2);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd5] + nm2[rnd6];
    } else if (i == 2) {
    rnd = rng() % std::size(nm4);
    rnd2 = rng() % std::size(nm5);
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm7);
    if (rnd2 > 20) {
    while (rnd4 > 22) {
    rnd4 = rng() % std::size(nm7);
    }
    }
    rnd5 = rng() % std::size(nm8);
    if (rnd4 < 2) {
    rnd5 = 0;
    }
    rnd6 = rng() % std::size(nm5);
    if (rnd2 > 20 || rnd4 > 22) {
    while (rnd6 > 20) {
    rnd6 = rng() % std::size(nm5);
    }
    }
    names = nm4[rnd] + nm5[rnd2] + nm6[rnd3] + nm7[rnd4] + nm8[rnd5] + nm5[rnd6];
    } else if (i == 3) {
    rnd = rng() % std::size(nm4);
    rnd2 = rng() % std::size(nm5);
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm9);
    rnd6 = rng() % std::size(nm4);
    rnd7 = rng() % std::size(nm5);
    rnd8 = rng() % std::size(nm6);
    rnd9 = rng() % std::size(nm5);
    names = nm4[rnd] + nm5[rnd2] + nm6[rnd3] + nm5[rnd4] + nm9[rnd5] + nm4[rnd6] + nm5[rnd7] + nm6[rnd8] + nm5[rnd9];
    } else if (i == 4) {
    rnd = rng() % std::size(nm10);
    rnd2 = rng() % std::size(nm11);
    rnd3 = rng() % std::size(nm12);
    rnd4 = rng() % std::size(nm13);
    rnd5 = rng() % std::size(nm14);
    if (rnd4 == 0) {
    rnd5 = 0;
    }
    rnd6 = rng() % std::size(nm11);
    rnd7 = rng() % std::size(nm15);
    names = nm10[rnd] + nm11[rnd2] + nm12[rnd3] + nm13[rnd4] + nm14[rnd5] + nm11[rnd6] + nm15[rnd7];
    } else if (i < 7) {
    rnd = rng() % std::size(nm16);
    rnd2 = rng() % std::size(nm17);
    rnd3 = rng() % std::size(nm18);
    rnd4 = rng() % std::size(nm17);
    rnd5 = rng() % std::size(nm19);
    names = nm16[rnd] + nm17[rnd2] + nm18[rnd3] + nm17[rnd4] + nm19[rnd5];
    } else if (i == 7) {
    rnd = rng() % std::size(nm16);
    rnd2 = rng() % std::size(nm17);
    rnd3 = rng() % std::size(nm18);
    rnd4 = rng() % std::size(nm17);
    rnd5 = rng() % std::size(nm18);
    rnd6 = rng() % std::size(nm17);
    if (rnd2 > 24 || rnd4 > 24) {
    while (rnd6 > 24) {
    rnd6 = rng() % std::size(nm17);
    }
    }
    rnd7 = rng() % std::size(nm19);
    names = nm16[rnd] + nm17[rnd2] + nm18[rnd3] + nm17[rnd4] + nm18[rnd5] + nm17[rnd6] + nm19[rnd7];
    } else if (i == 8) {
    rnd = rng() % std::size(nm16);
    rnd2 = rng() % std::size(nm17);
    rnd3 = rng() % std::size(nm19);
    if (rnd < 3) {
    while (rnd3 < 12) {
    rnd3 = rng() % std::size(nm19);
    }
    }
    rnd4 = rng() % std::size(nm9);
    rnd5 = rng() % std::size(nm16);
    rnd6 = rng() % std::size(nm17);
    rnd7 = rng() % std::size(nm18);
    rnd8 = rng() % std::size(nm17);
    rnd9 = rng() % std::size(nm19);
    names = nm16[rnd] + nm17[rnd2] + nm19[rnd3] + nm9[rnd4] + nm16[rnd5] + nm17[rnd6] + nm18[rnd7] + nm17[rnd8] + nm19[rnd9];
    } else {
    rnd = rng() % std::size(nm16);
    rnd2 = rng() % std::size(nm17);
    rnd3 = rng() % std::size(nm19);
    if (rnd < 3) {
    while (rnd3 < 12) {
    rnd3 = rng() % std::size(nm19);
    }
    }
    rnd4 = rng() % std::size(nm9);
    rnd5 = rng() % std::size(nm16);
    rnd6 = rng() % std::size(nm17);
    rnd7 = rng() % std::size(nm18);
    rnd8 = rng() % std::size(nm17);
    rnd9 = rng() % std::size(nm19);
    names = nm16[rnd5] + nm17[rnd6] + nm18[rnd7] + nm17[rnd8] + nm19[rnd9] + nm9[rnd4] + nm16[rnd] + nm17[rnd2] + nm19[rnd3];
    }
    return names;
    }
}
