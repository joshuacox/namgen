#ifndef GAME_OF_THRONES_DOTHRAKIS_LIB_H
#define GAME_OF_THRONES_DOTHRAKIS_LIB_H

#include <string>
#include <random>

/* Generate a Game of Thrones Dothraki style name.
 * The implementation mirrors the JavaScript generator found in
 * .javascript-fantasy-names-deprecated/generators/game_of_thrones/dothrakis.js
 */
std::string generate_game_of_thrones_dothrakis_name(std::mt19937& rng);

#endif // GAME_OF_THRONES_DOTHRAKIS_LIB_H
