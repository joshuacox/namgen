#ifndef HALO_FORERUNNERS_LIB_H
#define HALO_FORERUNNERS_LIB_H

#include <string>
#include <random>

/* Generate a Halo “forerunners” style name.
   The function picks a random element from two internal word lists
   and concatenates them with a space. */
std::string generate_halo_forerunners_name(std::mt19937& rng);

#endif // HALO_FORERUNNERS_LIB_H
