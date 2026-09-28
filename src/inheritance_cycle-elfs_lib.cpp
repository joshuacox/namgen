#include "inheritance_cycle-elfs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_inheritance_cycle_elfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "b", "bl", "c", "cl", "d", "f", "g", "gl", "gn", "h", "k", "l", "m", "n", "t", "th", "v", "vr", "w"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "í", "ö", "ä", "äo", "á", "ae", "ia", "ie", "io", "au", "ae"};
    static constexpr std::string_view nm3[] = {"c", "d", "dhg", "dg", "dr", "dh", "f", "g", "gh", "l", "lm", "ln", "ld", "ldth", "ll", "lr", "mn", "m", "mh", "n", "nd", "nr", "nth", "nw", "r", "rd", "rv", "rz", "rth", "s", "sd", "th", "tr", "v"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "dr", "l", "ldr", "lr", "mh", "n", "ng", "r", "rm", "s"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "bh", "cl", "d", "f", "gl", "gh", "h", "l", "m", "n", "rh", "s", "t", "th", "v", "w", "y"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "í", "ë", "ö", "á", "ëa", "ia", "io", "au", "ue", "ua", "ía", "ae"};
    static constexpr std::string_view nm7[] = {"d", "dr", "fr", "l", "ll", "lr", "ln", "lm", "ldr", "ld", "ly", "m", "mv", "my", "mm", "ny", "n", "nn", "nv", "nz", "r", "rm", "ry", "rh", "sn", "sl", "t", "th", "y"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "d", "n", "r", "s", "th"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 6) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5];
    } else {
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd6] + nm7[rnd7] + nm6[rnd4] + nm8[rnd5];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm4);
    if (i < 3) {
    if (rnd < 4) {
    while (rnd4 < 5) {
    rnd4 = rng() % std::size(nm4);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd4];
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm4[rnd4];
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm3[rnd6] + nm2[rnd7] + nm4[rnd4];
    }
    }
    return names;
    }
}
