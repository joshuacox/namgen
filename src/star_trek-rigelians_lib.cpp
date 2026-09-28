#include "star_trek-rigelians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_rigelians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"B", "C", "Ch", "D", "G", "Gr", "K", "Kr", "M", "Pr", "R", "Sr", "Sch", "T", "V", "Vr", "W", "Z"};
    static constexpr std::string_view nm2[] = {"a", "ae", "ei", "i", "o", "ou", "u", "a", "u", "a", "u", "o", "ii", "ea", "oo", "aa", "a", "u"};
    static constexpr std::string_view nm3[] = {"b", "b", "ch", "d", "g", "d", "g", "gr", "k", "l", "m", "n", "t", "v", "w", "k", "l", "m", "n", "t", "v", "w", "xt", "y", "z", "y", "z", "zy"};
    static constexpr std::string_view nm4[] = {"d", "k", "l", "lr", "n", "p", "r", "t", "v", "", ""};
    static constexpr std::string_view nm5[] = {"B", "C", "H", "J", "K", "Kh", "R", "S", "Sh", "X", "Y", "Z", "Zh"};
    static constexpr std::string_view nm6[] = {"a", "ae", "ei", "i", "o", "ou", "u", "a", "u", "a", "u", "o", "ii", "ea", "oo", "aa", "oi", "ee"};
    static constexpr std::string_view nm7[] = {"c", "ch", "gg", "gr", "l", "ll", "ln", "ngy", "ng", "n", "m", "s", "st", "sh", "shw", "v", "ys", "w", "wr", "c", "g", "l", "s", "v", "w", "c", "g", "l", "s", "v", "w", "n", "n", "m", "m"};
    static constexpr std::string_view nm8[] = {"d", "l", "n", "m", "s", "x", "", "", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 5) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5];
    } else {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm8);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd5] + nm6[rnd6] + nm8[rnd7];
    }
    } else {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd5] + nm2[rnd6] + nm4[rnd7];
    }
    }
    return names;
    }
}
