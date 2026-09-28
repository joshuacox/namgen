#ifndef STAR_TREK_FERENGIS_LIB_H
#define STAR_TREK_FERENGIS_LIB_H

#include <random>
#include <string>

std::string generate_star_trek_ferengis_name(std::mt19937& rng, int type = 0);

#endif // STAR_TREK_FERENGIS_LIB_H
