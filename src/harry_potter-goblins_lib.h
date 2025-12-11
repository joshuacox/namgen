#ifndef HARRY_POTTER_GOBLINS_LIB_H
#define HARRY_POTTER_GOBLINS_LIB_H

#include <string>
#include <random>

/* Generate a Harry Potter “Goblins” style name.
   The implementation mirrors the JavaScript generator
   .javascript-fantasy-names-deprecated/generators/harry_potter/goblins.js */
std::string generate_harry_potter_goblins_name(std::mt19937& rng);

#endif // HARRY_POTTER_GOBLINS_LIB_H
