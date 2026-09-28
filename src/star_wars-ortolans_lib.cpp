#include "star_wars-ortolans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_ortolans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "b", "d", "h", "l", "m", "n", "p", "r", "t", "v"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "o", "a", "e", "a", "e", "i", "o", "u", "a", "e", "o", "a", "e", "ee", "oo"};
    static constexpr std::string_view nm3[] = {"b", "bb", "br", "bn", "d", "dn", "dr", "dd", "j", "l", "lb", "lbr", "ldr", "lr", "lm", "ln", "ld", "md", "ml", "mdr", "md", "mr", "mm", "mn", "ndr", "n", "nn", "nl", "nd", "nb", "r", "rl", "rn", "rm", "rd", "rb"};
    static constexpr std::string_view nm4[] = {"", "", "", "b", "g", "gh", "j", "k", "m", "n", "p", "q", "r", "t", "tz", "x"};
    static constexpr std::string_view nm5[] = {"", "", "b", "bh", "bl", "f", "fl", "h", "l", "m", "n", "ph", "s", "sl", "w"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "a", "e", "o", "a", "e", "o"};
    static constexpr std::string_view nm7[] = {"bk", "b", "bb", "bn", "bl", "bs", "bh", "d", "dd", "dn", "dl", "f", "ff", "fl", "fr", "h", "hh", "l", "ll", "lm", "lr", "ln", "ld", "m", "mm", "ml", "md", "mn", "ms", "n", "nn", "nl", "ns", "nm", "ph", "phl", "phn", "t", "th", "tl", "tn", "ts"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "f", "h", "l", "n", "m", "s", "ss", "th"};
    static constexpr std::string_view nm9[] = {"b", "br", "d", "dr", "h", "l", "m", "n", "r", "s", "sr", "t", "v"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "o", "a", "e", "i", "o", "u", "a", "e", "o", "a", "e", "i", "o", "u", "a", "e", "o", "ee", "oo", "ai"};
    static constexpr std::string_view nm11[] = {"b", "d", "g", "j", "k", "l", "m", "n", "q", "t", "v"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "d", "g", "k", "l", "m", "n", "q", "r", "s", "x"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm12);
    if (i % 2 == 0) {
    namelast = nm9[rnd7] + nm10[rnd8] + nm12[rnd10];
    } else {
    rnd9 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    namelast = nm9[rnd7] + nm10[rnd8] + nm11[rnd11] + nm10[rnd9] + nm12[rnd10];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm7);
    rnd5 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd4] + nm6[rnd5] + nm8[rnd3] + "  " + namelast;
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm4);
    if (i < 5) {
    while (rnd < 2) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd3 < 3) {
    rnd3 = rng() % std::size(nm4);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd3] + "  " + namelast;
    } else {
    rnd4 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd4] + nm2[rnd5] + nm4[rnd3] + "  " + namelast;
    }
    }
    return names;
    }
}
