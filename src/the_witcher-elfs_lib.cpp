#include "the_witcher-elfs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_the_witcher_elfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "c", "ch", "cr", "d", "f", "g", "h", "m", "r", "s", "t", "v", "vr"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ia", "oi", "au", "ai", "ei", "ae", "ea", "io"};
    static constexpr std::string_view nm3[] = {"b", "bh", "ch", "d", "dr", "h", "l", "m", "md", "ml", "mm", "n", "nd", "ndr", "ng", "ngr", "nl", "nn", "r", "rbr", "rd", "rl", "rn", "rrd", "rv", "s", "v"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ia", "oi", "au", "ai", "ei", "ae", "ea", "io"};
    static constexpr std::string_view nm5[] = {"", "b", "bh", "ch", "d", "dr", "h", "l", "m", "md", "ml", "mm", "n", "nd", "ndr", "ng", "ngr", "nl", "nn", "r", "rbr", "rd", "rl", "rn", "rrd", "rv", "s", "v"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "d", "r", "s", "n", "c", "ch", "l", "rr", "th", "m", "nn"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "c", "d", "f", "h", "l", "m", "n", "r", "s", "sr", "sh", "t", "th", "v"};
    static constexpr std::string_view nm9[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ae", "ie", "ee", "io", "ua", "ia"};
    static constexpr std::string_view nm10[] = {"d", "dh", "fr", "f", "ff", "gl", "gh", "l", "ll", "m", "mm", "mn", "n", "nn", "nr", "r", "rr", "s", "ss", "sh", "th", "thl", "tt", "t", "tl", "v"};
    static constexpr std::string_view nm11[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ae", "ie", "ee", "io", "ua", "ia"};
    static constexpr std::string_view nm12[] = {"", "d", "dh", "fr", "f", "ff", "gl", "gh", "l", "ll", "m", "mm", "mn", "n", "nn", "nr", "r", "rr", "s", "ss", "sh", "th", "thl", "tt", "t", "tl", "v"};
    static constexpr std::string_view nm14[] = {"", "", "", "", "", "", "", "", "", "nn", "n", "l", "s", "sh"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm9);
    rnd3 = rng() % std::size(nm10);
    rnd6 = rng() % std::size(nm9);
    rnd7 = rng() % std::size(nm14);
    if (i < 5) {
    names = nm8[rnd] + nm9[rnd2] + nm10[rnd3] + nm9[rnd6] + nm14[rnd7];
    } else {
    rnd4 = rng() % std::size(nm11);
    rnd5 = rng() % std::size(nm12);
    if (rnd4 < 20) {
    rnd5 = 0;
    rnd6 = 0;
    } else {
    while (rnd5 == 0) {
    rnd5 = rng() % std::size(nm12);
    }
    }
    names = nm8[rnd] + nm9[rnd2] + nm10[rnd3] + nm11[rnd4] + nm12[rnd5] + nm9[rnd6] + nm14[rnd7];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm7);
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd6] + nm7[rnd7];
    } else {
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    if (rnd4 < 30) {
    rnd5 = 0;
    rnd6 = 0;
    } else {
    while (rnd5 == 0) {
    rnd5 = rng() % std::size(nm5);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm2[rnd6] + nm7[rnd7];
    }
    }
    return names;
    }
}
