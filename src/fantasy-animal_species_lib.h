#ifndef FANTASY_ANIMAL_SPECIES_LIB_H
#define FANTASY_ANIMAL_SPECIES_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a fantasy “animal species” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/fantasy/animal_species.js`.
 *
 * @param rng Random number generator.
 * @return Generated name string.
 */
std::string generate_fantasy_animal_species_name(std::mt19937& rng);

#endif // FANTASY_ANIMAL_SPECIES_LIB_H
