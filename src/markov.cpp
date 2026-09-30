#include "markov.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

MarkovModel::MarkovModel(int order) {
    setOrder(order);
}

void MarkovModel::setOrder(int order) {
    order_ = std::max(2, std::min(order, 5));
}

void MarkovModel::addWord(const std::string& rawWord) {
    if (rawWord.empty()) return;

    // Trim whitespace
    size_t first = rawWord.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return;
    size_t last = rawWord.find_last_not_of(" \t\r\n");
    std::string word = rawWord.substr(first, last - first + 1);

    if (word.length() < 2) return;

    std::string prefix(order_ - 1, '^');
    startPrefixes_.push_back(prefix);

    for (char c : word) {
        transitions_[prefix].push_back(c);
        prefix = prefix.substr(1) + c;
    }
    // End-of-word marker
    transitions_[prefix].push_back('$');
}

void MarkovModel::train(const std::vector<std::string>& samples) {
    transitions_.clear();
    startPrefixes_.clear();
    for (const auto& sample : samples) {
        // If sample has multiple words, train on each word
        std::istringstream iss(sample);
        std::string token;
        while (iss >> token) {
            addWord(token);
        }
    }
}

bool MarkovModel::trainFromFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        return false;
    }
    std::vector<std::string> words;
    std::string line;
    while (std::getline(file, line)) {
        words.push_back(line);
    }
    train(words);
    return isTrained();
}

std::string MarkovModel::generate(std::mt19937& rng, int minLength, int maxLength) {
    if (transitions_.empty()) {
        return "";
    }

    const int maxAttempts = 50;
    for (int attempt = 0; attempt < maxAttempts; ++attempt) {
        std::string prefix(order_ - 1, '^');
        std::string result = "";

        while (result.length() < static_cast<size_t>(maxLength)) {
            auto it = transitions_.find(prefix);
            if (it == transitions_.end() || it->second.empty()) {
                break;
            }

            const auto& nextChars = it->second;
            std::uniform_int_distribution<size_t> dist(0, nextChars.size() - 1);
            char nextChar = nextChars[dist(rng)];

            if (nextChar == '$') {
                break;
            }

            result += nextChar;
            prefix = prefix.substr(1) + nextChar;
        }

        if (result.length() >= static_cast<size_t>(minLength) &&
            result.length() <= static_cast<size_t>(maxLength)) {
            // Capitalize first character
            if (!result.empty()) {
                result[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(result[0])));
            }
            return result;
        }
    }

    // Fallback: return best effort if within reasonable size
    std::string prefix(order_ - 1, '^');
    std::string result = "";
    while (result.length() < static_cast<size_t>(maxLength)) {
        auto it = transitions_.find(prefix);
        if (it == transitions_.end() || it->second.empty()) break;
        const auto& nextChars = it->second;
        std::uniform_int_distribution<size_t> dist(0, nextChars.size() - 1);
        char nextChar = nextChars[dist(rng)];
        if (nextChar == '$') break;
        result += nextChar;
        prefix = prefix.substr(1) + nextChar;
    }
    if (!result.empty()) {
        result[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(result[0])));
    }
    return result;
}
