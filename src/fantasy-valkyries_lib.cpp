#include "fantasy-valkyries_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_valkyries_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"A", "Aga", "Ar", "Bry", "Ey", "Fri", "Fria", "Ge", "Gei", "Go", "Guo", "He", "Hi", "Hja", "Hjo", "Hla", "Hlo", "Hri", "Hru", "Ka", "Mi", "O", "Re", "Regi", "Ro", "Sa", "San", "Si", "Ska", "Ske", "Sko", "Sku", "Sva", "Sve", "Svei", "Svi", "Tho", "Thri", "Thru", "Va"};
    static constexpr std::string_view names2[] = {"dana", "dis", "dmadra", "dne", "dr", "dra", "drifa", "dul", "gabi", "gin", "ginleif", "gjold", "grdrifa", "grior", "grun", "gul", "hildr", "hylde", "ja", "la", "ld", "ldana", "ldr", "leif", "lmold", "lna", "lrun", "ma", "madra", "mold", "nd", "ndul", "ngrior", "nhildr", "nhylde", "nul", "pul", "ra", "rdmadra", "rifa", "rior", "rja", "ronul", "run", "rvif", "st", "ta", "tha", "va", "vif"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = names1[rnd] + names2[rnd2];
    return names;
    }
}
