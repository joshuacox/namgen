#include "final_fantasy-lalafells_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_final_fantasy_lalafells_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "w", "y", "ch", "sh"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "w", "y", "ch", "sh"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "r", "l", "s", "n", "g"};
    static constexpr std::string_view nm5[] = {"", "a", "e", "i", "o", "u"};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm1);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm1[rnd] + nm2[rnd2] + nm1[rnd3] + nm2[rnd4] + " " + nm1[rnd] + nm2[rnd2] + nm1[rnd3] + nm2[rnd4];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm1);
    rnd4 = rng() % std::size(nm2);
    names = nm3[rnd] + nm2[rnd2] + nm1[rnd3] + nm2[rnd4] + nm1[rnd3] + nm2[rnd4] + " " + nm3[rnd] + nm2[rnd2] + nm1[rnd3] + nm2[rnd4];
    }
    } else {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm1);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm1);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm1);
    rnd8 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm1[rnd] + nm2[rnd2] + nm1[rnd3] + nm2[rnd4] + nm1[rnd5] + nm2[rnd6] + " " + nm1[rnd7] + nm2[rnd8] + nm1[rnd7] + nm2[rnd8] + nm1[rnd3] + nm2[rnd4] + nm1[rnd5] + nm2[rnd6];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm1);
    rnd5 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm5);
    if (rnd6 < 15) {
    rnd7 = 0;
    }
    if (rnd6 > 14) {
    while (rnd7 == 0) {
    rnd7 = rng() % std::size(nm5);
    }
    }
    rnd8 = rng() % std::size(nm4);
    rnd9 = rng() % std::size(nm1);
    rnd10 = rng() % std::size(nm2);
    rnd11 = rng() % std::size(nm3);
    rnd12 = rng() % std::size(nm5);
    if (rnd11 < 15) {
    rnd12 = 0;
    }
    if (rnd11 > 14) {
    while (rnd12 == 0) {
    rnd12 = rng() % std::size(nm5);
    }
    }
    names = nm3[rnd] + nm2[rnd2] + nm4[rnd3] + nm1[rnd4] + nm2[rnd5] + nm3[rnd6] + nm5[rnd7] + nm4[rnd8] + " " + nm1[rnd9] + nm2[rnd10] + nm3[rnd11] + nm5[rnd12] + nm1[rnd4] + nm2[rnd5] + nm3[rnd6] + nm5[rnd7] + nm4[rnd8];
    }
    }
    return names;
    }
}
