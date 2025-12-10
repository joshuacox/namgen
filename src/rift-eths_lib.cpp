#include "rift-eths_lib.h"
#include <vector>
#include <cstddef>

/* Name parts for type == 1 */
static const std::vector<std::string> names1_type1 = {
    "Aah","Ah","Amen","Amun","Ankh","Bek","Bith","Ebon","Hal","Hab","Hem","Hon","Is","Kam","Kar","Kan","Khep","Khuns","Mak","Mad","Manet","Meh","Mer","Mukan","Mum","Naham","Nan","Nef","Nen","Nes","Nofr","Nub","Olab","Pen","Ran","Raz","Sam","San","Sen","Shen","Shan","Tam","Ten","Tet","Therm"
};

static const std::vector<std::string> names2_type1 = {
    "agara","anath","ankhnas","arama","arta","astis","atra","ekhu","ela","emi","enen","enet","ense","epet","erit","es","ese","iah","ibah","ibeu","ika","ila","ilah","ima","ina","inah","inoe","ira","irye","isi","isis","itis","iya","iza","onee","orisis","otep","ukura","unta","ura","utaraa","utis"
};

/* Name parts for type == 0 (default) */
static const std::vector<std::string> names1_type0 = {
    "Aah","Aakh","Abaal","Abay","Abdil","Abdam","Abub","Abus","Abuskh","Achen","Acher","Amen","Ankh","Apron","Baken","Bakar","Chat","Dar","Fen","Fun","Hak","Ham","Han","Har","Hek","Hor","Im","Jab","Jaf","Kam","Kak","Kef","Khab","Khaf","Khons","Man","Makal","Mem","Menk","Ment","Nar","Neb","Nekht","Osir","Osor","Pad","Phan","Phrah","Psam","Sem","Seph","Ser","Sok","Smen","Tab","Tah","Tat","Thoth","Thutm","Tosor"
};

static const std::vector<std::string> names2_type0 = {
    "aesis","ahersef","aka","akar","akaruti","aken","akhsas","amelek","amen","aphos","aphres","aphris","apis","asenb","astes","auhor","ehemto","ekhet","ekhtou","emheb","emhebi","emhet","emhotep","enaten","ennifi","entu","ephers","epthah","epthes","eramen","erermes","eres","eri","erres","ertum","eru","erumes","esseker","ihiti","iris","is","isaba","otep","oteph","oubis","ouris","ubis","umah","urmes"
};

/**
 * @brief Generate a Rift‑Eths name.
 *
 * The function randomly selects one element from each of the two name‑part
 * tables (depending on the `type` argument) and concatenates them.
 *
 * @param rng   Random number generator.
 * @param type  0 for the default tables, 1 for the alternate tables.
 * @return      The generated name.
 */
std::string generate_rift_eths_name(std::mt19937& rng, int type) {
    const std::vector<std::string>* part1;
    const std::vector<std::string>* part2;

    if (type == 1) {
        part1 = &names1_type1;
        part2 = &names2_type1;
    } else {
        part1 = &names1_type0;
        part2 = &names2_type0;
    }

    std::uniform_int_distribution<std::size_t> dist1(0, part1->size() - 1);
    std::uniform_int_distribution<std::size_t> dist2(0, part2->size() - 1);

    const std::string& first  = (*part1)[dist1(rng)];
    const std::string& second = (*part2)[dist2(rng)];

    return first + second;
}
