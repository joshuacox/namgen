#include "pathfinder-kobolds_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_kobolds_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "br", "cr", "dr", "d", "dh", "g", "gh", "gr", "j", "k", "m", "n", "q", "qr", "r", "rh", "v", "vr", "vh", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "i", "o", "a", "i", "o", "aa", "ea", "oo", "ee"};
    static constexpr std::string_view nm3[] = {"d", "dd", "dr", "dz", "dh", "gn", "gm", "gr", "gz", "gh", "k", "kk", "kn", "kz", "km", "kr", "l", "lz", "ll", "lr", "ld", "ln", "m", "mk", "mz", "n", "nz", "nr", "pm", "pz", "pr", "r", "rl", "rn", "rm", "rg", "rk", "rd", "rz", "rr", "t", "tr", "tz", "x", "zh", "z", "zz", "zr", "zk"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "b", "d", "g", "k", "l", "ld", "lk", "lp", "n", "nk", "p", "rk", "s", "sk", "x"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "d", "f", "g", "h", "l", "m", "n", "p", "r", "s", "t", "v", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "o", "a", "o", "a", "o", "aa", "ia", "ai", "ee"};
    static constexpr std::string_view nm7[] = {"d", "dk", "dr", "gr", "gl", "g", "h", "hr", "k", "kr", "kkr", "ks", "l", "lr", "lk", "ls", "r", "rk", "rs", "rg", "rl", "s", "ss", "sr", "sk", "sg", "sgr", "skr", "ssr", "tr", "th", "thr", "z", "zr", "zk", "zn", "zl"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "h", "k", "l", "n", "m", "r", "s"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm8);
    if (i < 8) {
    names = std::string(nm5[rnd]) + std::string(nm2[rnd2]) + std::string(nm7[rnd3]) + std::string(nm2[rnd4]) + std::string(nm8[rnd5]);
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm2);
    names = std::string(nm5[rnd]) + std::string(nm2[rnd2]) + std::string(nm7[rnd3]) + std::string(nm2[rnd4]) + std::string(nm7[rnd6]) + std::string(nm2[rnd7]) + std::string(nm8[rnd5]);
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 3) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 5) {
    rnd5 = rng() % std::size(nm4);
    }
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm4[rnd5]);
    } else if (i < 7) {
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
