#ifndef DESTINY_VEXS_LIB_H
#define DESTINY_VEXS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a fantasy‑destiny “vexs” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/destiny/vexs.js`.
 *
 * @param rng Random number generator.
 * @return Generated name string.
 */
std::string generate_destiny_vexs_name(std::mt19937& rng);

#endif // DESTINY_VEXS_LIB_H
