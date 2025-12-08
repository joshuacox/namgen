#include "destiny-hives_lib.h"

#include <vector>

std::string generate_destiny_hives_name(std::mt19937& rng, int type) {
    static const std::vector<std::string> nm1 = {"b","cr","d","g","gr","k","kr","m","n","r","s","tr","z"};
    static const std::vector<std::string> nm2 = {"a","e","o","u","a","e","o","u","a","e","o","u","oo"};
    static const std::vector<std::string> nm3 = {"c","cr","gr","k","kr","m","n","nd","r","rd","rg","rn","rv","rz","t","tr","v","z"};
    static const std::vector<std::string> nm4 = {"","c","k","k","n","r","x"};
    static const std::vector<std::string> nm5 = {"c","ch","h","m","n","ph","s","sh","th","v","z"};
    static const std::vector<std::string> nm6 = {"a","e","i","e","i","o"};
    static const std::vector<std::string> nm7 = {"g","lk","lm","ln","m","mn","n","nl","nr","rm","sh","sm","sn","sr","st","th","tr","v","vn","vr","z","zd","zl","zn"};
    static const std::vector<std::string> nm8 = {"","", "", "", "h","l","s","th"};

    std::string name;
    if (type == 1) {
        size_t rnd  = rng() % nm5.size();
        size_t rnd2 = rng() % nm6.size();
        size_t rnd3 = rng() % nm7.size();
        size_t rnd4 = rng() % nm6.size();
        size_t rnd5 = rng() % nm8.size();
        name = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5];
    } else {
        size_t rnd  = rng() % nm1.size();
        size_t rnd2 = rng() % nm2.size();
        size_t rnd3 = rng() % nm3.size();
        size_t rnd4 = rng() % nm2.size();
        size_t rnd5 = rng() % nm4.size();
        name = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    }
    return name;
}
