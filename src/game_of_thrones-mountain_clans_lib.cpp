#include "game_of_thrones-mountain_clans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_game_of_thrones_mountain_clans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names1[] = {"A", "Agga", "Ara", "Ardo", "Ba", "Bo", "Bra", "Bro", "Da", "Do", "Dra", "Dro", "Ga", "Gro", "Gru", "Gu", "Ho", "Hra", "Hro", "Hu", "Ja", "Jara", "Jo", "Jora", "Ka", "Kra", "Kri", "Kru", "Sha", "Sra", "Sru", "Sta", "Tho", "Ti", "Tra", "Tro", "U", "Uma", "Ura", "Uri"};
    static constexpr std::string_view names2[] = {"dar", "dog", "dor", "drag", "gah", "gga", "ggan", "ggor", "gir", "gra", "kha", "khan", "khar", "kkan", "kor", "laf", "lf", "llag", "log", "lor", "mar", "mhor", "mman", "mor", "nar", "nnag", "nog", "nthor", "rak", "rlag", "rrag", "rras", "tar", "ther", "thor", "ttag", "vas", "vor", "vrak", "vvar"};
    static constexpr std::string_view names3[] = {"Bi", "Bra", "Bre", "Bu", "Cha", "Che", "Cru", "Cwe", "Da", "De", "Dre", "Dri", "Fa", "Fe", "Fra", "Fri", "Ge", "Gi", "Gre", "Gri", "Gwe", "Ma", "Mhe", "Mi", "Pha", "Phu", "Pre", "Pru", "Ra", "Re", "Ri", "Ru", "Sha", "Sre", "Sta", "Ste", "Ta", "Tra", "Tre", "Tri"};
    static constexpr std::string_view names4[] = {"cei", "cha", "chal", "ffis", "ggi", "ggin", "ggis", "hell", "his", "hynn", "ka", "kinn", "kis", "lenn", "lla", "llis", "ma", "miy", "mmi", "nell", "nna", "nni", "ress", "rra", "rris", "senne", "sha", "ssi", "tish", "tta", "twyn", "va", "vara", "vell", "wenn", "wyn", "wys", "ya", "yas", "yenn"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(names3);
    rnd2 = rng() % std::size(names4);
    names = names3[rnd] + names4[rnd2];
    } else {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = names1[rnd] + names2[rnd2];
    }
    return names;
    }
}
