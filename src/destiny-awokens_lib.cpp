#include "destiny-awokens_lib.h"

#include <vector>

std::string generate_destiny_awoken_name(std::mt19937& rng, int type) {
    // Arrays copied from the original JavaScript implementation
    static const std::vector<std::string> nm1  = {"", "", "", "", "c", "g", "j", "k", "q", "r", "v", "x", "z"};
    static const std::vector<std::string> nm2  = {"a", "a", "u", "u", "e", "i", "a", "a", "u", "u", "e", "i", "a", "a", "u", "u", "e", "i", "oo", "ou", "uu", "aa"};
    static const std::vector<std::string> nm3  = {"d", "dr", "g", "gd", "gr", "h", "j", "ldr", "lgr", "ndr", "ngr", "q", "r", "rg", "rj", "sg", "v", "vg", "x", "z", "zg"};
    static const std::vector<std::string> nm4  = {"c", "ch", "g", "l", "n", "x", "z"};
    static const std::vector<std::string> nm5  = {"f", "l", "m", "n", "p", "ph", "s", "t", "th", "v", "z"};
    static const std::vector<std::string> nm6  = {"e", "e", "a", "a", "i", "o", "e", "e", "a", "a", "i", "o", "e", "e", "a", "a", "i", "o", "ia", "ua", "ea", "aa"};
    static const std::vector<std::string> nm7  = {"l", "lm", "ln", "lr", "m", "mm", "mn", "n", "nn", "r", "rh", "rl", "rm", "rn", "rr", "rt", "sr", "ss", "tr", "x", "y", "z"};
    static const std::vector<std::string> nm8  = {"f", "n", "nn", "ph", "s", "ss", "sh", "x"};
    static const std::vector<std::string> nm9  = {"c", "g", "j", "m", "q", "s", "th", "v", "x", "z"};
    static const std::vector<std::string> nm10 = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "aa"};
    static const std::vector<std::string> nm11 = {"d", "f", "h", "j", "k", "l", "m", "n", "q", "r", "sh", "v", "z"};
    static const std::vector<std::string> nm12 = {"hl", "hn", "j", "l", "m", "n", "nj", "s", "sh", "v"};

    // Random selections – mimic the JS logic
    int i = static_cast<int>(rng() % 10);

    size_t rndA = rng() % nm9.size();
    size_t rndB = rng() % nm10.size();
    size_t rndE = rng() % nm12.size();

    std::string nmLast;
    if (i % 2 == 0) {
        nmLast = nm9[rndA] + nm10[rndB] + nm12[rndE];
    } else {
        size_t rndC = rng() % nm11.size();
        size_t rndD = rng() % nm10.size();
        nmLast = nm9[rndA] + nm10[rndB] + nm11[rndC] + nm10[rndD] + nm12[rndE];
    }

    std::string name;
    if (type == 1) {
        size_t rnd  = rng() % nm5.size();
        size_t rnd2 = rng() % nm6.size();
        if (i < 5) {
            size_t rnd3 = rng() % nm8.size();
            name = nm5[rnd] + nm6[rnd2] + nm8[rnd3] + " " + nmLast;
        } else {
            size_t rnd3 = rng() % nm7.size();
            size_t rnd4 = rng() % nm6.size();
            name = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + " " + nmLast;
        }
    } else {
        size_t rnd  = rng() % nm1.size();
        size_t rnd2 = rng() % nm2.size();
        size_t rnd3 = rng() % nm3.size();
        size_t rnd4 = rng() % nm2.size();
        size_t rnd5 = rng() % nm4.size();
        name = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + nmLast;
    }

    return name;
}
