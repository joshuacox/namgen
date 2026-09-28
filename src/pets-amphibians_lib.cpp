#include "pets-amphibians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pets_amphibians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Alien", "Arrow", "Bazoo", "Beaker", "Belch", "Belcher", "Binky", "Bloats", "Blob", "Bob", "Bog", "Bogs", "Booger", "Boogy", "Bubba", "Bubbles", "Buffle", "Buffles", "Bully", "Buster", "Charizard", "Charmander", "Chubber", "Chubbles", "Chubbs", "Chubby", "Chunky", "Claw", "Clawde", "Clawdius", "Claws", "Cozmo", "Cricket", "Croak", "Croaker", "Croaks", "Crook", "Cruncher", "Crunchy", "Curmet", "Dart", "Darts", "Doc", "Fatty", "Fiddles", "Fire", "Flibbit", "Flippy", "Flips", "Flubber", "Flubs", "Flye", "Freak", "Freckles", "Frogger", "Froggie", "Frogzilla", "Gobbles", "Goble", "Gobles", "Godzilla", "Golem", "Goliath", "Gooey", "Grog", "Hobbit", "Hopkins", "Hopper", "Hopscotch", "Hudini", "Jabba", "JarJar", "Kermi", "Kermie", "Kermit", "Leaps", "Leapy", "Mantis", "Marsh", "Mello", "Mellow", "Mog", "MrSticky", "Mud", "Muds", "Newt", "Newton", "Orbit", "Patches", "Pickle", "Pickles", "Pogo", "Predator", "Prince", "Puddles", "Pudge", "Pug", "Quibbit", "Ribbit", "Shmoo", "Shmooch", "Skippy", "Skittles", "Slick", "Slimes", "Slippy", "Slub", "Slug", "Slugg", "Sluggs", "Slugs", "Smeagol", "Smudge", "Spot", "Sticky", "Stinky", "Stubby", "Stumper", "Swampie", "Swamps", "Thor", "Toad", "Weirdo", "Whopper", "Wiggles", "Wobble", "Wobbles", "Yoda"};
    static constexpr std::string_view nm2[] = {"Algee", "Amazone", "Amazonia", "Babe", "Belchy", "Blinks", "Blinky", "Bloats", "Bubble", "Bubbles", "Buffy", "Bufonia", "Cherry", "Chops", "Chubbles", "Chubby", "Clawdia", "Cookie", "Cosmo", "Cricket", "Croaks", "Daphne", "Dirty", "Faye", "Fern", "Fiddle", "Flubby", "Flye", "Freakey", "Freckles", "Frogzilla", "Fye", "Fyre", "Geo", "Gobbles", "Gooey", "Hippity", "Hipscotch", "Hoppity", "Iggy", "Karma", "Kirby", "Kiss", "Kisses", "Leaps", "Leapy", "Lilo", "Lily", "Lilypad", "Lips", "Mello", "Muddy", "Muds", "Mystique", "Noodles", "Patches", "Peeps", "Penelope", "Pepper", "Pickle", "Pickles", "Princess", "Puds", "Pugs", "Pumpkin", "Raisin", "Ribbit", "Ribbits", "Sally", "Shirly", "Shmoo", "Shmooches", "Slimey", "Slippy", "Smiley", "Smooch", "Snaile", "Sparkle", "Sparkles", "Speckles", "Spot", "Spots", "Squee", "Squiggy", "Stitch", "Stitches", "Teeny", "Tiggles", "Tiny", "Tootsie", "Trixie", "Twiggy", "Twinkle", "Waddle", "Waddles", "Wiggle", "Wiggles", "Wobble", "Wobbles", "Xena"};

    std::string names; size_t rnd = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm2);
    names = nm2[rnd];
    } else {
    rnd = rng() % std::size(nm1);
    names = nm1[rnd];
    }
    return names;
    }
}
