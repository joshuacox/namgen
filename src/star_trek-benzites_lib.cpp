#include "star_trek-benzites_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_benzites_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"b", "c", "d", "g", "j", "k", "m", "p", "q", "r", "t", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "u", "i", "o"};
    static constexpr std::string_view nm3[] = {"b", "d", "r", "rr", "dd", "zz", "rb", "rd", "rg", "rj", "rk", "rq", "rt", "rh", "rl", "rs", "rv", "nd", "ng", "nd", "nr", "nt", "nv", "dg", "zd", "zg", "zr"};
    static constexpr std::string_view nm4[] = {"ck", "n", "k", "d", "r", "z", "t", "g"};
    static constexpr std::string_view nm5[] = {"ar", "or", "ur", "an", "on", "un", "at", "ot", "ut", "az", "oz", "uz", "ab", "ob", "ub", "ad", "od", "ud", "ak", "ok", "uk", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm6[] = {"b", "c", "d", "g", "j", "k", "m", "p", "q", "r", "t", "v", "z"};
    static constexpr std::string_view nm7[] = {"b", "c", "d", "g", "h", "j", "k", "l", "p", "q", "r", "t", "v", "x", "y", "z", "cc", "dd", "gg", "kk", "pp", "qq", "rr", "tt", "vv", "xx", "zz"};
    static constexpr std::string_view nm8[] = {"n", "x", "q", "s", "th", "g", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm9[] = {"in", "en", "iq", "eq", "ix", "ex", "eth", "ith", "ez", "iz", "ey", "iy"};
    static constexpr std::string_view nm10[] = {"a", "e", "o", "u", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 5) {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm8);
    names = nm6[rnd] + nm2[rnd2] + nm7[rnd3] + nm2[rnd4] + nm8[rnd5];
    } else {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm9);
    rnd5 = rng() % std::size(nm10);
    names = nm6[rnd] + nm2[rnd2] + nm7[rnd3] + nm9[rnd4] + nm10[rnd5];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + nm5[rnd6];
    }
    return names;
    }
}
