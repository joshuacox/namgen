#include "dragon_age-qunaris_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_dragon_age_qunaris_name(std::mt19937& rng, int type) {
    static constexpr std::string_view namesFemale[] = {"As", "Bah", "Bir", "Birs", "Can", "Dem", "Fad", "Giz", "Hat", "Kar", "Kard", "Kub", "Kubr", "Kut", "Mel", "Naz", "Nazl", "Nih", "Or", "Ork", "Oz", "Ozen", "Ras", "San", "Say", "Sem", "Ser", "Sol", "Solm", "Sum", "Tam", "Tamg", "Tur", "Turn", "Yas", "Yasem", "Yen", "Yon"};
    static constexpr std::string_view namesFemale2[] = {"a", "aan", "al", "am", "an", "anem", "ar", "asan", "ay", "ayar", "az", "azik", "azli", "e", "ek", "elek", "elen", "em", "emin", "en", "ena", "ener", "enli", "er", "era", "et", "ice", "ide", "ie", "iha", "ihan", "ik", "in", "onal", "ul", "umer"};
    static constexpr std::string_view namesMale[] = {"Ak", "Akin", "Akor", "Al", "Ar", "Aris", "Arm", "Arv", "As", "Ask", "Askh", "Asl", "Bas", "Bast", "Bur", "Dur", "Gun", "Gund", "Gur", "Gurh", "Jar", "Jarv", "Kan", "Ket", "Kub", "Mar", "Met", "Naz", "Ok", "Okan", "Or", "Orn", "Oz", "Ozk", "Sal", "Sen", "S", "St", "Tam", "Ten", "Yag", "Yagm"};
    static constexpr std::string_view namesFamily[] = {"aarad", "aari", "aas", "aca", "ad", "ak", "alit", "amay", "an", "anat", "aner", "ant", "arad", "ari", "as", "at", "ay", "azim", "ehan", "ek", "en", "enol", "er", "ilay", "im", "iner", "ishok", "it", "ogan", "ojan", "ok", "ol", "oren", "ri", "ug", "ul", "urak", "urhan", "utlu"};

    std::string names; size_t rnd0 = 0; size_t rnd1 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd0 = rng() % std::size(namesFemale);
    rnd1 = rng() % std::size(namesFemale2);
    names = std::string(namesFemale[rnd0]) + std::string(namesFemale2[rnd1]);
    } else {
    rnd0 = rng() % std::size(namesMale);
    rnd1 = rng() % std::size(namesFamily);
    names = std::string(namesMale[rnd0]) + std::string(namesFamily[rnd1]);
    }
    return names;
    }
}
