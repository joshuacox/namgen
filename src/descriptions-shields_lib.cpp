#include "descriptions-shields_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_shields_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"durable", "forceful", "impressive", "mighty", "powerful", "reinforced", "robust", "solid", "sturdy", "tenacious", "tough"};
    static constexpr std::string_view nm2[] = {"rounded heater shield", "pointed heater shield", "sharp heater shield", "diamond heater shield", "triangular heater shield", "wide oval shield", "long oval shield", "Greek-style shield", "rounded oval shield", "long afro shield", "pointed afro shield", "rounded afro shield", "Roman-style shield", "Norman kite shield", "triangular kite shield", "rounded kite shield", "pointed kite shield", "teardrop kite shield", "agular coffin shield", "rounded coffin shield", "round shield", "square shield", "war-door shield", "Wankel shield"};
    static constexpr std::string_view nm3[] = {"adamantite", "ebonsteel", "hardwood", "iron", "ironbark", "mithril", "steel"};
    static constexpr std::string_view nm4[] = {"a forceful safeguard", "a mighty buffer", "a powerful buffer", "a powerful bulwark", "a robust cover", "a stable barricade", "a stalwart cover", "a tenacious barricade", "a tough safeguard", "a very resilient buffer", "a very resistant defense", "an agile safety guard", "an unbreakable defense", "an unyielding safeguard", "great lasting cover", "great protection", "heavy duty protection", "reinforced protection", "unyielding protection", "vigorous protection"};
    static constexpr std::string_view nm5[] = {"arrows and bolts", "bludgeoning attacks", "coordinated attacks", "crushing attacks", "lunging attacks", "piercing attacks", "slashing attacks", "smaller ballistics", "stabbing attacks"};
    static constexpr std::string_view nm6[] = {"This is no coincidence", "Rightfully so as well", "This isn't a mere fluke", "This is the result of expertise", "This isn't just any old shield", "A true work of mastery", "Not the work of a mere amateur", "The result of years of experience", "Perfected throughout the ages", "Mastery and perfection came into play"};
    static constexpr std::string_view nm7[] = {"abyss dwarves", "aurora gnomes", "chaos gnomes", "darkwood elves", "draconic goblins", "ebonwood elves", "enigma goblins", "fel orcs", "fury dragonkin", "lightwell humans", "lunar dragonkin", "nightmare trolls", "shadow trolls", "summit dwarves", "titan orcs", "ursine humans"};
    static constexpr std::string_view nm8[] = {"a chronomatic", "a cryo", "a draconic", "a hydro", "a pyro", "a storm", "a thaumatic", "a volcanic", "an ancient", "an arcane", "an elemental"};
    static constexpr std::string_view nm9[] = {"ornamented", "embellished", "enhanced", "emblazoned", "augmented", "reinforced"};
    static constexpr std::string_view nm10[] = {"small spikes", "large spikes", "double rows of small spikes", "layered metal plates", "metal plating", "metal rings", "small metal studs", "large metal studs", "thick metal plating", "a metal lining", "a thick metal lining", "broad metal lining", "layered metal scales", "layered metal rings", "double rows of metal studs"};
    static constexpr std::string_view nm11[] = {"intricate metalwork", "gilded linings", "decorative paintwork", "feather-like metalwork", "intricate metal patterns", "a simple layer of paint", "inscribed runes", "engraved words", "bone-like ornaments", "a scaly texture", "intricate paintings", "wing-like metalwork", "golden studs", "decorative gems", "small repeated symbols"};
    static constexpr std::string_view nm12[] = {"decorated", "adorned", "embellished", "garnished", "ornamented"};
    static constexpr std::string_view nm13[] = {"a painting of a sigil", "emblems of victory", "several skulls", "animal horns", "a large gem", "elaborate paintwork", "complex metalwork", "symmetrical metalwork", "painted symbols", "a painted animal head", "several gem stones", "metalwork wings", "symbols of nature", "metalwork scales", "a symbol of rank", "intertwining metalwork", "symmetrical paintwork", "religious symbols", "bones", "small spikes", "a large spike", "small scrolls attached with wax", "zealous texts", "seemingly magical runes", "symbols of personal accomplishments"};
    static constexpr std::string_view nm14[] = {"has seen its fair share of battle", "has seen better, peaceful times", "has been through numerous battles", "has experienced the art of war", "knows the ins and outs of battle", "has been through hell and back", "has seen glory and victory", "has served its master well", "stood the tests of battle", "never failed its master", "has yet to see its first battle", "has yet to taste blood", "hasn't been through hell just yet", "never went to war", "has only known times of peace", "has yet to protect its master", "hasn't felt the clash of a sword", "knows not what battle is", "is naive to the ways of war", "has yet to prove itself"};
    static constexpr std::string_view nm15_1[] = {"Everything's in pristine condition", "Not a scratch or mark to be found", "All polished and shiny", "As if freshly forged and crafted", "Nothing has left its mark yet", "As if carefully looked after", "With a full life ahead of it"};
    static constexpr std::string_view nm17_1[] = {"will ever know the glory of victory", "will one day need to prove its worth in battle", "is even meant for battle or for ceremony", "is going to get a chance to shine in battle", "will ever need to protect its master", "will ever be called upon in some future war", "will ever be matched with a master of its equal", "is ever going to be the final barricade between life and death", "will ever get to stare at death and smile", "will one day be praised and admired"};
    static constexpr std::string_view nm18_1[] = {"this shield is ready to prove itself", "nothing will stand in its way", "this shield will serve its master well", "this shield is ready for anything and everything", "this shield craves a master of its equal", "this shield yearns for glory", "glory shall come to this shield in one way or another", "this shield can overcome anything", "this shield shall always stand between its master and death", "this shield will always be by the side of its master"};
    static constexpr std::string_view nm15_2[] = {"Dents and scratches", "Scratches and marks", "Scores and scratches", "Dints and dents", "Nicks and cuts", "Indentions and scrapes", "Damage and trauma", "Gashes and cuts", "Fissures and dents", "Holes and cracks"};
    static constexpr std::string_view nm17_2[] = {"perhaps fond memories of victory", "a legacy of battles long over", "visible reminders of victory and loss", "echos of both glory and death", "mementos of beating the odds", "likely painful reminders of cruel times", "trophies of defeating death", "signs of perseverance and power", "warnings of the endurance of both shield and master", "indications you may wish to avoid its master's path"};
    static constexpr std::string_view nm18_2[] = {"this shield is ready for more", "this shield's days are far from over", "this shield hungers for more", "this shield isn't done serving just yet", "neither shield nor master is ready to rest", "nothing will get passed this shield", "this shield will never yield", "glory and victory are waiting once more", "death will have to wait a little while longer", "there's no stopping now"};

    ArrayView nm15; ArrayView nm17; ArrayView nm18; std::string name; std::string name2; std::string name3; std::string name4; std::string name5; std::string nm16; std::string result; size_t rnd1 = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13a = 0; size_t rnd13b = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd17 = 0; size_t rnd18 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5a = 0; size_t rnd5b = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

    nm15 = make_view(nm15_1);
    nm16 = ", who knows if this shield ";
    nm17 = make_view(nm17_1);
    nm18 = make_view(nm18_1);
    rnd1 = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5a = rng() % std::size(nm5);
    rnd5b = rng() % std::size(nm5);
    while (rnd5a == rnd5b) {
    rnd5b = rng() % std::size(nm5);
    }
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    rnd9 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    rnd12 = rng() % std::size(nm12);
    rnd13a = rng() % std::size(nm13);
    rnd13b = rng() % std::size(nm13);
    while (rnd13a == rnd13b) {
    rnd13b = rng() % std::size(nm13);
    }
    rnd14 = rng() % std::size(nm14);
    if (rnd14 < 10) {
    nm15 = make_view(nm15_2);
    nm16 = " made by who knows what leave ";
    nm17 = make_view(nm17_2);
    nm18 = make_view(nm18_2);
    }
    rnd15 = rng() % std::size(nm15);
    rnd17 = rng() % std::size(nm17);
    rnd18 = rng() % std::size(nm18);
    name = "This " + nm1[rnd1] + " " + nm2[rnd2] + ", made from " + nm3[rnd3] + ", offers " + nm4[rnd4] + ", especially against " + nm5[rnd5a] + " and " + nm5[rnd5b] + ".";
    name2 = nm6[rnd6] + ", as this shield was forged by " + nm7[rnd7] + " in " + nm8[rnd8] + " workshop.";
    name3 = "The shield's edges are " + nm9[rnd9] + " with " + nm10[rnd10] + " and have been decorated with " + nm11[rnd11] + ".";
    name4 = "Its center is " + nm12[rnd12] + " with " + nm13[rnd13a] + " and " + nm13[rnd13b] + ".";
    name5 = "It's clear this shield " + nm14[rnd14] + ". " + nm15[rnd15] + nm16 + nm17[rnd17] + ", but one this is for sure: " + nm18[rnd18] + ".";
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
