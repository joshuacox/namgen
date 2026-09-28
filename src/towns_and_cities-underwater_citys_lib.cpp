#include "towns_and_cities-underwater_citys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_towns_and_cities_underwater_citys_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Aby", "Abys", "Ache", "Acio", "Aeg", "Amphi", "Anu", "Aqu", "Aqua", "Aqui", "Asha", "Ashe", "Atla", "Azha", "Azu", "Beli", "Bery", "Boy", "Bri", "Cae", "Caenu", "Cala", "Cata", "Cla", "Coa", "Coara", "Cora", "Delph", "Do", "Ebi", "Expa", "Flu", "Gey", "Gla", "Glaci", "Hippo", "Hy", "Hyd", "Jutu", "Levi", "Levia", "Limu", "Liqi", "Liqu", "Liqua", "Liqui", "Litto", "Mari", "Mer", "Mimi", "Nata", "Nau", "Nauti", "Nava", "Nep", "Neph", "Nept", "Neptu", "Nerei", "Neri", "Njo", "Njor", "Oce", "Ocea", "Osi", "Paci", "Palae", "Pela", "Pose", "Posei", "Pura", "Puri", "Rive", "Sala", "Sali", "Saph", "Saphi", "Scy", "Sequa", "Si", "Sire", "Squa", "Te", "Tempe", "Teth", "Tha", "Thala", "Thau", "The", "Tri", "Trite", "Trito", "Tsu", "Tsuna", "Ty", "Typh", "Va", "Vapo", "Voltu", "Wata"};
    static constexpr std::string_view nm2[] = {"cada", "cadis", "cia", "cique", "cis", "dor", "dore", "gia", "lean", "lin", "lina", "lis", "loch", "lona", "lor", "lora", "lore", "lune", "mari", "mon", "mond", "na", "nas", "ne", "nea", "nia", "nis", "noch", "pis", "ra", "rai", "ran", "rei", "rem", "ren", "reth", "rey", "ri", "ria", "ril", "rin", "ris", "rius", "rus", "sa", "tas", "tesh", "thas", "theas", "this", "thys", "tia", "tin", "tis", "ton", "tria", "via"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2];
    return names;
    }
}
