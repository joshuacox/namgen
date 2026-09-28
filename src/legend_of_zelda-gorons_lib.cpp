#include "legend_of_zelda-gorons_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_legend_of_zelda_gorons_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"B", "D", "G", "K", "M", "N", "R", "T"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "o"};
    static constexpr std::string_view nm3[] = {"b", "br", "bl", "d", "dr", "dl", "g", "gr", "gl", "gg", "g", "gr", "gl", "gg", "g", "gr", "gl", "gg", "g", "gr", "gl", "gg", "l", "lg", "lb", "ld", "m", "mr", "md", "mb", "n", "nd", "nl", "nb", "ng", "r", "rb", "rg", "rd", "rk", "rm", "rtr", "t", "z", "kb", "kl", "km", "kn", "kd", "b", "d", "g", "k", "l", "m", "n", "r", "t", "z", "b", "d", "g", "k", "l", "m", "n", "r", "t", "z", "b", "d", "g", "k", "l", "m", "n", "r", "t", "z", "b", "d", "g", "k", "l", "m", "n", "r", "t", "z", "b", "d", "g", "k", "l", "m", "n", "r", "t", "z"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "", "", "", "", "", "k", "g", "ck", "gs", "m", "n", "s"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm2);
    if (i < 4) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm4[rnd4];
    } else {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm3[rnd6] + nm2[rnd7] + nm4[rnd4];
    if (i > 7) {
    rnd8 = rng() % std::size(nm3);
    rnd9 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm3[rnd6] + nm2[rnd7] + nm3[rnd8] + nm2[rnd9] + nm4[rnd4];
    }
    }
    return names;
    }
}
