#include "fantasy-nephilims_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_nephilims_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "b", "d", "g", "h", "j", "k", "n", "p", "q", "r", "s", "sh", "t", "th", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "a", "e", "a", "e", "a", "e", "a", "e", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ya", "yu", "ee", "ie", "ue", "ia"};
    static constexpr std::string_view nm3[] = {"dr", "dj", "gr", "gn", "kb", "kn", "mj", "mr", "mz", "nz", "nq", "rq", "rm", "rj", "rz", "sb", "sz", "st", "tr", "tn", "tz", "b", "d", "g", "j", "k", "m", "n", "q", "r", "s", "t", "z", "b", "d", "g", "j", "k", "m", "n", "q", "r", "s", "t", "z", "b", "d", "g", "j", "k", "m", "n", "q", "r", "s", "t", "z"};
    static constexpr std::string_view nm4[] = {"l", "n", "s", "th", "z", "l", "l", "", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    if (nm1[rnd] == nm3[rnd3]) {
    rnd3 = rng() % std::size(nm3);
    }
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 4) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    } else {
    rnd6 = rng() % std::size(nm3);
    if (rnd3 < 21) {
    while (rnd6 < 21) {
    rnd6 = rng() % std::size(nm3);
    }
    }
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5];
    }
    return names;
    }
}
