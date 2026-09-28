#include "warhammer_40k-eldars_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_40k_eldars_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names1[] = {"Al", "Am", "Amo", "Amon", "Ar", "Arag", "Arg", "Arro", "Asur", "Bahar", "Bale", "Bar", "Bara", "Baran", "Bel", "Bele", "Bene", "Bore", "Caen", "Caer", "Caera", "Cal", "Dal", "Dara", "Don", "Dun", "El", "Elam", "Elra", "Esar", "Faen", "Fan", "Far", "For", "Fue", "Gala", "Galan", "Gil", "Gilfa", "Gon", "Gul", "Idra", "Idran", "Iril", "Ise", "Isen", "Kae", "Kal", "Karan", "Kay", "Kel", "Lae", "Lan", "Lau", "Len", "Lo", "Mach", "Mau", "Men", "Mene", "Mener", "Mor", "Morro", "Ola", "On", "Ora", "Oro", "Osu", "Tae", "Tal", "Tan", "Ten", "Yl", "Yra", "Ysu"};
    static constexpr std::string_view names2[] = {"baer", "ban", "bas", "bryn", "byn", "davar", "deer", "dor", "drad", "dras", "duin", "gan", "gard", "gen", "groth", "hidon", "hith", "hyn", "kas", "kin", "kon", "kyn", "las", "lath", "leath", "leth", "lim", "lion", "lon", "lyth", "maer", "mar", "mas", "men", "mes", "mon", "more", "naer", "nar", "nedor", "nel", "nyl", "rad", "ran", "ranel", "rendil", "rian", "riel", "rion", "rith", "ros", "roth", "ruin", "rys", "saar", "san", "seith", "sen", "seth", "shin", "shor", "sys", "tar", "tari", "telar", "thanil", "tharal", "thorn", "tien", "tyr", "van", "var", "vel", "vor", "vyn"};
    static constexpr std::string_view names3[] = {"Al", "Aem", "Ami", "Aeme", "Ali", "Ara", "Aris", "Arre", "Ashe", "Baha", "Bela", "Baer", "Baera", "Balan", "Bel", "Baele", "Behne", "Bore", "Caen", "Cela", "Caella", "Cel", "Dil", "Dera", "Den", "Daen", "El", "Ela", "Elra", "Elsar", "Faen", "Fen", "Fir", "Fo", "Fae", "Gela", "Gellan", "Gil", "Gilsa", "Gen", "Gil", "Ilra", "Ilro", "Irli", "Ise", "Isen", "Kae", "Khel", "Kaera", "Kay", "Kel", "Lae", "Lana", "Lae", "Len", "Li", "Mes", "Mae", "Mena", "Mene", "Menel", "Meh", "Mello", "Ola", "One", "Ore", "Osi", "Oasa", "Tae", "Tel", "Taphe", "Ten", "Yl", "Yna", "Yse"};
    static constexpr std::string_view names4[] = {"bala", "benne", "bera", "brae", "bryn", "daen", "daer", "dole", "dona", "dra", "dynn", "gil", "gith", "gren", "gwen", "hina", "hish", "hynn", "kae", "keza", "kia", "kra", "laeth", "lara", "leth", "lira", "lith", "lone", "lya", "lyth", "mae", "mela", "mena", "mere", "mia", "myn", "myna", "nae", "nel", "nelle", "nera", "nys", "rana", "raniel", "rena", "ria", "riel", "rio", "ris", "rith", "rosa", "rye", "ryna", "rys", "sa", "sae", "sela", "shae", "sho", "sis", "sya", "sys", "tara", "tela", "tera", "thala", "thanis", "tiren", "tyra", "tys", "vae", "vara", "vela", "vena", "vyss"};

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
