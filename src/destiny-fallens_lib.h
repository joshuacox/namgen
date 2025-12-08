#ifndef DESTINY_FALLENS_LIB_H
#define DESTINY_FALLENS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a fantasy‑destiny “fallens” style name.
 *
 * This implementation mirrors the behaviour of the original JavaScript
 * generator found in `fantasy-names/generators/destiny/fallens.js`.
 *
 * @param rng Random number generator to use.
 * @return   Generated name string.
 */
std::string generate_destiny_fallens_name(std::mt19937& rng);

#endif // DESTINY_FALLENS_LIB_H
