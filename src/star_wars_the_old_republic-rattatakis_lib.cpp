#include "star_wars_the_old_republic-rattatakis_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_the_old_republic_rattatakis_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"a", "e", "i", "o", "u", "ai", "au", "ei", "ou", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"b", "br", "bz", "bj", "c", "cz", "ch", "d", "dj", "dz", "g", "gr", "h", "j", "k", "kz", "kr", "p", "pr", "pj", "pz", "q", "r", "sj", "st", "sr", "t", "ts", "tr", "v", "wr", "x", "xj", "xr", "yj", "yr", "ys", "yz", "z", "zr"};
    static constexpr std::string_view nm3[] = {"i", "a", "o", "e", "u"};
    static constexpr std::string_view nm4[] = {"c", "ch", "dj", "g", "gr", "h", "k", "m", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z"};
    static constexpr std::string_view nm5[] = {"c", "ch", "dj", "g", "gr", "h", "k", "m", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "i", "o", "u", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "ai", "au", "ei", "ou", "ay", "ey", "oy", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm7[] = {"b", "br", "bj", "c", "cz", "ch", "d", "dj", "dz", "g", "h", "j", "k", "kz", "l", "m", "n", "p", "pr", "pj", "q", "r", "s", "sj", "st", "sr", "t", "ts", "tr", "v", "w", "wr", "x", "xj", "xr", "y", "yj", "yr", "ys", "yz", "z", "zr"};
    static constexpr std::string_view nm8[] = {"i", "a", "o", "e", "u", "ie", "ai", "ey", "ay"};

    std::string names; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; int i = 0;

i = rng() % 10; {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    if (type == 1) {
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    names = nm6[rnd6] + nm7[rnd7] + nm8[rnd8] + nm4[rnd4] + nm3[rnd3] + nm5[rnd5];
    } else {
    rnd6 = rng() % std::size(nm1);
    rnd7 = rng() % std::size(nm2);
    rnd8 = rng() % std::size(nm3);
    names = nm1[rnd6] + nm2[rnd7] + nm3[rnd8] + nm4[rnd4] + nm3[rnd3] + nm5[rnd5];
    }
    return names;
    }
}
