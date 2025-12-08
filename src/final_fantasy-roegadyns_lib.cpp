#include "final_fantasy-roegadyns_lib.h"

#include <vector>
#include <utility>

/* Data taken directly from the original JavaScript generator */
static const std::vector<std::pair<std::string, std::string>> nm1 = {
    {"Abar", "Lone"}, {"Aerg", "Ambitious"}, {"Aerm", "Poor"}, {"Aerst", "First"},
    {"Agat", "Amber"}, {"Ahld", "Old"}, {"Awyr", "Absent"}, {"Bara", "Bare"},
    {"Bhald", "Brave"}, {"Blan", "Dark"}, {"Blau", "Lead"}, {"Blei", "Pale"},
    {"Bloe", "Blue"}, {"Blyn", "Blind"}, {"Broen", "Brown"}, {"Caepf", "Slate"},
    {"Caer", "Sad"}, {"Dani", "Narrow"}, {"Denn", "Thin"}, {"Doer", "Dry"},
    {"Does", "Two"}, {"Eifa", "Bitter"}, {"Elil", "Foreign"}, {"Erna", "Earnest"},
    {"Eyn", "One"}, {"Eyri", "Wandering"}, {"Faez", "Fat"}, {"Fhil", "Yellow"},
    {"Fhruh", "Early"}, {"Flaz", "Flat"}, {"Flekk", "Spotted"}, {"Frae", "Free"},
    {"Fryd", "Peaceful"}, {"Fyril", "Lost"}, {"Ganz", "Perfect"}, {"Ghim", "Modest"},
    {"Glaz", "Glass"}, {"Greh", "Calm"}, {"Grein", "Bronze"}, {"Grym", "Cruel"},
    {"Gryne", "Green"}, {"Guht", "Good"}, {"Guld", "Gold"}, {"Guol", "Glorious"},
    {"Hael", "Healthy"}, {"Haer", "Grand"}, {"Hald", "Kind"}, {"Hart", "Hard"},
    {"Hast", "Hazel"}, {"Helb", "Half"}, {"Herl", "Elder"}, {"Hezz", "Hot"},
    {"Holas", "Bald"}, {"Holl", "Hollow"}, {"Holsk", "Fast"}, {"Horsk", "Obedient"},
    {"Iyrn", "Iron"}, {"Jungh", "Young"}, {"Keim", "Violet"}, {"Kelt", "Cold"},
    {"Keten", "Chained"}, {"Klyn", "Small"}, {"Kryd", "Chalk"}, {"Kryst", "Crystal"},
    {"Kupf", "Copper"}, {"Kympf", "Champion"}, {"Lamm", "Injured"}, {"Loet", "Loud"},
    {"Loetr", "Pure"}, {"Loez", "Short"}, {"Lydir", "Leather"}, {"Lyna", "Linen"},
    {"Lyng", "Long"}, {"Maeti", "Mighty"}, {"Marm", "Marble"}, {"Myte", "Middle"},
    {"Nedyr", "Low"}, {"Ofan", "Clear"}, {"Pfar", "Walking"}, {"Rhen", "Clean"},
    {"Rheti", "Lawful"}, {"Rhit", "Right"}, {"Rhot", "Red"}, {"Roeh", "Rough"},
    {"Rostn", "Rusty"}, {"Skaen", "Beautiful"}, {"Skarn", "Horrible"},
    {"Skoen", "Shining"}, {"Slae", "Dull"}, {"Slaf", "Sleeping"}, {"Slett", "Plain"},
    {"Solk", "Blessed"}, {"Sterr", "Strong"}, {"Swar", "Black"}, {"Swoz", "Sweet"},
    {"Swyg", "Silent"}, {"Swyn", "Round"}, {"Swyr", "Big"}, {"Syhr", "Fearless"},
    {"Sylb", "Silver"}, {"Syngi", "Singing"}, {"Syzn", "Sitting"}, {"Thor", "Torn"},
    {"Thosin", "Grey"}, {"Thubyr", "Magic"}, {"Toeg", "Secret"}, {"Toff", "Deep"},
    {"Trachyn", "Dragon"}, {"Tragg", "Slow"}, {"Trahg", "Lazy"}, {"Troe", "Confused"},
    {"Tymb", "Dumb"}, {"Ubyl", "Evil"}, {"Unsyn", "Innocent"}, {"Unta", "Other"},
    {"Usyn", "Ashen"}, {"Waem", "Warm"}, {"Wakk", "Woken"}, {"Wann", "Empty"},
    {"Wast", "Sharp"}, {"Webb", "Silk"}, {"Whei", "Soft"}, {"Wilt", "Wild"},
    {"Wuot", "Berserk"}, {"Wyss", "Wise"}, {"Wyzn", "White"}, {"Ybolg", "Enraged"},
    {"Zirn", "Furious"}, {"Zwyn", "Twin"}
};

