#include "places-librarys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_librarys_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"ABC", "Aeos", "Algorithm", "Amenity", "Angel's", "Anomaly", "Apex", "Aptitude", "Art Archive", "Avant-garde", "Beauview", "Blossoms", "Book Mark", "Booked", "Bookworm", "Calligraph", "Capitol", "Carpe Librum", "Celestial", "Central Park", "Chapter", "Chapter One", "Charity", "Chimera", "Codex", "Compendium", "Cosmic", "Courtesy", "Crescent Moon", "Crest", "Crossroad", "Crown", "Curio", "Curiosity", "Data", "Daydream", "Desire", "Discovery", "Divine", "Epiphany", "Epitome", "Equinox", "Estate", "Eternal", "Evening Hour", "Explorer", "Figment", "First Story", "Forte", "Freedom", "Frontier", "Gift's", "Global", "Globe", "Grand", "Grand Archive", "Grand Duchess", "Grand Isle", "Grand Monastery", "Grand Oak", "Grand State", "Grotto", "Guardian's", "Harborview", "Harmony", "Heirloom", "Heritage", "Holy", "Idle Hour", "Illusions", "Imagine", "Imperial", "Infinity", "Innovation", "Inquiry", "Insight", "Institute", "Jubilee", "King's", "Knight", "Knowledge", "Labyrinth", "Legacy", "Leisure", "Lexicon", "Liberty", "Lullaby", "Marvel", "Memorial", "Millennium", "Miracle", "Mirage", "Mystery", "National History", "National Memorial", "National Public", "National University", "Novel Idea", "Obelisk", "Oceanic", "Open Book", "Opus", "Oracle", "Page One", "Paragon", "Patrimony", "Pinnacle", "Pioneer", "Plainfield", "Prime", "Prism", "Probe", "Prodigy", "Public Scientific", "Pursuit", "Quest", "Quietus", "Rainbow", "Reader's Garden", "Repose", "Requiem", "Reticence", "Revelation", "Reverie", "Rising Sun", "Royal", "Saturninity", "Savant", "Scholar's", "Serenity", "Solace", "Solitude", "Spectrum", "Spring Harbor", "Stellar", "Summit", "Supreme", "Tempest", "Temple", "Titlewave", "Tranquility", "Treatise", "Trove", "Utopia", "Vade Mecum", "Valley", "Virtue", "Vision", "Wonder", "Zenith"};
    static constexpr std::string_view nm2[] = {"Library", "Bilbiotheca", "Library", "Library", "Library", "Library", "Library", "Library", "Library", "Library", "Library", "Atheneum"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + " " + nm2[rnd2];
    return names;
    }
}
