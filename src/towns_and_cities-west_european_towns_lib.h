#ifndef TOWNS_AND_CITIES_WEST_EUROPEAN_TOWNS_LIB_H
#define TOWNS_AND_CITIES_WEST_EUROPEAN_TOWNS_LIB_H

#include <string>
#include <random>

/**
 * @brief Generate a random West European town name.
 *
 * This function replicates the behaviour of the legacy JavaScript generator
 * located at:
 * .javascript-fantasy-names-deprecated/generators/towns_and_cities/west_european_towns.js
 *
 * @param rng A random number generator (e.g. std::mt19937).
 * @return A generated town name.
 */
std::string generate_west_european_town_name(std::mt19937& rng);

#endif // TOWNS_AND_CITIES_WEST_EUROPEAN_TOWNS_LIB_H
