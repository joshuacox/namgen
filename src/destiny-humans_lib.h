#ifndef DESTINY_HUMANS_LIB_H
#define DESTINY_HUMANS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a fantasy‑destiny “humans” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/destiny/humans.js`.
 *
 * @param rng   Random number generator to use.
 * @param type Optional type selector (the original JS accepts a `type`
 *             argument; passing 0 yields the default behaviour).
 * @return      Generated name string.
 */
std::string generate_destiny_humans_name(std::mt19937& rng, int type = 0);

#endif // DESTINY_HUMANS_LIB_H
