#include "dungeon_and_dragons-dragonborns_lib.h"

#include <vector>

/* Implementation mirrors the original JavaScript generator:
 *
 *   function generator$dungeon_and_dragons$dragonborns(type) {
 *       var nm1 = [...];   // first part list
 *       var nm2 = [...];   // second part list
 *       var nm3 = [...];   // alternate first part list (type == 1)
 *       var nm4 = [...];   // alternate second part list (type == 1)
 *       i = Math.floor(Math.random() * 10);
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
std::string generate_dungeon_and_dragons_dragonborns_name(std::mt19937& rng, int type) {
    static const std::vector<std::string> nm1 = {
        "Ali", "Ar", "Ba", "Bal", "Bel", "Bha", "Bren", "Caer", "Calu", "Dur",
        "Do", "Dra", "Era", "Faer", "Fro", "Gre", "Ghe", "Gora", "He", "Hi",
        "Ior", "Jin", "Jar", "Kil", "Kriv", "Lor", "Lumi", "Mar", "Mor",
        "Med", "Nar", "Nes", "Na", "Oti", "Orla", "Pri", "Pa", "Qel", "Ravo",
        "Ras", "Rho", "Sa", "Sha", "Sul", "Taz", "To", "Trou", "Udo", "Uro",
        "Vor", "Vyu", "Vrak", "Wor", "Wu", "Wra", "Wul", "Xar", "Yor", "Zor",
        "Zra"
    };
    static const std::vector<std::string> nm2 = {
        "barum", "bor", "broth", "ciar", "crath", "daar", "dhall", "dorim",
        "farn", "fras", "gar", "ghull", "grax", "hadur", "hazar", "jhan",
        "jurn", "kax", "kris", "kul", "lasar", "lin", "mash", "morn",
        "naar", "prax", "qiroth", "qrin", "qull", "rakas", "rash", "rinn",
        "roth", "sashi", "seth", "skan", "trin", "turim", "varax", "vroth",
        "vull", "warum", "wunax", "xan", "xiros", "yax", "ythas", "zavur",
        "zire", "ziros"
    };
    static const std::vector<std::string> nm3 = {
        "Ari", "A", "Bi", "Bel", "Cris", "Ca", "Drys", "Da", "Erli", "Esh",
        "Fae", "Fen", "Gur", "Gri", "Hin", "Ha", "Irly", "Irie", "Jes",
        "Jo", "Ka", "Kel", "Ko", "Lilo", "Lora", "Mal", "Mi", "Na", "Nes",
        "Nys", "Ori", "O", "Ophi", "Phi", "Per", "Qi", "Quil", "Rai",
        "Rashi", "So", "Su", "Tha", "Ther", "Uri", "Ushi", "Val", "Vyra",
        "Welsi", "Wra", "Xy", "Xis", "Ya", "Yr", "Zen", "Zof"
    };
    static const std::vector<std::string> nm4 = {
        "birith", "bis", "bith", "coria", "cys", "dalynn", "drish", "drith",
        "faeth", "fyire", "gil", "gissa", "gwen", "hime", "hymm", "karyn",
        "kira", "larys", "liann", "lyassa", "meila", "myse", "norae",
        "nys", "patys", "pora", "qorel", "qwen", "rann", "riel", "rina",
        "rinn", "rish", "rith", "saadi", "shann", "sira", "thibra",
        "thyra", "vayla", "vyre", "vys", "wophyl", "wyn", "xiris", "xora",
        "yassa", "yries", "zita", "zys"
    };

    // The original JS uses a random i in [0,9] but never uses it.
    (void)rng(); // consume a random number to keep parity with other generators
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
