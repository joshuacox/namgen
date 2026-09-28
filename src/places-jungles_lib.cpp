#include "places-jungles_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_jungles_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Anaconda", "Ancient", "Angry", "Baboon", "Bellowing", "Bird of Paradise", "Black", "Black Elephant", "Black Panther", "Black Rhino", "Blazing", "Bloodthirsty", "Broken", "Brutal", "Burning", "Bustling", "Calm", "Calming", "Cougar", "Crocodile", "Cursed", "Dancing Bird", "Dark", "Dead", "Diamond", "Distant", "Eastern", "Ebon", "Elephant", "Elephant Tusk", "Emerald", "Emperor", "Empty", "Enchanted", "Ever Reaching", "Expanding", "Fabled", "Faraway", "Feared", "Fearsome", "Feral", "Ferocious", "Flower", "Forbidden", "Furious", "Gentle", "Giant", "Gloomy", "Golden", "Greedy", "Grim", "Growing", "Growling", "Guardian", "Haunted", "Hidden", "Hollow", "Hopeless", "Howling", "Hungry", "Infernal", "Ivory", "Laughing", "Lemur", "Lifeless", "Lioness", "Lionroar", "Lonely", "Lunar", "Macaw", "Mighty", "Mirrored", "Misty", "Moaning", "Moonlit", "Moving", "Mumbling", "Mysterious", "Narrow", "Neverending", "Northern", "Ocelot", "Orangutan", "Peaceful", "Plain", "Playful", "Predator", "Preying", "Primate", "Primeval", "Pristine", "Pygmy", "Quiet", "Raging", "Rainy", "Red", "Restless", "Rising", "Roaring", "Royal Lion", "Rugged", "Sacred", "Sad", "Sanguine", "Savage", "Scarlet", "Scented", "Scrambling", "Screaming", "Serpent", "Severed", "Shadowed", "Shimmering", "Sighing", "Silent", "Silver", "Silverback", "Sleeping", "Slumbering", "Snaketail", "Soft", "Solar", "Southern", "Spider", "Spider Monkey", "Sterile", "Storm", "Stormy", "Tempest", "Thirsty", "Thornbush", "Thunder", "Thundering", "Thunderstorm", "Tigerpaw", "Tigress", "Timeless", "Titan", "Toucan", "Towering", "Treachorous", "Turbulent", "Venomous", "Vicious", "Violent", "Voiceless", "Volcanic", "Wailing", "Waking", "Watching", "Western", "Wet", "Whimpering", "Whining", "Whispering", "White", "White Elephant", "White Lion", "White Parrot", "White Tiger", "Wild", "Windless", "Windy"};
    static constexpr std::string_view names2[] = {"Jungle", "Rain Forest", "Bush", "Tropics", "Gardens", "Wilds", "Wilderness", "Wild", "Jungles", "Garden", "Paradise"};
    static constexpr std::string_view names3[] = {"b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z", "", "", "", "", ""};
    static constexpr std::string_view names4[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view names5[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "", "", "", "", "", ""};
    static constexpr std::string_view names6[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view names7[] = {"b", "d", "g", "gh", "h", "hr", "hs", "ht", "hst", "hsh", "hn", "hm", "hl", "hz", "hx", "hq", "k", "ks", "kx", "l", "ll", "lk", "ln", "lm", "lz", "lp", "lt", "ls", "lst", "lf", "m", "mn", "mm", "mt", "ms", "n", "nn", "nt", "ns", "p", "ps", "pt", "ph", "q", "r", "rs", "rt", "rst", "rq", "rk", "rc", "rf", "rb", "rd", "s", "st", "ss", "sh", "sk", "sp", "t", "th", "ts", "w", "wth", "x", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (i < 6) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = "The " + names1[rnd] + " " + names2[rnd2];
    return names;
    } else if (i < 8) {
    rnd = rng() % std::size(names3);
    rnd2 = rng() % std::size(names4);
    rnd3 = rng() % std::size(names7);
    rnd4 = rng() % std::size(names2);
    names = names3[rnd] + names4[rnd2] + names7[rnd3] + " " + names2[rnd4];
    return names;
    } else {
    rnd = rng() % std::size(names3);
    rnd2 = rng() % std::size(names4);
    rnd3 = rng() % std::size(names5);
    rnd4 = rng() % std::size(names6);
    rnd5 = rng() % std::size(names7);
    rnd6 = rng() % std::size(names2);
    names = names3[rnd] + names4[rnd2] + names5[rnd3] + names6[rnd4] + names7[rnd5] + " " + names2[rnd6];
    return names;
    }
    }
}
