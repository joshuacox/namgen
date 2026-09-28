#include "harry_potter-winged_horses_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_harry_potter_winged_horses_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"a", "ae", "ea", "i", "o", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"ba", "bli", "blo", "bra", "bri", "cae", "ci", "cra", "cro", "da", "do", "dra", "dro", "fae", "fo", "fra", "fre", "glo", "gra", "gre", "gri", "la", "lea", "lia", "lo", "ma", "mae", "me", "mea", "nae", "nea", "nei", "ni", "phae", "phri", "pio", "po", "pri", "ra", "rae", "rea", "ro", "she", "sho", "sli", "sna", "tae", "the", "tho", "tri"};
    static constexpr std::string_view nm3[] = {"ban", "bian", "bral", "can", "cian", "ddan", "dial", "dian", "din", "hal", "han", "hian", "lan", "lian", "lin", "llan", "man", "mian", "min", "mman", "nan", "nial", "nian", "nnal", "nnan", "phal", "phian", "phion", "ppan", "ral", "ran", "rian", "rin", "rran", "sal", "san", "sin", "ssin", "stral", "tan", "thian", "tian", "tin", "tral", "xal", "xan", "xian", "xxin"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3];
    return names;
    }
}
