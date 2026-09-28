#include "game_of_thrones-free_citys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_game_of_thrones_free_citys_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names1[] = {"Adar", "Aer", "Ar", "Ball", "Bel", "Brach", "Daar", "Don", "Draq", "Garr", "Goran", "Gyll", "Har", "Harl", "Hor", "Ill", "Inn", "Irr", "Jaer", "Jaq", "Jor", "Laraz", "Laz", "Lys", "Maerr", "Mal", "Mar", "Nak", "Nor", "Nyess", "Sall", "Stall", "Syr", "Thor", "Treg", "Tych", "Var", "Varg", "Vog", "Vyr"};
    static constexpr std::string_view names2[] = {"adhor", "an", "ano", "aphos", "aquo", "ar", "ario", "aro", "apho", "arro", "ello", "elos", "en", "enhor", "enno", "eo", "eqor", "ero", "esso", "icho", "idos", "illos", "io", "iphos", "iros", "o", "odos", "onar", "onno", "onos", "oquo", "or", "orno", "oros", "os", "yllo", "ynno", "yrio", "yros", "ys"};
    static constexpr std::string_view names3[] = {"Ahr", "Aren", "Daen", "Dil", "Dor", "Erin", "Erl", "Faey", "Fer", "Firan", "Harr", "Hel", "Hen", "Il", "Iner", "Laen", "Ler", "Less", "Mel", "Mesh", "Min", "Nes", "Nil", "Noar", "Onal", "Or", "Phen", "Phir", "Sael", "Ser", "Sir", "Taen", "Tir", "Triann", "Vaer", "Vell", "Vor", "Waer", "Wen", "Wyn"};
    static constexpr std::string_view names4[] = {"a", "aena", "aerah", "ala", "aleah", "anah", "anea", "aria", "asha", "aya", "eah", "ela", "ella", "elna", "era", "erah", "esa", "esha", "eya", "eyana", "ianna", "ila", "ina", "ira", "irah", "issa", "ola", "olana", "olla", "ona", "ora", "oreah", "orlah", "osha", "ylea", "ylla", "yna", "ynea", "ysa", "ysha"};
    static constexpr std::string_view names5[] = {"Aen", "Ahr", "Aner", "Baerr", "Bah", "Bren", "Dirr", "Drenn", "Dyn", "Enn", "Eran", "Ess", "Faen", "Flaer", "For", "Fyll", "Hart", "Hest", "Hot", "Iran", "Irn", "Irr", "Maeg", "Mar", "Mop", "Naer", "Nah", "Nest", "Orl", "Orm", "Ost", "Paen", "Pahr", "Phass", "San", "Sorr", "Stass", "Vhass", "Voll", "Vyn"};
    static constexpr std::string_view names6[] = {"aan", "aar", "aenor", "ah", "ahran", "anar", "ar", "aris", "assar", "atis", "el", "elar", "elion", "en", "enohr", "erah", "erion", "erris", "in", "inar", "ion", "ios", "irah", "iris", "iros", "ohr", "ohrin", "olis", "onnis", "oran", "oris", "orlan", "os", "oyor", "yl", "ymion", "yr", "yrion", "yris", "ys"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(names3);
    rnd2 = rng() % std::size(names4);
    rnd3 = rng() % std::size(names5);
    rnd4 = rng() % std::size(names6);
    names = names3[rnd] + names4[rnd2] + " " + names5[rnd3] + names6[rnd4];
    } else {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names5);
    rnd4 = rng() % std::size(names6);
    names = names1[rnd] + names2[rnd2] + " " + names5[rnd3] + names6[rnd4];
    }
    return names;
    }
}
