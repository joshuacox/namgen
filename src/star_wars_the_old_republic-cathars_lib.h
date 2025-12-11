#ifndef STAR_WARS_THE_OLD_REPUBLIC_CATHARS_LIB_H
#define STAR_WARS_THE_OLD_REPUBLIC_CATHARS_LIB_H

#include <random>
#include <string>

/**
 * @brief Generate a Star Wars: The Old Republic – Cathars name.
 *
 * The implementation mirrors the JavaScript generator located at
 * .javascript-fantasy-names-deprecated/generators/star_wars_the_old_republic/cathars.js.
 *
 * @param rng  Random number generator to use.
 * @return     A randomly generated Cathars name (first name + space + last name).
 */
std::string generate_star_wars_the_old_republic_cathars_name(std::mt19937& rng);

#endif // STAR_WARS_THE_OLD_REPUBLIC_CATHARS_LIB_H
