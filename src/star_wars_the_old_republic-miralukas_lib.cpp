#include "star_wars_the_old_republic-miralukas_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_the_old_republic_miralukas_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"A", "B", "Ch", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "", "", ""};
    static constexpr std::string_view nm2[] = {"i", "a", "o", "e", "u"};
    static constexpr std::string_view nm3[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z"};
    static constexpr std::string_view nm4[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm5[] = {"i", "a", "o", "e", "u", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm6[] = {"c", "d", "f", "h", "hr", "hk", "hl", "k", "l", "m", "n", "p", "r", "rr", "rth", "s", "t", "th", "y"};
    static constexpr std::string_view nm7[] = {"A", "B", "Ch", "D", "E", "F", "Fl", "G", "Gl", "H", "I", "J", "K", "L", "M", "N", "O", "P", "R", "S", "Sh", "Sl", "T", "U", "V", "W", "X", "Y", "Z"};
    static constexpr std::string_view nm8[] = {"i", "a", "o", "e", "u", "", "", ""};

    std::string names; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd2b = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm2);
    rnd2b = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm6);
    if (type == 1) {
    rnd1 = rng() % std::size(nm7);
    rnd5 = rng() % std::size(nm8);
    names = nm7[rnd1] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm2[rnd2b] + nm8[rnd5] + nm6[rnd6];
    } else {
    rnd1 = rng() % std::size(nm1);
    rnd5 = rng() % std::size(nm5);
    names = nm1[rnd1] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm2[rnd2b] + nm5[rnd5] + nm6[rnd6];
    }
    return names;
    }
}
