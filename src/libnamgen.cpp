#include "libnamgen.h"
#include "generator_registry.h"
#include "markov.h"

#include <string>
#include <vector>
#include <random>
#include <cstring>
#include <algorithm>

extern "C" {

int namgen_c_generate(const char* generator_flag, int count, unsigned int seed, char* out_buf, int max_buf_len) {
    if (!out_buf || max_buf_len <= 0 || count <= 0) {
        return -1;
    }

    std::string flag = (generator_flag != nullptr && generator_flag[0] != '\0') ? generator_flag : "fantasy-elfs";
    const GeneratorInfo* gen = GeneratorRegistry::instance().find(flag);
    if (!gen && flag.rfind("--", 0) != 0) {
        gen = GeneratorRegistry::instance().find("--" + flag);
    }

    if (!gen) {
        return -2; // Generator not found
    }

    std::mt19937 rng(seed != 0 ? seed : std::random_device{}());
    std::string combined;
    for (int i = 0; i < count; ++i) {
        std::string n = gen->generate(rng);
        if (i > 0) combined += "\n";
        combined += n;
    }

    if (static_cast<int>(combined.size()) >= max_buf_len) {
        std::strncpy(out_buf, combined.c_str(), max_buf_len - 1);
        out_buf[max_buf_len - 1] = '\0';
        return max_buf_len - 1;
    }

    std::strcpy(out_buf, combined.c_str());
    return static_cast<int>(combined.size());
}

int namgen_c_markov(const char* generator_flag, int count, int order, unsigned int seed, char* out_buf, int max_buf_len) {
    if (!out_buf || max_buf_len <= 0 || count <= 0) {
        return -1;
    }

    std::string flag = (generator_flag != nullptr && generator_flag[0] != '\0') ? generator_flag : "fantasy-elfs";
    const GeneratorInfo* gen = GeneratorRegistry::instance().find(flag);
    if (!gen && flag.rfind("--", 0) != 0) {
        gen = GeneratorRegistry::instance().find("--" + flag);
    }
    if (!gen) {
        gen = GeneratorRegistry::instance().find("fantasy-elfs");
    }

    std::mt19937 rng(seed != 0 ? seed : std::random_device{}());
    MarkovModel model(order > 0 ? order : 3);
    std::vector<std::string> samples;
    for (int i = 0; i < 100; ++i) {
        samples.push_back(gen->generate(rng));
    }
    model.train(samples);

    std::string combined;
    for (int i = 0; i < count; ++i) {
        std::string n = model.generate(rng);
        if (i > 0) combined += "\n";
        combined += n;
    }

    if (static_cast<int>(combined.size()) >= max_buf_len) {
        std::strncpy(out_buf, combined.c_str(), max_buf_len - 1);
        out_buf[max_buf_len - 1] = '\0';
        return max_buf_len - 1;
    }

    std::strcpy(out_buf, combined.c_str());
    return static_cast<int>(combined.size());
}

int namgen_c_generator_count(void) {
    return static_cast<int>(GeneratorRegistry::instance().getAll().size());
}

const char* namgen_c_generator_flag(int index) {
    const auto& all = GeneratorRegistry::instance().getAll();
    if (index < 0 || static_cast<size_t>(index) >= all.size()) {
        return nullptr;
    }
    return all[index]->flag.c_str();
}

const char* namgen_c_generator_desc(int index) {
    const auto& all = GeneratorRegistry::instance().getAll();
    if (index < 0 || static_cast<size_t>(index) >= all.size()) {
        return nullptr;
    }
    return all[index]->description.c_str();
}

} // extern "C"
