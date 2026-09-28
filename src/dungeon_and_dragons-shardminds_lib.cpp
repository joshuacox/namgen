#include "dungeon_and_dragons-shardminds_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_dungeon_and_dragons_shardminds_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Adu", "Ama", "Ani", "Ar", "Arsha", "Ashi", "Ashtu", "Bala", "Bara", "Basha", "Beles", "Delu", "Di", "Dura", "Duru", "Enu", "Eri", "Eshu", "Hua", "Hun", "Il", "Ilu", "Ira", "Ish", "Ku", "Kua", "Kuba", "Lu", "Mani", "Mara", "Mashi", "Na", "Nara", "Nashi", "Nu", "Rua", "Run", "Sana", "Sari", "Selu", "Shir", "Suma", "Tab", "Tin", "Tiru", "Uba", "Uku", "Ura", "Ut", "Zaki"};
    static constexpr std::string_view names2[] = {"ba", "bam", "bani", "bu", "ha", "hara", "hu", "ka", "ku", "lazu", "lua", "mea", "nar", "nara", "naram", "naru", "nashtu", "ni", "niri", "nu", "nua", "pana", "ram", "ranu", "rashi", "raya", "ri", "rin", "runu", "shara", "shari", "shi", "shti", "shtu", "shu", "sunu", "ta", "tana", "tani", "tari", "ti", "tira", "tiru", "tua", "tum", "wia", "ya", "yara", "yua", "zu"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

    i = rng() % 10; {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = std::string(names1[rnd]) + std::string(names2[rnd2]);
    return names;
    }
}
