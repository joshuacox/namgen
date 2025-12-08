#ifndef FANTASY_AMAZONS_LIB_H
#define FANTASY_AMAZONS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a fantasy “amazons” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/fantasy/amazons.js`.
 *
 * @param rng Random number generator.
 * @return Generated name string.
 */
std::string generate_fantasy_amazons_name(std::mt19937& rng);

#endif // FANTASY_AMAZONS_LIB_H
