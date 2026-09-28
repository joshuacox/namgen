#include "star_wars-anzatis_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_anzatis_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "b", "d", "g", "h", "k", "m", "n", "r", "s", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"ct", "cn", "cm", "gr", "kk", "kr", "kt", "ll", "lf", "lg", "lr", "ld", "nn", "nt", "nr", "mr", "mm", "md", "rr", "rk", "rt", "st", "sn", "sm", "th", "sh", "tt", "tr", "zz"};
    static constexpr std::string_view nm4[] = {"", "", "", "c", "h", "k", "l", "n", "nt", "r", "s", "th"};
    static constexpr std::string_view nm5[] = {"b", "c", "d", "f", "h", "k", "l", "m", "n", "r", "s"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ea", "ia"};
    static constexpr std::string_view nm7[] = {"d", "f", "g", "j", "k", "l", "m", "n", "r", "sh", "th", "mm", "nn", "ll", "dh", "mh", "nh", "kr", "dr", "gr", "ml", "kl"};
    static constexpr std::string_view nm8[] = {"b", "d", "g", "h", "j", "k", "l", "m", "n", "r", "s", "t", "v", "y", "z"};
    static constexpr std::string_view nm9[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ou", "ei", "ea", "ia"};
    static constexpr std::string_view nm10[] = {"ct", "cn", "cm", "gr", "kk", "kr", "kt", "ll", "lg", "lf", "ld", "lr", "lkk", "k", "mm", "mr", "md", "nn", "nr", "nd", "nt", "nn", "r", "rr", "rt", "rkk", "sh", "st", "sn", "sm", "th", "sh", "tt", "tr", "zz"};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm8);
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd9 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm4);
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + "  " + nm8[rnd6] + nm9[rnd7] + nm10[rnd8] + nm9[rnd9] + nm4[rnd10];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + nm8[rnd6] + nm9[rnd7] + nm10[rnd8] + nm9[rnd9] + nm4[rnd10];
    }
    return names;
    }
}
