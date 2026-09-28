#include "mass_effect-krogans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_mass_effect_krogans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names1[] = {"B", "Br", "C", "Cr", "Ch", "D", "Dr", "F", "G", "Gr", "H", "J", "K", "Kh", "Kr", "M", "N", "P", "Pr", "Q", "Qr", "R", "S", "Sr", "Str", "T", "Tr", "V", "Vr", "W", "Wr", "Zr"};
    static constexpr std::string_view names2[] = {"a", "e", "u", "i", "o", "a", "u"};
    static constexpr std::string_view names3[] = {"rr", "x", "nd", "nk", "yas", "rm", "rn", "rk", "tack", "rg", "g", "gg", "sk", "zk", "nd", "d", "rd", "xx", "yak", "yax", "rak", "nak", "kar", "kor", "lak", "gor", "gar", "gas", "r"};
    static constexpr std::string_view names5[] = {"ash", "bakur", "brakir", "dark", "drak", "drax", "dtar", "k", "kador", "karor", "kirum", "kmar", "kmor", "krax", "ksan", "ksar", "kson", "ksor", "l", "lot", "mar", "nar", "ndok", "ntor", "rax", "rbok", "rbon", "rdak", "rdan", "rdok", "rdon", "rgal", "rgon", "rkan", "rloc", "rlok", "rsan", "rtak", "tarog", "tarok", "tarum", "tarun", "tatog", "tilak", "vanor", "varog", "vrak", "x", "yrdok", "yrloc"};
    static constexpr std::string_view names4_1[] = {""};
    static constexpr std::string_view names4_2[] = {"a", "e", "u", "i", "o", "a"};

    ArrayView names4; std::string names; size_t rnd0 = 0; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

    if (type == 1) {
    names4 = make_view(names4_1);
    } else {
    names4 = make_view(names4_2);
    }
i = rng() % 10; {
    rnd0 = rng() % std::size(names1);
    rnd1 = rng() % std::size(names2);
    rnd2 = rng() % std::size(names3);
    rnd3 = rng() % std::size(names4);
    rnd4 = rng() % std::size(names1);
    rnd5 = rng() % std::size(names2);
    rnd6 = rng() % std::size(names5);
    names = names1[rnd4] + names2[rnd5] + names5[rnd6] + " " + names1[rnd0] + names2[rnd1] + names3[rnd2] + names4[rnd3];
    return names;
    }
}
