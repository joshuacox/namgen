#include "fantasy-deaths_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_deaths_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "b", "bh", "br", "c", "ch", "ct", "cth", "d", "dr", "dh", "dy", "dz", "f", "fr", "g", "gh", "gn", "h", "hw", "k", "kh", "kn", "kr", "l", "m", "m", "mn", "mh", "m", "n", "ng", "p", "ph", "pr", "q", "qh", "s", "sh", "st", "sr", "t", "th", "v", "vr", "vh", "w", "wr", "x", "y"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ae", "ae", "ai", "aa", "eo", "ea", "ei", "io", "iu", "ia", "oo", "ou", "uu", "ua", "ue"};
    static constexpr std::string_view nm3[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ch", "g", "l", "m", "n", "p", "q", "r", "s", "z"};
    static constexpr std::string_view nm4[] = {"b", "c", "d", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "th", "tr", "w"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "", "", "", "", "", "", "c", "cs", "c", "d", "d", "h", "h", "k", "k", "ks", "l", "ls", "l", "n", "n", "ng", "nth", "q", "q", "r", "r", "rs", "s", "s", "t", "t", "th", "v", "x"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm5);
    if (i < 3) {
    while (rnd < 6) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 12) {
    rnd5 = rng() % std::size(nm5);
    }
    names = nm1[rnd] + nm2[rnd2] + nm5[rnd5];
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm2[rnd6] + nm5[rnd5];
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm3);
    rnd8 = rng() % std::size(nm4);
    rnd9 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm2[rnd6] + nm3[rnd7] + nm4[rnd8] + nm2[rnd9] + nm5[rnd5];
    }
    return names;
    }
}
