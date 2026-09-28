#include "descriptions-fancy_clothings_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_fancy_clothings_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"covers her shoulders halfway", "covers her shoulders entirely", "covers her shoulders almost fully", "covers her shoulders only barely with 2 spaghetti straps", "leaves the top of her shoulders uncovered, but does cover the sides", "leaves her shoulders mostly uncovered", "leaves her shoulders uncovered, instead it's supported around her neck", "covers just one of her shoulders, leaves the other uncovered", "covers only a small portion of her shoulders"};
    static constexpr std::string_view nm2[] = {"an elegant", "a graceful", "a stylish", "a delicate", "a simple", "a modest", "a fancy", "a beautiful", "a tasteful"};
    static constexpr std::string_view nm3[] = {"Queen Anne neckline", "court neckline", "cowl neckline", "draped neckline", "halter neckline", "jewel neckline", "keyhole neckline", "plunging neckline", "round neckline", "scoop neckline", "semi-sweetheart neckline", "square neckline", "sweetheart neckline", "v-neck"};
    static constexpr std::string_view nm4[] = {"tight", "snug", "close", "loose", "comfortable", "relaxed"};
    static constexpr std::string_view nm5[] = {"accentuates her breasts, but it does so in an elegant manner", "puts the focus on her breasts, but in a graceful manner", "emphasizes her breasts in an elegant and dignified manner", "highlights her breasts, but it does so in a refined and modest manner", "helps to accentuate her breasts without making it look tacky", "makes the dress look sleek and elegant", "adds to the grace and elegance of the dress", "gives the dress a classy and polished look", "makes the dress look smart and stylish", "is meant to draw attention to her breasts, but in a graceful and elegant manner", "removes the focus from her breasts, but without making it look sloppy", "covers up her breasts, but does so without making it look awkward or messy", "helps remove some of the unwanted attention on her breasts, but does so by still looking elegant", "makes the dress look comfortable, yet elegant and stylish", "gives the dress a relaxed, yet graceful look", "makes the dress both enjoyable to wear and look at"};
    static constexpr std::string_view nm6[] = {"have been left uncovered", "are completely uncovered", "are only covered at her shoulders", "have been covered to only just below her shoulders", "have been covered only halfway down", "have been covered to just above her elbows", "have been covered to just below her elbows", "have been covered to about her elbows", "have been covered fully", "have been covered to just above her wrists", "have been covered all the way down to her wrists", "have been covered completely"};
    static constexpr std::string_view nm7[] = {"A good choice too, as her skin and the color of the dress form a perfect combination", "Which is a good thing too, her silky skin isn't something you want to cover up", "A choice which adds to the elegance and grace of the dress", "Which not only helps accentuate her gorgeous skin, it also keeps the focus on other parts of the dress", "The sleeves broaden towards the bottom and playfully accentuate her skin", "The sleeves are a loose fit and, in a way, help put focus on her soft skin", "The sleeves start out loose and tighten towards the bottom where they form a perfect match with the color of her skin", "The sleeves are simply, yet elegant. A perfect combination of grace and style", "The sleeves broaden towards the bottom, allowing for bracelets to be visible", "The sleeves are a loose fit from top to bottom, giving the dress a slightly casual look", "The sleeves start out loose and tighten towards the bottom where they wrap graceful around her wrists", "The sleeves are a tight, but comfortable fit from top to bottom, allowing for enough movement while still looking stylish"};
    static constexpr std::string_view nm8[] = {"narrow", "thin", "broad", "wide"};
    static constexpr std::string_view nm9[] = {"loose fit", "comfortable fit", "slim fit", "tight fit"};
    static constexpr std::string_view nm10[] = {"It's not decorated with anything in order to create a graceful, flowing look", "It's left simple, elegant and undecorated, creating a look that flows from top to bottom", "A bow has been wrapped around her waist and positioned slightly to one side", "A bow has been wrapped around her and rests gently on her belly", "A bow has been wrapped around her and rests gentle on her lower back", "A small, elegant belt helps accentuate her waist without being too much", "A cloth ribbon has been wrapped around her and tied in the front", "A cloth ribbon has been wrapped around her and is tied on one side", "A large belt helps accentuate her waist in a stylish manner", "A small, stylish belt is all that is needed as a perfect adornment", "An elastic band within the dress perfectly accentuates her waist and breaks up the dress nicely"};
    static constexpr std::string_view nm11[] = {"widens and has multiple symmetric layers from top to bottom", "widens and has several asymmetric layers from top to bottom", "widens and has multiple symmetric layers towards the bottom", "widens and has multiple diagonal layers from top to bottom", "widens and has several asymmetric layers towards the bottom", "widens into a ball gown-like style dress", "widens and forms a round, balloon-style dress", "widens and has a princess dress style", "widens and has a sundress style", "widens and has a trapeze style", "widens slightly and has a pleat style", "widens and has a box pleated style", "widens every so slightly and has an accordion style", "widens and has a ruffle style from top to bottom", "widens and has a ruffle style towards the bottom", "widens and has a gypsy dress style", "widens and has a symmetric draped style", "widens and has an asymmetric draped style", "widens and has a tiered style", "widens and has a bell style", "widens and has a gathered style", "fits snug around her and has a draped style", "fits snug around her and has a flounded style at the bottom", "fits snug around her and has a suit skirt style", "fits snug around her and has a pleated style", "fits snug around her and has a mermaid style", "fits snug around her and has a pencil style", "fits snug around her and has a tulip style", "fits snug around her and has a tube style", "fits snug around her and has a sarong style", "fits snug around her and has a sundress style", "fits snug around her and has a straight style", "fits snug around her and has a fish tail style", "fits snug around her and has a wrap style", "fits snug around her and has an accordion style"};
    static constexpr std::string_view nm12[] = {"to just below her knees", "to just above her knees", "all the way down to her feet", "all the way down, almost covering her feet", "to just above her ankles", "to well above her ankles", "all the way down to the ground"};
    static constexpr std::string_view nm13[] = {"the same length all around", "the same length all around", "the same length all around", "the same length all around", "the same length all around", "the same length all around", "slightly longer in the back", "slightly longer at the sides", "slightly longer at the sides and back of the dress", "longer in the back", "longer at the sides", "longer at the sides and back of the dress"};
    static constexpr std::string_view nm14[] = {"kitten heels", "stilettos", "slingbacks", "pumps", "ballerina flats", "open toes", "t-straps", "ankle straps", "cone heels", "Mary Janes", "scarpins", "peep toes", "platforms", "wedges"};
    static constexpr std::string_view nm15[] = {"which matches the dress perfectly", "an ideal match for this dress", "which further adds elegance and class", "which goes hand in hand with this dress", "which adds simplicity and elegance", "a perfect choice in combination with this dress", "they're simple, but radiate grace and refinement", "a strange, yet seemingly perfect choice", "no other shoe would've matched this dress better", "gorgeous on their own, an ideal match in combination with the dress "};
    static constexpr std::string_view nm16[] = {"a simple, but stylish necklace", "an intricately designed necklace", "a gorgeous necklace", "a subtle necklace", "an ornate necklace", "a lavish necklace", "a simple, but stylish hat", "a small, elegant hat", "a gorgeous wide hat", "a bow in her hair"};
    static constexpr std::string_view nm17[] = {"one simple, but elegant bracelet", "an ornate bracelet", "an embroidered bracelet", "an opulent bracelet", "several lavish bracelets", "several elegant bracelets", "several jeweled bracelets", "several gilded bracelets", "small jeweled earrings", "large jeweled earrings", "small, stylish earrings", "large, stylish earrings"};
    static constexpr std::string_view ns1[] = {"simple shirt", "clean shirt", "smooth shirt", "plain shirt", "standard shirt"};
    static constexpr std::string_view ns2[] = {"left it unbuttoned at the top for a more casual look", "buttoned it up fully to support the elegant tie he's wearing", "buttoned it up fully to support the graceful bow tie he's wearing"};
    static constexpr std::string_view ns3[] = {"stylish", "classy", "trendy", "chic", "sleek"};
    static constexpr std::string_view ns4[] = {"3", "4", "5", "6", "7"};
    static constexpr std::string_view ns5[] = {"deep v-line, which causes the vest to remain hidden when the suit's jacket is buttoned up", "narrow v-line, which allows for the top to remain visible even when the suit's jacket is buttoned up", "very narrow v-line, which allows for a large portion of the top to remain visible, even if the suit's jacket is buttoned up", "fairly deep v-line, which causes the vest to line up perfectly with the jacket's v-line when it's button up", "fairly deep v-line, it's just narrow enough for the top to remain visible, adding another layer to the overal look of the suit"};
    static constexpr std::string_view ns6[] = {"is a perfectly tailored fit for him", "fits him like a glove, a tailored glove", "perfectly wraps around his body", "was clearly made for him, it's a perfect fit"};
    static constexpr std::string_view ns7[] = {"It's a solid color without a pattern which radiates finesse", "It has a subtle pinstripe pattern which gives the suit an elegant look", "It has a smooth chalk stripe pattern which gives the suit a refined look", "It has an intricate rope strike pattern which makes it look stylish and graceful", "It has an elegant windowpane pattern which radiates confidence", "It has an intricate, but subtle plaid pattern, giving the suit a stylish casual look", "It has an elaborate houndstooth pattern which gives the suit a sporty, yet stylish look", "It has a tight herringbone pattern which gives the suit a more formal and elegant look", "It has a wide herringbone pattern which gives the suit a classy and graceful look", "It has an elaborate checked plaid pattern which gives the suit a fancy affluent look", "It has a simple, but elegant blanket plaid pattern, giving the suit a dignified and elegant look"};
    static constexpr std::string_view ns9[] = {"3", "4", "5", "6"};
    static constexpr std::string_view ns10[] = {"single breasted", "double breasted"};
    static constexpr std::string_view ns11[] = {"are all buttoned up, it's the only right way to wear it", "are all buttoned up, he wants to look stylish after all", "are all buttoned up, giving him a sophisticated look", "are all buttoned up, a stylish and elegant choice", "are all buttoned up, it's the best way to wear a jacket like this after all", "are all buttoned up with the exception of one, a playful touch to a classy look", "are all buttoned up with the exception of one, it adds a casual touch to an elegant look", "are all buttoned up with the exception of one, a subtle touch of nonchalance which works perfectly", "are all buttoned up with the exception of one, it gives the suit a bit of both worlds, casual and stylish", "are all buttoned up with the exception of one, a subtle but very effective touch of informality", "have been left unbuttoned, it's a casual look which still manages to look classy", "have been left unbuttoned, he's clearly going for a more casual look, but at the same time he looks elegant as well", "have been left unbuttoned, he wants to appear well dressed while still looking casual and it works", "have been left unbuttoned, this suit is meant to be worn this way. Casual, yet graceful at the same time", "have been left unbuttoned, buttoned up would've made the overall look too fancy for his taste"};
    static constexpr std::string_view ns12[] = {"the same length all around", "the same length all around", "slightly longer at the back", "longer at the back", "the same length all around"};
    static constexpr std::string_view ns13[] = {"no vent", "a vent at the back", "vents at either side"};
    static constexpr std::string_view ns14[] = {"there's a pocket on either side", "there's a single pocket on one side", "there are two pockets on one side and one pocket on the other", "there are two pockets on either side", "there's a pocket on either side"};
    static constexpr std::string_view ns15[] = {"which contains a stylish pocket square", "which has been left empty", "which contains a stylish pocket square", "which has been left empty", "which contains a pocket watch", "which holds his sunglasses"};
    static constexpr std::string_view ns16[] = {"copy the style of the jacket, both in color and pattern", "copy the style of the jacket, both in color and pattern", "copy the style of the jacket, both in color and pattern", "have the same pattern as the jacket, but a different, complementary color", "have the same color as the jacket, but a slightly different pattern", "have a different style than the jacket, but they complement each other perfectly"};
    static constexpr std::string_view ns17[] = {"they're a perfect match for his", "they perfectly complement his", "they make an ideal combination with his", "they create a perfect balance with his"};
    static constexpr std::string_view ns18[] = {"a stylish", "a lavish", "an elegant", "a classy", "a modest", "a sharp", "a fancy", "a chich", "a handsome", "a graceful"};
    static constexpr std::string_view ns19[] = {"brogue derbies", "brogue monkstraps", "brogue oxfords", "cap toe balmorals", "cap toe monkstraps", "cap toe oxfords", "fullstrap loafers", "horsebit loafers", "longwing bluchers", "medallian cap toe oxfords", "moc toe penny loafers", "penny loafers", "perf toe balmorals", "plain toe bluchers", "plain toe derbies", "plain toe monkstraps", "plain toe oxfords", "shortwing bluchers", "spectator oxfords", "split toe bluchers", "split toe derbies", "wholecut oxfords"};
    static constexpr std::string_view ns20[] = {"an elegant", "a stylish", "a sleek", "a trendy", "a fancy", "a luxurious", "a graceful", "a refined", "a modest", "a classic"};
    static constexpr std::string_view ns21[] = {"gloves", "cuff links", "a hat", "a watch", "a tie clip", "a scarf", "a brooch"};

    std::string name; std::string name2; std::string name3; std::string name4; std::string name5; std::string result; size_t rnd1 = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd17 = 0; size_t rnd18 = 0; size_t rnd19 = 0; size_t rnd2 = 0; size_t rnd20 = 0; size_t rnd21a = 0; size_t rnd21b = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

    if (type == 1) {
    rnd1 = rng() % std::size(ns1);
    rnd2 = rng() % std::size(ns2);
    rnd3 = rng() % std::size(ns3);
    rnd4 = rng() % std::size(ns4);
    rnd5 = rng() % std::size(ns5);
    rnd6 = rng() % std::size(ns6);
    rnd7 = rng() % std::size(ns7);
    rnd9 = rng() % std::size(ns9);
    rnd10 = rng() % std::size(ns10);
    rnd11 = rng() % std::size(ns11);
    if (rnd10 == 1) {
    while (rnd11 > 9) {
    rnd11 = rng() % std::size(ns11);
    }
    }
    rnd12 = rng() % std::size(ns12);
    rnd13 = rng() % std::size(ns13);
    rnd14 = rng() % std::size(ns14);
    rnd15 = rng() % std::size(ns15);
    rnd16 = rng() % std::size(ns16);
    rnd17 = rng() % std::size(ns17);
    rnd18 = rng() % std::size(ns18);
    rnd19 = rng() % std::size(ns19);
    rnd20 = rng() % std::size(ns20);
    rnd21a = rng() % std::size(ns21);
    rnd21b = rng() % std::size(ns21);
    while (rnd21a == rnd21b) {
    rnd21b = rng() % std::size(ns21);
    }
    name = "He's wearing a " + ns1[rnd1] + " and " + ns2[rnd2] + ". On top of the shirt he's wearing a " + ns3[rnd3] + " vest with " + ns4[rnd4] + " buttons, it has a " + ns5[rnd5] + ".";
    name2 = "The jacket " + ns6[rnd6] + ". " + ns7[rnd7] + ". The " + ns9[rnd9] + " buttons of his " + ns10[rnd10] + " jacket " + ns11[rnd11] + ".";
    name3 = "The jacket is " + ns12[rnd12] + ", it has " + ns13[rnd13] + ", " + ns14[rnd14] + " and there's a breast pocket " + ns15[rnd15] + ".";
    name4 = "He's wearing pants which " + ns16[rnd16] + " and " + ns17[rnd17] + " shoes. He's wearing " + ns18[rnd18] + " pair of " + ns19[rnd19] + ".";
    name5 = "To top it all off he's wearing " + ns20[rnd20] + " belt, which can be accompanied by " + ns21[rnd21a] + " and " + ns21[rnd21b] + ".";
    result = "";
    result += name;
    result += "\n";
    result += "\n";
    result += name2;
    result += "\n";
    result += name3;
    result += "\n";
    result += "\n";
    result += name4;
    result += "\n";
    result += name5;
    return result;
    } else {
    rnd1 = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    if (rnd4 > 2) {
    while (rnd5 < 10) {
    rnd5 = rng() % std::size(nm5);
    }
    }
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    if (rnd6 < 4) {
    while (rnd7 > 3) {
    rnd7 = rng() % std::size(nm7);
    }
    } else if (rnd6 < 8) {
    while (rnd7 < 4 || rnd7 > 7) {
    rnd7 = rng() % std::size(nm7);
    }
    } else if (rnd6 > 7) {
    while (rnd7 < 8) {
    rnd7 = rng() % std::size(nm7);
    }
    }
    rnd8 = rng() % std::size(nm8);
    rnd9 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    rnd12 = rng() % std::size(nm12);
    rnd13 = rng() % std::size(nm13);
    rnd14 = rng() % std::size(nm14);
    rnd15 = rng() % std::size(nm15);
    rnd16 = rng() % std::size(nm16);
    rnd17 = rng() % std::size(nm17);
    name = "The dress " + nm1[rnd1] + " and flows down into " + nm2[rnd2] + " " + nm3[rnd3] + ". It's a " + nm4[rnd4] + " fit which " + nm5[rnd5] + ".";
    name2 = "Her arms " + nm6[rnd6] + ". " + nm7[rnd7] + ".";
    name3 = "The dress' waist is " + nm8[rnd8] + ", but it's a " + nm9[rnd9] + ". " + nm10[rnd10] + ".";
    name4 = "Below the waist the dress " + nm11[rnd11] + ". The dress reaches " + nm12[rnd12] + " and is " + nm13[rnd13] + ".";
    name5 = "She's wearing " + nm14[rnd14] + ", " + nm15[rnd15] + ". To top it all off she's wearing " + nm16[rnd16] + " and " + nm17[rnd17] + ".";
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
}
