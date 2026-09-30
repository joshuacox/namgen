#ifndef NAMGEN_LORE_H
#define NAMGEN_LORE_H

#include <string>
#include <random>

namespace Lore {

std::string generateEpithet(std::mt19937& rng);
std::string generateMeaning(std::mt19937& rng);
std::string formatWithLore(const std::string& name, std::mt19937& rng);

} // namespace Lore

#endif // NAMGEN_LORE_H
