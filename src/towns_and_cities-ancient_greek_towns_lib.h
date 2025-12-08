#ifndef TOWNS_AND_CITIES_ANCIENT_GREEK_TOWNS_LIB_H
#define TOWNS_AND_CITIES_ANCIENT_GREEK_TOWNS_LIB_H

#include <string>
#include <random>

/* Generate a single ancient Greek town name.
   The function uses the supplied random number generator to pick
   a random prefix (nm1) and a random suffix (nm2) and concatenates
   them, reproducing the behaviour of the original JavaScript generator. */
std::string generate_towns_and_cities_ancient_greek_towns_name(std::mt19937& rng);

#endif // TOWNS_AND_CITIES_ANCIENT_GREEK_TOWNS_LIB_H
