#include "dragon_ball-skians_lib.h"

#include <vector>

/* The original JavaScript generator builds a name from a single array
   of possible Saiyan‑style names and returns a random entry. */
std::string generate_dragon_ball_skians_name(std::mt19937& rng) {
    static const std::vector<std::string> names = {
        "Bardock", "Goku", "Vegeta", "Gohan", "Trunks", "Goten", "Pan",
        "Broly", "Turles", "Bojack", "Kale", "Caulifla", "Cabba", "Raditz",
        "Nappa", "Yamcha", "Tien", "Chiaotzu", "Piccolo", "Krillin",
        "Android 17", "Android 18", "Cell", "Frieza", "Zamasu", "Hit",
        "Jiren", "Kale", "Kale", "Kale", "Kale"
    };

    if (names.empty()) {
        return "";
    }

    size_t idx = static_cast<size_t>(rng() % names.size());
    return names[idx];
}
