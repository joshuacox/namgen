#include "towns_and_cities-egyptian_towns_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_towns_and_cities_egyptian_towns_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Ab", "Ac", "Ak", "Akh", "Am", "An", "Ap", "Ash", "Av", "Be", "Beh", "Behd", "Bes", "Cly", "Clys", "Cu", "Cus", "De", "Deh", "Des", "Dja", "Djan", "Dje", "Djed", "Eb", "Ed", "Ek", "Em", "En", "Fa", "Far", "Ge", "Ges", "He", "Heb", "Ke", "Ker", "Kha", "Khas", "Khe", "Khem", "Ki", "Kis", "Ku", "Kus", "Me", "Med", "Men", "Na", "Nap", "Ne", "Neb", "Nek", "Nekh", "Nem", "Qi", "Qis", "Qu", "Qul", "Sa", "Sak", "Se", "Sep", "Set", "Sha", "Shar", "She", "Shet", "Ta", "Tap", "Tar", "Tje", "Tjeb", "Tjen", "Wa", "Was", "Za"};
    static constexpr std::string_view names2[] = {"be", "bu", "by", "ca", "de", "dje", "dju", "fu", "kha", "khe", "ma", "me", "mu", "ne", "nei", "no", "nou", "nu", "pe", "pi", "po", "re", "ri", "ru", "sa", "sai", "se", "si", "so", "sou", "su", "sy", "ta", "te", "tu", "va", "zu"};
    static constexpr std::string_view names3[] = {"benu", "besheh", "bu", "det", "djed", "dju", "dos", "fu", "hdet", "henet", "kha", "khen", "lzum", "m", "ma", "mar", "meru", "mhat", "mty", "mu", "munein", "n", "na", "nein", "nemhat", "net", "nis", "nu", "nutjer", "pata", "pet", "pis", "remu", "ris", "rma", "rmeru", "rna", "ru", "run", "runa", "s", "sa", "sai", "set", "sheh", "sir", "siris", "sma", "souk", "sut", "sy", "ta", "taten", "ten", "tennu", "this", "thus", "tjer", "tunis", "ty", "yut", "zum", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    names = names1[rnd] + names2[rnd2] + names3[rnd3];
    return names;
    }
}
