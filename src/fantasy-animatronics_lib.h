#ifndef FANTASY_ANIMATRONICS_LIB_H
#define FANTASY_ANIMATRONICS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a fantasy “animatronics” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/fantasy/animatronics.js`.
 *
 * @param rng  Random number generator.
 * @param type Optional type selector (the original JS accepts a `type`
 *             argument; passing 0 yields the default behaviour, 1 selects the
 *             alternate name set).
 * @return Generated name string.
 */
std::string generate_fantasy_animatronics_name(std::mt19937& rng, int type = 0);

#endif // FANTASY_ANIMATRONICS_LIB_H
