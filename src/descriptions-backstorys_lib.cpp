#include "descriptions-backstorys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_backstorys_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1_1[] = {"He", "he", "his", "him", "man"};
    static constexpr std::string_view nm2_1[] = {"adventurous", "affectionate", "analytical", "athletic", "brave", "calm", "capable", "charismatic", "charming", "cheerful", "creative", "curious", "daring", "dedicated", "dependable", "determined", "driven", "dutiful", "eager", "elegant", "energetic", "faithful", "funny", "generous", "gentle", "happy", "helpful", "honest", "hospitable", "humble", "humorous", "innocent", "intelligent", "intrepid", "jovial", "just", "light-hearted", "loyal", "modest", "mysterious", "polite", "popular", "proud", "quick", "reliable", "responsible", "savvy", "sensitive", "sincere", "sweet", "talkative", "thoughtful", "whimsical", "wise", "witty"};
    static constexpr std::string_view nm3_1[] = {"anxious", "arrogant", "bewildered", "bossy", "conceited", "confused", "facetious", "foolish", "greedy", "grouchy", "harsh", "ignorant", "immature", "impatient", "impulsive", "jealous", "lonely", "mean", "naive", "nervous", "opinionated", "pompous", "rash", "restless", "rude", "selfish", "snobbish", "stubborn", "timid", "uncontrolled"};
    static constexpr std::string_view nm4[] = {"This is to be expected from somebody", "But what'd you expect from somebody", "This isn't surprising considering for someone", "Which isn't out of the ordinary for someone", "But this is all just a facade, a mechanism to deal", "But there's more than this to somebody", "But there's more than meets the eye, not surprising for somebody"};
    static constexpr std::string_view nm5_1[] = {"n average", " wealthy", " royal", "n ordinary", " fairly rich", " high class", " middle class", " loving", " large", " small", " decent", " successful"};
    static constexpr std::string_view nm6_1[] = {"n average", " normal", " large", " wealthy", " major", "n important", " merchant", " developing", " developed"};
    static constexpr std::string_view nm7[] = {"town", "city", "village", "port", "community", "capital"};
    static constexpr std::string_view nm8[] = {"without worry", "out of trouble", "free of worries", "free of trouble", "in peace", "comfortably", "happily"};
    static constexpr std::string_view nm10_1[] = {"things changed", "things began to change", "life changed", "life began to change"};
    static constexpr std::string_view nm11_1[] = {"gained responsibilities", "gained new responsibilities", "became more important", "became more important to society", "got an important job", "started to travel a lot", "started to travel the world", "started to experience the world", "started working for the family company", "studied a lot", "went to college", "explored the country", "moved out", "moved in with a friend", "did volunteering work", "did a lot of small jobs", "moved to another country", "became a travelling adventurer", "went on an adventure", "improved upon existing powers", "got a new pet", "got a new companion"};
    static constexpr std::string_view nm12_1[] = {"among the most popular people", "becoming quite desirable", "very successful", "growing up fast", "meeting a lot of influential people", "making many new friends", "learning a lot of new skills", "gaining a little fame", "making some great new friends", "about to meet 'Mr(s). Right'", "learning a new language", "becoming more cultured", "slowly improving upon existing skills", "learning how to cook in new styles", "strengthening the relationships with friends", "strengthening the relationship with both parents", "competing in large tournaments"};
    static constexpr std::string_view nm12b_1[] = {"managed to bloom", "succeeded", "managed to thrive", "boomed", "went beyond expectations", "reached for the stars", "lives the dream", "blossomed", "reached the top", "made a fortune", "fulfilled dreams", "thrived", "enjoys life", "loves life", "struggles to make it", "is going on a journey", "is part of an adventure", "is trying to reach the top", "is unstoppable", "is on top of the world", "is exploring new areas", "is discovering hidden secrets", "is discovering hidden treasures", "is venturing out", "is trying to help others"};
    static constexpr std::string_view nm13_1[] = {"With the support of great friends", "With the support of great parents", "With plenty of money and connections", "Alongside great friends", "With amazing, new friends", "With a great deal of determination", "With determination and some luck", "Alongside trusted friends", "With a great companion", "Through hard work", "Through plenty of trial and error", "By never giving up", "After an astonishing adventure", "With the help of great friends", "Having overcome plenty of obstacles"};
    static constexpr std::string_view nm14_1[] = {"strange", "weird", "crazy", "ever changing", "fast", "fast changing", "amazing", "fantasy", "fantastic", "wacky", "absurd", "strange", "mad", "wild", "remarkable", "wonderful", "outlandish", "astonishing", "extraordinary", "mystifying"};
    static constexpr std::string_view nm15_1[] = {"bravery", "brilliance", "capability", "charm", "compassion", "curiosity", "determination", "diligence", "eagerness", "sense of humor", "wits", "cunning", "perseverance", "persistence", "skills", "powers", "talents", "wisdom", "intrepidness", "honesty"};
    static constexpr std::string_view nm16_1[] = {"reaching great success", "finding a way to the top", "fulfilling all dreams", "accomplish all goals", "improving the world", "going beyond expectations", "climbing to the top", "staying ahead of the game", "reaching full potential", "doing anything"};
    static constexpr std::string_view nm17_1[] = {"a force to be reckoned with", "a true inspiration for many", "a true friend for life", "an ally you'd want by your side", "somebody we can expect great things of", "somebody who could change the world", "a great leader, perhaps even of the nation", "an unstoppable force", "a friend you'd want by your side", "a person of (great) importance"};
    static constexpr std::string_view nm18_1[] = {"Despite all this success,", "However,", "But there may be more to it than this;", "But for now that's speculation;", "But only time will tell;", "But who really knows what will happen;", "But anything could happen;", "But things could change quickly;"};
    static constexpr std::string_view nm19_1[] = {"searching for a higher purpose", "still studying", "enjoying the simpler life", "having fun with friends", "travelling the world", "exploring everything", "still growing up and learning new things", "still finding the right place in the world", "still looking for a true calling", "still trying to perfect skills", "improving upon skills and talents", "learning how to reach full potential", "enjoying the world and its beauty", "looking for a place to truly call home", "still learning, exploring and discovering"};
    static constexpr std::string_view nm20_1[] = {"to explore", "than meets the eye", "than we know", "secrets than answers", "than what we get to know", "to experience", "to discover", "to see, taste and experience", "than people let on", "incredible sights to behold", "watchful eyes than expected", "caution than needed", "to learn", "to enjoy", "people to meet"};
    static constexpr std::string_view nm21_1[] = {"great friends", "great companions", "great parents", "amazing friends", "plenty of resources", "a great family", "awesome friends", "great people around", "wise teachers and great friends", "a close group of friends"};
    static constexpr std::string_view nm1_2[] = {"She", "she", "her", "her", "woman"};
    static constexpr std::string_view nm2_2[] = {"adventurous", "ambitious", "angry", "arrogant", "brave", "calm", "capable", "cautious", "clever", "coarse", "conceited", "confident", "crafty", "cross", "daring", "dauntless", "determined", "eager", "efficient", "facetious", "fierce", "frank", "gloomy", "greedy", "hardy", "harsh", "impartial", "impatient", "impolite", "impulsive", "independent", "intelligent", "keen", "loyal", "malicious", "mysterious", "observant", "pensive", "petulant", "precise", "punctilious", "quick", "quiet", "sarcastic", "scornful", "self-reliant", "sincere", "skillful", "sly", "stingy", "strict", "stubborn", "sullen", "tactful", "versatile", "vulgar", "witty"};
    static constexpr std::string_view nm3_2[] = {"disturbing", "dreadful", "gruesome", "horrifying", "shocking", "terrible", "tormented", "troubled", "ugly", "unsettling"};
    static constexpr std::string_view nm5_2[] = {" broken", " decent", " fairly rich", " great", " high class", " large", " loving", " lower class", " middle class", " needy", " poor", " small", " successful", " wealthy", "n average", "n ordinary"};
    static constexpr std::string_view nm6_2[] = {"n average", " normal", " large", " wealthy", " major", "n important", " merchant", " developing", " developed", " poor", " broken"};
    static constexpr std::string_view nm10_2[] = {"things changed", "life changed", "everything changed", "life changed drastically", "life took a turn for the worst", "things took a turn for the worst"};
    static constexpr std::string_view nm11_2[] = {"lost her parents in", "lost her mother in", "lost her father in", "lost her parents when they left after", "lost her best friend in", "lost her home when it was destroyed after", "lost her money after", "lost her family was they were split up after", "lost her brother in", "lost her sister in", "lost her sisters in", "lost her brothers in", "lost her siblings in", "lost her family in", "killed somebody by accident during", "killed somebody during", "maimed somebody during", "accidently maimed somebody during", "destroyed someone's life during", "destroyed someone's life by accident during"};
    static constexpr std::string_view nm11_3[] = {"lost his parents in", "lost his mother in", "lost his father in", "lost his parents when they left after", "lost his best friend in", "lost his home when it was destroyed after", "lost his money after", "lost his family was they were split up after", "lost his brother in", "lost his sister in", "lost his sisters in", "lost his brothers in", "lost his siblings in", "lost his family in", "killed somebody by accident during", "killed somebody during", "maimed somebody during", "accidently maimed somebody during", "destroyed someone's life during", "destroyed someone's life by accident during"};
    static constexpr std::string_view nm12_2[] = {"a freak fire", "a robbery gone wrong", "a terrible disaster", "a natural disaster", "a suspicious accident", "a fight which got out of control", "an invasion", "a brutal war", "a drought", "an act of terrorism", "a volcanic eruption", "a hurricane", "an earthquake", "a horrible flood", "a long lasting heatwave", "an epidemic", "a food shortage", "a power outage", "a government takeover", "a rebellion", "a revolution"};
    static constexpr std::string_view nm12b_2[] = {"abandoned by all", "forsaken by all", "arrested", "forgotten by everybody", "neglected by everybody", "shunned", "rejected by all", "becoming an outcast", "caught up with the wrong people", "initiated in a gang", "now part of a sinister clan", "headed for a life of crime", "headed for a life of misery", "now alone and forgotten", "now alone, miserable and abandoned"};
    static constexpr std::string_view nm13_2[] = {"With a new found friend", "All alone", "Without any help", "With a childhood friend", "With the help of a stranger", "Alone, lost and forgotten", "With the help of a small group of strangers", "With a couple of friends", "With a new found love", "With the help of a suspicious stranger", "With the help of a suspicious friend", "While persued by the authority", "While persued by a criminal gang", "While persued by strangers", "While obstructed by many", "Against all odds", "Alongside a brother", "Alongside a sister", "Alongside a cousin", "Together with a companion", "Together with a pet", "With a loyal stranger", "With a loyal friend", "Reunited with a friend", "Reunited with a lost pet"};
    static constexpr std::string_view nm14_2[] = {"wicked", "crazy", "bizarre", "cruel", "outlandish", "odd", "harsh", "criminal", "insane", "mad", "bitter", "rough", "bleak", "brutal", "relentless", "unkind", "pitiless", "vicious", "villainous", "corrupt"};
    static constexpr std::string_view nm15_2[] = {"bravery", "fighting skills", "capability", "charm", "vigor", "courage", "determination", "diligence", "eagerness", "inginuity", "wits", "cunning", "perseverance", "persistance", "skills", "powers", "talents", "wisdom", "intrepidness", "strength"};
    static constexpr std::string_view nm16_2[] = {"battle the elements", "overcome all odds", "survive everything", "go beyond expectations", "face all obstacles", "conquer all fears and doubts", "crush all that's in the way", "overpower anybody who's a hinderance", "keep ahead of the curve", "remain out of reach of danger", "train to perfection", "escape hell", "reach full potential", "start a new life", "find a new home"};
    static constexpr std::string_view nm18_2[] = {"Still plagued by the past", "While haunted by memories of the past", "Powerless to change the past", "With new found pride and some happiness", "Still affected by the past", "Having finally found some peace of mind", "Having finally found some stability", "After finally turning life around", "With a new chance at life", "With the lessons of the past", "While still constantly on the move", "With the skills learned in the past", "Having found a significant other", "Settled down and with some peace and quiet", "While constantly travelling the world"};
    static constexpr std::string_view nm19_2[] = {"on helping people", "as a mercenary for the king", "a small job with low pay", "on making it in a large tournament", "on meeting new, kind people", "buying a house", "fitting in with society", "as a travelling trader", "as a travelling gun for hire", "as a travelling help for hire", "on travelling and surviving of nature", "perfecting skills and talents", "tracking the people of the past", "as help for hire", "as a sailor"};
    static constexpr std::string_view nm20_2[] = {"find some form of redemption", "shed the memories of the past", "be released of the haunting memories", "find a place to call home", "live a normal life", "find safety and happiness", "find joy and happiness in life", "leave the past behind", "find inner peace", "find answers to the events of the past", "learn more about the past", "find vengeance for the actions in the past", "forget about the past", "start life over on a good note", "support a new, honest life"};
    static constexpr std::string_view nm21_2[] = {"peace of mind", "friends", "happiness", "joy and love for life", "stability and security", "tranquility", "joys and comforts of life", "pleasureful life", "significant other", "purpose to life"};

    ArrayView nm1; ArrayView nm10; ArrayView nm11; ArrayView nm12; ArrayView nm12b; ArrayView nm13; ArrayView nm14; ArrayView nm15; ArrayView nm16; ArrayView nm17; ArrayView nm18; ArrayView nm19; ArrayView nm2; ArrayView nm20; ArrayView nm21; ArrayView nm3; ArrayView nm5; ArrayView nm6; double gnd = 0.0; std::string names; std::string result; std::string tp; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd12b = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15a = 0; size_t rnd15b = 0; size_t rnd16 = 0; size_t rnd17 = 0; size_t rnd18 = 0; size_t rnd19 = 0; size_t rnd20 = 0; size_t rnd21 = 0; size_t rnd2a = 0; size_t rnd2b = 0; size_t rnd2c = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; int i = 0; int nm9 = 0;

    nm1 = make_view(nm1_1);
    nm2 = make_view(nm2_1);
    nm3 = make_view(nm3_1);
    nm5 = make_view(nm5_1);
    nm6 = make_view(nm6_1);
    nm9 = (rng() % 10) + 10;
    nm10 = make_view(nm10_1);
    nm11 = make_view(nm11_1);
    nm12 = make_view(nm12_1);
    nm12b = make_view(nm12b_1);
    nm13 = make_view(nm13_1);
    nm14 = make_view(nm14_1);
    nm15 = make_view(nm15_1);
    nm16 = make_view(nm16_1);
    nm17 = make_view(nm17_1);
    nm18 = make_view(nm18_1);
    nm19 = make_view(nm19_1);
    nm20 = make_view(nm20_1);
    nm21 = make_view(nm21_1);
    tp = type;
    gnd = ((double)(rng() % 10000) / 10000.0);
    if (gnd < 0.5) {
    nm1 = make_view(nm1_2);
    }
    if (tp == 2) {
    nm2 = make_view(nm2_2);
    nm3 = make_view(nm3_2);
    nm5 = make_view(nm5_2);
    nm6 = make_view(nm6_2);
    nm9 = (rng() % 13) + 4;
    nm10 = make_view(nm10_2);
    if (gnd < 0.5) {
    nm11 = make_view(nm11_2);
    } else {
    nm11 = make_view(nm11_3);
    }
    nm12 = make_view(nm12_2);
    nm12b = make_view(nm12b_2);
    nm13 = make_view(nm13_2);
    nm14 = make_view(nm14_2);
    nm15 = make_view(nm15_2);
    nm16 = make_view(nm16_2);
    nm17 = make_view(nm16);
    nm18 = make_view(nm18_2);
    nm19 = make_view(nm19_2);
    nm20 = make_view(nm20_2);
    nm21 = make_view(nm21_2);
    }
    rnd2a = rng() % std::size(nm2);
    rnd2b = rng() % std::size(nm2);
    while (rnd2a == rnd2b) {
    rnd2b = rng() % std::size(nm2);
    }
    rnd2c = rng() % std::size(nm2);
    while (rnd2c == rnd2b || rnd2c == rnd2a) {
    rnd2c = rng() % std::size(nm2);
    }
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    rnd10 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    rnd12 = rng() % std::size(nm12);
    rnd12b = rng() % std::size(nm12b);
    rnd13 = rng() % std::size(nm13);
    rnd14 = rng() % std::size(nm14);
    rnd15a = rng() % std::size(nm15);
    rnd15b = rng() % std::size(nm15);
    while (rnd15a == rnd15b) {
    rnd15b = rng() % std::size(nm15);
    }
    rnd16 = rng() % std::size(nm16);
    rnd17 = rng() % std::size(nm17);
    while (rnd16 == rnd17) {
    rnd17 = rng() % std::size(nm17);
    }
    rnd18 = rng() % std::size(nm18);
    rnd19 = rng() % std::size(nm19);
    rnd20 = rng() % std::size(nm20);
    rnd21 = rng() % std::size(nm21);
    if (tp == 2) {
    names = nm1[0] + "'s " + nm2[rnd2a] + ", " + nm2[rnd2b] + " and " + nm2[rnd2c] + ". " + nm4[rnd4] + " with " + nm1[2] + " " + nm3[rnd3] + " past.";
    names = nm1[0] + " was born and grew up in a" + nm5[rnd5] + " family in a" + nm6[rnd6] + " " + nm7[rnd7] + ", " + nm1[1] + " lived " + nm8[rnd8] + " until " + nm1[1] + " was about " + nm9 + " years old, but at that point " + nm10[rnd10] + ".";
    names = nm1[0] + " " + nm11[rnd11] + " " + nm12[rnd12] + " and was " + nm12b[rnd12b] + ". " + nm13[rnd13] + " " + nm1[1] + " had to survive in a " + nm14[rnd14] + " world. But with " + nm1[2] + " " + nm15[rnd15a] + " and " + nm15[rnd15b] + ", " + nm1[1] + " managed to " + nm16[rnd16] + " and " + nm17[rnd17] + ". This has turned " + nm1[3] + " into the " + nm1[4] + " " + nm1[1] + " is today.";
    names = nm18[rnd18] + ", " + nm1[1] + " now works " + nm19[rnd19] + ". By doing so, " + nm1[1] + " hopes to " + nm20[rnd20] + " and finally find " + nm21[rnd21] + " " + nm1[1] + " has never had.";
    } else {
    names = nm1[0] + "'s " + nm2[rnd2a] + ", " + nm2[rnd2b] + ", " + nm2[rnd2c] + " and perhaps a little too " + nm3[rnd3] + ". " + nm4[rnd4] + " with " + nm1[2] + " position.";
    names = nm1[0] + " was born in a" + nm5[rnd5] + " family in a" + nm6[rnd6] + " " + nm7[rnd7] + ". " + nm1[0] + " lived " + nm8[rnd8] + " until " + nm1[1] + " was about " + nm9 + " years old, but at that point " + nm10[rnd10] + ".";
    names = nm1[0] + " " + nm11[rnd11] + " and was " + nm12[rnd12] + ".  " + nm13[rnd13] + ", " + nm1[1] + " " + nm12b[rnd12b] + " in a " + nm14[rnd14] + " world. But with " + nm1[2] + " " + nm15[rnd15a] + " and " + nm15[rnd15b] + ", there's nothing to stop " + nm1[3] + " from " + nm16[rnd16] + ". " + nm1[0] + " could quickly become " + nm17[rnd17] + ".";
    names = nm18[rnd18] + " " + nm1[1] + " is currently " + nm19[rnd19] + ". " + nm1[0] + " feels like there's more " + nm20[rnd20] + " in this world. Luckily " + nm1[1] + " has " + nm21[rnd21] + " to support " + nm1[3] + ".";
    }
    result = "";
    for (i = 0; i < 4; i++) {
    result += names;
    result += "\n";
    result += "\n";
    }
    return result;
}
