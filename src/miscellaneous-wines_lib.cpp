#include "miscellaneous-wines_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_wines_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "bl", "br", "ch", "cl", "dh", "fr", "fl", "gh", "gr", "sh", "tr"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ueu", "ou", "au", "ai", "ue", "eau", "au", "ei", "ee", "ia", "ie", "io", "uei", "oui", "ieu", "eo"};
    static constexpr std::string_view nm3[] = {"bb", "bl", "br", "c", "cc", "cch", "ch", "d", "f", "g", "gd", "gn", "gr", "j", "k", "l", "lb", "lbl", "ldt", "ll", "lr", "ls", "m", "mb", "mbl", "mbr", "mch", "mm", "mp", "n", "nc", "nch", "nd", "ndr", "ng", "nh", "nj", "nk", "nn", "nt", "nth", "ntr", "nv", "pf", "pl", "q", "r", "rb", "rc", "rch", "rd", "rf", "rg", "rgr", "rh", "rl", "rm", "rn", "rr", "rs", "rt", "rth", "rtz", "s", "sb", "sc", "sl", "ss", "ssl", "st", "th", "tt", "v", "vr", "x", "z"};
    static constexpr std::string_view nm4[] = {"beit", "bera", "beutel", "blage", "bles", "blis", "bourg", "bria", "cano", "cati", "cchio", "cchus", "ce", "cella", "chage", "che", "chen", "chot", "dange", "deaux", "der", "dol", "drieu", "fe", "ge", "geac", "geot", "gey", "giens", "gna", "gnan", "gne", "gnon", "gros", "grube", "gueil", "heim", "kastel", "lage", "lais", "las", "lbot", "lese", "let", "lien", "lino", "lion", "lla", "lle", "llina", "llo", "llon", "lly", "lo", "lon", "lou", "lung", "ly", "ma", "mante", "mat", "may", "mbes", "me", "mens", "ment", "mes", "meur", "ms", "mune", "mur", "na", "nac", "nais", "nas", "nay", "nce", "nche", "ne", "nee", "nel", "ner", "nett", "nia", "nier", "nieux", "nis", "nne", "node", "non", "note", "nots", "nti", "ntre", "nues", "nuhr", "phe", "que", "quem", "raud", "reic", "reich", "resco", "rie", "rnes", "rnet", "rno", "rol", "rons", "rre", "rten", "rtin", "rton", "san", "sco", "sir", "sis", "sne", "sone", "sse", "ssec", "sson", "sus", "tage", "tan", "tium", "tour", "tre", "tte", "val", "ve", "vel", "vens", "ves", "ville", "vrey", "vry", "wen", "wer", "xin", "zeaux", "zin"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "", "Abboccato", "Acescence", "Adamado", "Adega", "Amabile", "Annata", "Bianco", "Blanc", "Blanco", "Branco", "Cépage", "Cap Classique", "Cava", "Chiaretto", "Clairet", "Classic", "Demi-Sec", "Doce", "Dolce", "Doux", "Dulce", "Edes", "Frizzante", "Fume", "Garrafeira", "Granvas", "Halbtrocken", "Invecchiato", "Liquoroso", "Mousseux", "Noir", "Pétillant", "Piquant", "Rich", "Rosado", "Rosato", "Rosso", "Rouge", "Süss", "Sec", "Secco", "Száraz", "Vendemmia", "Vendimia", "Viejo", "d'Or"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd3] + " " + nm5[rnd4];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + nm5[rnd6];
    }
    return names;
    }
}
