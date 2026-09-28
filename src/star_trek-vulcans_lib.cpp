#include "star_trek-vulcans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_vulcans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Ch", "D", "F", "H", "J", "K", "L", "M", "N", "P", "S", "Sk", "Sp", "St", "Str", "T", "T'K", "V", "V'L", "S", "Sk", "Sp", "St", "Str", "S"};
    static constexpr std::string_view nm2[] = {"aa", "ia", "au", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "y"};
    static constexpr std::string_view nm3[] = {"d", "f", "j", "kk", "l", "ll", "lk", "lv", "n", "p", "r", "rr", "s", "str", "ss", "t", "v"};
    static constexpr std::string_view nm4[] = {"", "", "c", "ck", "k", "k", "k", "l", "lk", "m", "n", "nn", "r", "rk", "s", "ss", "t", "tt", "th", "v"};
    static constexpr std::string_view nm5[] = {"f", "h", "l", "m", "n", "s", "t's", "t'r", "t'h", "t'l", "t'm", "t'p", "t'pl", "t'pr", "t'sh", "v'l", "v"};
    static constexpr std::string_view nm6[] = {"", "", "", "", "", "f", "h", "l", "m", "n", "s", "t's", "t'r", "t'h", "t'l", "t'm", "t'p", "t'pl", "t'pr", "t'sh", "v'l", "v"};
    static constexpr std::string_view nm7[] = {"aa", "ai", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm8[] = {"k", "l", "m", "n", "nv", "nn", "r", "rr", "s", "ss", "t", "v"};
    static constexpr std::string_view nm9[] = {"", "", "k", "l", "n", "ng", "r", "s", "th"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 5) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm7);
    rnd3 = rng() % std::size(nm9);
    names = nm5[rnd] + nm7[rnd2] + nm9[rnd3];
    } else {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm7);
    rnd3 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm7);
    if (rnd2 < 2) {
    while (rnd4 < 2) {
    rnd4 = rng() % std::size(nm7);
    }
    }
    rnd5 = rng() % std::size(nm9);
    names = nm6[rnd] + nm7[rnd2] + nm8[rnd3] + nm7[rnd4] + nm9[rnd5];
    }
    } else {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd3];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    if (rnd2 < 3) {
    while (rnd4 < 3) {
    rnd4 = rng() % std::size(nm2);
    }
    }
    rnd5 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    }
    }
    return names;
    }
}
