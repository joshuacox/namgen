#include "game_of_thrones-summer_islanders_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_game_of_thrones_summer_islanders_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"B", "Bh", "D", "J", "M", "S", "T", "X", "Xh", "Z", "Zh"};
    static constexpr std::string_view nm2[] = {"a", "o", "a"};
    static constexpr std::string_view nm3[] = {"b", "bh", "dh", "l", "lth", "ll", "lh", "n", "nt", "qu", "r", "rr"};
    static constexpr std::string_view nm4[] = {"r", "l", "", "r", "l", "s"};
    static constexpr std::string_view nm5[] = {"Ch", "H", "J", "L", "M", "N", "R", "S", "T", "X", "Xh", "Z", "Zh"};
    static constexpr std::string_view nm6[] = {"dh", "l", "ll", "lh", "n", "nd", "nt", "r", "rr", "t", "s", "z"};
    static constexpr std::string_view nm7[] = {"Ch", "D", "Q", "Qh", "R", "Rh", "S", "T", "X", "Xh", "Z", "Zh"};
    static constexpr std::string_view nm8[] = {"a", "o", "a", "aa"};
    static constexpr std::string_view nm9[] = {"", "", "qu", "d", "l", "m", "n", "q", "r", "s", "x"};
    static constexpr std::string_view nm10[] = {"", "a", "o", "a"};
    static constexpr std::string_view nm11[] = {"", "", "", "n", "q", "s"};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd2b = 0; size_t rnd2c = 0; size_t rnd3 = 0; size_t rnd3b = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd6b = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm2);
    rnd2b = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    rnd9 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    if (rnd9 < 3) {
    rnd10 = 0;
    }
    if (rnd10 == 0) {
    rnd11 = 0;
    }
    if (type == 1) {
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    if (i < 5) {
    names = nm5[rnd5] + nm2[rnd2] + nm6[rnd6] + nm2[rnd2b] + " " + nm7[rnd7] + nm8[rnd8] + nm9[rnd9] + nm10[rnd10] + nm11[rnd11];
    } else {
    rnd6b = rng() % std::size(nm6);
    rnd2c = rng() % std::size(nm2);
    names = nm5[rnd5] + nm2[rnd2] + nm6[rnd6] + nm2[rnd2b] + nm6[rnd6b] + nm2[rnd2c] + " " + nm7[rnd7] + nm8[rnd8] + nm9[rnd9] + nm10[rnd10] + nm11[rnd11];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd2b] + nm4[rnd4] + " " + nm7[rnd7] + nm8[rnd8] + nm9[rnd9] + nm10[rnd10] + nm11[rnd11];
    } else {
    rnd3b = rng() % std::size(nm3);
    rnd2c = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd2b] + nm3[rnd3b] + nm2[rnd2c] + nm4[rnd4] + " " + nm7[rnd7] + nm8[rnd8] + nm9[rnd9] + nm10[rnd10] + nm11[rnd11];
    }
    }
    return names;
    }
}
