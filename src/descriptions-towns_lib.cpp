#include "descriptions-towns_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_towns_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Based", "Built", "Cast", "Constructed", "Designed", "Engineered", "Erected", "Established", "Fabricated", "Forged", "Formed", "Found", "Located", "Positioned", "Raised", "Rooted", "Set", "Settled", "Situated", "Stationed"};
    static constexpr std::string_view names2[] = {"on the Northern side of", "on the Southern side of", "on the Western side of", "on the Eastern side of", "on the top of", "on top of", "on the peak of", "on the base of", "on the bottom of", "on the right side of", "on the left side of", "on the light side of", "on the dark side of", "on the highest point of", "on the lowest point of", "above", "behind", "under", "inside", "around", "beside", "next to", "in", "on the end of"};
    static constexpr std::string_view names3[] = {" bluff", " canal", " canyon", " cave", " cavern", " cliff", " covert", " desert", " field", " forest", " geyser field", " glacier", " grotto", " grove", " hill", "n island", " jungle", " lake", " lava stream", " mound", " mountain", "n ocean", " peninsula", " river", " sea", " stream", " thicket", " tundra", " valley", " vulcano", " waterfall", " wetlands", " woodlands"};
    static constexpr std::string_view names4[] = {"village", "town", "city", "metropolis", "hamlet", "megalopolis", "outpost", "port", "township", "settlement", "crossroad", "burg"};
    static constexpr std::string_view names5_1[] = {"Barnemouth", "Paethsmouth", "Pernrith", "Perthlochry", "Pitmerden", "Coalfell", "Cullfield", "Darkwell", "Deathfall", "Doonatel", "Dry Gulch", "Easthaven", "Ecrin", "Erast", "Far Water", "Firebend", "Fool's March", "Frostford", "Goldcrest", "Goldenleaf", "Greenflower", "Garen's Well", "Haran", "Hillfar", "Hogsfeet", "Hollyhead", "Hull", "Hwen"};
    static constexpr std::string_view names6[] = {"humans", "elves", "orcs", "dwarves", "fairies", "trolls", "vampires", "werewolves", "humans", "humans", "humans", "night elves", "blood elves", "gnomes", "goblins", "high elves", "wood elves", "dark elves", "halflings", "giants", "pirates", "barbarians", "vikings"};
    static constexpr std::string_view names7_1[] = {"Agent", "Baron", "Captain", "Chief", "Colonel", "Commander", "Director", "Duchess", "Duke", "Earl", "General", "Governor", "Judge", "Knight", "Lady", "Lord", "Major", "Marshal", "Master", "Mayor", "Minister", "Mr.", "Mrs.", "Ms.", "Officer", "Ruler", "Sergeant", "Supervisor", "Warlord"};
    static constexpr std::string_view names8_1[] = {"Adwell", "Ady", "Afton", "Barnett", "Barney", "Barnfield", "Chilson", "Chilton", "Cawthorn", "Davenport", "Davey", "Dallin", "Eustice", "Eustis", "Evatt", "Falcon", "Faley", "Falkner", "Geary", "Gedman", "Gedney", "Hanshaw", "Hansley", "Hanson", "Lamkin", "Lamkins", "Lamm", "Lockridge", "Locks", "Lockwood", "Masser", "Massey", "Massingale", "Rosemond", "Shepherd", "Shepley", "Wakeley", "Wakelin"};
    static constexpr std::string_view names9[] = {"magical properties", "fertile soils", "ancient histories", "a cultural history", "hidden secrets", "healing properties", "an abundance of minerals", "a dark history", "rare resources", "precious gems", "ancient burial grounds", "old tombs", "a broken, hidden library", "an ancient water source", "dark ruins", "rare plants", "medicinal plants", "strong metal ores", "natural defences", "hidden tunnels", "ambush positions", "escape routes", "an abundance of wildlife", "ancient, lost technologies", "a comfortable weather system", "unique wildlife", "spiritual significance", "ancestral grounds", "ancient, unexplained statues", "body enhancing properties"};
    static constexpr std::string_view names10[] = {"n advancing", " booming", " breaking", " damaged", " declining", " developing", " failing", " feeble", " flourishing", " growing", " healthy", " hurting", "n improving", " mending", " poor", " progressing", " prospering", " prosperous", " thriving", " tormented", " troubled", "n unhealthy", " wounded"};
    static constexpr std::string_view names11[] = {"alchemy", "animal breeding", "animal training", "armorsmithing", "baking", "beer brewing", "blacksmithing", "carpenting", "cooking", "crafting", "engineering", "farming", "fishing", "fletching", "herbalism", "hunting", "jewelcrafting", "leatherworking", "medicine", "mining", "tailoring", "thieving", "trade", "war", "weaponsmithing", "wine brewing", "wood production", "woodcrafting"};
    static constexpr std::string_view names14[] = {"alchemy", "rare animal breeding", "rare animal training", "advanced armorsmithing", "refined baking", "elaborate beer brewing techniques", "elaborate blacksmithing", "refined carpenting", "sophisticated cooking", "complex crafting", "master engineering", "rare crop farming", "ocean fishing", "intricate fletching techniques", "rare herbalism", "sustainable hunting", "intricate jewelcrafting", "gorgeous leatherworking", "advanced medicine", "prosperous mining", "delicate tailoring", "highly skilled thieving", "prosperous trade", "skilled in the art of war", "weaponsmithing", "ancient wine brewing techniques", "rare wood production", "delicate woodcrafting", "a strong defence", "skilled fighters", "strong magicians", "deadly archers"};
    static constexpr std::string_view names17[] = {"gorgeous", "beautiful", "majestic", "elegant", "glorious", "impressive", "flamboyant", "luxuriant", "stunning", "impressive", "delightful", "graceful", "magnificent", "imposing", "sublime", "grandiose", "humble", "crude", "rough", "mediocre", "dull", "plain", "ordinary", "hideous", "gruesome", "dreadful", "macabre", "ghastly", "unattractive", "unexciting", "worn", "mundane"};
    static constexpr std::string_view names18_1[] = {"oak wood", "maple wood", "yew wood", "cypress wood", "pine wood", "spruce  wood", "redwood", "ash wood", "birch wood", "blackwood", "ebony wood", "elm wood", "ironwood", "mahogany wood", "silky oak wood", "willow wood", "bamboo", "tatchet", "shingle", "slate tile", "wheat straw", "seagrass", "ceramic tile", "copper"};
    static constexpr std::string_view names19_1[] = {"golden brick", "red brick", "redstone", "granite", "marble", "limestone", "sandstone", "stone veneer", "chiseled stone", "oak wood", "maple wood", "yew wood", "cypress wood", "pine wood", "spruce  wood", "redwood", "ash wood", "birch wood", "blackwood", "ebony wood", "elm wood", "ironwood", "mahogany wood", "silky oak wood", "willow wood", "bamboo", "tatchet", "shingle", "slate tile", "wheat straw", "seagrass", "ceramic tile", "copper", "lavastone"};
    static constexpr std::string_view names20_1[] = {"lucious gardens", "enchanting wildlife", "swarms of fireflies", "babbling creeks", "vibrant, rare trees", "breathtaking waterfall", "calm and quiet collection of ponds", "frozen lakes", "frozen waterfall", "imposing glacier", "ambient light of nearby lava streams", "the native bird species", "rainbow of different flowers", "everclear night sky", "huge, majestic geyser", "silent mountain range", "foggy fields", "a gorgeous mirror lake", "rows upon rows of lucious trees", "staircase of waterfalls", "frozen ponds", "aromatic flowers", "calming ocean front", "fields of farmland", "bamboo forest", "huge oak tree", "stunning canyon", "majestic fjords", "white, sandy beaches", "amazing sunsets"};
    static constexpr std::string_view names21_1[] = {"amusing", "captivating", "charming", "delightful", "enchanting", "enthralling", "entrancing", "fascinating", "glamorous", "heavenly", "intriguing", "inviting", "magical", "mystical", "mythical", "otherworldly", "pleasant", "pleasing", "seductive", "whimsical"};
    static constexpr std::string_view names38[] = {"town hall", "cathedral", "farm", "large park", "bank", "jail", "wishing well", "old bar", "armory", "training grounds", "graveyard", "mausoleum", "watchtower", "blacksmith", "hotel", "lighthouse", "market", "museum", "hospital", "barracks", "power plant", "watermill", "windmill", "library", "school", "temple", "castle", "dueling arena", "fountain", "greenhouse", "guard tower", "lumber mill", "quarry", "stables", "statue", "tombs", "monument", "ancient forge", "inn", "cemetery", "theatre", "stadium", "wizard tower"};
    static constexpr std::string_view names41[] = {"affluent", "beautiful", "bleak", "booming", "cheerful", "comfortable", "delightful", "enjoyable", "flourishing", "frightful", "gloomy", "gracious", "grim", "grisly", "growing", "gruesome", "harsh", "horrendous", "horrible", "horrific", "luxuriant", "macabre", "pleasant", "pleasurable", "prosperous", "sinister", "somber", "terrible", "terrifying", "thriving"};
    static constexpr std::string_view names18_2[] = {"metal shingle", "galvanised steel", "rusted", "decaying", "blackened", "gray", "black wooden", "dark wooden", "murky wooden", "gloomy wooden", "half rotten"};
    static constexpr std::string_view names19_2[] = {"mossy wooden", "mossy stone", "faded granite", "faded marble", "worn limestone", "worn sandstone", "stone veneer", "chiseled stone", "galvanised steel", "rusted", "decaying", "blackened", "gray", "black wooden", "dark wooden", "murky wooden", "gloomy wooden", "half rotten", "lavastone"};
    static constexpr std::string_view names20_2[] = {"decaying trees", "rotten fields", "broken roads", "overgrown gardens", "vines overgrowing everything", "unmaintained gardens", "foggy surroundings", "murky woods", "musky swamps", "menacing mountain tops", "barren grounds", "absolute silence", "a large graveyard", "large cobwebs", "dusty windows", "dirty roads", "thick smoke", "creaking wood", "whistling wind", "scary animals", "a lot of insects", "scavenger birds", "ominous scarecrows"};
    static constexpr std::string_view names21_2[] = {"bizarre", "bleak", "chilling", "creepy", "dark", "desolate", "dreary", "dull", "eerie", "foreboding", "frightening", "ghostly", "ghoulish", "gloomy", "grim", "grisly", "gruesome", "macabre", "morbid", "mysterious", "ominous", "peculiar", "repulsive", "revolting", "sinister", "somber", "spine-chilling", "supernatural", "uncanny", "unearthly"};
    static constexpr std::string_view names5_2[] = {"Gorash", "Ogrinar", "Tohrall", "Dranorg", "Hammerfall", "Orsanum", "Wrothguard", "Garlund", "Kharn", "Xarluk"};
    static constexpr std::string_view names8_2[] = {"Gnarg", "Gnarlug", "Gnorl", "Gnorth", "Gnoth", "Gnurl", "Golag", "Golub", "Gomatug", "Gomoku", "Gorgu", "Gorlag", "Grikug", "Grug", "Grukag", "Grukk", "Grung", "Gruul"};
    static constexpr std::string_view names5_3[] = {"Balagost", "Moriath", "Nogrand", "Frosthold", "Hammerhold", "Thar Modan", "Kaz Modor", "Uldama", "Hammerforge", "Stormforge"};
    static constexpr std::string_view names8_3[] = {"Bengahdar", "Banbrek", "Drumdus", "Dulgarn", "Galirg", "Kharnur", "Iromuador", "Ragorhdrom", "Urmbrek", "Theledon"};
    static constexpr std::string_view names5_4[] = {"Eviana", "Malica", "Mystohr", "Arconia", "Aeria", "Mithyria", "Calairith", "Myracal", "Fentalia", "Curacius"};
    static constexpr std::string_view names7_2[] = {"Queen", "King", "Prince", "Princess"};
    static constexpr std::string_view names8_4[] = {"Azore", "Coral", "Cowrie", "Ebbie", "Gullie", "Ionia", "Ivory", "Marin", "Meer", "Meri", "Mora", "Nautila", "Oceana", "Pearl", "Percula", "Sandy", "Shelly", "Starfish", "Tidal", "Urchin", "Wave", "Whirl", "Wrassey", "Aed", "Aodh", "Aeden", "Ash", "Ashley", "Blaze", "Candala", "Coala", "Firo", "Flare"};
    static constexpr std::string_view names5_5[] = {"Zuldazin", "Zalzabin", "Jintalman", "Zulamor", "Julguroob", "Atalakar", "Zandalur", "Farakazul", "Guruubash", "Amano"};
    static constexpr std::string_view names8_5[] = {"Ekon", "Erasto", "Haijen", "Hamedi", "Hokima", "Jaafan", "Jabir", "Jalai", "Javyn", "Jijel", "Juma", "Jumoke", "Kaijin", "Kazko", "Maalik", "Makas", "Malak", "Nyabingi", "Rahjin", "Rakash", "Rashi", "Razi"};
    static constexpr std::string_view names5_6[] = {"Gandoline", "Galadoneh", "Tirianae", "Darnassea", "Sinashari", "Kaladorei", "Hiborane", "Fandralore", "Cenorias", "Ishnuala"};
    static constexpr std::string_view names8_6[] = {"Wyninn", "Ninleyn", "Tinlef", "Elluin", "Elduin", "Elmon", "Almar", "Alas", "Alwin", "Almer", "Alre", "Alred", "Alen", "Alluin", "Alduin", "Almon", "Hagmar", "Hagas", "Hagwin", "Hagmer", "Hagre"};
    static constexpr std::string_view names5_7[] = {"Nomeregone", "Meckotarq", "Kasmord", "Trokkus", "Hitonkar", "Serian", "Gloufry", "Hazelmyre", "Erposanra", "Ardnode"};
    static constexpr std::string_view names8_7[] = {"Glinoflonk", "Bonlebick", "Bimbik", "Gnobflink", "Binflonk", "Nittlewizz", "Gimkink", "Merbibus", "Totonk", "Dinnus"};
    static constexpr std::string_view names5_8[] = {"Bolgewotar", "Galowax", "Kozan", "Stimwedle", "Bootabai", "Midsprocket", "Rotchet", "Grozlik", "Andormyn", "Ventarco"};
    static constexpr std::string_view names8_8[] = {"Karax", "Baxeek", "Soxart", "Rezikmez", "Fizink", "Wimax", "Jexmelyx", "Grexmex", "Tinkbelex", "Greekeels"};
    static constexpr std::string_view names7_3[] = {"Captain"};
    static constexpr std::string_view names18_3[] = {"metal shingle", "galvanised steel", "rusted", "decaying", "blackened", "gray", "black wooden", "dark wooden", "murky wooden", "gloomy wooden", "half rotten"};
    static constexpr std::string_view names19_3[] = {"faded granite", "faded marble", "worn limestone", "worn sandstone", "stone veneer", "chiseled stone", "galvanised steel", "rusted", "decaying", "blackened", "gray", "black wooden", "dark wooden", "murky wooden", "gloomy wooden", "half rotten", "lavastone"};
    static constexpr std::string_view names20_3[] = {"decaying trees", "rotten fields", "broken roads", "overgrown gardens", "vines overgrowing everything", "unmaintained gardens", "foggy surroundings", "murky woods", "musky swamps", "menacing mountain tops", "barren grounds", "absolute silence", "a large graveyard", "large cobwebs", "dusty windows", "dirty roads", "thick smoke", "creaking wood", "whistling wind", "scary animals", "a lot of insects", "scavenger birds", "ominous scarecrows"};
    static constexpr std::string_view names21_3[] = {"bizarre", "bleak", "chilling", "creepy", "dark", "desolate", "dreary", "dull", "eerie", "foreboding", "frightening", "ghostly", "ghoulish", "gloomy", "grim", "grisly", "gruesome", "macabre", "morbid", "mysterious", "ominous", "peculiar", "repulsive", "revolting", "sinister", "somber", "spine-chilling", "supernatural", "uncanny", "unearthly"};

    ArrayView names18; ArrayView names19; ArrayView names20; ArrayView names21; ArrayView names5; ArrayView names7; ArrayView names8; std::string name; std::string name2; std::string name3; std::string name4; std::string name5; std::string name6; std::string name7; std::string random40; std::string result; size_t random1 = 0; size_t random10 = 0; size_t random11 = 0; size_t random12 = 0; size_t random13 = 0; size_t random14 = 0; size_t random15 = 0; size_t random16 = 0; size_t random17 = 0; size_t random18 = 0; size_t random19 = 0; size_t random2 = 0; size_t random20 = 0; size_t random21 = 0; size_t random3 = 0; size_t random38 = 0; size_t random39 = 0; size_t random4 = 0; size_t random41 = 0; size_t random5 = 0; size_t random6 = 0; size_t random6b = 0; size_t random7 = 0; size_t random8 = 0; size_t random9 = 0; int i = 0;

    names5 = make_view(names5_1);
    names7 = make_view(names7_1);
    names8 = make_view(names8_1);
    names18 = make_view(names18_1);
    names19 = make_view(names19_1);
    names20 = make_view(names20_1);
    names21 = make_view(names21_1);
    random1 = rng() % std::size(names1);
    random2 = rng() % std::size(names2);
    random3 = rng() % std::size(names3);
    random4 = rng() % std::size(names4);
    random6 = rng() % std::size(names6);
    random6b = rng() % std::size(names6);
    random9 = rng() % std::size(names9);
    random10 = rng() % std::size(names10);
    random11 = rng() % std::size(names11);
    random12 = rng() % std::size(names11);
    while (random12 == random11) {
    random12 = rng() % std::size(names11);
    }
    random13 = rng() % std::size(names11);
    while (random13 == random12 || random13 == random11) {
    random13 = rng() % std::size(names11);
    }
    random14 = rng() % std::size(names14);
    random15 = rng() % std::size(names14);
    while (random15 == random14) {
    random15 = rng() % std::size(names14);
    }
    random16 = rng() % std::size(names11);
    while (random16 == random11 || random16 == random12 || random16 == random13) {
    random16 = rng() % std::size(names11);
    }
    random17 = rng() % std::size(names17);
    if (random17 > 16) {
    names18 = make_view(names18_2);
    names19 = make_view(names19_2);
    names20 = make_view(names20_2);
    names21 = make_view(names21_2);
    }
    random18 = rng() % std::size(names18);
    random20 = rng() % std::size(names20);
    random21 = rng() % std::size(names21);
    random38 = rng() % std::size(names38);
    random39 = (rng() % 50) + 20;
    random40 = std::to_string(random39);
    random41 = rng() % std::size(names41);
    if (random6 == 2) {
    names5 = make_view(names5_2);
    names8 = make_view(names8_2);
    random5 = rng() % std::size(names5);
    random8 = rng() % std::size(names8);
    } else if (random6 == 3) {
    names5 = make_view(names5_3);
    names8 = make_view(names8_3);
    random5 = rng() % std::size(names5);
    random8 = rng() % std::size(names8);
    } else if (random6 == 4) {
    names5 = make_view(names5_4);
    names7 = make_view(names7_2);
    names8 = make_view(names8_4);
    random5 = rng() % std::size(names5);
    random7 = rng() % std::size(names7);
    random8 = rng() % std::size(names8);
    } else if (random6 == 5) {
    names5 = make_view(names5_5);
    names8 = make_view(names8_5);
    } else if (random6 == 1 || random6 == 11 || random6 == 12 || random6 == 15 || random6 == 16 || random6 == 17) {
    names5 = make_view(names5_6);
    names8 = make_view(names8_6);
    } else if (random6 == 13) {
    names5 = make_view(names5_7);
    names8 = make_view(names8_7);
    } else if (random6 == 14) {
    names5 = make_view(names5_8);
    names8 = make_view(names8_8);
    } else if (random6 == 20) {
    names7 = make_view(names7_3);
    } else {
    }
    if (random17 > 16) {
    names18 = make_view(names18_3);
    names19 = make_view(names19_3);
    names20 = make_view(names20_3);
    names21 = make_view(names21_3);
    }
    random5 = rng() % std::size(names5);
    random7 = rng() % std::size(names7);
    random8 = rng() % std::size(names8);
    random19 = rng() % std::size(names19);
    name = names1[random1] + " " + names2[random2] + " a " + names3[random3] + ", the " + names4[random4] + " of " + names5[random5] + " is home to " + names6[random6] + " lead by " + names7[random7] + " " + names8[random8] + ".";
    name2 = "This " + names4[random4] + " wasn't built by a" + names3[random3] + " by accident, as it has " + names9[random9] + ", which is of great importance to the people of " + names5[random5] + " and its success.";
    name3 = "The " + names4[random4] + " itself looks " + names17[random17] + ". With its " + names18[random18] + " rooftops, " + names19[random19] + " walls and " + names20[random20] + ", " + names5[random5] + " has a " + names21[random21] + " atmosphere.";
    name4 = "The main attraction is the " + names38[random38] + ", which was built " + random40 + " years ago and designed by " + names6[random6b] + ".";
    name5 = names5[random5] + " has a" + names10[random10] + " economy, which is mainly supported by " + names11[random11] + ", " + names11[random12] + " and " + names11[random13] + ". But their biggest strengths are " + names14[random14] + " and " + names14[random15] + ".";
    name6 = "However, " + names5[random5] + " lacks people skilled in " + names11[random16] + ".";
    name7 = "Despite its strengths and weaknesses, " + names5[random5] + " is most likely headed towards a " + names41[random41] + " future under the leadership of " + names7[random7] + " " + names8[random8] + ". But this remains to be seen.";
    result = "";
    result += name;
    result += "\n";
    result += name2;
    result += "\n";
    result += "\n";
    result += name3;
    result += "\n";
    result += name4;
    result += "\n";
    result += "\n";
    result += name5;
    result += "\n";
    result += name6;
    result += "\n";
    result += "\n";
    result += name7;
    return result;
}
