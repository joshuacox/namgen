#include "miscellaneous-galaxys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_galaxys_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Alpha", "Apus", "Aquila", "Ara", "Beta", "Canis", "Carina", "Comae", "Corona", "Crux", "Delta", "Draco", "Epsilon", "Gamma", "Lambda", "Lyra", "Nemo", "Omega", "Omicron", "Pavo", "Proxima", "Sagitta", "Serpens", "Sigma", "Theta", "Upsilon", "Ursa", "Vela", "Virgo", "Zeta", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"Acallaris", "Achelois", "Adastreia", "Aegialeus", "Aegimius", "Alatheia", "Alcyoneus", "Aldebaran", "Amphiaraus", "Anadeia", "Andromeda", "Aquarii", "Arcturus", "Aristaeus", "Asteria", "Asteropaios", "Astraeus", "Aurigae", "Boreas", "Borysthenis", "Calesius", "Capella", "Cassiopeia", "Centauri", "Centaurus", "Chronos", "Cymopoleia", "Dioscuri", "Draconis", "Eioneus", "Eridani", "Eridanus", "Eubuleus", "Euphorion", "Eusebeia", "Euthenia", "Hemithea", "Hyperbius", "Hyperes", "Hyperion", "Icarius", "Ichnaea", "Ilioneus", "Kentaurus", "Leporis", "Librae", "Lyrae", "Majoris", "Miriandynus", "Myrmidon", "Nebula", "Nemesis", "Odysseus", "Ophiuchi", "Orion", "Orionis", "Orithyia", "Palioxis", "Peleus", "Perileos", "Perseus", "Phoroneus", "Polystratus", "Porphyrion", "Proioxis", "Sagittarius", "Sirius", "Solymus", "Zagreus", "Zephyrus"};
    static constexpr std::string_view nm3[] = {"Abyss", "Acorn", "Arrowhead", "Banana", "Beansprout", "Beanstalk", "Bell", "Blue Ribbon", "Blueberry", "Bottleneck", "Bowl", "Bull's Eye", "Bullet", "Butterfly", "Cat's Ear", "Cat's Eye", "Catterpillar", "Cherry", "Chickpea", "Clover", "Coconut", "Comet", "Crescent", "Crow's Feet", "Crown", "Dandelion", "Diamond", "Dragontooth", "Droplet", "Eagle Claw", "Eggshell", "Exploding", "Eyebrow", "Eyelash", "Falling", "Feather", "Fern Leaf", "Fingerprint", "Fisheye", "Fishscale", "Flame", "Football", "Grain", "Halo", "Heart", "Horseshoe", "Hurricane", "Icicle", "Iris", "Jellyfish", "Kettle", "Leaf", "Lemon", "Lightbulb", "Lilypad", "Lion's Mane", "Lion's Tail", "Maelstrom", "Meridian", "Mosaic", "Mouse", "Octopus", "Oculus", "Onion", "Owl Head", "Pear", "Pepper", "Pig's Tail", "Pinecone", "Ponytail", "Potato", "Red Ribbon", "Rippled", "Rose Petal", "Sawblade", "Seashell", "Serpent", "Serpent's Eye", "Sharkfin", "Sharktooth", "Shield", "Shooting Star", "Snail Shell", "Snowflake", "Soap Bubble", "Sparrow", "Spearpoint", "Spiderleg", "Spiderweb", "Spiral", "Starfish", "Strawberry", "Teacup", "Tiara", "Tiger Paw", "Tree Root", "Tree Trunk", "Turtle Shell", "Vortex", "Wave", "Whale's Tail", "Zodiac"};
    static constexpr std::string_view nm4[] = {"Nebula", "Galaxy", "Cloud", "Star System"};
    static constexpr std::string_view nm5[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", ""};
    static constexpr std::string_view nm6[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ""};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (i < 3) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + " " + nm2[rnd2];
    } else if (i < 5) {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm4);
    names = nm2[rnd] + " " + nm4[rnd2];
    } else if (i < 8) {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    names = nm3[rnd] + " " + nm4[rnd2];
    } else if (i < 9) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm5);
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm6);
    names = nm5[rnd] + nm5[rnd2] + "-" + nm6[rnd3] + nm6[rnd4] + nm6[rnd5];
    } else {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm5);
    rnd3 = rng() % std::size(nm5);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm5);
    names = nm5[rnd] + nm5[rnd2] + nm5[rnd3] + " " + nm6[rnd4] + nm6[rnd5] + nm5[rnd5];
    }
    return names;
    }
}
