#ifndef STAR_WARS_THE_OLD_REPUBLIC_CHISS_LIB_H
#define STAR_WARS_THE_OLD_REPUBLIC_CHISS_LIB_H

#include <string>
#include <random>

/**
 * @brief Generate a single Chiss name.
 *
 * The implementation resides in `star_wars_the_old_republic-chiss_lib.cpp`.
 *
 * @param rng A reference to a seeded std::mt19937 random number generator.
 * @return A generated Chiss name.
 */
std::string generate_star_wars_the_old_republic_chiss_name(std::mt19937& rng);

#endif // STAR_WARS_THE_OLD_REPUBLIC_CHISS_LIB_H
