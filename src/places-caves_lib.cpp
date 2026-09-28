#include "places-caves_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_caves_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Abysmal", "Adamantine", "Ancient", "Angry", "Arching", "Arctic", "Arid", "Bare", "Beholding", "Bellowing", "Black", "Bleak", "Blue", "Boiling", "Bottomless", "Boundless", "Brilliant", "Bronze", "Burned", "Burning", "Calm", "Calmest", "Charmed", "Cheerless", "Climbing", "Cobalt", "Cold", "Collapsing", "Colorless", "Colossal", "Coral", "Crystal", "Cunning", "Cursed", "Dancing", "Dangerous", "Dark", "Darkest", "Dead", "Decayed", "Decaying", "Deep", "Deepest", "Dense", "Depraved", "Deserted", "Desolate", "Desolated", "Diamond", "Distant", "Dread", "Dreaded", "Dreadful", "Dreary", "Dry", "Eastern", "Emerald", "Empty", "Enchanted", "Enormous", "Eroded", "Ethereal", "Ever Reaching", "Everlasting", "Fabled", "Faraway", "Farthest", "Feared", "Fearsome", "Fiery", "Flaring", "Flat", "Flowing", "Foaming", "Forbidden", "Forbidding", "Fractured", "Frightening", "Frozen", "Gargantuan", "Giant", "Gigantic", "Glassy", "Gleaming", "Glistening", "Gloomy", "Glowing", "Gold", "Golden", "Grave", "Gray", "Green", "Grim", "Harmonious", "Haunted", "Heaving", "Hellish", "Hollow", "Homeless", "Hopeless", "Hot", "Huge", "Humongous", "Hungry", "Immense", "Infernal", "Infinite", "Invisible", "Iron", "Isolated", "Jade", "Jagged", "Killing", "Laughing", "Lifeless", "Light", "Lightest", "Living", "Lonely", "Lucent", "Majestic", "Malevolent", "Malicious", "Mammoth", "Mesmerizing", "Mighty", "Mirrored", "Misty", "Moaning", "Molten", "Monotonous", "Monstrous", "Motionless", "Mysterious", "Narrow", "Neverending", "New", "Northern", "Open", "Orient", "Overhanging", "Parched", "Peaceful", "Perfumed", "Plain", "Pleasant", "Prickly", "Primeval", "Quiet", "Raging", "Red", "Relentless", "Remote", "Restless", "Rocking", "Rocky", "Rough", "Rugged", "Sad", "Sandy", "Sanguine", "Savage", "Scarlet", "Scorching", "Serene", "Severed", "Shadow", "Shadowed", "Shadowy", "Shimmering", "Silent", "Silver", "Sleeping", "Slumbering", "Slumbrous", "Sly", "Soundless", "Southern", "Spacious", "Sparkling", "Sterile", "Stern", "Straitened", "Sunny", "Symmetrical", "Teal", "Terraced", "Terrestrial", "Throbbing", "Thundering", "Tinted", "Titanic", "Tranquil", "Treacherous", "Troubled", "Turbulent", "Turquoise", "Twisting", "Ugly", "Uncanny", "Unfathomed", "Uninviting", "Unknown", "Unresting", "Unruffled", "Unscaled", "Unstable", "Unwelcoming", "Vast", "Violent", "Voiceless", "Volcanic", "Walled", "Wasted", "Wasteful", "Wasting", "Welcoming", "Western", "Whelming", "Whispering", "White", "Wild", "Windless", "Windy", "Withered", "Wondering", "Wrinkled", "Yearning", "Yelling", "Yellow"};
    static constexpr std::string_view nm2[] = {"Cave", "Cavern", "Grotto", "Den", "Cavity", "Hollow", "Hollows", "Caves", "Caverns", "Hole", "Hideout", "Shelter", "Overhang", "Sanctuary", "Subterrane"};
    static constexpr std::string_view nm3[] = {"b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z", "", "", "", "", ""};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm5[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "", "", "", "", "", ""};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm7[] = {"b", "d", "g", "gh", "h", "hr", "hs", "ht", "hst", "hsh", "hn", "hm", "hl", "hz", "hx", "hq", "k", "ks", "kx", "l", "ll", "lk", "ln", "lm", "lz", "lp", "lt", "ls", "lst", "lf", "m", "mn", "mm", "mt", "ms", "n", "nn", "nt", "ns", "p", "ps", "pt", "ph", "q", "r", "rs", "rt", "rst", "rq", "rk", "rc", "rf", "rb", "rd", "s", "st", "ss", "sh", "sk", "sp", "t", "th", "ts", "w", "wth", "x", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm2);
    if (i < 4) {
    rnd = rng() % std::size(nm1);
    names = "The " + nm1[rnd] + " " + nm2[rnd2];
    } else if (i < 7) {
    rnd = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm7);
    names = nm3[rnd] + nm4[rnd3] + nm7[rnd4] + " " + nm2[rnd2];
    } else {
    rnd = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    names = nm3[rnd] + nm4[rnd3] + nm5[rnd4] + nm6[rnd5] + nm7[rnd6] + " " + nm2[rnd2];
    }
    return names;
    }
}
