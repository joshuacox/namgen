#include "warhammer_40k-sisters_of_battles_lib.h"

static const std::vector<std::string> nm1 = {
    "Agn", "Al", "Alic", "Am", "An", "Ar", "Arab", "Asp", "Bell", "Bren",
    "Brig", "Bris", "Cel", "Celest", "Chr", "Chris", "Chrism", "Dec",
    "Diss", "Dor", "Dyl", "Ell", "Ephr", "Ess", "Est", "Gal", "Gell",
    "Gin", "Gwyn", "Hann", "Hel", "Hen", "Hild", "Imm", "Immac", "Ion",
    "Ish", "Jen", "Jess", "Josm", "Jul", "Kat", "Kath", "Kess", "Kyl",
    "Let", "Leth", "Luc", "Lyn", "Mesh", "Min", "Mir", "Mor", "Og",
    "Ol", "Oliv", "Osh", "Pal", "Palm", "Phan", "Prax", "Res", "Rhian",
    "Rhiann", "Rienn", "Sab", "Sabr", "Sar", "Sel", "Seph", "Silv",
    "Syl", "Venn", "Ver", "Viss", "Vyl"
};

static const std::vector<std::string> nm2 = {
    "a", "ael", "ais", "ana", "ane", "anon", "ata", "atea", "arya", "ahla",
    "e", "ea", "edes", "ella", "ena", "enta", "erina", "erine", "es",
    "enya", "i", "ia", "iael", "iah", "icia", "ien", "ima", "ina", "ine",
    "ira", "iro", "isma", "itta", "ity", "iya", "on", "one", "osha", "oya",
    "olis", "oia", "onya", "olla", "o", "oris", "ora", "ulata", "uya",
    "une", "uah", "una"
};

std::string generate_warhammer_40k_sisters_of_battles_name(std::mt19937& rng) {
    std::uniform_int_distribution<std::size_t> dist1(0, nm1.size() - 1);
    std::uniform_int_distribution<std::size_t> dist2(0, nm2.size() - 1);
    return nm1[dist1(rng)] + nm2[dist2(rng)];
}
