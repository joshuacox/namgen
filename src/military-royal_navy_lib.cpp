#include "military-royal_navy_lib.h"
#include <vector>
#include <string>

std::string generate_military_royal_navy_name(std::mt19937& rng) {
    static const std::vector<std::string> names = {
        "Apples", "Butter", "Charlie", "Duff", "Edward", "Freddy", "George",
        "Harry", "Ink", "Johnnie", "King", "London", "Monkey", "Nuts",
        "Orange", "Pudding", "Queenie", "Robert", "Sugar", "Tommy", "Uncle",
        "Vinegar", "Willie", "Xerxes", "Yellow", "Zebra"
    };

    // Choose first index
    std::size_t r1 = rng() % names.size();

    // Choose second index, ensuring it differs from r1
    std::size_t r2 = rng() % (names.size() - 1);
    if (r2 >= r1) {
        ++r2; // shift to avoid collision
    }

    return names[r1] + " " + names[r2];
}
