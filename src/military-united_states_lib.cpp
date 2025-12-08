#include "military-united_states_lib.h"
#include <vector>
#include <string>

std::string generate_military_united_states_name(std::mt19937& rng) {
    static const std::vector<std::string> names = {
        "Able", "Baker", "Charlie", "Dog", "Easy", "Fox", "George", "How",
        "Item", "Jig", "King", "Love", "Mike", "Nan", "Oboe", "Peter",
        "Queen", "Roger", "Sugar", "Tare", "Uncle", "Victor", "William",
        "Xray", "Yoke", "Zebra"
    };

    // Choose first index
    std::size_t r1 = rng() % names.size();

    // Choose second index from the remaining elements
    std::size_t r2 = rng() % (names.size() - 1);
    if (r2 >= r1) {
        ++r2; // skip over r1 to ensure distinctness
    }

    return names[r1] + " " + names[r2];
}
