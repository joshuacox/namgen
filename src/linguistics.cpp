#include "linguistics.h"
#include <cctype>
#include <vector>
#include <sstream>
#include <algorithm>

namespace Linguistics {

static inline bool isVowel(char c) {
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int countWordSyllables(const std::string& rawWord) {
    if (rawWord.empty()) return 0;

    std::string word = "";
    for (char c : rawWord) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            word += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
    }
    if (word.empty()) return 0;
    if (word.length() <= 3) return 1;

    int syllables = 0;
    bool prevIsVowel = false;

    for (size_t i = 0; i < word.length(); ++i) {
        bool currentIsVowel = isVowel(word[i]);
        if (currentIsVowel && !prevIsVowel) {
            syllables++;
        }
        prevIsVowel = currentIsVowel;
    }

    // Trailing 'e' is usually silent unless ending in 'le' after consonant
    if (word.back() == 'e') {
        if (word.length() > 2 && word[word.length() - 2] == 'l' && !isVowel(word[word.length() - 3])) {
            // e.g. "tle", "ble", "dle" keeps syllable
        } else {
            syllables--;
        }
    }

    // Trailing "ed" without 't' or 'd' preceding
    if (word.length() > 3 && word.substr(word.length() - 2) == "ed") {
        char beforeEd = word[word.length() - 3];
        if (beforeEd != 'd' && beforeEd != 't') {
            syllables--;
        }
    }

    return std::max(1, syllables);
}

int countSyllables(const std::string& name) {
    int total = 0;
    std::string current = "";
    for (char c : name) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            current += c;
        } else if (!current.empty()) {
            total += countWordSyllables(current);
            current.clear();
        }
    }
    if (!current.empty()) {
        total += countWordSyllables(current);
    }
    return std::max(1, total);
}

bool matchesSyllables(const std::string& name, int minSyl, int maxSyl) {
    int count = countSyllables(name);
    if (minSyl > 0 && count < minSyl) return false;
    if (maxSyl > 0 && count > maxSyl) return false;
    return true;
}

bool isAlliterative(const std::string& name) {
    std::vector<char> firstLetters;
    std::string current = "";

    for (char c : name) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            current += c;
        } else if (!current.empty()) {
            firstLetters.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(current[0]))));
            current.clear();
        }
    }
    if (!current.empty()) {
        firstLetters.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(current[0]))));
    }

    if (firstLetters.size() < 2) {
        return false;
    }

    char first = firstLetters[0];
    for (size_t i = 1; i < firstLetters.size(); ++i) {
        if (firstLetters[i] != first) {
            return false;
        }
    }
    return true;
}

} // namespace Linguistics
