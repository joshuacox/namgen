#include "doctor_who-ice_warriors_lib.h"

#include <vector>
#include <string>
#include <random>

std::string generate_doctor_who_ice_warriors_name(std::mt19937& rng) {
    static const std::vector<std::string> nm1 = {"h","gr","g","gl","k","kr","kl","r","sk","sl","ss","sr","sz","v","vr","xz","x","xr","xzn","z"};
    static const std::vector<std::string> nm2 = {"a","i","o","e","aa","a","u","a","y","a"};
    static const std::vector<std::string> nm3 = {"d","dr","kss","ld","m","nt","r","rt","rd","rn","rg","sb","sr","sz","szr","zr","ssb","x","xl","z","zd"};
    static const std::vector<std::string> nm4 = {"d","dz","k","kz","l","lk","n","r","rd","rzz","rz","rs","x","z"};
    static const std::vector<std::string> nm5 = {"a","","","","","",""};

    std::uniform_int_distribution<int> dist0(0, 9);
    int i = dist0(rng);

    if (i < 5) {
        std::uniform_int_distribution<std::size_t> d5(0, nm5.size() - 1);
        std::uniform_int_distribution<std::size_t> d1(0, nm1.size() - 1);
        std::uniform_int_distribution<std::size_t> d2(0, nm2.size() - 1);
        std::uniform_int_distribution<std::size_t> d3(0, nm3.size() - 1);
        std::uniform_int_distribution<std::size_t> d4(0, nm4.size() - 1);

        std::string name = nm5[d5(rng)] + nm1[d1(rng)] + nm2[d2(rng)] + nm3[d3(rng)] + nm2[d2(rng)] + nm4[d4(rng)];
        return name;
    } else {
        std::uniform_int_distribution<std::size_t> d5(0, nm5.size() - 1);
        std::uniform_int_distribution<std::size_t> d1(0, nm1.size() - 1);
        std::uniform_int_distribution<std::size_t> d2(0, nm2.size() - 1);
        std::uniform_int_distribution<std::size_t> d4(0, nm4.size() - 1);

        std::string name = nm5[d5(rng)] + nm1[d1(rng)] + nm2[d2(rng)] + nm4[d4(rng)];
        return name;
    }
}
