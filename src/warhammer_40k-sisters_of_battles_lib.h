#ifndef WARHAMMER_40K_SISTERS_OF_BATTLES_LIB_H
#define WARHAMMER_40K_SISTERS_OF_BATTLES_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Warhammer 40k “Sisters of Battles” name.
 *
 * The algorithm mirrors the legacy JavaScript generator:
 *   - Choose a random prefix from a predefined list (nm1).
 *   - Choose a random suffix from a predefined list (nm2).
 *   - Concatenate them.
 *
 * @param rng Random number generator.
 * @return Generated name.
 */
std::string generate_warhammer_40k_sisters_of_battles_name(std::mt19937& rng);

#endif // WARHAMMER_40K_SISTERS_OF_BATTLES_LIB_H
