#include "rift-bahmis_lib.h"
#include <vector>

std::string generate_rift_bahmis_name(std::mt19937& rng) {
    // Name parts for the default (type != 1) case
    static const std::vector<std::string> names1 = {
        "Bat", "Batu", "Chin", "Chuluun", "Ene", "Enkh", "Gan", "Khün",
        "Khen", "Mönkh", "Medekh", "Munoo", "Naran", "Ner", "Ogt",
        "Otgon", "Sühk", "Tömör", "Ter", "Yul"
    };
    static const std::vector<std::string> names2 = {
        "baatar", "bat", "bataar", "bayar", "bish", "bold", "güi", "gis",
        "jargal", "khan", "khoi", "saikhan", "sukh", "tulga", "zorig"
    };

    std::uniform_int_distribution<std::size_t> dist1(0, names1.size() - 1);
    std::uniform_int_distribution<std::size_t> dist2(0, names2.size() - 1);

    const std::string& part1 = names1[dist1(rng)];
    const std::string& part2 = names2[dist2(rng)];

    return part1 + part2;
}
