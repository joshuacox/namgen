#pragma once

#include <random>
#include <string>

// Generate a marine mammal name.
// If `type` is 1, the name is chosen from the secondary list (nm2),
// otherwise it is chosen from the primary list (nm1).
std::string generate_pets_marine_mammals_name(std::mt19937& rng, int type = 0);
