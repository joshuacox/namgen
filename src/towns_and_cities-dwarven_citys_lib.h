#ifndef TOWNS_AND_CITIES_DWARVEN_CITYS_LIB_H
#define TOWNS_AND_CITIES_DWARVEN_CITYS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a dwarven city name.
 *
 * Mirrors the legacy JavaScript generator `generators/towns_and_cities/dwarven_citys.js`.
 *
 * @param rng A random number generator (e.g. std::mt19937) used for the selections.
 * @return A generated dwarven city name.
 */
std::string generate_towns_and_cities_dwarven_citys_name(std::mt19937& rng);

#endif // TOWNS_AND_CITIES_DWARVEN_CITYS_LIB_H
