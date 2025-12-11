#ifndef ELDER_SCROLLS_BOSMERS_LIB_H
#define ELDER_SCROLLS_BOSMERS_LIB_H

#include <string>
#include <random>

/* Generates a single Elder Scrolls Bosmer style name.
   The implementation mirrors the behaviour of the deprecated JavaScript
   generator located at:
   .javascript-fantasy-names-deprecated/generators/elder_scrolls/bosmers.js
*/
std::string generate_elder_scrolls_bosmers_name(std::mt19937& rng);

#endif // ELDER_SCROLLS_BOSMERS_LIB_H
