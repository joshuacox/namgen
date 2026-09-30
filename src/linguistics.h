#ifndef NAMGEN_LINGUISTICS_H
#define NAMGEN_LINGUISTICS_H

#include <string>

namespace Linguistics {

// Estimate syllable count in an English or fantasy word
int countWordSyllables(const std::string& word);

// Count total syllables across multi-word or hyphenated names
int countSyllables(const std::string& name);

// Check if syllable count falls within specified range [minSyl, maxSyl]
bool matchesSyllables(const std::string& name, int minSyl, int maxSyl);

// Check if multi-word name has matching initial consonants / sounds (e.g. Peter Parker, Balthazar Bronzebeard)
bool isAlliterative(const std::string& name);

} // namespace Linguistics

#endif // NAMGEN_LINGUISTICS_H
