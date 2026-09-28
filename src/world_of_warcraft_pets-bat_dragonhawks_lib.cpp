#include "world_of_warcraft_pets-bat_dragonhawks_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_world_of_warcraft_pets_bat_dragonhawks_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Aidec", "Alucard", "Aluminum", "Anca", "Athugz", "Awin", "Azurisz", "Azurys", "Azuryz", "Balgzr", "Balloon", "Baloo", "Bartok", "Bast", "BatPitt", "Batholomew", "Batista", "Batita", "Batley", "BatleyCooper", "Batty", "Bax", "Baxter", "Belfry", "Belphegor", "Beniam", "Bephelgor", "Bibacr", "Bloodmaw", "Bloodscent", "Bloodwing", "BloodyMary", "Bloodymuzzle", "Blurp", "Boannan", "Brandusa", "Brokenfang", "Bruce", "Bubbles", "Bunted", "Camazotz", "Caped", "Cecirh", "Cezar", "Chausiku", "Chocula", "Cipanr", "Ciprian", "Corneliu", "Count", "CountChocula", "CountDracula", "Danut", "Darkness", "Dawn", "Deathmaw", "Delano", "Demetrie", "Dimitri", "Ding", "Dingbat", "Dinu", "Drac", "Dracula", "Draculon", "Dradis", "Drakul", "Dreuc", "Dung", "Eclipse", "Ecture", "Edimmu", "Eseit", "Fang", "Fangs", "Fanteriso", "Fizzle", "Flapper", "Flappy", "Fledermaus", "Floater", "Flotsam", "Flygon", "Fontenay", "Fuzzy", "Gargles", "Gavril", "Glider", "Golbat", "Grigore", "Guano", "Gullet", "HairTangler", "Haze", "Helldiver", "Horatiu", "Hynraic", "Hynryac", "Iach", "Iarsere", "Iatosr", "Ioan", "Irritant", "Irubleu", "Jet", "Kite", "Knuckle", "Lacip", "Laicch", "Laimhynr", "Laitpaurh", "Lamsor", "Lasis", "Liwa", "Lockjaw", "Lollipop", "Longfang", "Lorenna", "Loryss", "Lucifer", "Lucirr", "Luna", "Man", "Maya", "Mihail", "Mihaiti", "Mist", "Mothball", "Mozzie", "Nerf", "Nibbles", "Nightwing", "Nosferatu", "Nyx", "Outtahell", "Ozzy", "Petru", "Pickle", "Quentynn", "Quickfang", "Quillestra", "Quilstream", "Rabbies", "Rabies", "Radar", "Raich", "Rajnish", "Remus", "Render", "Reucec", "Ripmaw", "Ruqualash", "Ryacoer", "Sade", "Screech", "Screechy", "Secr", "Serenity", "Sharptooth", "Skona", "Slideshow", "Slithe", "SlowMo", "Snape", "Sonar", "Sorin", "Sparkle", "Spaulding", "Spawnie", "Spike", "Sport", "Spudnik", "Spuds", "Spyestra", "Squeekers", "Ssynec", "Stinky", "Sturmovic", "Sucka", "Suckah", "Summanus", "Sunshine", "Sunshynne", "Sushi", "Swoops", "Tampax", "Tiberius", "Tlaitparh", "Tloiciac", "Twilight", "Twinkle", "Twinkles", "Umpire", "Vampire", "Vlad", "Vladimir", "Wayne", "Wiggles", "Willy", "Wingnut", "Wooden", "Ybhugr", "Ynremr", "Yugnos", "Zubat"};
    static constexpr std::string_view nm2[] = {"Aasterinian", "Adarna", "Aine", "Aiolus", "Ajax", "Alaricus", "Amani", "Amber", "Ametarasu", "Anor", "Apep", "Apollo", "Apophis", "Archangel", "Astilabor", "Aurora", "Azar", "Azrael", "Bahamut", "Belinda", "BlackHawkUp", "Blaze", "Blaziken", "Bridget", "Brimstone", "CaptainMagestic", "Char", "Charizard", "Chronepsis", "Cinaed", "Cinderella", "Cindur", "Combusken", "Cupcake", "Cyra", "Dart", "Dawn", "DawningStar", "Dragonair", "Dragonite", "Eclipse", "Ember", "Emberella", "Emilius", "Equiknocks", "Equinox", "Equintess", "Esabon", "Exona", "Faluzure", "Fefnir", "Fiammetta", "Fiera", "Fierna", "Fintan", "Fiona", "Firedancer", "Flamebreath", "Flamebringer", "Flappy", "Flare", "Flareon", "Flicker", "Flutterby", "Flygon", "Fuego", "Furrion", "Gabija", "Garyx", "Gizmo", "Glaurung", "Griffin", "Heatran", "Heatwave", "Helios", "Hlal", "Hyperion", "ILikemCrispy", "Ignacio", "Ignescent", "Illumina", "Imatazeubro", "Incandessa", "Inti", "Io", "Kestrel", "Kindle", "Kiyo", "Lendys", "Leryda", "LilMsCrispy", "Lina", "Loogie", "Lucifer", "Magmar", "Magmortar", "Matthew", "Moltres", "Morningstar", "Mushu", "Naur", "Phoenix", "PhoenixDown", "Plume", "Pyrrhus", "Quilafyre", "Quilla", "Ra", "Rainbow", "Rhonin", "Rouge", "Ryuu", "Salamence", "Sardior", "Seraphim", "Serenity", "Shina", "Shrike", "SimpleSensations", "Smaug", "Solar", "Sora", "Spectre", "Spitfire", "StarScream", "Starburst", "Sun Queen", "Sunburn", "Sunburst", "Sunflare", "Sunrise", "Sunshine", "Tamara", "Tawhaki", "Tequila", "TequilaSundown", "Tiamat", "Timeus", "Tinder", "Tobias", "Torchic", "Uruloki", "Vallenari", "Vanity", "Vulkan", "Xolotl"};

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
