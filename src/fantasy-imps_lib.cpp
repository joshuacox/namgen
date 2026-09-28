#include "fantasy-imps_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_imps_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "", "b", "ch", "cr", "cy", "d", "dr", "g", "gn", "gr", "j", "k", "kr", "ky", "l", "n", "p", "q", "qr", "r", "sh", "t", "tr", "ty", "v", "x", "y", "z", "zr"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ee", "ia", "iu", "ai", "aa"};
    static constexpr std::string_view nm3[] = {"bb", "bh", "bj", "bk", "bl", "bq", "br", "gb", "gf", "gh", "gl", "gm", "gn", "gr", "kb", "kh", "kj", "kk", "kl", "km", "kn", "kr", "lb", "lj", "ll", "ln", "lp", "lr", "lt", "ph", "pk", "pn", "pp", "pq", "pr", "rb", "rj", "rk", "rl", "rm", "rn", "rp", "rq", "rr", "rt", "zb", "zl", "zm", "zn", "zp", "zr", "zt", "cb", "cl", "cn", "cq", "cr", "ct", "cx", "cz", "dj", "dr", "dv", "dz", "fn", "fr", "nc", "nd", "ng", "nj", "nl", "nt", "qb", "ql", "qn", "qq", "qr", "sc", "sh", "sk", "sl", "sm", "sn", "sq", "sr", "ss", "st", "str", "sz", "tc", "th", "tj", "tn", "xh", "xn"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "b", "c", "k", "l", "m", "n", "p", "q", "r", "s", "t", "x", "z"};
    static constexpr std::string_view nm5[] = {"ch", "cr", "cy", "d", "dr", "gn", "gr", "kr", "ky", "qr", "r", "sz", "t", "tr", "ty", "v", "x", "y", "z", "zr"};
    static constexpr std::string_view nm6[] = {"c", "l", "m", "n", "p", "q", "r", "t", "x", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0; int tyr = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm2);
    if (i % 3 == 0) {
    rnd = rng() % std::size(nm5);
    rnd3 = rng() % std::size(nm6);
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3];
    } else {
    rnd = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (rnd < 7) {
    while (rnd5 < 5) {
    rnd5 = rng() % std::size(nm4);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd2] + nm2[rnd4] + nm4[rnd5];
    }
    tyr = rng() % 300;
    if (tyr == 10) {
    names = "Tyrion Lannister (just kidding)";
    }
    return names;
    }
}
