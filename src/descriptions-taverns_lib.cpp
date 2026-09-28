#include "descriptions-taverns_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_taverns_name(std::mt19937& rng) {
    static constexpr std::string_view names1_1[] = {"welcoming", "cozy", "inviting", "warm", "cheerful", "snug", "delightful", "well maintained", "clean", "homey", "folksy", "pleasant", "intimate", "rustic", "modest", "humble", "peaceful", "beautiful", "enchanting", "cheerful"};
    static constexpr std::string_view names2[] = {"Bricks", "Clay", "Clay bricks", "Hardwooden planks", "Large and small stones", "Large stones", "Logs", "Plastered walls", "Sandstone bricks", "Small stones", "Softwood", "Softwooden planks", "Stacked boulders", "Stacked stones", "Timber"};
    static constexpr std::string_view names3[] = {"carved pillars", "hardwooden beams", "hardwooden pillars", "hardwooden tree trunks", "huge, stone beams", "huge, stone pillars", "intricate stone carvings", "intricate wooden carvings", "marble details", "marble pillars", "marble stones", "sandstone pillars", "softwooden tree trunks", "stone beams", "stone pillars", "thick, hardwooden logs", "thick, stone beams", "tree trunks", "well-crafted wooden beams", "wooden pillars"};
    static constexpr std::string_view names4[] = {"hard", "near impossible", "difficult", "tough", "impossible"};
    static constexpr std::string_view names5_1[] = {"curtained windows", "darkened windows", "high windows", "large, curtained windows", "large, stained glass windows", "small, curtained windows", "small, stained glass windows", "stained glass windows", "windows", "closed windows"};
    static constexpr std::string_view names6_1[] = {"animation", "cheerful sounds", "clapping and cheering", "clinking of beer glasses", "energy and excitement", "enjoyment", "entertained voices", "entertainment", "enthusiastic noises", "excited voices", "excitement", "happiness and joy", "hustling and bustling", "inviting music", "laughter", "laughter and cheering", "livelyness", "music and songs", "music and voices", "noise", "passionate voices", "sounds of cutlery and drinking glasses", "sounds of dancing and singing", "thrilled sounds", "warm noises"};
    static constexpr std::string_view names7_1[] = {"decorated, metal door", "decorated, wooden door", "hardwooden door", "heavily used, metal door", "heavily used, wooden door", "heavy, metallic door", "heavy, wooden door", "huge, hardwooden door", "old, hardwooden door", "old, metal door", "old, wooden door", "small, softwooden door", "thick, metal door", "thick, wooden door", "well-crafted, metal door"};
    static constexpr std::string_view names8_1[] = {"amazing, but unknown scents", "a pleasant atmosphere", "excitement", "joyful music", "cheerful singing", "the smell of alcohol", "laughing voices", "clapping hands", "dancing people", "aromas of roasted meats", "the smile of a waitress", "overall happiness", "a sense of home", "a feeling of comfort"};
    static constexpr std::string_view names9_1[] = {"busy", "extremely busy", "quite busy", "a little preoccupied", "handling some customers", "engaged in a conversation", "working hard", "buried in orders", "swamped in work", "working up a sweat"};
    static constexpr std::string_view names10_1[] = {"short wave", "smile", "wink", "friendly nod", "wave"};
    static constexpr std::string_view names11_1[] = {"lovely", "alluring", "enchanting", "engaging", "charming"};
    static constexpr std::string_view names12[] = {"Hardwooden beams", "Marble pillars", "Rounded, stone beams", "Rounded, wooden beams", "Several walls", "Sqaured, stone beams", "Squared, wooden beams", "Stone beams", "Tree logs", "Wooden beams"};
    static constexpr std::string_view names13_1[] = {"Christmas-like lights", "ambient lights", "candles", "chandeliers", "decorational lights", "fans", "huge lamps", "lanterns", "large candles", "light fixtures", "lights", "rows of small candles", "rows of small lights", "sconces", "torches"};
    static constexpr std::string_view names14_1[] = {"clear of anything, though signs do show plenty of things used to hang on the walls, though they've probably been knocked off by customers who had too much to drink.", "completely empty, besides the lighting, most likely because customers stumble against the walls too often and would knock off anything on the walls.", "covered in photographs of personal achievements, all related to the nearby mountain. Some of people who reached the summit, others simply of happy people.", "decorated with mounted animal heads, hides and small animals. It's clear the owner is an avid hunter and the smells coming from the kitchen indicate the animals don't go to waste.", "decorated with sports memorabilia, it's clear the owner, and probably the customers, are avid fans.", "full of paintings, all in a different style, but all of the surrounding area.", "full of paintings, judging by the style they're all done by 1 person, perhaps the owner.", "littered with all sorts of memorabilia, though whether they're collected or donated is uncertain.", "littered with so many different memorabilia, you're not sure if they tried going for a specific style at one time or just put up anything they like.", "loaded with hundreds of memorabilia, all signed and most likely donated by customers.", "overflowing with signatures and written messages, undoubtedly from happy customers.", "packed with all sorts of travel memorabilia, most likely all collected by the owner.", "packed with rows of painted portraits. You recognize the bartender on one of them, so the others must be either friends, family or previous owners.", "swarmed with flags of all sorts and sizes. Some are from nearby towns or provinces, others from the far corners of the world. They must've been fited to the owner.", "swarming with photographs, some of what undoubtedly must be famous people and others of happy customers."};
    static constexpr std::string_view names15_1[] = {"Locals", "Tourists", "Travelers", "Passing traders", "Workers", "Soldiers", "Groups belonging to some kind of organization, whether sport, music or other you're not sure of,"};
    static constexpr std::string_view names16_1[] = {"is often a good sign.", "could be seen as the best sign you can get.", "could be seen as a bad sign, though you're sure it's not.", "often indicates great food.", "often means great company.", "often leads to exciting evenings.", "is probably the best clientele for the owner."};
    static constexpr std::string_view names17_1[] = {", what looks like couples, lone travellers and anybody else who enjoys great company.", ", what must be seperate groups who have bonded over great food and conversation.", ", what seems to be entire families, all enjoying the food, drinks and company of each other.", ", what seems to be one large group of people.", ", what seems to be the entire surrounding village.", " happy, excited groups of people, some are dancing on the table, while others cheer them on with clapping and yelling.", " locals, travellers, foreigners and anybody else who wishes to join.", " seperate groups of people, all enjoying themselves, but they keep to themselves.", " seperate groups who, after having had quite a few drinks, seem to be trying to prove which group is best.", " several smaller groups of people."};
    static constexpr std::string_view names18_1[] = {"are clearly having a good time.", "seem to be enjoying themselves a lot, perhaps too much, if such a thing is possible.", "are probably starting to reach the point of having drunk too much, though nobody seems to mind.", "clearly enjoy each other's company, though they seem to be strangers who have met here.", "are playing games and, judging by their laughter, are either telling jokes or great, perhaps embarrasing, tales.", "seem to be close with the owner, though they happily welcome others among their midst.", "are singing and dancing, occassionaly pulling an unsuspecting waitress amidst their dancing group.", "are indulging in great food and drinks, while some do try to strike a conversation, others can barely speak a word between eating what must be delicious food.", "who seem to be strangers to each other, all sitting here because there are no other seats. Though they all clearly enjoy each other's company."};
    static constexpr std::string_view names19_1[] = {"the smells of grilled and cooked food coming from the kitchen, it must be the food.", "the amount of cups, tankards and glasses on the table, it's probably the fine alcoholic drinks.", "the amount of men staring at one of the waitresses, it's probably her beauty and charm.", "the amount of women in this tavern and the amount of them trying to subtly eye the bartender, it's probably his good looks and charm.", "the music and how many people are dancing, it must be the live band who just started playing.", "the angelic voice who just started singing, it must be famous for this singer.", "the laughter, cheering and overall enjoyment of everybody, it's probably the people themselves who make this tavern famous.", "the warmth and joy radiating throught the tavern, it's probably the atmosphere that makes this tavern famous."};
    static constexpr std::string_view names1_2[] = {"broken", "cheerless", "cold", "crude", "dark", "depressing", "dire", "dirty", "disturbing", "dull", "gloomy", "horrible", "nasty", "rough", "ugly", "uncomfortable", "unenjoyable", "unfriendly", "uninviting", "unwelcoming"};
    static constexpr std::string_view names5_2[] = {"curtained windows", "darkened windows", "high windows", "large, curtained windows", "large, stained glass windows", "small, curtained windows", "small, stained glass windows", "stained glass windows", "windows", "closed windows", "dirty windows", "dusty windows"};
    static constexpr std::string_view names6_2[] = {"apathy", "awkward silence", "bitterness", "coldness", "depressing vibes", "dire mood", "gloominess", "lack of joy", "lack of life", "lack of people", "lethargy", "lifelessness", "ominous atmosphere", "quiet sorrow", "silence", "uncomfortable atmosphere", "whispers and weeping"};
    static constexpr std::string_view names7_2[] = {"worn, metal door", "worn, wooden door", "hardwooden door", "heavily used, metal door", "heavily used, wooden door", "heavy, metallic door", "heavy, wooden door", "huge, hardwooden door", "old, hardwooden door", "old, metal door", "old, wooden door", "small, softwooden door", "thick, metal door", "thick, wooden door", "dirty, metal door", "dirty, wooden door"};
    static constexpr std::string_view names8_2[] = {"a horrific scent", "dirt and dust from all places", "silence", "a few groans", "watching eyes", "the smell of alcohol", "whispers", "the sound of the wind outside", "a coldness", "aromas of what's probably food, hopefully", "the rinkle of the doorbell", "thick air", "a layer of smoke hanging below the ceiling", "a feeling of discomfort"};
    static constexpr std::string_view names9_2[] = {"coughing into a dirty napkin", "lying in a chair, doing nothing", "pouring a drink for a customer", "reading a newspaper", "rubbing a glass with a cloth, though it's not getting cleaner", "sleeping", "smoking tobacco", "staring at nothing", "talking to a customer", "trying to catch a spider"};
    static constexpr std::string_view names10_2[] = {""};
    static constexpr std::string_view names11_2[] = {"dire", "disgusting", "dreary", "dull", "gloomy", "horrible", "somber"};
    static constexpr std::string_view names13_2[] = {"candles", "broken fans", "huge, dusty lamps", "lanterns", "large, molten candles", "light fixtures", "broken lights", "rows of small, molten candles", "rows of small, broken lights", "sconces", "unlit torches"};
    static constexpr std::string_view names14_2[] = {"completely empty, only covered in a layer of fatty grime", "decorated, if you can call it that, with old paintings covered in dust", "covered in cobwebs and any decoration that does hang there is now unrecognizable", "covered in a layer of dust, making it near impossible to see what the few paintings on the walls are about", "decorated with sport's memorabilia, though it looks like it hasn't been maintained or cleaned for years", "loaded with pictures, though the dust and cobwebs stops you from taking a closer look", "covered in messages, once written by loyal customers and now covered in dust, worn away and mostly unreadable", "decorated with mounted animal heads and small animals, though most have become worn and broken, given the place an even creapier feel", "littered with all sorts of memorabilia, many of which have become unrecognizable due to dust, cobwebs and other dirt", "covered in photographs of what were undoubtedly better times for this tavern. They're now more of a painful reminder of what it has turned into"};
    static constexpr std::string_view names15_2[] = {"could be locals, could be lost souls", "could be anybody really", "you'd like to stay away from", "are silent and they keep to themselves", "are eerily silent, you're unsure if all of them are even alive", "appear to be quite ominous and suspicious in your eyes", "appear to be dangerous in way or another", "probably work less honorable operations"};
    static constexpr std::string_view names16_2[] = {"you'd like to stay as for away from them as possible", "you hope they'll leave you alone, just like you're leaving them alone", "they give you an uncomfortable feeling of dread", "it makes you a little nervous", "you think it's probably time to leave, right now", "it's about the clearest sign you can get, telling you you don't belong", "you begin to fear for your safety, it's probably best to find a different place"};
    static constexpr std::string_view names17_2[] = {""};
    static constexpr std::string_view names18_2[] = {""};
    static constexpr std::string_view names19_2[] = {"the figures lurking in the shadows, it's probably some dirty business", "the dirt and unhygienic circumstances, it's probably food poisoning", "everything you've seen so far, you don't really care and you probably don't want to know", "the things and people you've seen, you're not waiting to find out", "everything in this place, it must be something horrifying", "judging by the people in this place, it's probably something shady and possibly dangerous for strangers like you"};

    ArrayView names1; ArrayView names10; ArrayView names11; ArrayView names13; ArrayView names14; ArrayView names15; ArrayView names16; ArrayView names17; ArrayView names18; ArrayView names19; ArrayView names5; ArrayView names6; ArrayView names7; ArrayView names8; ArrayView names9; double type = 0.0; std::string name; std::string name2; std::string name3; std::string name4; std::string name5; std::string name6; std::string name7; std::string result; size_t random10 = 0; size_t random11 = 0; size_t random12 = 0; size_t random13 = 0; size_t random14 = 0; size_t random15 = 0; size_t random16 = 0; size_t random17 = 0; size_t random18 = 0; size_t random19 = 0; size_t random1a = 0; size_t random1b = 0; size_t random1c = 0; size_t random2 = 0; size_t random3 = 0; size_t random4 = 0; size_t random5 = 0; size_t random6 = 0; size_t random7 = 0; size_t random8a = 0; size_t random8b = 0; size_t random9 = 0; int i = 0;

    type = ((double)(rng() % 10000) / 10000.0);
    names1 = make_view(names1_1);
    names5 = make_view(names5_1);
    names6 = make_view(names6_1);
    names7 = make_view(names7_1);
    names8 = make_view(names8_1);
    names9 = make_view(names9_1);
    names10 = make_view(names10_1);
    names11 = make_view(names11_1);
    names13 = make_view(names13_1);
    names14 = make_view(names14_1);
    names15 = make_view(names15_1);
    names16 = make_view(names16_1);
    names17 = make_view(names17_1);
    names18 = make_view(names18_1);
    names19 = make_view(names19_1);
    if (type > 0.5) {
    names1 = make_view(names1_2);
    names5 = make_view(names5_2);
    names6 = make_view(names6_2);
    names7 = make_view(names7_2);
    names8 = make_view(names8_2);
    names9 = make_view(names9_2);
    names10 = make_view(names10_2);
    names11 = make_view(names11_2);
    names13 = make_view(names13_2);
    names14 = make_view(names14_2);
    names15 = make_view(names15_2);
    names16 = make_view(names16_2);
    names17 = make_view(names17_2);
    names18 = make_view(names18_2);
    names19 = make_view(names19_2);
    }
    random1a = rng() % std::size(names1);
    random1b = rng() % std::size(names1);
    while (random1a == random1b) {
    random1b = rng() % std::size(names1);
    }
    random1c = rng() % std::size(names1);
    while (random1a == random1c || random1b == random1c) {
    random1c = rng() % std::size(names1);
    }
    random2 = rng() % std::size(names2);
    random3 = rng() % std::size(names3);
    random4 = rng() % std::size(names4);
    random5 = rng() % std::size(names5);
    random6 = rng() % std::size(names6);
    random7 = rng() % std::size(names7);
    random8a = rng() % std::size(names8);
    random8b = rng() % std::size(names8);
    while (random8a == random8b) {
    random8b = rng() % std::size(names8);
    }
    random9 = rng() % std::size(names9);
    random10 = rng() % std::size(names10);
    random11 = rng() % std::size(names11);
    random12 = rng() % std::size(names12);
    random13 = rng() % std::size(names13);
    random14 = rng() % std::size(names14);
    random15 = rng() % std::size(names15);
    random16 = rng() % std::size(names16);
    random17 = rng() % std::size(names17);
    random18 = rng() % std::size(names18);
    random19 = rng() % std::size(names19);
    name = "From the outside it looks " + names1[random1a] + ", " + names1[random1b] + " and " + names1[random1c] + ". " + names2[random2] + " and " + names3[random3] + " make up most of the building's outer structure.";
    name2 = "It's " + names4[random4] + " to see through the " + names5[random5] + ", but the " + names6[random6] + " from within can be felt outside.";
    name3 = "As you enter the tavern through the " + names7[random7] + ", you're welcomed by " + names8[random8a] + " and " + names8[random8b] + ".";
    name4 = "The bartender is " + names9[random9] + ", but still manages to welcome you with a " + names10[random10] + ".";
    name5 = "It's as " + names11[random11] + " inside as it is on the outside. " + names12[random12] + " support the upper floor and the " + names13[random13] + " attached to them. The walls are " + names14[random14] + ".";
    name6 = "The tavern itself is packed. " + names15[random15] + " seem to be the primary clientele here, which " + names16[random16] + " Several long tables are occupied by" + names17[random17] + " The other, smaller tables are also occupied by people who " + names18[random18] + " Even most of the stools at the bar are occupied, though nobody seems to mind more company.";
    name7 = "You did hear rumors about this tavern, supposedly it's famous for something, but you can't remember what for. Though judging by " + names19[random19] + " You manage to find a seat and prepare for what will undoubtedbly be a great evening.";
    if (type > 0.5) {
    name4 = "The bartender is " + names9[random9] + " and makes no effort to acknowledge your pressence.";
    name6 = "The tavern itself is almost completely abanonded.  The few people inside " + names15[random15] + ", but whoever they are, " + names16[random16] + ".";
    name7 = "You did hear rumors about this tavern, supposedly it's infamous for something, but for the life of you you can't remember what for. Though juding by " + names19[random19] + ".";
    }
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
    result += "\n";
    result += name6;
    result += "\n";
    result += "\n";
    result += name7;
    return result;
}
