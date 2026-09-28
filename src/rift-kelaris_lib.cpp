#include "rift-kelaris_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_rift_kelaris_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names1_1[] = {"Ac", "Ad", "Adem", "Adon", "Adr", "Ag", "Agl", "Ail", "Air", "Al", "Alet", "Alex", "Alys", "Am", "An", "Anas", "And", "Ang", "Aph", "Aphr", "Apol", "Ar", "Aret", "Art", "As", "Asp", "Ath", "Bar", "Cal", "Call", "Cas", "Casc", "Cath", "Cel", "Char", "Cher", "Cos", "Cres", "Cyr", "Daphn", "Del", "Delph", "Dem", "Den", "Dian", "Dion", "Dor", "Dorin", "Dun", "Eil", "Elean", "Elen", "Elin", "Eud", "Euph", "Evan", "Evang", "Gel", "Hel", "Hyac", "Hyp", "Ir", "Is", "Isad", "Kal", "Kol", "Lar", "Lyd", "Mar", "Mel", "Nel", "Ner", "Nes", "Nor", "Ol", "Olym", "Oph", "Pan", "Pand", "Phed", "Phil", "Ren", "San", "Sel", "Stel", "Tar", "Ter", "Thel", "Xand", "Xen", "Zan", "Zer"};
    static constexpr std::string_view names2_1[] = {"acia", "adia", "agia", "aina", "ala", "alia", "anda", "andia", "andra", "ania", "antha", "ara", "arria", "asia", "atha", "atia", "eanor", "ectra", "eda", "eia", "ela", "elia", "elina", "emia", "emona", "emone", "ena", "enia", "ephone", "erine", "erise", "esa", "eta", "etha", "ethea", "etina", "etria", "exis", "ia", "ice", "ida", "ienne", "illa", "ina", "ine", "inthe", "ira", "isia", "isma", "issa", "ite", "itha", "iza", "ocia", "odite", "odora", "omeda", "omena", "ona", "one", "onia", "onne", "ora", "osine", "othea", "othy", "yllis", "yne", "ysa"};
    static constexpr std::string_view names1_2[] = {"Ab", "Abd", "Abs", "Absyr", "Ac", "Acas", "Ach", "Achat", "Achel", "Achil", "Achl", "Acr", "Act", "Ad", "Adber", "Adel", "Adelp", "Adm", "Adr", "Adras", "Aeac", "Aeg", "Aegis", "Aegyp", "Aen", "Aeol", "Aes", "Aescul", "Aet", "Ag", "Agam", "Agat", "Ain", "Aj", "Ak", "Al", "Alcan", "Alcin", "Ales", "Alex", "Alp", "Am", "And", "Andr", "Ant", "Antil", "Apo", "Apol", "Arc", "Arg", "Aris", "At", "Bal", "Bas", "Baz", "Bem", "Bor", "But", "Cadm", "Cap", "Cas", "Cast", "Cel", "Cep", "Cerb", "Cir", "Col", "Cor", "Corid", "Cro", "Dam", "Damar", "Damas", "Dar", "Darr", "Dem", "Demet", "Demod", "Demor", "Diom", "Dion", "Dn", "Dor", "Dun", "Erasm", "Erys", "Eur", "Gan", "Gor", "Greg", "Grig", "Hec", "Hect", "Hel", "Her", "Herc", "Herm", "Hes", "Hom", "Homer", "Icar", "Jul", "Kor", "Krat", "Krik", "Kyr", "Lean", "Leon", "Lys", "Maur", "Morp", "Nar", "Nect", "Nem", "Ob", "Obel", "Or", "Orp", "Pal", "Pat", "Pen", "Per", "Phant", "Plat", "Pos", "Proct", "Ras", "Rhod", "Socr", "Spyr", "Stam", "Tak", "Thad", "Ther", "Trit", "Vas", "Xer", "Zen"};
    static constexpr std::string_view names2_2[] = {"acus", "aemon", "aeon", "aethon", "aeus", "annos", "antes", "apius", "areus", "arios", "arius", "arus", "asius", "astos", "ates", "atius", "aus", "avros", "eas", "elous", "emas", "emus", "enios", "eon", "eos", "epios", "erios", "eron", "eros", "erus", "es", "etheus", "etrios", "etrius", "etus", "eus", "hates", "heus", "hile", "hos", "ian", "icus", "idas", "illes", "illos", "ion", "is", "isius", "iss", "issus", "isthus", "isto", "ites", "iton", "ius", "obus", "ocles", "olemus", "olos", "olus", "onis", "orgon", "orior", "orus", "os", "osios", "othius", "ous", "ycus", "ymion", "yros", "ysius", "ystheus", "ysus", "ytus"};

    ArrayView names1; ArrayView names2; std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

    if (type == 1) {
    names1 = make_view(names1_1);
    names2 = make_view(names2_1);
    } else {
    names1 = make_view(names1_2);
    names2 = make_view(names2_2);
    }
i = rng() % 10; {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = names1[rnd] + names2[rnd2];
    return names;
    }
}
