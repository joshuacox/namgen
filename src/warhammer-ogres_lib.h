#ifndef WARHAMMER_OGRES_LIB_H
#define WARHAMMER_OGRES_LIB_H

#include <string>
#include <random>

/**
 * @brief Generate a Warhammer “ogres” style name.
 *
 * The algorithm mirrors the original JavaScript generator
 * (.javascript-fantasy-names-deprecated/generators/warhammer/ogres.js).
 *
 * @param rng Random number generator to use.
 * @return Generated name string.
 */
std::string generate_warhammer_ogres_name(std::mt19937& rng);

#endif // WARHAMMER_OGRES_LIB_H
