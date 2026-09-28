#include "dungeon_and_dragons-halflings_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_dungeon_and_dragons_halflings_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"An", "Ar", "Bar", "Bel", "Con", "Cor", "Dan", "Dav", "El", "Er", "Fal", "Fin", "Flyn", "Gar", "Go", "Hal", "Hor", "Ido", "Ira", "Jan", "Jo", "Kas", "Kor", "La", "Lin", "Mar", "Mer", "Ne", "Nor", "Ori", "Os", "Pan", "Per", "Pim", "Quin", "Quo", "Ri", "Ric", "San", "Shar", "Tar", "Te", "Ul", "Uri", "Val", "Vin", "Wen", "Wil", "Xan", "Xo", "Yar", "Yen", "Zal", "Zen"};
    static constexpr std::string_view nm2[] = {"ace", "amin", "bin", "bul", "dak", "dal", "der", "don", "emin", "eon", "fer", "fire", "gin", "hace", "horn", "kas", "kin", "lan", "los", "min", "mo", "nad", "nan", "ner", "orin", "os", "pher", "pos", "ras", "ret", "ric", "rich", "rin", "ry", "ser", "sire", "ster", "ton", "tran", "umo", "ver", "vias", "von", "wan", "wrick", "yas", "yver", "zin", "zor", "zu"};
    static constexpr std::string_view nm3[] = {"An", "Ari", "Bel", "Bre", "Cal", "Chen", "Dar", "Dia", "Ei", "Eo", "Eli", "Era", "Fay", "Fen", "Fro", "Gel", "Gra", "Ha", "Hil", "Ida", "Isa", "Jay", "Jil", "Kel", "Kith", "Le", "Lid", "Mae", "Mal", "Mar", "Ne", "Ned", "Odi", "Ora", "Pae", "Pru", "Qi", "Qu", "Ri", "Ros", "Sa", "Shae", "Syl", "Tham", "Ther", "Tryn", "Una", "Uvi", "Va", "Ver", "Wel", "Wi", "Xan", "Xi", "Yes", "Yo", "Zef", "Zen"};
    static constexpr std::string_view nm4[] = {"alyn", "ara", "brix", "byn", "caryn", "cey", "da", "dove", "drey", "elle", "eni", "fice", "fira", "grace", "gwen", "haly", "jen", "kath", "kis", "leigh", "la", "lie", "lile", "lienne", "lyse", "mia", "mita", "ne", "na", "ni", "nys", "ola", "ora", "phina", "prys", "rana", "ree", "ri", "ris", "sica", "sira", "sys", "tina", "trix", "ula", "vira", "vyre", "wyn", "wyse", "yola", "yra", "zana", "zira"};

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
