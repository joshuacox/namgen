#ifndef DUNGEON_AND_DRAGONS_ELADRINS_LIB_H
#define DUNGEON_AND_DRAGONS_ELADRINS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Dungeons & Dragons “eladrins” style name.
 *
 * Mirrors the JavaScript generator in
 * `fantasy-names/generators/dungeon_and_dragons/eladrins.js`.
 *
 * @param rng  Random number generator.
 * @param type Optional type selector (0 = default, 1 = alternate style).
 * @return Generated name string.
 */
std::string generate_dungeon_and_dragons_eladrins_name(std::mt19937& rng, int type = 0);

#endif // DUNGEON_AND_DRAGONS_ELADRINS_LIB_H
