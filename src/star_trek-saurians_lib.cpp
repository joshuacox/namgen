#include "star_trek-saurians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_saurians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "d", "g", "j", "k", "kr", "m", "n", "pl", "r", "st", "t", "y", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"g", "gz", "ggt", "j", "k", "kz", "kr", "km", "l", "m", "mz", "nz", "n", "nn", "r", "rr", "rk", "rd", "t", "tg", "tk", "zk", "zr", "zg", "z", "g", "j", "k", "l", "m", "n", "r", "t", "z", "g", "j", "k", "l", "m", "n", "r", "t", "z"};
    static constexpr std::string_view nm4[] = {"c", "chv", "g", "gt", "k", "n", "s", "ss", "t", "tt", "z"};
    static constexpr std::string_view nm5[] = {"a", "e", "i", "o", "u", "ee", "ii", "", ""};
    static constexpr std::string_view nm6[] = {"g", "gz", "ggt", "j", "k", "kz", "kr", "km", "l", "m", "mz", "nz", "n", "nn", "r", "rr", "rk", "rd", "t", "tg", "tk", "zk", "zr", "zg", "z", "c", "chv", "g", "gt", "k", "n", "s", "ss", "t", "tt", "z"};
    static constexpr std::string_view nm7[] = {"", "", "c", "g", "gl", "h", "j", "k", "l", "n", "m", "r", "s", "sh", "y"};
    static constexpr std::string_view nm8[] = {"a", "e", "i", "o", "u", "ia", "ie", "uo", "ai", "uu", "oo", "ae", "uoa"};
    static constexpr std::string_view nm9[] = {"gr", "gg", "g", "gt", "h", "l", "m", "n", "nn", "q", "qq", "r", "rr", "sh", "s", "ss", "t", "tt", "v", "y", "z"};
    static constexpr std::string_view nm10[] = {"", "", "", "", "", "", "", "", "ch", "g", "m", "n", "s"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 5) {
    rnd = rng() % std::size(nm7);
    rnd2 = rng() % std::size(nm8);
    rnd3 = rng() % std::size(nm9);
    rnd4 = rng() % std::size(nm8);
    if (rnd2 > 4) {
    while (rnd4 > 4) {
    rnd4 = rng() % std::size(nm8);
    }
    }
    rnd5 = rng() % std::size(nm10);
    names = nm7[rnd] + nm8[rnd2] + nm9[rnd3] + nm8[rnd4] + nm10[rnd5];
    } else {
    rnd = rng() % std::size(nm7);
    rnd2 = rng() % std::size(nm8);
    rnd3 = rng() % std::size(nm9);
    rnd4 = rng() % std::size(nm8);
    if (rnd2 > 4) {
    while (rnd4 > 4) {
    rnd4 = rng() % std::size(nm8);
    }
    }
    rnd5 = rng() % std::size(nm9);
    rnd6 = rng() % std::size(nm8);
    if (rnd2 > 4 || rnd4 > 4) {
    while (rnd6 > 4) {
    rnd6 = rng() % std::size(nm8);
    }
    }
    rnd7 = rng() % std::size(nm10);
    names = nm7[rnd] + nm8[rnd2] + nm9[rnd3] + nm8[rnd4] + nm9[rnd5] + nm8[rnd6] + nm10[rnd7];
    }
    } else {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm6[rnd3] + nm5[rnd6];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + nm5[rnd6];
    }
    }
    return names;
    }
}
