#include "warhammer-daemons_of_chaos_lib.h"
#include <vector>
#include <algorithm>

/* Helper to pick a random element from a vector using the supplied RNG */
template <typename T>
static const T& random_choice(const std::vector<T>& vec, std::mt19937& rng) {
    std::uniform_int_distribution<std::size_t> dist(0, vec.size() - 1);
    return vec[dist(rng)];
}

/* Implementation of the name generator – direct translation of the JS version */
std::string generate_warhammer_daemons_of_chaos_name(std::mt19937& rng) {
    const std::vector<std::string> nm1 = {"", "", "", "", "c", "ch", "cr", "cz", "g", "gr", "k", "kr", "kh", "n", "q", "qh", "qr", "r", "rh", "sc", "str", "sk", "t", "tr", "v", "vr", "z", "zh"};
    const std::vector<std::string> nm2 = {"a", "o", "u", "a", "o", "u", "i", "a", "o", "u", "a", "o", "u", "i", "e", "e", "ai"};
    const std::vector<std::string> nm3 = {"'", "", "", "", "", ""};
    const std::vector<std::string> nm4 = {"ch", "dr", "dj", "dz", "g", "gh", "gg", "gr", "gd", "gb", "k", "kr", "kz", "m", "mn", "mz", "mr", "n", "nn", "nd", "ng", "nz", "ndr", "nbr", "ngr", "r", "rr", "rdr", "rgr", "rz", "rzh", "rzr", "rbr", "sr", "sg", "sgh", "shr", "zh", "zr", "zhr", "zg", "zk"};
    const std::vector<std::string> nm5 = {"c", "k", "l", "n", "nd", "s", "th", "z"};
    const std::vector<std::string> nm6 = {"amber", "ash", "battle", "bitter", "blade", "blaze", "blazing", "blood", "bone", "chain", "chaos", "cinder", "claw", "dead", "death", "ember", "fate", "fire", "flame", "fury", "gore", "grim", "heart", "hell", "horn", "lone", "mourn", "nether", "night", "obsidian", "onyx", "plague", "pyre", "rage", "shadow", "silent", "skull", "slate", "storm", "void", "wild", "wrath"};
    const std::vector<std::string> nm7 = {"bane", "bender", "binder", "blaze", "bleeder", "blight", "born", "brand", "breaker", "breath", "bringer", "caller", "chaser", "cleaver", "crest", "dancer", "drifter", "father", "flayer", "force", "forged", "gaze", "gazer", "grip", "heart", "hunter", "keeper", "maker", "master", "might", "mourn", "reaper", "reaver", "rider", "ripper", "seeker", "shade", "shadow", "shaper", "strider", "striker", "sworn", "taker", "thane", "watcher", "weaver"};
    const std::vector<std::string> nm8 = {"the ", "", "", ""};

    // The original JS generator performed an extra random step (i = Math.floor(Math.random() * 10))
    // which is unused in the result; we keep the behaviour for parity.
    std::uniform_int_distribution<int> dummyDist(0, 9);
    (void)dummyDist(rng); // discard

    std::size_t rnd  = rng() % nm1.size();
    std::size_t rnd2 = rng() % nm2.size();
    std::size_t rnd3 = rng() % nm3.size();
    std::size_t rnd4 = rng() % nm2.size();
    std::size_t rnd5 = rng() % nm4.size();
    std::size_t rnd6 = rng() % nm5.size();
    std::size_t rnd7 = rng() % nm6.size();
    std::size_t rnd8 = rng() % nm7.size();
    std::size_t rnd9 = rng() % nm8.size();

    // Ensure the adjective (nm6) and noun suffix (nm7) are not identical
    while (nm6[rnd7] == nm7[rnd8]) {
        rnd8 = rng() % nm7.size();
    }

    std::string name = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd5] + nm2[rnd4] + nm5[rnd6] +
                       " " + nm8[rnd9] + nm6[rnd7] + nm7[rnd8];
    return name;
}
