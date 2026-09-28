#include "dungeon_and_dragons-minotaurs_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_dungeon_and_dragons_minotaurs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view namesFemF[] = {"Aam", "Ane", "Are", "Ase", "Duu", "Em", "Enti", "Este", "Fen", "Hene", "Hes", "Hila", "Hine", "Ias", "Ire", "Ki", "Kia", "Kuo", "Laan", "Line", "Loo", "Muu", "Nan", "Nea", "Neo", "Noo", "Nuo", "Oen", "Oes", "Raas", "Ras", "Sees", "Seo", "Sina", "Tee", "Tes", "Tia", "Tina", "Uova", "Weo"};
    static constexpr std::string_view namesFemL[] = {"dra", "fin", "kane", "kea", "la", "las", "len", "lin", "lo", "mas", "me", "mi", "min", "na", "nan", "nas", "nim", "nu", "pen", "pe", "ra", "ren", "res", "rin", "ris", "ru", "sen", "sia", "ta", "ter", "tin", "tra", "tred", "tri", "trin", "tris", "ven", "vena", "vera", "vin"};
    static constexpr std::string_view namesMaleF[] = {"Ar", "Are", "Aste", "Bjor", "Car", "Cod", "Da", "Djar", "Djun", "Doen", "Dor", "Dur", "Foos", "Gar", "Goe", "Gra", "Gran", "Gun", "Hun", "Ja", "Jar", "Kar", "Kin", "Kir", "Koo", "Koor", "Krum", "Kur", "Man", "Min", "Mir", "Noo", "Pod", "Rak", "Te", "Toon", "Trak", "Tur", "Zam", "Zun"};
    static constexpr std::string_view namesMaleL[] = {"ban", "baran", "bur", "dak", "daran", "dor", "fajar", "faruk", "furan", "gajan", "garak", "gur", "jar", "kan", "kar", "karat", "kun", "kurat", "kus", "manuk", "maruk", "nark", "narun", "paran", "raduk", "rak", "rakar", "ranak", "rapak", "ras", "rat", "rios", "ron", "rus", "rut", "tagar", "taruk", "toron", "turok", "tus"};
    static constexpr std::string_view namesSur[] = {"Agilebody", "Agilemind", "Bearfighter", "Boldmind", "Boldwarrior", "Boulderfist", "Boulderhide", "Braveheart", "Brightheart", "Brightmind", "Fearlessheart", "Fistfury", "Gloryhunter", "Gloryslash", "Goblinbane", "Goblinslayer", "Greathunter", "Heavyhide", "Honorheart", "Ironheart", "Ironhorn", "Ironskin", "Ironskull", "Jaggedhorns", "Keeneye", "Nimblestep", "Orcbane", "Orcslayer", "Rockhorn", "Ruggedhide", "Sharpmind", "Silentstriker", "Silentwalker", "Singlehorn", "Steadyhand", "Steelhide", "Steelhorn", "Steelskin", "Steelskull", "Stonehide", "Stormhoof", "Stormroar", "Stoutheart", "Strongleader", "Strongroar", "Swiftrunner", "Swiftstriker", "Swiftwalker", "Thickhide", "Thickskin", "Thunderfist", "Thunderhoof", "Thunderroar", "Toughpelt", "Truthspeaker", "Valiantheart", "Vigileye", "Wolfheart", "Wolfrunner", "Wolfvigor"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(namesFemF);
    rnd2 = rng() % std::size(namesFemL);
    rnd3 = rng() % std::size(namesSur);
    names = std::string(namesFemF[rnd]) + std::string(namesFemL[rnd2]) + " " + std::string(namesSur[rnd3]);
    } else {
    rnd = rng() % std::size(namesMaleF);
    rnd2 = rng() % std::size(namesMaleL);
    rnd3 = rng() % std::size(namesSur);
    names = std::string(namesMaleF[rnd]) + std::string(namesMaleL[rnd2]) + " " + std::string(namesSur[rnd3]);
    }
    return names;
    }
}
