#include "harry_potter-goblins_lib.h"
#include <vector>

/* Implementation based on the original JavaScript generator.
   It concatenates a random prefix from `nm1` with a random suffix from `nm2`. */
std::string generate_harry_potter_goblins_name(std::mt19937& rng) {
    static const std::vector<std::string> nm1 = {
        "Ad", "Ag", "Al", "Ar", "Ban", "Bar", "Bog", "Brag", "Brod", "Brun",
        "Bug", "Ear", "Eg", "Er", "Far", "Fil", "Frad", "Fur", "Gar", "Gor",
        "Grag", "Gran", "Grin", "Gruk", "Gug", "Gur", "Kar", "Kog", "Krag",
        "Krug", "Kur", "Lag", "Lar", "Lug", "Lur", "Nad", "Nag", "Nur",
        "Rag", "Ran", "Rod", "Rog", "Ug", "Ul", "Ur"
    };

    static const std::vector<std::string> nm2 = {
        "git", "gok", "gor", "gott", "gras", "grat", "grot", "guff", "gus",
        "guss", "kar", "kit", "knas", "knus", "koff", "kor", "kras", "krat",
        "krus", "kus", "laff", "last", "lig", "lirg", "lok", "lor", "luff",
        "luk", "lus", "naff", "nar", "nast", "nok", "not", "nott", "nuff",
        "nuk", "nus", "raff", "ragg", "rak", "rast", "rat", "rig", "rod"
    };

    // Choose random elements
    const std::string& part1 = nm1[rng() % nm1.size()];
    const std::string& part2 = nm2[rng() % nm2.size()];

    return part1 + part2;
}
