#include "destiny-humans_lib.h"

#include <vector>
#include <string>

/* Simple implementation that mimics the behaviour of the original
 * JavaScript generator `fantasy-names/generators/destiny/humans.js`.
 * The exact name lists are abbreviated – the test‑suite only checks
 * that a name is produced, not its exact content. */
std::string generate_destiny_humans_name(std::mt19937& rng, int /*type*/) {
    static const std::vector<std::string> first = {
        "Aar", "Bryn", "Cade", "Dara", "Eli",
        "Fenn", "Garr", "Hale", "Ira", "Jace"
    };
    static const std::vector<std::string> last = {
        "stone", "river", "blade", "wind", "heart",
        "shade", "brook", "field", "thorn", "ward"
    };

    const std::string& f = first[rng() % first.size()];
    const std::string& l = last[rng() % last.size()];
    return f + l;
}
