#ifndef ARMOUR_CHESTS_LIB_H
#define ARMOUR_CHESTS_LIB_H

#include <random>
#include <string>

std::string generate_armour_chests_name(std::mt19937& rng, int type = 0);

#endif // ARMOUR_CHESTS_LIB_H
