#ifndef INHERITANCE_CYCLE_DRAGONS_LIB_H
#define INHERITANCE_CYCLE_DRAGONS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a name using the "inheritance_cycle-dragons" generator.
 *
 * This function replicates the behaviour of the JavaScript generator
 * `.javascript-fantasy-names-deprecated/generators/inheritance_cycle/dragons.js`.
 *
 * @param rng   Random number generator to use.
 * @param type  Generator type (0 = default, 1 = alternate style). The CLI flag
 *              does not expose this, so callers should pass 0.
 * @return      Generated name.
 */
std::string generate_inheritance_cycle_dragons_name(std::mt19937& rng, int type = 0);

#endif // INHERITANCE_CYCLE_DRAGONS_LIB_H
