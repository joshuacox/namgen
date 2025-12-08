#include "destiny-cabals_lib.h"

#include <vector>

std::string generate_destiny_cabals_name(std::mt19937& rng) {
    static const std::vector<std::string> nm1 = {"d","dh","g","gh","k","kh","m","n","sh","t","th","tl","v","z","zh"};
    static const std::vector<std::string> nm2 = {"a'au","au'ua","o'ou","u'u","u'ua","u'uo","ua'au"};
    static const std::vector<std::string> nm2b = {"a","o","u"};
    static const std::vector<std::string> nm3 = {"d","g","l","m","n","r","v","z"};
    static const std::vector<std::string> nm4 = {"c","ch","g","l","m","n","r","v","z"};
    static const std::vector<std::string> nm5 = {"c","d","k","l","lk","ll","m","n","rc","rd","rg","rk","rn"};

    int i = static_cast<int>(rng() % 10);
    size_t rnd = rng() % nm1.size();

    std::string name;
    if (i < 5) {
        size_t rnd2 = rng() % nm2.size();
        size_t rnd3 = rng() % nm5.size();
        name = nm1[rnd] + nm2[rnd2] + nm5[rnd3];
    } else if (i < 7) {
        size_t rnd2 = rng() % nm2b.size();
        size_t rnd3 = rng() % nm4.size();
        name = nm1[rnd] + nm2b[rnd2] + nm4[rnd3];
    } else {
        size_t rnd2 = rng() % nm2b.size();
        size_t rnd3 = rng() % nm4.size();
        // size_t rnd4 = rng() % nm2b.size(); // unused in original JS
        size_t rnd5 = rng() % nm3.size();
        name = nm1[rnd] + nm2b[rnd2] + nm3[rnd5] + nm2b[rnd2] + nm4[rnd3];
    }
    return name;
}
