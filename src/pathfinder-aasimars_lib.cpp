#include "pathfinder-aasimars_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_aasimars_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "c", "cr", "d", "gr", "k", "kr", "l", "m", "n", "p", "s", "t", "w", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "ai", "au", "ie", "ia", "ea"};
    static constexpr std::string_view nm3[] = {"b", "b", "d", "d", "dr", "g", "g", "gr", "gn", "k", "k", "kw", "kr", "l", "l", "lw", "lr", "lm", "ln", "lg", "lt", "m", "m", "mr", "ml", "mw", "n", "n", "nr", "nl", "ng", "nv", "nw", "r", "r", "rl", "rw", "rg", "rn", "t", "t"};
    static constexpr std::string_view nm4[] = {"l", "m", "n", "n", "n", "nt", "r"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "b", "br", "d", "dr", "h", "l", "m", "n", "p", "ph", "r", "rh", "v", "vh", "w"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "oe", "ou", "ua", "ea", "ia"};
    static constexpr std::string_view nm7[] = {"d", "d", "dr", "dy", "gr", "j", "j", "l", "l", "ll", "lt", "ld", "lm", "ln", "ldr", "ls", "m", "m", "mr", "mk", "ml", "n", "n", "ndr", "nd", "nk", "ng", "nd", "ny", "nm", "p", "p", "pr", "r", "r", "rk", "rl", "s", "s", "v", "v", "y", "y", "z", "z"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "h", "l", "n", "r"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "b", "br", "d", "dr", "h", "k", "kr", "l", "m", "n", "p", "r", "s", "t", "v", "w", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm11[] = {"b", "d", "g", "gr", "h", "k", "kr", "km", "l", "ll", "lr", "ls", "lg", "ldr", "lm", "lw", "m", "mr", "ml", "n", "nm", "ng", "nv", "nk", "p", "pr", "r", "rl", "rg", "rv", "rw", "s", "v", "z"};
    static constexpr std::string_view nm12[] = {"", "", "", "l", "m", "n", "r"};

    std::string nameLast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd10 = rng() % std::size(nm9);
    rnd11 = rng() % std::size(nm10);
    rnd12 = rng() % std::size(nm12);
    rnd13 = rng() % std::size(nm11);
    rnd14 = rng() % std::size(nm10);
    if (i % 2 == 0) {
    rnd15 = rng() % std::size(nm11);
    rnd16 = rng() % std::size(nm10);
    nameLast = nm9[rnd10] + nm10[rnd11] + nm11[rnd13] + nm10[rnd14] + nm11[rnd15] + nm10[rnd16] + nm12[rnd12];
    } else {
    nameLast = nm9[rnd10] + nm10[rnd11] + nm11[rnd13] + nm10[rnd14] + nm12[rnd12];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 6) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + " " + nameLast;
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm8[rnd5] + " " + nameLast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 7) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + nameLast;
    } else {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + " " + nameLast;
    }
    }
    return names;
    }
}
