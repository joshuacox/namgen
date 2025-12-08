#ifndef DRAGON_BALL_FRIEZA_CLANS_LIB_H
#define DRAGON_BALL_FRIEZA_CLANS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Dragon Ball “Frieza Clans” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/dragon_ball/frieza_clans.js`.
 *
 * @param rng Random number generator.
 * @return Generated name string.
 */
std::string generate_dragon_ball_frieza_clans_name(std::mt19937& rng);

#endif // DRAGON_BALL_FRIEZA_CLANS_LIB_H
