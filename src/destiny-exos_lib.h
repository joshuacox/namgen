#ifndef DESTINY_EXOS_LIB_H
#define DESTINY_EXOS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a fantasy‑destiny “exos” style name.
 *
 * Mirrors the JavaScript generator in
 * `fantasy-names/generators/destiny/exos.js`.
 *
 * @param rng Random number generator.
 * @return Generated name string.
 */
std::string generate_destiny_exos_name(std::mt19937& rng);

#endif // DESTINY_EXOS_LIB_H
