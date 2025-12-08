#include "dragon_ball-others_lib.h"

#include <vector>

std::string generate_dragon_ball_others_name(std::mt19937& rng) {
    static const std::vector<std::string> names1 = {
        "Lala","Abra","Ala","Alaka","Bim","Braca","Bracada","Cada","Cadabra","Dabra",
        "Eppe","Flam","Flim","Gobble","Gobbledee","Gook","Hello","Hillo","Hocu",
        "Hocus","Hollo","Hum","Jumbo","Kakke","Kazam","Laka","Mani","Mumbo",
        "Ocus","Om","Padme","Peppe","Pocu","Pocus","Pow","Presto","Sala","Same",
        "Sesa","Sesame","Shazam","Sim","Wow","Zam","Zik","Zizzi","Zuzzy"
    };
    static const std::vector<std::string> names2 = {
        "Aioli","Anise","Basil","Bay","Celery","Chili","Chutney","Cilantro","Cinnamon",
        "Clove","Coriander","Cream","Cumin","Dashi","Dressing","Fennel","Guacamole",
        "Jasmine","Juniper","Ketchup","Lemon","Lime","Mace","Marmite","Mash","Mayo",
        "Mint","Miso","Naise","Nutmeg","Oil","Onion","Oregano","Paprika","Parsley",
        "Pepper","Peppermint","Pesto","Piccalilli","Pickle","Ponzu","Radish","Relish",
        "Rice","Riyaki","Rosemary","Safe","Saffron","Salsa","Sambal","Sauce","Sesame",
        "Shichimi","Sichuan","Soy","Syrup","Tarragon","Tartar","Teriya","Teriyaki",
        "Thyme","Turmeric","Tzatziki","Vanilla","Wasabi"
    };

    // Random i in [0,9]
    int i = static_cast<int>(rng() % 10);
    if (i < 5) {
        size_t idx = rng() % names1.size();
        return names1[idx];
    } else {
        size_t idx = rng() % names2.size();
        return names2[idx];
    }
}
