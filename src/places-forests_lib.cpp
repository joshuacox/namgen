#include "places-forests_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_forests_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"White", "Black", "Brown", "Gray", "Majestic", "Pygmy", "Little", "Giant", "Northern", "Southern", "Eastern", "Western", "Greater", "Lesser", "Masked", "Grass", "Water", "Common", "Mountain", "Prairie", "Grassland", "Taiga", "Tundra", "Savanna", "Alpine", "Collared", "Grand", "Pacific", "Oriental", "Spotted", "Speckled", "Striped", "Dotted", "Rusty", "Maned", "Cloud", "Long-tailed", "Short-tailed", "Crowned", "Golden", "Imperial", "Royal", "Noble", "Laughing", "Lined", "Banded", "Snow", "Ivory", "Ebony", "Wild", "Reagal"};
    static constexpr std::string_view nm2[] = {"Panda", "Gerbil", "Hare", "Hedgehog", "Jackal", "Warthog", "Coyote", "Cat", "Badger", "Hyena", "Jaguar", "Gorilla", "Sloth", "Anteater", "Ocelot", "Lion", "Porcupine", "Beaver", "Otter", "Ant", "Bandicoot", "Crocodile", "Alligator", "Treefrog", "Wolverine", "Goat", "Spider", "Mouse", "Snail", "Crab", "Deer", "Fox", "Lizard", "Toad", "Mole", "Turtle", "Frog", "Squirrel", "Tortoise", "Gazelle", "Panther", "Bear", "Rat", "Lynx", "Okapi", "Leopard", "Tiger", "Wolf", "Rhino", "Wallaby", "Yak", "Pelican", "Swallow", "Duck", "Eagle", "Hawk", "Falcon", "Vulture", "Sunbird", "Macaw", "Woodpecker", "Kingfisher", "Hummingbird", "Pygmy Owl", "Sandpiper", "Mockingbird"};
    static constexpr std::string_view nm3[] = {"Forest", "Grove", "Woods", "Covert", "Woodland", "Thicket", "Forest", "Grove", "Woods", "Covert", "Woodland", "Wilds", "Wood", "Wood", "Timberland", "Timberland"};
    static constexpr std::string_view nm4[] = {"Calm", "Sacred", "Massive", "Huge", "Teeny", "Tiny", "Puny", "Mammoth", "Gigantic", "Colossal", "Big", "Faint", "Hissing", "Quiet", "Thundering", "Whispering", "Beautiful", "Fancy", "Magnificent", "Mysterious", "Old", "Broken", "Creepy", "Abandoned", "Light", "Earthy", "Elegent", "Deep", "Enchanted", "Detailed", "Deserted", "Exclusive", "Dramatic", "Curious", "Awesome", "Jaded", "Jagged", "Incredible", "Healthy", "Heavenly", "High", "Hollow", "Huge", "Gentle", "Giant", "Glistening", "Glorious", "Gorgeous", "Groovy", "Free", "Frightened", "Frightening", "Little", "Lively", "Lonely", "Lush", "Magical", "Majestic", "Marvelous", "Mellow", "Mighty", "Misty", "Moldy", "Narrow", "Oceanic", "Quiet", "Panoramic", "Parallel", "Peaceful", "Plain", "Pleasant", "Precious", "Private", "Rainy", "Reflecting", "Romantic", "Rotten", "Royal", "Terrible", "Terrific", "Thick", "Thin", "Threatening", "Towering", "Scattered", "Secret", "Sickly", "Dark", "Shadow", "Simple", "Special", "Spectacular", "Spiritual", "Square", "Round", "Triangular", "Stormy", "Young", "Wandering", "Whimsical", "Wicked", "Wild", "Windy", "Wise", "Wretched", "Venomous", "Violent", "Violet", "Unknown", "Alien"};
    static constexpr std::string_view nm5[] = {"Jolly", "Broad", "Brass", "Copper", "Golden", "Silver", "Bronze", "Massive", "Huge", "Teeny", "Tiny", "Puny", "Mammoth", "Gigantic", "Colossal", "Big", "Quiet", "Thundering", "Whispering", "Ancient", "Beautiful", "Fancy", "Magnificent", "Mysterious", "Old", "Short", "Heavy", "Light", "Elegent", "Enchanted", "Exclusive", "Exotic", "Dramatic", "Curious", "Aromatic", "Awesome", "Imaginary", "Incredible", "Healthy", "Heavenly", "Hollow", "Huge", "Hypnotic", "Gentle", "Giant", "Glistening", "Glorious", "Goofy", "Gorgeous", "Greasy", "Groovy", "Gruesome", "Fabulous", "Faded", "False", "Familiar", "Fancy", "Fantastic", "Fascinating", "Foolish", "Fragile", "Free", "Frightened", "Frightening", "Last", "Little", "Lonely", "Lush", "Magical", "Majestic", "Mellow", "Mighty", "Misty", "Minor", "Misty", "Moldy", "Naive", "Narrow", "Nonstalgic", "Quiet", "Peaceful", "Plain", "Pleasant", "Precious", "Private", "Rare", "Regular", "Reflecting", "Royal", "Tall", "Terrific", "Thick", "Thin", "Threatening", "Tired", "Towering", "Scattered", "Secret", "Shaggy", "Sickly", "Simple", "Sleepy", "Special", "Spectacular", "Spotless", "Spotted", "Stormy", "Young", "Waiting", "Wandering", "Whimsical", "Wicked", "Wild", "Windy", "Wise", "Wretched", "Violet", "Unique", "Unknown", "Unnatural", "Alien"};
    static constexpr std::string_view nm6[] = {"Alder", "Ash", "Ash", "Ash", "Beech", "Birch", "Birch", "Birch", "Bladdernut", "Buckeye", "Cedar", "Chestnut", "Cypress", "Devilwood", "Dogwood", "Elderberry", "Elm", "Fir", "Harlequin", "Hemlock", "Hickory", "Holly", "Ironwood", "Jacktree", "Juniper", "Linden", "Locust", "Magnolia", "Maple", "Maple", "Maple", "Maple", "Musclewood", "Oak", "Oak", "Oak", "Oak", "Olive", "Palm", "Pawpaw", "Peach", "Pine", "Pine", "Pine", "Pine", "Apple", "Raspberry", "Plum", "Poplar", "Redbud", "Redwood", "Redwood", "Silverbell", "Spruce", "Spruce", "Spruce", "Spruce", "Sumac", "Tupelo", "Walnut", "Willow", "Willow", "Willow", "Willow", "Hazulnut", "Blueberry", "Chestnut", "Blackberry", "Butternut", "Pecan", "River", "Lake", "Wetland", "Stream", "Creek", "Brook", "Rivulet", "Basin", "Lagoon", "Loch", "Pond", "Spring", "Reservoir", "Basin", "Marsh", "Quagmire", "Swampland", "Bog", "Clearing", "Glade", "Field", "Hill", "Garden", "Range", "Territory", "Meadow", "Mead", "Grassland", "Bluff", "Cliff", "Highland", "Knoll", "Mound", "Mount", "Thorn"};
    static constexpr std::string_view nm7[] = {"b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z", "", "", "", "", ""};
    static constexpr std::string_view nm8[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm9[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "", "", "", "", "", ""};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm11[] = {"b", "d", "g", "gh", "h", "hr", "hs", "ht", "hst", "hsh", "hn", "hm", "hl", "hz", "hx", "hq", "k", "ks", "kx", "l", "ll", "lk", "ln", "lm", "lz", "lp", "lt", "ls", "lst", "lf", "m", "mn", "mm", "mt", "ms", "n", "nn", "nt", "ns", "p", "ps", "pt", "ph", "q", "r", "rs", "rt", "rst", "rq", "rk", "rc", "rf", "rb", "rd", "s", "st", "ss", "sh", "sk", "sp", "t", "th", "ts", "w", "wth", "x", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd3b = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    rnd3 = rng() % std::size(nm3);
    if (i < 2) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    names = nm5[rnd] + " " + nm6[rnd2] + " " + nm3[rnd3];
    } else if (i < 4) {
    rnd = rng() % std::size(nm4);
    names = nm4[rnd] + " " + nm3[rnd3];
    } else if (i < 6) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + " " + nm2[rnd2] + " " + nm3[rnd3];
    } else if (i < 8) {
    rnd = rng() % std::size(nm7);
    rnd2 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm11);
    names = nm7[rnd] + nm8[rnd2] + nm11[rnd4] + " " + nm3[rnd3];
    } else {
    rnd = rng() % std::size(nm7);
    rnd2 = rng() % std::size(nm8);
    rnd3b = rng() % std::size(nm9);
    rnd4 = rng() % std::size(nm10);
    rnd5 = rng() % std::size(nm11);
    names = nm7[rnd] + nm8[rnd2] + nm9[rnd3b] + nm10[rnd4] + nm11[rnd5] + " " + nm3[rnd3];
    }
    return names;
    }
}
