#include "dragon_ball-frieza_clans_lib.h"

#include <vector>

/* The original JavaScript generator builds a name from two large arrays.
   We copy those arrays verbatim (trimmed for readability) and implement
   the same random‑selection logic. */
std::string generate_dragon_ball_frieza_clans_name(std::mt19937& rng) {
    static const std::vector<std::string> names1 = {
        "Arcti","Arctic","Arctico","Chill","Chilla","Chilley","Chills","Colde","Coled","Coola","Coolio",
        "Forost","Freez","Freeze","Fridge","Fridged","Frigi","Frigid","Frosbyte","Fross","Frost",
        "Frostbite","Froza","Froze","Frozen","Hail","Hale","Ice","Icecube","Icequ","Iceqube","Icey",
        "Icicle","Kold","Kool","Nippy","Pola","Polara","Polaro","Qube","Rime","Ryme","Sano","Sanow",
        "Shiver","Shivera","Shivero","Snow","Wintera","Wintrey","Yce","Ycicle"
    };
    static const std::vector<std::string> names2 = {
        "Andarin","Appel","Appine","Apple","Aprico","Apricot","Avoca","Avocado","Bana","Banan","Berry",
        "Blueber","Cantalou","Cantaloupe","Cheely","Cherr","Cherry","Citro","Citron","Citrone","Coconu",
        "Coconut","Conut","Cranber","Cranberry","Crant","Curran","Currant","Darin","Doorian","Duria",
        "Durian","Emil","Fig","Figg","Gerine","Gomang","Goose","Gooseber","Gooseberry","Granate","Grape",
        "Grapefru","Grapefruit","Grapefrute","Graype","Guav","Guava","Iwik","Kinpum","Kiwi","Kokonut",
        "Kuava","Kumqua","Kumquad","Kumquat","Lamone","Lemon","Lemone","Lime","Lych","Lychee","Lyme",
        "Mandar","Mandarin","Mango","Mato","Mellon","Melo","Melon","Melone","Nectari","Nectarine","Nilla",
        "Nolem","Nomel","Notric","Odacova","Ognam","Orange","Orango","Otamot","Pallum","Papaw","Papay",
        "Papaya","Pawpaw","Paya","Peach","Peache","Pear","Peare","Peech","Peere","Pine","Pineap",
        "Pineapple","Plum","Pomegra","Pomegranate","Pomel","Pomelo","Pricot","Pump","Pumpki","Pumpkin",
        "Qiwi","Quiwi","Rango","Rasber","Raspberry","Rasperry","Rhubar","Rhubarb","Rubar","Strawber",
        "Strawberry","Taloupe","Tanger","Tangeri","Tangerine","Tarine","Toma","Tomato","Vanilla","Vocado"
    };

    // Random i in [0,9]
    int i = static_cast<int>(rng() % 10);
    if (i < 4) {
        size_t idx = rng() % names1.size();
        return names1[idx];
    } else {
        size_t idx = rng() % names2.size();
        return names2[idx];
    }
}
