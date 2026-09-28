#include "pathfinder-oreads_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_oreads_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "b", "d", "g", "j", "l", "m", "n", "p", "r", "s", "t", "v"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "o", "u", "y"};
    static constexpr std::string_view nm3[] = {"d", "dd", "f", "fd", "ft", "hd", "hn", "hv", "l", "ll", "ln", "lm", "ld", "lv", "lt", "lth", "lm", "m", "md", "mt", "mh", "mv", "n", "nd", "nt", "nv", "nh", "nn", "nm", "nh", "nr", "r", "rt", "rh", "rn", "rm", "rl", "rv", "rr", "rd", "th", "tr", "thr", "v", "vh", "vr"};
    static constexpr std::string_view nm4[] = {"", "m", "n", "r", "s", "t"};
    static constexpr std::string_view nm5[] = {"", "", "", "b", "bh", "d", "dh", "gh", "h", "l", "m", "n", "p", "r", "rh", "s", "sh", "t", "th", "v", "w"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "i", "e"};
    static constexpr std::string_view nm7[] = {"c", "ch", "d", "dh", "f", "ff", "fh", "fth", "h", "hn", "hv", "hl", "hs", "l", "lh", "ln", "lm", "ls", "lsh", "m", "mn", "mm", "mh", "my", "n", "nn", "nh", "ny", "ns", "nth", "nf", "r", "ry", "rh", "rs", "rsh", "rth", "s", "sh", "sth", "sht", "sn", "sm", "sy", "sl", "t", "th", "ty", "thy", "y"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    if (i < 5) {
    names = std::string(nm5[rnd]) + std::string(nm6[rnd2]) + std::string(nm7[rnd3]) + std::string(nm6[rnd4]);
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = std::string(nm5[rnd]) + std::string(nm6[rnd2]) + std::string(nm7[rnd3]) + std::string(nm6[rnd4]) + std::string(nm7[rnd6]) + std::string(nm6[rnd7]);
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm4[rnd5]);
    } else {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm3[rnd6]) + std::string(nm2[rnd7]) + std::string(nm4[rnd5]);
    }
    }
    return names;
    }
}
