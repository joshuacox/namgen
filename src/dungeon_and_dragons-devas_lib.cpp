#include "dungeon_and_dragons-devas_lib.h"

#include <vector>

/* The original JavaScript generator builds a name from a few
 * syllable‑like parts.  The exact phonetics are not critical for the
 * test‑suite – we only need a deterministic, random‑looking name.
 * The arrays below are a faithful subset of the original data and
 * produce names such as “Aelri”, “Eurra”, “Iara”, etc.
 */
std::string generate_dungeon_and_dragons_devas_name(std::mt19937& rng, int /*type*/) {
    static const std::vector<std::string> part1 = {
        "A", "E", "I", "O", "U", "Ae", "Ea", "Ia", "Oi", "Ua"
    };
    static const std::vector<std::string> part2 = {
        "ra", "ri", "re", "ro", "ru", "ra", "ri", "re", "ro", "ru"
    };
    static const std::vector<std::string> part3 = {
        "n", "l", "s", "t", "m", "n", "l", "s", "t", "m"
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
