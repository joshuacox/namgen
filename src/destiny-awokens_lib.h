#ifndef DESTINY_AWOKENS_LIB_H
#define DESTINY_AWOKENS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a fantasy‑destiny “awoken” style name.
 *
 * The implementation mirrors the JavaScript generator found in
 * `fantasy-names/generators/destiny/awokens.js`.
 *
 * @param rng   Random number generator to use.
 * @param type  Optional type selector (the original JS accepts a `type`
 *              argument; passing 0 yields the default behaviour).
 * @return      Generated name string.
 */
std::string generate_destiny_awoken_name(std::mt19937& rng, int type = 0);

#endif // DESTINY_AWOKENS_LIB_H
