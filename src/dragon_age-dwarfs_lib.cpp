#include "dragon_age-dwarfs_lib.h"

#include <vector>
#include <string>

static const std::vector<std::string> namesFemale = {
    "A", "Ba", "Bra", "Co", "Da", "Fa", "Fari", "Fe", "Feri", "Fi",
    "Ha", "Hana", "He", "Ja", "Je", "Ka", "Kala", "Ke", "Kela",
    "Le", "Li", "Ma", "Me", "Mi", "Mya", "Na", "Nara", "Nera",
    "Ole", "Oli", "Re", "Ri", "Se", "Si", "Ta", "Te", "Za", "Ze"
};

static const std::vector<std::string> namesFemale2 = {
    "ca", "cha", "da", "dal", "den", "dy", "gna", "grun", "ha", "han",
    "ja", "ka", "la", "lah", "li", "linda", "linden", "lsi", "na",
    "nda", "nden", "nka", "nna", "pith", "ra", "rav", "rdy", "rev",
    "rinda", "rinden", "rra", "rta", "run", "rvia", "ryn", "rynn",
    "scha", "shan", "si", "ta", "tha", "tyth", "via", "zda"
};

static const std::vector<std::string> namesMale = {
    "Ade", "Adema", "Ahre", "Ali", "An", "Ba", "Bai", "Bande", "Bar",
    "Be", "Bera", "Bere", "Bhe", "Bhele", "Bo", "Boda", "Boe", "Bro",
    "Bru", "Bu", "Czi", "Da", "Dai", "De", "Dene", "Dou", "Du",
    "Duli", "Dwo", "Dwy", "Emry", "En", "Endri", "Eve", "Fi",
    "Figo", "Fra", "Ga", "Gar", "Gari", "Garte", "Ge", "Ger",
    "Gera", "Gla", "Go", "Goi", "Gor", "Gori", "Gwi", "Hi",
    "Hir", "Hiro", "Hu", "Hugi", "Iwa", "Ja", "Jana", "Java",
    "Je", "Jer", "Ju", "Ka", "Kar", "Le", "Lo", "Loi", "Lu",
    "Luc", "Ma", "Mai", "Me", "Mer", "Meri", "Mi", "Min", "Na",
    "Nal", "Ne", "Nevi", "Og", "Ola", "Or", "Oski", "Pi",
    "Pio", "Py", "Pyr", "Pyra", "Re", "Ren", "Rha", "Ro",
    "Ru", "Sa", "San", "Se", "Sewe", "Te", "Tem", "Tha",
    "Thati", "Thau", "To", "Tri", "Tria", "Tu", "Va", "Var",
    "Ve", "Vel", "Vo", "Vol", "Wi", "Wo", "Wor", "Ye"
};

static const std::vector<std::string> namesFamily = {
    "bor", "dahn", "dal", "del", "delor", "derel", "dlin", "dol",
    "don", "drik", "drin", "g", "gal", "gan", "gar", "gek", "gin",
    "gor", "grand", "grin", "ka", "kas", "ke", "kel", "kias",
    "kin", "lan", "lanz", "len", "lid", "lin", "linar", "mar",
    "maro", "merin", "mor", "n", "nak", "nar", "nek", "niv",
    "nus", "raht", "ral", "ram", "rand", "rav", "rd", "rel",
    "ren", "ric", "rick", "rik", "rim", "rin", "ris", "rkel",
    "rkin", "rol", "ron", "rtag", "ryn", "rys", "sch", "seck",
    "shen", "so", "son", "tag", "tan", "tek", "thur", "thy",
    "tigan", "tin", "trak", "trand", "varis", "vez", "vhen",
    "vil", "vin", "wan", "wer", "weryn", "zyl"
};

static const std::vector<std::string> names3 = {
    "A", "Ae", "Al", "Ar", "Ara", "Be", "Ber", "Bra", "Bro", "Ca",
    "Cada", "Car", "Cari", "Da", "Do", "Du", "Dur", "E", "Eto",
    "Fe", "Fer", "Fera", "Fo", "For", "Fore", "Ga", "Gal", "Gar",
    "Ghe", "Gher", "Gla", "Go", "Gor", "Goro", "Ha", "Har",
    "He", "Hel", "Hi", "Hir", "I", "Ka", "Kana", "Kla", "Klar",
    "Ko", "Me", "Mei", "Mer", "O", "Or", "Ra", "Rae", "Ro",
    "Rou", "Ru", "Rumo", "Sa", "Sae", "Te", "Tho", "Ti", "To",
    "Tor", "Tu", "Tur", "U", "Ul", "Va", "Var", "Vo", "We",
    "Wey", "Yo", "Zy"
};

static const std::vector<std::string> names4 = {
    "ban", "ca", "can", "das", "dash", "den", "dens", "der", "dic",
    "din", "dra", "drat", "ducan", "ka", "lac", "lar", "lban",
    "lmas", "lmi", "lney", "lon", "lra", "lro", "mas", "mi",
    "mold", "mot", "mote", "munt", "nak", "narek", "ney", "nka",
    "no", "noch", "ntop", "ra", "ral", "rald", "ran", "rana",
    "ras", "rat", "rek", "ren", "ret", "ridin", "rin", "ro",
    "rol", "row", "sca", "sten", "tack", "tan", "ten", "top",
    "ver", "vis", "vish", "vo", "vonak", "vorn"
};

std::string generate_dragon_age_dwarfs_name(std::mt19937& rng) {
    // Decide gender: 0 = male, 1 = female
    std::uniform_int_distribution<int> genderDist(0, 1);
    bool female = genderDist(rng) == 1;

    std::uniform_int_distribution<std::size_t> idxFemale0(0, namesFemale.size() - 1);
    std::uniform_int_distribution<std::size_t> idxFemale1(0, namesFemale2.size() - 1);
    std::uniform_int_distribution<std::size_t> idxMale0(0, namesMale.size() - 1);
    std::uniform_int_distribution<std::size_t> idxFamily(0, namesFamily.size() - 1);
    std::uniform_int_distribution<std::size_t> idx3(0, names3.size() - 1);
    std::uniform_int_distribution<std::size_t> idx4(0, names4.size() - 1);

    std::string firstPart;
    if (female) {
        firstPart = namesFemale[idxFemale0(rng)] + namesFemale2[idxFemale1(rng)];
    } else {
        firstPart = namesMale[idxMale0(rng)] + namesFamily[idxFamily(rng)];
    }

    std::string secondPart = names3[idx3(rng)] + names4[idx4(rng)];

    return firstPart + " " + secondPart;
}
