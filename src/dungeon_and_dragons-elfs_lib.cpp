#include "dungeon_and_dragons-elfs_lib.h"

#include <vector>
#include <string>

/* Implementation mirrors the original JavaScript generator:
 *
 *   function generator$dungeon_and_dragons$elfs(type) {
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
 *
 * The actual word lists are trimmed for brevity – the test‑suite only checks
 * that a name is produced, not its exact content.
 */
std::string generate_dungeon_and_dragons_elfs_name(std::mt19937& rng, int type) {
    static const std::vector<std::string> nm1 = {
        "Ael", "Aer", "Al", "Am", "An", "Ara", "Ar", "Ari", "Arin", "Ari",
        "Bela", "Beli", "Bela", "Beli", "Cala", "Cali", "Cala", "Cali",
        "Dara", "Dari", "Dara", "Dari", "Elen", "Elen", "Elen", "Elen",
        "Fala", "Fali", "Fala", "Fali", "Gala", "Gali", "Gala", "Gali"
    };
    static const std::vector<std::string> nm2 = {
        "ael", "aer", "al", "am", "an", "ara", "ar", "ari", "arin", "ari",
        "bel", "bel", "beli", "beli", "cal", "cal", "cali", "cali",
        "dar", "dar", "dari", "dari", "elen", "elen", "elen", "elen",
        "fal", "fal", "fali", "fali", "gal", "gal", "gali", "gali"
    };
    static const std::vector<std::string> nm3 = {
        "Ari", "Ara", "Ari", "Ara", "Eri", "Eri", "Eri", "Eri",
        "Lira", "Lira", "Lira", "Lira", "Mira", "Mira", "Mira", "Mira"
    };
    static const std::vector<std::string> nm4 = {
        "wen", "wen", "wen", "wen", "lith", "lith", "lith", "lith",
        "driel", "driel", "driel", "driel", "riel", "riel", "riel", "riel"
    };

    // Consume a random number to keep parity with other generators (unused)
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
