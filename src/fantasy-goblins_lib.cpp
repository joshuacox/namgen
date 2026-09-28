#include "fantasy-goblins_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_goblins_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "", "b", "c", "d", "f", "g", "h", "j", "k", "l", "p", "r", "t", "v", "w", "x", "z", "br", "bl", "cr", "cl", "ch", "dr", "fr", "gr", "gl", "gn", "kr", "kl", "pr", "pl", "str", "st", "sr", "sl", "tr", "vr", "wr", "zr"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "ia", "io", "ee", "aa", "ui", "ie", "ea", "oi"};
    static constexpr std::string_view nm3[] = {"b", "d", "g", "h", "k", "l", "m", "n", "r", "s", "t", "v", "z", "b", "d", "g", "h", "k", "l", "m", "n", "r", "s", "t", "v", "z", "b", "d", "g", "h", "k", "l", "m", "n", "r", "s", "t", "v", "z", "b", "d", "g", "h", "k", "l", "m", "n", "r", "s", "t", "v", "z", "bb", "bd", "bh", "bl", "bk", "bn", "br", "bs", "bt", "bz", "db", "dd", "df", "dh", "dl", "dn", "dr", "ds", "dv", "dz", "", "gg", "gb", "gd", "gh", "gk", "gl", "gm", "gn", "gr", "gs", "gt", "gz", "hd", "hb", "hk", "hn", "hz", "kl", "kn", "kz", "kv", "kk", "lb", "ld", "lg", "lk", "ll", "lr", "ls", "lt", "lv", "lz", "mr", "mv", "mz", "mt", "nr", "nv", "nz", "nt", "rb", "rd", "rg", "rk", "rl", "rm", "rn", "rr", "rs", "rt", "rv", "rz", "sb", "sd", "sh", "sk", "sm", "sn", "sr", "str", "st", "sv", "sz", "ss", "tb", "tl", "tm", "tn", "tr", "tv", "tz", "tt", "vl", "vn", "vr", "vz", "zb", "zd", "zg", "zl", "zm", "zn", "zt"};
    static constexpr std::string_view nm4[] = {"c", "g", "k", "l", "q", "r", "t", "x", "z", "nk", "ld", "rd", "s", "sz", "zz", "ng", "kz", "lb", "rm", "sb", "bs", "ts", "cs", "ct", "gs", "gz", "kt", "kx", "lk", "lx", "rk", "rt", "rd", "rx"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "bh", "br", "bl", "cr", "cl", "ch", "fr", "fl", "gr", "gl", "gn", "kh", "kl", "ph", "pr", "sh", "st", "sr", "sl", "sw", "th", "thr", "tr", "vr", "wr"};
    static constexpr std::string_view nm6[] = {"b", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "b", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "b", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "b", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "bb", "bd", "bh", "bl", "bk", "bn", "br", "bs", "bt", "bz", "fb", "fl", "fm", "fn", "fs", "ft", "gg", "gb", "gd", "gh", "gk", "gl", "gm", "gn", "gr", "gs", "gt", "gz", "hd", "hb", "hk", "hn", "hz", "kl", "kn", "kz", "kv", "kk", "lb", "ld", "lg", "lk", "ll", "lr", "ls", "lt", "lv", "lz", "mr", "mv", "mz", "mt", "nr", "nv", "nz", "nt", "ph", "pf", "pl", "pn", "pm", "pr", "ps", "pt", "pv", "rb", "rd", "rg", "rk", "rl", "rm", "rn", "rr", "rs", "rt", "rv", "rz", "sb", "sd", "sh", "sk", "sm", "sn", "sr", "str", "st", "sv", "sz", "ss", "tb", "tl", "tm", "tn", "tr", "tv", "tz", "tt", "vl", "vn", "vr", "vz"};
    static constexpr std::string_view nm7[] = {"h", "f", "g", "l", "n", "q", "s", "x", "z", "ls", "nk", "zz", "ld", "sh", "sz", "ss", "gs", "sx", "lx", "hx", "th", "rx", "rt", "ft", "fs", "fz", "lm", "lk", "lt", "ng", "nx", "ns", "nq"};
    static constexpr std::string_view nm8[] = {"e", "i", "ee", "ia", "ea", "a", "ai", "", "", "", "", "", "", "", "", "", "", "", "", ""};

    std::string names; size_t rnd2 = 0; size_t rnd2b = 0; size_t rnd3 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm2);
    rnd2b = rng() % std::size(nm2);
    if (type == 1) {
    rnd5 = rng() % std::size(nm5);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    if (i < 5) {
    names = nm5[rnd5] + nm2[rnd2] + nm7[rnd7] + nm8[rnd8];
    } else {
    rnd6 = rng() % std::size(nm6);
    names = nm5[rnd5] + nm2[rnd2] + nm6[rnd6] + nm2[rnd2b] + nm7[rnd7] + nm8[rnd8];
    }
    } else {
    rnd5 = rng() % std::size(nm1);
    rnd7 = rng() % std::size(nm4);
    if (i < 5) {
    names = nm1[rnd5] + nm2[rnd2] + nm4[rnd7];
    } else {
    rnd3 = rng() % std::size(nm3);
    names = nm1[rnd5] + nm2[rnd2] + nm3[rnd3] + nm2[rnd2b] + nm4[rnd7];
    }
    }
    return names;
    }
}
