#include "star_trek-tellarites_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_tellarites_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"B", "Br", "Ch", "C", "Cr", "D", "Dv", "Fr", "F", "G", "Gl", "Gr", "H", "J", "K", "Kh", "L", "M", "N", "Pr", "R", "Sh", "Sk", "T", "Th", "Tr", "V", "W", "X", "Z", "Zh"};
    static constexpr std::string_view nm2[] = {"aa", "ao", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "o"};
    static constexpr std::string_view nm3[] = {"bl", "fr", "g", "gr", "hr", "l", "ll", "nn", "nk", "r", "rgg", "rk", "s", "shl", "shn", "vr", "rt"};
    static constexpr std::string_view nm4[] = {"ch", "g", "gm", "k", "llv", "m", "n", "nn", "nch", "nd", "r", "rsh", "rc", "rg", "rv", "th", "s", "sh", "ss", "v"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "", "", " bav", " bim", " blasch", " chim", " glasch", " glov", " lorin", " jav"};
    static constexpr std::string_view nm6[] = {"B", "Bl", "Ch", "C", "Cl", "D", "Fr", "Fr", "F", "G", "Gl", "Gh", "H", "J", "K", "Kh", "L", "M", "N", "P", "R", "Sh", "Sk", "T", "Th", "Tl", "V", "W", "Z", "Zh"};
    static constexpr std::string_view nm8[] = {"bl", "f", "ff", "g", "gg", "gr", "hr", "hl", "l", "ll", "nn", "nk", "r", "rk", "s", "ss", "shl", "shn", "v", "rth", "th", "t", "tt"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "", "ch", "f", "g", "gh", "hg", "hk", "l", "ll", "m", "n", "nn", "nsh", "nd", "p", "r", "rr", "rs", "rg", "rn", "th", "s", "sh", "ss", "v", "w"};
    static constexpr std::string_view nm10[] = {"ch", "f", "g", "gh", "hg", "hk", "l", "ll", "m", "n", "nn", "nsh", "nd", "p", "r", "rr", "rs", "rg", "rn", "th", "s", "sh", "ss", "v", "w"};
    static constexpr std::string_view nm11[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "aa", "ao", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "o"};
    static constexpr std::string_view nm12[] = {"B", "Bl", "Br", "C", "Ch", "Cl", "Cr", "D", "Dv", "F", "Fr", "G", "Gh", "Gl", "Gr", "H", "J", "K", "Kh", "L", "M", "N", "P", "Pr", "R", "Sh", "Sk", "T", "Th", "Tl", "Tr", "V", "W", "X", "Z", "Zh"};
    static constexpr std::string_view nm13[] = {"bl", "f", "ff", "fr", "g", "gg", "gr", "hl", "hr", "l", "ll", "nk", "nn", "r", "rgg", "rk", "rth", "s", "shl", "shn", "ss", "t", "th", "tt", "v", "vr"};
    static constexpr std::string_view nm14[] = {"ch", "f", "g", "gh", "gm", "hg", "hk", "k", "l", "ll", "llv", "m", "n", "nch", "nd", "nn", "nsh", "p", "r", "rc", "rg", "rn", "rr", "rs", "rsh", "rv", "s", "sh", "ss", "th", "v", "w"};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 5) {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm9);
    rnd6 = rng() % std::size(nm5);
    rnd7 = rng() % std::size(nm12);
    rnd8 = rng() % std::size(nm2);
    rnd9 = rng() % std::size(nm14);
    names = nm6[rnd] + nm2[rnd2] + nm8[rnd3] + nm2[rnd4] + nm9[rnd5] + nm5[rnd6] + " " + nm12[rnd7] + nm2[rnd8] + nm14[rnd9];
    } else {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm10);
    rnd4 = rng() % std::size(nm11);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm12);
    rnd7 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm13);
    rnd9 = rng() % std::size(nm2);
    rnd10 = rng() % std::size(nm14);
    names = nm6[rnd] + nm2[rnd2] + nm10[rnd3] + nm11[rnd4] + nm5[rnd5] + " " + nm12[rnd6] + nm2[rnd7] + nm13[rnd8] + nm2[rnd9] + nm14[rnd10];
    }
    } else {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm12);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm13);
    rnd8 = rng() % std::size(nm2);
    rnd9 = rng() % std::size(nm14);
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd3] + nm5[rnd4] + " " + nm12[rnd5] + nm2[rnd6] + nm13[rnd7] + nm2[rnd8] + nm14[rnd9];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm5);
    rnd7 = rng() % std::size(nm12);
    rnd8 = rng() % std::size(nm2);
    rnd9 = rng() % std::size(nm14);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + nm5[rnd6] + " " + nm12[rnd7] + nm2[rnd8] + nm14[rnd9];
    }
    }
    return names;
    }
}
