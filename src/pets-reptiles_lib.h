#ifndef PETS_REPTILES_LIB_H
#define PETS_REPTILES_LIB_H

#include <string>
#include <random>

/**
 * @brief Generate a reptile pet name.
 *
 * This function replicates the behaviour of the legacy JavaScript generator
 * `.javascript-fantasy-names-deprecated/generators/pets/reptiles.js`.
 *
 * @param rng   Random number generator to use.
 * @param type  If 1, selects from the secondary name list; otherwise selects
 *              from the primary list. The original JS ignored the random `i`
 *              variable, so we keep the same behaviour.
 * @return      A randomly selected reptile name.
 */
std::string generate_pets_reptiles_name(std::mt19937& rng, int type = 0);

#endif // PETS_REPTILES_LIB_H
