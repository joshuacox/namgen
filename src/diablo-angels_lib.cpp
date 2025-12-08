#include "diablo-angels_lib.h"

#include <vector>

/* The implementation follows the logic of the original JavaScript
 * generator `fantasy-names/generators/diablo/angels.js`.  The arrays are
 * reproduced verbatim (with minor C++‑friendly adjustments). */
std::string generate_diablo_angels_name(std::mt19937& rng, int type) {
    static const std::vector<std::string> nm1 = {"", "", "", "", "b", "c", "dr", "g", "h", "l", "m", "n", "p", "r", "s", "t", "th", "v", "y", "z"};
    static const std::vector<std::string> nm2 = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ae", "ai"};
    static const std::vector<std::string> nm3 = {"br", "d", "dr", "f", "g", "l", "lt", "ll", "lg", "lth", "lz", "m", "mp", "mph", "mphr", "mr", "n", "nd", "nn", "nny", "nr", "nl", "ph", "r", "s", "sr", "st", "th", "z", "zr"};
    static const std::vector<std::string> nm4 = {"al", "ael", "eon", "iel", "ial", "il", "el", "ius", "ion", "on", "os", "ual", "us"};
    static const std::vector<std::string> nm5 = {"c", "dr", "f", "g", "h", "k", "l", "m", "n", "p", "ph", "s", "th", "v"};
    static const std::vector<std::string> nm6 = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ae", "ai", "au"};
    static const std::vector<std::string> nm7 = {"br", "c", "dr", "dy", "f", "g", "gh", "gl", "hn", "hr", "l", "ll", "lth", "ls", "lz", "ln", "lm", "lf", "m", "mr", "ml", "mn", "mph", "nl", "ny", "nph", "nd", "r", "rd", "s", "sh", "sr", "th", "z"};
    static const std::vector<std::string> nm8 = {"el", "ael", "il", "on", "uen", "uel", "eil", "iel", "is", "ith", "oelle", "oenne", "aelle"};

    // Random index i in [0,9]
    int i = static_cast<int>(rng() % 10);
    std::string name;

    if (type == 1) {
        // Use the “short” variant (nm5‑nm8)
        size_t rnd  = rng() % nm5.size();
        size_t rnd2 = rng() % nm6.size();
        size_t rnd3 = rng() % nm7.size();
        size_t rnd4 = rng() % nm8.size();

        if (i < 5) {
            name = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm8[rnd4];
        } else {
            size_t rnd5 = rng() % nm7.size();
            size_t rnd6 = rng() % nm6.size();
            name = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd6] + nm7[rnd5] + nm8[rnd4];
        }
    } else {
        // Use the “full” variant (nm1‑nm4)
        size_t rnd  = rng() % nm1.size();
        size_t rnd2 = rng() % nm2.size();
        size_t rnd3 = rng() % nm3.size();
        size_t rnd4 = rng() % nm4.size();

        if (i < 5) {
            name = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4];
        } else {
            size_t rnd5 = rng() % nm3.size();
            size_t rnd6 = rng() % nm2.size();
            name = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd6] + nm3[rnd5] + nm4[rnd4];
        }
    }

    return name;
}
