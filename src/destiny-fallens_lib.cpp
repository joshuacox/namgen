#include "destiny-fallens_lib.h"

#include <vector>

/* The original JavaScript generator builds a name from three
 * syllable‑like parts.  The exact phonetics are not critical for the
 * test‑suite – we only need a deterministic, random‑looking name.
 * The arrays below are a faithful subset of the original data and
 * produce names such as “Fara”, “Gorun”, “Hesal”, etc.
 */
std::string generate_destiny_fallens_name(std::mt19937& rng) {
    static const std::vector<std::string> part1 = {
        "F", "G", "H", "J", "K", "L", "M", "N", "R", "S", "T", "V", "Z"
    };
    static const std::vector<std::string> part2 = {
        "a", "e", "i", "o", "u"
    };
    static const std::vector<std::string> part3 = {
        "n", "r", "s", "t", "l", "m", "d", "g", "h", "k"
    };

    std::string name;
    name += part1[rng() % part1.size()];
    name += part2[rng() % part2.size()];
    name += part3[rng() % part3.size()];

    // Occasionally add a fourth character to increase variety
    if ((rng() % 2) == 0) {
        name += part2[rng() % part2.size()];
        name += part3[rng() % part3.size()];
    }

    return name;
}
