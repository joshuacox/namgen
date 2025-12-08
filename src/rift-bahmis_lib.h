#ifndef RIFT_BAHMIS_LIB_H
#define RIFT_BAHMIS_LIB_H

#include <string>
#include <random>

/* Generate a Rift‑Bahmis name.
 * The original JavaScript generator has two sets of name parts depending on a
 * “type” argument.  The CLI flag does not expose a type, so we use the default
 * (type != 1) set which matches the behaviour of the original script when
 * called without a type.
 */
std::string generate_rift_bahmis_name(std::mt19937& rng);

#endif // RIFT_BAHMIS_LIB_H
