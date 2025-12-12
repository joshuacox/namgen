#ifndef WILDERSTAR_MORDESHS_LIB_H
#define WILDERSTAR_MORDESHS_LIB_H

#include <random>
#include <string>

/* Generate a Wildstar Mordeshs name.
 * The implementation mirrors the JavaScript generator
 * .javascript-fantasy-names-deprecated/generators/wildstar/wildstar_mordeshs.js
 */
std::string generate_wildstar_mordeshs_name(std::mt19937& rng);

#endif // WILDERSTAR_MORDESHS_LIB_H
