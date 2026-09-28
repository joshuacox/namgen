#include "elder_scrolls-falmers_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_elder_scrolls_falmers_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names3[] = {"An", "Ag", "Agar", "Bin", "Berel", "Cryn", "Caer", "Den", "Dane", "Ere", "Eme", "Fin", "For", "Gran", "Gan", "Hene", "Har", "Irel", "Ise", "Kran", "Kor", "Lene", "Lore", "Mas", "Mine", "Nor", "Nara", "Or", "Ore", "Pan", "Pris", "Ran", "Rone", "Shan", "Sin", "Tor", "Tin", "Ure", "Unar", "Vran", "Vor", "Wan", "Was", "Yre", "Yren", "Zon", "Zar"};
    static constexpr std::string_view names4[] = {"bath", "borin", "dwen", "dras", "faroth", "ferys", "garwen", "goth", "horith", "han", "krath", "kelor", "len", "loth", "meloth", "myn", "naris", "noth", "paris", "parwen", "rawyn", "renoth", "saroth", "saris", "taroth", "tan", "vryn", "varys", "wenoth", "wen", "yloth", "yrwen", "zras", "zoth"};
    static constexpr std::string_view names1_1[] = {"Ari", "Aith", "Bel", "Bire", "Cele", "Cen", "El", "Elle", "En", "Fae", "Fai", "Gis", "Gwen", "Haer", "Hele", "Inhe", "Ime", "Je", "Jes", "Kir", "Kine", "Les", "Lyn", "Mel", "Min", "Nira", "Nythe", "Pes", "Prys", "Rine", "Ryn", "Shi", "Sina", "Tera", "Ter", "Unhel", "Uve", "Ven", "Vyr", "Wae", "Wina", "Ynhe", "Ys", "Zhar", "Zida"};
    static constexpr std::string_view names2_1[] = {"bora", "bysh", "dhora", "denyse", "fani", "feah", "geth", "greah", "her", "hish", "kharise", "kyre", "lenor", "lori", "mhes", "meril", "neris", "nyish", "pireth", "path", "rae", "rish", "reno", "ren", "shan", "selin", "thune", "tys", "vhis", "vena", "wihn", "wen", "yane", "yis", "zhina", "zis"};
    static constexpr std::string_view names1_2[] = {"Are", "Ath", "Bal", "Bir", "Cele", "Cen", "Ed", "Edhel", "En", "Fa", "Fai", "Gir", "Glen", "Har", "Here", "Idhe", "Ire", "Ja", "Jed", "Kar", "Kida", "Lat", "Lyr", "Men", "Mir", "Niri", "Nyr", "Pare", "Pryn", "Red", "Ryn", "Si", "Sida", "Tere", "Tor", "Udhel", "Ure", "Var", "Vyr", "Wai", "Wiri", "Ydhe", "Yr", "Zar", "Zida"};
    static constexpr std::string_view names2_2[] = {"bor", "bys", "dhor", "danyis", "faris", "fiath", "groth", "griath", "hur", "his", "karis", "kir", "lebor", "lor", "mhor", "mitil", "naris", "nyis", "prith", "piroth", "re", "riath", "rilor", "ring", "sur", "sebir", "thur", "til", "vhur", "vus", "with", "we", "yaris", "yor", "zhor", "zius"};

    ArrayView names1; ArrayView names2; std::string names; size_t rnd0 = 0; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

    if (type == 1) {
    names1 = make_view(names1_1);
    names2 = make_view(names2_1);
    } else {
    names1 = make_view(names1_2);
    names2 = make_view(names2_2);
    }
i = rng() % 10; {
    rnd0 = rng() % std::size(names1);
    rnd1 = rng() % std::size(names2);
    rnd2 = rng() % std::size(names3);
    rnd3 = rng() % std::size(names4);
    names = names1[rnd0] + names2[rnd1] + " " + names3[rnd2] + names4[rnd3];
    return names;
    }
}
