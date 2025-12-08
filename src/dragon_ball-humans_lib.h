#ifndef DRAGON_BALL_HUMANS_LIB_H
#define DRAGON_BALL_HUMANS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Dragon Ball “humans” style name.
 *
 * Mirrors the JavaScript generator in
 * `fantasy-names/generators/dragon_ball/humans.js`.
 *
 * @param rng   Random number generator.
 * @param type  Optional type selector (0 = male, 1 = female).
 * @return      Generated name string.
 */
std::string generate_dragon_ball_humans_name(std::mt19937& rng, int type = 0);

#endif // DRAGON_BALL_HUMANS_LIB_H
