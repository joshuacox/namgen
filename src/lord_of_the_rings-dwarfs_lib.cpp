#include "lord_of_the_rings-dwarfs_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_lord_of_the_rings_dwarfs_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"b", "br", "d", "dr", "dw", "f", "fl", "fr", "g", "gl", "gr", "k", "kh", "kr", "l", "m", "mh", "n", "t", "th", "thr"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"b", "f", "fr", "l", "lb", "lr", "lv", "m", "mb", "ml", "mr", "n", "nd", "nr", "r", "rb", "rl", "rv", "s", "sr"};
    static constexpr std::string_view nm4[] = {"k", "m", "n", "r"};
    static constexpr std::string_view nm5[] = {"a", "ai", "e", "i", "o", "oi", "u"};
    static constexpr std::string_view nm6[] = {"b", "d", "f", "g", "k", "l", "m", "n", "t"};
    static constexpr std::string_view nm7[] = {"a", "e", "i", "o", "u", "", "", "", ""};

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
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm5);
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm7);
    names = std::string(nm1[rnd]) + std::string(nm5[rnd2]) + std::string(nm6[rnd3]) + std::string(nm7[rnd4]);
    }
    return names;
    }
}
