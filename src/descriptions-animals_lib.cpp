#include "descriptions-animals_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_animals_name(std::mt19937& rng) {
    static constexpr std::string_view names0[] = {" and rare", " and incredibily rare", " and nearly extinct", ", but common", ", but very common", " and uncommon", " and seldom seen", ", but extremely common", ", but fairly common", ", but often seen"};
    static constexpr std::string_view names1[] = {"adorable", "amazing", "amusing", "astonishing", "beautiful", "bizarre", "captivating", "charming", "clever", "curious", "delightful", "fierce", "funny", "incredible", "lovely", "odd", "special", "strange", "unusual", "weird"};
    static constexpr std::string_view names2[] = {"mammal", "aquatic mammal", "amphibian", "reptile", "fish", "invertebrate", "bird"};
    static constexpr std::string_view names3_1[] = {" bear", " cat", " cow", " deer", " dog", "n elephant", " fox", " goat", " hippo", " horse", " human", " leopard", " lion", " mouse", " pig", " rabbit", " rat", " rhino", " tiger", " wolf"};
    static constexpr std::string_view names4a_1[] = {"two legs and two arms", "two legs and four arms", "four legs", "six legs", "two legs and two arms", "four legs", "six legs", "four legs and two arms", "four legs and two arms"};
    static constexpr std::string_view names4b_1[] = {""};
    static constexpr std::string_view names4c_1[] = {", but they have no tail", ", but they have no tail", ", but they have no tail", ", but they have no tail", ", but they have no tail", ", but they have no tail", " and a long, curling tail", " and a long, fluffy tail", " and a long, muscular tail", " and a long, ribbon-like tail", " and a long, strong and agile tail", " and a long, strong tail", " and a long, thick tail", " and a long, thin tail", " and a long, weak tail", " and a short, curly tail", " and a short, fluffy tail", " and a short, muscular tail", " and a short, strong tail", " and a short, stubby tail", " and a short, thick tail", " and a short, thin tail", " and a short, weak tail", " and a thick, flat tail", " and remnants of what was once a tail"};
    static constexpr std::string_view names5_1[] = {"soft, but strong skin", "thick, strong skin", "soft, delicate skin", "thick, rough skin", "thin, rough skin", "thin, delicate skin", "thick, smooth skin", "soft, smooth skin", "thin, but strong skin", "thick, but delicate skin"};
    static constexpr std::string_view names6_1[] = {"covered in thick, soft fur", "covered in thick, coarse fur", "covered in thin, soft fur", "covered in thin, coarse fur", "covered in thick, fluffy fur", "covered in thin, fluffy fur", "covered in short, soft fur", "covered in long, soft fur", "covered in long, fluffy fur", "covered in short, fluffy fur", "covered in short, coarse hairs", "covered in short, soft hairs", "covered in long, coarse hairs", "covered in long, soft hairs", "covered in thick, soft hairs", "covered in thick, coarse hairs", "covered in thin, soft hairs", "covered in thin, coarse hairs"};
    static constexpr std::string_view names7a[] = {"black", "blue", "bronze", "brown", "gold", "grey", "orange", "pink", "purple", "red", "silver", "white", "yellow", "dark blue", "dark bronze", "dark brown", "dark gold", "dark grey", "dark orange", "dark pink", "dark purple", "dark red", "dark silver", "dark yellow", "light blue", "light bronze", "light brown", "light gold", "light grey", "light orange", "light pink", "light purple", "light red", "light silver", "light yellow"};
    static constexpr std::string_view names7b[] = {", black", ", blue", ", bronze", ", brown", ", gold", ", grey", ", orange", ", pink", ", purple", ", red", ", silver", ", white", ", yellow", ", dark blue", ", dark bronze", ", dark brown", ", dark gold", ", dark grey", ", dark orange", ", dark pink", ", dark purple", ", dark red", ", dark silver", ", dark yellow", ", light blue", ", light bronze", ", light brown", ", light gold", ", light grey", ", light orange", ", light pink", ", light purple", ", light red", ", light silver", ", light yellow", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view names7c[] = {", black", ", blue", ", bronze", ", brown", ", gold", ", grey", ", orange", ", pink", ", purple", ", red", ", silver", ", white", ", yellow", ", dark blue", ", dark bronze", ", dark brown", ", dark gold", ", dark grey", ", dark orange", ", dark pink", ", dark purple", ", dark red", ", dark silver", ", dark yellow", ", light blue", ", light bronze", ", light brown", ", light gold", ", light grey", ", light orange", ", light pink", ", light purple", ", light red", ", light silver", ", light yellow", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view names7d[] = {" or black", " or blue", " or bronze", " or brown", " or gold", " or grey", " or orange", " or pink", " or purple", " or red", " or silver", " or white", " or yellow", " or dark blue", " or dark bronze", " or dark brown", " or dark gold", " or dark grey", " or dark orange", " or dark pink", " or dark purple", " or dark red", " or dark silver", " or dark yellow", " or light blue", " or light bronze", " or light brown", " or light gold", " or light grey", " or light orange", " or light pink", " or light purple", " or light red", " or light silver", " or light yellow"};
    static constexpr std::string_view names8_1[] = {"barren areas", "cold areas", "darker areas", "forested areas", "frozen areas", "high areas", "hot areas", "humid areas", "low areas", "marshy areas", "moist areas", "mountainous areas", "open areas", "quiet areas", "rainy areas", "snowy areas", "temperate areas", "warm areas", "wet areas", "wintry areas"};
    static constexpr std::string_view names9[] = {"common", "extremely common", "extremely rare", "fairly common", "fairly rare", "quite common", "quite rare", "rare", "relatively common", "relatively rare"};
    static constexpr std::string_view names10[] = {"herbivores", "carnivores", "omnivores"};
    static constexpr std::string_view names11_1[] = {"relatively small", "relatively large", "fairly small", "fairly large", "small, long", "large, long", "small, thin", "large, wide", "small, narrow", "long, narrow"};
    static constexpr std::string_view names12[] = {"long", "short", "wide", "narrow", "rough"};
    static constexpr std::string_view names13_1[] = {"grasses", "berries", "fruits", "nuts", "flowers", "plants", "leaves", "insects", "fish", "smaller creatures", "larger creatures", "mushrooms", "creatures"};
    static constexpr std::string_view names14[] = {"nocturnal", "diurnal", "crepuscular"};
    static constexpr std::string_view names15[] = {"sight", "sense of smell", "hearing", "taste buds", "extra sense"};
    static constexpr std::string_view names16[] = {"large, round eyes", "thin, narrow eyes", "small, slanted eyes", "small, round eyes", "small, beady eyes", "small, elliptic eyes", "large, elliptic eyes", "large, slanted eyes", "odd, but interesting eyes", "gorgeous eyes"};
    static constexpr std::string_view names17[] = {"not that great", "not very reliable", "not impressive", "a bit poor", "not too great", "lacking", "underdeveloped", "relatively poor"};
    static constexpr std::string_view names18_1[] = {"huge noses", "small noses", "wide noses", "long noses", "enormous noses", "thin noses", "an almost hidden nose", "a lack of a visible nose", "tiny noses", "narrow noses"};
    static constexpr std::string_view names19_1[] = {"enormous ears", "huge, flappy ears", "huge, hanging ears", "large, bended ears", "large, hanging ears", "large, round ears", "large, standing ears", "long, pointy ears", "short, flappy ears", "short, pointy ears", "small, bended ears", "small, hanging ears", "small, round ears", "small, standing ears", "tiny, almost hidden ears"};
    static constexpr std::string_view names20[] = {"relatively small", "relatively large", "fairly small", "fairly large", "small and long", "large and long", "small and thin", "large and wide", "small and narrow", "long and narrow"};
    static constexpr std::string_view names21[] = {"extremely high pitched", "very high pitched", "high pitched", "fairly high pitched", "relatively high pitched", "relatively low pitched", "fairly low pitched", "low pitched", "very low pitched", "extremely low pitched"};
    static constexpr std::string_view names22[] = {"extremely large", "extremely limited", "fairly limited", "fairly small", "fairly wide", "huge", "large", "limited", "small", "very limited", "very small", "wide"};
    static constexpr std::string_view names23[] = {"aggressive", "bold", "fairly violent", "invasive", "quite forceful", "quite frenzied", "quite intrusive", "quite nervous", "very aggressive", "very violent", "very peaceful", "calm", "fairly calm", "very calm", "very gentle", "very timid", "quite timid", "timid", "mild mannered", "gentle"};
    static constexpr std::string_view names24[] = {"they're very territorial.", "they get very territorial.", "they heavily defend their personal space.", "they'll fiercely defend their territory.", "they're quite territorial.", "they'll defend their territory strongly.", "their territory is well defended.", "they can get quite territorial.", "they're territorial in terms of personal space.", "their personal space is fiercely defended.", "they're not very territorial.", "they're not territorial at all.", "they won't defend their territory much.", "they tend to let their territory be taken be stronger creatures.", "they're not one to defend their territory.", "they're not keen on defending their personal space.", "they minimize conflict and thus aren't very territorial.", "they have no real territory and wish to avoid conflicts.", "they travel a lot and thus have no real territory nor urges to defend it.", "their nomadic lifestyle has made them placid in terms of defending territory."};
    static constexpr std::string_view names25_1[] = {"once a year", "twice a year", "once every two years", "once every 18 months", "once every three years", "twice to three times a year", "once or twice a year", "once every nine to ten months", "once every five years", "once every four years"};
    static constexpr std::string_view names26[] = {"mate and bond with a single partner for life", "mate with just 1 partner for life", "mate and bond with a select few partners for life", "mate and bond with one or two partners throughout life", "mate with multiple partners throughout life", "mate with one or two partners throughout life", "mate with a select few partners throughout life", "mate with a specificly selected partner for life", "mate with a select group of partners for life", "mate with a select few partners for life"};
    static constexpr std::string_view names27[] = {"long lifepans", "incredibily long lifespans", "very long lifespans", "fairly long lifespans", "short lifespans", "fairly short lifespans", "very short lifespans", "unfortunately short lifespans"};
    static constexpr std::string_view names28_1[] = {"is to be expected.", "isn't too surprising.", "is only normal.", "isn't out of the ordinary.", "isn't extraordinary.", "is quite common among other species as well."};
    static constexpr std::string_view names3_2[] = {" seal", " dolphin", "n orca", " minke whale", " blue whale", " fin whale", " humpback whale", " great white shark", " narwhal", " reef shark", " manta ray", " tuna", " squid", " salmon", " carp", " trout", " piranha", " goldfish", " bass", "n eel", " catfish", " pike", " small shark", " parrotfish", " young tuna"};
    static constexpr std::string_view names4a_2[] = {"two large flippers", "two small flippers", "two large flippers", "two small flippers", "four large flippers", "four small flippers", "two strong side fins", "four strong side fins", "two side fins", "four side fins", "two large side fins", "four large side fins", "two powerful side fins", "four powerful side fins", "two huge side fins", "four huge side fins"};
    static constexpr std::string_view names4b_2[] = {", a huge dorsal fin", ", a small dorsal fin", ", a thick, long dorsal fin", ", a thin, long dorsal fin", ", a wide, sail-like dorsal fin", ", a ribbon-like dorsal fin", ", a long, ribbon-like dorsal fin", ", a short, ribbon-like dorsal fin", ", a huge, sail-like dorsal fin", ", a short, strong dorsal fin", ", a long, strong dorsal fin", ", a short, pointy dorsal fin", ", a long, pointy dorsal fin", ", a long, streamlined dorsal fin", ", a short, streamlined dorsal fin"};
    static constexpr std::string_view names4c_2[] = {" and a huge, powerful tail", " and a huge, muscular tail", " and a large, muscular tail", " and a large, powerful tail", " and a short, muscular tail", " and a long, powerful tail", " and a short, powerful tail", " and a long, muscular tail", " and a huge, powerful tail", " and a huge, muscular tail", " and a large, muscular tail", " and a large, powerful tail", " and a short, muscular tail", " and a long, powerful tail", " and a short, powerful tail", " and a long, muscular tail"};
    static constexpr std::string_view names6_2[] = {""};
    static constexpr std::string_view names8_2[] = {"deep waters", "relatively shallow waters", "coastal areas", "the depths of the ocean", "the depths of the seas", "large lakes", "rivers", "large rivers", "lakes", "the entire ocean as they migrate"};
    static constexpr std::string_view names19_2[] = {"virtually no visible ears", "no visible ears", "pretty much no visible ears", "short, flappy ears", "short, pointy ears", "small, bended ears", "small, hanging ears", "small, round ears", "small, standing ears", "tiny, almost hidden ears"};
    static constexpr std::string_view names3_3[] = {" toad", " tree frog", " salamander", "n anaconda", "n earthworm", " gecko", " chameleon", " newt", " frog", " cobra", " komodo dragon", " viper", " coral snake", " python", " Chinese giant salamander"};
    static constexpr std::string_view names4a_3[] = {"four legs", "four legs and two arms", "no legs or arms, like a snake", "six legs", "two legs and two arms"};
    static constexpr std::string_view names4c_3[] = {", but they have no tail", " and a huge, powerful tail", " and a long, muscular tail", " and a long, powerful tail", " and a long, strong and agile tail", " and a long, strong tail", " and a long, thick tail", " and a long, thin tail", " and a long, useless tail", " and a long, weak tail", " and a short, muscular tail", " and a short, powerful tail", " and a short, strong tail", " and a short, stubby tail", " and a short, thick tail", " and a short, thin tail", " and a short, useless tail", " and a short, weak tail", " and a thick, powerful tail", " and remnants of what was once a tail"};
    static constexpr std::string_view names6_3[] = {" covered in a thin layer of mucous,", " covered in a thick layer of mucous,", " covered in a very thin layer of mucous,", " covered in a very thick layer of mucous,", " covered lightly in mucous,", " covered in nothing but small scales,", " covered in nothing but large scales,", ", ", ", ", ", "};
    static constexpr std::string_view names19_3[] = {"virtually no visible ears", "no visible ears", "pretty much no visible ears", "short, pointy ears", "small, bended ears", "small, hanging ears", "small, round ears", "small, standing ears", "tiny, almost hidden ears"};
    static constexpr std::string_view names25_2[] = {"once a year", "twice a year", "once every two years", "once every 18 months", "once every three years", "twice to three times a year", "once or twice a year", "once every three to four months", "four times a year", "three times a year"};
    static constexpr std::string_view names3_4[] = {" boa", " chameleon", " cobra", " crocodile", " diplodocus", " frog", " gecko", " komodo dragon", " newt", " python", " salamander", " sea turtle", " stegosaurus", " t-rex", " tortoise", " triceratops", " velociraptor", " viper", "n alligator", "n anaconda"};
    static constexpr std::string_view names4a_4[] = {"four legs", "four legs and two arms", "no legs or arms, like a snake", "six legs", "two legs and two arms"};
    static constexpr std::string_view names4c_4[] = {", but they have no tail", " and a huge, powerful tail", " and a long, muscular tail", " and a long, powerful tail", " and a long, strong and agile tail", " and a long, strong tail", " and a long, thick tail", " and a long, thin tail", " and a long, useless tail", " and a long, weak tail", " and a short, muscular tail", " and a short, powerful tail", " and a short, strong tail", " and a short, stubby tail", " and a short, thick tail", " and a short, thin tail", " and a short, useless tail", " and a short, weak tail", " and a thick, powerful tail", " and remnants of what was once a tail"};
    static constexpr std::string_view names6_4[] = {" covered in thin, coarse scales,", " covered in large, coarse scales,", " covered in large, smooth scales,", " covered in large, strong scales,", " covered in small, coarse scales,", " covered in small, smooth scales,", " covered in small, strong scales,", " covered in strong, hard scales,", " covered in thick, coarse scales,", " covered in thick, strong scales,"};
    static constexpr std::string_view names8_3[] = {"barren areas", "darker areas", "forested areas", "high areas", "hot areas", "humid areas", "low areas", "marshy areas", "moist areas", "mountainous areas", "open areas", "quiet areas", "rainy areas", "temperate areas", "warm areas", "wet areas"};
    static constexpr std::string_view names18_2[] = {"small noses", "wide noses", "long noses", "thin noses", "almost hidden noses", "lack of a visible nose", "tiny noses", "narrow noses"};
    static constexpr std::string_view names19_4[] = {"virtually no visible ears", "no visible ears", "pretty much no visible ears", "short, pointy ears", "small, bended ears", "small, hanging ears", "small, round ears", "small, standing ears", "tiny, almost hidden ears"};
    static constexpr std::string_view names25_3[] = {"once a year", "twice a year", "once every two years", "once every 18 months", "once every three years", "twice to three times a year", "once or twice a year", "once every three to four months", "four times a year", "three times a year"};
    static constexpr std::string_view names3_5[] = {" seal", " dolphin", "n orca", " minke whale", " blue whale", " fin whale", " humpback whale", " great white shark", " narwhal", " reef shark", " manta ray", " tuna", " squid", " salmon", " carp", " trout", " piranha", " goldfish", " bass", "n eel", " catfish", " pike", " small shark", " parrotfish", " young tuna", " pufferfish", " clownfish", " triggerfish", " guppy", " discus fish", " lionfish"};
    static constexpr std::string_view names4a_5[] = {"two strong side fins", "four strong side fins", "two side fins", "four side fins", "two large side fins", "four large side fins", "two powerful side fins", "four powerful side fins", "two huge side fins", "four huge side fins"};
    static constexpr std::string_view names4b_3[] = {", a huge dorsal fin", ", a small dorsal fin", ", a thick, long dorsal fin", ", a thin, long dorsal fin", ", a wide, sail-like dorsal fin", ", a ribbon-like dorsal fin", ", a long, ribbon-like dorsal fin", ", a short, ribbon-like dorsal fin", ", a huge, sail-like dorsal fin", ", a short, strong dorsal fin", ", a long, strong dorsal fin", ", a short, pointy dorsal fin", ", a long, pointy dorsal fin", ", a long, streamlined dorsal fin", ", a short, streamlined dorsal fin"};
    static constexpr std::string_view names4c_5[] = {" and a huge, powerful tail and small anal fin", " and a huge, muscular tail and small anal fin", " and a large, muscular tail and small anal fin", " and a large, powerful tail and small anal fin", " and a short, muscular tail and small anal fin", " and a long, powerful tail and small anal fin", " and a short, powerful tail and small anal fin", " and a long, muscular tail and small anal fin", " and a huge, powerful tail and small anal fin", " and a huge, muscular tail and long anal fin", " and a large, muscular tail and long anal fin", " and a large, powerful tail and long anal fin", " and a short, muscular tail and long anal fin", " and a long, powerful tail and long anal fin", " and a short, powerful tail and long anal fin", " and a long, muscular tail and long anal fin"};
    static constexpr std::string_view names6_5[] = {" covered in thin, coarse scales,", " covered in large, coarse scales,", " covered in large, smooth scales,", " covered in large, strong scales,", " covered in small, coarse scales,", " covered in small, smooth scales,", " covered in small, strong scales,", " covered in strong, hard scales,", " covered in thick, coarse scales,", " covered in thick, strong scales,"};
    static constexpr std::string_view names8_4[] = {"deep waters", "relatively shallow waters", "coastal areas", "the depths of the ocean", "the depths of the seas", "large lakes", "rivers", "large rivers", "lakes", "the entire ocean as they migrate"};
    static constexpr std::string_view names18_3[] = {"small noses", "wide noses", "long noses", "thin noses", "almost hidden noses", "lack of a visible nose", "tiny noses", "narrow noses"};
    static constexpr std::string_view names19_5[] = {"virtually no visible ears", "no visible ears", "pretty much no visible ears", "tiny, almost hidden ears"};
    static constexpr std::string_view names25_4[] = {"once a year", "twice a year", "once every two years", "once every 18 months", "once every three years", "twice to three times a year", "once or twice a year", "once every three to four months", "four times a year", "three times a year"};
    static constexpr std::string_view names3_6[] = {" lobster", " hermite crab", " king crab", " squid", " mosquito", " fly", " fruitfly", "n octopus", " bee", " wasp", " shrimp", " crayfish", " flea", " prawn", " giant squid"};
    static constexpr std::string_view names4a_6[] = {"eight legs", "eight tentacles", "four clawed arms, four legs", "four legs", "four tentacles, four legs", "four tentacles, six legs", "four tentacles, two clawed arms", "four tentacles, two legs", "four winged arms, four legs", "four winged arms, six legs", "four winged arms, two legs", "four wings, four legs", "four wings, six legs", "four wings, two legs", "six legs", "six tentacles", "two clawed arms, four legs", "two clawed arms, six legs", "two clawed arms, two legs", "two legs, two arms", "two tentacles, four legs", "two tentacles, six legs", "two tentacles, two clawed arms", "two tentacles, two legs", "two winged arms, four legs", "two winged arms, six legs", "two winged arms, two legs", "two wings, four legs", "two wings, six legs", "two wings, two legs"};
    static constexpr std::string_view names4c_6[] = {", but they have no tail", " and a huge, powerful tail", " and a long, muscular tail", " and a long, powerful tail", " and a long, strong and agile tail", " and a long, strong tail", " and a long, thick tail", " and a long, thin tail", " and a long, useless tail", " and a long, weak tail", " and a short, muscular tail", " and a short, powerful tail", " and a short, strong tail", " and a short, stubby tail", " and a short, thick tail", " and a short, thin tail", " and a short, useless tail", " and a short, weak tail", " and a thick, powerful tail", " and remnants of what was once a tail"};
    static constexpr std::string_view names5_2[] = {"soft, but strong skin", "thick, strong skin", "soft, delicate skin", "thick, rough skin", "thin, rough skin", "thin, delicate skin", "thick, smooth skin", "soft, smooth skin", "thin, but strong skin", "thick, but delicate skin", "stong, armored skin", "thick, armored skin", "soft, armored skin", "thinly armored skin", "hard, armored skin"};
    static constexpr std::string_view names6_6[] = {""};
    static constexpr std::string_view names25_5[] = {"once a year", "twice a year", "once every two years", "once every 18 months", "once every three years", "twice to three times a year", "once or twice a year", "once every three to four months", "four times a year", "three times a year"};
    static constexpr std::string_view names3_7[] = {"n albatross", " chicken", " cockatoo", " condor", " crane", " crow", " dove", " duck", "n eagle", " falcon", " flamingo", " kiwi", "n owl", " macaw", "n ostrich", " peacock", " pelican", " penguin", " pigeon", " raven", " robin", " sparrow", " swan", " swift", " vulture"};
    static constexpr std::string_view names4a_7[] = {"two huge wings", "four huge wings", "two huge, powerful wings", "four huge, powerful wings", "two huge and two smaller wings", "two enormous wings", "four enormous wings", "two large and four smaller wings", "four smaller wings", "two smaller wings"};
    static constexpr std::string_view names4b_4[] = {", two strong, clawed legs", ", two small, clawed legs", ", four strong, clawed legs", ", four small, clawed legs", ", two strong legs", ", four strong legs", ", two small legs", ", four small legs", ", two thin, long legs", ", two long, strong legs, "};
    static constexpr std::string_view names4c_7[] = {" and a huge tail", " and a huge, wide tail", " and a huge, powerful tail", " and a long, powerful tail", " and a long, elegant tail", " and a short, elegant tail", " and a short, powerful tail", " and a wide, powerful tail", " and a wide, elegant tail", " and a short tail"};
    static constexpr std::string_view names6_7[] = {" covered in large feathers,", " covered in short feathers,", " covered in thick feathers,", " covered in thin feathers,", " covered in small, narrow feathers,", " covered in large, narrow feathers,", " covered in large, thin feathers,", " covered in large, wide feathers,", " covered in long, thin feathers,", " covered in long, wide feathers,", " covered in short, thin feathers,", " covered in short, wide feathers,", " covered in small feathers,", " covered in small, thin feathers,", " covered in small, wide feathers,"};
    static constexpr std::string_view names11_2[] = {""};
    static constexpr std::string_view names18_4[] = {"long beaks", "sharp beaks", "thin beaks", "short beaks", "huge beaks", "enormous beaks", "wide beaks", "thin, sharp beaks", "long, sharp beaks", "long, pointy beaks", "short, pointy beaks", "huge, pointy beaks", "huge, sharp beaks", "short, sharp beaks", "thin, pointy beaks"};
    static constexpr std::string_view names19_6[] = {"virtually no visible ears", "no visible ears", "pretty much no visible ears", "tiny, almost hidden ears"};
    static constexpr std::string_view names13_2[] = {"plants", "soft corals", "hard corals"};
    static constexpr std::string_view names13_3[] = {"grasses", "berries", "fruits", "nuts", "flowers", "plants", "leaves", "mushrooms"};
    static constexpr std::string_view names13_4[] = {"fish", "smaller creatures", "larger creatures", "creatures", "crustaceans"};
    static constexpr std::string_view names13_5[] = {"insects", "fish", "smaller creatures", "larger creatures", "creatures"};
    static constexpr std::string_view names13_6[] = {"fish", "smaller creatures", "larger creatures", "creatures", "crustaceans", "plants", "soft corals", "hard corals"};
    static constexpr std::string_view names28_2[] = {"is quite surprising.", "is just amazing.", "is beautiful in its own right.", "is something special indeed.", "is astonishing."};

    ArrayView names11; ArrayView names13; ArrayView names18; ArrayView names19; ArrayView names25; ArrayView names28; ArrayView names3; ArrayView names4a; ArrayView names4b; ArrayView names4c; ArrayView names5; ArrayView names6; ArrayView names8; std::string name; std::string name2; std::string name3; std::string name4; std::string name5; std::string name6; std::string name7; std::string names11a; std::string names23b; std::string result; size_t random0 = 0; size_t random1 = 0; size_t random10 = 0; size_t random11 = 0; size_t random12 = 0; size_t random13 = 0; size_t random14 = 0; size_t random15a = 0; size_t random15b = 0; size_t random16 = 0; size_t random17 = 0; size_t random18 = 0; size_t random19 = 0; size_t random2 = 0; size_t random20 = 0; size_t random21a = 0; size_t random21b = 0; size_t random22 = 0; size_t random23 = 0; size_t random24 = 0; size_t random25 = 0; size_t random26 = 0; size_t random27 = 0; size_t random28 = 0; size_t random2b = 0; size_t random3 = 0; size_t random4a = 0; size_t random4b = 0; size_t random4c = 0; size_t random5 = 0; size_t random6 = 0; size_t random7a = 0; size_t random7b = 0; size_t random7c = 0; size_t random7d = 0; size_t random7e = 0; size_t random8 = 0; size_t random9 = 0; int i = 0;

    names3 = make_view(names3_1);
    names4a = make_view(names4a_1);
    names4b = make_view(names4b_1);
    names4c = make_view(names4c_1);
    names5 = make_view(names5_1);
    names6 = make_view(names6_1);
    names8 = make_view(names8_1);
    names11 = make_view(names11_1);
    names11a = "mouths, their teeth";
    names13 = make_view(names13_1);
    names18 = make_view(names18_1);
    names19 = make_view(names19_1);
    names23b = ", but ";
    names25 = make_view(names25_1);
    names28 = make_view(names28_1);
    random0 = rng() % std::size(names0);
    random1 = rng() % std::size(names1);
    random2 = rng() % std::size(names2);
    if (random2 == 1) {
    names3 = make_view(names3_2);
    names4a = make_view(names4a_2);
    names4b = make_view(names4b_2);
    names4c = make_view(names4c_2);
    names6 = make_view(names6_2);
    names8 = make_view(names8_2);
    names19 = make_view(names19_2);
    } else if (random2 == 2) {
    names3 = make_view(names3_3);
    names4a = make_view(names4a_3);
    names4c = make_view(names4c_3);
    names6 = make_view(names6_3);
    names19 = make_view(names19_3);
    names25 = make_view(names25_2);
    } else if (random2 == 3) {
    names3 = make_view(names3_4);
    names4a = make_view(names4a_4);
    names4c = make_view(names4c_4);
    names6 = make_view(names6_4);
    names8 = make_view(names8_3);
    names18 = make_view(names18_2);
    names19 = make_view(names19_4);
    names25 = make_view(names25_3);
    } else if (random2 == 4) {
    names3 = make_view(names3_5);
    names4a = make_view(names4a_5);
    names4b = make_view(names4b_3);
    names4c = make_view(names4c_5);
    names6 = make_view(names6_5);
    names8 = make_view(names8_4);
    names11a = "mouths";
    names18 = make_view(names18_3);
    names19 = make_view(names19_5);
    names25 = make_view(names25_4);
    } else if (random2 == 5) {
    names3 = make_view(names3_6);
    names4a = make_view(names4a_6);
    names4c = make_view(names4c_6);
    names5 = make_view(names5_2);
    names6 = make_view(names6_6);
    names11a = "mouths";
    names25 = make_view(names25_5);
    } else if (random2 == 6) {
    names3 = make_view(names3_7);
    names4a = make_view(names4a_7);
    names4b = make_view(names4b_4);
    names4c = make_view(names4c_7);
    names6 = make_view(names6_7);
    names11 = make_view(names11_2);
    names11a = "beaks";
    names18 = make_view(names18_4);
    names19 = make_view(names19_6);
    }
    random3 = rng() % std::size(names3);
    random4a = rng() % std::size(names4a);
    random4b = rng() % std::size(names4b);
    random4c = rng() % std::size(names4c);
    random5 = rng() % std::size(names5);
    random6 = rng() % std::size(names6);
    random7a = rng() % std::size(names7a);
    random7b = rng() % std::size(names7b);
    while (random7b == random7a) {
    random2b = rng() % std::size(names7b);
    }
    random7c = rng() % std::size(names7c);
    while (random7c == random7a || random7c == random7b) {
    random7c = rng() % std::size(names7c);
    }
    random7d = rng() % std::size(names7c);
    while (random7d == random7a || random7d == random7b || random7d == random7c) {
    random7d = rng() % std::size(names7c);
    }
    random7e = rng() % std::size(names7d);
    while (random7e == random7a || random7e == random7b || random7e == random7c || random7e == random7d) {
    random7e = rng() % std::size(names7d);
    }
    random8 = rng() % std::size(names8);
    random9 = rng() % std::size(names9);
    random10 = rng() % std::size(names10);
    if (random10 == 0) {
    if (random2 == 1 || random2 == 4) {
    names13 = make_view(names13_2);
    } else {
    names13 = make_view(names13_3);
    }
    } else if (random10 == 1) {
    if (random2 == 1 || random2 == 4) {
    names13 = make_view(names13_4);
    } else {
    names13 = make_view(names13_5);
    }
    } else if (random10 == 2) {
    if (random2 == 1 || random2 == 4) {
    names13 = make_view(names13_6);
    }
    }
    random11 = rng() % std::size(names11);
    random12 = rng() % std::size(names12);
    random13 = rng() % std::size(names13);
    random14 = rng() % std::size(names14);
    random15a = rng() % std::size(names15);
    random15b = rng() % std::size(names15);
    while (random15b == random15a) {
    random15b = rng() % std::size(names15);
    }
    random16 = rng() % std::size(names16);
    random17 = rng() % std::size(names17);
    random18 = rng() % std::size(names18);
    random19 = rng() % std::size(names19);
    random20 = rng() % std::size(names20);
    name4 = "";
    name5 = "";
    if (random15a != 0 && random15b != 0) {
    name4 = "They're " + names14[random14] + " and rely on their " + names15[random15a] + " and " + names15[random15b] + " to get around. They do have " + names16[random16] + ", but their sight is " + names17[random17] + ".";
    name5 = "They have " + names18[random18] + " and " + names19[random19] + ". Their heads are " + names20[random20] + " in comparison to their bodies.";
    } else if (random15a != 1 && random15b != 1) {
    name4 = "They're " + names14[random14] + " and rely on their " + names15[random15a] + " and " + names15[random15b] + " to get around. They do have " + names18[random18] + ", but their sense of smell is " + names17[random17] + ".";
    name5 = "They have " + names16[random16] + " and " + names19[random19] + ". Their heads are " + names20[random20] + " in comparison to their bodies.";
    } else if (random15a != 2 && random15b != 2) {
    name4 = "They're " + names14[random14] + " and rely on their " + names15[random15a] + " and " + names15[random15b] + " to get around. They do have " + names19[random19] + ", but their hearing is " + names17[random17] + ".";
    name5 = "They have " + names18[random18] + " and " + names16[random16] + ". Their heads are " + names20[random20] + " in comparison to their bodies.";
    } else if (random15a != 3 && random15b != 3) {
    name4 = "They're " + names14[random14] + " and rely on their " + names15[random15a] + " and " + names15[random15b] + " to get around. However, their taste buds are " + names17[random17] + ".";
    name5 = "They have " + names16[random16] + ", " + names18[random18] + " and " + names19[random19] + ". Their heads are " + names20[random20] + " in comparison to their bodies.";
    } else if (random15a != 4 && random15b != 4) {
    name4 = "They're " + names14[random14] + " and rely on their " + names15[random15a] + " and " + names15[random15b] + " to get around. However, their other senses are " + names17[random17] + ".";
    name5 = "They have " + names16[random16] + ", " + names18[random18] + " and " + names19[random19] + ". Their heads are " + names20[random20] + " in comparison to their bodies.";
    }
    random21a = rng() % std::size(names21);
    random21b = rng() % std::size(names21);
    while (random21b == random21a) {
    random21b = rng() % std::size(names21);
    }
    random22 = rng() % std::size(names22);
    random23 = rng() % std::size(names23);
    random24 = rng() % std::size(names24);
    if (random23 < 10 && random24 < 10 || random23 > 9 && random24 > 9) {
    names23b = " and ";
    }
    random25 = rng() % std::size(names25);
    random26 = rng() % std::size(names26);
    random27 = rng() % std::size(names27);
    if (random27 < 4 && random26 < 4) {
    names28 = make_view(names28_2);
    }
    random28 = rng() % std::size(names28);
    name = "This " + names1[random1] + names0[random0] + " creature is a type of " + names2[random2] + ". It's about the size of a" + names3[random3] + ", has " + names4a[random4a] + names4b[random4b] + names4c[random4c] + ".";
    name2 = "They have a " + names5[random5] + " " + names6[random6] + " which is usually either " + names7a[random7a] + names7b[random7b] + names7c[random7c] + names7c[random7d] + names7d[random7e] + " or a combination of these colors.";
    name3 = "They live in " + names8[random8] + " and are " + names9[random9] + ". They're " + names10[random10] + " and their " + names11[random11] + " " + names11a + " and " + names12[random12] + " tongue are ideal for eating " + names13[random13] + ".";
    name6 = "They make sounds ranging from " + names21[random21a] + " to " + names21[random21b] + " and have a " + names22[random22] + " range of sounds they make to indicate discoveries, dangers and otherwise communicate with each other.";
    name7 = "These creatures are " + names23[random23] + names23b + names24[random24] + " They mate " + names25[random25] + " and they " + names26[random26] + ". Which, with their " + names27[random27] + ", " + names28[random28];
    result = "";
    result += name;
    result += "\n";
    result += name2;
    result += "\n";
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
    result += "\n";
    result += name7;
    return result;
}
