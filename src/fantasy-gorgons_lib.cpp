#include "fantasy-gorgons_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_gorgons_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"ch", "chr", "d", "h", "k", "m", "n", "ph", "r", "sth", "th", "x", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "eia", "ei", "eu", "ae", "ya", "ai", "ia"};
    static constexpr std::string_view nm3[] = {"d", "l", "m", "n", "r", "s", "x", "v", "z", "d", "l", "m", "n", "r", "s", "x", "v", "z", "d", "l", "m", "n", "r", "s", "x", "v", "z", "dn", "dr", "gg", "gn", "kt", "lc", "ld", "mbr", "nc", "ndr", "nt", "nth", "rd", "rl", "rr", "sc", "sd", "sn", "sp", "st", "str", "th", "tt"};
    static constexpr std::string_view nm4[] = {"a", "e", "o", "a", "e", "o", "a", "e", "o", "ea", "ia", "y"};
    static constexpr std::string_view nm5[] = {"aemon", "aenon", "aeon", "aestus", "aeus", "agos", "aios", "anes", "anos", "antos", "aon", "arus", "as", "ates", "atos", "aumas", "eas", "eidon", "er", "erion", "erus", "es", "etheus", "etus", "eus", "ias", "ibos", "ion", "ios", "is", "iton", "ius", "o", "oeis", "oeus", "olus", "on", "onos", "or", "os", "oteus", "otos", "otus", "ous", "us", "yrus", "ys", "ytion"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4];
    } else {
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm2);
    if (rnd3 > 26) {
    while (rnd5 > 26) {
    rnd5 = rng() % std::size(nm3);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd6] + nm3[rnd5] + nm4[rnd4];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm5[rnd4];
    }
    return names;
    }
}
