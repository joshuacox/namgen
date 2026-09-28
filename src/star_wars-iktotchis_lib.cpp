#include "star_wars-iktotchis_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_iktotchis_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "c", "d", "f", "h", "k", "m", "n", "r", "s", "t", "v", "w", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ee", "ae", "ie", "ye", "yi", "ei"};
    static constexpr std::string_view nm3[] = {"d", "dh", "f", "fl", "fn", "l", "ll", "ld", "ln", "lm", "lr", "lv", "m", "mm", "md", "mr", "mn", "mk", "n", "nn", "nh", "nk", "ng", "nv", "nl", "r", "rr", "rn", "rl", "rk", "rd", "s", "sl", "sh", "shk"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "j", "l", "m", "n", "r", "s", "th"};
    static constexpr std::string_view nm5[] = {"ch", "d", "h", "j", "k", "m", "n", "t", "v", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "a", "e", "i", "a", "e", "i", "o", "u", "aa", "ii"};
    static constexpr std::string_view nm7[] = {"d", "f", "h", "j", "l", "m", "n", "r", "s", "v", "w", "z"};
    static constexpr std::string_view nm8[] = {"", "", "l", "mm", "n", "r", "s"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm5);
    rnd7 = rng() % std::size(nm6);
    rnd8 = rng() % std::size(nm8);
    if (i % 2 == 0) {
    rnd9 = rng() % std::size(nm7);
    rnd10 = rng() % std::size(nm6);
    namelast = nm5[rnd6] + nm6[rnd7] + nm7[rnd9] + nm6[rnd10] + nm8[rnd8];
    } else {
    namelast = nm5[rnd6] + nm6[rnd7] + nm8[rnd8];
    }
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    return names;
    }
}
