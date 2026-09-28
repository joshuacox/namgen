#include "fantasy-unicorns_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_unicorns_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Aeolus", "Ainsel", "Aiolos", "Albion", "Alewar", "Amyntas", "Anor", "Argus", "Argyros", "Arion", "Aron", "Arryn", "Auris", "Baine", "Bastion", "Blythe", "Boaz", "Brand", "Cadillac", "Calimerio", "Calimero", "Chant", "Chanted", "Chipper", "Colbolt", "Corin", "Craze", "Dashing", "Demetrius", "Dryade", "Elgar", "Elmas", "Elwyn", "Eos", "Erwin", "Estar", "Euros", "Fernaco", "Garvin", "Giddy", "Gil", "Giulio", "Grace", "Grant", "Gwayne", "Gwyn", "Happy", "Hart", "Helios", "Hesperos", "Iris", "Izar", "Jada", "Jaden", "Jasper", "Jolly", "Joshi", "Julius", "Kaisa", "Kimber", "Knight", "Lance", "Lancelot", "Lanstrom", "Linus", "Lothir", "Majesty", "Marcello", "Marjallo", "Matia", "Mawu", "Meara", "Merry", "Midnight", "Mika", "Milky Way", "Monterya", "Moriba", "Mortus", "Mystery", "Mystic", "Nestor", "Nightwind", "Olwen", "Olwin", "Ozzy", "Perky", "Phaeton", "Placido", "Poseidon", "Prancer", "Rainbow", "Robin", "Roshan", "Rune", "Sable", "Sapphire", "Sigil", "Silly", "Silvesse", "Silvester", "Sly", "Snow", "Snowflake", "Solstice", "Sparkles", "Starburst", "Stardust", "Sterling", "Sunny", "Sunshine", "Titanius", "Tomo", "Tryne", "Twilight", "Twinkle", "Unity", "Virgil", "Wilbur", "Willow", "Wrynn", "Wynn", "Wynstar", "Xavier", "Zane", "Zion"};
    static constexpr std::string_view nm2[] = {"Aalona", "Acorna", "Adiana", "Aerowen", "Agaloa", "Aglaea", "Ainsel", "Alairia", "Alanala", "Albany", "Aletha", "Alice", "Alize", "Allena", "Alona", "Amandaria", "Amara", "Andra", "Angelina", "Annamika", "Arryn", "Astra", "Aura", "Aurae", "Auris", "Aurora", "Baine", "Bellini", "Benicia", "Bennettia", "Biancha", "Blissia", "Bonita", "Brandi", "Breanna", "Breena", "Bryanne", "Bubbles", "Candice", "Carna", "Cassiopeia", "Celeste", "Celestia", "Celina", "Chant", "Chanted", "Chipper", "Cindi", "Claire", "Clare", "Clementine", "Cortesia", "Crystal", "Daisy", "Danika", "Daphne", "Della", "Denali", "Dessa", "Deva", "Drisana", "Dulcea", "Duscha", "Electra", "Elen", "Elita", "Elmas", "Eluna", "Elune", "Elwyn", "Emerald", "Enigma", "Eos", "Eowyn", "Epona", "Estar", "Estrellita", "Etana", "Eternia", "Euros", "Evania", "Fae", "Faith", "Faye", "Felicia", "Fenella", "Fenna", "Fiona", "Fleta", "Floriana", "Gerda", "Giddy", "Gil", "Glamor", "Grace", "Gratiana", "Grizelda", "Gwyn", "Gwynth", "Happy", "Hope", "Hyacinthie", "Hylzarie", "Inara", "Ira", "Irene", "Iris", "Jada", "Jade", "Jaden", "Javiera", "Jewel", "Jolly", "Kaisa", "Kenzie", "Kimber", "Langaria", "Laqueta ", "Larissa", "Leila", "Lily", "Lotus", "Luna", "Lunaria", "Lunette", "Mae", "Majesty", "Marya", "Matia", "Mawu", "Meara", "Merry", "Midnight", "Mika", "Milky Way", "Mona", "Monterya", "Moriba", "Mystery", "Mystic", "Mystique", "Nadira", "Necia", "Nightwind", "Nola", "Opal", "Oracle", "Orielle", "Pearl", "Perky", "Primara", "Rainbow", "Robin", "Roshan", "Ruby", "Rune", "Sable", "Samantha", "Sapphire", "Sassy", "Selena", "Serenity", "Shakti", "Shanna", "Sigil", "Silly", "Silvesse", "Simona", "Snow", "Snowflake", "Solstice", "Sparkles", "Speranza", "Starburst", "Stardust", "Sterling", "Sugar", "Suki", "Sunny", "Sunshine", "Sylvie", "Tacita", "Tama", "Tara", "Trixie", "Tryne", "Twilight", "Twinkle", "Unity", "Valeria", "Wilda", "Willow", "Wynn", "Xaveria", "Xenia", "Yashiana", "Yasmin", "Yennaria", "Yoriara", "Yvonne", "Zane", "Zara"};
    static constexpr std::string_view nm3[] = {"Ainsel", "Arryn", "Auris", "Baine", "Chant", "Chanted", "Chipper", "Elmas", "Elwyn", "Eos", "Estar", "Euros", "Giddy", "Gil", "Grace", "Gwyn", "Happy", "Iris", "Jada", "Jaden", "Jolly", "Kaisa", "Kimber", "Majesty", "Matia", "Mawu", "Meara", "Merry", "Midnight", "Mika", "Milky Way", "Monterya", "Moriba", "Mystery", "Mystic", "Nightwind", "Perky", "Rainbow", "Robin", "Roshan", "Rune", "Sable", "Sapphire", "Sigil", "Silly", "Silvesse", "Snow", "Snowflake", "Solstice", "Sparkles", "Starburst", "Stardust", "Sterling", "Sunny", "Sunshine", "Tryne", "Twilight", "Twinkle", "Unity", "Willow", "Wynn", "Zane"};

    std::string names; size_t rnd = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm2);
    names = nm2[rnd];
    } else if (type == 2) {
    rnd = rng() % std::size(nm3);
    names = nm3[rnd];
    } else {
    rnd = rng() % std::size(nm1);
    names = nm1[rnd];
    }
    return names;
    }
}
