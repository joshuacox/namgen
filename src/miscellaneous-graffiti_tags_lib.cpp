#include "miscellaneous-graffiti_tags_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_graffiti_tags_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "bd", "bg", "bh", "bk", "bl", "br", "by", "bz", "c", "cd", "cf", "ch", "chr", "cj", "cl", "cm", "cn", "cr", "cry", "cy", "cz", "d", "df", "dg", "dh", "dk", "dl", "dm", "dr", "dy", "dz", "f", "fh", "fl", "fr", "fy", "fx", "g", "gd", "gh", "gl", "gn", "gr", "gy", "gry", "h", "hy", "j", "jy", "k", "kh", "kl", "kn", "kr", "ky", "kry", "kz", "l", "lh", "ly", "lx", "m", "mn", "mj", "mr", "my", "mx", "mk", "n", "nh", "ny", "nj", "nx", "nm", "p", "ph", "ph", "pj", "pl", "pm", "pn", "pr", "ps", "pz", "py", "pry", "phy", "q", "ql", "qr", "qz", "qv", "r", "rc", "rh", "rq", "rk", "rm", "rt", "rx", "ry", "s", "sc", "sh", "sk", "sl", "sm", "sn", "sq", "sr", "st", "str", "sy", "sty", "stry", "sly", "sz", "sx", "t", "td", "th", "tl", "tp", "tr", "ts", "tv", "ty", "tz", "try", "thy", "th", "v", "vn", "vm", "vl", "vx", "vq", "vs", "vz", "vh", "vy", "w", "wh", "wk", "wq", "wy", "x", "xc", "xh", "xz", "xy", "xr", "xt", "xs", "y", "z", "zh", "zn", "zs", "zv", "zw", "zy", "zx"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ea", "eo", "eu", "ei", "ee", "ia", "io", "iu", "ie", "ae", "ao", "ai", "aa", "ua", "ui", "ue", "oi", "oo", "ou", "oe"};
    static constexpr std::string_view nm3[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "bb", "bh", "bl", "br", "bz", "c", "cc", "ch", "cl", "cm", "cn", "cr", "cs", "ct", "cx", "cz", "d", "dd", "db", "dh", "dk", "dm", "dn", "dr", "f", "ff", "fk", "fl", "fr", "g", "gg", "gb", "gl", "gm", "gn", "gr", "gt", "gz", "h", "hh", "hr", "hn", "hm", "hl", "j", "k", "kk", "kb", "kl", "km", "kn", "kr", "ks", "kt", "kx", "kz", "l", "ll", "lc", "lg", "lm", "ln", "lp", "lq", "lr", "ls", "lt", "lz", "m", "mm", "mh", "mn", "mr", "ms", "mt", "mz", "n", "nn", "nh", "ng", "nd", "nk", "nl", "nm", "nq", "nr", "ns", "nt", "nz", "nx", "p", "ph", "pl", "pp", "pq", "pr", "pz", "q", "qq", "qr", "qx", "r", "rc", "rd", "rg", "rh", "rk", "rl", "rm", "rn", "rp", "rq", "rr", "rs", "rt", "rx", "rz", "s", "sc", "ss", "sh", "sk", "sm", "sn", "sq", "sr", "st", "sz", "sx", "t", "th", "tm", "tn", "tq", "v", "w", "x", "xx", "xz", "xs", "xt", "xr", "z", "zc", "zz", "zs", "zl", "zm", "zn", "zq"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ea", "eo", "eu", "ei", "ee", "ia", "io", "iu", "ie", "ae", "ao", "ai", "aa", "ua", "ui", "ue", "oi", "oo", "ou", "oe"};
    static constexpr std::string_view nm5[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "bl", "c", "ch", "ct", "d", "dd", "dr", "dz", "f", "ff", "fs", "g", "gg", "gh", "ght", "gs", "gz", "hn", "j", "k", "kk", "kr", "ks", "kt", "kz", "lb", "ld", "ll", "lr", "ls", "lt", "lz", "m", "ml", "mm", "mms", "mn", "mr", "ms", "mz", "n", "nd", "ndr", "ng", "nk", "nr", "ns", "nt", "nz", "nzy", "p", "pd", "ph", "pr", "ps", "q", "qq", "r", "rb", "rd", "rf", "rk", "rm", "rn", "rs", "rsh", "rt", "rts", "rtz", "rz", "s", "sh", "sk", "sp", "sr", "ss", "st", "str", "t", "tch", "th", "tr", "ts", "tt", "tz", "v", "vs", "vz", "w", "x", "xc", "xs", "xx", "xz", "y", "z", "zl", "zn", "zr", "zz"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm5[rnd3];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4];
    }
    return names;
    }
}
