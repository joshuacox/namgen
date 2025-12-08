#ifndef DIABLO_DEMONS_LIB_H
#define DIABLO_DEMONS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Diablo “demons” style name.
 *
 * Mirrors the JavaScript generator `fantasy-names/generators/diablo/demons.js`.
 *
 * @param rng   Random number generator.
 * @param type  Optional type selector (0 = default, 1 = short variant).
 * @return      Generated name string.
 */
std::string generate_diablo_demons_name(std::mt19937& rng, int type = 0);

#endif // DIABLO_DEMONS_LIB_H
