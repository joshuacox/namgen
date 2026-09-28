#include "elder_scrolls-forsworns_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_elder_scrolls_forsworns_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "br", "d", "dr", "g", "gr", "h", "k", "m", "n", "p", "pr", "r", "s", "t", "tr", "v", "w"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "ey", "ay", "ai", "ua", "uu", "uo", "au"};
    static constexpr std::string_view nm3[] = {"br", "bb", "cc", "cr", "cd", "d", "dv", "dr", "dl", "gv", "gl", "gm", "gn", "gr", "l", "lr", "lm", "ln", "lk", "lv", "ld", "lc", "mr", "ml", "mm", "mv", "md", "n", "nn", "nd", "nb", "nv", "nr", "ng", "r", "rk", "rv", "rg", "rd", "rb", "rt", "st", "sl", "sr", "v", "vv", "vr", "vl"};
    static constexpr std::string_view nm4[] = {"c", "ch", "d", "g", "l", "n", "r", "s"};
    static constexpr std::string_view nm5[] = {"b", "d", "f", "g", "h", "j", "k", "l", "m", "n", "r", "s", "t", "v", "w"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "o"};
    static constexpr std::string_view nm7[] = {"uai", "aie", "eia", "uae", "iae", "iea", "ai", "ua", "ea", "ia", "ei"};
    static constexpr std::string_view nm8[] = {"d", "f", "g", "h", "l", "m", "n", "r", "s", "t", "v", "w", "z"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "a", "e", "i", "o", "u", "a", "e", "o"};
    static constexpr std::string_view nm10[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "b", "br", "d", "dr", "g", "gr", "h", "k", "m", "n", "p", "pr", "r", "s", "t", "tr", "v", "w"};

    std::string nameLast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd8a = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd8a = rng() % std::size(nm10);
    rnd8 = rng() % std::size(nm6);
    rnd9 = rng() % std::size(nm3);
    rnd10 = rng() % std::size(nm6);
    rnd11 = rng() % std::size(nm8);
    rnd12 = rng() % std::size(nm9);
    nameLast = nm10[rnd8a] + nm6[rnd8] + nm3[rnd9] + nm6[rnd10] + nm8[rnd11] + nm9[rnd12];
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm7);
    if (i < 3) {
    names = nm5[rnd] + nm7[rnd2] + "  " + nameLast;
    } else if (i < 7) {
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd3] + nm6[rnd4] + " " + nameLast;
    } else {
    rnd = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm8);
    names = nm7[rnd2] + nm8[rnd3] + nm6[rnd] + " " + nameLast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + nameLast;
    } else if (i < 8) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + nameLast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + " " + nameLast;
    }
    }
    return names;
    }
}
