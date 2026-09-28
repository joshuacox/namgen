#include "descriptions-medieval_clothings_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_medieval_clothings_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"delicate", "elegant", "fancy", "graceful", "luxurious", "relatively simple", "majestic", "modest", "noble", "ornate", "rather simple", "refined", "stylish", "traditional"};
    static constexpr std::string_view nm2[] = {"Queen Anne neckline", "court neckline", "cowl neckline", "draped neckline", "halter neckline", "jewel neckline", "keyhole neckline", "round neckline", "scoop neckline", "semi-sweethear neckline", "square neckline", "sweetheart neckline", "v-neck"};
    static constexpr std::string_view nm3[] = {"charmingly", "daintily", "delicately", "elegantly", "entrancingly", "gracefully", "graciously", "harmoniously", "lightly", "subtly", "tastefully", "wonderfully"};
    static constexpr std::string_view nm4[] = {"comfortable", "delectable", "delicate", "exquisite", "fine", "flowing", "gentle", "ornate", "satiny", "silky", "smooth", "soft", "velvety"};
    static constexpr std::string_view nm5[] = {"buttoned up fabric", "loosely tied fabric", "tightly tied fabric", "corset-like tied fabric", "corset"};
    static constexpr std::string_view nm6[] = {"thin", "thick", "simple", "small", "slender", "light", "dark", "large", "long", "wide", "small"};
    static constexpr std::string_view nm7[] = {"leather belt", "ribbon", "cloth belt", "rope belt", "cloth band"};
    static constexpr std::string_view nm8[] = {"fairly high", "quite high", "low", "high", "fairly low", "quite low"};
    static constexpr std::string_view nm9[] = {"opens up slightly and reveals", "opens up to the right and reveals", "opens up to the left and reveals", "opens up and reveals", "opens up wide and reveals", "flows down and hides", "opens up left and right and reveals", "flows down wide and hides"};
    static constexpr std::string_view nm10[] = {"is shorter at the front and curves outwards", "is much shorter at the front and curves outwards", "is shorter at the front and flows straight down", "reaches the ground generously", "easily reaches the ground in the front", "is longer than the bottom dress and flows straight down", "is longer than the bottom dress and curves outwards", "makes it just to the ground to cover her feet"};
    static constexpr std::string_view nm11[] = {"fair", "large", "good", "short", "decent", "long", "small"};
    static constexpr std::string_view nm12[] = {"broad curve", "narrow curve", "narrow tip", "broad tip", "narrow rectangle", "broad rectangle"};
    static constexpr std::string_view nm13[] = {"very long", "quite long", "a little too long", "purposely too long", "incredibly long", "the length of her arms", "longer than her arms", "slightly shorter than her arms", "almost the length of her arms", "fairly short", "a little short"};
    static constexpr std::string_view nm14[] = {"incredibly wide", "very wide", "quite wide", "wide", "a little wide", "narrow", "quite narrow", "a little narrow", "a comfortable fit", "a loose fit"};
    static constexpr std::string_view nm15[] = {"just below the shoulder", "just below the elbow", "just above the elbow", "below the shoulder", "below the elbow", "above the elbow", "well below the shoulder", "well below the elbow", "well above the elbow", "at the elbow", "at the shoulder"};
    static constexpr std::string_view nm16[] = {"they change color and where ", ""};
    static constexpr std::string_view nm17[] = {"decorative", "elegant", "ornamental", "cosmetic", "embellishing", "ornate", "delicate", "graceful", "luxurious", "simple", "modest", "refined", "stylish"};
    static constexpr std::string_view nm18[] = {"edges", "sleeves", "sleeves and bottom", "bottom", "neckline", "bottom and neckline", "sleeves, bottom and neckline", "sleeves and neckline"};
    static constexpr std::string_view nm19[] = {"long", "very long", "fairly long", "short", "very short", "fairly short"};
    static constexpr std::string_view nm20[] = {"leather", "hide", "furred", "cloth", "animal skin", "silky", "velvety"};
    static constexpr std::string_view nm21[] = {"just below his waist", "well below his waist", "just below his groin", "well below his groin", "just below his knees", "well below his knees", "just above his waist", "well above his waist", "just above his groin", "well above his groin", "just above his knees", "well above his knees", "his waist", "his knees", "his groin"};
    static constexpr std::string_view nm22[] = {"tightly tied with string", "loosely tied with string", "buttoned up completely", "almost completely buttoned up", "half buttoned up", "barely tied with string", "barely buttoned up", "bound"};
    static constexpr std::string_view nm23[] = {"at the center", "at the left side", "at the right side", "at the top left side", "at the top right side", "at the bottom left side", "at the bottom right side", "slightly off-center"};
    static constexpr std::string_view nm25[] = {"incredibly wide", "very wide", "quite wide", "wide", "a little wide", "narrow", "quite narrow", "a little narrow", "a comfortable fit", "a loose fit"};
    static constexpr std::string_view nm26[] = {"his hands", "just above his hands", "well below his hands", "below his hands", "well above his hands", "his wrists", "just below his wrists", "just above his wrists", "well above his wrists", "well below his wrists"};
    static constexpr std::string_view nm27[] = {"a single thread lining from top to bottom", "several thread linings from top to bottom", "a single thread lining at the sleeve ends", "several thread linings at the sleeve ends", "a decorative band at the edges", "a decorative band almost at the edges", "a single thread lining and a decorative band"};
    static constexpr std::string_view nm28[] = {"round neckline", "wide, round neckline", "narrow, round neckline", "deep, round neckline", "wide v-neck", "narrow v-neck", "deep v-neck", "rectangular neckline", "wide, rectangular neckline", "narrow, rectangular neckline", "deep, rectangular neckline"};
    static constexpr std::string_view nm29[] = {"rough", "elegant", "fancy", "graceful", "luxurious", "relatively simple", "majestic", "modest", "noble", "ornate", "rather simple", "refined", "stylish", "traditional"};
    static constexpr std::string_view nm30[] = {"thin", "thick", "simple", "small", "big", "light", "dark", "large", "long", "wide", "small"};
    static constexpr std::string_view nm31[] = {"leather belt", "cloth belt", "rope belt", "cloth band"};
    static constexpr std::string_view nm32[] = {"a big belt buckle", "a simple knot", "a small belt buckle", "an intricate knot", "an ornate pin", "a decorative pin"};
    static constexpr std::string_view nm33[] = {"purely decorative and a sign of wealth", "mostly decorative and a sign of wealth", "entirely decorative and a way to show off", "solely decorative and a status symbol", "mostly decorative, but does serve its purpose", "partially decorative, but mostly a purposeful addition", "slightly decorative, but mostly there to hang things from", "almost entirely a functional addition", "purely a functional addition", "a functional addition, but does have some decorative value"};
    static constexpr std::string_view nm35[] = {"leather", "hide", "furred", "soft leather", "hard leather", "bound cloth"};
    static constexpr std::string_view nm36[] = {"rare", "very rare", "fairly rare", "fairly uncommon", "very uncommon", "pretty uncommon", "pretty rare", "pretty unusual", "pretty unique"};
    static constexpr std::string_view nm37[] = {"quite simple", "a simple design", "an ordinary design", "a common design", "a common type", "not that special", "a design found commonly", "not any different from others"};
    static constexpr std::string_view nm38[] = {"boots", "shoes"};
    static constexpr std::string_view nm39[] = {"leather", "hide", "fur", "leather", "leather", "cloth"};

    std::string name; std::string name2; std::string name3; std::string nm24; std::string result; std::string rnd24; std::string tp; size_t rnd = 0; size_t rnd1 = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd16b = 0; size_t rnd17 = 0; size_t rnd18 = 0; size_t rnd19 = 0; size_t rnd2 = 0; size_t rnd20 = 0; size_t rnd21 = 0; size_t rnd22 = 0; size_t rnd23 = 0; size_t rnd25 = 0; size_t rnd26 = 0; size_t rnd27 = 0; size_t rnd28 = 0; size_t rnd29 = 0; size_t rnd3 = 0; size_t rnd30 = 0; size_t rnd31 = 0; size_t rnd32 = 0; size_t rnd33 = 0; size_t rnd34 = 0; size_t rnd35 = 0; size_t rnd36 = 0; size_t rnd37 = 0; size_t rnd38 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

    nm24 = " jacket ";
    tp = type;
    if (tp == 1) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd1 = rng() % std::size(nm1);
    while (rnd == rnd1) {
    rnd1 = rng() % std::size(nm1);
    }
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    rnd9 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    rnd12 = rng() % std::size(nm12);
    rnd13 = rng() % std::size(nm13);
    rnd14 = rng() % std::size(nm14);
    rnd15 = rng() % std::size(nm15);
    rnd16 = rng() % std::size(nm16);
    rnd16b = rng() % std::size(nm6);
    rnd17 = rng() % std::size(nm17);
    rnd18 = rng() % std::size(nm18);
    name = "Her " + nm1[rnd] + " dress flows from top to bottom and has a " + nm2[rnd2] + ", which " + nm3[rnd3] + " reveals the " + nm1[rnd1] + " dress worn below it. The " + nm4[rnd4] + ", " + nm5[rnd5] + " of her dress covers her stomach where the continuous flow is broken up by a " + nm6[rnd6] + " " + nm7[rnd7] + " worn " + nm8[rnd8] + " around her waist.";
    name2 = "Below the " + nm7[rnd7] + " the dress " + nm9[rnd9] + " the dress below. The front of the top dress " + nm10[rnd10] + ", the back continues to flow a " + nm11[rnd11] + " length behind her and ends in a " + nm12[rnd12] + ".";
    name3 = "Her sleeves are " + nm13[rnd13] + " and " + nm14[rnd14] + ", their flow is broken up " + nm15[rnd15] + " where " + nm16[rnd16] + "they're divided by " + nm6[rnd16b] + ", " + nm17[rnd17] + " bands, these are the same fabric and color used to outline the " + nm18[rnd18] + " of the dress.";
    } else {
    rnd19 = rng() % std::size(nm19);
    rnd20 = rng() % std::size(nm20);
    rnd21 = rng() % std::size(nm21);
    rnd22 = rng() % std::size(nm22);
    rnd23 = rng() % std::size(nm23);
    if (rnd19 > 2) {
    nm24 = " shirt ";
    }
    rnd25 = rng() % std::size(nm25);
    rnd26 = rng() % std::size(nm26);
    rnd27 = rng() % std::size(nm27);
    rnd28 = rng() % std::size(nm28);
    rnd29 = rng() % std::size(nm29);
    rnd30 = rng() % std::size(nm30);
    rnd31 = rng() % std::size(nm31);
    rnd32 = rng() % std::size(nm32);
    rnd33 = rng() % std::size(nm33);
    rnd34 = rng() % std::size(nm25);
    rnd35 = rng() % std::size(nm35);
    rnd36 = rng() % std::size(nm36);
    rnd37 = rng() % std::size(nm37);
    rnd38 = rng() % std::size(nm38);
    name = "His " + nm19[rnd19] + " sleeved, " + nm20[rnd20] + " jacket covers him to " + nm21[rnd21] + " and is " + nm22[rnd22] + " " + nm23[rnd23] + ". The sleeves of his" + nm24 + "are " + nm25[rnd25] + " and reach down to " + nm26[rnd26] + ", they're decorated with " + nm27[rnd27] + ".";
    name2 = "The jacket has a " + nm28[rnd28] + " which reveals part of the " + nm29[rnd29] + " shirt worn below it and is worn with a " + nm30[rnd30] + " " + nm31[rnd31] + ", which is held together by " + nm32[rnd32] + ". The " + nm31[rnd31] + " is " + nm33[rnd33] + ".";
    name3 = "His pants are simple and " + nm25[rnd34] + " and reach down to his " + nm35[rnd35] + " " + nm38[rnd38] + ". The " + nm38[rnd38] + " are made from a " + nm36[rnd36] + " " + nm39[rnd35] + ", but are otherwise " + nm37[rnd37] + ".";
    }
    result = "";
    result += name;
    result += "\n";
    result += "\n";
    result += name2;
    result += "\n";
    result += "\n";
    result += name3;
    return result;
}
