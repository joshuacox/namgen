#ifndef DIABLO_KHAZRAS_LIB_H
#define DIABLO_KHAZRAS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Diablo “khazras” style name.
 *
 * Mirrors the JavaScript generator `fantasy-names/generators/diablo/khazras.js`.
 *
 * @param rng   Random number generator.
 * @param type  Optional type selector (currently unused, kept for API compatibility).
 * @return      Generated name string.
 */
std::string generate_diablo_khazras_name(std::mt19937& rng, int type = 0);

#endif // DIABLO_KHAZRAS_LIB_H
