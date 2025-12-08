#ifndef DIABLO_NEPHALEMS_LIB_H
#define DIABLO_NEPHALEMS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Diablo “nephalems” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/diablo/nephalems.js`.
 *
 * @param rng   Random number generator to use.
 * @param type  Optional type selector (the original JS accepts a `type`
 *              argument; passing 0 yields the default behaviour).
 * @return      Generated name string.
 */
std::string generate_diablo_nephalems_name(std::mt19937& rng, int type = 0);

#endif // DIABLO_NEPHALEMS_LIB_H
