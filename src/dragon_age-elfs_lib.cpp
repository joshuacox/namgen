#include "dragon_age-elfs_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_dragon_age_elfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view namesFemale[] = {"Ada", "Ari", "Aria", "Asha", "Ashi", "Athe", "Bri", "Bria", "Dany", "De", "Deve", "Di", "Elo", "Fi", "Fio", "Ghe", "Io", "Ise", "Ka", "La", "Lana", "Li", "Lia", "Ma", "Mare", "Me", "Melo", "Merri", "Mi", "Mih", "Na", "Nama", "Ne", "Nesi", "Nesia", "No", "Nola", "Ora", "Orana", "Pa", "Pano", "Ri", "Se", "Sera", "Sha", "Shae", "Shi", "Shia", "Va", "Valo", "Valy", "Vari", "Ve", "Vela"};
    static constexpr std::string_view namesFemale2[] = {"hari", "hra", "hris", "la", "lanna", "ll", "lle", "lora", "lva", "lwyn", "lya", "maya", "na", "naya", "ne", "ni", "nna", "nne", "nni", "nowen", "nril", "nyla", "ra", "rana", "ranni", "ren", "ri", "riel", "ril", "rill", "ris", "rrill", "sa", "siara", "ssa", "thari", "thra", "triel", "va", "vera", "vra", "wen", "wyn", "ya"};
    static constexpr std::string_view namesMale[] = {"Ad", "Al", "Ala", "Ar", "At", "Ath", "Bra", "Ca", "Cam", "Car", "Cy", "Cyr", "Dey", "El", "Fe", "Fel", "Fen", "Fey", "Feyn", "Ga", "Gar", "Ge", "Get", "Geth", "Ha", "Har", "Hu", "Il", "Ja", "Jos", "Jun", "Le", "Lem", "Ne", "Nel", "Pa", "Pai", "Pi", "Sa", "Sam", "Sar", "Se", "Sen", "So", "Sor", "Ta", "Tae", "Tam", "The", "Thel", "Thre", "Va", "Var", "Vara", "Ye", "Yev", "Zat", "Zath", "Zev"};
    static constexpr std::string_view namesFamily[] = {"cen", "dis", "dor", "gan", "hel", "hon", "horn", "lan", "laros", "lasan", "lassan", "len", "lhen", "mael", "men", "met", "nar", "narel", "rahel", "ralan", "ran", "rand", "ras", "rel", "ren", "rian", "riel", "rion", "ris", "rith", "ron", "ros", "sas", "thon", "thorn", "vel", "ven", "vin", "wen"};

    std::string names; size_t rnd0 = 0; size_t rnd1 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd0 = rng() % std::size(namesFemale);
    rnd1 = rng() % std::size(namesFemale2);
    names = std::string(namesFemale[rnd0]) + std::string(namesFemale2[rnd1]);
    } else {
    rnd0 = rng() % std::size(namesMale);
    rnd1 = rng() % std::size(namesFamily);
    names = std::string(namesMale[rnd0]) + std::string(namesFamily[rnd1]);
    }
    return names;
    }
}
