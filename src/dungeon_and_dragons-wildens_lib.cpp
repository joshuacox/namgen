#include "dungeon_and_dragons-wildens_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_dungeon_and_dragons_wildens_name(std::mt19937& rng, int type) {
    static constexpr std::string_view namesMaleFf[] = {"Ban", "Bar", "Dal", "Dam", "Dun", "Dur", "Fas", "Fin", "Kan", "Kin", "Kor", "Lan", "Lim", "Lon", "Man", "Mar", "Mas", "Mid", "Mor", "Mur", "Nam", "Nor", "Rad", "Ran", "Ras", "Rod", "San", "Sin", "Tor", "Tum"};
    static constexpr std::string_view namesMaleFl[] = {"darras", "darris", "dommar", "donnir", "durrun", "farran", "fidden", "garron", "kammin", "karran", "lammir", "larrin", "mannor", "marden", "mennar", "mennor", "mindin", "mirron", "morrin", "murrin", "norren", "norten", "rammas", "sammas", "sannim", "sarrin", "sarris", "sorran", "tarrin", "torrin"};
    static constexpr std::string_view namesMaleSf[] = {"Barrun", "Burrin", "Darras", "Farran", "Farrin", "Fidden", "Garrin", "Harren", "Harrun", "Karrat", "Karren", "Ketten", "Korrin", "Larras", "Lommir", "Lorrin", "Marrad", "Mirren", "Mirrun", "Morrin", "Parran", "Purren", "Tarris", "Torren", "Torrim", "Turrus", "Venner", "Vunnar", "Zakkan", "Zarrak"};
    static constexpr std::string_view namesMaleSl[] = {"bar", "bor", "bun", "das", "din", "dun", "dur", "fas", "fum", "gar", "gun", "kas", "kin", "las", "lis", "mar", "mas", "min", "mur", "nas", "nim", "nor", "pan", "rak", "ras", "tor", "tur", "zad", "zim", "zor"};
    static constexpr std::string_view namesFemF[] = {"Allin", "Ashin", "Bunn", "Dann", "Darn", "Diss", "Enn", "Eril", "Fenn", "Fert", "Firr", "Fiss", "Genn", "Grin", "Kalk", "Kenn", "Kers", "Krin", "Lerm", "Less", "Linn", "Lorr", "Minn", "Mirt", "Mist", "Nem", "Niss", "Shall", "Shan", "Shenn", "Tarr", "Taz", "Tell", "Tin", "Tirr", "Tris", "Wenn", "Zar", "Zaz", "Zell"};
    static constexpr std::string_view namesFemL[] = {"ahai", "akei", "alin", "amai", "anai", "annar", "annas", "arris", "arrel", "arresh", "artish", "asha", "atish", "elbis", "embin", "enna", "ennash", "entah", "eris", "erla", "erlis", "imai", "imbel", "imei", "immesh", "inah", "inash", "inda", "inna", "innem", "irrah", "ishai", "issa", "itas", "onnes", "onteh", "orda", "oren", "oris", "orren"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(namesFemF);
    rnd2 = rng() % std::size(namesFemL);
    names = std::string(namesFemF[rnd]) + std::string(namesFemL[rnd2]);
    } else {
    if (i < 5) {
    rnd = rng() % std::size(namesMaleFf);
    rnd2 = rng() % std::size(namesMaleFl);
    names = std::string(namesMaleFf[rnd]) + std::string(namesMaleFl[rnd2]);
    } else {
    rnd = rng() % std::size(namesMaleSf);
    rnd2 = rng() % std::size(namesMaleSl);
    names = std::string(namesMaleSf[rnd]) + std::string(namesMaleSl[rnd2]);
    }
    }
    return names;
    }
}
