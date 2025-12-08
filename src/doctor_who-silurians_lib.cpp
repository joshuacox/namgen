#include "doctor_who-silurians_lib.h"

std::string generate_doctor_who_silurians_name(std::mt19937& rng, int type) {
    // Arrays taken directly from the original JavaScript generator.
    static const std::vector<std::string> nm1 = {"", "d", "h", "k", "l", "m", "r", "t"};
    static const std::vector<std::string> nm2 = {"o", "e", "a", "i"};
    static const std::vector<std::string> nm3 = {"d", "dr", "cth", "ct", "cl", "cr", "hr", "hk", "hl",
                                                 "kd", "kl", "kr", "l", "lr", "ln", "n", "lm", "ml",
                                                 "nl", "nr", "nl", "ld", "r", "rk", "rl"};
    static const std::vector<std::string> nm4 = {"h", "k", "l", "n", "m", "r"};
    static const std::vector<std::string> nm5 = {"e", "a", "", "", "", ""};
    static const std::vector<std::string> nm6 = {"d", "h", "k", "l", "m", "n", "r", "s", "v"};
    static const std::vector<std::string> nm7 = {"o", "e", "a"};
    static const std::vector<std::string> nm8 = {"d", "dr", "hr", "hl", "hn", "lr", "ln", "n", "lm",
                                                 "ln", "ml", "mn", "l", "r", "rl", "rk", "sk",
                                                 "sl", "sn", "sm", "st", "str", "y"};
    static const std::vector<std::string> nm9 = {"", "", "", "", "", "", "", "h", "c", "l", "n", "m", "s"};

    if (type == 1) {
        // Type‑1 algorithm (the “type === 1” branch in the JS file)
        std::string name;
        name += nm6[rng() % nm6.size()];
        name += nm7[rng() % nm7.size()];
        name += nm8[rng() % nm8.size()];
        name += nm7[rng() % nm7.size()];
        name += nm9[rng() % nm9.size()];
        return name;
    } else {
        // Default algorithm (the “else” branch in the JS file)
        std::string name;
        name += nm1[rng() % nm1.size()];
        name += nm2[rng() % nm2.size()];
        name += nm3[rng() % nm3.size()];
        name += nm2[rng() % nm2.size()];
        name += nm4[rng() % nm4.size()];
        name += nm5[rng() % nm5.size()];
        return name;
    }
}
