#ifndef FANTASY_ALIENS_LIB_H
#define FANTASY_ALIENS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a fantasy “aliens” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/fantasy/aliens.js`.
 *
 * @param rng Random number generator.
 * @return Generated name string.
 */
std::string generate_fantasy_aliens_name(std::mt19937& rng);

#endif // FANTASY_ALIENS_LIB_H
