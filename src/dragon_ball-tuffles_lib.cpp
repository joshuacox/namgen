#include "dragon_ball-tuffles_lib.h"

#include <vector>
#include <string>

/* The original JavaScript generator builds a name from a single array
   of possible Tuffle names, picking one at random and removing it from
   the list so it is not reused in the same process. */
std::string generate_dragon_ball_tuffles_name(std::mt19937& rng) {
    static std::vector<std::string> names = {
        "Amba", "Ango", "Anno", "Appri", "Apri", "Ara", "Atemo", "Azara", "Babacoco", "Baco", "Bacu", "Bananan", "Banna", "Barella", "Blica", "Boloma", "Buljam", "Buram", "Butan", "Cala", "Callama", "Canta", "Cawwes", "Cerola", "Cerole", "Chari", "Charrie", "Chayo", "Cheelai", "Cheri", "Chuello", "Cito", "Clemmen", "Cocon", "Connu", "Conut", "Cote", "Cotejo", "Craba", "Cranbe", "Cupari", "Curi", "Dila", "Dillagra", "Dirra", "Drian", "Durin", "Elon", "Embli", "Feeg", "Firkaf", "Firri", "Fousa", "Frui", "Galis", "Gallia", "Ganlon", "Gava", "Gojee", "Goma", "Grana", "Granadi", "Grapis", "Guara", "Guav", "Guavis", "Guavvan", "Gunun", "Jambully", "Jubbish", "Jubeju", "Jubu", "Juju", "Kaffi", "Larel", "Limbi", "Limo", "Lonme", "Loquish", "Loupe", "Maboro", "Maray", "Marin", "Marind", "Meelo", "Meelon", "Melain", "Mello", "Melo", "Melopo", "Menti", "Merron", "Monga", "Monlee", "Moring", "Moya", "Moyaa", "Moyate", "Nabana", "Nadila", "Nadilgra", "Nadira", "Netche", "Nona", "Nonaan", "Papaw", "Papayata", "Pari", "Pawpa", "Paya", "Payapa", "Payata", "Pearish", "Peejee", "Pegra", "Peqi", "Per", "Persim", "Pilly", "Pimmello", "Pitay", "Pote", "Potesa", "Pricot", "Pulum", "Pulume", "Pumme", "Qincee", "Quatum", "Quipe", "Quira", "Raime", "Ranagua", "Rangee", "Ranji", "Raza", "Razza", "Riandu", "Rime", "Rola", "Rongan", "Roupe", "Ruity", "Rybe", "Simper", "Talou", "Taloup", "Tama", "Tang", "Tara", "Tarato", "Tareen", "Tarine", "Taya", "Tayapi", "Tecojo", "Temoya", "Tohui", "Vagua", "Vaqua", "Wesha", "Wiki", "Woran", "Yapa", "Yote", "Zara"
    };

    if (names.empty()) {
        return "";
    }

    size_t idx = rng() % names.size();
    std::string result = names[idx];
    names.erase(names.begin() + idx);
    return result;
}
