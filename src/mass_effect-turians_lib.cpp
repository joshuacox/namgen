#include "mass_effect-turians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_mass_effect_turians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names3[] = {"Ab", "Aber", "Abi", "Aca", "Acha", "Acil", "Ada", "Adep", "Adju", "Adra", "Aebu", "Aet", "Ag", "Aga", "Ago", "Al", "Alba", "Albi", "Albu", "Ale", "Ba", "Bar", "Barba", "Bell", "Bella", "Belli", "Bibu", "Bitu", "Bola", "Boni", "Brom", "Bromi", "Bru", "Bruc", "Bul", "Cae", "Cael", "Caep", "Cal", "Cala", "Calp", "Calpo", "Cam", "Campa", "Can", "Candi", "Capi", "Dar", "Darda", "Dec", "Dexi", "Didi", "Domi", "Domiti", "Doni", "Drus", "Drusi", "Duvi", "Ebo", "Egna", "Elvo", "Enni", "Epi", "Epidi", "Epo", "Eras", "Eudo", "Fa", "Fal", "Faus", "Fel", "Fim", "Flo", "Flori", "Frum", "Gai", "Gal", "Gari", "Gav", "Gene", "Glob", "Gor", "Gra", "Grat", "Hab", "Hel", "Hil", "Hila", "Hono", "Hora", "Horten", "Igna", "Ind", "Inda", "Isa", "Ita", "Lae", "Laevi", "Lin", "Lucce", "Luci", "Lupi", "Mac", "Macri", "Mal", "Marce", "Mau", "Maur", "Maxi", "Mel", "Merca", "Mola", "Mur", "Muti", "Nar", "Nata", "Naza", "Neme", "Numo", "Octa", "Octavi", "Olym", "Opi", "Opti", "Orien", "Oro", "Paet", "Pali", "Pan", "Pap", "Peta", "Pho", "Pos", "Pota", "Pro", "Proc", "Prota", "Qua", "Quen", "Qui", "Quin", "Ram", "Rami", "Rece", "Regi", "Remi", "Romul", "Ruf", "Sabe", "Salvi", "San", "Sanc", "Scri", "Seve", "Sim", "Simp", "Stra", "Sul", "Suli", "Sur", "Syl", "Tan", "Tani", "Ter", "Tib", "Tibur", "Tremo", "Treni", "Umbo", "Ursi", "Var", "Vari", "Veli", "Veri", "Vibi", "Vic", "Victo", "Victri", "Vita"};
    static constexpr std::string_view names4[] = {"cius", "colus", "culus", "cus", "das", "donis", "dos", "dros", "dus", "gatus", "gius", "ion", "lianus", "lienus", "lin", "linus", "lius", "lus", "mius", "mus", "nian", "nianus", "nion", "nis", "nius", "nus", "panus", "raka", "rian", "ril", "rinus", "rius", "scus", "sis", "so", "tion", "tis", "tius", "tumus", "tus"};
    static constexpr std::string_view names1_1[] = {"Agri", "Am", "Amu", "Amul", "Amuli", "Ap", "Ar", "Arru", "Au", "Augu", "Augus", "Aul", "Bri", "Bru", "Brut", "Ca", "Cae", "Cael", "Cai", "Cam", "Cami", "Can", "Cas", "Cna", "Cnae", "Cos", "De", "Dec", "Deci", "Dru", "Drus", "Fa", "Fau", "Faus", "Fla", "Flavi", "Ga", "Gai", "Gal", "Galer", "He", "Her", "Heri", "Ho", "Hos", "Ju", "Juli", "Julian", "Ka", "Kae", "Kaes", "La", "Lar", "Lu", "Luc", "Luci", "Ma", "Mame", "Mamer", "Man", "Mani", "Mar", "Marce", "Max", "Maxi", "Met", "No", "Nu", "Num", "Nume", "Octa", "Octavi", "Op", "Opi", "Oppi", "Pa", "Paul", "Pla", "Po", "Posti", "Postu", "Pot", "Poti", "Pri", "Prim", "Pro", "Proc", "Procu", "Pu", "Publi", "Qui", "Quin", "Se", "Sec", "Secu", "Sep", "Septi", "Ser", "Servi", "Si", "Sis", "Spu", "Te", "Ter", "Terti", "Ti", "Tibe", "Tiber", "Tiberi", "Tu", "Tul", "Tull", "Ve", "Vel", "Vi", "Vibi", "Vo", "Vopi"};
    static constexpr std::string_view names2_1[] = {"bius", "bus", "cus", "eus", "ius", "lio", "lius", "lus", "mius", "mus", "na", "nus", "pius", "rius", "runs", "sius", "so", "ter", "tis", "tius", "tus", "us", "vius", "vus"};
    static constexpr std::string_view names1_2[] = {"Abu", "Ac", "Aci", "Aebu", "Aedi", "Aemi", "Al", "An", "Anto", "Avi", "Bae", "Ban", "Barba", "Betu", "Bruc", "Cae", "Caeci", "Cael", "Caese", "Caeso", "Cali", "Calve", "Came", "Cami", "Cani", "Cice", "Clo", "Comi", "Conse", "Decu", "Desti", "Dexi", "Di", "Duro", "Epi", "Equ", "Fadi", "Fla", "Flo", "Flori", "Floro", "Furi", "Gabi", "Gale", "Gega", "Gra", "Here", "Hermi", "Hora", "Ici", "Ju", "Juve", "La", "Lae", "Libu", "Livi", "Luta", "Mae", "Mal", "Mani", "Mari", "Maxi", "Me", "Mene", "Meti", "Milo", "Nae", "Nepi", "Ni", "Novi", "Octa", "Oppi", "Pa", "Pae", "Ped", "Pina", "Pli", "Pol", "Pompe", "Popi", "Por", "Qu", "Qui", "Ru", "Ruso", "Ruti", "Salo", "Secu", "Sei", "Sen", "Septi", "Si", "Sido", "Sil", "Ta", "Tani", "Treba", "Treme", "Tu", "Tul", "Ul", "Va", "Vale", "Vel", "Vera", "Vi", "Vibi", "Viri", "Vite", "Vitel", "Volu", "Vore"};
    static constexpr std::string_view names2_2[] = {"ana", "bia", "cia", "cidia", "dia", "ginia", "ia", "lea", "lia", "lonia", "mia", "na", "naria", "nea", "nia", "pia", "pilia", "ponia", "retia", "ria", "sia", "tana", "teia", "tia", "tilia", "tina", "tiria", "toria", "vea", "via"};

    ArrayView names1; ArrayView names2; std::string names; size_t rnd = 0; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

    if (type == 1) {
    names1 = make_view(names1_1);
    names2 = make_view(names2_1);
    } else {
    names1 = make_view(names1_2);
    names2 = make_view(names2_2);
    }
i = rng() % 10; {
    rnd = rng() % std::size(names1);
    rnd1 = rng() % std::size(names2);
    rnd2 = rng() % std::size(names3);
    rnd3 = rng() % std::size(names4);
    names = names1[rnd] + names2[rnd1] + " " + names3[rnd2] + names4[rnd3];
    return names;
    }
}
