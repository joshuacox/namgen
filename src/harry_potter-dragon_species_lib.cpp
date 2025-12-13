#include "harry_potter-dragon_species_lib.h"
#include <vector>
#include <algorithm>

std::string generate_harry_potter_dragon_species_name(std::mt19937& rng) {
    const std::vector<std::string> nm1 = {
        "Algerian", "American", "Angolan", "Antarctic", "Argentinian",
        "Armenian", "Australian", "Austrian", "Bolivian", "Brazilian",
        "British", "Bulgarian", "Cambodian", "Canadian", "Chilean",
        "Chinese", "Croatian", "Cuban", "Danish", "Egyptian",
        "Finnish", "French", "German", "Hungarian", "Indian",
        "Irish", "Italian", "Jamaican", "Japanese", "Mexican",
        "Mongolian", "Moroccan", "Nepalese", "Norwegian", "Peruvian",
        "Romanian", "Russian", "Slovenian", "South-African", "Spanish",
        "Swedish", "Thai", "Turkish", "Ukrainian", "Vietnamese"
    };

    const std::vector<std::string> nm2 = {
        "Barb", "Blaze", "Bristle", "Dart", "Demon", "Ember",
        "Fire", "Flame", "Foul", "Fury", "Giant", "Glow",
        "Horn", "Iron", "Jade", "Long", "Mammoth", "Monster",
        "Opal", "Plate", "Rage", "Ridge", "Ruby", "Short",
        "Smooth", "Snake", "Soft", "Spark", "Spike", "Steel",
        "Storm", "Swift", "Thin", "Thorn", "Thunder", "Venom",
        "Vile", "Viper", "Warp", "Wide"
    };

    const std::vector<std::string> nm3 = {
        "back", "belly", "bottom", "claw", "crown", "dart",
        "eye", "fang", "frame", "gut", "head", "horn",
        "muzzle", "paw", "rump", "scale", "skull",
        "snout", "spike", "stub", "tail", "tooth",
        "trunk", "tusk", "wing"
    };

    std::uniform_int_distribution<> dist1(0, nm1.size() - 1);
    std::uniform_int_distribution<> dist2(0, nm2.size() - 1);
    std::uniform_int_distribution<> dist3(0, nm3.size() - 1);

    size_t rnd = dist1(rng);

    return nm1[rnd] + " " + nm2[dist2(rng)] + nm3[dist3(rng)];
}
