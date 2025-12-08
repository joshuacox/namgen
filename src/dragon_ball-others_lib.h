#ifndef DRAGON_BALL_OTHERS_LIB_H
#define DRAGON_BALL_OTHERS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Dragon Ball “others” style name.
 *
 * Mirrors the JavaScript generator in
 * `fantasy-names/generators/dragon_ball/others.js`.
 *
 * @param rng Random number generator.
 * @return Generated name string.
 */
std::string generate_dragon_ball_others_name(std::mt19937& rng);

#endif // DRAGON_BALL_OTHERS_LIB_H
