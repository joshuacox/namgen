#include "diablo-nephalems_lib.h"

#include <vector>

/* Implementation follows the logic of the original JavaScript generator
 * `fantasy-names/generators/diablo/nephalems.js`. */
std::string generate_diablo_nephalems_name(std::mt19937& rng, int type) {
    static const std::vector<std::string> nm1 = {"", "", "", "", "b", "c", "d", "g", "j", "k", "l", "m", "n", "ph", "r", "t", "v", "w", "z"};
    static const std::vector<std::string> nm2 = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ia", "oe", "io", "y"};
    static const std::vector<std::string> nm3 = {"c", "dr", "gr", "l", "ld", "lm", "ln", "m", "md", "mn", "n", "nd", "r", "rl", "rd", "s", "ss", "th", "thm", "z"};
    static const std::vector<std::string> nm4 = {"", "", "", "", "", "b", "c", "d", "k", "l", "ln", "lm", "n", "r", "s"};
    static const std::vector<std::string> nm5 = {"", "", "", "", "", "ch", "h", "j", "l", "m", "n", "ph", "r", "rh", "s", "sh", "w", "z"};
    static const std::vector<std::string> nm6 = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y"};
    static const std::vector<std::string> nm7 = {"dr", "l", "ll", "lm", "ln", "ld", "m", "mn", "n", "nm", "nn", "nr", "mr", "lgr", "n", "r", "rl", "rn", "rm", "rsh", "s", "sh", "ss", "th"};
    static const std::vector<std::string> nm8 = {"", "", "", "", "", "l", "n", "r", "s", "sh"};

    int i = static_cast<int>(rng() % 10);
    std::string name;

    if (type == 1) {
        size_t rnd  = rng() % nm5.size();
        size_t rnd2 = rng() % nm6.size();
        size_t rnd3 = rng() % nm7.size();
        // size_t rnd4 = rng() % nm6.size(); // Unused variable removed
        size_t rnd5 = rng() % nm8.size();

        if (i < 5) {
            name = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm8[rnd5];
        } else {
            size_t rnd6 = rng() % nm7.size();
            size_t rnd7 = rng() % nm6.size();
            name = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd7] + nm7[rnd6] + nm8[rnd5];
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
