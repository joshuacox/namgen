#ifndef DOCTOR_WHO_RAXACORICOFALLAPATORIANS_LIB_H
#define DOCTOR_WHO_RAXACORICOFALLAPATORIANS_LIB_H

#include <string>
#include <random>

/**
 * @brief Generate a Doctor Who – Raxacoricofallapatorians style name.
 *
 * The algorithm mirrors the original JavaScript implementation found in
 * `.javascript-fantasy-names-deprecated/generators/doctor_who/raxacoricofallapatorians.js`.
 *
 * @param rng Random number generator to use.
 * @return A generated name string.
 */
std::string generate_doctor_who_raxacoricofallapatorians_name(std::mt19937& rng);

#endif // DOCTOR_WHO_RAXACORICOFALLAPATORIANS_LIB_H
