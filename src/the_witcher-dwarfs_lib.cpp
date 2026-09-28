#include "the_witcher-dwarfs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_the_witcher_dwarfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "bl", "br", "c", "cr", "d", "dh", "f", "fl", "g", "gr", "j", "k", "kr", "l", "m", "p", "r", "rh", "shr", "sk", "sh", "th", "t", "v", "w", "x", "y", "z", "zh"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ie", "au", "ia", "ei", "ou"};
    static constexpr std::string_view nm3[] = {"c", "cc", "cr", "d", "dh", "dr", "g", "gg", "gm", "gn", "h", "l", "lc", "ld", "lfl", "lk", "ll", "lm", "lr", "lt", "m", "mm", "mn", "n", "nb", "nc", "nd", "nn", "nr", "nt", "r", "rb", "rcl", "rd", "rg", "rl", "rm", "rn", "rp", "rt", "rth", "s", "sc", "sr", "st", "v", "ym", "z"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ie", "au", "ia", "ei", "ou"};
    static constexpr std::string_view nm5[] = {"", "c", "cc", "cr", "d", "dh", "dr", "g", "gg", "gm", "gn", "h", "l", "lc", "ld", "lfl", "lk", "ll", "lm", "lr", "lt", "m", "mm", "mn", "n", "nb", "nc", "nd", "nn", "nr", "nt", "r", "rb", "rcl", "rd", "rg", "rl", "rm", "rn", "rp", "rt", "rth", "s", "sc", "sr", "st", "v", "ym", "z"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "b", "ck", "k", "l", "ld", "lm", "n", "nd", "nn", "rn", "rm", "rd", "r", "rk", "rd", "s"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "b", "br", "c", "ch", "cl", "d", "dh", "f", "fl", "g", "gh", "gr", "l", "m", "n", "p", "pr", "r", "rh", "sh", "s", "st", "th", "t", "v", "w", "y", "z", "zh"};
    static constexpr std::string_view nm9[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "eu", "ea", "ia", "eo", "io"};
    static constexpr std::string_view nm10[] = {"c", "cc", "ch", "d", "dh", "dd", "g", "gl", "gn", "gm", "gh", "gr", "h", "l", "ln", "lm", "ll", "lr", "ls", "m", "mm", "mn", "n", "ns", "nm", "nl", "ng", "nz", "nw", "p", "ph", "r", "rh", "rl", "rn", "rm", "rs", "s", "sh", "sm", "sn", "st", "v", "w", "lw", "z", "zh", "zn", "zm"};
    static constexpr std::string_view nm11[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "eu", "ea", "ia", "eo", "io"};
    static constexpr std::string_view nm12[] = {"", "c", "cc", "ch", "d", "dh", "dd", "g", "gl", "gn", "gm", "gh", "gr", "h", "l", "ln", "lm", "ll", "lr", "ls", "m", "mm", "mn", "n", "ns", "nm", "nl", "ng", "nz", "nw", "p", "ph", "r", "rh", "rl", "rn", "rm", "rs", "s", "sh", "sm", "sn", "st", "v", "w", "lw", "z", "zh", "zn", "zm"};
    static constexpr std::string_view nm14[] = {"", "", "", "", "", "", "", "", "", "n", "th", "s"};
    static constexpr std::string_view nm15[] = {"", "", "", "", "", "b", "br", "c", "ch", "cr", "d", "dr", "f", "g", "gr", "h", "k", "l", "m", "n", "p", "pr", "sk", "st", "str", "s", "t", "tr", "v", "z"};
    static constexpr std::string_view nm16[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "au", "ei", "ia", "ea", "ai"};
    static constexpr std::string_view nm17[] = {"c", "cc", "ck", "cr", "dn", "g", "gg", "gl", "gn", "gr", "hl", "hlb", "hln", "hn", "l", "ld", "lm", "ln", "lr", "n", "nd", "ngv", "nl", "nm", "nr", "r", "rd", "rg", "rl", "rn", "rt", "s", "sr", "ssl", "st", "tt", "v", "zd"};
    static constexpr std::string_view nm18[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "au", "ei", "ia", "ea", "ai"};
    static constexpr std::string_view nm19[] = {"", "c", "cc", "ck", "cr", "dn", "g", "gg", "gl", "gn", "gr", "hl", "hlb", "hln", "hn", "l", "ld", "lm", "ln", "lr", "n", "nd", "ngv", "nl", "nm", "nr", "r", "rd", "rg", "rl", "rn", "rt", "s", "sr", "ssl", "st", "tt", "v", "zd"};
    static constexpr std::string_view nm20[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "au", "ei", "ia", "ea", "ai"};
    static constexpr std::string_view nm21[] = {"", "", "", "", "", "ck", "ggs", "gs", "l", "ld", "ls", "lt", "m", "n", "r", "rd", "rg", "s", "ss", "st", "t", "y", "ys"};

    std::string lname; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd8 = rng() % std::size(nm15);
    rnd9 = rng() % std::size(nm16);
    rnd10 = rng() % std::size(nm17);
    rnd11 = rng() % std::size(nm18);
    rnd12 = rng() % std::size(nm19);
    rnd13 = rng() % std::size(nm20);
    rnd14 = rng() % std::size(nm21);
    if (rnd11 < 60) {
    rnd12 = 0;
    rnd13 = 0;
    } else {
    while (rnd12 == 0) {
    rnd12 = rng() % std::size(nm19);
    }
    }
    lname = nm15[rnd8] + nm16[rnd9] + nm17[rnd10] + nm18[rnd11] + nm19[rnd12] + nm20[rnd13] + nm21[rnd14];
    if (type == 1) {
    rnd = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm9);
    rnd3 = rng() % std::size(nm10);
    rnd6 = rng() % std::size(nm9);
    rnd7 = rng() % std::size(nm14);
    if (i < 5) {
    names = nm8[rnd] + nm9[rnd2] + nm10[rnd3] + nm9[rnd6] + nm14[rnd7] + " " + lname;
    } else {
    rnd4 = rng() % std::size(nm11);
    rnd5 = rng() % std::size(nm12);
    if (rnd4 < 30) {
    rnd5 = 0;
    rnd6 = 0;
    } else {
    while (rnd5 == 0) {
    rnd5 = rng() % std::size(nm12);
    }
    }
    names = nm8[rnd] + nm9[rnd2] + nm10[rnd3] + nm11[rnd4] + nm12[rnd5] + nm9[rnd6] + nm14[rnd7] + " " + lname;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm7);
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd6] + nm7[rnd7] + " " + lname;
    } else {
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    if (rnd4 < 40) {
    rnd5 = 0;
    rnd6 = 0;
    } else {
    while (rnd5 == 0) {
    rnd5 = rng() % std::size(nm5);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm2[rnd6] + nm7[rnd7] + " " + lname;
    }
    }
    return names;
    }
}
