#ifndef DUNGEON_AND_DRAGONS_ELFS_LIB_H
#define DUNGEON_AND_DRAGONS_ELFS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Dungeons & Dragons “elfs” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/dungeon_and_dragons/elfs.js`.
 *
 * @param rng  Random number generator.
 * @param type Optional type selector (the original JS accepts a `type`
 *             argument; passing 0 yields the default behaviour, 1 uses the
 *             alternate name set).
 * @return Generated name string.
 */
std::string generate_dungeon_and_dragons_elfs_name(std::mt19937& rng, int type = 0);

#endif // DUNGEON_AND_DRAGONS_ELFS_LIB_H
