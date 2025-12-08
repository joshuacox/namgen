#ifndef DUNGEON_AND_DRAGONS_GITHZERAIS_LIB_H
#define DUNGEON_AND_DRAGONS_GITHZERAIS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Dungeons & Dragons “githzerais” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/dungeon_and_dragons/githzerais.js`.
 *
 * @param rng  Random number generator.
 * @param type Optional type selector (1 = female variant, 0 = male/default).
 * @return Generated name string.
 */
std::string generate_dungeon_and_dragons_githzerais_name(std::mt19937& rng, int type = 0);

#endif // DUNGEON_AND_DRAGONS_GITHZERAIS_LIB_H
