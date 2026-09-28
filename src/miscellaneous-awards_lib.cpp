#include "miscellaneous-awards_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_awards_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "Acclaimed", "Adept", "Arcane", "Artistic", "Aurora", "Austere", "Bold", "Brass", "Bravery", "Bright", "Brilliant", "Candid", "Children's", "Clever", "Comfort", "Complexity", "Confusion", "Convention", "Crafty", "Creation", "Creative", "Critic", "Critics'", "Crystal", "Dapper", "Defiant", "Diamond", "Discovery", "Discretion", "Dual", "Duality", "Earnesty", "Education", "Elegance", "Elegant", "Elementary", "Enchanted", "Enlightened", "Ethic", "Exalted", "Excellence", "Experience", "Expert", "Expertise", "Fantasy", "Fashion", "Flawless", "Fragrant", "Free", "Future", "Gentle", "Golden", "Graceful", "Gracious", "Grand", "Guardian", "Handy", "Harmony", "Health", "Healthy", "Honest", "Honesty", "Honor", "Honored", "Humane", "Humanity", "Humble", "Imagination", "Impossible", "Incredible", "Independent", "Infinity", "Informed", "Innocence", "Intelligence", "Intelligent", "International", "Intrepid", "Jade", "Jubilant", "Knowledge", "Life", "Light", "Literary", "Logic", "Loyalty", "Luminous", "Luna", "Lunar", "Magic", "Majestic", "Majesty", "Medicine", "Melody", "Merry", "Miniature", "Motion", "Mysterious", "Mystery", "National", "Natural", "Nature", "Neo", "New", "Novel", "Novice", "Passion", "Peace", "People's", "Pointless", "Possibility", "Power", "Perseverance", "Prime", "Public's", "Regal", "Ruby", "Sanity", "Sapphire", "Science", "Short", "Silk", "Silver", "Solar", "Soul", "Stellar", "Style", "Stylish", "Superior", "Sympathy", "Teen", "Terror", "Truth", "Twin", "Unity", "Unsung", "Velvet", "Vigilant", "Virtuous", "Warped", "Wisdom", "Wise", "Young"};
    static constexpr std::string_view nm2[] = {"Act", "Actor", "Performance", "Performer", "Answer", "Art", "Atom", "Badge", "Balloon", "Band", "Bear", "Bell", "Bird", "Book", "Camera", "Canvas", "Chance", "Change", "Cherry", "Choice", "Clover", "Comet", "Cord", "Creator", "Crown", "Curtain", "Cushion", "Dance", "Design", "Droplet", "Eagle", "Education", "Engine", "Example", "Eye", "Fan", "Feather", "Film", "Fingerprint", "Flame", "Flower", "Footprint", "Globe", "Glove", "Halo", "Hammer", "Heart", "Hero", "Horse", "Image", "Impulse", "Instrument", "Invention", "Iris", "Jewel", "Ladybug", "Laugh", "Leaf", "Lion", "Locket", "Machine", "Mark", "Mask", "Melody", "Monkey", "Moon", "Mouse", "Music", "Owl", "Palm", "Performance", "Press", "Print", "Pulse", "Question", "Question Mark", "Quill", "Quiver", "Record", "Ribbon", "Smile", "Snail", "Song", "Spade", "Star", "Sun", "Taste", "Theory", "Throne", "Tune", "Veil", "Wand", "Wing"};
    static constexpr std::string_view nm3[] = {"", "", "", "", "", "Accolade", "Award", "Award", "Award", "Award", "Award", "Award", "Award", "Award", "Award", "Award", "Grant", "Hall of Fame", "Hall of Fame Award", "Prize", "Prize for Quality", "Quality Award", "Trophy", "of the Year"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    if (nm1[rnd] == "") {
    while (rnd3 < 5) {
    rnd3 = rng() % std::size(nm3);
    }
    }
    names = "The " + nm1[rnd] + " " + nm2[rnd2] + " " + nm3[rnd3];
    return names;
    }
}
