#include "miscellaneous-jewelrys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_jewelrys_name(std::mt19937& rng) {
    static constexpr std::string_view nm3[] = {"Tiara", "Necklace", "Amulet", "Bracelet", "Ornament", "Pendant", "Ring", "Pin", "Choker", "Anklet", "Brooch", "Necklace", "Amulet", "Bracelet", "Pendant", "Ring"};
    static constexpr std::string_view nm1[] = {"Adored", "Agate", "Aged", "Amber", "Amethyst", "Ancient", "Angel", "Angelic", "Anonymous", "Antique", "Arctic", "Austere", "Azure", "Blind", "Blushing", "Brave", "Bright", "Brilliant", "Broken", "Citrine", "Colossal", "Coral", "Crisp", "Crystal", "Curly", "Curvy", "Darling", "Dearest", "Defiant", "Devoted", "Diamond", "Diligent", "Earnest", "Elated", "Elegant", "Emerald", "Enchanted", "Enchanting", "Enlightened", "Exalted", "Exotic", "Faint", "Fair", "Feline", "Flawless", "Forsaken", "Free", "Frozen", "Garnet", "Gentle", "Gifted", "Glistening", "Graceful", "Gracious", "Grand", "Grateful", "Handsome", "Happy", "Harmonious", "Heaven", "Heavenly", "Hematite", "Honest", "Humble", "Idle", "Illustrious", "Impossible", "Infinite", "Innocent", "Jade", "Jasper", "Lavish", "Lonely", "Loyal", "Luminous", "Lunar", "Lustrous", "Majestic", "Malachite", "Mellow", "Mysterious", "Obsidian", "Ocean", "Onyx", "Parallel", "Peace", "Peaceful", "Pearl", "Perfect", "Pink", "Playful", "Precious", "Pristine", "Proud", "Pure", "Purity", "Quiet", "Royal", "Ruby", "Sapphire", "Scented", "Secret", "Serene", "Serpent", "Serpentine", "Shadow", "Silent", "Sinful", "Solar", "Spinel", "Spotless", "Stunning", "Sweet", "Tempting", "Tender", "Tinted", "Unmounted", "Velvet", "Vibrant", "Violet", "Virtuous", "Worthy", "Zircon"};
    static constexpr std::string_view nm2[] = {"Ambition", "Aura", "Balance", "Bauble", "Beauty", "Belle", "Blessing", "Bliss", "Blossom", "Bond", "Breath", "Bubble", "Charm", "Class", "Clover", "Core", "Crescent", "Crest", "Cross", "Crux", "Desire", "Devotion", "Dewdrop", "Dream", "Drop", "Droplet", "Eye", "Fan", "Favor", "Flame", "Flower", "Focus", "Force", "Gift", "Glamour", "Globe", "Grace", "Heart", "Hope", "Hum", "Hymn", "Image", "Leaf", "Life", "Light", "Lily", "Love", "Lure", "Mark", "Memorial", "Mind", "Moon", "Oath", "Oculus", "Orb", "Palm", "Panther", "Passion", "Petal", "Pledge", "Poem", "Prayer", "Promise", "Prospect", "Rainbow", "Resolve", "Riddle", "Rock", "Root", "Scale", "Seal", "Shield", "Song", "Soul", "Spark", "Spiral", "Spirit", "Star", "Stone", "Sun", "Swan", "Tear", "Teardrop", "Tempest", "Tribute", "Trinket", "Twin", "Twins", "Twirl", "Twist", "Valor", "Vigor", "Vision", "Voice", "Vow", "Whisper", "Will", "Wing", "Wings", "Wish"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    if (i < 5) {
    names = "The " + nm1[rnd] + " " + nm2[rnd2];
    } else {
    rnd3 = rng() % std::size(nm3);
    names = "The " + nm1[rnd] + " " + nm2[rnd2] + " " + nm3[rnd3];
    }
    return names;
    }
}
