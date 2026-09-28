#include "dungeon_and_dragons-gnomes_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_dungeon_and_dragons_gnomes_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Al", "Ari", "Bil", "Bri", "Cal", "Cor", "Dav", "Dor", "Eni", "Er", "Far", "Fel", "Ga", "Gra", "His", "Hor", "Ian", "Ipa", "Je", "Jor", "Kas", "Kel", "Lan", "Lo", "Man", "Mer", "Nes", "Ni", "Or", "Oru", "Pana", "Po", "Qua", "Quo", "Ras", "Ron", "Sa", "Sal", "Sin", "Tan", "To", "Tra", "Um", "Uri", "Val", "Vor", "War", "Wil", "Wre", "Xal", "Xo", "Ye", "Yos", "Zan", "Zil"};
    static constexpr std::string_view nm2[] = {"bar", "ben", "bis", "corin", "cryn", "don", "dri", "fan", "fiz", "gim", "grim", "hik", "him", "ji", "jin", "kas", "kur", "len", "lin", "min", "mop", "morn", "nan", "ner", "ni", "pip", "pos", "rick", "ros", "rug", "ryn", "ser", "ston", "tix", "tor", "ver", "vyn", "win", "wor", "xif", "xim", "ybar", "yur", "ziver", "zu"};
    static constexpr std::string_view nm3[] = {"Alu", "Ari", "Ban", "Bree", "Car", "Cel", "Daphi", "Do", "Eili", "El", "Fae", "Fen", "Fol", "Gal", "Gren", "Hel", "Hes", "Ina", "Iso", "Jel", "Jo", "Klo", "Kri", "Lil", "Lori", "Min", "My", "Ni", "Ny", "Oda", "Or", "Phi", "Pri", "Qi", "Que", "Re", "Rosi", "Sa", "Sel", "Spi", "Ta", "Tifa", "Tri", "Ufe", "Uri", "Ven", "Vo", "Wel", "Wro", "Xa", "Xyro", "Ylo", "Yo", "Zani", "Zin"};
    static constexpr std::string_view nm4[] = {"bi", "bys", "celi", "ci", "dira", "dysa", "fi", "fyx", "gani", "gyra", "hana", "hani", "kasys", "kini", "la", "li", "lin", "lys", "mila", "miphi", "myn", "myra", "na", "niana", "noa", "nove", "phina", "pine", "qaryn", "qys", "rhana", "roe", "sany", "ssa", "sys", "tina", "tra", "wyn", "wyse", "xi", "xis", "yaris", "yore", "za", "zyre"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    names = std::string(nm3[rnd]) + std::string(nm4[rnd2]);
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]);
    }
    return names;
    }
}
