#ifndef DRAGON_BALL_HAKAISHINS_LIB_H
#define DRAGON_BALL_HAKAISHINS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Dragon Ball “hakaishins” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/dragon_ball/hakaishins.js`.
 *
 * @param rng Random number generator.
 * @return Generated name string.
 */
std::string generate_dragon_ball_hakaishins_name(std::mt19937& rng);

#endif // DRAGON_BALL_HAKAISHINS_LIB_H
