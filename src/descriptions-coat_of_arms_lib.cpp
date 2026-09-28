#include "descriptions-coat_of_arms_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_coat_of_arms_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"large", "fairly large", "great", "grand", "broad", "fairly small", "not too large", "standard sized", "modest", "regular sized"};
    static constexpr std::string_view nm2[] = {"a symmetrical", "a symmetrical", "an asymmetrical"};
    static constexpr std::string_view nm3[] = {"double inward curving", "double outward curving", "downwards curving", "heart shaped", "long pointed", "podium-like", "pointed", "rounded", "short pointed", "squared", "straight", "tower-like", "zig-zagged", "angular shaped", "upwards curving", "horn-like cornered", "inward curving cornered", "inward curving sided", "outward curving cornered", "outward curving sided", "sharp, inwards curving cornered", "sharp, inwards pointing cornered", "sharp, outwards curving cornered", "sharp, outwards pointing cornered", "talon-like cornered"};
    static constexpr std::string_view nm4[] = {"broad curved", "bullet shaped", "diamond shaped", "downwards curving", "droplet shaped", "long pointed", "narrow curved", "pointed", "round", "short pointed", "squared", "straight", "angular shaped", "upwards curving", "double downwards curving", "double inwards curving"};
    static constexpr std::string_view nm5[] = {"a bear", "a bird of paradise", "a boar", "a cat", "a centaur", "a column", "a dark pillar", "a deer", "a demon", "a dog", "a dragon", "a dryad", "a fish", "a flag pole", "a fox", "a griffon", "a harp", "a hawk", "a hippogriff", "a horse", "a knight", "a leopard", "a lighthouse", "a lion", "a mage", "a maiden", "a mammoth", "a man", "a marble pillar", "a mermaid", "a minotaur", "a moose", "a palm", "a parrot", "a peacock", "a pegasus", "a pelican", "a phoenix", "a pine", "a rabbit", "a ram", "a rhino", "a saint", "a shark", "a snake", "a songbird", "a swan", "a tiger", "a tower", "a treant", "a turtle", "a unicorn", "a vine", "a whale", "a white stag", "a wolf", "a woman", "an angel", "an ape", "an elephant", "an owl"};
    static constexpr std::string_view nm6[] = {"and", "on either side", "on either side"};
    static constexpr std::string_view nm7[] = {"boulder field", "boulder surrounded by water", "cloud", "desert landscape", "field of wheat", "flower field", "forest landscape", "golden platform", "grassy mount", "hilly landscape", "monolith", "mound of gems", "mound of ores", "mound of petals", "mountainous landscape", "path with grass on either side", "pedestal", "small island surrounded by ocean", "snowy landscape", "temple top"};
    static constexpr std::string_view nm8[] = {"considerable", "fairly large", "fairly small", "grand", "humble", "large", "lavish", "modest", "simple", "small"};
    static constexpr std::string_view nm9[] = {"acanthus leaves", "broad tines", "clover leaves", "crosses", "fleurs-de-lis", "gems raised on stalks", "golden arches", "heraldic roses", "narrow tines", "pearls raised on stalks", "raised crescents", "raised leaves", "raised snowflakes", "raised stars", "tines with pearls"};
    static constexpr std::string_view nm10[] = {"", "", "", "", "", "", "cashmere", "felt", "lace", "satin", "silk", "suede", "velour", "velvet", "woolen"};
    static constexpr std::string_view nm11[] = {"an abundance of different gems", "rows of similar gems", "two rows of various gems", "two rows of similar gems", "an abundance of similar gems", "rows of various gems", "rows of precious gems", "two rows of precious gems", "an abundance of precious gems", "a modest amount of different gems", "a modest amount of similar gems", "a modest amount of precious gems"};
    static constexpr std::string_view nm12[] = {"a great", "a frog-mouth", "an armet", "a coppergate", "a coventry sallet", "a sallet", "a horned", "a bascinet", "a barbute", "a hounskull"};
    static constexpr std::string_view nm13[] = {"a classic", "a common", "a gilded", "a glamorous", "a grand", "a great", "a large", "a lavish", "a masterfully made", "a modest", "a simple", "a small", "a traditional", "a well crafted", "an adorned", "an ornamented", "an ornate"};
    static constexpr std::string_view nm14[] = {"anchor", "anvil", "armored hand", "bat", "bear", "bear's head", "boar", "boar's head", "boat", "bull", "bull's head", "carriage", "cat", "crescent moon", "cross", "crow", "deer", "deer's head", "dog", "dove", "dragon", "dragon's head", "eagle", "eagle with closed wings", "eagle with spread wings", "fish", "fleurs-de-lis", "fox", "grapevine", "griffon", "griffon's head", "harp", "hawk with closed wings", "hawk with spread wings", "horse", "horse's head", "hunting horn", "key", "lamb", "lion", "lion's head", "mermaid", "owl with closed wings", "owl with spread wings", "pair of antlers", "pair of intertwining snakes", "pair of large antlers", "pair of wings", "phoenix with closed wings", "phoenix with spread wings", "row of feathers", "row of leaves", "scale", "set of arrows", "swan with closed wings", "swan with spread wings", "tiger", "tiger's head", "tower", "tree", "two headed eagle", "unicorn", "wheat sheaf", "wheel", "wolf", "wolf's head"};
    static constexpr std::string_view nm15[] = {"a large", "an enormous", "a fairly large", "a not too large", "a fairly small", "an average sized", "a modest", "an elegant", "a luxurious", "a lavish", "a grand", "an ornate"};
    static constexpr std::string_view nm16[] = {"large flowers", "small flowers", "delicate ribbons", "simple leaves", "intricate leaves", "leaf-like patterns", "simple ribbons", "intricate ribbons", "large leaves", "floral patterns", "normal drapes", "a large cloak", "large stage curtains", "small stage curtains", "a small cloak"};
    static constexpr std::string_view nm17[] = {"2", "3", "4", "5", "6"};
    static constexpr std::string_view nm18[] = {"a bevilled", "a bordure", "a chevron", "a dancetty", "a diagonal cross", "a diagonal, asymmetrically striped", "a diagonal, symmetrically striped", "a dovetailed", "a fret", "a gore", "a horizontal, asymmetrically striped", "a horizontal, symmetrically striped", "a nebuly", "a nowy", "a pall", "a potenty", "a rayonn�", "a saltire", "a straight cross", "a vertical, assymetrically striped", "a vertical, symmetrically striped", "a wavy", "an angled", "an embattled", "an embattled grady", "an embowed", "an engrailed", "an indented", "an invected", "an orle", "an upside down chevron", "an urdy"};
    static constexpr std::string_view nm19[] = {"1", "1", "2", "2", "3", "4"};
    static constexpr std::string_view nm20[] = {"anchor", "angel wing set", "antler", "antler set", "anvil", "apple", "arrow", "axe", "axe set", "badger", "badger head", "bat", "bear", "bear head", "bird", "boar", "boar head", "book", "bow", "bow and arrow set", "bull", "bull head", "cannon", "castle", "chain", "circle", "clover", "cow", "cow head", "crab", "crescent moon", "cross set", "crow", "crown", "dagger", "dagger set", "deer head", "diamond", "dove", "dragon", "dragon head", "eagle", "eagle head", "elephant", "elephant head", "fan", "feather", "flame", "flower", "footprint", "goat", "goat head", "grapevine", "griffin", "hammer", "hammer set", "hand", "harp", "hatchet", "heart", "helmet", "horn", "horse", "horse head", "key", "knight", "lantern", "leave", "lightning bolt", "lily flower", "lion", "lion head", "lizard", "mace", "mace set", "mermaid", "moon", "moon and star set", "owl", "palm tree", "peacock", "petal", "pig", "pig head", "pitchfork", "ram", "ram head", "rising sun", "rose", "scale", "scorpion", "scythe", "sickel", "skull", "snake", "snake head", "spear", "spear set", "square", "stag", "star", "sun", "swan", "sword", "sword set", "temple", "thistle", "tower", "tree", "tree stump", "triangle", "tusk", "unicorn", "vine", "water droplet", "wheat garb", "wheel", "wing pair", "wolf head"};
    static constexpr std::string_view nm22[] = {"and", "", ""};
    static constexpr std::string_view nm23[] = {"a delicate", "a fancy", "a graceful", "a large", "a long", "a luxurious", "a majestic", "a modest", "a simple", "a small", "an elegant", "an ornate"};
    static constexpr std::string_view nm24[] = {"partially wrapped around the supporters", "reaching from supporter to supporter", "positioned just below the supporters", "positioned just below the shield", "partially covering the bottom of the shield", "partially covered by the shield", "wrapped around the sides of the shield", "hanging above the crest"};
    static constexpr std::string_view nm25[] = {"Formed from many, now as one", "God is great, god is just", "One nation, one people", "For the people, for the realm", "United we stand, united we conquer", "In unity and freedom", "Justice, honesty, integrity", "Pride and honor", "In service of god", "Work, love, play", "Peace, justice, progress", "Truth prevails", "God, king, country", "Peace, equality, unity", "Friends, family, fatherland", "Peace, progress, prosperity", "One struggle, one people, one destiny", "Reap what you sow", "Spirits guide us, spirits watch over us", "Let there be eternal light", "United we stand, united we stay", "We will persevere", "Pride, honor, justice", "Without god we are nothing", "Strength, prosperity, perseverance"};

    std::string name; std::string name2; std::string name3; std::string name4; std::string name5; std::string result; std::string rn10; std::string rn20; std::string rn6; size_t rnd1 = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd17 = 0; size_t rnd18 = 0; size_t rnd19 = 0; size_t rnd19b = 0; size_t rnd2 = 0; size_t rnd20 = 0; size_t rnd20b = 0; size_t rnd22 = 0; size_t rnd23 = 0; size_t rnd24 = 0; size_t rnd25 = 0; size_t rnd2b = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd5b = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

    rnd1 = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd2b = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    if (rnd6 == 0) {
    rnd5b = rng() % std::size(nm5);
    while (rnd5b == rnd5) {
    rnd5b = rng() % std::size(nm5);
    }
    rn6 = nm5[rnd5] + " " + nm6[rnd6] + " " + nm5[rnd5b];
    } else {
    rn6 = nm5[rnd5] + " " + nm6[rnd6];
    }
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    rnd9 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm10);
    if (rnd10 < 6) {
    rn10 = "";
    } else {
    rn10 = ", it has a " + nm10[rnd10] + " cap";
    }
    rnd11 = rng() % std::size(nm11);
    rnd12 = rng() % std::size(nm12);
    rnd13 = rng() % std::size(nm13);
    rnd14 = rng() % std::size(nm14);
    rnd15 = rng() % std::size(nm15);
    rnd16 = rng() % std::size(nm16);
    rnd17 = rng() % std::size(nm17);
    rnd18 = rng() % std::size(nm18);
    rnd19 = rng() % std::size(nm19);
    rnd20 = rng() % std::size(nm20);
    rnd22 = rng() % std::size(nm22);
    if (rnd22 == 0) {
    rnd19b = rng() % std::size(nm19);
    rnd20b = rng() % std::size(nm20);
    if (rnd19 < 2) {
    if (rnd19b < 2) {
    rn20 = nm19[rnd19] + " " + nm20[rnd20] + " and " + nm19[rnd19b] + " " + nm20[rnd20b] + " serve";
    } else {
    rn20 = nm19[rnd19] + " " + nm20[rnd20] + " and " + nm19[rnd19b] + " " + nm20[rnd20b] + "s serve";
    }
    } else {
    if (rnd19b < 2) {
    rn20 = nm19[rnd19] + " " + nm20[rnd20] + "s and " + nm19[rnd19b] + " " + nm20[rnd20b] + " serve";
    } else {
    rn20 = nm19[rnd19] + " " + nm20[rnd20] + "s and " + nm19[rnd19b] + " " + nm20[rnd20b] + "s serve";
    }
    }
    } else {
    if (rnd19 < 2) {
    rn20 = nm19[rnd19] + " " + nm20[rnd20] + " serves";
    } else {
    rn20 = nm19[rnd19] + " " + nm20[rnd20] + "s serve";
    }
    }
    rnd23 = rng() % std::size(nm23);
    rnd24 = rng() % std::size(nm24);
    rnd25 = rng() % std::size(nm25);
    name = "A " + nm1[rnd1] + " shield with " + nm2[rnd2] + " " + nm3[rnd3] + " top and " + nm2[rnd2b] + " " + nm4[rnd4] + " bottom is supported by " + rn6 + ". All of which rests on a " + nm7[rnd7] + ".";
    name2 = "A " + nm8[rnd8] + " crown, or coronet, rests atop the shield, it's a crown of " + nm9[rnd9] + rn10 + " and " + nm11[rnd11] + " decorate the outer sides.";
    name3 = "On top of the coronet sits " + nm12[rnd12] + " helm, which itself supports the crest, in this case " + nm13[rnd13] + " " + nm14[rnd14] + ". The coronet and crest are decoratively bound by a roll of fabric, or torse, which carries the main colors used on the shield.";
    name4 = "Lastly, tied to the helmet is " + nm15[rnd15] + " drapery, or mantling, in the shape of " + nm16[rnd16] + " and colored in the main colors, just like the torse.";
    name5 = "The shield itself has " + nm17[rnd17] + " colors which are painted in " + nm18[rnd18] + " pattern. " + rn20 + " as the emblem, or charge, and " + nm23[rnd23] + " ribbon, " + nm24[rnd24] + ", carries the motto, which reads: \"" + nm25[rnd25] + ".\".";
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
    return result;
}
