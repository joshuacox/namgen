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

static std::string toLowerAlphaNum(const std::string& input) {
    std::string out;
    out.reserve(input.size());
    for (unsigned char c : input) {
        if (std::isalnum(c)) {
            out.push_back(static_cast<char>(std::tolower(c)));
        }
    }
    return out;
}

std::string toBrandToken(const std::string& input) {
    std::string result;
    bool nextUpper = true;
    for (unsigned char c : input) {
        if (std::isalnum(c)) {
            if (nextUpper) {
                result.push_back(static_cast<char>(std::toupper(c)));
                nextUpper = false;
            } else {
                result.push_back(static_cast<char>(std::tolower(c)));
            }
        } else {
            if (!result.empty()) {
                nextUpper = true;
            }
        }
    }
    return result;
}

static std::string phoneticallyClarifyChunk(const std::string& chunk, bool isFirst) {
    std::string out;
    out.reserve(chunk.size() + 2);
    for (size_t i = 0; i < chunk.size(); ++i) {
        char c = chunk[i];
        char next = (i + 1 < chunk.size()) ? chunk[i + 1] : '\0';
        if (c == 'p' && next == 'h') {
            out += 'f';
            ++i;
        } else if (c == 'q' && next == 'u') {
            out += "kw";
            ++i;
        } else if (c == 'a' && next == 'e') {
            out += "ay";
            ++i;
        } else if (c == 'e' && next == 'i') {
            out += "ay";
            ++i;
        } else if (c == 'a' && next == 'u') {
            out += "aw";
            ++i;
        } else if (c == 'o' && next == 'u') {
            out += "ow";
            ++i;
        } else if (c == 'x') {
            out += (isFirst && i == 0) ? "z" : "ks";
        } else if (c == 'y' && !isFirst && !isVowel(next) && next == '\0') {
            out += "ee";
        } else {
            out.push_back(c);
        }
    }
    return out;
}

std::string pronunciationSigil(const std::string& word) {
    std::string clean = toLowerAlphaNum(word);
    if (clean.empty()) return "";

    std::vector<std::string> syllables;
    std::string current;
    for (size_t i = 0; i < clean.size(); ++i) {
        char c = clean[i];
        current.push_back(c);
        bool curVowel = isVowel(c);
        bool nextExists = (i + 1 < clean.size());
        if (curVowel && nextExists) {
            bool nextVowel = isVowel(clean[i + 1]);
            // Split after vowel group when followed by C + V, or split between two consonants C1 C2
            if (!nextVowel) {
                if (i + 2 < clean.size()) {
                    bool thirdVowel = isVowel(clean[i + 2]);
                    if (thirdVowel) {
                        // V-CV boundary
                        syllables.push_back(current);
                        current.clear();
                    } else if (!isVowel(clean[i + 1]) && !isVowel(clean[i + 2])) {
                        // VC-CV boundary
                        current.push_back(clean[i + 1]);
                        ++i;
                        syllables.push_back(current);
                        current.clear();
                    }
                }
            }
        }
    }
    if (!current.empty()) {
        // Merge trailing consonant-only fragment onto previous syllable
        if (!syllables.empty()) {
            bool hasVowel = false;
            for (char ch : current) {
                if (isVowel(ch)) {
                    hasVowel = true;
                    break;
                }
            }
            if (!hasVowel) {
                syllables.back() += current;
                current.clear();
            }
        }
        if (!current.empty()) {
            syllables.push_back(current);
        }
    }

    if (syllables.empty()) {
        syllables.push_back(clean);
    }

    // Capitalize stressed syllable (first syllable unless 3+ syllables where 1st or penult is accented -> first syllable works cleanly)
    size_t stressIdx = 0;
    std::string sigil = "/";
    for (size_t i = 0; i < syllables.size(); ++i) {
        std::string chunk = phoneticallyClarifyChunk(syllables[i], i == 0);
        if (i == stressIdx) {
            for (char& ch : chunk) {
                ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
            }
        }
        if (i > 0) sigil += '-';
        sigil += chunk;
    }
    sigil += '/';
    return sigil;
}

std::string portmanteauBlend(const std::string& aRaw, const std::string& bRaw) {
    std::string a = toLowerAlphaNum(aRaw);
    std::string b = toLowerAlphaNum(bRaw);
    if (a.empty()) return toBrandToken(b);
    if (b.empty()) return toBrandToken(a);
    if (a == b) return toBrandToken(a);

    // 1. Overlap fusion: try overlap lengths 3, 2, 1
    size_t maxOverlap = std::min<size_t>(3, std::min(a.size(), b.size()) - 1);
    for (size_t ov = maxOverlap; ov >= 1; --ov) {
        if (a.size() >= ov + 2 && b.size() >= ov + 2 &&
            a.substr(a.size() - ov) == b.substr(0, ov)) {
            return toBrandToken(a + b.substr(ov));
        }
        if (ov == 1) break;
    }

    // 2. Syllable-seam splice: keep first vowel-anchored prefix of a (at least 3 chars)
    size_t cutA = std::max<size_t>(2, (a.size() * 2 + 1) / 3);
    for (size_t i = 2; i < a.size(); ++i) {
        if (isVowel(a[i - 1]) && !isVowel(a[i])) {
            cutA = i + 1;
            if (cutA >= (a.size() + 1) / 2) break;
        }
    }
    if (cutA > a.size()) cutA = a.size();
    std::string head = a.substr(0, cutA);

    // Trim tail start only for longer second words, keeping onset clean
    size_t startB = 0;
    if (b.size() >= 6) {
        for (size_t i = 1; i + 3 <= b.size(); ++i) {
            if (isVowel(b[i - 1]) && !isVowel(b[i])) {
                startB = i;
                break;
            }
        }
    }
    std::string tail = b.substr(startB);
    if (!head.empty() && !tail.empty() && head.back() == tail.front()) {
        tail.erase(tail.begin());
    }
    if (head.size() + tail.size() < 4) {
        return toBrandToken(a + b);
    }
    return toBrandToken(head + tail);
}

} // namespace Linguistics
