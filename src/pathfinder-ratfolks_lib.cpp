#include "pathfinder-ratfolks_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_ratfolks_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "", "b", "br", "c", "cr", "ch", "d", "dr", "dj", "g", "gr", "gn", "gl", "j", "k", "kr", "kv", "kn", "m", "n", "p", "pr", "r", "s", "st", "sr", "skr", "sc", "scr", "sk", "t", "tr", "v", "vr", "z", "zr"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "a", "e", "i"};
    static constexpr std::string_view nm3[] = {"cc", "cd", "cr", "gg", "gr", "gk", "gv", "gd", "kk", "kr", "kv", "kz", "m", "mm", "md", "mk", "mv", "mz", "n", "nn", "nd", "nv", "nk", "ng", "nz", "rr", "r", "rk", "rv", "rz", "rc", "rg", "rd", "vv", "v", "vd", "vk", "vz"};
    static constexpr std::string_view nm4[] = {"c", "g", "c", "g", "hl", "hz", "hk", "hn", "hc", "k", "m", "n", "q", "r", "s", "t", "z", "k", "m", "n", "q", "r", "s", "t", "z"};
    static constexpr std::string_view nm5[] = {"b", "bh", "c", "ch", "dh", "f", "fr", "fh", "gh", "j", "k", "m", "n", "nh", "p", "r", "s", "sh", "t", "th", "v", "vh", "z", "zh"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "e", "e", "e", "i", "i", "i"};
    static constexpr std::string_view nm7[] = {"b", "bb", "c", "cc", "f", "ff", "g", "gg", "j", "k", "kk", "l", "ll", "m", "mm", "n", "nn", "p", "pp", "r", "rr", "s", "ss", "t", "tt", "z", "zz"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "ch", "f", "hm", "hl", "ks", "l", "m", "n", "r", "s", "sh", "t", "th", "tch", "x"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 5) {
    while (rnd5 < 8) {
    rnd5 = rng() % std::size(nm8);
    }
    names = std::string(nm5[rnd]) + std::string(nm6[rnd2]) + std::string(nm8[rnd5]);
    } else {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = std::string(nm5[rnd]) + std::string(nm6[rnd2]) + std::string(nm7[rnd3]) + std::string(nm6[rnd4]) + std::string(nm8[rnd5]);
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    while (rnd < 7) {
    rnd = rng() % std::size(nm1);
    }
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm4[rnd5]);
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm4[rnd5]);
    }
    }
    return names;
    }
}
