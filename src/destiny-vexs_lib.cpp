#include "destiny-vexs_lib.h"

#include <vector>
#include <string>

/* Implementation mirrors the original JavaScript generator:
 *
 * function generator$destiny$vexs() {
 *   var nm1 = ["", "", "", "", "c", "g", "h", "k", "n", "s", "t", "th", "z"];
 *   var nm2 = ["a", "e", "a", "e", "a", "e", "i", "o", "a", "e", "i", "o",
 *              "eo", "io", "y", "y", "ia", "ea"];
 *   var nm3 = ["d", "dh", "dr", "g", "gg", "gh", "gr", "k", "kh", "kk",
 *              "kr", "lg", "lk", "nk", "nr", "rg", "rk", "sk", "th", "tr"];
 *   var nm4 = ["m", "n", "s", "t", "x"];
 *
 *   i = Math.floor(Math.random() * 10);
 *   rnd = Math.floor(Math.random() * nm1.length);
 *   rnd2 = Math.floor(Math.random() * nm2.length);
 *   rnd3 = Math.floor(Math.random() * nm3.length);
 *   rnd4 = Math.floor(Math.random() * nm2.length);
 *   rnd5 = Math.floor(Math.random() * nm4.length);
 *   names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
 *   return names;
 * }
 *
 * The C++ version follows the same logic, using the supplied RNG.
 */
std::string generate_destiny_vexs_name(std::mt19937& rng) {
    static const std::vector<std::string> nm1 = {
        "", "", "", "", "c", "g", "h", "k", "n", "s", "t", "th", "z"
    };
    static const std::vector<std::string> nm2 = {
        "a", "e", "a", "e", "a", "e", "i", "o", "a", "e", "i", "o",
        "eo", "io", "y", "y", "ia", "ea"
    };
    static const std::vector<std::string> nm3 = {
        "d", "dh", "dr", "g", "gg", "gh", "gr", "k", "kh", "kk",
        "kr", "lg", "lk", "nk", "nr", "rg", "rk", "sk", "th", "tr"
    };
    static const std::vector<std::string> nm4 = {
        "m", "n", "s", "t", "x"
    };

    // Consume a random number to keep parity with other generators (the original JS
    // generates a random i in [0,9] but never uses it).
    (void)rng;

    const std::string& part1 = nm1[rng() % nm1.size()];
    const std::string& part2 = nm2[rng() % nm2.size()];
    const std::string& part3 = nm3[rng() % nm3.size()];
    const std::string& part4 = nm2[rng() % nm2.size()];
    const std::string& part5 = nm4[rng() % nm4.size()];

    return part1 + part2 + part3 + part4 + part5;
}
