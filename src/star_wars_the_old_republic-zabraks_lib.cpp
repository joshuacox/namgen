#include "star_wars_the_old_republic-zabraks_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_the_old_republic_zabraks_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"A", "O", "E", "U", "B", "Br", "Bl", "D", "Dr", "G", "Gr", "H", "K", "Kr", "Kl", "M", "N", "P", "Q", "R", "S", "St", "T", "V", "Vr", "X"};
    static constexpr std::string_view nm2[] = {"a", "o", "u", "e"};
    static constexpr std::string_view nm3[] = {"ra", "ro", "ru", "rga", "rgo", "rgu", "rge", "ba", "bo", "bu", "bra", "bru", "bro", "da", "do", "du", "dra", "dru", "dro", "ga", "go", "gu", "gro", "gra", "gru", "ka", "ko", "ku", "ke", "kra", "kro", "kru", "ma", "mo", "mu", "na", "no", "nu", "pa", "po", "pu", "pra", "pro", "pru", "qa", "qo", "qu", "sa", "so", "su", "sra", "sro", "sru", "sta", "sto", "stu", "ta", "to", "tu", "tra", "tro", "tru", "va", "vo", "vu", "vra", "vro", "vru", "xa", "xo", "xu"};
    static constexpr std::string_view nm4[] = {"d", "g", "k", "m", "n", "p", "r", "s", "t", "x", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm5[] = {"a", "o", "u", "e", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm6[] = {"A", "O", "E", "B", "Bl", "D", "G", "H", "K", "Kl", "L", "M", "N", "P", "Q", "R", "S", "St", "T", "V", "Vr", "X", "W"};
    static constexpr std::string_view nm7[] = {"ba", "be", "bi", "bo", "bra", "bre", "bri", "bro", "da", "de", "di", "do", "dra", "dre", "dri", "dro", "ga", "ge", "gi", "go", "gra", "gre", "gri", "gro", "ka", "ke", "ki", "ko", "kra", "kre", "kri", "kro", "ma", "me", "mi", "mo", "na", "ne", "ni", "no", "pa", "pe", "pi", "po", "pra", "pre", "pri", "pro", "qa", "qe", "qi", "qo", "ra", "re", "rga", "rge", "rgi", "rgo", "ri", "ro", "sa", "se", "si", "so", "sra", "sre", "sri", "sro", "sta", "ste", "sti", "sto", "ta", "te", "ti", "to", "tra", "tre", "tri", "tro", "va", "ve", "vi", "vo", "vra", "vre", "vri", "vro", "xa", "xe", "xi", "xo"};
    static constexpr std::string_view nm8[] = {"a", "o", "u", "e", "i", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm4);
    if (type == 1) {
    rnd = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd5 = rng() % std::size(nm8);
    names = nm6[rnd] + nm2[rnd2] + nm7[rnd3] + nm4[rnd4] + nm8[rnd5];
    } else {
    rnd = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5];
    }
    return names;
    }
}
