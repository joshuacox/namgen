#include "descriptions-dragons_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_dragons_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Angry", "Bright", "Calm", "Dark", "Enormous", "Fierce", "Gentle", "Large", "Narrow", "Piercing", "Restless", "Savage", "Small", "Tranquil", "Wide"};
    static constexpr std::string_view nm2[] = {"amber", "azure", "blazing", "cerulean", "cobalt", "crimson", "ebony", "emerald", "fiery", "flaming", "ivory", "jade", "obsidian", "onyx", "pearly", "ruby", "sapphire", "scarlet", "umber", "viridian"};
    static constexpr std::string_view nm3[] = {"deep", "narrowly", "buried", "far", "rooted", "well", "low", "high", "sunken", "lightly", "thightly", "graciously", "concealed", "delicately", "elegantly", "gracefully", "dreadfully", "wickedly"};
    static constexpr std::string_view nm4[] = {"angular", "bony", "hard", "thorny", "narrow", "horned", "long", "scaled", "rounded", "soft"};
    static constexpr std::string_view nm5[] = {"rather menacing", "menacing", "terrifying", "fierce", "frightening", "very ominous", "rather intimidating", "vicious", "threatening", "savage", "rather gentle", "fairly mellow", "mild", "disciplined", "rather peaceful", "sympathetic", "fairly kind", "considerate", "rather docile", "merciful"};
    static constexpr std::string_view nm6[] = {"Two enormous horns", "Two small horns", "Two horns", "Several enormous horns", "Several small horns", "Several horns", "One enormous central horn", "One small central horn", "One central horn", "Several enormous central horns", "Several small central horns", "Several central horns", "Several large tendrils", "Several small tendrils", "Several tendrils", "Two crystal growths", "Two enormous crystal growths", "Two small crystal growths", "Several crystal growths", "Several enormous crystal growths", "Several small crystal growths"};
    static constexpr std::string_view nm7[] = {"small", "large", "enormous", "tiny", "narrow", "wide", "thick", "thin", "long", "short"};
    static constexpr std::string_view nm8[] = {"pointy", "round", "cat-like", "dog-like", "angular", "curved", "warped"};
    static constexpr std::string_view nm9[] = {"A row of small horns", "A row of small tendrils", "A row of small crystal growths", "A row of crystal growths", "A row of horns", "A row of tendrils", "Several rows of small horns", "Several rows of small tendrils", "Several rows of small crystal growths", "Several rows of crystal growths", "Several rows of horns", "Several rows of tendrils", "Large fan-like skin and bone structures", "Small fan-like skin and bone structures", "Several large fan-like skin and bone structures", "Several small fan-like skin and bone structures"};
    static constexpr std::string_view nm10[] = {"pointy", "round", "wide", "thick", "thing", "long", "short", "stubby", "flat", "large", "small"};
    static constexpr std::string_view nm11[] = {"rounded", "curved", "slitted", "pointy", "angular", "warped", "oval"};
    static constexpr std::string_view nm12[] = {"there's a small horn", "there's a small crystal growth", "there's a small tendril", "there are small horns", "there are small crystal growths", "there are small tendrils", "there's a horn", "there's a crystal growth", "there's a tendril", "there are horns", "there are crystal growths", "there are tendrils"};
    static constexpr std::string_view nm13[] = {"A few sharp teeth", "Rows of sharp teeth", "Two huge teeth", "Several huge teeth", "Several sharp teeth", "Several rows of sharp teeth", "Rows of large teeth", "A few large teeth", "Several rows of large teeth", "Four large teeth"};
    static constexpr std::string_view nm14[] = {"reveal only a fraction of", "give a slight hint at", "show a glimpse of", "give a preview of"};
    static constexpr std::string_view nm15[] = {"short", "thick", "muscular", "long", "wide", "huge", "thin", "broad", "strong", "lean"};
    static constexpr std::string_view nm16[] = {"massive", "huge", "slim", "slender", "long", "short", "bulky", "colossal", "narrow", "snake-like", "muscular"};
    static constexpr std::string_view nm17[] = {"massive scales", "small scales", "thick scales", "narrow scales", "wide scales", "rounded scales", "curved scales", "warped scales", "smooth skin", "coarse skin", "thick skin", "radiant skin", "crystal-like skin", "reptilian skin", "stone-like scales", "scale-like skin"};
    static constexpr std::string_view nm18[] = {"a row of spikes", "rows of spikes", "a row of thick armor plating", "rows of thick armor plating", "a row of small spikes", "rows of small spikes", "a row of armor plating", "rows of armor plating", "a row of crystal growths", "rows of crystal growths", "a row of fan-like growths", "rows of fan-like growths", "a row of small crystal growths", "rows of small crystal growths", "a row of small fan-like growths", "rows of small fan-like growths", "a row of tendrils", "a row of small tendrils", "rows of tendrils", "rows of small tendrils", "a crystal ridge", "an armored ridge", "a fan-like growth"};
    static constexpr std::string_view nm19[] = {"much lighter", "slightly lighter", "lighter", "darker", "slightly darker", "much darker", "differently"};
    static constexpr std::string_view nm20[] = {"Four", "Six", "Two", "Four", "Two", "Four"};
    static constexpr std::string_view nm21[] = {"huge", "muscular", "slim", "slender", "bulky", "thick", "long", "massive", "powerful", "mighty"};
    static constexpr std::string_view nm22[] = {"graceful", "proud", "tall", "sturdy", "elegantly", "poised", "noble", "illustrious", "dignified", "imposing", "intimidating", "towering", "mighty", "elevated", "arrogantly"};
    static constexpr std::string_view nm23[] = {"3", "4", "5", "6"};
    static constexpr std::string_view nm24[] = {"sharp", "thick", "strong", "long", "narrow", "massive", "huge", "pointy", "barbed", "keen", "spiny", "thorny"};
    static constexpr std::string_view nm25[] = {"claws", "talons", "nails"};
    static constexpr std::string_view nm26[] = {"bone", "obsidian", "onyx", "crystal", "stone"};
    static constexpr std::string_view nm27[] = {"Enormous", "Massive", "Gigantic", "Huge", "Colossal", "Monstrous", "Giant", "Humongous", "Magnificent", "Freakish", "Terrifying", "Horrendous", "Graceful", "Delicate", "Slender"};
    static constexpr std::string_view nm28[] = {"its shoulders", "just below its shoulders", "just above its shoulders", "its shoulders"};
    static constexpr std::string_view nm29[] = {"all the way down at its pelvis", "at the middle of its back", "at the lower end of its back", "at the end of its shoulder blades", "at its hips", "just passed its shoulder blades"};
    static constexpr std::string_view nm30[] = {"angular", "rounded", "curved", "bat-like", "somewhat triangular", "scythe-shaped", "bladed in structure", "almost butterfly-like", "almost angel-like", "almost demonic"};
    static constexpr std::string_view nm31[] = {"bone structures are clearly visible through the thin layer of skin", "a specialized layer of skin is all that's visible inside", "the inside is almost entirely see-through, especially when viewed from a distance", "thick skin and eerie bone structures make up most of the wing", "a specialized layer of seeminly color-changing skin makes up most of the wing", "the edges of the skin inside the wings are tattered and damaged", "the inner sides of the wing are full of minor holes", "the insides of the wing seem to be made of thin crystals", "the skin of the wings seems to glow as if made from fire itself"};
    static constexpr std::string_view nm32[] = {"curved talons grow from each ending like giant scythes", "sharp hooks grow from the endings of each bone", "long tendril-like growths grow from many parts of the bottom sides of each wing", "armor-like scales grow on top of the wing's primary bones", "small, sharp tips grow from each ending like massive spears", "each bone structures ends in a curved, yet blunt tip", "sharp, spiky scales cover the top of each visible bone", "jagged edges at the bottom almost give it a feathered look"};
    static constexpr std::string_view nm33[] = {"long", "massive", "elegant", "fairly short", "graceful", "barbed", "spiky", "simple", "thick", "narrow", "wide", "flat"};
    static constexpr std::string_view nm34[] = {"sharp tip", "curved talon", "single tendril", "seemingly fluffy tip", "mace-like growth", "sword-like edge", "sharp, arrowhead shaped tip", "gentle point", "scythe-like blade", "hammer-like growth", "curled tip", "fan-like tip"};

    std::string name; std::string name2; std::string name3; std::string name4; std::string name5; std::string name6; std::string name7; std::string name8; std::string result; size_t rnd1 = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd17 = 0; size_t rnd17a = 0; size_t rnd18 = 0; size_t rnd19 = 0; size_t rnd2 = 0; size_t rnd20 = 0; size_t rnd21 = 0; size_t rnd22 = 0; size_t rnd22a = 0; size_t rnd23 = 0; size_t rnd24 = 0; size_t rnd25 = 0; size_t rnd26 = 0; size_t rnd27 = 0; size_t rnd28 = 0; size_t rnd29 = 0; size_t rnd3 = 0; size_t rnd30 = 0; size_t rnd31 = 0; size_t rnd32 = 0; size_t rnd33 = 0; size_t rnd34 = 0; size_t rnd4a = 0; size_t rnd4b = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd7b = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

    rnd1 = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4a = rng() % std::size(nm4);
    rnd4b = rng() % std::size(nm4);
    if (rnd4a < 8) {
    while (rnd4b > 7) {
    rnd4b = rng() % std::size(nm4);
    while (rnd4a == rnd4b) {
    rnd4b = rng() % std::size(nm4);
    }
    }
    }
    rnd5 = rng() % std::size(nm5);
    if (rnd4a < 5 || rnd4b < 5) {
    while (rnd5 > 9) {
    rnd5 = rng() % std::size(nm5);
    }
    }
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd7b = rng() % std::size(nm7);
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
    rnd17a = rng() % std::size(nm17);
    while (rnd17 == rnd17a) {
    rnd17a = rng() % std::size(nm17);
    }
    rnd18 = rng() % std::size(nm18);
    rnd19 = rng() % std::size(nm19);
    rnd20 = rng() % std::size(nm20);
    rnd21 = rng() % std::size(nm21);
    rnd22 = rng() % std::size(nm22);
    rnd22a = rng() % std::size(nm22);
    rnd23 = rng() % std::size(nm23);
    rnd24 = rng() % std::size(nm24);
    rnd25 = rng() % std::size(nm25);
    rnd26 = rng() % std::size(nm26);
    rnd27 = rng() % std::size(nm27);
    rnd28 = rng() % std::size(nm28);
    rnd29 = rng() % std::size(nm29);
    rnd30 = rng() % std::size(nm30);
    rnd31 = rng() % std::size(nm31);
    rnd32 = rng() % std::size(nm32);
    rnd33 = rng() % std::size(nm33);
    rnd34 = rng() % std::size(nm34);
    name = nm1[rnd1] + " " + nm2[rnd2] + " eyes sit " + nm3[rnd3] + " within the creature's " + nm4[rnd4a] + ", " + nm4[rnd4b] + " skull, which gives the creature a " + nm5[rnd5] + " looking appearance.";
    name2 = nm6[rnd6] + " sit atop its head, just above its " + nm7[rnd7] + ", " + nm8[rnd8] + " ears. " + nm9[rnd9] + " runs down the sides of each of its jaw lines.";
    name3 = "Its nose is " + nm10[rnd10] + " and has two " + nm7[rnd7b] + ", " + nm11[rnd11] + " nostrils and " + nm12[rnd12] + " on its chin. " + nm13[rnd13] + " poke out from the side of its mouth and " + nm14[rnd14] + " the terror hiding inside.";
    name4 = "A " + nm15[rnd15] + " neck runs down from its head and into a " + nm16[rnd16] + " body. The top is covered in " + nm17[rnd17] + " and " + nm18[rnd18] + " runs down its spine.";
    name5 = "Its bottom is covered in " + nm17[rnd17a] + " and is colored " + nm19[rnd19] + " than the rest of its body. ";
    name6 = nm20[rnd20] + " " + nm21[rnd21] + " limbs carry its body and allow the creature to stand " + nm22[rnd22] + " and " + nm22[rnd22a] + ". Each limb has " + nm23[rnd23] + " digits, each of which end in " + nm24[rnd24] + " " + nm25[rnd25] + " seemingly made of " + nm26[rnd26] + ".";
    name7 = nm27[rnd27] + " wings grow starting from " + nm28[rnd28] + " and end " + nm29[rnd29] + ". The wings are " + nm30[rnd30] + ", " + nm31[rnd31] + " and " + nm32[rnd32] + ".";
    name8 = "Its " + nm33[rnd33] + " tail ends in a " + nm34[rnd34] + " and is covered in the same " + nm17[rnd17] + " as its body.";
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
    result += name6;
    result += "\n";
    result += "\n";
    result += name7;
    result += "\n";
    result += "\n";
    result += name8;
    result += "\n";
    return result;
}
