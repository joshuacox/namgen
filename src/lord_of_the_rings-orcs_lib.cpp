#include "lord_of_the_rings-orcs_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_lord_of_the_rings_orcs_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"b", "br", "c", "cr", "d", "dr", "g", "gh", "gr", "k", "kr", "l", "m", "r", "s", "sh", "sr"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "au"};
    static constexpr std::string_view nm3[] = {"cb", "cd", "cr", "db", "dd", "fd", "fth", "g", "gb", "gd", "gg", "gl", "gr", "gz", "h", "lcm", "ld", "lf", "lg", "rb", "rc", "rd", "rg", "rz", "shn", "thr", "z", "zb", "zg", "zr", "zz"};
    static constexpr std::string_view nm4[] = {"c", "d", "dh", "f", "g", "gh", "kh", "l", "r", "rg", "sh", "t", "th", "", "", ""};
    static constexpr std::string_view nm5[] = {"a", "o", "u", "au"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

    i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm4[rnd5]);
    } else {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm4);
    names = std::string(nm5[rnd]) + std::string(nm3[rnd2]) + std::string(nm2[rnd3]) + std::string(nm4[rnd4]);
    }
    return names;
    }
}
