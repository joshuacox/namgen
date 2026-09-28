#include "descriptions-school_uniforms_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_school_uniforms_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"straight", "striped", "lined", "finely striped", "thickly striped", "plain", "checkered", "loose fitting", "narrow fitting"};
    static constexpr std::string_view nm2[] = {"Dacron", "cotton", "nylon", "polycotton", "polyester", "cotton", "nylon"};
    static constexpr std::string_view nm3[] = {"down to about their calves and thus reveal", "down to just above", "down to just under their knees, clearly revealing", "down to just above their ankles and reveal", "all the way down and partially cover", "down to well below their knees and clearly reveal"};
    static constexpr std::string_view nm3s[] = {"loafers", "single strap shoes", "double strap shoes", "triple strap shoes", "sporty loafers", "lace-up shoes", "slip-in shoes", "Chelsea boots"};
    static constexpr std::string_view nm4[] = {"both of which are colored", "each respectively colored"};
    static constexpr std::string_view nm5[] = {"almond", "amber", "apricot", "aquamarine", "auburn", "azure", "baby blue", "beige", "black", "bronze", "brown", "burgundy", "cardinal", "cerulean", "cobalt", "crimson", "denim", "forest green", "ginger", "indigo", "jade", "jasmine", "jasper", "khaki", "lavender", "lilac", "mahogany", "maroon", "navy", "ochre", "onyx", "orchid", "peach", "rosewood", "russet", "scarlet", "sepia", "sienna", "sinopia", "tangerine", "tawny", "teal", "vanilla", "vermilion", "viridian", "wheat"};
    static constexpr std::string_view nm6[] = {"long", "short", "regular"};
    static constexpr std::string_view nm7[] = {"and a simple belt ", "and a thick belt ", " and a regular belt ", "", ""};
    static constexpr std::string_view nm8[] = {"A white", "An almond", "A beige", "A cream", "A floral white", "A ghost white", "An ivory"};
    static constexpr std::string_view nm8b[] = {"long sleeved", "short sleeved", "fairly short sleeved", "long sleeved"};
    static constexpr std::string_view nm9[] = {"neatly tucked into", "gently tucked into", "almost perfectly tucked into", "barely tucked into", "roughly tucked into", "loosely hanging over", "neatly hanging over", "playfully hanging over", "somewhat messily hanging over", "carelessly hanging over"};
    static constexpr std::string_view nm10[] = {"basic", "charming", "classic", "clear-cut", "comfortable", "diligent", "discrete", "fairly long", "fancy", "formal", "graceful", "heavy", "humble", "lavish", "light", "lined", "long", "loose", "luxurious", "moderate", "modest", "mundane", "narrow", "navy", "neat", "plain", "regular", "short", "simple", "slim", "standard", "stylish", "thick", "thin", "tight", "wide"};
    static constexpr std::string_view nm11[] = {"long", "short", "thin", "wide", "narrow", "slim", "lean", "light", "fine", "broad"};
    static constexpr std::string_view nm12[] = {"splits right down", "hangs gently in", "playfully dangles in", "neatly rests in", "divides", "neatly splits", "drops freely down", "hangs neatly in", "playfully hangs in", "hangs down", "is tucked in", "is neatly tucked behind"};
    static constexpr std::string_view nm13[] = {"buttoned up", "half buttoned up", "unbuttoned", "mostly buttoned up", "barely buttoned up", "rarely buttoned up", "often unbottoned", "half unbottoned"};
    static constexpr std::string_view nm14[] = {"striped", "dotted", "thinly striped", "broadly striped", "thinly dotted", "diagonally striped", "horizontally striped", "vertically striped", "gingerly dotted", "moderately dotted", "patterned", "checkered", "broadly checkered", "thinly checkered", "crisscrossed", "broadly crisscrossed", "thinly crisscrossed", "plain and undecorated"};
    static constexpr std::string_view nm15[] = {"straight", "circle", "accordion", "pleated", "box pleated", "paneled", "wrap", "bubble", "layered", "tiered", "pencil"};
    static constexpr std::string_view nm16[] = {"reach down to just above their calves", "dangle down to just below their knees", "reach down to just above their ankles", "dangle all the way down to their feet", "cover the entirety of their legs", "reveal their legs from the knees down", "just reveal their calves", "reach down to well below their knees", "dangle down to about their calves", "reach to just above their ankles", "dangle down to about their ankles"};
    static constexpr std::string_view nm16s[] = {"Mary Jane shoes", "toe cap shoes", "brogue shoes", "plimsolls", "pumps", "wedge shoes"};
    static constexpr std::string_view nm17[] = {"knee high", "striped", "dotted", "crisscrossed", "regular", "over the calf", "thigh high"};
    static constexpr std::string_view nm18[] = {"while not mandatory", "although slightly frowned upon", "although forbidden by regulations", "while not really encouraged", "although discouraged by teachers", "while it's completely up to them", "although completely optional", "while up to their discretion", "although non-compulsory", "although slightly disapproved"};
    static constexpr std::string_view nm19[] = {"school-colored", "all sorts of", "varied", "matching", "uniform matching", "various", "distinct", "individual", "separate", "corresponding"};
    static constexpr std::string_view nm20[] = {"mostly as a form of self expression", "in some cases purely to be somewhat rebellious", "often as a way to show their school spirit", "often because this is the only part of their clothing they have any say over", "sometimes somewhat as an act of defiance", "in some cases simply to make a statement", "often to create a new style within the standard uniform", "usually to identify themselves as being part of a specific group", "usually to bring some form of their own identity into the standard uniform", "mostly because many think the standard uniform's too dull", "many do it to add a personal touch to the otherwise identical uniform", "some do it simply to avoid being confused for somebody else", "it's an easy way to express themselves at least a little", "for some it's a means to stand out from the crowd", "often it's done through forms of group expression"};
    static constexpr std::string_view nm21[] = {"are emblazoned with the school logo", "have a line around all edges in the school color", "have two lines around all edges in the school color", "are adorned with a small school logo", "have buttons with the school symbol on them", "have the school symbol on the breast pockets", "have colored lines around the sleeves", "have been left plain and undecorated", "have a line in the school color at the bottom", "have school colored accents on all edges"};

    std::string name; std::string name2; std::string name3; std::string name4; std::string name5; std::string name6; std::string result; size_t rnd1 = 0; size_t rnd10 = 0; size_t rnd10b = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd12b = 0; size_t rnd13 = 0; size_t rnd13b = 0; size_t rnd14 = 0; size_t rnd14b = 0; size_t rnd14c = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd16s = 0; size_t rnd17 = 0; size_t rnd18 = 0; size_t rnd19 = 0; size_t rnd2 = 0; size_t rnd20 = 0; size_t rnd21 = 0; size_t rnd3 = 0; size_t rnd3s = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd5b = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd8b = 0; size_t rnd9 = 0; size_t rnd9b = 0; int i = 0;

    rnd1 = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd3s = rng() % std::size(nm3s);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd5b = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    rnd8b = rng() % std::size(nm8b);
    rnd9 = rng() % std::size(nm9);
    rnd9b = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm10);
    rnd10b = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    rnd12 = rng() % std::size(nm12);
    rnd12b = rng() % std::size(nm12);
    rnd13 = rng() % std::size(nm13);
    rnd13b = rng() % std::size(nm13);
    rnd14 = rng() % std::size(nm14);
    rnd14b = rng() % std::size(nm14);
    rnd14c = rng() % std::size(nm14);
    rnd15 = rng() % std::size(nm15);
    rnd16 = rng() % std::size(nm16);
    rnd16s = rng() % std::size(nm16s);
    rnd17 = rng() % std::size(nm17);
    rnd18 = rng() % std::size(nm18);
    rnd19 = rng() % std::size(nm19);
    rnd20 = rng() % std::size(nm20);
    rnd21 = rng() % std::size(nm21);
    name = "The boys in this school wear " + nm1[rnd1] + ", " + nm2[rnd2] + " trousers that reach " + nm3[rnd3] + " their " + nm3s[rnd3s] + ", all of which are colored " + nm5[rnd5] + ".";
    name2 = " They're paired with " + nm6[rnd6] + ", " + nm14[rnd14] + " socks " + nm7[rnd7] + "colored " + nm5[rnd5b] + ".";
    name3 = nm8[rnd8] + " " + nm8b[rnd8b] + " shirt is " + nm9[rnd9] + " their trousers and covered with a " + nm10[rnd10] + " jacket. A " + nm11[rnd11] + " tie " + nm12[rnd12] + " the middle of their " + nm13[rnd13] + " jacket and is " + nm14[rnd14b] + " in " + nm5[rnd5] + " and " + nm5[rnd5b] + ".";
    name4 = "The girls wear " + nm15[rnd15] + " skirts in " + nm5[rnd5] + " and they " + nm16[rnd16] + ". They're paired with " + nm17[rnd17] + " socks and " + nm16s[rnd16s] + " colored in " + nm5[rnd5b] + " and " + nm5[rnd5] + " respectively.";
    name5 = "Like the boys the girls wear " + nm8b[rnd8b] + " shirts, which are usually " + nm9[rnd9b] + " their skirts and are covered with a " + nm10[rnd10b] + " jacket. They too wear a tie that " + nm12[rnd12b] + " the middle of their often " + nm13[rnd13b] + " jackets and is " + nm14[rnd14c] + " in the same colors.";
    name6 = "All jackets " + nm21[rnd21] + " and, " + nm18[rnd18] + ", many students wear " + nm19[rnd19] + " accessoires, " + nm20[rnd20] + ".";
    result = "";
    result += name;
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
    return result;
}
