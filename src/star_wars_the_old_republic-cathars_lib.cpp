#include "star_wars_the_old_republic-cathars_lib.h"

#include <algorithm>
#include <cstddef>
#include <vector>

/* Helper to pick a random element from a vector */
template <typename T>
static const T& randomChoice(const std::vector<T>& vec, std::mt19937& rng) {
    return vec[rng() % vec.size()];
}

/**
 * Generate a Star Wars: The Old Republic – Cathars name.
 *
 * The algorithm follows the original JavaScript implementation:
 *   - Randomly decide whether the surname is “long” or “short”.
 *   - Build the surname from a series of character groups.
 *   - Build the given name either from the “type‑1” set or the “type‑0” set.
 *
 * The JavaScript version accepts a `type` argument; the C++ wrapper always uses
 * the default (type 0) because the CLI flag does not expose this option.
 */
std::string generate_star_wars_the_old_republic_cathars_name(std::mt19937& rng) {
    /* ----- Surname tables ----- */
    const std::vector<std::string> nm10 = {"j","k","l","m","n","p","r","s","t"};
    const std::vector<std::string> nm14 = {"","", "", "h"};
    const std::vector<std::string> nm11 = {"i","o","a","u"};
    const std::vector<std::string> nm12 = {"d","l","m","n","s","sh","rg","z"};
    const std::vector<std::string> nm13 = {"","", "", "g","k","l","m","n","r","s","t"};

    const std::vector<std::string> nm1  = {"", "", "a", "u", "y", "i"};
    const std::vector<std::string> nm2  = {"c","cr","h","kh","m","n","r","s","t","x"};
    const std::vector<std::string> nm3  = {"a","i","o","y","u"};
    const std::vector<std::string> nm4  = {"c","d","k","m","n","nd","r","rb","s"};
    const std::vector<std::string> nm5  = {"","", "", "", "", "c","h","hr","k","m","n","rr","x"};

    const std::vector<std::string> nm6  = {"c","ch","d","j","m","n","r","s","th","x"};
    const std::vector<std::string> nm7  = {"h","l","lv","m","n","r","s","th","v","sh","w"};
    const std::vector<std::string> nm8  = {"r","h","s","n","hr","x","sh","z"};
    const std::vector<std::string> nm9  = {"", "", "", "a","i","y"};

    /* ----- Build surname ----- */
    std::string lName;
    int i = static_cast<int>(rng() % 10);   // 0‑9
    if (i < 5) {
        // long surname: 6 parts
        const std::string& part0 = randomChoice(nm10, rng);
        const std::string& part1 = randomChoice(nm14, rng);
        const std::string& part2 = randomChoice(nm11, rng);
        const std::string& part3 = randomChoice(nm12, rng);
        const std::string& part4 = randomChoice(nm11, rng);
        const std::string& part5 = randomChoice(nm13, rng);
        lName = part0 + part1 + part2 + part3 + part4 + part5;
    } else {
        // short surname: 4 parts
        const std::string& part0 = randomChoice(nm10, rng);
        const std::string& part1 = randomChoice(nm14, rng);
        const std::string& part2 = randomChoice(nm11, rng);
        const std::string& part3 = randomChoice(nm13, rng);
        lName = part0 + part1 + part2 + part3;
    }

    /* ----- Build given name (type 0) ----- */
    const std::string& g1 = randomChoice(nm1, rng);
    const std::string& g2 = randomChoice(nm2, rng);
    const std::string& g3 = randomChoice(nm3, rng);
    const std::string& g4 = randomChoice(nm5, rng);
    std::string firstName = g1 + g2 + g3 + g4;

    /* ----- Assemble full name ----- */
    return firstName + " " + lName;
}
