#ifndef DUNGEON_AND_DRAGONS_DWARFS_LIB_H
#define DUNGEON_AND_DRAGONS_DWARFS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Dungeons & Dragons “dwarfs” style name.
 *
 * Mirrors the JavaScript generator found in
 * `fantasy-names/generators/dungeon_and_dragons/dwarfs.js`.
 *
 * @param rng   Random number generator to use.
 * @param type  Optional type selector (the original JS accepts a `type`
 *              argument; passing 0 yields the default behaviour, 1 uses the
 *              alternate name set).
 * @return      Generated name string.
 */
std::string generate_dungeon_and_dragons_dwarfs_name(std::mt19937& rng, int type = 0);

#endif // DUNGEON_AND_DRAGONS_DWARFS_LIB_H
