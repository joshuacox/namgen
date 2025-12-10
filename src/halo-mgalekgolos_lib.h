#ifndef HALO_MGALEKGOLOS_LIB_H
#define HALO_MGALEKGOLOS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Halo “Mgalekgolos” style name.
 *
 * The algorithm mirrors the JavaScript implementation found in
 * `.javascript-fantasy-names-deprecated/generators/halo/mgalekgolos.js`.
 *
 * @param rng Random number generator.
 * @return Generated name string (three words separated by spaces).
 */
std::string generate_halo_mgalekgolos_name(std::mt19937& rng);

#endif // HALO_MGALEKGOLOS_LIB_H
