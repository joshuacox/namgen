#ifndef DOCTOR_WHO_SILURIANS_LIB_H
#define DOCTOR_WHO_SILURIANS_LIB_H

#include <string>
#include <random>

/**
 * @brief Generate a Doctor Who Silurians name.
 *
 * The implementation mirrors the JavaScript generator located at
 * .javascript-fantasy-names-deprecated/generators/doctor_who/silurians.js.
 *
 * @param rng   Random number generator to use.
 * @param type  If 1, use the “type‑1” name generation algorithm; otherwise
 *              use the default algorithm. The CLI flag does not expose this
 *              parameter – it always calls the default (type 0) algorithm.
 * @return      Generated name.
 */
std::string generate_doctor_who_silurians_name(std::mt19937& rng, int type = 0);

#endif // DOCTOR_WHO_SILURIANS_LIB_H
