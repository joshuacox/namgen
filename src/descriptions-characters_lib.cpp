#include "descriptions-characters_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_characters_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names1_1[] = {"Black", "Gray", "White", "Blonde", "Brown", "Red", "Ginger", "Chestnut", "Silver"};
    static constexpr std::string_view names2_1[] = {"short hair", "short spiky hair", "short bristly hair", "well groomed hair", "crinkly hair", "sleek hair", "flowing hair", "shaggy hair", "well groomed hair", "long hair", "curly hair", "straight hair", "wavy hair", "frizzy hair", "coily hair", "long hair", "curly hair", "straight hair", "wavy hair", "frizzy hair", "coily hair", "dreadlocks", "shoulder-length hair"};
    static constexpr std::string_view names3_1[] = {"hangs over", "slightly reveals", "tight in a ponytail reveals", "gently hangs over", "slightly covers", "almost fully covers", "clumsily hangs over", "awkwardly hangs over", "neatly coiffured to reveal", "is pulled back to reveal"};
    static constexpr std::string_view names4_1[] = {"thin", "chiseled", "craggy", "fine", "fresh", "full", "furrowed", "handsome", "sculpted", "weak", "strong", "long", "round", "bony", "lean", "skinny", "fat"};
    static constexpr std::string_view names5_1[] = {"time-worn", "cheerful", "friendly", "charming", "radiant", "warm", "anguished", "menacing", "lively", "tense", "wild", "gloomy", "frowning", "worried", "sad", "lived-in"};
    static constexpr std::string_view names6_1[] = {"Beady", "Big, round", "Bloodshot", "Bright", "Bulging", "Clear", "Dancing", "Darting", "Dead", "Expressive", "Gentle", "Glinting", "Glistening", "Glittering", "Heavy", "Hollow", "Hooded", "Lidded", "Narrow", "Piercing", "Round", "Shining", "Shuttered", "Small", "Smart", "Sparkling", "Squinting", "Wide", "Woeful"};
    static constexpr std::string_view names7_1[] = {"blue", "brown", "hazel", "black", "green", "amber", "gray"};
    static constexpr std::string_view names8_1[] = {"deep", "narrowly", "buried", "far", "rooted", "well", "low", "high", "sunken", "lightly", "thightly", "graciously", "concealed", "delicately", "elegantly", "handsomely", "a-symmetrically", "gracefully", "seductively", "appealingly", "charmingly", "dreadfully", "wickedly"};
    static constexpr std::string_view names9_1[] = {"wearily", "delightfully", "cheerfully", "gratefully", "heartily", "warmly", "eagerly", "delightedly", "merrily", "lovingly", "enthusiastically", "readily", "hungrily", "intently", "energetically", "impatiently", "longingly", "vigorously", "rapidly", "admiringly", "affectionately", "fondly", "thoughtfully", "devotedly", "yearningly", "loyally", "cautiously", "slowly", "carefully", "guardedly", "discreetly", "anxiously", "attentively", "meticulously", "honorably", "vigilantly", "watchfully", "delicately", "faithfully"};
    static constexpr std::string_view names10_1[] = {"village", "city", "lands", "people", "town", "families", "ships", "armies", "homes", "castle", "palace", "natives", "wildlife", "farms", "country", "haven", "mountains", "rivers", "river", "sea", "woods", "wastelands", "clan", "folk", "tribe", "ancestors", "children", "deserts", "mines", "spirits", "stronghold"};
    static constexpr std::string_view names11_1[] = {"protected", "sworn to protect", "come to love", "loved", "fought for", "bled for", "nearly died for", "looked after", "cared for", "defended", "safeguarded", "kept safe", "watched over", "stood guard for", "come to appreciate", "grown affactionate of", "become enchancted by", "worshipped", "befriended", "grieved with", "shown mercy on", "sought solace in", "felt at home at", "rarely felt at home at", "barely related to", "disassociated with", "felt disconnected from", "have been seperated from", "been seperated from", "been isolated from"};
    static constexpr std::string_view names12_1[] = {"A scar", "Scars", "A sword left a mark", "A gunshot left a mark", "Fallen debry left a mark", "Fire has left a mark", "A birthmark", "An old tattoo", "A tattoo", "Tribal marks", "Several moles", "Freckles", "Smooth skin", "Soft skin", "Fair skin", "A beard", "A large beard", "Dark stubble", "A moustache", "A goatee", "A moustache and goatee"};
    static constexpr std::string_view names13_1[] = {"stretching from just under the right eye", "stretching from just under the left eye", "stretching from just under the right eyebrow", "stretching from just under the left eyebrow", "stretching from just under the right eye", "stretching from the top of the right cheek", "stretching from the top of the left cheek", "stretching from the bottom of the right cheek", "stretching from the bottom of the left cheek", "stretching from the bottom of the right cheekbone", "stretching from the bottom of the left cheekbone", "stretching from the right side of the forehead", "stretching from the left side of the forehead", "reaching from just under the right eye", "reaching from just under the left eye", "reaching from just under the right eyebrow", "reaching from just under the left eyebrow", "reaching from just under the right eye", "reaching from the top of the right cheek", "reaching from the top of the left cheek", "reaching from the bottom of the right cheek", "reaching from the bottom of the left cheek", "reaching from the bottom of the right cheekbone", "reaching from the bottom of the left cheekbone", "reaching from the right side of the forehead", "reaching from the left side of the forehead"};
    static constexpr std::string_view names14_1[] = {", running across the nose", ", running towards the other eye", ", first running towards thin lips", ", first running towards his fairly big lips", ", running towards the right side of his lips", ", running towards the left side of his lips", ", running towards the tip of the nose", ", running towards his left nostril", ", running towards his right nostril", ", running towards his upper lip"};
    static constexpr std::string_view names15_1[] = {"and ending on his left cheek", "and ending on his left cheekbone", "and ending on his right cheek", "and ending on his right cheekbone", "and ending on his upper lip", "and ending on his chin", "and ending on his forehead", "and ending on his right nostril", "and ending on his left nostril", "and ending under his left eye", "and ending under his right eye", "and ending above his right eye", "and ending above his left eye"};
    static constexpr std::string_view names16_1[] = {"a pleasant memory", "an aching memory", "a burning memory", "a stinging memory", "a tormenting memory", "an aching burden", "a stinging burden", "a tormenting burden", "a painful burden", "a lasting punishment", "a lasting burden", "an amusing memory", "a delightful memory", "a gracious memory", "a pleasurable memory", "a bittersweet memory", "a heartbreaking memory", "an agonizing memory", "a grievous memory", "a beautiful memory", "a satisfying memory", "a fascinating memory", "a captivating memory", "an intriguing memory", "a compelling memory"};
    static constexpr std::string_view names17_1[] = {"a former life", "a great reputation", "a new life", "a reclaimed home", "an unusual alliance", "battles long forgotten", "battles past", "companionship", "deceased love", "deceased loved ones", "defended homes", "defended honor", "defended lands", "departed love", "departed loved ones", "famed glory", "forbidden adventures", "forbidden love", "former lives", "former love", "fortunate adventures", "heroic liberations", "hidden talents", "his adventurous love life", "his ex-love", "his former lover", "his fortunate destiny", "his fortunate past", "his fortunate survival", "his fortunate upbringing", "his love", "his luck in battles", "his luck in love", "his luck", "his reckless luck", "his unfortunate past", "his unfortunate upbringing", "innocence long lost", "lands long forgotten", "liberated love", "lost comrades", "lost friends", "lost honor", "lost love", "reclaimed honor", "reclaimed lands", "redeemed honor", "redeemed love", "redemption", "restored honor", "return to home", "true friendship", "unexpected friendship", "unfortunate adventures"};
    static constexpr std::string_view names18_1[] = {"Adam", "Adan", "Addison", "Brock", "Brodie", "Brody", "Brooks", "Bruce", "Bruno", "Bryan", "Bryant", "Bryce", "Brycen", "Bryson", "Byron", "Cade", "Caden", "Cael", "Caiden", "Cale", "Gunnar", "Irving", "Isaac", "Jamal", "Jamar", "Kade", "Maverick", "Max", "Orion", "Orlando"};
    static constexpr std::string_view names19_1[] = {"Adwell", "Afton", "Barnett", "Barney", "Barnfield", "Chilson", "Chilton", "Cawthorn", "Davenport", "Davey", "Dallin", "Eustice", "Eustis", "Evatt", "Falcon", "Faley", "Falkner", "Geary", "Gedman", "Gedney", "Hanshaw", "Hansley", "Hanson", "Lamkin", "Lamkins", "Lamm", "Lockridge", "Locks", "Lockwood", "Masser", "Massey", "Massingale", "Rosemond", "Shepherd", "Shepley", "Wakeley", "Wakelin"};
    static constexpr std::string_view names20_1[] = {"hero", "friend", "leader", "pioneer", "romancer", "fortune-hunter", "explorer", "daredevil", "globetrotter", "mercenary", "dreamer", "visionary", "idealist", "genius", "champion", "master", "prodigy", "spectacle", "guardian", "angel", "paladin", "warrior", "hunter", "warden", "defender", "sentinel", "victor", "winner", "challenger", "ally", "protector", "vanquisher", "vindicator", "romanticist", "stargazer", "nobleman", "utopian", "adventurer", "opportunist", "pioneer"};
    static constexpr std::string_view names21_1[] = {"humans", "humans", "humans", "humans", "elves", "night elves", "blood elves", "high elves", "wood elves", "dark elves", "gnomes", "trolls", "orcs", "goblins", "dwarves", "giants", "halflings", "vampires", "werewolves"};
    static constexpr std::string_view names22_1[] = {"tall among", "short among", "towering among", "towering above", "tall above", "big among", "high among", "small among", "average among", "ordinary among", "common among", "oddly among", "awkwardly among", "gracefully among", "graciously among", "elegantly among", "easily among", "tiny among", "seductively among", "alluringly among"};
    static constexpr std::string_view names23_1[] = {"thin", "big", "fragile", "delicate", "lean", "narrow", "skinny", "slim", "light", "subtle", "scraggy", "bulky", "heavy", "hefty", "athletic", "brawny", "sturdy", "strong", "muscled", "tough"};
    static constexpr std::string_view names24_1[] = {"alluring", "ambiguous", "appealing", "bewildering", "bizarre", "captivating", "charming", "curious", "different", "enigmatic", "enthralling", "enticing", "extraordinary", "fascinating", "incomprehensible", "inexplicable", "intriguing", "irregular", "misleading", "mystifying", "obscure", "odd", "puzzling", "seductive", "wonderful"};
    static constexpr std::string_view names25_1[] = {"a feeling of anguish", "a feeling of arogance", "a feeling of coldness", "a feeling of comfort", "a feeling of delight", "a feeling of guilt", "a feeling of hospitality", "a feeling of indifference", "a feeling of joy", "a feeling of regret", "a feeling of remorse", "a feeling of sadness", "a feeling of shame", "his attitude", "his bravery", "his clumsiness", "his company", "his composure", "his decency", "his disposition", "his fortunate past", "his friendly demeanor", "his gentleness", "his good looks", "his good will", "his goodwill", "his hatred", "his humility", "his kindness", "his odd companions", "his odd friends", "his painful past", "his patience", "his perseverance", "his persistence", "his personality", "his presence", "his reputation", "his sense of comradery", "his sense of honor", "his sense of humor", "his sense of justice", "his sensitivity", "his suffering", "his sympathy", "his tenderness", "his unfortunate past", "his unusual alliances", "his unusual looks", "his warmth"};
    static constexpr std::string_view names26_1[] = {"a feeling of anguish", "a feeling of arogance", "a feeling of coldness", "a feeling of comfort", "a feeling of delight", "a feeling of guilt", "a feeling of hospitality", "a feeling of indifference", "a feeling of joy", "a feeling of regret", "a feeling of remorse", "a feeling of sadness", "a feeling of shame", "his attitude", "his bravery", "his clumsiness", "his company", "his composure", "his decency", "his disposition", "his fortunate past", "his friendly demeanor", "his gentleness", "his good looks", "his good will", "his goodwill", "his hatred", "his humility", "his kindness", "his odd companions", "his odd friends", "his painful past", "his patience", "his perseverance", "his persistence", "his personality", "his presence", "his reputation", "his sense of comradery", "his sense of honor", "his sense of humor", "his sense of justice", "his sensitivity", "his suffering", "his sympathy", "his tenderness", "his unfortunate past", "his unusual alliances", "his unusual looks", "his warmth"};
    static constexpr std::string_view names27_1[] = {"keep their distance", "flock towards him", "worship him", "befriend him", "assist him", "follow him", "welcome him", "welcome him with open arms", "invite him into their homes", "hit it off with him", "ask him for favors", "shower him with gifts", "subtly ignore him", "pretend to be his friend", "pretend to be his best friend", "lie about knowing him to brag", "brag about knowing him", "take pride in knowing him", "take pride in knowing him as a friend", "wish to get to know him better", "become his friend", "socialize with him", "try to get him to marry their off-spring", "buy him a drink", "salute him in the streets", "stay on his good side", "thank him for his service", "ask him to tell stories", "ask him about his adventures", "ask him about his latest victory", "share local gossip with him", "be curious about him", "treat him like family"};
    static constexpr std::string_view names28_1[] = {"trying to subtlely stare", "secretly admiring him", "trying to hide from him", "trying to avoid him", "trying to please him", "secretly dispising him", "jealousy consumes them", "wishing they were more like him", "thinking of ways to become his friend", "wanting to fight along his side in battle", "hoping to one day follow in his footsteps", "secretly training to become more like him", "trying to subtly look more like him", "befriending his friends to get closer to him", "learning as much about him as possible", "commending him for his deeds", "hoping he will one day be their leader", "hoping their sons will grow up to be like him", "helping him out in any way they can", "awkwardly avoid talking about his past", "spreading rumors about him behind his back", "spreading stories about him", "making up bigger stories about him", "training with him whenever he's available", "treating him to a good meal when he's around"};
    static constexpr std::string_view names1_2[] = {"Purple", "Blue", "Green", "Red", "White", "Blonde", "Brown", "Light blue", "Light green", "Pink", "Silver", "Golden"};
    static constexpr std::string_view names2_2[] = {"perfectly groomed hair", "well groomed hair", "sleek hair", "long hair", "curly hair", "straight hair", "flowing hair", "wavy hair", "shoulder-length hair"};
    static constexpr std::string_view names4_2[] = {"thin", "chiseled", "craggy", "fine", "fresh", "full", "furrowed", "handsome", "sculpted", "strong", "long", "round", "bony", "lean"};
    static constexpr std::string_view names7_2[] = {"blue", "brown", "hazel", "green", "amber", "gray", "sapphire", "aquamarine", "pink", "red", "golden", "violet", "silver"};
    static constexpr std::string_view names10_2[] = {"village", "lands", "people", "town", "families", "ships", "armies", "homes", "castle", "palace", "natives", "wildlife", "farms", "country", "haven", "mountains", "rivers", "river", "sea", "woods", "woodlands", "ancestors", "children", "spirits"};
    static constexpr std::string_view names18_2[] = {"Wyninn", "Ninleyn", "Tinlef", "Elluin", "Elduin", "Elmon", "Almar", "Alas", "Alwin", "Almer", "Alre", "Alred", "Alen", "Alluin", "Alduin", "Almon", "Hagwin", "Hagmere"};
    static constexpr std::string_view names19_2[] = {"Moonwalker", "Dawnwing", "Dawnfury", "Moonfall", "Nightgaze", "Dawnthorn", "Stagrunner", "Wildoak", "Lunadancer", "Dawnwhisper"};
    static constexpr std::string_view names1_3[] = {"Purple", "Blue", "Green", "Red", "White", "Brown", "Light blue", "Light green", "Orange", "Silver", "Golden", "Yellow", "Black", "Blue", "Brown", "Hazel", "Black", "Green", "Amber", "Gray"};
    static constexpr std::string_view names2_3[] = {"short hair", "short hair", "short hair", "long hair", "curly hair", "straight hair", "sleek hair", "frizzy hair", "shaggy hair", "shoulder-length hair"};
    static constexpr std::string_view names4_3[] = {"thin", "fine", "fresh", "full", "handsome", "round", "bony", "lean", "skinny", "fat"};
    static constexpr std::string_view names18_3[] = {"Glinoflonk", "Bonlebick", "Bimbik", "Gnobflink", "Binflonk", "Nittlewizz", "Gimkink", "Merbibus", "Totonk", "Dinnus"};
    static constexpr std::string_view names19_3[] = {"Steambonk", "Berryspark", "Spannerwhistle", "Steamspanner", "Tosslefuse", "Draxlespanner", "Finewizzle", "Puddleblast", "Stormgauge", "Shinesprocket"};
    static constexpr std::string_view names2_4[] = {"short hair", "short hair", "short hair", "long hair", "curly hair", "straight hair", "coily hair", "shaggy hair", "greasy hair", "oily hair", "frizzy hair", "shoulder-length hair", "dreadlocks"};
    static constexpr std::string_view names4_4[] = {"thin", "chiseled", "craggy", "fine", "fresh", "full", "furrowed", "strong", "long", "round", "bony", "lean", "skinny"};
    static constexpr std::string_view names10_3[] = {"village", "city", "lands", "people", "town", "families", "ships", "armies", "homes", "stronghold", "natives", "wildlife", "farms", "country", "haven", "mountains", "rivers", "river", "sea", "clan", "folk", "tribe", "tribes", "ancestors", "children", "deserts", "mines", "spirits"};
    static constexpr std::string_view names18_4[] = {"Ekon", "Erasto", "Haijen", "Hamedi", "Hokima", "Jaafan", "Jabir", "Jalai", "Javyn", "Jijel", "Juma", "Jumoke", "Kaijin", "Kazko", "Maalik", "Makas", "Malak", "Nyabingi", "Rahjin", "Rakash", "Rashi", "Razi"};
    static constexpr std::string_view names19_4[] = {"Xueshi", "Vintish", "Zalaahoku", "Valkeiki", "Hakjel", "Hanalaji", "Zebnanji", "Tesh'Rimon", "Junbir", "Zenunjo"};
    static constexpr std::string_view names18_5[] = {"Gnarg", "Gnarlug", "Gnorl", "Gnorth", "Gnoth", "Gnurl", "Golag", "Golub", "Gomatug", "Gomoku", "Gorgu", "Gorlag", "Grikug", "Grug", "Grukag", "Grukk", "Grung", "Gruul"};
    static constexpr std::string_view names19_5[] = {"Wolfbasher", "Burningfury", "Firesong", "Goreseeker", "Hellsplitter", "Deatheye", "Burninghorn", "Gorebasher", "Wolfhammer", "Boneslayer"};
    static constexpr std::string_view names18_6[] = {"Karax", "Baxeek", "Soxart", "Rezikmez", "Fizink", "Wimax", "Jexmelyx", "Grexmex", "Tinkbelex", "Greekeels"};
    static constexpr std::string_view names19_6[] = {"Greaseblast", "Haggletooth", "Deadnozzle", "Fizfingers", "Gearnozzle", "Shadowgleam", "Copperbuttons", "Deadsprocket", "Greasebottom", "Toptwister"};
    static constexpr std::string_view names2_5[] = {"short hair", "short hair", "short hair", "long hair", "curly hair", "coily hair", "greasy hair", "shaggy hair", "oily hair", "frizzy hair", "shoulder-length hair"};
    static constexpr std::string_view names4_5[] = {"craggy", "fine", "fresh", "full", "furrowed", "strong", "long", "round", "fat"};
    static constexpr std::string_view names18_7[] = {"Bengahdar", "Banbrek", "Drumdus", "Dulgarn", "Galirg", "Kharnur", "Iromuador", "Ragorhdrom", "Urmbrek", "Theledon"};
    static constexpr std::string_view names19_7[] = {"Longmantle", "Highbeard", "Frostpike", "Boulderstone", "Bouldergem", "Frostshaper", "Bouldershout", "Blackaxe", "Goldstone", "Battlefist"};
    static constexpr std::string_view names13_2[] = {"resembling a shield", "resembling a sword", "resembling a skull", "resembling a flag", "resembling a tear", "of a small dragon", "of a small cross", "of a small star", "of a small eagle", "of a small swallow", "of a small lion", "of a small wolf", "of a small bear", "of a bear paw", "of a lion paw", "of an eagle claw", "of a talon", "of a dagger", "of a wolf paw", "of a shield", "of a sword", "of a skull", "of a flag", "of a tear", "resembling a small dragon", "resembling a small cross", "resembling a small star", "resembling a small eagle", "resembling a small swallow", "resembling a small lion", "resembling a small wolf", "resembling a small bear", "resembling a bear paw", "resembling a lion paw", "resembling an eagle claw", "resembling a talon", "resembling a dagger", "resembling a wolf paw"};
    static constexpr std::string_view names14_2[] = {"is almost hidden", "is displayed", "is subtly placed", "is prominently featured", "is proudly worn"};
    static constexpr std::string_view names15_2[] = {"on the right side of his neck", "on the left side of his neck", "just below his right eye", "just below his left eye", "on the side of his right cheekbone", "on the side of his left cheekbone", "on the side of the left eye", "on the side of his right eye", "just above the side of his left eye", "just above the side of his right eye", "just above the right side of his right eyebrow", "just above the left side of his left eyebrow"};
    static constexpr std::string_view names13_3[] = {"in the form of 2 stripes running from above the eyes to the bottom of the cheeks", "in the form of 2 stripes on each side of the face, running from just above the eyes to the bottom of the cheeks", "in the form of 1 stripe under his right eye", "in the form of 1 stripe under his left eye", "in the form of 2 stripes under his right eye", "in the form of 2 stripes under his left eye", "in the form of 1 stripe under each eye", "in the form of 1 stripe under each eye", "in the form of 2 stripes under each eye", "in the form of 2 stripes under each eye", "in the form of a stripe above and below his right eye", "in the form of a stripe above and below his left eye", "in the form of a stripe above and below both his eyes", "in the form of 1 stripe above and 2 stripes below his right eye", "in the form of 1 stripe above and 2 stripes below his left eye", "in the form of 1 stripe above and 2 stripes below both his eyes", "in the form of a diagonal line across his right eye", "in the form of a diagonal line across his left eye", "resembling a lightning bolt under his right eye", "resembling a lightning bolt under his left eye", "resembling a horizontal lightning bolt under his right eye", "resembling a horizontal lightning bolt under his left eye", "resembling two large lightning bolts on each side of his face"};
    static constexpr std::string_view names14_3[] = {"marks his heritage", "marks his ancestry", "marks his skills in combat", "marks his rank", "marks his upbringing", "marks his legacy", "marks his birthright", "marks his heirship", "marks his descent", "marks his lineage", "marks his blood relation", };
    static constexpr std::string_view names15_3[] = {"but, more importantly"};
    static constexpr std::string_view names13_4[] = {"are spread"};
    static constexpr std::string_view names14_4[] = {"charmingly", "gracefully", "beautifully", "elegantly", "seductively", "alluringly", "delightfully", "delicately", "graciously", "neatly", "oddly", "awkwardly", "grotesquely", "gracelessly", "unusually", "peculiarly"};
    static constexpr std::string_view names15_4[] = {"on his left cheek and", "on his right cheek and", "across his whole face and", "across his forehead and", "around his nose and", "on his neck and"};
    static constexpr std::string_view names16_2[] = {"a pleasant memory", "an aching memory", "a burning memory", "a stinging memory", "a tormenting memory", "a lasting burden", "an amusing memory", "a delightful memory", "a pleasurable memory", "a bittersweet memory", "a heartbreaking memory", "an agonizing memory", "a grievous memory", "a satisfying memory", "a fascinating memory", "a captivating memory", "an intriguing memory", "a compelling memory"};
    static constexpr std::string_view names17_2[] = {"his past", "his upbringing", "his fortunate upbringing", "his former lovers", "his fortunate looks", "his fortunate survival", "his luck", "his luck in battles", "his luck in love", "his fortunate destiny", "his adventurous love life", "his reckless luck", "his fortunate adventures", "his unfortunate upbringing", "his unfortunate looks", "his lack of luck in love", "his unadventurous love life", "his unfortunate adventures"};
    static constexpr std::string_view names13_5[] = {"are spread"};
    static constexpr std::string_view names14_5[] = {"charmingly", "gracefully", "beautifully", "elegantly", "gorgeously", "handsomely", "seductively", "alluringly", "delightfully", "delicately", "graciously", "neatly"};
    static constexpr std::string_view names15_5[] = {"around his cheeks and", "across his whole face and", "across his cheeks and", "across his cheeks and forehead and", "around his nose and cheekbones and"};
    static constexpr std::string_view names16_3[] = {"a pleasant memory", "an amusing memory", "a delightful memory", "a gracious memory", "a pleasurable memory", "a bittersweet memory", "a heartbreaking memory", "a beautiful memory", "a satisfying memory", "a fascinating memory", "a captivating memory", "an intriguing memory", "a compelling memory"};
    static constexpr std::string_view names17_3[] = {"his past", "his upbringing", "his fortunate upbringing", "his former lovers", "his fortunate looks", "his fortunate survival", "his luck", "his luck in battles", "his luck in love", "his fortunate destiny", "his adventurous love life", "his reckless luck", "his fortunate adventures"};
    static constexpr std::string_view names13_6[] = {"charmingly", "gracefully", "beautifully", "elegantly", "gorgeously", "handsomely", "seductively", "alluringly", "delightfully", "graciously"};
    static constexpr std::string_view names14_6[] = {"compliments his"};
    static constexpr std::string_view names15_6[] = {"eyes and", "cheekbones and", "cheeks and", "mouth and", "hair and", "nose and", "nose and mouth and", "eyes and mouth and", "eyes and cheekbones and", "eyes and hair and", "hair and cheekbones and"};
    static constexpr std::string_view names16_4[] = {"a pleasant memory", "an amusing memory", "a delightful memory", "a gracious memory", "a pleasurable memory", "a bittersweet memory", "a heartbreaking memory", "a beautiful memory", "a satisfying memory", "a fascinating memory", "a captivating memory", "an intriguing memory", "a compelling memory"};
    static constexpr std::string_view names17_4[] = {"his past", "his upbringing", "his fortunate upbringing", "his former lovers", "his fortunate looks", "his fortunate survival", "his luck", "his luck in battles", "his luck in love", "his fortunate destiny", "his adventurous love life", "his reckless luck", "his fortunate adventures"};
    static constexpr std::string_view names1_4[] = {"Black", "Gray", "White", "Blonde", "Brown", "Red", "Ginger", "Chestnut", "Silver"};
    static constexpr std::string_view names2_6[] = {"short hair", "short curly hair", "short layered hair", "well groomed hair", "crinkly hair", "sleek hair", "flowing hair", "shaggy hair", "well groomed hair", "long hair", "curly hair", "straight hair", "wavy hair", "frizzy hair", "coily hair", "short hair", "long hair", "curly hair", "straight hair", "wavy hair", "frizzy hair", "coily hair", "dreadlocks", "hip-length hair", "shoulder-length hair"};
    static constexpr std::string_view names3_2[] = {"hangs over", "slightly reveals", "braided to reveal", "double braided to reveal", "tight in a bun reveals", "tight in a ponytail reveals", "gently hangs over", "slightly covers", "almost fully covers", "clumsily hangs over", "awkwardly hangs over", "neatly coiffured to reveal", "is pulled back to reveal"};
    static constexpr std::string_view names4_6[] = {"thin", "chiseled", "craggy", "fine", "fresh", "full", "furrowed", "handsome", "sculpted", "weak", "strong", "long", "round", "bony", "lean", "skinny", "fat"};
    static constexpr std::string_view names5_2[] = {"time-worn", "cheerful", "friendly", "charming", "radiant", "warm", "anguished", "menacing", "lively", "tense", "wild", "gloomy", "frowning", "worried", "sad", "lived-in"};
    static constexpr std::string_view names6_2[] = {"Beady", "Big, round", "Bloodshot", "Bright", "Bulging", "Clear", "Dancing", "Darting", "Dead", "Expressive", "Gentle", "Glinting", "Glistening", "Glittering", "Heavy", "Hollow", "Hooded", "Lidded", "Narrow", "Piercing", "Round", "Shining", "Shuttered", "Small", "Smart", "Sparkling", "Squinting", "Wide", "Woeful"};
    static constexpr std::string_view names7_3[] = {"blue", "brown", "hazel", "black", "green", "amber", "gray"};
    static constexpr std::string_view names8_2[] = {"deep", "narrowly", "buried", "far", "rooted", "well", "low", "high", "sunken", "lightly", "thightly", "graciously", "concealed", "delicately", "elegantly", "handsomely", "a-symmetrically", "gracefully", "seductively", "appealingly", "charmingly", "dreadfully", "wickedly"};
    static constexpr std::string_view names9_2[] = {"wearily", "delightfully", "cheerfully", "gratefully", "heartily", "warmly", "eagerly", "delightedly", "merrily", "lovingly", "enthusiastically", "readily", "hungrily", "intently", "energetically", "impatiently", "longingly", "vigorously", "rapidly", "admiringly", "affectionately", "fondly", "thoughtfully", "devotedly", "yearningly", "loyally", "cautiously", "slowly", "carefully", "guardedly", "discreetly", "anxiously", "attentively", "meticulously", "honorably", "vigilantly", "watchfully", "delicately", "faithfully"};
    static constexpr std::string_view names10_4[] = {"village", "city", "lands", "people", "town", "families", "ships", "armies", "homes", "castle", "palace", "natives", "wildlife", "farms", "country", "haven", "mountains", "rivers", "river", "sea", "woods", "wastelands", "clan", "folk", "tribe", "ancestors", "children", "deserts", "mines", "spirits", "stronghold"};
    static constexpr std::string_view names11_2[] = {"protected", "sworn to protect", "come to love", "loved", "fought for", "bled for", "nearly died for", "looked after", "cared for", "defended", "safeguarded", "kept safe", "watched over", "stood guard for", "come to appreciate", "grown affactionate of", "become enchancted by", "worshipped", "befriended", "grieved with", "shown mercy on", "sought solace in", "felt at home at", "rarely felt at home at", "barely related to", "disassociated with", "felt disconnected from", "have been seperated from", "been seperated from", "been isolated from"};
    static constexpr std::string_view names12_2[] = {"A scar", "Scars", "A sword left a mark", "A gunshot left a mark", "Fallen debry left a mark", "Fire has left a mark", "A birthmark", "An old tattoo", "A tattoo", "Tribal marks", "Several moles", "Freckles", "Smooth skin", "Soft skin", "Fair skin"};
    static constexpr std::string_view names13_7[] = {"stretching from just under the right eye", "stretching from just under the left eye", "stretching from just under the right eyebrow", "stretching from just under the left eyebrow", "stretching from just under the right eye", "stretching from the top of the right cheek", "stretching from the top of the left cheek", "stretching from the bottom of the right cheek", "stretching from the bottom of the left cheek", "stretching from the bottom of the right cheekbone", "stretching from the bottom of the left cheekbone", "stretching from the right side of the forehead", "stretching from the left side of the forehead", "reaching from just under the right eye", "reaching from just under the left eye", "reaching from just under the right eyebrow", "reaching from just under the left eyebrow", "reaching from just under the right eye", "reaching from the top of the right cheek", "reaching from the top of the left cheek", "reaching from the bottom of the right cheek", "reaching from the bottom of the left cheek", "reaching from the bottom of the right cheekbone", "reaching from the bottom of the left cheekbone", "reaching from the right side of the forehead", "reaching from the left side of the forehead"};
    static constexpr std::string_view names14_7[] = {", running across the nose", ", running towards the other eye", ", first running towards thin lips", ", first running towards her fairly big lips", ", running towards the right side of her lips", ", running towards the left side of her lips", ", running towards the tip of the nose", ", running towards her left nostril", ", running towards her right nostril", ", running towards her upper lip"};
    static constexpr std::string_view names15_7[] = {"and ending on her left cheek", "and ending on her left cheekbone", "and ending on her right cheek", "and ending on her right cheekbone", "and ending on her upper lip", "and ending on her chin", "and ending on her forehead", "and ending on her right nostril", "and ending on her left nostril", "and ending under her left eye", "and ending under her right eye", "and ending above her right eye", "and ending above her left eye"};
    static constexpr std::string_view names16_5[] = {"a pleasant memory", "an aching memory", "a burning memory", "a stinging memory", "a tormenting memory", "an aching burden", "a stinging burden", "a tormenting burden", "a painful burden", "a lasting punishment", "a lasting burden", "an amusing memory", "a delightful memory", "a gracious memory", "a pleasurable memory", "a bittersweet memory", "a heartbreaking memory", "an agonizing memory", "a grievous memory", "a beautiful memory", "a satisfying memory", "a fascinating memory", "a captivating memory", "an intriguing memory", "a compelling memory"};
    static constexpr std::string_view names17_5[] = {"a former life", "a great reputation", "a new life", "a reclaimed home", "an unusual alliance", "battles long forgotten", "battles past", "companionship", "deceased love", "deceased loved ones", "defended homes", "defended honor", "defended lands", "departed love", "departed loved ones", "famed glory", "forbidden adventures", "forbidden love", "former lives", "former love", "fortunate adventures", "heroic liberations", "hidden talents", "her adventurous love life", "her ex-love", "her former lover", "her fortunate destiny", "her fortunate past", "her fortunate survival", "her fortunate upbringing", "her love", "her luck in battles", "her luck in love", "her luck", "her reckless luck", "her unfortunate past", "her unfortunate upbringing", "innocence long lost", "lands long forgotten", "liberated love", "lost comrades", "lost friends", "lost honor", "lost love", "reclaimed honor", "reclaimed lands", "redeemed honor", "redeemed love", "redemption", "restored honor", "return to home", "true friendship", "unexpected friendship", "unfortunate adventures"};
    static constexpr std::string_view names18_8[] = {"Allyson", "Allyssa", "Camille", "Camryn", "Daphne", "Elyse", "Elyssa", "Emily", "Faith", "Jayde", "Julie", "Juliet", "Kylee", "Melinda", "Melissa", "Sarina", "Sasha"};
    static constexpr std::string_view names19_8[] = {"Adwell", "Afton", "Barnett", "Barney", "Barnfield", "Chilson", "Chilton", "Cawthorn", "Davenport", "Davey", "Dallin", "Eustice", "Eustis", "Evatt", "Falcon", "Faley", "Falkner", "Geary", "Gedman", "Gedney", "Hanshaw", "Hansley", "Hanson", "Lamkin", "Lamkins", "Lamm", "Lockridge", "Locks", "Lockwood", "Masser", "Massey", "Massingale", "Rosemond", "Shepherd", "Shepley", "Wakeley", "Wakelin"};
    static constexpr std::string_view names20_2[] = {"hero", "friend", "leader", "pioneer", "romancer", "fortune-hunter", "explorer", "daredevil", "globetrotter", "mercenary", "dreamer", "visionary", "idealist", "genius", "champion", "master", "prodigy", "spectacle", "guardian", "angel", "paladin", "warrior", "hunter", "warden", "defender", "sentinel", "victor", "winner", "challenger", "ally", "protector", "vanquisher", "vindicator", "romanticist", "stargazer", "noblewoman", "utopian", "adventurer", "opportunist", "pioneer"};
    static constexpr std::string_view names21_2[] = {"humans", "humans", "humans", "humans", "elves", "night elves", "blood elves", "high elves", "wood elves", "dark elves", "gnomes", "trolls", "orcs", "goblins", "dwarves", "giants", "halflings", "vampires", "werewolves"};
    static constexpr std::string_view names22_2[] = {"tall among", "short among", "towering among", "towering above", "tall above", "big among", "high among", "small among", "average among", "ordinary among", "common among", "oddly among", "awkwardly among", "gracefully among", "graciously among", "elegantly among", "easily among", "tiny among", "seductively among", "alluringly among"};
    static constexpr std::string_view names23_2[] = {"thin", "big", "fragile", "delicate", "lean", "narrow", "skinny", "slim", "light", "subtle", "scraggy", "bulky", "heavy", "hefty", "athletic", "brawny", "sturdy", "strong", "muscled", "tough"};
    static constexpr std::string_view names24_2[] = {"alluring", "ambiguous", "appealing", "bewildering", "bizarre", "captivating", "charming", "curious", "different", "enigmatic", "enthralling", "enticing", "extraordinary", "fascinating", "incomprehensible", "inexplicable", "intriguing", "irregular", "misleading", "mystifying", "obscure", "odd", "puzzling", "seductive", "wonderful"};
    static constexpr std::string_view names25_2[] = {"a feeling of anguish", "a feeling of arogance", "a feeling of coldness", "a feeling of comfort", "a feeling of delight", "a feeling of guilt", "a feeling of hospitality", "a feeling of indifference", "a feeling of joy", "a feeling of regret", "a feeling of remorse", "a feeling of sadness", "a feeling of shame", "her attitude", "her bravery", "her clumsiness", "her company", "her composure", "her decency", "her disposition", "her fortunate past", "her friendly demeanor", "her gentleness", "her good looks", "her good will", "her goodwill", "her hatred", "her humility", "her kindness", "her odd companions", "her odd friends", "her painful past", "her patience", "her perseverance", "her persistence", "her personality", "her presence", "her reputation", "her sense of comradery", "her sense of honor", "her sense of humor", "her sense of justice", "her sensitivity", "her suffering", "her sympathy", "her tenderness", "her unfortunate past", "her unusual alliances", "her unusual looks", "her warmth"};
    static constexpr std::string_view names26_2[] = {"a feeling of anguish", "a feeling of arogance", "a feeling of coldness", "a feeling of comfort", "a feeling of delight", "a feeling of guilt", "a feeling of hospitality", "a feeling of indifference", "a feeling of joy", "a feeling of regret", "a feeling of remorse", "a feeling of sadness", "a feeling of shame", "her attitude", "her bravery", "her clumsiness", "her company", "her composure", "her decency", "her disposition", "her fortunate past", "her friendly demeanor", "her gentleness", "her good looks", "her good will", "her goodwill", "her hatred", "her humility", "her kindness", "her odd companions", "her odd friends", "her painful past", "her patience", "her perseverance", "her persistence", "her personality", "her presence", "her reputation", "her sense of comradery", "her sense of honor", "her sense of humor", "her sense of justice", "her sensitivity", "her suffering", "her sympathy", "her tenderness", "her unfortunate past", "her unusual alliances", "her unusual looks", "her warmth"};
    static constexpr std::string_view names27_2[] = {"keep their distance", "flock towards her", "worship her", "befriend her", "assist her", "follow her", "welcome her", "welcome her with open arms", "invite her into their homes", "hit it off with her", "ask her for favors", "shower her with gifts", "subtly ignore her", "pretend to be her friend", "pretend to be her best friend", "lie about knowing her to brag", "brag about knowing her", "take pride in knowing her", "take pride in knowing her as a friend", "wish to get to know her better", "become her friend", "socialize with her", "try to get her to marry their off-spring", "buy her a drink", "salute her in the streets", "stay on her good side", "thank her for her service", "ask her to tell stories", "ask her about her adventures", "ask her about her latest victory", "share local gossip with her", "be curious about her", "treat her like family", "hopelessly try to seduce her"};
    static constexpr std::string_view names28_2[] = {"trying to subtlely stare", "secretly admiring her", "trying to hide from her", "trying to avoid her", "trying to please her", "secretly dispising her", "jealousy consumes them", "wishing they were more like her", "thinking of ways to become her friend", "wanting to fight along her side in battle", "hoping to one day follow in her footsteps", "secretly training to become more like her", "trying to subtly look more like her", "befriending her friends to get closer to her", "learning as much about her as possible", "commending her for her deeds", "hoping she will one day be their leader", "hoping their sons will grow up to be like her", "helping her out in any way they can", "awkwardly avoid talking about her past", "spreading rumors about her behind her back", "spreading stories about her", "making up bigger stories about her", "training with her whenever she's available", "treating her to a good meal when she's around"};
    static constexpr std::string_view names1_5[] = {"Purple", "Blue", "Green", "Red", "White", "Blonde", "Brown", "Light blue", "Light green", "Pink", "Silver", "Golden"};
    static constexpr std::string_view names2_7[] = {"perfectly groomed hair", "well groomed hair", "long wavy hair", "long layed hair", "layered hair", "sleek hair", "long hair", "curly hair", "straight hair", "flowing hair", "wavy hair", "shoulder-length hair"};
    static constexpr std::string_view names4_7[] = {"thin", "chiseled", "craggy", "fine", "fresh", "full", "furrowed", "handsome", "sculpted", "strong", "long", "round", "bony", "lean"};
    static constexpr std::string_view names7_4[] = {"blue", "brown", "hazel", "green", "amber", "gray", "sapphire", "aquamarine", "pink", "red", "golden", "violet", "silver"};
    static constexpr std::string_view names10_5[] = {"village", "lands", "people", "town", "families", "ships", "armies", "homes", "castle", "palace", "natives", "wildlife", "farms", "country", "haven", "mountains", "rivers", "river", "sea", "woods", "woodlands", "ancestors", "children", "spirits"};
    static constexpr std::string_view names18_9[] = {"Ylsysea", "Nilerea", "Lelselea", "Lelarea", "Nafareath", "Felerai", "Sillaesa", "Leadrieth", "Yneasia", "Iyohara"};
    static constexpr std::string_view names19_9[] = {"Moonwalker", "Dawnwing", "Dawnfury", "Moonfall", "Nightgaze", "Dawnthorn", "Stagrunner", "Wildoak", "Lunadancer", "Dawnwhisper"};
    static constexpr std::string_view names1_6[] = {"Purple", "Blue", "Green", "Red", "White", "Brown", "Light blue", "Light green", "Orange", "Silver", "Golden", "Yellow", "Black", "Blue", "Brown", "Hazel", "Black", "Green", "Amber", "Gray"};
    static constexpr std::string_view names2_8[] = {"short hair", "short hair", "short hair", "long hair", "curly hair", "straight hair", "sleek hair", "frizzy hair", "shaggy hair", "shoulder-length hair"};
    static constexpr std::string_view names4_8[] = {"thin", "fine", "fresh", "full", "handsome", "round", "bony", "lean", "skinny", "fat"};
    static constexpr std::string_view names18_10[] = {"Glinkeefonk", "Binfink", "Tolikink", "Katbrick", "Tiltinkle", "Tinkeeflonk", "Bonfinkle", "Tyntinkle", "Mittlefink", "Talmink"};
    static constexpr std::string_view names19_10[] = {"Steambonk", "Berryspark", "Spannerwhistle", "Steamspanner", "Tosslefuse", "Draxlespanner", "Finewizzle", "Puddleblast", "Stormgauge", "Shinesprocket"};
    static constexpr std::string_view names2_9[] = {"short hair", "short hair", "short hair", "long hair", "curly hair", "straight hair", "coily hair", "shaggy hair", "greasy hair", "oily hair", "frizzy hair", "shoulder-length hair", "dreadlocks"};
    static constexpr std::string_view names4_9[] = {"thin", "chiseled", "craggy", "fine", "fresh", "full", "furrowed", "strong", "long", "round", "bony", "lean", "skinny"};
    static constexpr std::string_view names10_6[] = {"village", "city", "lands", "people", "town", "families", "ships", "armies", "homes", "stronghold", "natives", "wildlife", "farms", "country", "haven", "mountains", "rivers", "river", "sea", "clan", "folk", "tribe", "tribes", "ancestors", "children", "deserts", "mines", "spirits"};
    static constexpr std::string_view names18_11[] = {"Gir'Enji", "Yahuja", "Feyini", "Ziruja", "Zeyra", "Zuladur", "Zujula", "Sonayo", "Vulino", "Yaonji"};
    static constexpr std::string_view names19_11[] = {"Xueshi", "Vintish", "Zalaahoku", "Valkeiki", "Hakjel", "Hanalaji", "Zebnanji", "Tesh'Rimon", "Junbir", "Zenunjo"};
    static constexpr std::string_view names18_12[] = {"Umoda", "Zonkaja", "Goredo", "Umakuma", "Groanu", "Zunala", "Gredula", "Sheeda", "Greras", "Elgudo"};
    static constexpr std::string_view names19_12[] = {"Wolfbasher", "Burningfury", "Firesong", "Goreseeker", "Hellsplitter", "Deatheye", "Burninghorn", "Gorebasher", "Wolfhammer", "Boneslayer"};
    static constexpr std::string_view names18_13[] = {"Amizenee", "Nexlee", "Pybilope", "Nalleex", "Glelee", "Glyxi", "Linxie", "Minzi", "Glebizee", "Fluxinky"};
    static constexpr std::string_view names19_13[] = {"Greaseblast", "Haggletooth", "Deadnozzle", "Fizfingers", "Gearnozzle", "Shadowgleam", "Copperbuttons", "Deadsprocket", "Greasebottom", "Toptwister"};
    static constexpr std::string_view names2_10[] = {"short hair", "short hair", "short hair", "long hair", "curly hair", "coily hair", "greasy hair", "shaggy hair", "oily hair", "frizzy hair", "shoulder-length hair"};
    static constexpr std::string_view names4_10[] = {"craggy", "fine", "fresh", "full", "furrowed", "strong", "long", "round", "fat"};
    static constexpr std::string_view names18_14[] = {"Belianyss", "Daerahniss", "Dearirwyn", "Brenunwyn", "Gwenirnys", "Bretianura", "Einormyl", "Breteodiel", "Bellores", "Brylilen"};
    static constexpr std::string_view names19_14[] = {"Longmantle", "Highbeard", "Frostpike", "Boulderstone", "Bouldergem", "Frostshaper", "Bouldershout", "Blackaxe", "Goldstone", "Battlefist"};
    static constexpr std::string_view names13_8[] = {"resembling a rose", "resembling a petal", "of a heart", "resembling a shield", "resembling a sword", "resembling a skull", "resembling a flag", "resembling a tear", "of a small dragon", "of a small cross", "of a small star", "of a small eagle", "of a small swallow", "of a small lion", "of a small wolf", "of a small bear", "of a bear paw", "of a lion paw", "of an eagle claw", "of a talon", "of a dagger", "of a wolf paw", "of a shield", "of a sword", "of a skull", "of a flag", "of a tear", "resembling a small dragon", "resembling a small cross", "resembling a small star", "resembling a small eagle", "resembling a small swallow", "resembling a small lion", "resembling a small wolf", "resembling a small bear", "resembling a bear paw", "resembling a lion paw", "resembling an eagle claw", "resembling a talon", "resembling a dagger", "resembling a wolf paw"};
    static constexpr std::string_view names14_8[] = {"is almost hidden", "is displayed", "is subtly placed", "is prominently featured", "is proudly worn"};
    static constexpr std::string_view names15_8[] = {"on the right side of her neck", "on the left side of her neck", "just below her right eye", "just below her left eye", "on the side of her right cheekbone", "on the side of her left cheekbone", "on the side of the left eye", "on the side of her right eye", "just above the side of her left eye", "just above the side of her right eye", "just above the right side of her right eyebrow", "just above the left side of her left eyebrow"};
    static constexpr std::string_view names13_9[] = {"in the form of 2 stripes running from above the eyes to the bottom of the cheeks", "in the form of 2 stripes on each side of the face, running from just above the eyes to the bottom of the cheeks", "in the form of 1 stripe under her right eye", "in the form of 1 stripe under her left eye", "in the form of 2 stripes under her right eye", "in the form of 2 stripes under her left eye", "in the form of 1 stripe under each eye", "in the form of 1 stripe under each eye", "in the form of 2 stripes under each eye", "in the form of 2 stripes under each eye", "in the form of a stripe above and below her right eye", "in the form of a stripe above and below her left eye", "in the form of a stripe above and below both her eyes", "in the form of 1 stripe above and 2 stripes below her right eye", "in the form of 1 stripe above and 2 stripes below her left eye", "in the form of 1 stripe above and 2 stripes below both her eyes", "in the form of a diagonal line across her right eye", "in the form of a diagonal line across her left eye", "resembling a lightning bolt under her right eye", "resembling a lightning bolt under her left eye", "resembling a horizontal lightning bolt under her right eye", "resembling a horizontal lightning bolt under her left eye", "resembling two large lightning bolts on each side of her face"};
    static constexpr std::string_view names14_9[] = {"marks her heritage", "marks her ancestry", "marks her skills in combat", "marks her rank", "marks her upbringing", "marks her legacy", "marks her birthright", "marks her heirship", "marks her descent", "marks her lineage", "marks her blood relation", };
    static constexpr std::string_view names15_9[] = {"but, more importantly"};
    static constexpr std::string_view names13_10[] = {"are spread"};
    static constexpr std::string_view names14_10[] = {"charmingly", "gracefully", "beautifully", "elegantly", "seductively", "alluringly", "delightfully", "delicately", "graciously", "neatly", "oddly", "awkwardly", "grotesquely", "gracelessly", "unusually", "peculiarly"};
    static constexpr std::string_view names15_10[] = {"on her left cheek and", "on her right cheek and", "across her whole face and", "across her forehead and", "around her nose and", "on her neck and"};
    static constexpr std::string_view names16_6[] = {"a pleasant memory", "an aching memory", "a burning memory", "a stinging memory", "a tormenting memory", "a lasting burden", "an amusing memory", "a delightful memory", "a pleasurable memory", "a bittersweet memory", "a heartbreaking memory", "an agonizing memory", "a grievous memory", "a satisfying memory", "a fascinating memory", "a captivating memory", "an intriguing memory", "a compelling memory"};
    static constexpr std::string_view names17_6[] = {"her past", "her upbringing", "her fortunate upbringing", "her former lovers", "her fortunate looks", "her fortunate survival", "her luck", "her luck in battles", "her luck in love", "her fortunate destiny", "her adventurous love life", "her reckless luck", "her fortunate adventures", "her unfortunate upbringing", "her unfortunate looks", "her lack of luck in love", "her unadventurous love life", "her unfortunate adventures"};
    static constexpr std::string_view names13_11[] = {"are spread"};
    static constexpr std::string_view names14_11[] = {"charmingly", "gracefully", "beautifully", "elegantly", "gorgeously", "handsomely", "seductively", "alluringly", "delightfully", "delicately", "graciously", "neatly"};
    static constexpr std::string_view names15_11[] = {"around her cheeks and", "across her whole face and", "across her cheeks and", "across her cheeks and forehead and", "around her nose and cheekbones and"};
    static constexpr std::string_view names16_7[] = {"a pleasant memory", "an amusing memory", "a delightful memory", "a gracious memory", "a pleasurable memory", "a bittersweet memory", "a heartbreaking memory", "a beautiful memory", "a satisfying memory", "a fascinating memory", "a captivating memory", "an intriguing memory", "a compelling memory"};
    static constexpr std::string_view names17_7[] = {"her past", "her upbringing", "her fortunate upbringing", "her former lovers", "her fortunate looks", "her fortunate survival", "her luck", "her luck in battles", "her luck in love", "her fortunate destiny", "her adventurous love life", "her reckless luck", "her fortunate adventures"};
    static constexpr std::string_view names13_12[] = {"charmingly", "gracefully", "beautifully", "elegantly", "gorgeously", "handsomely", "seductively", "alluringly", "delightfully", "graciously"};
    static constexpr std::string_view names14_12[] = {"compliments her"};
    static constexpr std::string_view names15_12[] = {"eyes and", "cheekbones and", "cheeks and", "mouth and", "hair and", "nose and", "nose and mouth and", "eyes and mouth and", "eyes and cheekbones and", "eyes and hair and", "hair and cheekbones and"};
    static constexpr std::string_view names16_8[] = {"a pleasant memory", "an amusing memory", "a delightful memory", "a gracious memory", "a pleasurable memory", "a bittersweet memory", "a heartbreaking memory", "a beautiful memory", "a satisfying memory", "a fascinating memory", "a captivating memory", "an intriguing memory", "a compelling memory"};
    static constexpr std::string_view names17_8[] = {"her past", "her upbringing", "her fortunate upbringing", "her former lovers", "her fortunate looks", "her fortunate survival", "her luck", "her luck in battles", "her luck in love", "her fortunate destiny", "her adventurous love life", "her reckless luck", "her fortunate adventures"};

    ArrayView names1; ArrayView names10; ArrayView names11; ArrayView names12; ArrayView names13; ArrayView names14; ArrayView names15; ArrayView names16; ArrayView names17; ArrayView names18; ArrayView names19; ArrayView names2; ArrayView names20; ArrayView names21; ArrayView names22; ArrayView names23; ArrayView names24; ArrayView names25; ArrayView names26; ArrayView names27; ArrayView names28; ArrayView names3; ArrayView names4; ArrayView names5; ArrayView names6; ArrayView names7; ArrayView names8; ArrayView names9; std::string name; std::string name2; std::string name3; std::string name4; std::string result; size_t random1 = 0; size_t random10 = 0; size_t random11 = 0; size_t random12 = 0; size_t random13 = 0; size_t random14 = 0; size_t random15 = 0; size_t random16 = 0; size_t random17 = 0; size_t random18 = 0; size_t random19 = 0; size_t random2 = 0; size_t random20 = 0; size_t random21 = 0; size_t random22 = 0; size_t random23 = 0; size_t random24 = 0; size_t random25 = 0; size_t random26 = 0; size_t random27 = 0; size_t random28 = 0; size_t random3 = 0; size_t random4 = 0; size_t random5 = 0; size_t random6 = 0; size_t random7 = 0; size_t random8 = 0; size_t random9 = 0; int i = 0;

    auto generator_charactersMale = [&]() -> std::string {
    names1 = make_view(names1_1);
    names2 = make_view(names2_1);
    names3 = make_view(names3_1);
    names4 = make_view(names4_1);
    names5 = make_view(names5_1);
    names6 = make_view(names6_1);
    names7 = make_view(names7_1);
    names8 = make_view(names8_1);
    names9 = make_view(names9_1);
    names10 = make_view(names10_1);
    names11 = make_view(names11_1);
    names12 = make_view(names12_1);
    names13 = make_view(names13_1);
    names14 = make_view(names14_1);
    names15 = make_view(names15_1);
    names16 = make_view(names16_1);
    names17 = make_view(names17_1);
    names18 = make_view(names18_1);
    names19 = make_view(names19_1);
    names20 = make_view(names20_1);
    names21 = make_view(names21_1);
    names22 = make_view(names22_1);
    names23 = make_view(names23_1);
    names24 = make_view(names24_1);
    names25 = make_view(names25_1);
    names26 = make_view(names26_1);
    names27 = make_view(names27_1);
    names28 = make_view(names28_1);
    random21 = rng() % std::size(names21);
    if (random21 > 3 && random21 < 9) {
    names1 = make_view(names1_2);
    names2 = make_view(names2_2);
    names4 = make_view(names4_2);
    names7 = make_view(names7_2);
    names10 = make_view(names10_2);
    names18 = make_view(names18_2);
    names19 = make_view(names19_2);
    } else if (random21 == 10) {
    names1 = make_view(names1_3);
    names2 = make_view(names2_3);
    names4 = make_view(names4_3);
    names18 = make_view(names18_3);
    names19 = make_view(names19_3);
    } else if (random21 >= 11 || random21 < 14) {
    names2 = make_view(names2_4);
    names4 = make_view(names4_4);
    names10 = make_view(names10_3);
    if (random21 == 11) {
    names18 = make_view(names18_4);
    names19 = make_view(names19_4);
    } else if (random21 == 12) {
    names18 = make_view(names18_5);
    names19 = make_view(names19_5);
    } else if (random21 == 13) {
    names18 = make_view(names18_6);
    names19 = make_view(names19_6);
    }
    } else if (random21 >= 14 || random21 <= 16) {
    names2 = make_view(names2_5);
    names4 = make_view(names4_5);
    if (random21 == 14) {
    names18 = make_view(names18_7);
    names19 = make_view(names19_7);
    }
    }
    random1 = rng() % std::size(names1);
    random2 = rng() % std::size(names2);
    random3 = rng() % std::size(names3);
    random4 = rng() % std::size(names4);
    random5 = rng() % std::size(names5);
    random6 = rng() % std::size(names6);
    random7 = rng() % std::size(names7);
    random8 = rng() % std::size(names8);
    random9 = rng() % std::size(names9);
    random10 = rng() % std::size(names10);
    random11 = rng() % std::size(names11);
    random12 = rng() % std::size(names12);
    if (random12 > 6 && random12 < 9) {
    names13 = make_view(names13_2);
    names14 = make_view(names14_2);
    names15 = make_view(names15_2);
    } else if (random12 == 9) {
    names13 = make_view(names13_3);
    names14 = make_view(names14_3);
    names15 = make_view(names15_3);
    } else if (random12 == 10) {
    names13 = make_view(names13_4);
    names14 = make_view(names14_4);
    names15 = make_view(names15_4);
    names16 = make_view(names16_2);
    names17 = make_view(names17_2);
    } else if (random12 == 11) {
    names13 = make_view(names13_5);
    names14 = make_view(names14_5);
    names15 = make_view(names15_5);
    names16 = make_view(names16_3);
    names17 = make_view(names17_3);
    } else if (random12 > 11) {
    names13 = make_view(names13_6);
    names14 = make_view(names14_6);
    names15 = make_view(names15_6);
    names16 = make_view(names16_4);
    names17 = make_view(names17_4);
    }
    random13 = rng() % std::size(names13);
    random14 = rng() % std::size(names14);
    random15 = rng() % std::size(names15);
    random16 = rng() % std::size(names16);
    random17 = rng() % std::size(names17);
    random18 = rng() % std::size(names18);
    random19 = rng() % std::size(names19);
    random20 = rng() % std::size(names20);
    random22 = rng() % std::size(names22);
    random23 = rng() % std::size(names23);
    random24 = rng() % std::size(names24);
    random25 = rng() % std::size(names25);
    random26 = rng() % std::size(names26);
    while (random26 == random25) {
    random26 = rng() % std::size(names26);
    }
    random27 = rng() % std::size(names27);
    random28 = rng() % std::size(names28);
    name = names1[random1] + ", " + names2[random2] + " " + names3[random3] + " a " + names4[random4] + ", " + names5[random5] + " face. " + names6[random6] + " " + names7[random7] + " eyes, set " + names8[random8] + " within their sockets, watch " + names9[random9] + " over the " + names10[random10] + " they've " + names11[random11] + " for so long.";
    name2 = names12[random12] + " " + names13[random13] + " " + names14[random14] + " " + names15[random15] + " leaves " + names16[random16] + " of " + names17[random17] + ".";
    name3 = "The is the face of " + names18[random18] + " " + names19[random19] + ", a true " + names20[random20] + " among " + names21[random21] + ". He stands " + names22[random22] + " others, despite his " + names23[random23] + " frame.";
    name4 = "There's something " + names24[random24] + " about him, perhaps it's " + names25[random25] + " or perhaps it's simply " + names26[random26] + ". But nonetheless, people tend to " + names27[random27] + ", while " + names28[random28] + ".";
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
    };
    auto generator_charactersFemale = [&]() -> std::string {
    names1 = make_view(names1_4);
    names2 = make_view(names2_6);
    names3 = make_view(names3_2);
    names4 = make_view(names4_6);
    names5 = make_view(names5_2);
    names6 = make_view(names6_2);
    names7 = make_view(names7_3);
    names8 = make_view(names8_2);
    names9 = make_view(names9_2);
    names10 = make_view(names10_4);
    names11 = make_view(names11_2);
    names12 = make_view(names12_2);
    names13 = make_view(names13_7);
    names14 = make_view(names14_7);
    names15 = make_view(names15_7);
    names16 = make_view(names16_5);
    names17 = make_view(names17_5);
    names18 = make_view(names18_8);
    names19 = make_view(names19_8);
    names20 = make_view(names20_2);
    names21 = make_view(names21_2);
    names22 = make_view(names22_2);
    names23 = make_view(names23_2);
    names24 = make_view(names24_2);
    names25 = make_view(names25_2);
    names26 = make_view(names26_2);
    names27 = make_view(names27_2);
    names28 = make_view(names28_2);
    random21 = rng() % std::size(names21);
    if (random21 > 3 && random21 < 10) {
    names1 = make_view(names1_5);
    names2 = make_view(names2_7);
    names4 = make_view(names4_7);
    names7 = make_view(names7_4);
    names10 = make_view(names10_5);
    names18 = make_view(names18_9);
    names19 = make_view(names19_9);
    } else if (random21 == 10) {
    names1 = make_view(names1_6);
    names2 = make_view(names2_8);
    names4 = make_view(names4_8);
    names18 = make_view(names18_10);
    names19 = make_view(names19_10);
    } else if (random21 >= 11 || random21 < 14) {
    names2 = make_view(names2_9);
    names4 = make_view(names4_9);
    names10 = make_view(names10_6);
    if (random21 == 11) {
    names18 = make_view(names18_11);
    names19 = make_view(names19_11);
    } else if (random21 == 12) {
    names18 = make_view(names18_12);
    names19 = make_view(names19_12);
    } else if (random21 == 13) {
    names18 = make_view(names18_13);
    names19 = make_view(names19_13);
    }
    } else if (random21 >= 14 || random21 <= 16) {
    names2 = make_view(names2_10);
    names4 = make_view(names4_10);
    if (random21 == 14) {
    names18 = make_view(names18_14);
    names19 = make_view(names19_14);
    }
    }
    random1 = rng() % std::size(names1);
    random2 = rng() % std::size(names2);
    random3 = rng() % std::size(names3);
    random4 = rng() % std::size(names4);
    random5 = rng() % std::size(names5);
    random6 = rng() % std::size(names6);
    random7 = rng() % std::size(names7);
    random8 = rng() % std::size(names8);
    random9 = rng() % std::size(names9);
    random10 = rng() % std::size(names10);
    random11 = rng() % std::size(names11);
    random12 = rng() % std::size(names12);
    if (random12 > 6 && random12 < 9) {
    names13 = make_view(names13_8);
    names14 = make_view(names14_8);
    names15 = make_view(names15_8);
    } else if (random12 == 9) {
    names13 = make_view(names13_9);
    names14 = make_view(names14_9);
    names15 = make_view(names15_9);
    } else if (random12 == 10) {
    names13 = make_view(names13_10);
    names14 = make_view(names14_10);
    names15 = make_view(names15_10);
    names16 = make_view(names16_6);
    names17 = make_view(names17_6);
    } else if (random12 == 11) {
    names13 = make_view(names13_11);
    names14 = make_view(names14_11);
    names15 = make_view(names15_11);
    names16 = make_view(names16_7);
    names17 = make_view(names17_7);
    } else if (random12 > 11) {
    names13 = make_view(names13_12);
    names14 = make_view(names14_12);
    names15 = make_view(names15_12);
    names16 = make_view(names16_8);
    names17 = make_view(names17_8);
    }
    random13 = rng() % std::size(names13);
    random14 = rng() % std::size(names14);
    random15 = rng() % std::size(names15);
    random16 = rng() % std::size(names16);
    random17 = rng() % std::size(names17);
    random18 = rng() % std::size(names18);
    random19 = rng() % std::size(names19);
    random20 = rng() % std::size(names20);
    random22 = rng() % std::size(names22);
    random23 = rng() % std::size(names23);
    random24 = rng() % std::size(names24);
    random25 = rng() % std::size(names25);
    random26 = rng() % std::size(names26);
    while (random26 == random25) {
    random26 = rng() % std::size(names26);
    }
    random27 = rng() % std::size(names27);
    random28 = rng() % std::size(names28);
    name = names1[random1] + ", " + names2[random2] + " " + names3[random3] + " a " + names4[random4] + ", " + names5[random5] + " face. " + names6[random6] + " " + names7[random7] + " eyes, set " + names8[random8] + " within their sockets, watch " + names9[random9] + " over the " + names10[random10] + " they've " + names11[random11] + " for so long.";
    name2 = names12[random12] + " " + names13[random13] + " " + names14[random14] + " " + names15[random15] + " leaves " + names16[random16] + " of " + names17[random17] + ".";
    name3 = "The is the face of " + names18[random18] + " " + names19[random19] + ", a true " + names20[random20] + " among " + names21[random21] + ". She stands " + names22[random22] + " others, despite her " + names23[random23] + " frame.";
    name4 = "There's something " + names24[random24] + " about her, perhaps it's " + names25[random25] + " or perhaps it's simply " + names26[random26] + ". But nonetheless, people tend to " + names27[random27] + ", while " + names28[random28] + ".";
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
    };

    return type == 1 ? generator_charactersFemale() : generator_charactersMale();
}

