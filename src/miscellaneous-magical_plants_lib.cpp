#include "miscellaneous-magical_plants_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_magical_plants_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Abyss", "Aching", "Ancestor", "Angel", "Angel's", "Anxious", "Aquatic", "Arching", "Arctic", "Aromatic", "Ash", "Ashen", "Assassin", "Banshee", "Barbed", "Barren", "Bitter", "Black", "Bleak", "Bleeding", "Blessed", "Blight", "Blister", "Blood", "Blue", "Bone", "Boomerang", "Bouncing", "Bright", "Bronze", "Candy", "Canis", "Cave", "Chameleon", "Chilling", "Cliff", "Cold", "Corrupt", "Corrupted", "Corrupting", "Coughing", "Crawling", "Creeping", "Creepy", "Crimson", "Curse", "Dancing", "Dawn", "Daydream", "Dead", "Deadly", "Death", "Death's", "Delicious", "Demon", "Demon's", "Devil's", "Dim", "Dire", "Dragon", "Dragon's", "Dream", "Drifting", "Drowsy", "Dusk", "Dwarf", "Dwarven", "Eagle", "Echo", "Elven", "Emperor", "Fake", "Fanged", "Fatigue", "Fear", "Fearful", "Fever", "Fire", "Fjord", "Flying", "Fragrant", "Frost", "Frozen", "Funeral", "Funky", "Ghost", "Giant", "Glacier", "Glow", "Glowing", "Golden", "Grand", "Grave", "Gray", "Green", "Grim", "Grumpy", "Hammer", "Hanging", "Happy", "Harmless", "Hate", "Heart", "Heart's", "Hidden", "Hollow", "Horned", "Hot", "Hovering", "Humble", "Ice", "Imp", "Imperial", "Infecting", "Inferno", "Invisible", "Island", "Itching", "Jealous", "Jester", "Joyful", "King's", "Knight's", "Lethal", "Life's", "Lion", "Love", "Lunar", "Mage's", "Majestic", "Mammoth", "Marsh", "Master", "Mercy's", "Mimic", "Miracle", "Mock", "Mocking", "Monk's", "Moon", "Mound", "Mountain", "Nasty", "Naughty", "Nervous", "Night", "Nightmare", "Nordic", "Noxious", "Ocean", "Orange", "Orcish", "Ordinary", "Perfumed", "Pest", "Phantom", "Phoenix", "Pink", "Pipe", "Piranha", "Pixy", "Plague", "Pleasant", "Poisonous", "Prancing", "Putrid", "Pygmy", "Queen's", "Quiet", "Rare", "Rash", "Raven", "Red", "Regal", "Restoration", "River", "Rock", "Rotten", "Royal", "Sacred", "Sad", "Salty", "Sanguine", "Savage", "Scented", "Screaming", "Sentient", "Serpent", "Shadow", "Shield", "Shocking", "Shrine", "Shy", "Silent", "Silver", "Skeletal", "Skulking", "Skull", "Sleeping", "Sleepy", "Smelly", "Smooth", "Sneeze", "Sneezing", "Snow", "Solar", "Sore", "Sour", "Spicy", "Spider", "Spiky", "Spirit", "Spitfire", "Star", "Stink", "Stinking", "Sugar", "Sun", "Sunny", "Swamp", "Sweet", "Tall", "Tangle", "Tangled", "Taunting", "Tear", "Tickle", "Tiny", "Toxic", "Tube", "Tundra", "Twilight", "Twin", "Twisted", "Urban", "Venomous", "Vision", "Void", "Volcano", "Walking", "Warm", "Weeping", "Whisper", "White", "Whomping", "Wicked", "Wild", "Wisdom", "Wolf", "Yellow"};
    static constexpr std::string_view nm2[] = {"Aconite", "Ambrosia", "Annie", "Azolla", "Bamboo", "Bean", "Bearberry", "Belladonna", "Berry", "Betty", "Bindweed", "Bite", "Bittercress", "Bittersweet", "Bitterweed", "Blade", "Bloom", "Bower", "Buxus", "Boxwood", "Brier", "Brittlebush", "Broadleaf", "Bush", "Buttons", "Cabbage", "Cane", "Cap", "Clove", "Clover", "Collard", "Colwort", "Coneflower", "Cornel", "Cotton", "Cress", "Daisy", "Deadnettle", "Dewberry", "Dindle", "Dogbane", "Duscle", "Fairymoss", "Felonwood", "Felonwort", "Fennel", "Fern", "Feverfew", "Fieldcress", "Fig", "Flax", "Flower", "Fluxroot", "Fumewort", "Gallberry", "Garget", "Garlic", "Geranium", "Gilliflower", "Ginger", "Goldenglow", "Grapevine", "Grass", "Groundberry", "Gutweed", "Hair", "Haldi", "Harlequin", "Hedge", "Hellebore", "Hemp", "Hibiscus", "Hogweed", "Holly", "Hops", "Horse Nettle", "Houseleek", "Huckleberry", "Ink Plant", "Inkberry", "Itchweed", "Ivy", "Jack-in-the-Bush", "Joy", "Juniper", "Laceflower", "Laurel", "Lavender", "Lilac", "Lily", "Lotus", "Milfoil", "Milkweed", "Mint", "Morel", "Moss", "Mulberry", "Needle", "Nettle", "Nightshade", "Parsley", "Parsnip", "Pea", "Pepper", "Pine", "Plant", "Poinsetta", "Poisonberry", "Poisonflower", "Poke", "Pokeroot", "Pokeweed", "Polkweed", "Poppy", "Pudina", "Ragweed", "Rantipole", "Raspberry", "Ribwort", "Roadweed", "Rock Fern", "Root", "Rose", "Rosemary", "Rye", "Saffron", "Sage", "Sanguinary", "Shadblow", "Shadbush", "Silkweed", "Skunkweed", "Snakeberry", "Snowdrop", "Sorrel", "Spoolwood", "Stammerwort", "Stickweed", "Sugarcane", "Sugarplum", "Sunflower", "Swallow-wort", "Swinies", "Tansy", "Tassel", "Tea", "Thimbleberry", "Thimbleweed", "Thistle", "Thorn", "Thousand-leaf", "Thyme", "Tongue", "Toothwort", "Touch-me-not", "Tulip", "Tulsi", "Vine", "Violet", "Waybread", "Weed", "Wheat", "Wild Rose", "Windroot", "Wineberry", "Winterberry", "Wintercress", "Woodbine", "Wormwood", "Woundwort"};
    static constexpr std::string_view nm3[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ea", "ei", "eo", "ae", "ai", "ia", "io", "ua", "aa", "ee", "oo", "ou", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm4[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "x", "y", "z", "bl", "br", "ch", "chr", "cl", "cr", "dl", "dr", "fl", "fr", "fy", "gl", "gr", "kl", "kn", "kr", "ph", "phr", "pl", "pr", "sc", "sh", "shr", "sl", "sm", "sn", "sp", "sr", "str", "th", "thr", "tr", "vl"};
    static constexpr std::string_view nm5[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ea", "ei", "eo", "ae", "ai", "ia", "io", "ua", "aa", "ee", "oo", "ou"};
    static constexpr std::string_view nm6[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "bb", "bd", "bg", "bl", "br", "bs", "cc", "ch", "chr", "cl", "cr", "dd", "df", "dg", "dl", "dr", "ds", "dt", "fd", "ff", "fg", "fl", "fm", "fn", "fp", "fr", "fy", "gd", "gg", "ght", "gl", "gr", "gth", "hh", "hl", "hm", "hn", "hs", "ht", "kd", "kk", "kl", "km", "kn", "kr", "lb", "ld", "lf", "lg", "lk", "ll", "lm", "ln", "lp", "ls", "lt", "ly", "mb", "md", "mf", "mk", "ml", "mm", "mn", "mp", "ms", "my", "nc", "nd", "nf", "ng", "nk", "nl", "nm", "nn", "np", "ns", "nt", "ny", "ph", "phr", "pl", "pp", "pr", "ql", "qr", "qs", "rc", "rd", "rf", "rg", "rh", "rk", "rl", "rm", "rn", "rp", "rr", "rs", "rsh", "rt", "rth", "rw", "sb", "sc", "sd", "sf", "sg", "sh", "shr", "sk", "sl", "sm", "sn", "sp", "sr", "ss", "st", "str", "sw", "sy", "th", "thr", "tr", "tt", "vl", "zh", "zl", "zr", "zz"};
    static constexpr std::string_view nm7[] = {"b", "bb", "c", "cc", "d", "dd", "f", "ff", "g", "gg", "h", "j", "k", "kk", "l", "ll", "m", "mm", "n", "nn", "p", "pp", "r", "rr", "s", "ss", "t", "tt", "v", "w", "x", "xx", "y", "z", "zz"};
    static constexpr std::string_view nm8[] = {"ac", "ade", "age", "aire", "aisy", "alda", "amire", "ane", "anium", "anor", "ard", "ary", "asse", "ax", "ead", "eaf", "ebore", "edil", "eed", "eek", "eet", "egon", "el", "elas", "elda", "ender", "equin", "erry", "ess", "et", "etta", "ettle", "etty", "ianna", "ie", "ier", "ies", "ina", "ine", "inque", "ip", "iper", "ire", "irin", "iscus", "ite", "ium", "oil", "ole", "olla", "on", "onna", "ons", "oo", "ood", "oom", "oot", "ore", "orn", "ort", "os", "osie", "oss", "osse", "otus", "ove", "over", "ow", "ower", "uin", "um", "us", "ush"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + " " + nm2[rnd2];
    } else if (i < 7) {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm8);
    names = nm3[rnd] + nm4[rnd2] + nm8[rnd3];
    } else if (i < 9) {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    if (rnd > 9) {
    while (rnd3 > 9) {
    rnd3 = rng() % std::size(nm5);
    }
    }
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    names = nm3[rnd] + nm4[rnd2] + nm5[rnd3] + nm6[rnd4] + nm8[rnd5];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    if (rnd > 9) {
    while (rnd3 > 9) {
    rnd3 = rng() % std::size(nm5);
    }
    }
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm5);
    if (rnd3 > 9 || rnd > 9) {
    while (rnd5 > 9) {
    rnd5 = rng() % std::size(nm5);
    }
    }
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm8);
    names = nm3[rnd] + nm4[rnd2] + nm5[rnd3] + nm6[rnd4] + nm5[rnd5] + nm7[rnd6] + nm8[rnd7];
    }
    return names;
    }
}
