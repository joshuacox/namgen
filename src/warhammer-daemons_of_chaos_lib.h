#ifndef WARHAMMER_DAEMONS_OF_CHAOS_LIB_H
#define WARHAMMER_DAEMONS_OF_CHAOS_LIB_H

#include <string>
#include <random>

/* Generate a Warhammer “Daemons of Chaos” style name.
   The algorithm mirrors the legacy JavaScript generator
   .javascript-fantasy-names-deprecated/generators/warhammer/daemons_of_chaos.js */
std::string generate_warhammer_daemons_of_chaos_name(std::mt19937& rng);

#endif // WARHAMMER_DAEMONS_OF_CHAOS_LIB_H
