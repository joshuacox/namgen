#include "descriptions-rifles_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_rifles_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"a classic", "a beauty", "excellent", "fear inducing", "intimidating", "near perfect", "amazing", "terrifying", "a new release", "a prototype", "an odd one", "a new model", "a one of a kind", "a new design", "different from most", "unique"};
    static constexpr std::string_view nm2[] = {"admired by many", "commissioned for many around the world", "desired across the globe", "famous around the world", "in high demand", "infamous around the world", "made a name for itself", "noted by many across the world", "praised by many", "prominent across the globe", "purchased and sold by many", "sold to people across the globe", "well-known across the world", "world renowned"};
    static constexpr std::string_view nm3[] = {"celebrated for its consistent aim and accuracy", "celebrated for its precision and reliability", "known as a low cost, high value weapon", "known for its deadly accuracy", "known for its versatility and adaptability", "praised as bang for your buck, due to its low manufacturing cost", "praised for its deadly precision", "praised for its reliability in almost any situation", "praised for its stability, reliability and versatility", "prominent due to its cheap cost and good reliability"};
    static constexpr std::string_view nm4[] = {"overall length", "standard length", "length", "typical length"};
    static constexpr std::string_view nm7[] = {"roughly around", "about", "roughly", "around", "approximately"};
    static constexpr std::string_view nm9[] = {"5.45x39", "5.56x45", "5.8x42", "6.5x39", "6.8x43", "7.62x33", "7.62x35", "7.62x39", "7.62x45", "7.62x51", "7.92x33"};
    static constexpr std::string_view nm10[] = {"a few other calibers have been produced as well", "all other standard calibers are available as well", "it can come in a wide variety of different calibers", "many other calibers are produced as well", "most other calibers are available", "one other caliber is available", "other calibers are available", "other calibers are available, although harder to come by", "other calibers are currently in production", "other calibers have yet to be produced"};
    static constexpr std::string_view nm11[] = {"an upper and lower receiver for easier maintenance", "an upper and lower receiver to allow for easier customization", "an upper and lower receiver to make potential repairs easier and low cost", "its receiver located in front of the pistol grip to increase customizability", "its receiver located in front of the pistol grip which helped increase the barrel length", "its receiver located in front of the pistol grip, allowing for a more ergonomic design", "its receiver located behind the pistol grip for a more compact design", "its receiver located behind the pistol grip to improve maneuverability", "its receiver located behind the pistol grip to save on weight"};
    static constexpr std::string_view nm12[] = {"wood", "plastic", "metal"};
    static constexpr std::string_view nm13[] = {"wood", "plastic", "metal", "premium wood", "ivory", "pearl", "engraved wood", "exotic wood", "horn"};
    static constexpr std::string_view nm14[] = {"your wishes", "your desires", "your purpose", "your goals", "your needs"};
    static constexpr std::string_view nm15[] = {"walnut", "maple", "myrtle wood", "birch", "plastic", "metal", "laminated wood"};
    static constexpr std::string_view nm16[] = {"other materials are available", "other stocks will soon go in production", "a few other stock materials are available", "other stock materials are unfortunately not available yet", "stocks made from a different material have to be custom made", "most other stock materials are widely available", "some other stock materials can be acquired with some effort", "other materials, including luxury materials, are available as well", "other materials have yet to be made available", "other materials aren't available yet and may never be"};
    static constexpr std::string_view nm17[] = {"folding stock", "extendable stock", "detachable stock", "shoulder stock", "wooden stock", "plastic stock", "straight grip stock", "full grip stock", "semi-grip stock"};
    static constexpr std::string_view nm19[] = {"very common as well", "the next most common stock available", "high up on the list of demand", "often preferred instead", "used more often", "just as common and popular", "second in line, although not as common", "very popular as well, despite being less common", "slowly becoming the new standard", "a close second in terms of popularity"};
    static constexpr std::string_view nm20[] = {"drum", "detachable box", "horizontal box", "casket", "rotary", "spool", "STANAG", "hopper", "helical", "saddle-drum", "semi-curved"};
    static constexpr std::string_view nm21[] = {"10", "20", "30", "40", "50", "60", "70", "80", "90", "100"};
    static constexpr std::string_view nm22[] = {"other magazine are available", "plenty of other magazine are available", "a few other magazines are available as well", "this is generally the only available magazine", "other sizes are available", "the magazine comes in various sizes", "while this is the only magazine type, it does come in other sizes", "other magazines types and magazine sizes are available", "two more sizes and one other magazine type is available", "customization for other magazine types and sizes is possible"};
    static constexpr std::string_view nm23[] = {"a push button", "a paddle", "a lever", "both a button and lever"};
    static constexpr std::string_view nm24[] = {"automatic", "semi-auto", "2-round burst", "3-round burst"};
    static constexpr std::string_view nm25[] = {"secret forces", "military police", "military", "freedom fighters", "rebels", "revolutionists", "separatists", "army", "special forces", "marines", "armed forces", "secret service"};
    static constexpr std::string_view nm26[] = {"winning a war", "winning a civil war", "preventing more crime", "preventing war through a show of power", "keeping the peace", "increasing security", "fighting crime on a bigger scale", "upgrading the existing inventory", "updating the existing inventory", "preparing for a likely war", "gaining the upper hand in a guerrilla war", "providing more versatility in terms of weapon choice", "increasing the amount of weapons available", "fighting new threats", "fighting terrorism more efficiently"};
    static constexpr std::string_view nm27[] = {"Japanese man named H. Yoshimitsu", "German man named G. Klauss", "British man named E. Fawkes", "American man named G. Jones", "Canadian man names L. Coats", "South-African man named A. Botha", "Chinese man named B. Chan", "Israeli man named D. Mizrahi", "Russian man named T. Yakovich", "Korean man named Sung S. W", "Indian man named C. Mahal", "Iranian man named B. Javan", "Turkish man named T. Almaz", "Italian man named W. Brocato", "French man named C. Bouvard", "Spanish man named D. Cruz"};
    static constexpr std::string_view nm28[] = {"There are a few other variants of this weapon", "Many other variants of this weapon are available", "There are three other variants of this weapon", "This weapon has quite a few other variants", "Several other variants of this weapon are in production as well", "Two other variants of this weapon are currently in production", "Quite a few other variants of this weapon are available, with more nearing production", "A few variants of this weapon will soon be in production"};
    static constexpr std::string_view nm29[] = {"including a civilian version", "including a semi-auto civilian version", "including two less powerful civilian versions", "but there's no civilian version yet", "but there are no plans for a civilian version", "but a civilian version is most likely out of the question", "but a civilian version is currently on hold", "but the plans for a less powerful civilian version have been delayed"};
    static constexpr std::string_view nm30[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    static constexpr std::string_view nm31[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm32[] = {"Desert Viper", "Black Mamba", "Peacekeeper", "The Ambassador", "Oathkeeper", "Due Diligence", "Boomer", "Bulldog", "Valkyrie", "Vengeance", "Rattlesnake", "Thunder", "Big Daddy", "The Punisher", "The Judge"};

    double nm8 = 0.0; std::string name; std::string name10; std::string name2; std::string name3; std::string name4; std::string name5; std::string name6; std::string name7; std::string name8; std::string name9; std::string nm1b; std::string result; std::string rnd1b; size_t rnd1 = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13a = 0; size_t rnd13b = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd17 = 0; size_t rnd18 = 0; size_t rnd19 = 0; size_t rnd2 = 0; size_t rnd20 = 0; size_t rnd21 = 0; size_t rnd22 = 0; size_t rnd23 = 0; size_t rnd24a = 0; size_t rnd24b = 0; size_t rnd25 = 0; size_t rnd26 = 0; size_t rnd27 = 0; size_t rnd28 = 0; size_t rnd29 = 0; size_t rnd3 = 0; size_t rnd30a = 0; size_t rnd30b = 0; size_t rnd31a = 0; size_t rnd31b = 0; size_t rnd31c = 0; size_t rnd31d = 0; size_t rnd32 = 0; size_t rnd4 = 0; size_t rnd7 = 0; size_t rnd9 = 0; int nm5 = 0; int nm6 = 0;

    nm1b = ", but ";
    nm5 = (rng() % 500) + 600;
    nm6 = (rng() % 255) + 295;
    nm8 = ((double)((rng() % 27) + 27)) / 10;
    rnd1 = rng() % std::size(nm1);
    if (rnd1 < 8) {
    rnd1b = " and ";
    }
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd7 = rng() % std::size(nm7);
    rnd9 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    rnd12 = rng() % std::size(nm12);
    rnd13a = rng() % std::size(nm13);
    while (rnd13a == rnd12) {
    rnd13a = rng() % std::size(nm13);
    }
    rnd13b = rng() % std::size(nm13);
    while (rnd13b == rnd12 || rnd13b == rnd13a) {
    rnd13b = rng() % std::size(nm13);
    }
    rnd14 = rng() % std::size(nm14);
    rnd15 = rng() % std::size(nm15);
    rnd16 = rng() % std::size(nm16);
    rnd17 = rng() % std::size(nm17);
    rnd18 = rng() % std::size(nm17);
    while (rnd18 == rnd17) {
    rnd18 = rng() % std::size(nm17);
    }
    rnd19 = rng() % std::size(nm19);
    rnd20 = rng() % std::size(nm20);
    rnd21 = rng() % std::size(nm21);
    if (rnd20 == 0) {
    while (rnd21 < 5) {
    rnd21 = rng() % std::size(nm21);
    }
    } else {
    while (rnd21 > 4) {
    rnd21 = rng() % std::size(nm21);
    }
    }
    rnd22 = rng() % std::size(nm22);
    rnd23 = rng() % std::size(nm23);
    rnd24a = rng() % std::size(nm24);
    rnd24b = rng() % std::size(nm24);
    while (rnd24a == rnd24b) {
    rnd24b = rng() % std::size(nm24);
    }
    if (rnd24b == 2 || rnd24b == 3) {
    while (rnd24a > 1) {
    rnd24a = rng() % std::size(nm24);
    }
    }
    rnd25 = rng() % std::size(nm25);
    rnd26 = rng() % std::size(nm26);
    rnd27 = rng() % std::size(nm27);
    rnd28 = rng() % std::size(nm28);
    rnd29 = rng() % std::size(nm29);
    rnd30a = rng() % std::size(nm30);
    rnd30b = rng() % std::size(nm30);
    rnd31a = rng() % std::size(nm31);
    rnd31b = rng() % std::size(nm31);
    rnd31c = rng() % std::size(nm31);
    rnd31d = rng() % std::size(nm31);
    rnd32 = rng() % std::size(nm32);
    name = "This weapon is " + nm1[rnd1] + nm1b + nm2[rnd2] + " and " + nm3[rnd3] + ".";
    name2 = "The " + nm4[rnd4] + " of the weapon is " + std::to_string(nm5) + "mm, with a " + std::to_string(nm6) + "mm barrel and the weapon weighs " + nm7[rnd7] + " " + std::to_string(nm8) + "kg.";
    name3 = "It uses " + nm9[rnd9] + "mm rounds, but " + nm10[rnd10] + ".";
    name4 = "The weapon has " + nm11[rnd11] + ". The pistol grip is made out of " + nm12[rnd12] + ", but can also be made out of " + nm13[rnd13a] + " and " + nm13[rnd13b] + " depending on " + nm14[rnd14] + ".";
    name5 = "The stock is made out of " + nm15[rnd15] + ", but " + nm16[rnd16] + ". The standard stock is a " + nm17[rnd17] + ", but the " + nm17[rnd18] + " is " + nm19[rnd19] + ".";
    name6 = "The standard issue magazine is a " + nm20[rnd20] + " which carries " + nm21[rnd21] + " rounds, but " + nm22[rnd22] + ". It has " + nm23[rnd23] + " mechanism to release the magazine.";
    name7 = "The selective fire modes are safe mode, " + nm24[rnd24a] + " and " + nm24[rnd24b] + ".";
    name8 = "This weapon was designed for the " + nm25[rnd25] + " with the purpose of " + nm26[rnd26] + ". It was designed by a " + nm27[rnd27] + ".";
    name9 = nm28[rnd28] + ", " + nm29[rnd29] + ".";
    name10 = "The weapon is called the " + nm30[rnd30a] + nm31[rnd31a] + nm31[rnd31b] + "-" + nm30[rnd30b] + nm31[rnd31c] + nm31[rnd31d] + ", but it usally goes by its nickname '" + nm32[rnd32] + "'.";
    result = "";
    result += name;
    result += "\n";
    result += name2;
    result += "\n";
    result += name3;
    result += "\n";
    result += "\n";
    result += name4;
    result += "\n";
    result += name5;
    result += "\n";
    result += "\n";
    result += name6;
    result += "\n";
    result += name7;
    result += "\n";
    result += "\n";
    result += name8;
    result += "\n";
    result += name9;
    result += "\n";
    result += name10;
    return result;
}
