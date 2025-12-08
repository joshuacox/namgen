#ifndef POP_CULTURE_HOMESTUCKS_LIB_H
#define POP_CULTURE_HOMESTUCKS_LIB_H

#include <random>
#include <string>

/* Generate a Homestucks‑style name.
 * The algorithm mirrors the JavaScript implementation found in
 * .javascript-fantasy-names-deprecated/generators/pop_culture/homestucks.js
 */
std::string generate_pop_culture_homestucks_name(std::mt19937& rng);

#endif // POP_CULTURE_HOMESTUCKS_LIB_H
