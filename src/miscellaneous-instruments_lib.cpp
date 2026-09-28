#include "miscellaneous-instruments_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_instruments_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"a", "e", "i", "o", "u", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view names2[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "br", "cr", "gr", "pr", "tr", "ch", "bl", "cl", "fl", "gl", "kl", "pl", "sl", "vl", "st", "str"};
    static constexpr std::string_view names3[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ia", "ie", "io", "ai", "ea", "ei", "eo"};
    static constexpr std::string_view names4[] = {"b", "d", "f", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "t", "w", "x", "y", "ld", "lf", "lk", "lm", "ln", "lp", "ls", "lt", "ck", "cs", "ct", "ft", "mn", "ms", "ng", "ns", "ps", "rd", "rg", "rk", "rs", "rt", "sk", "ss", "ll", "st", "sh"};
    static constexpr std::string_view names5[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ia", "ie", "io", "ai", "ea", "ei", "eo"};
    static constexpr std::string_view names6[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "bb", "cc", "dd", "ff", "gg", "kk", "ll", "mm", "nn", "pp", "rr", "ss", "tt", "zz", "br", "cr", "gr", "pr", "tr", "ch", "bl", "cl", "fl", "gl", "kl", "pl", "sl", "vl", "st", "str"};
    static constexpr std::string_view names7[] = {"a", "e", "i", "o", "u", "ia", "io", "ea", "ei", "eo"};
    static constexpr std::string_view names8[] = {" Accordion", " Bass", " Bow", " Clarinet", " Drum", " Drums", " Flute", " Guitar", " Harmonica", " Horn", " Organ", " Pipe", " Saxophone", " Trombone", " Trumpet", " Tuba", " Violin", " Whistle", "horn", "phone", "pipe", "horn", "phone", "phone", "phone", "phone", "pipe"};
    static constexpr std::string_view names9[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ia", "io", "ai", "ea", "eo", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (i < 3) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    rnd4 = rng() % std::size(names4);
    rnd5 = rng() % std::size(names5);
    names = names1[rnd] + names2[rnd2] + names3[rnd3] + names4[rnd4] + names5[rnd5];
    } else if (i < 6) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    rnd4 = rng() % std::size(names4);
    names = names1[rnd] + names2[rnd2] + names3[rnd3] + names4[rnd4];
    } else if (i < 8) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    rnd4 = rng() % std::size(names4);
    rnd5 = rng() % std::size(names9);
    rnd6 = rng() % std::size(names8);
    names = names1[rnd] + names2[rnd2] + names3[rnd3] + names4[rnd4] + names9[rnd5] + names8[rnd6];
    } else if (i == 8) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    rnd4 = rng() % std::size(names4);
    rnd5 = rng() % std::size(names5);
    rnd6 = rng() % std::size(names6);
    rnd7 = rng() % std::size(names7);
    names = names1[rnd] + names2[rnd2] + names3[rnd3] + names4[rnd4] + names5[rnd5] + names6[rnd6] + names7[rnd7];
    } else {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    rnd4 = rng() % std::size(names4);
    rnd5 = rng() % std::size(names5);
    rnd6 = rng() % std::size(names4);
    names = names1[rnd] + names2[rnd2] + names3[rnd3] + names4[rnd4] + names5[rnd5] + names4[rnd6];
    }
    return names;
    }
}
