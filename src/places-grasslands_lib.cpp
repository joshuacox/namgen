#include "places-grasslands_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_grasslands_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"White", "Black", "Brown", "Gray", "Majestic", "Pygmy", "Little", "Giant", "Northern", "Southern", "Eastern", "Western", "Greater", "Lesser", "Masked", "Grass", "Water", "Common", "Mountain", "Prairie", "Grassland", "Taiga", "Tundra", "Savanna", "Alpine", "Collared", "Grand", "Pacific", "Oriental", "Spotted", "Speckled", "Striped", "Dotted", "Rusty", "Maned", "Cloud", "Long-tailed", "Short-tailed", "Crowned", "Golden", "Imperial", "Royal", "Noble", "Laughing", "Lined", "Banded", "Snow", "Ivory", "Ebony", "Wild", "Reagal"};
    static constexpr std::string_view names2[] = {"Aardvark", "Alpaca", "Anaconda", "Ant", "Anteater", "Antelope", "Armadillo", "Baboon", "Badger", "Bandicoot", "Bat", "Bear", "Bee", "Beetle", "Bird", "Bison", "Boa", "Buffalo", "Butterfly", "Buzzard", "Caterpillar", "Chipmunk", "Cobra", "Cougar", "Coyote", "Crane", "Cricket", "Crow", "Deer", "Dingo", "Dove", "Duck", "Eagle", "Elephant", "Elk", "Fox", "Frog", "Gazelle", "Grasshopper", "Groundhog", "Hawk", "Hedgehog", "Hyena", "Jackal", "Kangaroo", "Ladybug", "Lion", "Meerkat", "Mouse", "Rabbit", "Rat", "Raven", "Rhino", "Snake", "Toad", "Tortoise", "Warthog", "Wasp", "Weasel", "Wild Dog"};
    static constexpr std::string_view names3[] = {"Grasslands", "Grassland", "Savanna", "Pastures", "Plains", "Prairie", "Steppe", "Range", "Fields", "Meadow", "Gardens", "Terrain", "Territory", "Expanse", "Plateau", "Valley"};
    static constexpr std::string_view names4[] = {"Abandoned", "Awesome", "Beautiful", "Big", "Blooming", "Blossoming", "Broken", "Calm", "Colossal", "Creepy", "Curious", "Deep", "Deserted", "Detailed", "Dramatic", "Dry", "Earthy", "Elegent", "Enchanted", "Exclusive", "Faint", "Fancy", "Free", "Gentle", "Giant", "Gigantic", "Glistening", "Glorious", "Gorgeous", "Green", "Groovy", "Healthy", "Heavenly", "High", "Hissing", "Hollow", "Huge", "Incredible", "Jaded", "Jagged", "Light", "Little", "Lively", "Lonely", "Luscious", "Lush", "Magical", "Magnificent", "Majestic", "Mammoth", "Marvelous", "Massive", "Mellow", "Mighty", "Misty", "Moldy", "Mysterious", "Narrow", "Old", "Panoramic", "Parallel", "Peaceful", "Plain", "Pleasant", "Precious", "Private", "Quiet", "Rainy", "Reflecting", "Romantic", "Rotten", "Round", "Royal", "Sacred", "Scattered", "Secret", "Shimmering", "Sickly", "Simple", "Special", "Spectacular", "Spiritual", "Stormy", "Teeny", "Terrible", "Terrific", "Thick", "Thin", "Thundering", "Tiny", "Unknown", "Violent", "Violet", "Wandering", "Whimsical", "Whispering", "Wicked", "Wild", "Windy", "Young"};
    static constexpr std::string_view names5[] = {"b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z", "", "", "", "", ""};
    static constexpr std::string_view names6[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view names7[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "", "", "", "", "", ""};
    static constexpr std::string_view names8[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view names9[] = {"b", "d", "g", "gh", "h", "hr", "hs", "ht", "hst", "hsh", "hn", "hm", "hl", "hz", "hx", "hq", "k", "ks", "kx", "l", "ll", "lk", "ln", "lm", "lz", "lp", "lt", "ls", "lst", "lf", "m", "mn", "mm", "mt", "ms", "n", "nn", "nt", "ns", "p", "ps", "pt", "ph", "q", "r", "rs", "rt", "rst", "rq", "rk", "rc", "rf", "rb", "rd", "s", "st", "ss", "sh", "sk", "sp", "t", "th", "ts", "w", "wth", "x", "z"};

    std::string names; size_t rnd0 = 0; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (i < 4) {
    rnd0 = rng() % std::size(names1);
    rnd1 = rng() % std::size(names2);
    rnd2 = rng() % std::size(names3);
    names = names1[rnd0] + " " + names2[rnd1] + " " + names3[rnd2];
    } else if (i < 7) {
    rnd0 = rng() % std::size(names3);
    rnd1 = rng() % std::size(names4);
    names = names4[rnd1] + " " + names3[rnd0];
    } else {
    rnd0 = rng() % std::size(names5);
    rnd1 = rng() % std::size(names6);
    rnd2 = rng() % std::size(names7);
    rnd3 = rng() % std::size(names8);
    rnd4 = rng() % std::size(names9);
    rnd5 = rng() % std::size(names3);
    names = names5[rnd0] + names6[rnd1] + names7[rnd2] + names8[rnd3] + names9[rnd4] + " " + names3[rnd5];
    }
    return names;
    }
}
