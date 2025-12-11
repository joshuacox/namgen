#ifndef MILITARY_ROYAL_NAVY_LIB_H
#define MILITARY_ROYAL_NAVY_LIB_H

#include <string>
#include <random>

/**
 * @brief Generate a random "military royal navy" name.
 *
 * This function replicates the behaviour of the deprecated JavaScript generator
 * located at .javascript-fantasy-names-deprecated/generators/military/royal_navy.js.
 *
 * It selects two distinct names from a predefined list and returns them
 * concatenated with a single space.
 *
 * @param rng A random number generator (e.g. std::mt19937) to use for selection.
 * @return A string containing the generated name.
 */
std::string generate_military_royal_navy_name(std::mt19937& rng);

#endif // MILITARY_ROYAL_NAVY_LIB_H
