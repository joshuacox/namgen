#include "star_trek-gorns_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_gorns_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Acu", "Are", "Aza", "Azsa", "Ba", "Besa", "Bra", "Bre", "Dasu", "Deza", "Di", "Dra", "Era", "Esee", "Essa", "Eza", "Fe", "Fee", "Fidi", "Fra", "Ga", "Garee", "Gli", "Graa", "He", "Hesa", "Hi", "Hra", "K'a", "K'sa", "K'staa", "Kee", "Ko", "Kra", "La", "Lazsa", "Lera", "Loze", "Masa", "Me", "Meka", "Mo", "Morsi", "Na", "Ne", "Neko", "Nha", "Re", "Reri", "Rla", "Roza", "S'a", "S'ka", "S'kaa", "S'la", "S'ree", "S'sa", "S'sha", "S'slee", "S'sme", "S'sne", "S'sra", "S'sta", "S'ta", "S'taa", "S'tra", "S'za", "See", "Sla", "So", "Sozze", "Sra", "Sree", "Tare", "Tee", "Tha", "Tra", "Xa", "Xazi", "Xee", "Xra", "Zho", "Zo", "Zogo", "Zra"};
    static constexpr std::string_view nm2[] = {"bahr", "bas", "bet", "bizs", "bus", "cees", "ch", "chat", "chium", "cus", "d", "daar", "das", "dous", "drees", "g", "gazs", "get", "girb", "gozin", "hlik", "hr", "hrid", "hris", "hs", "k", "kah", "kan", "kazs", "kouk", "l", "lak", "lath", "let", "leus", "lis", "lk", "llk", "m", "mal", "mar", "msek", "mus", "n", "nbet", "nd", "ndas", "nzaar", "r", "rash", "rd", "rith", "rozs", "rr", "s", "sek", "sh", "sibus", "ss", "szan", "tar", "tezs", "th", "this", "ts", "yah", "yak", "yas", "yin", "yith", "z", "zaar", "zin", "zs", "zzan"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2];
    return names;
    }
}
