#ifndef DESTINY_CABALS_LIB_H
#define DESTINY_CABALS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a fantasy‑destiny “cabals” style name.
 *
 * Mirrors the JavaScript generator in
 * `fantasy-names/generators/destiny/cabals.js`.
 *
 * @param rng Random number generator.
 * @return Generated name string.
 */
std::string generate_destiny_cabals_name(std::mt19937& rng);

#endif // DESTINY_CABALS_LIB_H
