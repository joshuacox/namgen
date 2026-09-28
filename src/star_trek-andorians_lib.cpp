#include "star_trek-andorians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_andorians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"a", "e", "o", "i", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"k", "r", "sh", "shr", "t", "th", "s", "b"};
    static constexpr std::string_view nm3[] = {"a", "e", "o", "i", "y"};
    static constexpr std::string_view nm4[] = {"r", "b", "l", "v", "n", "s", "ss", "th", "hr", "hl"};
    static constexpr std::string_view nm5[] = {"a", "e", "o", "i", "ia", "ao", "aa"};
    static constexpr std::string_view nm6[] = {"Th'", "Ch'"};
    static constexpr std::string_view nm7[] = {"Sh'", "Zh'"};
    static constexpr std::string_view nm8[] = {"zh", "sh", "th", "z", "v", "rh", "shr", "vh", "k", "t", "r", "ch", "q"};
    static constexpr std::string_view nm9[] = {"a", "e", "o", "i", "y", "ao", "ia", "aa"};
    static constexpr std::string_view nm10[] = {"r", "l", "v", "n", "th", "hr", "hl", "nn", "rh", "lr", "sr", "kr", "tr", "ln", "thr", "q", "ll", "rr"};
    static constexpr std::string_view nm11[] = {"a", "e", "o", "i"};
    static constexpr std::string_view nm12[] = {"th", "s", "ss", "n", "t", "r", "hr", "rh", "l", "k", "q"};
    static constexpr std::string_view nm13[] = {"vr", "thr", "v", "jh", "p", "t", "th", "s", "shr", "s", "z"};
    static constexpr std::string_view nm14[] = {"th", "r", "m", "ss", "v", "l", "ll", "r", "z", "t", "tt", "sh"};
    static constexpr std::string_view nm15[] = {"h", "s", "l", "ss", "n", "t", "th", "sh", "", "", "", "", "", "", "", "", "", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm13);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm14);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm15);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm1);
    rnd9 = rng() % std::size(nm8);
    rnd10 = rng() % std::size(nm9);
    rnd11 = rng() % std::size(nm10);
    rnd12 = rng() % std::size(nm11);
    rnd13 = rng() % std::size(nm12);
    names = nm1[rnd] + nm13[rnd2] + nm3[rnd3] + nm14[rnd4] + nm5[rnd5] + nm15[rnd6] + " " + nm7[rnd7] + nm1[rnd8] + nm8[rnd9] + nm9[rnd10] + nm10[rnd11] + nm11[rnd12] + nm12[rnd13];
    } else {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm1);
    rnd7 = rng() % std::size(nm8);
    rnd8 = rng() % std::size(nm9);
    rnd9 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm11);
    rnd11 = rng() % std::size(nm12);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + " " + nm6[rnd5] + nm1[rnd6] + nm8[rnd7] + nm9[rnd8] + nm10[rnd9] + nm11[rnd10] + nm12[rnd11];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm4);
    rnd7 = rng() % std::size(nm6);
    rnd8 = rng() % std::size(nm1);
    rnd9 = rng() % std::size(nm8);
    rnd10 = rng() % std::size(nm9);
    rnd11 = rng() % std::size(nm10);
    rnd12 = rng() % std::size(nm11);
    rnd13 = rng() % std::size(nm12);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm4[rnd6] + " " + nm6[rnd7] + nm1[rnd8] + nm8[rnd9] + nm9[rnd10] + nm10[rnd11] + nm11[rnd12] + nm12[rnd13];
    }
    }
    return names;
    }
}
