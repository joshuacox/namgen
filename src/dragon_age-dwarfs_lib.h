#ifndef DRAGON_AGE_DWARFS_LIB_H
#define DRAGON_AGE_DWARFS_LIB_H

#include <string>
#include <random>

/**
 * @brief Generate a Dragon Age dwarf name.
 *
 * The function mimics the behaviour of the legacy JavaScript generator
 * (generators/dragon_age/dwarfs.js). It randomly chooses a gender (male or
 * female) and then builds a name from the appropriate name parts.
 *
 * @param rng A random number generator (e.g. std::mt19937).
 * @return A fully‑formed dwarf name (e.g. "Arianna Bregg" or "Baldur dal").
 */
std::string generate_dragon_age_dwarfs_name(std::mt19937& rng);

#endif // DRAGON_AGE_DWARFS_LIB_H
