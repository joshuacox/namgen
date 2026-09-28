#include "dungeon_and_dragons-half_elfs_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_dungeon_and_dragons_half_elfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Al", "Aro", "Bar", "Bel", "Cor", "Cra", "Dav", "Dor", "Eir", "El", "Fal", "Fril", "Gaer", "Gra", "Hal", "Hor", "Ian", "Ilo", "Jam", "Kev", "Kri", "Leo", "Lor", "Mar", "Mei", "Nil", "Nor", "Ori", "Os", "Pan", "Pet", "Quo", "Raf", "Ri", "Sar", "Syl", "Tra", "Tyr", "Uan", "Ul", "Van", "Vic", "Wal", "Wil", "Xan", "Xav", "Yen", "Yor", "Zan", "Zyl"};
    static constexpr std::string_view nm2[] = {"avor", "ben", "borin", "coril", "craes", "deyr", "dithas", "elor", "enas", "faelor", "faerd", "finas", "fyr", "gotin", "gretor", "homin", "horn", "kas", "koris", "lamir", "lanann", "lumin", "minar", "morn", "nan", "neak", "neiros", "orin", "ovar", "parin", "phanis", "qarim", "qinor", "reak", "ril", "ros", "sariph", "staer", "torin", "tumil", "valor", "voril", "warith", "word", "xian", "xiron", "yeras", "ynor", "zaphir", "zaren"};
    static constexpr std::string_view nm3[] = {"Alu", "Aly", "Ar", "Bren", "Byn", "Car", "Co", "Dar", "Del", "El", "Eli", "Fae", "Fha", "Gal", "Gif", "Haly", "Ho", "Ile", "Iro", "Jen", "Jil", "Kri", "Kys", "Les", "Lora", "Ma", "Mar", "Mare", "Neri", "Nor", "Ol", "Ophi", "Phaye", "Pri", "Qi", "Que", "Rel", "Res", "Sael", "Saf", "Syl", "Ther", "Tyl", "Una", "Uri", "Ven", "Vyl", "Win", "Wol", "Xil", "Xyr", "Yes", "Yll", "Zel", "Zin"};
    static constexpr std::string_view nm4[] = {"aerys", "anys", "bellis", "bwynn", "cerys", "charis", "diane", "dove", "elor", "enyphe", "faen", "fine", "galyn", "gwynn", "hana", "hophe", "kaen", "kilia", "lahne", "lynn", "mae", "malis", "mythe", "nalore", "noa", "nys", "ona", "phira", "pisys", "qarin", "qwyn", "rila", "rora", "seris", "stine", "sys", "thana", "theris", "tihne", "trana", "viel", "vyre", "walyn", "waris", "xaris", "xipha", "yaries", "yra", "zenya", "zira"};

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
