#include "real-maoris_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_real_maoris_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names1[] = {"Ahera", "Ahia", "Ahuru", "Aika", "Aketu", "Amako", "Amiri", "Amonga", "Anaru", "Anewa", "Arama", "Ariki", "Atama", "Atua", "Eau", "Eiwi", "Ekara", "Eraka", "Erehe", "Erepu", "Erorangi", "Eru", "Eruera", "Eteka", "Eti", "Hakara", "Hamahona", "Hamakona", "Hamonga", "Hangakore", "Hani", "Hanu", "Hare", "Haru", "Hemi", "Heriko", "Hirini", "Hohepa", "Hori", "Huatare", "Iaka", "Ianga", "Ikei", "Imua", "Io", "Iramai", "Itu", "Kae", "Kahi", "Kahorere", "Kauri", "Kea", "Keka", "Kiki", "Kingi", "Kiri", "Kiwi", "Koro", "Maaka", "Mahora", "Maiope", "Maipi", "Mairo", "Maka", "Manu", "Marama", "Maro", "Matewa", "Mikaere", "Mirama", "Moana", "Mokihi", "Nahi", "Naihi", "Nanui", "Napo", "Natana", "Ngaire", "Okiara", "Opi", "Oraora", "Ori", "Otikoro", "Paau", "Pahu", "Paipa", "Paipau", "Paiwa", "Paiwai", "Pakanga", "Paki-Iwi", "Pana", "Pango", "Paora", "Patariki", "Petera", "Piki", "Piripi", "Pita", "Poto", "Puta", "Raiepe", "Raione", "Rana", "Rangi", "Raru", "Rawiri", "Rera", "Rewi", "Rongo", "Rua", "Ruhi", "Ruki", "Ruru", "Taanga", "Taaura", "Tahiwai", "Taipo", "Tama", "Tamati", "Tana", "Tane", "Tangaroa", "Taonga", "Tapu", "Tiki", "Timoti", "Tipene", "Tua", "Tuna", "Tupai", "Turi", "Uamutu", "Ungu", "Uniki", "Urepa", "Urepo", "Uru Reio", "Uru Tonga", "Urutu", "Wa", "Waiapi", "Waiara", "Waraki", "Whiro", "Wiremu", "Witi"};
    static constexpr std::string_view names2[] = {"Ahuaiti", "Ai Kauri", "Aia", "Airini", "Aka", "Akona", "Aku", "Akumatua", "Amiria", "Anahera", "Ani", "Ano Matao", "Ao Mania", "Aperira", "Aputa", "Areta", "Aroha", "Arona", "Aronui", "Ataahua", "Atamarie", "Ea", "Eitu", "Emere", "Ena", "Enutanga", "Erihapeti", "Eriki", "Erina", "Ha Amu", "Haki", "Hakina", "Hara", "Harakoke", "Heeni", "Hine", "Huhana", "Ie", "Ihanga", "Ihiko", "Iria", "Irihapeti", "Kaewa", "Keke", "Kiri", "Kura", "Lani", "Maa Rei", "Maata", "Mahuika", "Maia", "Maiore", "Mairana", "Makareta", "Makei", "Makoro", "Makuku", "Makutu", "Mami", "Manewa", "Marama", "Marika", "Mere", "Mirama", "Moana", "Mokihi", "Naihi", "Nako", "Neina", "Neni", "Neumia", "Newea", "Nga Mimi", "Ngaio", "Ngaire", "Oea", "Oenga", "Oia", "Oie", "Oki", "Okitu", "Oma", "Omaka", "Ori", "Paiti", "Pakeha", "Pakeka", "Pania", "Panoti", "Pianga", "Pihi", "Pipi", "Pora", "Poroka", "Poto", "Pouriwa", "Puhi", "Rakina Au", "Ramarie", "Rangi", "Rangi Area", "Rea", "Reka", "Rere", "Riana", "Roha", "Roimata", "Rona", "Ruhi", "Ruiha", "Ruihi", "Tahi-Popa", "Tahupotiki", "Taikaroa", "Taiko", "Taimana", "Taiomi", "Tapu", "Tarore", "Te Pura", "Tui", "Uariki", "Ukuroa", "Urangi", "Urehu", "Uri Kino", "Uri Wai", "Uru Manau", "Uru Pari", "Uru Rewa", "Uru Tarangi", "Uruanga", "Uruau", "Uruewa", "Wa", "Waauru", "Waewai", "Wai Oro", "Wai Paku", "Waiano", "Waikomanawa", "Whetu", "Whina"};
    static constexpr std::string_view names3[] = {"Akarana", "Aperahama", "Arana", "Arepata", "Arona", "Arono", "Eketone", "Enoka", "Hakopa", "Hamuera", "Hamutana", "Hariwana", "Henare", "Herangi", "Herewini", "Himona", "Hohepa", "Karaka", "Karauna", "Kawhena", "Keeti", "Kerehoma", "Keretene", "Kingi", "Manuera", "Matene", "Mete", "Munu", "Natana", "Nepe", "Nopera", "Paora", "Paraone", "Pekama", "Petera", "Pihere", "Pihopa", "Pikari", "Piripi", "Puhipi", "Raharuhi", "Rakena", "Rara", "Rata", "Rehipeti", "Romana", "Ropata", "Taera", "Tahana", "Taimana", "Taimona", "Tame", "Tamihana", "Taneti", "Tapihana", "Teira", "Tereiti", "Terere", "Tiki", "Timoti", "Tipene", "Topia", "Waaka", "Waata", "Wati", "Watihana", "Wetere", "Wihone", "Wikiriwhi", "Winiata", "Wirihana", "Witika"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(names2);
    rnd2 = rng() % std::size(names3);
    names = names2[rnd] + " " + names3[rnd2];
    } else {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names3);
    names = names1[rnd] + " " + names3[rnd2];
    }
    return names;
    }
}
