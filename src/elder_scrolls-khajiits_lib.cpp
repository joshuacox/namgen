#include "elder_scrolls-khajiits_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_elder_scrolls_khajiits_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names3[] = {"Ah", "Boora", "Hamnu", "Jar", "Khar", "Ka", "Mahr", "Ravi", "Rou", "Sah", "Sih", "Sohl", "Tawak", "Zah", "Ahr", "Bava", "Havnu", "Java", "Kahra", "Kihr", "Marah", "Rawi", "Roj", "Saj", "Sij", "Sal", "Tarvak", "Zahj", "Ahj", "Bahraja", "Hannu", "Jahk", "Khanj", "Kiji", "Mahri", "Rajiv", "Rahk", "Sara", "Sira", "Sajil", "Tovik", "Xa", "A", "Bara", "Hammu", "Ja", "Kha", "Ki", "Mah", "Rai", "Ro", "Sa", "Si", "Sol", "Tavak", "Za"};
    static constexpr std::string_view names4[] = {"biri", "bus", "davi", "han", "hir", "kar", "manni", "mnin", "nai", "oni", "rabi", "spoor", "stae", "tani", "vandi", "bari", "bes", "dawi", "haan", "hior", "kahr", "mahni", "mnihn", "naihn", "ani", "rabbi", "spaer", "stee", "tanni", "vadni", "bihrri", "bussi", "dhari", "rhan", "hirn", "ghar", "mhan", "mnirn", "nair", "onihr", "garvi", "kpoor", "stavir", "tannil", "gandihr", "bihrith", "busihr", "dawihn", "hasin", "hirin", "karon", "manrin", "nmin", "nahir", "ohin", "radir", "sopor", "stahe", "tamil", "vanadi"};
    static constexpr std::string_view names1_1[] = {"Dra'", "Daro'", "Ko'", "Ab'", "Ak'", "Akh'", "Dar'", "Do'", "Dro'", "Fa'", "J'", "Ja'", "Ji'", "Jo'", "K'", "M'", "Ma'", "Qa'", "R'", "Ra'", "Ri'", "S'", "Za'", "Zan'", "Ab'", "Ak'", "Akh'", "Dar'", "Do'", "Dro'", "Fa'", "J'", "Ja'", "Ji'", "Jo'", "K'", "M'", "Ma'", "Qa'", "R'", "Ra'", "Ri'", "S'", "Za'", "Zan'", "Am", "Baa", "Baad", "Bhi", "Bhis", "Dah", "Dahl", "Dro", "Has", "Hass", "Hel", "Heln", "Hus", "Job", "Joba", "Jod", "Jodh", "Jos", "Josh", "Jot", "Joto", "Kaz", "Kaza", "Kes", "Kesh", "Kha", "Khar", "Mo", "Moham", "Moj", "Na", "Om", "Ran", "Rana", "Sha", "Sho", "Shol", "Sin", "The", "Then", "Ther", "Urj", "Urja", "Urjo", "Vas", "Vash", "Wad", "Wada", "Zoa", "Zoar"};
    static constexpr std::string_view names2_1[] = {"barri", "qanar", "sakhar", "shavir", "tasarr", "zah", "zaymar", "zhirr", "farahn", "marash", "shanji", "zharim", "bassa", "dar", "dara", "darsha", "dumiwa", "fazir", "jahirr", "jhan", "jidarr", "jirr", "karim", "khar", "kothre", "mhirr", "raska", "ren-dar", "sava", "shajirr", "tesh", "thri-dar", "vassa", "virr", "zaadha", "zahn", "zahr", "zakar", "zhid", "aaj-Dar", "aana", "aasha", "abhi", "addha", "adirr", "agh", "akha", "aksa", "amha", "andra", "anir", "anni", "ara", "argo", "ari", "arkhu", "arr", "arr-Jo", "arsha", "asha", "ashi", "athad", "atharr", "athra", "ato", "ava", "averr", "azha", "azirr", "dargo", "dirsha", "dran", "enji", "esi", "fer", "ha", "had", "han", "hani", "hannar", "har", "harr", "hasta", "hirr", "hur", "idzo", "ier", "in-Dar", "iq", "irr", "iska", "jhad", "jhera", "jiradh", "jirr", "kar", "kheran", "lani", "lima", "ngil", "nor", "orad", "randru-jo", "rassa", "raym", "rjo", "rris", "saad", "sha", "siri", "tasarr", "zaddha", "zaka", "ar", "bar", "bil", "der", "dul", "gh", "ir", "kir", "med", "nir", "noud", "sien", "soud", "taba", "tabe", "urabi"};
    static constexpr std::string_view names1_2[] = {"Dra'", "Daro'", "Ko'", "La'", "Dar'", "Do'", "Dro'", "J'", "Ja'", "Ji'", "Jo'", "M'", "Ma'", "Qa'", "Ra'", "Ri'", "S'", "Dar'", "Do'", "Dro'", "J'", "Ja'", "Ji'", "Jo'", "M'", "Ma'", "Qa'", "Ra'", "Ri'", "S'", "Dar'", "Do'", "Dro'", "J'", "Ja'", "Ji'", "Jo'", "M'", "Ma'", "Qa'", "Ra'", "Ri'", "S'", "A", "Aba", "Aban", "Abh", "Abhu", "Ada", "Adan", "Add", "Addh", "Adh", "Adha", "Aff", "Affr", "Ahd", "Ahda", "Ahdn", "Ahdr", "Ahj", "Ahja", "Ahji", "Ahk", "Ahka", "Ahn", "Ahna", "Ahnd", "Ahni", "Ahz", "Ahzi", "Ain", "Aina", "Aji", "Ajir", "Anj", "Anja", "Anu", "Anur", "Ara", "Arab", "Arav", "Ash", "Ashi", "Ashn", "Ata", "Atah", "Atr", "Atra", "Ayi", "Ayis", "Azi", "Bah", "Bahd", "Bai", "Bais", "Bhi", "Bhis", "Bhu", "Bhus", "Chi", "Chir", "Dah", "Dahl", "Dahn", "Dro", "Eka", "Ekap", "Ela", "Fa", "Hab", "Haba", "Har", "Hara", "Idh", "Idha", "Ine", "Iner", "Ino", "Inor", "Kaa", "Kaas", "Kha", "Kham", "Khay", "Khaz", "Khi", "Khin", "Ki", "Kis", "Kise", "Kish", "Kisi", "Mo", "Na", "Nah", "Nahs", "Nis", "Nisa", "Ra", "Rab", "Rabi", "Ri", "Sa", "Sha", "Shab", "Sham", "Shav", "Shi", "Shiv", "Sho", "Shom", "Shot", "Shu", "Shun", "Shur", "So", "Ta", "Tal", "Tala", "Tsa", "Tsab", "Tsaj", "Tsal", "Tsan", "Tsar", "Tsav", "Tsi", "Tsiy", "Tsr", "Tsra", "Uba", "Ubaa", "Uda", "Udar", "Unj", "Unja", "Vaj", "Vajh", "Van", "Vanj", "Yus", "Yush", "Za", "Zab", "Zabh", "Zah", "Zahr", "Zay", "Zayn"};
    static constexpr std::string_view names2_2[] = {"aba", "abhi", "abi", "ada", "adhi", "ahin", "ahna", "ahni", "ahra", "aji", "ajma", "amla", "ani", "ara", "aranji", "ari", "arji", "arra", "asa", "asha", "ashi", "asi", "asma", "assa", "assi", "asuna", "ava", "avi", "azami", "azda", "ba", "bah", "bhi", "dahna", "dahra", "dasha", "drashi", "eena", "ena", "feliz", "hana", "hasa", "hashi", "hba", "hbah", "heh", "herra", "hi", "hila", "hinda", "hira", "hiranirr", "hni", "hrazad", "ia", "idasha", "ila", "imba", "ini", "inna", "ira", "iranirr", "irra", "isa", "isi", "ivva", "ja", "jadhi", "jarsi", "ji", "jirra", "jjan", "khtar", "ki", "la", "lajma", "lani", "leena", "mada", "mara", "mba", "mla", "muzi", "nabi", "nara", "nari", "ni", "nita", "nja", "njarsi", "nji", "nna", "pi", "ra", "raji", "ranirr", "ranji", "rasha", "rashi", "rassa", "ravi", "raya", "ri", "riba", "rina", "rivva", "rji", "rra", "rranirr", "rri", "rrina", "sa", "sari", "sha", "shima", "si", "sma", "srin", "ssa", "ssi", "suna", "therra", "tima", "uki", "ura", "uzi", "va", "vani", "vari", "vi", "ya", "yla", "zami", "zda", "zhinda", "zita", "zura"};

    ArrayView names1; ArrayView names2; std::string names; std::string tp; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; int i = 0;

    tp = type;
    if (type == 2) {
    names1 = make_view(names1_1);
    names2 = make_view(names2_1);
    } else {
    names1 = make_view(names1_2);
    names2 = make_view(names2_2);
    }
i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = names1[rnd] + names2[rnd2];
    } else {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    rnd4 = rng() % std::size(names4);
    names = names1[rnd] + names2[rnd2] + " " + names3[rnd3] + names4[rnd4];
    }
    return names;
    }
}
