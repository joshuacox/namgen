#include "fantasy-lichs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_lichs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "bh", "br", "bz", "c", "ch", "cr", "cz", "d", "dh", "dr", "g", "gh", "gr", "h", "j", "k", "kh", "kr", "m", "mh", "n", "nh", "p", "pr", "ps", "ph", "q", "qh", "qr", "r", "rh", "s", "sc", "sh", "sk", "sq", "sr", "st", "str", "sz", "t", "th", "tr", "ts", "tz", "v", "vh", "vr", "x", "xh", "z", "zh"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "y", "y", "y", "au", "aa", "ae", "ai", "ea", "ee", "ia", "oo", "ou", "ua"};
    static constexpr std::string_view nm3[] = {"b", "br", "b'gh", "bz", "c", "cq", "cr", "ch", "cd", "cn", "cm", "cz", "c'z", "c'n", "c'm", "c'dh", "d", "dd", "dh", "dr", "dz", "d'z", "d'gh", "g", "gg", "gh", "gd", "g'd", "gn", "gm", "gr", "g'sh", "gv", "g'v", "gz", "g'z", "j", "k", "kd", "kh", "kk", "kn", "kr", "kt", "kv", "kz", "k'z", "k'n", "k'm", "k'sh", "k'v", "l", "ld", "lg", "lk", "lq", "lz", "lx", "l'z", "l'x", "l'q", "l'kh", "md", "m'g", "m'gh", "mk", "m'q", "mz", "m'z", "nc", "nd", "ng", "n'g", "n'gh", "nk", "nq", "n'q", "nz", "q", "q'd", "q'g", "qn", "q'r", "q'z", "r", "rr", "rc", "rd", "rg", "rgh", "rk", "rq", "rz", "r'z", "r'g", "r'gh", "r'q", "s", "sz", "sc", "sg", "sk", "s'q", "s'z", "st", "s't", "t", "th", "tr", "t'g", "th'g", "t'z", "t'q", "x", "xh", "x'r", "x'z", "xz", "z", "zz", "zc", "zd", "zg", "z'q", "z'g", "z'dh", "zh"};
    static constexpr std::string_view nm4[] = {"c", "d", "g", "k", "l", "n", "q", "r", "gh", "gn", "gr"};
    static constexpr std::string_view nm5[] = {"", "", "c", "d", "dh", "g", "k", "l", "n", "q", "r", "s", "x", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm5);
    if (i < 6) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm5[rnd5];
    } else {
    rnd6 = rng() % std::size(nm2);
    if (rnd2 > 50 || rnd4 > 50) {
    while (rnd6 > 50) {
    rnd6 = rng() % std::size(nm2);
    }
    }
    rnd7 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd7] + nm2[rnd6] + nm5[rnd5];
    }
    return names;
    }
}
