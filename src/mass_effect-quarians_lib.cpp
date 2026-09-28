#include "mass_effect-quarians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_mass_effect_quarians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names2[] = {"a", "e", "i", "o", "u", "aa", "ee", "ae"};
    static constexpr std::string_view names5[] = {"C", "F", "H", "G", "J", "L", "M", "N", "R", "S", "Sh", "V", "T", "W", "X", "Y", "Z"};
    static constexpr std::string_view names6[] = {"dal", "dda", "dor", "fal", "fin", "for", "gar", "l", "la", "lan", "las", "lin", "ll", "llo", "lon", "lun", "m", "ma", "man", "mas", "me", "min", "mis", "mm", "mma", "mor", "mos", "mun", "n", "nar", "nis", "nn", "nna", "r", "ra", "rah", "ram", "ras", "ris", "rol", "rrel", "rul", "s", "sa", "sal", "sar", "ss", "sul", "zh", "zu"};
    static constexpr std::string_view names7[] = {"nar", "vas"};
    static constexpr std::string_view names8[] = {"bra", "ca", "chol", "darum", "din", "dir", "dolor", "dor", "doruk", "firn", "fis", "gro", "hala", "hok", "ji", "jol", "ko", "kor", "kra", "larm", "lazi", "leya", "ma", "morn", "nbay", "nil", "nna", "pal", "pan", "ra", "rah", "raka", "ram", "rark", "reh", "ron", "sost", "talir", "vo", "vum", "wa", "wal", "wan", "wib", "worp", "yya", "zal", "zay", "zorn", "zzor"};
    static constexpr std::string_view names1_1[] = {"K", "G", "C", "F", "H", "J", "L", "M", "N", "R", "S", "V", "W", "Y", "Z", "C", "F", "H", "J", "L", "M", "N", "R", "S", "V", "W", "Y", "Z"};
    static constexpr std::string_view names3_1[] = {"f", "h", "l", "m", "n", "r", "s", "l", "n", "nn", "mm", "tor", "to", "sin", "lo"};
    static constexpr std::string_view names4_1[] = {""};
    static constexpr std::string_view names1_2[] = {"C", "F", "H", "J", "L", "M", "N", "R", "S", "Sh", "W", "Y", "Z"};
    static constexpr std::string_view names3_2[] = {"f", "h", "l", "m", "n", "r", "s", "l", "n", "nn", "mm"};
    static constexpr std::string_view names4_2[] = {"a", "e", "u", "i", "o", "a"};

    ArrayView names1; ArrayView names3; ArrayView names4; std::string names; size_t rnd0 = 0; size_t rnd1 = 0; size_t rnd10 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

    if (type == 1) {
    names1 = make_view(names1_1);
    names3 = make_view(names3_1);
    names4 = make_view(names4_1);
    } else {
    names1 = make_view(names1_2);
    names3 = make_view(names3_2);
    names4 = make_view(names4_2);
    }
i = rng() % 10; {
    rnd0 = rng() % std::size(names1);
    rnd1 = rng() % std::size(names2);
    rnd2 = rng() % std::size(names3);
    rnd3 = rng() % std::size(names4);
    rnd4 = rng() % std::size(names5);
    rnd5 = rng() % std::size(names2);
    rnd6 = rng() % std::size(names6);
    rnd7 = rng() % std::size(names7);
    rnd8 = rng() % std::size(names5);
    rnd9 = rng() % std::size(names2);
    rnd10 = rng() % std::size(names8);
    names = names1[rnd0] + names2[rnd1] + names3[rnd2] + names4[rnd3] + "'" + names5[rnd4] + names2[rnd5] + names6[rnd6] + " " + names7[rnd7] + " " + names5[rnd8] + names2[rnd9] + names8[rnd10];
    return names;
    }
}
