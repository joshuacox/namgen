#ifndef NAMGEN_MARKOV_H
#define NAMGEN_MARKOV_H

#include <string>
#include <vector>
#include <unordered_map>
#include <random>

class MarkovModel {
public:
    explicit MarkovModel(int order = 3);

    void setOrder(int order);
    int getOrder() const { return order_; }

    // Train on a list of words or sample names
    void train(const std::vector<std::string>& samples);
    bool trainFromFile(const std::string& filepath);

    // Generate a novel name using the trained n-gram model
    std::string generate(std::mt19937& rng, int minLength = 3, int maxLength = 18);

    bool isTrained() const { return !transitions_.empty(); }

private:
    int order_;
    std::unordered_map<std::string, std::vector<char>> transitions_;
    std::vector<std::string> startPrefixes_;

    void addWord(const std::string& word);
};

#endif // NAMGEN_MARKOV_H
