#include "fantasy-christmas_elfs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_christmas_elfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Alabaster", "Angel", "Berry", "Bing", "Bling", "Blitz", "Blue", "Bluebell", "Brandysnap", "Brownie", "Buddy", "Bushy", "Buster", "Butters", "Button", "Buttons", "Candycane", "Cedar", "Chestnut", "Choco", "Cinnamon", "Coco", "Cocoa", "Cookie", "Dash", "Elm", "Evergreen", "Fig", "Figgy", "Fir", "Fizzy", "Flake", "Fluffy", "Frost", "Frosty", "Fruity", "Fudge", "Fuzzle", "Garland", "Ginger", "Gingernuts", "Gingersnap", "Glitter", "Glory", "Hazelnut", "Ice", "Jangle", "Jingle", "Jolly", "Marzipan", "Merry", "Mince", "Mint", "Mistle", "Mistletoe", "Noel", "Nutmeg", "Pepper", "Peppetmint", "Perky", "Pine", "Pinecone", "Pudding", "Rusty", "Shimmer", "Skittle", "Snappy", "Snow", "Snowball", "Snowdrop", "Snowflake", "Sparkle", "Sprinkle", "Sprinkles", "Starlight", "Stripes", "Sugar", "Sugarplum", "Tinkles", "Tinsel", "Tiny", "Topper", "Trinket", "Twinkle", "Twinkletoes", "Wink", "Winter", "Yule"};
    static constexpr std::string_view nm2[] = {"Angel", "Berry", "Bing", "Bling", "Blitz", "Blue", "Bluebell", "Brownie", "Button", "Buttons", "Candycane", "Choco", "Cinnamon", "Coco", "Cocoa", "Cookie", "Dash", "Fig", "Figgy", "Fizzy", "Flake", "Fluffy", "Fruity", "Fudge", "Fuzzle", "Garland", "Ginger", "Gingernuts", "Gingersnap", "Glitter", "Glory", "Ice", "Jangle", "Jingle", "Jolly", "Merry", "Mince", "Mint", "Mistle", "Mistletoe", "Nutmeg", "Pepper", "Peppetmint", "Perky", "Pine", "Pudding", "Skittle", "Snappy", "Snow", "Snowball", "Snowdrop", "Snowflake", "Sparkle", "Sprinkle", "Sprinkles", "Starlight", "Stripes", "Sugar", "Sugarplum", "Tinkles", "Tinsel", "Tiny", "Topper", "Trinket", "Twinkle", "Twinkletoes", "Wink", "Winter", "Yule"};
    static constexpr std::string_view nm3[] = {"Angel", "Belle", "Berry", "Bing", "Bling", "Blitz", "Blue", "Bluebell", "Brandy", "Brownie", "Bubbles", "Button", "Buttons", "Candy", "Candycane", "Carol", "Cherry", "Choco", "Cinnamon", "Clove", "Coco", "Cocoa", "Cookie", "Cupcake", "Dandy", "Dash", "Ember", "Emerald", "Eve", "Evie", "Faith", "Fig", "Figgy", "Fizzy", "Flake", "Fluffy", "Fruity", "Fudge", "Fuzzle", "Garland", "Ginger", "Gingernuts", "Gingersnap", "Glitter", "Gloria", "Glory", "Hazel", "Holly", "Honey", "Honeycomb", "Hope", "Ice", "Ivy", "Jangle", "Jewel", "Jingle", "Jolly", "Joy", "Juniper", "Merry", "Mince", "Mint", "Mistle", "Mistletoe", "Noelle", "Nutmeg", "Pepper", "Peppetmint", "Perky", "Pine", "Pudding", "Ruby", "Scarlet", "Skittle", "Snappy", "Snow", "Snowball", "Snowdrop", "Snowflake", "Sparkle", "Sprinkle", "Sprinkles", "Starlight", "Stripes", "Sugar", "Sugarplum", "Tinkles", "Tinsel", "Tiny", "Topper", "Trinket", "Trixie", "Twinkle", "Twinkletoes", "Wink", "Winter", "Yule"};
    static constexpr std::string_view nm4[] = {"Angel", "Bustle", "Busy", "Candle", "Candy", "Carol", "Chill", "Chilly", "Chimney", "Chocolate", "Cider", "Cookie", "Crackle", "Cuddle", "Dream", "Ever", "Fire", "Flippy", "Frost", "Frosty", "Fruit", "Gift", "Good", "Goody", "Grotto", "Happy", "Holi", "Holly", "Hot", "Hustle", "Ivy", "Jiggle", "Jingle", "Jolly", "Magic", "Milk", "Milky", "Miracle", "Mistle", "Mitten", "Morning", "Muffin", "Nibble", "Night", "Nippy", "Party", "Pickle", "Plum", "Poem", "Pudding", "Rhyme", "Ribbon", "Sleepy", "Snow", "Sparkle", "Sugar", "Sweet", "Toffee", "Twinkle", "Wiggle"};
    static constexpr std::string_view nm5[] = {"ball", "beard", "bell", "bow", "box", "cake", "cane", "card", "carol", "cheer", "dance", "dancer", "dash", "feast", "flake", "foot", "friend", "frost", "fun", "game", "gift", "glitter", "glove", "guest", "hat", "hope", "hug", "icicle", "ivy", "joke", "joy", "jump", "kiss", "laugh", "light", "love", "milk", "mitten", "moon", "myrrh", "night", "pie", "plum", "scarf", "sledge", "sleigh", "song", "spirit", "star", "toy", "tree", "warmth", "wine", "wish", "wrap"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    names = nm3[rnd] + " " + nm4[rnd2] + nm5[rnd3];
    } else if (type == 2) {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    names = nm2[rnd] + " " + nm4[rnd2] + nm5[rnd3];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    names = nm1[rnd] + " " + nm4[rnd2] + nm5[rnd3];
    }
    return names;
    }
}
