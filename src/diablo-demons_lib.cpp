#include "diablo-demons_lib.h"
#include <vector>

std::string generate_diablo_demons_name(std::mt19937& rng, int type) {
    static const std::vector<std::string> nm1 = {"", "", "", "", "", "b", "bl", "br", "c", "cr", "ch", "d", "dr", "g", "gr", "gh", "h", "j", "k", "kh", "kr", "l", "m", "n", "p", "pr", "r", "s", "sl", "str", "sthr", "sth", "sr", "t", "th", "tr", "thr", "v", "vr", "wr", "x", "y", "z"};
    static const std::vector<std::string> nm2 = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "io", "oi", "aa", "iu", "ia", "ou", "ea", "uu", "au", "ao"};
    static const std::vector<std::string> nm3 = {"b", "bl", "br", "c", "d", "dd", "dr", "g", "gg", "gh", "gn", "gr", "h", "j", "k", "kh", "kr", "kk", "kn", "lf", "lth", "lt", "lm", "lr", "ld", "m", "mm", "n", "ng", "nth", "nd", "nr", "nt", "ph", "phr", "r", "rch", "rp", "rr", "rt", "rzh", "rs", "rz", "rd", "rk", "s", "sh", "ss", "sz", "str", "t", "th", "tr", "thr", "x", "xtr", "xx", "z", "zz"};
    static const std::vector<std::string> nm4 = {"", "", "", "", "c", "hr", "k", "l", "n", "r", "rm", "rr", "rth", "s", "ss", "th", "tt", "w", "x", "z"};
    static const std::vector<std::string> nm5 = {"", "", "", "", "", "b", "bh", "bl", "c", "ch", "d", "dh", "dr", "g", "gl", "gr", "gh", "fr", "h", "j", "k", "kh", "l", "ll", "m", "n", "p", "ph", "pr", "phr", "pl", "r", "s", "sh", "shr", "st", "sth", "sthr", "sl", "t", "th", "thr", "v", "w", "wr", "x", "y", "z"};
    static const std::vector<std::string> nm6 = {"a", "e", "i", "o", "u", "io", "oi", "aa", "iu", "ia", "ou", "ea", "uu", "au", "ao"};
    static const std::vector<std::string> nm7 = {"b", "bb", "br", "bh", "c", "ch", "d", "dh", "dd", "dr", "g", "gn", "gr", "h", "hr", "hl", "k", "kh", "kr", "l", "lf", "lph", "lth", "lm", "ln", "ld", "ll", "lr", "m", "mm", "ml", "mf", "n", "nn", "ng", "nth", "ns", "nt", "ndr", "ph", "phr", "r", "rr", "rph", "rl", "rs", "rn", "s", "sh", "ss", "sz", "sth", "str", "t", "th", "tr", "tt", "thr", "x", "xx", "xh", "z", "zz"};
    static const std::vector<std::string> nm8 = {"", "", "", "", "h", "l", "n", "s", "th", "z"};

    int i = static_cast<int>(rng() % 10);
    std::string name;

    if (type == 1) {
        size_t rnd  = rng() % nm5.size();
        size_t rnd2 = rng() % nm6.size();
        size_t rnd3 = rng() % nm7.size();
        size_t rnd4 = rng() % nm6.size();
        size_t rnd5 = rng() % nm8.size();

        if (i < 5) {
            name = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5];
        } else {
            size_t rnd6 = rng() % nm7.size();
            size_t rnd7 = rng() % nm6.size();
            name = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm8[rnd5];
        }
    } else {
        size_t rnd  = rng() % nm1.size();
        size_t rnd2 = rng() % nm2.size();
        size_t rnd3 = rng() % nm3.size();
        size_t rnd4 = rng() % nm2.size();
        size_t rnd5 = rng() % nm4.size();

        if (i < 5) {
            name = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
        } else {
            size_t rnd6 = rng() % nm3.size();
            size_t rnd7 = rng() % nm2.size();
            name = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5];
        }
    }

    return name;
}
