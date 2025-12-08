#include "dungeon_and_dragons-eladrins_lib.h"

#include <vector>
#include <string>

/* Implementation mirrors the original JavaScript generator:
 *
 *   function generator$dungeon_and_dragons$eladrins(type) {
 *       var nm1 = [...];   // default first part list
 *       var nm2 = [...];   // default second part list
 *       var nm3 = [...];   // alternate first part list (type == 1)
 *       var nm4 = [...];   // alternate second part list (type == 1)
 *       i = Math.floor(Math.random() * 10); // unused, kept for parity
 *       if (type === 1) {
 *           names = nm3[random] + nm4[random];
 *       } else {
 *           names = nm1[random] + nm2[random];
 *       }
 *       return names;
 *   }
 *
 * The C++ version follows the same logic, using the supplied RNG.
 */
std::string generate_dungeon_and_dragons_eladrins_name(std::mt19937& rng, int type) {
    static const std::vector<std::string> nm1 = {
        "Ara","Aran","Ber","Bran","Cor","Cru","Da","Daye","Elro","Ere","Far","Fyla","Gal","Galin","Ha","Hor","Im","Ira","Ja","Jor","Kru","Kuo","Lan","Lic","Mar","Min","Nal","Nark","Ola","Otir","Pae","Pan","Qua","Quo","Rel","Riar","Sarn","Sove","Tav","Trin","Uri","Veth","Vic","Wal","Wrug","Xan","Yan","Yor","Zen","Zor"
    };
    static const std::vector<std::string> nm2 = {
        "aris","aster","baver","bin","card","corin","dan","darai","dartis","don","emin","erta","fis","fros","geon","grephor","heros","horn","ikul","iver","kris","kul","lias","liss","mendi","meral","mil","morn","neiros","nis","okas","oros","peiros","prath","ratra","reth","rian","rion","sirak","ster","thas","tihr","torin","urian","uvir","van","vis","wirn","worn","xeral","xis","ykos","yth","zeiros","zion"
    };
    static const std::vector<std::string> nm3 = {
        "Al","An","Anas","Be","Bri","Cae","Cyl","Dris","Dur","Eil","Ena","Fae","Fan","Gru","Gyl","Hen","Hyl","Illa","Ire","Jar","Jelen","Kai","Kora","Les","Lyv","Mag","Me","Nai","Neri","Ol","Ori","Pi","Prys","Qi","Que","Ri","Rol","Sa","Sha","Thei","Tri","Ul","Ura","Va","Vela","Wes","Wre","Xyr","Ylla","Zen"
    };
    static const std::vector<std::string> nm4 = {
        "bis","bynn","cahne","caryn","celle","cena","diel","dys","faera","fyra","glyn","grys","hanna","hyssa","kiries","kyrath","lenae","lenna","lyn","lynna","meiv","miris","mynis","nairra","neth","parys","prana","qirith","qis","raste","rastra","riele","rynna","sanna","shana","sys","thaea","tora","trianna","vara","viryn","vyre","wena","wyse","xana","xis","yana","yeira","zane","zora"
    };

    // Consume a random number to keep parity with other generators (the original JS
    // generates a random i in [0,9] but never uses it).
    (void)rng;

    if (type == 1) {
        const std::string& part1 = nm3[rng() % nm3.size()];
        const std::string& part2 = nm4[rng() % nm4.size()];
        return part1 + part2;
    } else {
        const std::string& part1 = nm1[rng() % nm1.size()];
        const std::string& part2 = nm2[rng() % nm2.size()];
        return part1 + part2;
    }
}
