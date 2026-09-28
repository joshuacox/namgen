#include "pop_culture-hunger_games_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pop_culture_hunger_games_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nmM[] = {"Acee", "Affron", "Aldar", "Alder", "Allio", "Allium", "Almond", "Apratis", "Ardar", "Ardor", "Arfaj", "Ash", "Bage", "Baoba", "Bauble", "Bead", "Beads", "Birch", "Birr", "Blacaw", "Brier", "Burch", "Cabe", "Cabel", "Calyp", "Chester", "Chrysan", "Chryss", "Clover", "Coake", "Coakum", "Coil", "Coile", "Colard", "Colic", "Collar", "Collard", "Collic", "Collort", "Colwort", "Cornel", "Cornell", "Cress", "Crocas", "Curio", "Currio", "Deecee", "Deezee", "Devis", "Devise", "Dewda", "Duscle", "Dussel", "Edel", "Farn", "Fellord", "Fennal", "Fennel", "Flax", "Flint", "Froll", "Frollick", "Gadge", "Gadget", "Galvan", "Galve", "Garget", "Gear", "Geare", "Gimm", "Gimmick", "Glint", "Gordal", "Gordald", "Gordaldo", "Hald", "Haldin", "Harl", "Helbor", "Hibis", "Jolt", "Junk", "Keek", "Kinnik", "Kooza", "Kousa", "Kouza", "Kuds", "Kudz", "Kudzu", "Leome", "Light", "Marel", "Mimosa", "Morel", "Morrel", "Mox", "Neam", "Neem", "Nemo", "Nettle", "Oak", "Ornam", "Osage", "Osier", "Owk", "Parsley", "Parsnip", "Paslee", "Pasnip", "Peesta", "Pellitor", "Pista", "Pocan", "Poplars", "Prong", "Rantee", "Rantipo", "Rantipol", "Rhuba", "Rhubar", "Rigg", "Riggs", "Rye", "Saffran", "Saffron", "Sanguin", "Sarrel", "Scoke", "Scotch", "Sorrel", "Spark", "Sparks", "Syca", "Sycamo", "Tanz", "Tassel", "Tazzel", "Thist", "Torrac", "Triffel", "Triffle", "Trill", "Trillium", "Trink", "Trinket", "Tuls", "Tulsee", "Vanil", "Vender", "Vim", "Waln", "Weiss", "Yarro", "Yarrow", "Zedo", "Zedoary"};
    static constexpr std::string_view nmF[] = {"Acey", "Aldera", "Allium", "Alyss", "Alyssum", "Amara", "Amaran", "Amaryll", "Amaryllis", "Ambro", "Ambrosia", "Aster", "Azalea", "Azo", "Azolla", "Baubelle", "Bauble", "Beade", "Birches", "Birr", "Birre", "Brier", "Brierre", "Cabbyge", "Cabil", "Calyptis", "Calyptus", "Carro", "Catlina", "Chickpea", "Chrysa", "Chrysanthe", "Cleome", "Clove", "Clover", "Cocone", "Coilee", "Cornille", "Cresh", "Cress", "Daffodil", "Daffodille", "Dahlia", "Dahlis", "Daisy", "Daizee", "Deecee", "Deecey", "Dew", "Dewda", "Doodi", "Duscle", "Edel", "Edelwyse", "Elbora", "Elbore", "Ethelia", "Eytelia", "Eytelle", "Fern", "Ferne", "Flaire", "Flare", "Flaxe", "Fodille", "Gadges", "Gadget", "Gidget", "Gimmick", "Glinte", "Haldi", "Harquin", "Harquinne", "Helbora", "Hibis", "Ibiscus", "Iry", "Iwy", "Izy", "Keek", "Kinni", "Kinniki", "Kousha", "Lavender", "Lavenne", "Light", "Marjoree", "Marjory", "Mesqi", "Mesquite", "Mimo", "Mimosa", "Morelle", "Moxi", "Moxie", "Neem", "Neeme", "Nettelle", "Nettle", "Nilla", "Orna", "Osa", "Osage", "Osie", "Parsley", "Paslee", "Pea", "Pellee", "Pellitory", "Pista", "Pleur", "Pleuris", "Pleurisy", "Pocanne", "Poplaire", "Pudina", "Pudine", "Rhubae", "Riggee", "Rye", "Saffreen", "Saffrin", "Saffron", "Saguine", "Santhe", "Sparkle", "Sparkley", "Sycae", "Sycamore", "Tansee", "Tansy", "Tassel", "Tasselle", "Thistle", "Tilsee", "Tine", "Tipole", "Tissel", "Trifle", "Trillium", "Trilly", "Trink", "Trinkee", "Trinket", "Trinks", "Tulsee", "Tulsi", "Vanilee"};
    static constexpr std::string_view nmN[] = {"Acee", "Acey", "Alder", "Allio", "Allium", "Amaran", "Amaryll", "Amaryllis", "Ambro", "Ash", "Azo", "Bauble", "Beade", "Birch", "Birr", "Birre", "Brier", "Cabe", "Cabel", "Cabil", "Chrysan", "Clove", "Coile", "Coilee", "Cornel", "Cornell", "Cresh", "Cress", "Deecee", "Deecey", "Deezee", "Duscle", "Dussel", "Edel", "Fennal", "Fennel", "Flaxe", "Gadget", "Gimmick", "Glinte", "Haldi", "Haldin", "Hibis", "Jolt", "Keek", "Kinnik", "Lavenne", "Leome", "Light", "Mesqi", "Mesquite", "Mimo", "Mimosa", "Morel", "Morrel", "Mox", "Neam", "Neem", "Nemo", "Nettle", "Osa", "Parsley", "Parsnip", "Paslee", "Pasnip", "Pea", "Pista", "Pocan", "Poplaire", "Prong", "Riggee", "Riggs", "Rye", "Saffran", "Saffrin", "Saffron", "Sarrel", "Sorrel", "Spark", "Sparkle", "Sparks", "Syca", "Sycamo", "Sycamore", "Tazzel", "Thist", "Trifle", "Trillium", "Trilly", "Trink", "Trinkee", "Trinket", "Trinks", "Tuls", "Tulsee", "Vender"};
    static constexpr std::string_view nm4[] = {"Amber", "Ash", "Bell", "Bright", "Bronze", "Clear", "Common", "Copper", "Dawn", "Day", "Dusk", "Earth", "Ever", "Fair", "Far", "Flat", "Gallo", "Green", "Hard", "Hawk", "Heaven", "Keen", "Little", "Lock", "Low", "Meadow", "Mild", "Night", "Ocean", "Over", "Peace", "Pit", "Plain", "River", "Rose", "Sea", "Silent", "Silver", "Single", "Sky", "Solid", "Spotted", "Spring", "Steel", "Thorne", "Under", "Well", "Wheat", "White", "Wild"};
    static constexpr std::string_view nm5[] = {"berg", "berry", "bloom", "blossom", "brand", "breath", "breeze", "brook", "bush", "creek", "drop", "dust", "fall", "feather", "flake", "forest", "forge", "gaze", "grove", "hair", "heart", "hill", "horn", "leaf", "lock", "mark", "path", "petal", "rock", "root", "sand", "scape", "shire", "smith", "snow", "song", "star", "stone", "thorn", "tide", "tree", "vale", "ville", "water", "way", "willow", "wind", "wing", "wood", "worth"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nmF);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    names = nmF[rnd] + " " + nm4[rnd2] + nm5[rnd3];
    } else if (type == 2) {
    rnd = rng() % std::size(nmN);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    names = nmN[rnd] + " " + nm4[rnd2] + nm5[rnd3];
    } else {
    rnd = rng() % std::size(nmM);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    names = nmM[rnd] + " " + nm4[rnd2] + nm5[rnd3];
    }
    return names;
    }
}