static const std::vector<std::pair<std::string, std::string>> nm3 = {
    {"swys", "Sister"}, {"thota", "Daughter"}, {"wyda", "Willow"},
    {"geim", "Jewel"}, {"wyb", "Woman"}, {"rael", "Doe"},
    {"lona", "Gatherer"}, {"bryda", "Bride"}
};

static const std::vector<std::string> nm6 = {
    "Active","Adept","Admired","Adored","Ages","Aggressive","Agile","Alert","Amazing","Amused",
    "Amusing","Ancient","Angry","Anxious","Arctic","Austere","Aware","Awesome","Awkward","Bad",
    "Bare","Basic","Beautiful","Beloved","Big","Bitter","Black","Blue","Bold","Brave","Bright",
    "Brilliant","Broken","Bronze","Busy","Calm","Careful","Careless","Cheerful","Cleaan","Clever",
    "Clumsy","Cold","Colossal","Complex","Composed","Crafty","Cruel","Damaged","Dangerous",
    "Dapper","Daring","Dark","Defiant","Dependable","Devoted","Difficult","Diligent","Dirt",
    "Distant","Dull","Eager","Earnest","Elderly","Enchanted","Enormous","Enraged","Exalted",
    "Excellent","Excited","Exotic","Expert","Faithful","Famous","Fancy","Fast","Fatal","Fearless",
    "Firm","Fixed","Flawed","Flawless","Forsaken","Free","Friendly","Frozen","Gentle","Giant",
    "Gifted","Giving","Glamorous","Glorious","Golden","Graceful","Gracious","Grand","Grateful",
    "Gray","Great","Grim","Harmless","Hasty","Heavy","Helpful","Hidden","Hollow","Honest",
    "Honorable","Humble","Hungry","Joyful","Keen","Kind","Large","Lazy","Light","Little",
    "Lone","Loud","Loyal","Lucky","Majestic","Major","Massive","Mellow","Mild","Minor",
    "Modest","Nervous","Nifty","Nimble","Obedient","Odd","Old","Orange","Ordinary","Ornate",
    "Pale","Perfect","Plain","Pleasant","Powerful","Prime","Pristine","Proud","Pure","Quick",
    "Quiet","Rapid","Rare","Reckless","Red","Regular","Rough","Scary","Second","Secret",
    "Serene","Serious","Sharp","Shiny","Shy","Silent","Silver","Simple","Skinny","Sleepy",
    "Slow","Small","Smart","Sneaky","Spotted","Stable","Stark","Strange","Strong","Sturdy",
    "Subtle","Surprised","Swift","Tall","Tame","Thin","Tough","Useful","Vibrant","Vicious",
    "Warm","Weak","Weird","White","Wide","Wild","Wise","Witty","Worthy","Yellow","Young",
    "Youthful"
};

static const std::vector<std::string> nm7 = {
    "Air","Allium","Alyssum","Amarath","Amazon","Anemone","Apple","Aura","Aurora","Autumn",
    "Bee","Bell","Berry","Bird","Bloom","Blossom","Bunny","Bush","Butterfly","Cherry",
    "Chive","Clematis","Cloud","Clover","Cosmos","Crocus","Daffodil","Daisy","Dandelion",
    "Deer","Dew","Dill","Dove","Dream","Droplet","Earth","Eclipse","Feather","Flower",
    "Fog","Forest","Frost","Fruit","Fuchsia","Fur","Gilly","Ginger","Grain","Grass",
    "Heliconia","Hibiscus","Holly","Horizon","Hyacinth","Ice","Iris","Juniper","Lavender",
    "Leaf","Lilac","Lily","Locust","Lotus","Magnolia","Mantle","Maple","Marigold","Mist",
    "Moon","Moss","Mouse","Mushroom","Myrtle","Narcissus","Oleander","Orchid","Pad",
    "Pea","Peach","Peony","Petal","Petunia","Plume","Poinsetta","Poppy","Rabbit","Rain",
    "Robin","Root","Rose","Safflower","Sage","Sapling","Sheep","Snow","Snowflake","Sparrow",
    "Spring","Sprout","Star","Summer","Sun","Sunflower","Tulip","Vapor","Vine","Willow","Winter"
};

std::string generate_final_fantasy_roegadyns_name(std::mt19937& rng) {
    // Random number to decide which naming scheme to use (mirrors JS logic)
    int i = rng() % 10;
    if (i < 5) {
        // Use nm1 + nm3 with description in parentheses
        const auto& part1 = nm1[rng() % nm1.size()];
        const auto& part3 = nm3[rng() % nm3.size()];
        return part1.first + part3.first + " (" + part1.second + " " + part3.second + ")";
    } else {
        // Use nm6 + nm7 (adjective + noun)
        const std::string& adj = nm6[rng() % nm6.size()];
        const std::string& noun = nm7[rng() % nm7.size()];
        return adj + " " + noun;
    }
}
