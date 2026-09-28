#include "mass_effect-salarians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_mass_effect_salarians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names1[] = {"b", "c", "d", "f", "g", "h", "j", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "", "", "", ""};
    static constexpr std::string_view names2[] = {"a", "e", "o", "i", "u", "ae"};
    static constexpr std::string_view names3[] = {"r", "", ""};
    static constexpr std::string_view names4[] = {"b", "d", "g", "h", "k", "l", "m", "n", "p", "r", "s", "st", "t", "w"};
    static constexpr std::string_view names5[] = {"af", "al", "all", "an", "ann", "ant", "ar", "arf", "arp", "art", "arth", "aw", "ern", "ik", "in", "ip", "irn", "ok", "ol", "oln", "on", "op", "orm", "ort", "orth", "ow", "um"};
    static constexpr std::string_view names6[] = {"bam", "ban", "ben", "dril", "drok", "he", "ja", "ji", "ks", "lan", "lban", "lben", "lis", "lji", "lon", "lorn", "ls", "lu", "lus", "lzik", "mal", "min", "mnor", "mor", "nik", "nis", "nmorn", "nok", "pon", "raji", "ral", "ralan", "ran", "rban", "rix", "rji", "rlan", "ss", "u", "wan", "x", "yor", "zal", "zen", "zik", "zom", "zon", "zor", "zu", "zz"};
    static constexpr std::string_view names7_1[] = {""};
    static constexpr std::string_view names7_2[] = {"a", "e", "o", "i"};

    ArrayView names7; std::string names; size_t rnd0 = 0; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; int i = 0;

    if (type == 1) {
    names7 = make_view(names7_1);
    } else {
    names7 = make_view(names7_2);
    }
i = rng() % 10; {
    rnd0 = rng() % std::size(names1);
    rnd1 = rng() % std::size(names2);
    rnd2 = rng() % std::size(names3);
    rnd3 = rng() % std::size(names4);
    rnd4 = rng() % std::size(names5);
    rnd5 = rng() % std::size(names1);
while (names1[rnd5] == "") {
    rnd5 = rng() % std::size(names1);
    }
    rnd6 = rng() % std::size(names2);
    rnd7 = rng() % std::size(names6);
    rnd8 = rng() % std::size(names7);
    names = names1[rnd0] + names2[rnd1] + names3[rnd2] + names4[rnd3] + names5[rnd4] + " " + names1[rnd5] + names2[rnd6] + names6[rnd7] + names7[rnd8];
    return names;
    }
}
