#include "towns_and_cities-steampunk_citys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_towns_and_cities_steampunk_citys_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Aera", "Aero", "Aether", "Alder", "Arc", "Arca", "Ash", "Astro", "Automa", "Bacca", "Baro", "Beak", "Bel", "Bell", "Bene", "Bibbing", "Black", "Blag", "Bobbing", "Bol", "Bone", "Brass", "Broad", "Buckle", "Can", "Cant", "Caper", "Char", "Chaun", "Chisel", "Chro", "Chrono", "Cinder", "Cine", "Coal", "Cog", "Cokum", "Cooper", "Cove", "Cover", "Crank", "Crow", "Dapple", "Dark", "Dawn", "Deca", "Dillo", "Dipper", "Diri", "Dirigi", "Dobbin", "Drag", "Dread", "Dub", "Duc", "Duffer", "Dumplin", "Dusk", "Dyna", "Ebon", "Ember", "Ether", "Flam", "Flush", "Fogle", "Gaff", "Gallie", "Gammon", "Gatter", "Gear", "Gearing", "Gegor", "Giz", "Gizmo", "Glim", "Glimmer", "Glimming", "Glock", "Goggle", "Gouge", "Grap", "Graven", "Gray", "Grim", "Grime", "Grub", "Heat", "Heather", "Heli", "Hob", "Hobble", "Ichor", "Iron", "Ivor", "Ivory", "Jemmy", "Jugger", "Kanur", "Ken", "Kenning", "Kennuck", "Kife", "Kine", "Kino", "Knap", "Labo", "Lag", "Leaden", "Leg", "Lever", "Lill", "Lug", "Lugger", "Lushing", "Mag", "Meck", "Mecking", "Mel", "Mill", "Milling", "Min", "Mizzle", "Muffle", "Mumper", "Murk", "Nedding", "Nether", "Nobble", "Nom", "Nox", "Nubbik", "Obsidi", "Onyx", "Padding", "Pall", "Para", "Peri", "Pitch", "Plu", "Pneu", "Poly", "Pradding", "Prater", "Prong", "Rack", "Racket", "Rain", "Raven", "Reaming", "Reeb", "Rig", "Rip", "Riven", "Rook", "Rooker", "Rozzer", "Ruffle", "Scal", "Scran", "Scuttle", "Sere", "Shevi", "Skip", "Skipper", "Skipping", "Slate", "Sloe", "Slum", "Snell", "Snow", "Snoz", "Soot", "Speeler", "Spindle", "Steam", "Steel", "Swart", "Swelling", "Tatting", "Terra", "Tine", "Tinker", "Titfer", "Toff", "Toffing", "Tol", "Tooler", "Toper", "Topping", "Twirl", "Tyro", "Umber", "Van", "Velo", "Veloci", "Vex", "Voli", "Vox", "Wheal", "Whealing"};
    static constexpr std::string_view nm2[] = {"barrow", "borough", "bourne", "burg", "burgh", "burn", "bury", "cairn", "dale", "denn", "drift", "edge", "fall", "fell", "ford", "fort", "garde", "gate", "glen", "guard", "gue", "haben", "hagen", "hallow", "ham", "haven", "helm", "hold", "hollow", "mere", "mire", "moor", "more", "mourne", "point", "port", "rath", "stead", "stein", "storm", "sturm", "thain", "ton", "town", "vale", "wall", "wallow", "ward", "watch", "worth"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2];
    return names;
    }
}
