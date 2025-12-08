#ifndef FANTASY_ANGELS_LIB_H
#define FANTASY_ANGELS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a fantasy “angels” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/fantasy/angels.js`.
 *
 * @param rng Random number generator.
 * @param type Optional type selector (the original JS accepts a `type`
 *              argument; passing 0 yields the default behaviour).
 * @return Generated name string.
 */
std::string generate_fantasy_angels_name(std::mt19937& rng, int type = 0);

#endif // FANTASY_ANGELS_LIB_H
