#include "star_wars-hutts_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_hutts_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "bl", "br", "bw", "c", "ch", "d", "dr", "f", "g", "gl", "gr", "h", "j", "k", "kh", "kl", "kr", "l", "m", "n", "p", "pl", "pr", "q", "r", "s", "sh", "sk", "sm", "sp", "sz", "t", "tr", "v", "w", "wh", "y", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "aa", "uu", "ee", "io", "oo", "eu", "ua", "ai", "oa", "oe", "ae"};
    static constexpr std::string_view nm3[] = {"b", "bb", "bd", "bs", "ch", "chr", "d", "dd", "ddl", "ff", "ffr", "g", "gg", "gh", "gr", "j", "jj", "k", "kk", "l", "lb", "ld", "lg", "ll", "ln", "lr", "lt", "m", "mb", "mdr", "mr", "n", "nd", "ng", "ngr", "nj", "nn", "nt", "nv", "ny", "pp", "q", "r", "rb", "rbl", "rchr", "rd", "rdr", "rg", "rgr", "rk", "rl", "rp", "rph", "rr", "rrb", "rrg", "rs", "rt", "rv", "rz", "s", "sh", "sk", "skh", "ss", "st", "t", "th", "tj", "tt", "v", "w", "wn", "x", "yb"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "", "", "b", "c", "d", "g", "gg", "h", "hl", "k", "l", "lb", "ll", "m", "n", "nn", "r", "rd", "rg", "rgg", "rm", "s", "sch", "sh", "sk", "ss", "th", "x", "z", "zz"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd8 = rng() % std::size(nm1);
    rnd9 = rng() % std::size(nm2);
    rnd12 = rng() % std::size(nm4);
    if (i % 2 == 0) {
    rnd10 = rng() % std::size(nm3);
    rnd11 = rng() % std::size(nm2);
    namelast = nm1[rnd8] + nm2[rnd9] + nm3[rnd10] + nm2[rnd11] + nm4[rnd12];
    } else {
    while (rnd8 < 5) {
    rnd8 = rng() % std::size(nm1);
    }
    while (rnd12 < 9) {
    rnd12 = rng() % std::size(nm4);
    }
    namelast = nm1[rnd8] + nm2[rnd9] + nm4[rnd12];
    }
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 7) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + "  " + namelast;
    } else {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + "  " + namelast;
    }
    return names;
    }
}
