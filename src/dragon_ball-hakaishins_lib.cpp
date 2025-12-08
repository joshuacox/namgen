#include "dragon_ball-hakaishins_lib.h"

#include <vector>
#include <string>

/* The original JavaScript generator builds a name from a single array
   of possible names, picking one at random and removing it from the list
   so it is not reused in the same process. */
std::string generate_dragon_ball_hakaishins_name(std::mt19937& rng) {
    static std::vector<std::string> names = {
        "Absi","Ager","Alus","Arak","Arkis","Arma","Awa","Bassi","Beerus","Bourbu",
        "Bouru","Calva","Calvad","Cha","Champa","Chi","Cid","Cide","Cog","Cogna",
        "Daiqui","Deira","Deiras","Gani","Ginge","Gria","Guino","Gyn","Ider",
        "Ine","Jen","Jenev","Jenne","Jiu","Kari","Karis","Keffi","Kefi","Kumi",
        "Kuras","Lagus","Magna","Magnac","Manche","Manchi","Marsa","Mea","Meada",
        "Meadas","Mez","Mezca","Moonshi","Mooshi","Nac","Neve","Never","Niha",
        "Pache","Pagne","Para","Paras","Perie","Quiri","Rai","Raici","Raicil",
        "Raki","Rakis","Sak","Sakis","Sakus","Sala","Salas","Sangris","Santis",
        "Shou","Sin","Singa","Sinthe","Sojus","Sontis","Teq","Teqi","Tequi",
        "Tes","Tonton","Vado","Vados","Vod","Vodkis","Waine","Whis","Wynn"
    };

    if (names.empty()) {
        return "";
    }

    size_t idx = rng() % names.size();
    std::string result = names[idx];
    names.erase(names.begin() + idx);
    return result;
}
