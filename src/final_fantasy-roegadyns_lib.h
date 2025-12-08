#ifndef FINAL_FANTASY_ROEGADYNS_LIB_H
#define FINAL_FANTASY_ROEGADYNS_LIB_H

#include <string>
#include <random>

/* Generate a Final Fantasy Roegadyn name.
   The algorithm mirrors the JavaScript implementation in
   .javascript-fantasy-names-deprecated/generators/final_fantasy/roegadyns.js */
std::string generate_final_fantasy_roegadyns_name(std::mt19937& rng);

#endif // FINAL_FANTASY_ROEGADYNS_LIB_H
