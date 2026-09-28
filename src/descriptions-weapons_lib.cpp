#include "descriptions-weapons_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_weapons_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"fairly large", "fairly long", "fairly short", "fairly small", "large", "long", "short", "small", "very long", "very short"};
    static constexpr std::string_view nm2[] = {"thick", "thin", "wide", "narrow", "slim", "broad"};
    static constexpr std::string_view nm3[] = {"straight", "smooth", "slightly curved", "warped", "curved", "jagged", "barbed"};
    static constexpr std::string_view nm4[] = {"ceramic", "diamond", "copper", "bronze", "glass", "ivory", "silver", "adamantium", "cystal", "folded steel", "iron", "mithril", "obsidian", "steel", "titanium"};
    static constexpr std::string_view nm5[] = {"common", "dull", "elegant", "expensive", "extravagant", "extremely rare", "fairly common", "gilded", "high quality", "lavish", "low-cost", "ordinary", "rare", "regular", "strange", "uncommon"};
    static constexpr std::string_view nm6[] = {"black", "bronze", "brown", "dark brown", "deep orange", "emerald green", "forest green", "gold colored", "green", "grey", "ivory", "jade green", "light brown", "maroon", "navy blue", "onyx", "red", "royal blue", "ruby red", "sapphire blue", "scarlet", "white"};
    static constexpr std::string_view nm7[] = {"bear leather", "boar hide", "buffalo skin", "cow leather", "crocodile leather", "deerskin", "goat leather", "pig leather", "ray skin", "salmon leather", "scaled leather", "shark skin", "smooth leather", "snake leather", "sting ray leather", "wolf leather"};
    static constexpr std::string_view nm8[] = {"One sharp edge", "A single, sharp edge", "With just one razor-sharp edge", "Because its sharp on just one edge", "With a single, sharp edge", "A sharp, dual-edged blade", "The sharp, dual-edged blade", "Dual-edged and razor-sharp", "With its sharp, dual-edged blade", "Because its sharp on both its edges", "A fine, sharp point", "The razor-sharp point", "With a point as sharp as a razor", "With just a razor-sharp point", "Because it only has a razor-sharp point"};
    static constexpr std::string_view nm9[] = {"makes this weapon ideal for both blocking and slicing, your enemies won't stand a chance.", "makes this a perfect weapon to block attacks and slice enemies to tiny, little pieces.", "makes sure this weapon is not just for hacking and slashing, but also great to block incoming attacks.", "this weapon is ideal for both cleaving enemies as well as blocking their attacks.", "this weapon will protect you from incoming blows while also giving you the ability to shred your enemies to pieces.", "this weapon is the perfect choice for slicing and dicing while also offering you a way to effectively block attacks.", "makes this weapon the best choice for both cleaving and stabbing your enemies with ferocious power.", "makes this the ideal weapon if you're looking to slice, dice, stab and jab your enemies.", "makes this weapon the choice for any warrior looking for a versatile weapon ideal for any combat style.", "this weapon will slice, dice, stab and jab your enemies and shred whatever's left of them.", "this weapon is the champion's choice. It'll crush your enemies with cleaving hacks and piercing stabs.", "this weapon makes for the best choice for those looking for power, versatility and general awesomeness.", "makes this weapon ideal to pierce your enemies and turn them into a sieve.", "makes this weapon a perfect choice if you wish to puncture your enemies to death with ruthless speed and precision.", "makes this weapon the best choice if you want to pierce, prick, puncture and peforate your enemies.", "this weapon is the ideal choice to turn your enemies into Swiss cheese. ", "this weapon will make sure your enemies are full of holes with deadly speed and precision.", "this weapon will cause your enemies to leak from thousands of holes before they even know what happened."};
    static constexpr std::string_view nm10[] = {"small", "thin", "narrow", "wide", "broad", "large", "barbed", "jagged", "spiked"};
    static constexpr std::string_view nm11[] = {"slightly curved", "straight", "curved", "warped", "twisted", "curled"};
    static constexpr std::string_view nm12[] = {"just large enough to protect the owner's fingers", "just large enough to prevent it from slipping from your hands", "just large enough to make sure your fingers are safe and the blade will remain firmly in your hands", "just large enough to give the blade the perfect weight balance", "offering just enough protection to the owner's hands, as well as adding a weight balance to the blade", "offering plenty of protection to the owner's hands and thus his or her life", "adding weight to the blade for a better weight balance, as well as offering hand protection during battle", "creating the ideal weight balance to allow for smooth and accurate swings with this blade", "adding just enough weight to make sure the blade sits firmly in the owner's hand and protecting those same hands as well", "which makes sure the blade is both balanced and capable of protecting the owner's hands against any sliding sword"};
    static constexpr std::string_view nm13[] = {"a simple", "a plain", "a basic", "an intricate", "an elaborate", "a decorative", "a lavish", "an ornamented", "an elegant", "a jeweled", "a gilded"};
    static constexpr std::string_view nm14[] = {"sphere", "curl", "coil", "twist", "loop", "orb", "ring", "cross", "dragon head", "lion head", "bear paw", "hawk beak", "eye", "wolf head", "skull", "flame", "eagle wing", "horn", "bear head", "lion paw", "panther head", "claw", "tooth", "crow head", "fish scale", "snake head", "owl head", "dragon tail", "snake", "spider"};
    static constexpr std::string_view nm15[] = {"which is common on many weapons", "which shows how ordinary this weapon is", "a sign of mass production", "which tells you this weapon belongs to a soldier or commoner", "so this weapon is for just about anybody with the right amount of cash", "this weapon clearly isn't a one of a kind", "marking the house it belongs to", "a clear sign this weapon belongs to a champion", "this weapon wasn't created by just any blacksmith", "this weapon was clearly a custom order, probably by an important figure", "this is clearly a weapon not meant to be wielded by a commoner", "the cost of this weapon must have been high", "this weapon is clearly meant to be taken care of with dedication", "a unique design for a unique weapon"};
    static constexpr std::string_view nm16[] = {"small", "fairly small", "large", "wide", "thick", "massive", "fairly large"};
    static constexpr std::string_view nm17[] = {"marked", "engraved", "decorated", "decorated"};
    static constexpr std::string_view nm18[] = {"the sword maker's symbol", "the sword maker's signature", "a quality symbol", "the symbol of the house this sword belongs to", "the symbol of its owner", "a fairly common gem", "common gems", "precious gems", "gilded linings", "a rare gem"};
    static constexpr std::string_view nm19[] = {"a symbol one can be proud of", "a symbol of true greatness", "a symbol many are jealous of", "a famous symbol and rightfully so", "a symbol many would kill for", "an unimpressive symbol at the best of times", "not the most impressive symbol to be fair", "a symbol which doesn't prove much", "a symbol some might be embarrased of", "a decent symbol for a decent weapon", "commonness for a commonly made weapon", "anything better would be a waste", "nothing too impressive, but that's to be expected", "but the weapon is supposed to cut after all, not look fancy", "but to be fair, gems aren't what makes a weapon great", "fancy decorations for a fancy sword", "which is to be expected from such an elegant weapon", "no expense is spared for this gorgeous weapon", "fine details which prove how carefully this weapon was crafted", "this weapon is clearly meant for an important figure"};
    static constexpr std::string_view nm20[] = {"bare", "simple", "fairly simple", "unadorned", "engraved", "engraved"};
    static constexpr std::string_view nm21[] = {"No markings can be found", "No decorations or engraved patterns", "No markings, no decorations and no engravings", "No decorations of any sorts are on it", "Several runes are etched into the blade", "A line of text is engraved on the blade", "Seemingly strange markings are carved into the blade", "Ancient symbols are engraved on the blade", "Intricate decorational patterns have been carefully etched into the blade", "Religious symbols have been delicately etched into the blade", "Several words of power have been artistically etched into the blade", "The symbol of the owner's house is engraved on the blade", "The owner's name has been artistically etched into the blade", "The name of the owner's house has been engraved on the blade", "The name of the blade has been engraved into the blade with artistic elegance"};
    static constexpr std::string_view nm22[] = {". Engravings are too costly and time consuming for an ordinary weapon", ", an everyday weapon needs no decorations", ", engravings, marks and decorations are only for special or expensive weapons", ". This weapon is meant for fighting, decorations don't make you fight better", ". Engravings are too costly, but perhaps the owner can have the weapon blessed instead", ", with the exception of the small scratches from battle, which are perhaps the best marks for a weapon", ", any engravings could only diminish the strength of the blade", ". While the hilt is as elegant as its owner, the blade has to be as strong as its owner", ", the blade needs no decorations, it only needs to be strong and sharp", ". A seathed sword has a hidden blade and a sword in use will be dirty and bloody, so only the hilt needs decorations", ", but the blade will surely be decorated in battle", ", which is supposed to give the weapon and its owner extra strength", ", which adds mystery and supposedly more power to the weapon", ", which, like a blessing, is supposed to protect the weapon's owner in battle", ", which only adds to the elegance of this weapon, as well as its cost", ", which is supposed to contain a hidden power", ". This is clearly no ordinary weapon to be used by anybody", ". This weapon is clearly a priced possession owned by somebody important", ". A weapon this magnificent is not meant for battle", ", which further adds to the uniqueness of this valuable weapon", ", which hints at the purpose, as well as the age of this elegant weapon", ". This weapon must be old and incredibly valuable, who knows what it has seen", ", which just shows how special this weapon truly is", ". This weapon is no ordinary weapon, that much is clear", ". This weapon and its master are both famous and infamous throughout the world", ". This weapon is feared and admired throughout the lands and rightfully so", ". You would not want to meet this blade, let alone its owner, in battle"};
    static constexpr std::string_view nm23[] = {"only during celebrations", "only during special occassions", "only on rare occassions", "only for ceremonial purposes", "only as a bragging object", "only as a decorational piece", "only as a display of wealth", "by royalty and the noble", "only by those with vast amounts of wealth", "by just about anybody", "by anybody with a decent amount of money", "the lower ranked guards", "by the royal guard", "by higher ranked guards", "by champions and proven fighters"};
    static constexpr std::string_view nm24[] = {"A decent weapon which serves its purpose", "Whatever the purpose of its owner, this weapon will be sufficient", "A respectable weapon for mostly respectable people", "A great weapon for proven fighters", "An excellent weapon for the defense of the country", "An exceptional weapon for exceptional fighters", "The capable hands of the country's greatest defenders deserve nothing less than this weapon's excellence", "None deserve this weapon more than the greatest fighters of all", "You'd expect nothing less from such fighters", "Worn by the wealthiest among us, but not always the most deserving among us", "Worn by the high and mighty as a display of status, wealth and power", "An elegant and valuable weapon for mostly elegant and respectable people", "Perhaps not great in battle, but definitely great at showing off wealth and power", "An exceptional weapon carried by exceptional people, for better and worse", "Any occassion which requires royalty also requires this weapon by their side", "From royal weddings and births to cutting ribbons and slicing pie, this weapon has plenty of ceremonies to attend", "A weapon this rare and magnificent is only used in the most important, royal ceremonies", "This ceremonial weapon has seen king's being crowned, princes and princesses being born and kings and queens being married", "While not rare and impressive enough for the most important celebrations, this weapon has seen its fair share of ceremonies"};

    std::string name; std::string name2; std::string name3; std::string name4; std::string name5; std::string name6; std::string name7; std::string result; size_t rnd1 = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd17 = 0; size_t rnd18 = 0; size_t rnd19 = 0; size_t rnd2 = 0; size_t rnd20 = 0; size_t rnd21 = 0; size_t rnd22 = 0; size_t rnd23 = 0; size_t rnd24 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

    rnd1 = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    if (rnd3 > 4) {
    while (rnd8 < 4) {
    rnd8 = rng() % std::size(nm8);
    }
    }
    if (rnd8 == 0 || rnd8 == 1) {
    rnd9 = ((rng() % 3) + 0);
    } else if (rnd8 > 1 && rnd8 < 5) {
    rnd9 = ((rng() % 3) + 3);
    } else if (rnd8 == 5 || rnd8 == 6) {
    rnd9 = ((rng() % 3) + 6);
    } else if (rnd8 > 6 && rnd8 < 10) {
    rnd9 = ((rng() % 3) + 9);
    } else if (rnd8 == 10 || rnd8 == 11) {
    rnd9 = ((rng() % 3) + 12);
    } else {
    rnd9 = ((rng() % 3) + 15);
    }
    rnd10 = rng() % std::size(nm10);
    if (rnd10 < 2) {
    rnd12 = ((rng() % 5) + 0);
    } else {
    rnd12 = ((rng() % 5) + 5);
    }
    rnd11 = rng() % std::size(nm11);
    rnd13 = rng() % std::size(nm13);
    if (rnd13 < 3) {
    rnd14 = ((rng() % 8) + 0);
    rnd15 = ((rng() % 6) + 0);
    }
    else {
    rnd14 = rng() % std::size(nm14);
    rnd15 = ((rng() % 8) + 6);
    }
    rnd16 = rng() % std::size(nm16);
    rnd17 = rng() % std::size(nm17);
    if (rnd17 < 2) {
    rnd18 = ((rng() % 5) + 0);
    } else {
    if (rnd13 < 3) {
    rnd18 = ((rng() % 2) + 5);
    } else {
    rnd18 = ((rng() % 3) + 7);
    }
    }
    if (rnd18 < 4) {
    if (rnd13 < 3) {
    rnd19 = ((rng() % 5) + 5);
    } else {
    rnd19 = ((rng() % 5) + 0);
    }
    } else {
    if (rnd13 < 3) {
    rnd19 = ((rng() % 5) + 10);
    } else {
    rnd19 = ((rng() % 5) + 15);
    }
    }
    rnd20 = rng() % std::size(nm20);
    if (rnd20 < 4) {
    rnd21 = ((rng() % 4) + 0);
    } else {
    rnd21 = ((rng() % 10) + 4);
    }
    if (rnd21 < 4) {
    if (rnd13 < 3) {
    rnd22 = ((rng() % 7) + 0);
    } else {
    rnd22 = ((rng() % 4) + 7);
    }
    } else {
    if (rnd21 < 12 && rnd21 > 3) {
    rnd22 = ((rng() % 11) + 5);
    } else if (rnd21 > 11) {
    rnd22 = ((rng() % 5) + 22);
    }
    }
    if (rnd22 < 6) {
    rnd23 = ((rng() % 3) + 9);
    } else if (rnd22 < 11 && rnd22 > 5) {
    rnd23 = ((rng() % 3) + 12);
    } else if (rnd22 > 10 && rnd22 < 16) {
    rnd23 = ((rng() % 4) + 0);
    } else if (rnd22 > 15 && rnd22 < 22) {
    rnd23 = ((rng() % 9) + 0);
    } else {
    rnd23 = ((rng() % 5) + 4);
    }
    if (rnd23 < 3) {
    rnd24 = ((rng() % 10) + 15);
    } else if (rnd23 > 2 && rnd23 < 9) {
    rnd24 = ((rng() % 5) + 10);
    } else if (rnd23 > 8 && rnd23 < 12) {
    rnd24 = ((rng() % 4) + 0);
    } else {
    rnd24 = ((rng() % 6) + 4);
    }
    name = "A " + nm1[rnd1] + ", " + nm2[rnd2] + ", " + nm3[rnd3] + " blade made of " + nm4[rnd4] + " is held by a grip wrapped in " + nm5[rnd5] + ", " + nm6[rnd6] + " " + nm7[rnd7] + ".";
    name2 = nm8[rnd8] + " " + nm9[rnd9];
    name3 = "The blade has a " + nm10[rnd10] + ", " + nm11[rnd11] + " cross-guard, " + nm12[rnd12] + ".";
    name4 = " The cross-guard has " + nm13[rnd13] + " " + nm14[rnd14] + " on each side, " + nm15[rnd15] + ".";
    name5 = "A " + nm16[rnd16] + " pommel is  " + nm17[rnd17] + " with " + nm18[rnd18] + ", " + nm19[rnd19] + ".";
    name6 = "The blade itself is " + nm20[rnd20] + ". " + nm21[rnd21] + nm22[rnd22] + ".";
    name7 = "This weapon is used " + nm23[rnd23] + ". " + nm24[rnd24] + ".";
    result = "";
    result += name;
    result += "\n";
    result += name2;
    result += "\n";
    result += "\n";
    result += name3;
    result += name4;
    result += "\n";
    result += name5;
    result += "\n";
    result += "\n";
    result += name6;
    result += "\n";
    result += name7;
    return result;
}
