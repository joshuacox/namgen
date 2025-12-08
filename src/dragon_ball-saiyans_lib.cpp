#include "dragon_ball-saiyans_lib.h"

#include <vector>

/* The original JavaScript generator builds a name from a single array
   of possible Saiyan names and returns a random entry. */
std::string generate_dragon_ball_saiyans_name(std::mt19937& rng) {
    static const std::vector<std::string> names = {
        "Sarada","Chaya","Negi","Cress","Komatsuna","Mizuna","Celeron","Nion","Luffa","Sabi","Aikon","Akchoy","Argula","Arlic","Articho","Arugu","Aspara","Aubergee","Aubergi","Avoca","Ayote","Bage","Beath","Beatroo","Been","Beetroo","Bokcho","Cabba","Cado","Calaba","Callio","Callion","Capper","Carole","Cassa","Cauri","Celleri","Ceriac","Chayot","Chini","Coliflo","Collar","Colrab","Corget","Corgetta","Coriflo","Courge","Courne","Cucum","Cucumb","Cumber","Daiko","Dakon","Dicchio","Dive","Elery","Endife","Erkin","Escar","Escaro","Fannel","Fennle","Galalang","Galanga","Gangal","Garlik","Gherk","Ginge","Gorlick","Gula","Gurki","Iceber","Ionon","Isebereg","Jinjer","Kabage","Kail","Kallabash","Kaper","Karroto","Kassava","Kayle","Keel","Kohlra","Kolard","Kolra","Korn","Langal","Lantain","Lattuce","Leeck","Lemogra","Lemogras","Leriac","Lery","Lettus","Lottus","Lotuce","Maiz","Matillo","Matiloto","Matoto","May","Mayze","Naeb","Niun","Noino","Noppal","Noppale","Okara","Okarot","Okchoy","Okora","Olave","Olve","Onnio","Orat","Otamot","Pakcho","Palantay","Paragu","Parslee","Parsnap","Pasley","Peppa","Pinach","Pinache","Pinrut","Planta","Potate","Potota","Proute","Pumkin","Pumpki","Quash","Raddis","Radichio","Radis","Reppep","Rootaba","Rota","Ruccollo","Ruco","Rugool","Rugu","Rutaba","Sallot","Scalli","Scallio","Shalot","Snippar","Spargu","Sproute","Squas","Suncho","Sunchock","Tabaga","Tarro","Tato","Teeb","Tercres","Tichoke","Totoma","Tunnip","Turrip","Ugula","Umpkin","Vocado","Yamma","Zucchi"
    };

    if (names.empty()) {
        return "";
    }

    size_t idx = static_cast<size_t>(rng() % names.size());
    return names[idx];
}
