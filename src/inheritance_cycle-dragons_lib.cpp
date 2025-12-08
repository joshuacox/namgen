#include "inheritance_cycle-dragons_lib.h"

#include <array>
#include <string>
#include <vector>

static std::string random_element(const std::vector<std::string>& vec, std::mt19937& rng) {
    std::uniform_int_distribution<std::size_t> dist(0, vec.size() - 1);
    return vec[dist(rng)];
}

std::string generate_inheritance_cycle_dragons_name(std::mt19937& rng, int type) {
    // Name parts taken directly from the original JavaScript implementation
    const std::vector<std::string> nm1 = {"", "", "", "", "b", "c", "d", "f", "g", "gl", "gr", "k", "l", "n", "r", "s", "sr", "shr", "t", "th", "v"};
    const std::vector<std::string> nm2 = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ae", "io", "ui", "ua", "au"};
    const std::vector<std::string> nm3 = {"b", "d", "g", "k", "ln", "l", "lg", "lm", "m", "md", "n", "nd", "r", "rm", "rn"};
    const std::vector<std::string> nm4 = {"c", "d", "dr", "gr", "k", "kr", "lfr", "ldr", "m", "n", "ngr", "r", "rn", "th"};

    const std::vector<std::string> nm5 = {"", "", "", "", "c", "d", "f", "gl", "h", "j", "l", "m", "n", "ph", "r", "sh", "s", "th", "v"};
    const std::vector<std::string> nm6 = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ae", "io", "ei", "ea", "au"};
    const std::vector<std::string> nm7 = {"d", "g", "l", "lm", "ln", "m", "mn", "n", "nv", "ph", "r", "rn", "rv", "th", "v"};
    const std::vector<std::string> nm8 = {"", "", "", "", "", "", "", "", "", "", "", "h", "l", "n", "s", "sh", "th"};

    // i = Math.floor(Math.random() * 10);
    std::uniform_int_distribution<int> dist_i(0, 9);
    int i = dist_i(rng);

    if (type == 1) {
        // Use the nm5‑nm8 tables
        std::string rnd  = random_element(nm5, rng);
        std::string rnd2 = random_element(nm6, rng);
        std::string rnd3 = random_element(nm7, rng);
        std::string rnd4 = random_element(nm6, rng);
        std::string rnd5 = random_element(nm8, rng);

        if (i < 6) {
            return rnd + rnd2 + rnd3 + rnd4 + rnd5;
        } else {
            std::string rnd6 = random_element(nm6, rng);
            std::string rnd7 = random_element(nm7, rng);
            return rnd + rnd2 + rnd3 + rnd6 + rnd7 + rnd4 + rnd5;
        }
    } else {
        // Use the nm1‑nm4 tables
        std::string rnd  = random_element(nm1, rng);
        std::string rnd2 = random_element(nm2, rng);
        std::string rnd4 = random_element(nm4, rng);

        if (i < 3) {
            return rnd + rnd2 + rnd4;
        } else if (i < 7) {
            std::string rnd3 = random_element(nm3, rng);
            std::string rnd5 = random_element(nm2, rng);
            return rnd + rnd2 + rnd3 + rnd5 + rnd4;
        } else {
            std::string rnd3 = random_element(nm3, rng);
            std::string rnd5 = random_element(nm2, rng);
            std::string rnd6 = random_element(nm3, rng);
            std::string rnd7 = random_element(nm2, rng);
            return rnd + rnd2 + rnd3 + rnd5 + rnd6 + rnd7 + rnd4;
        }
    }
}
