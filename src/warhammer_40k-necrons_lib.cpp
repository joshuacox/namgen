#include "warhammer_40k-necrons_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_40k_necrons_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Aaho", "Adda", "Aga", "Aha", "Ahho", "Ah", "Akhe", "Ama", "Amene", "Amenho", "Anho", "Ankhese", "Anla", "Ara", "Asha", "Baqe", "Bebi", "Beke", "Bere", "Cleo", "Dakha", "Dedu", "Deme", "Dja", "Djede", "Dje", "Djo", "Duae", "Eury", "Gany", "Geme", "Gilu", "Hako", "Harkhe", "Harsio", "Hedje", "Hekenu", "Hema", "Henu", "Heqa", "Hete", "Hewe", "Hore", "Hote", "Ibi", "Ibia", "Imho", "Ina", "Ine", "Inetka", "Inte", "Ise", "Isetno", "Iuwe", "Kage", "Kape", "Karo", "Kawa", "Kha", "Khae", "Khame", "Khamu", "Khede", "Khe", "Khu", "Maga", "Mane", "Meke", "Menkau", "Menkhe", "Mentu", "Mere", "Meri", "Merne", "Mery", "Minmo", "Mutne", "Nakhto", "Nasa", "Nebu", "Nebe", "Nebne", "Necta", "Nefe", "Nehe", "Nephe", "Nimae", "Nubkhe", "Pane", "Pare", "Pawu", "Pene", "Petu", "Preho", "Psuse", "Ptahmo", "Ptole", "Qare", "Raho", "Rahe", "Rame", "Ramo", "Sahu", "Sehe", "Sekhe", "Seme", "Sense", "Senu", "Seshe", "Simu", "Tadu", "Takha", "Thutmo", "Tuta", "Udje", "Yanha"};
    static constexpr std::string_view names2[] = {"bash", "basken", "bi", "biankh", "bkay", "clea", "clid", "cris", "des", "djem", "dkare", "fer", "fret", "hyt", "kare", "kauhor", "khaf", "khat", "khet", "khmet", "khmire", "khnet", "khotep", "kht", "kor", "maka", "mehyt", "menes", "menre", "mes", "mhat", "mka", "mkah", "mnisu", "mopet", "mose", "mqen", "msaf", "mun", "munzu", "nakht", "namen", "namun", "naten", "nath", "ndes", "nebti", "nebu", "nhor", "nhotekh", "nhotep", "nmut", "nna", "nru", "nu", "nut", "nza", "phren", "pses", "ptah", "qar", "qed", "ra", "ramen", "reh", "rekh", "renef", "ros", "rqa", "rtari", "ru", "rus", "s", "sankh", "sehti", "seneb", "set", "shen", "shenq", "shet", "skaf", "skhet", "snet", "sret", "t", "tamen", "tamun", "tanath", "tankh", "tari", "taruk", "taten", "tef", "tekh", "tep", "thap", "thes", "this", "thor", "tka", "wa"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = names1[rnd] + names2[rnd2];
    return names;
    }
}
