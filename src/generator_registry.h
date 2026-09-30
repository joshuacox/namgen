#ifndef GENERATOR_REGISTRY_H
#define GENERATOR_REGISTRY_H

#include <functional>
#include <memory>
#include <random>
#include <string>
#include <vector>
#include <unordered_map>

using GeneratorFunc = std::function<std::string(std::mt19937&)>;

struct GeneratorInfo {
    std::string flag;                 // Primary flag without leading "--"
    std::vector<std::string> aliases; // Additional flag aliases without leading "--"
    std::string description;          // Short description for help output
    GeneratorFunc generate;           // Callable taking std::mt19937& RNG
};

class GeneratorRegistry {
public:
    static GeneratorRegistry& instance();

    // Register a generator entry
    void registerGenerator(GeneratorInfo info);

    // Lookup a generator by flag name or alias (with or without leading "--", hyphen/underscore tolerant)
    const GeneratorInfo* find(const std::string& flagName) const;

    // Search generators by substring / keyword in flag, alias, or description
    std::vector<const GeneratorInfo*> search(const std::string& query) const;

    // Get all registered generators in insertion order
    const std::vector<std::unique_ptr<GeneratorInfo>>& getAll() const;

private:
    GeneratorRegistry();
    void initBuiltins();

    std::vector<std::unique_ptr<GeneratorInfo>> generators_;
    std::unordered_map<std::string, const GeneratorInfo*> lookup_;
};

#endif // GENERATOR_REGISTRY_H
