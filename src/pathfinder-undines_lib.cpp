#include "pathfinder-undines_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_undines_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "bh", "d", "dh", "g", "gh", "j", "kh", "m", "n", "r", "rh", "sh", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "a", "e", "i", "o", "a", "e", "i", "o", "a", "e", "i", "o", "a", "e", "i", "o", "a", "e", "i", "o", "aa", "oo"};
    static constexpr std::string_view nm3[] = {"b", "bd", "c", "cd", "d", "dd", "db", "g", "gd", "gv", "gn", "gm", "j", "k", "kb", "kd", "kn", "km", "kv", "m", "md", "mm", "mb", "n", "nn", "nb", "nd", "r", "rd", "rg", "rv", "rz", "v", "b", "c", "d", "g", "j", "k", "m", "n", "r", "v"};
    static constexpr std::string_view nm4[] = {"d", "hz", "j", "k", "m", "n", "r", "sh", "v"};
    static constexpr std::string_view nm5[] = {"", "", "", "b", "c", "d", "f", "h", "l", "m", "n", "p", "r", "s", "w", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "u", "a", "e", "i", "u", "a", "e", "i", "u", "a", "e", "i", "u", "a", "e", "i", "u", "y", "y", "y", "ya", "aa"};
    static constexpr std::string_view nm7[] = {"b", "bh", "d", "dz", "dh", "fd", "fn", "ff", "f", "fz", "hn", "hl", "hr", "hm", "h", "hh", "l", "lg", "ld", "lb", "lf", "ln", "m", "mm", "mn", "mr", "mf", "n", "nn", "nr", "nd", "nf", "nh", "r", "rh", "rb", "rv", "rd", "rz", "v", "vr", "b", "d", "f", "h", "l", "n", "m", "r", "v", "b", "d", "f", "h", "l", "n", "m", "r", "v"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "h", "n"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 5) {
    names = std::string(nm5[rnd]) + std::string(nm6[rnd2]) + std::string(nm7[rnd3]) + std::string(nm6[rnd4]) + std::string(nm8[rnd5]);
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = std::string(nm5[rnd]) + std::string(nm6[rnd2]) + std::string(nm7[rnd3]) + std::string(nm6[rnd4]) + std::string(nm7[rnd6]) + std::string(nm6[rnd7]) + std::string(nm8[rnd5]);
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 3) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm1);
    }
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm4[rnd5]);
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm4[rnd5]);
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm3[rnd6]) + std::string(nm2[rnd7]) + std::string(nm4[rnd5]);
    }
    }
    return names;
    }
}
