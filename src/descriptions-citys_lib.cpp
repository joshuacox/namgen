#include "descriptions-citys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_citys_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"along the banks of a mighty river", "along the banks of modest rivers", "along the banks of a gentle river", "along the banks of a crystal clear river", "along the banks of a labyrinth of rivers", "atop the crowns of majestic hills", "atop gentle hills", "atop emerald hills of grass", "atop quiet and serene hills", "atop robust hills", "at the base of a mighty mountain", "in the shadow of an enormous mountain", "on the sunny side of a gentle mountain", "at the base of a rugged mountain", "at the base of a modest mountain", "in the center of a giant forest", "in a large glade of a mighty forest", "at the edge of a lush forest", "at the edge of a dense, tall forest", "among the towering trees of a huge forest", "atop a breathtaking fjord", "atop a towering fjord", "atop the rugged walls of a fjord", "atop the steep facade of a mighty fjord", "atop the rocky heights of a fjord", "amidst the green grasses of a gentle field", "amidst the windy fields of gentle grasslands", "amidst the swaying grasses of a windy meadow", "amidst the dry grasses of a simple savanna", "amidst the lush grasses of an evergreen pasture", "amidst the ivory fields of snow", "amidst the gentle snows of a pristine tundra", "amidst the crisp snows of a silver taiga", "amidst the frozen lands of a bitter expanse", "amidst the bleak fields of snow", "at the edge of a mighty swamp", "in the center of an expansive swamp", "at the borders of a murky swamp", "amidst the murky waters of an enormous swamp", "around the mushy waters of a traitorous swamp", "at the base of a mighty volcano", "in the shadow of a dormant volcano", "at the base of a traitorous volcano", "in the shadow of a rugged volcano", "at the base of a potentially active volcano", "on the banks of a large natural harbor", "on the banks of a carefully crafted harbor", "on the banks of a modest natural harbor", "on the banks of a man-made harbor", "on the banks of a delicate natural harbor", "amidst the flora of a mighty jungle", "at the edge of a lush jungle", "at the center of a dangerous jungle", "at the border of a traitorous jungle", "at the center of a gorgeous jungle", "at the center of a delicate island", "amidst a large, rugged island", "on a simple island", "at the edge of an enormous island", "at the center of a relatively small island", "at the edge of a desert", "amidst the sands of a mighty desert", "around an oasis in the middle of a desert", "in the middle of a scorching desert", "in a seemingly endless desert"};
    static constexpr std::string_view nm2[] = {"Southport", "Highfront", "Shroudmoor", "Freyport", "Westborough", "Dawnburgh", "Oldwood", "Stonewick", "Freyford", "Blackmere", "Rosemore", "Amberhill", "Evermere", "Sunhold", "Ebonwick", "Ravenside", "Riverburn", "Embercrest", "Whiteburn", "Oxglen", "Madhollow", "Ironford", "Earthwall", "Claybourne", "Shimmergarde", "Earthbury", "Fayglen", "Craghorn", "Bellburn", "Kilbrook"};
    static constexpr std::string_view nm3[] = {"a true modern", "a modest", "a historic", "an evergrowing", "an architectural", "a technological", "an extraordinary", "a gorgeous", "an ancient", "a classic", "a contemporary", "a state-of-the-art", "a fully modernized", "a future oriented", "a leading-edge"};
    static constexpr std::string_view nm4[] = {"metropolis", "marvel", "wonder", "city", "phenomenon", "sight", "curiosity", "display of wonder", "urban phenomenon", "trade center"};
    static constexpr std::string_view nm5[] = {"beauty", "wonder", "uniqueness", "appearance", "allure", "grace", "elegance", "charm"};
    static constexpr std::string_view nm6[] = {"snowy mountains", "mighty mountains", "tall mountains", "a gentle mountain", "a majestic mountain", "lush forests", "majestic forests", "grand forests", "several waterfalls", "monumental waterfalls", "cascading waterfalls", "a dorment volcano", "a smoldering volcano", "a fuming volcano", "lush fields of grass", "green, fertile fields", "rich, luscious fields", "gentle hills", "an abundance of hills", "modest hills", "clear blue skies", "pristine skies", "everclear skies"};
    static constexpr std::string_view nm7[] = {"resources", "riches", "trade resources", "materials", "climate"};
    static constexpr std::string_view nm8c[] = {"riddled", "packed", "crowded", "sprinkled", "scattered", "littered", "growing", "spreading"};
    static constexpr std::string_view nm9[] = {"tall", "impressive", "modest", "towering", "soaring", "giant", "stylish", "elaborate", "various", "distinct", "unique", "peculiar", "similar", "luxurious", "elegant", "impressive"};
    static constexpr std::string_view nm10[] = {"a new one seems to pop up every other week", "many have clearly been built within the last decade", "many show their age and a rich history", "a lot of them seem to have evolved throughout the ages", "more seem to be on their way", "they look astonishingly beautiful all together", "they each represent the many different aspects of the city", "they clearly show what they represent to the city itself", "they've been designed to adorn the city and each other", "they have aspects which represent their past, present and future", "each was more impressive than the next", "while modern now, their history still shined through", "their history seemed to shine more now than ever", "each seems to evolve with the times without losing their history", "they all seem to be in perfect unison despite being different", "they seem to be continuously evolving as new additions are added even now", "there is no place on earth with anything like this", "even from afar they manage to display their beauty", "their beauty is only matched by each other", "they seem to be reaching higher and higher each year"};
    static constexpr std::string_view nm11[] = {"Business is booming", "Life is great", "Culture is rising", "The quality of life is high", "Technology is thriving", "Trade is at an all time high", "Recreation is impeccable", "Education is superb", "Parks and gardens are flourishing", "Health and services are faultless", "Daily life isn't too stressful", "Science and development is flourishing", "Employment is tremendous"};
    static constexpr std::string_view nm12[] = {"Various cultures", "New cultures", "Many new cultures", "A few new cultures", "Countless cultures", "Many different cultures"};
    static constexpr std::string_view nm13[] = {"the architecture", "education", "the city's development", "business", "the city's history", "education", "trade and relations", "international relations", "the city's people", "the city's cuisine"};
    static constexpr std::string_view nm14[] = {"few differences", "plain, ordinary people", "little diversity", "no variation", "monotony", "little contrast", "few cultures", "predictability"};
    static constexpr std::string_view nm15[] = {"a large melting pot", "a fusion of everything", "a new culture of variety", "a multicultural hub", "an amalgamation of differences"};
    static constexpr std::string_view nm16[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14"};
    static constexpr std::string_view nm17[] = {"restaurants", "bars", "clubs", "coffeehouses", "bistros", "bakeries", "concession stands", "diners", "food carts", "take-outs", "sandwich bars", "cafés", "ethnic restaurants", "gastropubs", "theme restaurants"};
    static constexpr std::string_view nm18[] = {"art galleries", "one of the many parks", "nature", "the national park", "sightseeing", "libraries", "water sports", "adventure sports", "sport activities", "concerts", "musical activities", "musea", "tours", "city exploring", "dance", "theaters", "arcades", "clubs", "an amusement park", "aerobics", "photography"};
    static constexpr std::string_view nm8_1[] = {"have been built with rocks from those very same mountains", "were designed with shapes and elements found in the mountains", "mimic the broad slopes and steep peeks of the mountains", "have been built in the shape of those same mountains"};
    static constexpr std::string_view nm8_2[] = {"have been built with timber from those very same forests", "have been built with many natural elements to keep in line with the forests", "have been built with both materials and stylistic shapes of the forests", "have been built alongside the trees and often incorporate many different forest elements"};
    static constexpr std::string_view nm8_3[] = {"have their own man-made waterfalls or similar elements as part of their architecture", "not only use water from those waterfalls, they often incorporate some form of falling water as part of their architecture", "mimic the falling waters of those waterfalls, sometimes by having their own man-made waterfalls", "incorporate the aesthetic elements of water and waterfalls, as well as the lush greenery they provide"};
    static constexpr std::string_view nm8_4[] = {"have been built in similar shapes as that very same volcano", "have been built with volcanic rocks and similar looking materials", "incorporate shapes and colors of both the volcano and of lava", "have been built not just to withstand a volcano, but with elements and shapes of a volcano"};
    static constexpr std::string_view nm8_5[] = {"have been built with an abundance of large windows to mimic the openness of fields", "have been built with a lot of open elements to mimic the openness and vastness of the fields around them", "are slim and tall, which mimics the grasses and openness of the fields around them", "incorporate grass as part of their architecture in order to continue the lushious aesthetic of the fields around them"};
    static constexpr std::string_view nm8_6[] = {"have been built with many round shapes and wide sizes, similar to the fields around them", "have been built in various round shapes and sizes, which mimics the playfulness of the hills around them", "have been built in shapes and with elements of the hills around them", "follow the flowing round shapes of those very same hills and continue the overall aesthetics"};
    static constexpr std::string_view nm8_7[] = {"were designed to take full advantage of the climate through large windows and lush gardens", "have been built with lots of glass and light elements to mimic the aesthetics of the blue skies around them", "have been built to great heights, as if to try and reach the blue skies above them", "were designed to take full advantage of the climate, as more daring elements can be created when you don't have to worry about strong winds"};

    ArrayView nm8; std::string name; std::string name2; std::string name3; std::string name4; std::string nm8b; std::string result; size_t rnd1 = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd17 = 0; size_t rnd17b = 0; size_t rnd17c = 0; size_t rnd18 = 0; size_t rnd18b = 0; size_t rnd18c = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd8c = 0; size_t rnd9 = 0; int i = 0;

    rnd1 = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    if (rnd1 > 59) {
    while (rnd6 < 20) {
    rnd6 = rng() % std::size(nm6);
    }
    }
    if (rnd6 > 19) {
    rnd7 = 4;
    }
    if (rnd6 < 5) {
    nm8 = make_view(nm8_1);
    nm8b = " mountains ";
    } else if (rnd6 > 4 && rnd6 < 8) {
    nm8 = make_view(nm8_2);
    nm8b = " forests ";
    } else if (rnd6 > 7 && rnd6 < 11) {
    nm8 = make_view(nm8_3);
    nm8b = " waterfalls ";
    } else if (rnd6 > 10 && rnd6 < 14) {
    nm8 = make_view(nm8_4);
    nm8b = " volcanoes ";
    } else if (rnd6 > 13 && rnd6 < 17) {
    nm8 = make_view(nm8_5);
    nm8b = " fields ";
    } else if (rnd6 > 16 && rnd6 < 20) {
    nm8 = make_view(nm8_6);
    nm8b = " hills ";
    } else {
    nm8 = make_view(nm8_7);
    nm8b = " skies ";
    }
    rnd8 = rng() % std::size(nm8);
    rnd8c = rng() % std::size(nm8c);
    rnd9 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    rnd12 = rng() % std::size(nm12);
    rnd13 = rng() % std::size(nm13);
    rnd14 = rng() % std::size(nm14);
    rnd15 = rng() % std::size(nm15);
    rnd16 = rng() % std::size(nm16);
    rnd17 = rng() % std::size(nm17);
    rnd17b = rng() % std::size(nm17);
    while (rnd17 == rnd17b) {
    rnd17b = rng() % std::size(nm17);
    }
    rnd17c = rng() % std::size(nm17);
    while (rnd17 == rnd17c || rnd17b == rnd17c) {
    rnd17c = rng() % std::size(nm17);
    }
    rnd18 = rng() % std::size(nm18);
    rnd18b = rng() % std::size(nm18);
    rnd18c = rng() % std::size(nm18);
    while (rnd18 == rnd18b) {
    rnd18b = rng() % std::size(nm18);
    }
    rnd18c = rng() % std::size(nm18);
    while (rnd17 == rnd18c || rnd18b == rnd18c) {
    rnd18c = rng() % std::size(nm18);
    }
    name = "The city of " + nm2[rnd2] + " was built " + nm1[rnd1] + " and is truly " + nm3[rnd3] + " " + nm4[rnd4] + ". Its " + nm5[rnd5] + " is matched by the backdrop of " + nm6[rnd6] + " which have helped shape the city to what it is today.";
    name2 = "The " + nm7[rnd7] + " these " + nm8b + " brought were of great importance, but they were also influential when it came to architectural designs as the vast majority of buildings " + nm8[rnd8] + ".";
    name3 = "The skyline is " + nm8c[rnd8c] + " with " + nm9[rnd9] + " skyscrapers and " + nm10[rnd10] + ". " + nm11[rnd11] + " in " + nm2[rnd2] + " and it has attracted a lot of attention. " + nm12[rnd12] + " have left their mark not just on " + nm13[rnd13] + ", but also upon the city's identity. What historically was a city of " + nm14[rnd14] + " has grown into " + nm15[rnd15] + " and it's this that unites the " + nm16[rnd16] + " million people to this day.";
    name4 = "It's this multicultural identity that has truly left its mark. Hundreds of " + nm17[rnd17] + ", " + nm17[rnd17b] + " and " + nm17[rnd17c] + " offer a plethora of culinary choices and those who feel hungry for something else can enjoy " + nm18[rnd18] + ", " + nm18[rnd18b] + ", " + nm18[rnd18c] + " or one of the many other recreational venues.";
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
    return result;
}
