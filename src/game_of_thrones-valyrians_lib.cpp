#include "game_of_thrones-valyrians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_game_of_thrones_valyrians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names1[] = {"Ae", "Aega", "Aera", "Aery", "Bae", "Baese", "Balae", "Dae", "Daema", "Daera", "Gae", "Gahae", "Galae", "Garae", "Jacae", "Jae", "Jaehae", "Jaere", "Lae", "Lucae", "Ma", "Mae", "Maeha", "Malae", "Mata", "Rae", "Ragae", "Rahae", "Rhae", "Tae", "Taece", "Tahae", "Talae", "Tyrae", "Va", "Vae", "Vahae", "Vi", "Vise", "Yrae"};
    static constexpr std::string_view names2[] = {"dar", "dor", "gar", "garon", "garys", "gel", "gon", "gor", "lar", "larr", "larys", "lon", "lor", "lyx", "mar", "marr", "marys", "mion", "mon", "mond", "mor", "morys", "myx", "nar", "narr", "nor", "nys", "nyx", "raenar", "rion", "ron", "rys", "var", "von", "vor"};
    static constexpr std::string_view names3[] = {"Aene", "Aere", "Alae", "Aly", "Bae", "Bhae", "Ba", "Dae", "Daene", "Delae", "Elae", "Erae", "Hae", "Haele", "He", "Jae", "Jaela", "Jelae", "Mae", "Maele", "Malae", "Manae", "Nae", "Naela", "Naere", "Nelae", "Nesae", "Raene", "Relae", "Renae", "Rhae", "Rhaene", "Sae", "Saela", "Saene", "Saere", "Selae", "Vae", "Vhae", "Vyse"};
    static constexpr std::string_view names4[] = {"hna", "hra", "hrys", "hnae", "hra", "la", "lys", "lla", "lyra", "mys", "mala", "mera", "na", "nla", "nera", "nna", "nya", "nyra", "nys", "ra", "rla", "rya", "rys", "ssa", "sanne", "sella", "sa", "sys"};
    static constexpr std::string_view names5[] = {"Aer", "Ag", "Ar", "Bael", "Bar", "Ber", "Caen", "Cal", "Cel", "Daer", "Dal", "Dor", "Gael", "Gal", "Gon", "Laen", "Laer", "Len", "Maen", "Mal", "Mel", "Nael", "Nar", "Noh", "Qar", "Qoh", "Rael", "Raen", "Rah", "Taen", "Tael", "Tar", "Vael", "Val", "Vel"};
    static constexpr std::string_view names6[] = {"aellis", "aelor", "aenor", "aeris", "aleos", "anyon", "areon", "daerys", "eneos", "ennis", "eris", "gaeron", "garis", "gyreon", "iar", "inarys", "itheos", "laeris", "laeron", "larys", "maereon", "naeros", "nalys", "nareon", "naris", "raenos", "ralis", "reos", "talor", "talos", "taris", "theon", "theos", "tigar", "yreos"};

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
