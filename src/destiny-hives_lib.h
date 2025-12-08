#ifndef DESTINY_HIVES_LIB_H
#define DESTINY_HIVES_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a fantasy‑destiny “hives” style name.
 *
 * Mirrors the JavaScript generator in
 * `fantasy-names/generators/destiny/hives.js`.
 *
 * @param rng  Random number generator.
 * @param type Optional type selector (0 = default, 1 = alternate style).
 * @return     Generated name string.
 */
std::string generate_destiny_hives_name(std::mt19937& rng, int type = 0);

#endif // DESTINY_HIVES_LIB_H
