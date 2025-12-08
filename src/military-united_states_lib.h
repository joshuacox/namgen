#pragma once

#include <string>
#include <random>

/**
 * @brief Generate a United States military style name.
 *
 * The generator selects two distinct words from the NATO phonetic alphabet
 * (e.g., "Alpha Bravo") and returns them separated by a space.
 *
 * @param rng Random number generator to use.
 * @return std::string Generated name.
 */
std::string generate_military_united_states_name(std::mt19937& rng);
