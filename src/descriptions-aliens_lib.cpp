#include "descriptions-aliens_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_aliens_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"mammal", "aquatic mammal", "amphibian", "reptile", "fish", "invertebrate", "bird", "mammal"};
    static constexpr std::string_view names2a_1[] = {"two arms and ", "four arms and ", "six arms and ", "two arms and ", "two arms and ", "four arms and ", "two arms and "};
    static constexpr std::string_view names2b_1[] = {"two legs, ", "four legs, ", "six legs, ", "four legs, ", "two legs, ", "two legs, "};
    static constexpr std::string_view names2c_1[] = {"with a long, thin tail", "with a long, thick tail", "with a short, thin tail", "with a short, thick tail", "with remnants of what was once a tail", "but they have no tail", "with a long, strong and agile tail", "with a short, strong tail", "with a long, strong tail", "with a short, muscular tail", "with a long, muscular tail", "with a long, weak tail", "with a short, weak tail", "with a long, useless tail", "with a short, useless tail", "with a short, stubby tail"};
    static constexpr std::string_view names3[] = {"two eyes", "four eyes", "six eyes", "two eyes", "four eyes", "two eyes"};
    static constexpr std::string_view names4[] = {"deep", "narrowly", "buried", "far", "rooted", "well", "low", "high", "sunken", "lightly", "thightly", "graciously", "concealed", "delicately", "elegantly", "gracefully"};
    static constexpr std::string_view names5[] = {"friendly", "angry", "arrogant", "reserved", "serene", "compased", "distant", "modest", "restrained", "cautious", "gentle", "withdrawn", "annoyed", "nervous", "agitated", "bold", "excited", "troubled", "upset", "formal", "evil", "trustworthy", "untrustworthy", "sly", "honest", "dishonest", "slick", "elusive", "calculating", "intelligent"};
    static constexpr std::string_view names6[] = {"excellent", "fairly good", "quite good", "not the best", "amazing", "astonishing", "a bit poor", "great at distances", "not too great at distances", "impressive", "average", "not that great", "among the best", "almost among the best", "perhaps the best of all species"};
    static constexpr std::string_view names7a_1[] = {"wide mouths", "small mouths", "long mouths", "huge mouths", "thin mouths", "narrow mouths", "enormous mouths"};
    static constexpr std::string_view names7b_1[] = {" and huge noses", " and small noses", " and wide noses", " and long noses", " and enormous noses", " and thin noses", " and almost hidden noses", " and lack of a visible nose", " and tiny noses", " and narrow noses"};
    static constexpr std::string_view names8_1[] = {"almost invisible", "long and pointy", "small", "huge", "large", "long", "quite long", "a bit small", "wide and long", "long and narrow", "will hidden", "small and pointy", "wide and large", "long and hanging", "small and stubby"};
    static constexpr std::string_view names9_1[] = {"They also have two horns on their heads.", "They also have three horns on their heads.", "They also have four horns on their heads.", "They also have horns covering their face.", "They also have horns running across their backs.", "They also have small horns on their hands.", "They also have small horns on their hands, arms and legs.", "They also have two small horns on their elbows.", "They also have two horns on their heels.", "They also have small horns on their feet.", "They also have small horns on their hands and feet.", "They also have small horns across their chests.", "They also have small horns across their body.", "They also have small horns across their chests and backs.", "They also have one long horn on their head.", "", "", "", "", ""};
    static constexpr std::string_view names10[] = {"very thick and rough.", "smooth and thin.", "thin, but strong.", "thin and fairly weak.", "very thick and very strong.", "very strong, but not very thick.", "course, thick and strong.", "smooth, yet strong.", "smooth, elastic and quite strong.", "elastic and strong."};
    static constexpr std::string_view names11_1[] = {"It's covered in thick fur.", "It's covered lightly in small hairs.", "It's covered lightly in long, coarse hairs.", "It's covered in thick, course fur.", "It's covered long, wavy hairs.", "It's covered short hairs.", "It's covered short, curly hairs.", "It's covered in nothing but a few hairs on their hands.", "It's covered in nothing but hair on their heads, arms and legs.", "It's covered in nothing, except for hair on their heads.", "It's covered in nothing, except for hairs on their heads, chests, arms and legs.", "It's covered in nothing but a few hairs on their heads.", "It's covered lightly in tiny hairs.", "It's covered in thick, short hairs.", "It's covered in soft, short hairs."};
    static constexpr std::string_view names12a[] = {"black", "blue", "bronze", "brown", "gold", "grey", "orange", "pink", "purple", "red", "silver", "white", "yellow", "dark blue", "dark bronze", "dark brown", "dark gold", "dark grey", "dark orange", "dark pink", "dark purple", "dark red", "dark silver", "dark yellow", "light blue", "light bronze", "light brown", "light gold", "light grey", "light orange", "light pink", "light purple", "light red", "light silver", "light yellow"};
    static constexpr std::string_view names12b[] = {", black", ", blue", ", bronze", ", brown", ", gold", ", grey", ", orange", ", pink", ", purple", ", red", ", silver", ", white", ", yellow", ", dark blue", ", dark bronze", ", dark brown", ", dark gold", ", dark grey", ", dark orange", ", dark pink", ", dark purple", ", dark red", ", dark silver", ", dark yellow", ", light blue", ", light bronze", ", light brown", ", light gold", ", light grey", ", light orange", ", light pink", ", light purple", ", light red", ", light silver", ", light yellow", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view names12c[] = {", black", ", blue", ", bronze", ", brown", ", gold", ", grey", ", orange", ", pink", ", purple", ", red", ", silver", ", white", ", yellow", ", dark blue", ", dark bronze", ", dark brown", ", dark gold", ", dark grey", ", dark orange", ", dark pink", ", dark purple", ", dark red", ", dark silver", ", dark yellow", ", light blue", ", light bronze", ", light brown", ", light gold", ", light grey", ", light orange", ", light pink", ", light purple", ", light red", ", light silver", ", light yellow", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view names12d[] = {" and black", " and blue", " and bronze", " and brown", " and gold", " and grey", " and orange", " and pink", " and purple", " and red", " and silver", " and white", " and yellow", " and dark blue", " and dark bronze", " and dark brown", " and dark gold", " and dark grey", " and dark orange", " and dark pink", " and dark purple", " and dark red", " and dark silver", " and dark yellow", " and light blue", " and light bronze", " and light brown", " and light gold", " and light grey", " and light orange", " and light pink", " and light purple", " and light red", " and light silver", " and light yellow"};
    static constexpr std::string_view names13[] = {"darker", "lighter", "dull", "dim", "pale", "faded"};
    static constexpr std::string_view names14[] = {"more arrogant", "bigger", "bossier", "braver", "bulkier", "faster", "friendlier", "heavier", "lazier", "more adventurous", "more confident", "more cunning", "more dependable", "more emotional", "more gracious", "more helpful", "more honorable", "more humble", "more impulsive", "more independent", "more obedient", "more obnoxious", "more optimistic", "more self-centered", "more self-reliant", "more vulgar", "smarter", "sneakier", "stronger", "taller"};
    static constexpr std::string_view names15[] = {"more vibrant", "less vibrant", "more varied", "less varied", "darker", "lighter"};
    static constexpr std::string_view names2a_2[] = {"a huge, powerful tail and small anal fin, ", "a huge, muscular tail and small anal fin, ", "a large, muscular tail and small anal fin, ", "a large, powerful tail and small anal fin, ", "a short, muscular tail and small anal fin, ", "a long, powerful tail and small anal fin, ", "a short, powerful tail and small anal fin, ", "a long, muscular tail and small anal fin, ", "a huge, powerful tail and small anal fin, ", "a huge, muscular tail and long anal fin, ", "a large, muscular tail and long anal fin, ", "a large, powerful tail and long anal fin, ", "a short, muscular tail and long anal fin, ", "a long, powerful tail and long anal fin, ", "a short, powerful tail and long anal fin, ", "a long, muscular tail and long anal fin, "};
    static constexpr std::string_view names2b_2[] = {"two arms and ", "four arms and ", "two strong side fins and ", "four strong side fins and ", "six strong side fins and ", "two side fins and ", "four side fins and ", "six side fins and ", "two large side fins and ", "four large side fins and ", "six large side fins and ", "two powerful arms and ", "four powerful arms and ", "two powerful side fins and ", "four powerful sidefins and ", "two huge side fins and ", "four huge side fins and "};
    static constexpr std::string_view names2c_2[] = {"a huge dorsal fin", "a small dorsal fin", "a thick, long dorsal fin", "a thin, long dorsal fin", "a wide, sail-like dorsal fin", "a ribbon-like dorsal fin", "a long, ribbon-like dorsal fin", "a short, ribbon-like dorsal fin", "a huge, sail-like dorsal fin", "a short, strong dorsal fin", "a long, strong dorsal fin", "a short, pointy dorsal fin", "a long, pointy dorsal fin", "a long, streamlined dorsal fin", "a short, streamlined dorsal fin"};
    static constexpr std::string_view names9_2[] = {"They also have two horns on their heads.", "They also have three horns on their heads.", "They also have four horns on their heads.", "They also have horns running across their backs.", "They also have one long horn on their head.", "", "", "", "", ""};
    static constexpr std::string_view names11_2[] = {""};
    static constexpr std::string_view names2c_3[] = {"but they have no tail", "with a huge, powerful tail", "with a long, muscular tail", "with a long, powerful tail", "with a long, strong and agile tail", "with a long, strong tail", "with a long, thick tail", "with a long, thin tail", "with a long, useless tail", "with a long, weak tail", "with a short, muscular tail", "with a short, powerful tail", "with a short, strong tail", "with a short, stubby tail", "with a short, thick tail", "with a short, thin tail", "with a short, useless tail", "with a short, weak tail", "with a thick, powerful tail", "with remnants of what was once a tail"};
    static constexpr std::string_view names11_3[] = {"It's covered in a thin layer of mucous.", "It's covered in a thick layer of mucous.", "It's covered in a very thin layer of mucous.", "It's covered in a very thick layer of mucous.", "It's covered lightly in mucous."};
    static constexpr std::string_view names2a_3[] = {"two arms and two legs, ", "two arms and four legs, ", "two arms and six legs, ", "four arms and two legs, ", "four arms and four legs, ", "four arms and six legs, ", "six arms and two legs, ", "six arms and four legs, ", "two arms, but no legs, like a snake with arms, ", "four arms, but no legs, like a snake with arms, ", "six arms, but no legs, like a snake with arms, "};
    static constexpr std::string_view names2b_3[] = {""};
    static constexpr std::string_view names2c_4[] = {"with a long, thin tail", "with a long, thick tail", "with a short, thin tail", "with a short, thick tail", "with remnants of what was once a tail", "but they have no tail", "with a long, strong and agile tail", "with a short, strong tail", "with a long, strong tail", "with a short, muscular tail", "with a long, muscular tail", "with a long, weak tail", "with a short, weak tail", "with a long, useless tail", "with a short, useless tail", "with a short, stubby tail"};
    static constexpr std::string_view names11_4[] = {"It's covered in thin, coarse scales.", "It's covered in large, coarse scales.", "It's covered in large, smooth scales.", "It's covered in large, strong scales.", "It's covered in small, coarse scales.", "It's covered in small, smooth scales.", "It's covered in small, strong scales.", "It's covered in strong, hard scales.", "It's covered in thick, coarse scales.", "It's covered in thick, strong scales."};
    static constexpr std::string_view names2a_4[] = {"a huge, powerful tail and small anal fin, ", "a huge, muscular tail and small anal fin, ", "a large, muscular tail and small anal fin, ", "a large, powerful tail and small anal fin, ", "a short, muscular tail and small anal fin, ", "a long, powerful tail and small anal fin, ", "a short, powerful tail and small anal fin, ", "a long, muscular tail and small anal fin, ", "a huge, powerful tail and small anal fin, ", "a huge, muscular tail and long anal fin, ", "a large, muscular tail and long anal fin, ", "a large, powerful tail and long anal fin, ", "a short, muscular tail and long anal fin, ", "a long, powerful tail and long anal fin, ", "a short, powerful tail and long anal fin, ", "a long, muscular tail and long anal fin, "};
    static constexpr std::string_view names2b_4[] = {"two strong side fins and ", "four strong side fins and ", "six strong side fins and ", "two side fins and ", "four side fins and ", "six side fins and ", "two large side fins and ", "four large side fins and ", "six large side fins and ", "two powerful side fins and ", "four powerful sidefins and ", "two huge side fins and ", "four huge side fins and "};
    static constexpr std::string_view names2c_5[] = {"a huge dorsal fin", "a small dorsal fin", "a thick, long dorsal fin", "a thin, long dorsal fin", "a wide, sail-like dorsal fin", "a ribbon-like dorsal fin", "a long, ribbon-like dorsal fin", "a short, ribbon-like dorsal fin", "a huge, sail-like dorsal fin", "a short, strong dorsal fin", "a long, strong dorsal fin", "a short, pointy dorsal fin", "a long, pointy dorsal fin", "a long, streamlined dorsal fin", "a short, streamlined dorsal fin"};
    static constexpr std::string_view names7b_2[] = {" and small noses", " and wide noses", " and long noses", " and thin noses", " and almost hidden noses", " and lack of a visible nose", " and tiny noses", " and narrow noses"};
    static constexpr std::string_view names8_2[] = {"almost invisible", "small", "will hidden", "small and pointy", "small and stubby"};
    static constexpr std::string_view names11_5[] = {"It's covered in thin, coarse scales.", "It's covered in large, coarse scales.", "It's covered in large, smooth scales.", "It's covered in large, strong scales.", "It's covered in small, coarse scales.", "It's covered in small, smooth scales.", "It's covered in small, strong scales.", "It's covered in strong, hard scales.", "It's covered in thick, coarse scales.", "It's covered in thick, strong scales."};
    static constexpr std::string_view names2a_5[] = {"two arms and ", "four arms and ", "six arms and ", "four winged arms and ", "two winged arms and ", "six winged arms and ", "two clawed arms and ", "four clawed arms and ", "two wings, two arms and ", "four wings, two arms and ", "two wings, four arms and ", "four wings, four arms and ", "two wings, six arms and ", "two wings, two clawed arms and ", "two clawed arms, two normal arms and "};
    static constexpr std::string_view names2b_5[] = {"two legs, ", "four legs, ", "six legs, ", "four legs, ", "two legs, "};
    static constexpr std::string_view names2c_6[] = {"but they have no tail", "with a huge, powerful tail", "with a long, muscular tail", "with a long, powerful tail", "with a long, strong and agile tail", "with a long, strong tail", "with a long, thick tail", "with a long, thin tail", "with a long, useless tail", "with a long, weak tail", "with a short, muscular tail", "with a short, powerful tail", "with a short, strong tail", "with a short, stubby tail", "with a short, thick tail", "with a short, thin tail", "with a short, useless tail", "with a short, weak tail", "with a thick, powerful tail", "with remnants of what was once a tail"};
    static constexpr std::string_view names2a_6[] = {"two huge wings and ", "four huge wings and ", "two huge, powerful wings and ", "four huge, powerful wings and ", "two huge and two smaller wings and ", "two enormous wings and ", "four enormous wings and ", "two large and four smaller wings and ", "four smaller wings and ", "two smaller wings and "};
    static constexpr std::string_view names2b_6[] = {"two strong, clawed legs, ", "two small, clawed legs, ", "four strong, clawed legs, ", "four small, clawed legs, ", "two strong legs, ", "four strong legs, ", "two small legs, ", "four small legs, ", "two thin, long legs, ", "two long, strong legs, "};
    static constexpr std::string_view names2c_7[] = {"with a huge tail", "with a huge, wide tail", "with a huge, powerful tail", "with a long, powerful tail", "with a long, elegant tail", "with a short, elegant tail", "with a short, powerful tail", "with a wide, powerful tail", "with a wide, elegant tail", "with a short tail"};
    static constexpr std::string_view names7a_2[] = {"long beaks", "sharp beaks", "thin beaks", "short beaks", "huge beaks", "enormous beaks", "wide beaks", "thin, sharp beaks", "long, sharp beaks", "long, pointy beaks", "short, pointy beaks", "huge, pointy beaks", "huge, sharp beaks", "short, sharp beaks", "thin, pointy beaks"};
    static constexpr std::string_view names7b_3[] = {""};
    static constexpr std::string_view names8_3[] = {"almost invisible", "small", "will hidden", "small and pointy", "small and stubby", "hidden behind their feathers"};
    static constexpr std::string_view names9_3[] = {""};
    static constexpr std::string_view names11_6[] = {"It's covered in large feathers.", "It's covered in large, thin feathers.", "It's covered in large, wide feathers.", "It's covered in long, thin feathers.", "It's covered in long, wide feathers.", "It's covered in short, thin feathers.", "It's covered in short, wide feathers.", "It's covered in small feathers.", "It's covered in small, thin feathers.", "It's covered in small, wide feathers."};

    ArrayView names11; ArrayView names2a; ArrayView names2b; ArrayView names2c; ArrayView names7a; ArrayView names7b; ArrayView names8; ArrayView names9; std::string name; std::string name2; std::string name3; std::string name4; std::string name5; std::string name6; std::string name7; std::string names11a; std::string result; size_t random1 = 0; size_t random10 = 0; size_t random11 = 0; size_t random12a = 0; size_t random12b = 0; size_t random12c = 0; size_t random12d = 0; size_t random12e = 0; size_t random13 = 0; size_t random14a = 0; size_t random14b = 0; size_t random15 = 0; size_t random2a = 0; size_t random2b = 0; size_t random2c = 0; size_t random3 = 0; size_t random4 = 0; size_t random5a = 0; size_t random5b = 0; size_t random6a = 0; size_t random6b = 0; size_t random7a = 0; size_t random7b = 0; size_t random8 = 0; size_t random9 = 0; int i = 0;

    names2a = make_view(names2a_1);
    names2b = make_view(names2b_1);
    names2c = make_view(names2c_1);
    names7a = make_view(names7a_1);
    names7b = make_view(names7b_1);
    names8 = make_view(names8_1);
    names9 = make_view(names9_1);
    names11 = make_view(names11_1);
    names11a = "Their skin ";
    random1 = rng() % std::size(names1);
    if (random1 == 1) {
    names2a = make_view(names2a_2);
    names2b = make_view(names2b_2);
    names2c = make_view(names2c_2);
    names9 = make_view(names9_2);
    names11 = make_view(names11_2);
    } else if (random1 == 2) {
    names2c = make_view(names2c_3);
    names11 = make_view(names11_3);
    } else if (random1 == 3) {
    names2a = make_view(names2a_3);
    names2b = make_view(names2b_3);
    names2c = make_view(names2c_4);
    names11 = make_view(names11_4);
    names11a = "Their scale ";
    } else if (random1 == 4) {
    names2a = make_view(names2a_4);
    names2b = make_view(names2b_4);
    names2c = make_view(names2c_5);
    names7b = make_view(names7b_2);
    names8 = make_view(names8_2);
    names11 = make_view(names11_5);
    names11a = "Their scale ";
    } else if (random1 == 5) {
    names2a = make_view(names2a_5);
    names2b = make_view(names2b_5);
    names2c = make_view(names2c_6);
    } else if (random1 == 6) {
    names2a = make_view(names2a_6);
    names2b = make_view(names2b_6);
    names2c = make_view(names2c_7);
    names7a = make_view(names7a_2);
    names7b = make_view(names7b_3);
    names8 = make_view(names8_3);
    names9 = make_view(names9_3);
    names11 = make_view(names11_6);
    names11a = "Their feather ";
    }
    random2a = rng() % std::size(names2a);
    random2b = rng() % std::size(names2b);
    random2c = rng() % std::size(names2c);
    random3 = rng() % std::size(names3);
    random4 = rng() % std::size(names4);
    random5a = rng() % std::size(names5);
    random5b = rng() % std::size(names5);
    while (random5b == random5a) {
    random5b = rng() % std::size(names5);
    }
    random6a = rng() % std::size(names6);
    random6b = rng() % std::size(names6);
    while (random6b == random6a) {
    random6b = rng() % std::size(names6);
    }
    random7a = rng() % std::size(names7a);
    random7b = rng() % std::size(names7b);
    random8 = rng() % std::size(names8);
    random9 = rng() % std::size(names9);
    random10 = rng() % std::size(names10);
    random11 = rng() % std::size(names11);
    random12a = rng() % std::size(names12a);
    random12b = rng() % std::size(names12b);
    while (random12b == random12a) {
    random2b = rng() % std::size(names12b);
    }
    random12c = rng() % std::size(names12c);
    while (random12c == random12a || random12c == random12b) {
    random12c = rng() % std::size(names12c);
    }
    random12d = rng() % std::size(names12c);
    while (random12d == random12a || random12d == random12b || random12d == random12c) {
    random12d = rng() % std::size(names12c);
    }
    random12e = rng() % std::size(names12d);
    while (random12e == random12a || random12e == random12b || random12e == random12c || random12e == random12d) {
    random12e = rng() % std::size(names12d);
    }
    random13 = rng() % std::size(names13);
    random14a = rng() % std::size(names14);
    random14b = rng() % std::size(names14);
    while (random14b == random14a) {
    random14b = rng() % std::size(names14);
    }
    random15 = rng() % std::size(names15);
    name = "These aliens are a type of " + names1[random1] + ". They have " + names2a[random2a] + names2b[random2b] + names2c[random2c] + ".";
    name2 = "They have " + names3[random3] + " which sit " + names4[random4] + " in their sockets and can often make them appear to be " + names5[random5a] + ". Their eyesight is " + names6[random6a] + ".";
    name3 = "Their " + names7a[random7a] + names7b[random7b] + " often make these aliens appear to be " + names5[random5b] + ", but looks can be deceiving.";
    name4 = "Their ears are " + names8[random8] + " and their hearing is " + names6[random6b] + ". " + names9[random9];
    name5 = "Their skin is " + names10[random10] + " " + names11[random11];
    name6 = names11a + " colors are mostly " + names12a[random12a] + names12b[random12b] + names12c[random12c] + names12c[random12d] + names12d[random12e] + ", which tend to become " + names13[random13] + " as they age.";
    name7 = "The males are usually " + names14[random14a] + " than their female counter part and their colors are " + names15[random15] + ". The females, however, are usually " + names14[random14b] + ".";
    result = "";
    result += name;
    result += "\n";
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
