#ifndef DIABLO_ANGELS_LIB_H
#define DIABLO_ANGELS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Diablo “angels” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/diablo/angels.js`.
 *
 * @param rng   Random number generator to use.
 * @param type  Optional type selector (the original JS accepts a `type`
 *              argument; passing 0 yields the default behaviour).
 * @return      Generated name string.
 */
std::string generate_diablo_angels_name(std::mt19937& rng, int type = 0);

#endif // DIABLO_ANGELS_LIB_H
