#include "dungeon_and_dragons-githzerais_lib.h"

#include <vector>
#include <string>

/* Implementation mirrors the original JavaScript generator:
 *
 *   function generator$dungeon_and_dragons$githzerais(type) {
 *       var namesFemF = [...];   // female first part
 *       var namesFemL = [...];   // female second part
 *       var namesMaleF = [...];  // male first part
 *       var namesMaleL = [...];  // male second part
 *       i = Math.floor(Math.random() * 10); // unused, kept for parity
 *       if (type === 1) {
 *           names = namesFemF[rnd] + namesFemL[rnd2];
 *       } else {
 *           names = namesMaleF[rnd] + namesMaleL[rnd2];
 *       }
 *       return names;
 *   }
 *
 * The C++ version follows the same logic, using the supplied RNG.
 */
std::string generate_dungeon_and_dragons_githzerais_name(std::mt19937& rng, int type) {
    static const std::vector<std::string> namesFemF = {
        "Ad","Alm","Arw","Ash","Dah","Dhar","Dolm","Dran","Ell","Erzh","Esz","Ezh","Grel","Halm","Han","Harn","Heln","Ihr","Iln","Imm","Iz","Kan","Kharm","Khaz","Krez","Laz","Lez","Lhash","Magd","Marm","Nagr","Nah","Nalm","Rasz","Rez","Sham","Sharm","Shund","Um","Uw"
    };
    static const std::vector<std::string> namesFemL = {
        "a","ah","aka","al","arah","arin","aya","ayah","eah","eka","el","ela","elna","elya","elzal","ena","enah","era","erah","eya","ihn","ila","ilzin","in","ina","ira","iza","mina","ya","yara"
    };
    static const std::vector<std::string> namesMaleF = {
        "Am","Ar","Ara","Aza","Bar","Bra","Bru","Da","Dar","Dor","Dra","Dro","Du","Fa","Far","Fer","Gra","Gran","Gre","Gro","Gru","Hu","Ka","Kar","Kha","Kra","Kro","Ma","Mu","Na","Nar","Nu","Ra","Ran","Rin","Ru","Sha","Shra","Sra","Zra"
    };
    static const std::vector<std::string> namesMaleL = {
        "d","dak","gh","k","kahr","kar","khar","kk","lag","llak","mag","mak","nag","rag","rak","ram","rath","rek","rg","rm","rth","ruk","th","tig","zag","zak","zar","zeg","zirg","zth"
    };

    // Consume a random number to keep parity with the original JS (unused)
    (void)rng;

    if (type == 1) {
        const std::string& partF = namesFemF[rng() % namesFemF.size()];
        const std::string& partL = namesFemL[rng() % namesFemL.size()];
        return partF + partL;
    } else {
        const std::string& partF = namesMaleF[rng() % namesMaleF.size()];
        const std::string& partL = namesMaleL[rng() % namesMaleL.size()];
        return partF + partL;
    }
}
