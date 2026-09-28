#include "descriptions-holidays_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_holidays_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"year", "2 years", "9 months", "6 months", "4 months"};
    static constexpr std::string_view nm2[] = {"Age", "All Souls", "Ancestors", "Animals", "Art", "Ashes", "Asteroids", "Auras", "Auroras", "Awe", "Baking", "Ballet", "Beer", "Birds", "Birth", "Bliss", "Blossoms", "Books", "Bounties", "Brass", "Bravery", "Bread", "Brewing", "Brews", "Candles", "Candy", "Carnival", "Cats", "Champions", "Cheese", "Chickens", "Children", "Chocolate", "Clouds", "Color", "Comets", "Communities", "Competition", "Construction", "Coronations", "Cows", "Creativity", "Culinary Arts", "Culture", "Dance", "Darkness", "Death", "Diversity", "Dogs", "Dragons", "Dreams", "Earth", "Elders", "Embers", "Enlightenment", "Fairies", "Faith", "Falling Stars", "Families", "Farming", "Fear", "Fertility", "Film", "Fire", "Fireworks", "Fish", "Flames", "Flight", "Flowers", "Folklore", "Food", "Forests", "Friends", "Friendship", "Fruits", "Games", "Generosity", "Ghosts", "Gods", "Grandeur", "Happiness", "Harmony", "Harvests", "Heroes", "Honey", "Hope", "Horses", "Hospitality", "Hymns", "Ice", "Ice and Snow", "Independence", "Insects", "Joy", "Lakes", "Languages", "Lanterns", "Laughter", "Life", "Light", "Lights", "Literature", "Love", "Luminescence", "Magic", "Meat", "Melodies", "Merchants", "Miracles", "Mirrors", "Mountains", "Music", "Names", "Nations", "Nature", "New Life", "Nightfall", "Nights", "Oceans", "Paint", "Parents", "Parks", "Peace", "Petals", "Pigs", "Planting", "Prophets", "Prosperity", "Rainbows", "Recreation", "Reflection", "Reincarnation", "Relaxation", "Remembrance", "Respect", "Rest", "Restoration", "Rivers", "Seafood", "Seeds", "Serenity", "Shadows", "Silence", "Sleep", "Snow", "Solidarity", "Solstices", "Sound", "Spirits", "Sports", "Strangers", "Strength", "Sugar", "Superstitions", "Taverns", "Technology", "Time", "Titans", "Trade", "Tranquility", "Trees", "Truth", "Unity", "Victory", "Voices", "Warmth", "Water", "Waves", "Whispers", "Wine", "Wonders", "Wood", "Worship", "Writing", "Youth"};
    static constexpr std::string_view nm3[] = {"great pleasure", "much enthusiasm", "great participation", "a lot of anticipation", "pure delight", "enchanted hearts", "much gratification", "a lot of gusto", "great expectations", "many preparations", "high hopes", "eager participation", "a lot of fascination", "much bewilderment", "excited hearts", "awe and wonder", "much creativity", "big imaginations", "grandeur", "much joy"};
    static constexpr std::string_view nm4[] = {"age-old", "ancient", "archaic", "distant", "divine", "fairly modern", "long established", "long-lived", "mysterious", "mystical", "mythical", "relatively young", "religious", "seemingly ancient", "spiritual", "time lost", "time-honored", "undiscovered", "unknown", "untold"};
    static constexpr std::string_view nm5[] = {"acts of courage", "athletic competitions", "bonding with family", "bonding with friends", "celebrating imagination", "charitable donations", "colorful lights", "coming of age rituals", "costumed mascots", "creating charity gift baskets", "creation of art", "dance parties", "decorating homes", "decorating the streets", "exchanging gifts", "face painting", "fireworks", "forgiving others", "gag gifts", "games of chance", "giving compliments", "going out for dinner", "group games", "hanging around campfires", "helping strangers", "helping those in need", "holiday meals", "holiday related drinks", "holiday themed sports games", "holiday treats", "homemade costumes", "homemade gifts", "homemade holiday decorations", "hot beverages", "humility", "kindness for others", "lighting candles", "love and romance", "marriage proposals", "neighborhood parties", "night walks", "outdoor food parties", "parades", "playing board games", "playing instruments", "playing pranks", "playing with pets", "preparing big feasts", "preparing holiday themed foods", "random acts of kindness", "rights of passage", "romantic gestures", "scavenger hunts", "secret gift giving", "seeing holiday movies", "self discovery", "singing songs", "skill-based contests", "spirituality", "telling jokes", "telling of stories", "togetherness", "traditional clothing", "traditional dances", "traditional hair styling", "traditional plays", "truth and dare games", "watching a natural phenomena", "watching special shows", "wearing homemade costumes"};
    static constexpr std::string_view nm6[] = {"one day", "two days", "three days", "four days", "five days", "six days", "1 week", "eight days", "nine days", "ten days", "eleven days", "twelve days", "thirteen days", "2 weeks", "1 week", "2 weeks"};
    static constexpr std::string_view nm7[] = {"decorations and festivities are often found well before and after that time as well", "decorations are often found well before and after that time as well", "it often continues well after that time as well", "festivities often start earlier than that as well", "the final half is often celebrated more strongly and looked forward to the most", "the first half is often celebrated more strongly and looked forward to the most", "the periods before and after that time are so festive it may as well be 4 weeks long", "the final celebrations often lasts deep into the night and even into the next day", "decorations often stay around for weeks after the celebrations", "decorations are often seen weeks before the actual celebrations", "a generally festive atmosphere continues to fill the streets for weeks after the celebrations", "it can be both shorter and longer, depending on personal preferences", "enthusiastic people often celebrate it for a few days more by starting earlier", "a strong sense of community often gets people to celebrate it for a few days more", "the final hours are by far the most intense and the most beloved hours", "the opening hours are by far the most beloved hours and looked forward to by all", "the opening ceremony is often the part with the most participation", "the closing celebrations are what everybody looks forward to the most", "it's not until the second half that celebrations really go all out", "the climax of the celebrations are in the final hours and is what everybody looks forward to", "another holiday starts soon after this one ends, resulting in a much longer period of festivities", "this holiday ties in closely with another, so festivities continue for a much longer time", "preparations often start weeks before, so many decorations can be seen much earlier", "there's a long period of joy and satisfaction after the celebrations, adding to the festive atmosphere", "many people will celebrate it longer by starting earlier and ending later"};

    std::string name; std::string name2; std::string name3; std::string result; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5a = 0; size_t rnd5b = 0; size_t rnd5c = 0; size_t rnd5d = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

    result = "";
    for (i = 0; i < 3; i++) {
    rnd1 = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5a = rng() % std::size(nm5);
    rnd5b = rng() % std::size(nm5);
    while (rnd5a == rnd5b) {
    rnd5b = rng() % std::size(nm5);
    }
    rnd5c = rng() % std::size(nm5);
    while (rnd5a == rnd5c || rnd5b == rnd5c) {
    rnd5c = rng() % std::size(nm5);
    }
    rnd5d = rng() % std::size(nm5);
    while (rnd5a == rnd5d || rnd5b == rnd5d || rnd5c == rnd5d) {
    rnd5d = rng() % std::size(nm5);
    }
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    name = "Every " + nm1[rnd1] + " the Festival of " + nm2[rnd2] + " is celebrated with " + nm3[rnd3] + ". It's a holiday with " + nm4[rnd4] + " roots, but today it is mostly associated with " + nm5[rnd5a] + ", " + nm5[rnd5b] + ", " + nm5[rnd5c] + " and " + nm5[rnd5d] + ".";
    name2 = "It is officially celebrated for " + nm6[rnd6] + ", but " + nm7[rnd7] + ".";
    name3 = "";
    if (i < 2) {
    name3 = "------------------------------------------";
    }
    result += name;
    result += "\n";
    result += name2;
    result += "\n";
    result += name3;
    result += "\n";
    }
    return result;
}
