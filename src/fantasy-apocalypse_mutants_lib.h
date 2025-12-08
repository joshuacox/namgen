#ifndef FANTASY_APOCALYPSE_MUTANTS_LIB_H
#define FANTASY_APOCALYPSE_MUTANTS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a fantasy “apocalypse_mutants” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/fantasy/apocalypse_mutants.js`.
 *
 * @param rng   Random number generator.
 * @param type Optional type selector:
 *             0 = male (default),
 *             1 = female,
 *             2 = neutral.
 * @return Generated name string.
 */
std::string generate_fantasy_apocalypse_mutants_name(std::mt19937& rng, int type = 0);

#endif // FANTASY_APOCALYPSE_MUTANTS_LIB_H
