#include "game_of_thrones-dothrakis_lib.h"

#include <vector>
#include <string>
#include <random>

/* Full name lists copied from the original JavaScript generator */
static const std::vector<std::string> namesMale = {
    "Acchakko (Acchakat, To silence)", "Achrallo (Achralat, To be smelly)", "Addrivo (Addrivat, To kill)",
    "Addro (Addrivat, To kill)", "Aggendo (Aggendat, To rip something)", "Aggo (Aggendat, To rip something)",
    "Ahesso (Ahesh, Snow)", "Annakko (Annakholat, To finish)", "Annitho (Annithat, To cause pain)",
    "Anno (Annithat, To cause pain)", "Aresso (Aresak, Coward)", "Arrisso (Arrisat, To fix)", "Arro (Arrisat, To fix)",
    "Arrokko (Arrokhat, To frighten)", "Assammo (Assamvat, To break)", "Assilo (Assilat, To defeat)",
    "Asso (Assamvat, To break)", "Assollo (Assolat, To command)", "Astillo (Astilat, To joke)",
    "Astollo (Astolat, To speak)", "Awazzo (Awazat, To scream)", "Ayollo (Ayolat, To wait)",
    "Azzafro (Azzafrolat, To enslave)", "Azzo (Azzisat, To harm someone)", "Chakko (Chakat, To be silent)",
    "Charro (Charloat, To listen)", "Chommo (Chomat, To be respectful)", "Chomokko (Chomokh, Honor)",
    "Chongo (Chongat, To be hard)", "Dallo (Dalfe, Cow/Beef)", "Davro (Davra, Good/Useful)",
    "Davrollo (Davralat, To be useful)", "Dirgo (Dirgat, To think)", "Disso (Dis, Simple/Plain)",
    "Donno (Donat, To shout)", "Drogo (Drogat, To drive)", "Edavro (Edavrasa, Useless)",
    "Ematto (Emat, To smile)", "Emmatto (Emmat, To amuse)", "Enosso (Enossho, Mule)",
    "Erro (Erin, Kind/Good)", "Esitto (Esittesalat, To brag)", "Essino (Esinalat, To be different)",
    "Esso (Esina, Different)", "Ezollo (Ezolat, To learn)", "Ezzo (Ezat, To find)",
    "Ezzollo (Ezzolat, To teach)", "Fakko (Fakat, To kick)", "Fejo (Fejat, To hate)",
    "Fesho (Feshith, Tree)", "Ficho (Fichat, To take/To bring)", "Filko (Filkak, Coward)",
    "Fitto (Fitte, Short)", "Fonno (Fonak, Hunter)", "Fono (Fonat, To Hunt)",
    "Gacho (Gachat, To solve)", "Gezro (Gezri, Snake)", "Gorro (Gorat, To charge)",
    "Gosho (Goshat, To be sure)", "Haji (Haj, Strong)", "Havvo (Havziven, Lazy)",
    "Havzo (Havziven, Lazy)", "Hezho (Hezhahat, To travel)", "Hezzo (Hezhahat, To travel)",
    "Hlizzo (Hlizif, Bear)", "Hrazzo (Hrazef, Horse)", "Idrillo (Idrilat, To guide)",
    "Ifakko (Ifak, Foreigner)", "Ildatto (Ildat, To strike)", "Ildo (Ildat, To strike)",
    "Izzo (Izzat, To poison)", "Jasso (Jasat, To laugh)", "Jazzo (Jazat, To block)",
    "Jezzo (Jezat, To block a strike)", "Jillo (Jilat, To be right)", "Kaffatto (Kaffat, To crush)",
    "Kaffo (Kafat, To smash)", "Karlinno (Karlinat, To gallop)", "Karlo (Karlinat, To gallop)",
    "Kesso (Kesselat, To carry)", "Kovarro (Kovarat, To stand)", "Krazzo (Krazaaj, Mountain)",
    "Lajatto (Lajat, To fight)", "Lajo (Lajak, Fighter/Warrior)", "Lanno (Lanat, To run)",
    "Lanqo (Lanqoyi, Killing spree)", "Lavakho (Lavakhat, To be loud)", "Layafo (Layafat, To be happy)",
    "Leqso (Leqse, Rat)", "Lojatto (Lojat, To hit)", "Loqqo (Loqam, Arrow)",
    "Losho (Loshak, Guard)", "Losso (Loshak, Guard)", "Marillo (Marilat, To construct)",
    "Marro (Marilat, To construct)", "Mattello (Mattelat, To limp)", "Matto (Mattelat, To limp)",
    "Mello (Melat, To be evil)", "Mosko (Moskat, To load/To pack)", "Movvo (Movek, Warlock/Magician)",
    "Najaho (Najahak, Winner)", "Najaho (Najahat, To be victorious)", "Najo (Najah, Victorious)",
    "Naqo (Naqis, Small)", "Navvo (Navik, Beginner)", "Neggo (Negwin, Stone)",
    "Nevakko (Nevak, Guest)", "Nivvo (Nivat, To frown)", "Nizho (Nizhat, To be tough)",
    "Nizzo (Nizhat, To be tough)", "Ogatto (Ogat, To slaughter)", "Ohollo (Oholat, To be still)",
    "Onqo (Onqothat, To walk)", "Ostatto (Ostat, To bite)", "Ovvetho (Ovvethat, To throw/To shoot)",
    "Ovvo (Ovah, Fat)", "Qotho (Qothat, To be loyal)", "Qotho (Qothat, To be loyal/To be repetitive)",
    "Qotto (Qothat, To be loyal/To be repetitive)", "Qovvo (Qovat, To tremble)", "Rakharo (Rakh, Boy)",
    "Remekko (Remekat, To sleep)", "Remmo (Remekat, To sleep)", "Rhaego (Rhaek, Athlete)",
    "Rhanno (Rhanat, To be merciful)", "Rhello (Rhelat, To help)", "Sajo (Sajak, Rider)",
    "Shiggo (Shigat, To snore)", "Shiko (Shigat, To snore)", "Shovvo (Shoven, Marked/Smudged)",
    "Sikhtello (Sikhtelat, To spit)", "Sikko (Sikhtelat, To spit)", "Temmo (Temme, Thunder)",
    "Thirro (Thirlat, To survive)", "Tihho (Tihat, To look/To see)", "Tihollo (Tiholat, To understand)",
    "Tokko (Toki, Dumb)", "Vazzo (Vaz, Storm)", "Verakko (Verak, Traveler)", "Verro (Ver, Wolf)",
    "Verro (Verat, To travel)", "Villo (Villat, To be wise)", "Vindello (Vindelat, To stab)",
    "Vinesso (Vineserat, To remember)", "Virsallo (Virsalat, To burn)",
    "Vitihho (Vitihirat, To watch/To oberserve)", "Vorro (Vorsa, Fire)", "Vorsakko (Vorsakh, Flame)",
    "Vorso (Vorsa, Fire)", "Vrozzo (Vroz, Slow)", "Yenno (Yeni, Failure)", "Zerqo (Zerqolat, To swim)",
    "Zerqollo (Zerqolat, To swim)", "Zhowakko (Zhowak, Dangerous)", "Zhowo (Zhowak, Dangerous)",
    "Zicho (Zichome, Disrespectful)", "Zichommo (Zichome, Disrespectful)", "Ziffo (Zifichelat, To steal)",
    "Zificho (Zifichelat, To steal)", "Ziganno (Ziganesolat, To defy/To oppose)",
    "Ziggo (Ziganesolat, To defy/To oppose)", "Zinemmo (Zimemelat, To distract)",
    "Zinno (Zimemelat, To distract)", "Zireyo (Zireyeselat, To offend/To bug)",
    "Zirqo (Zirqoyi, Bird of prey)", "Zirro (Zireyeselat, To offend/To bug)",
    "Zoratto (Zorat, To roar)", "Zorro (Zorat, To roar)"
};

static const std::vector<std::string> namesFemale = {
    "Acchi (Acchakat, To silence)", "Achralli (Achralat, To be smelly)", "Achri (Achralat, To be smelly)",
    "Affi (Affisat, To clean)", "Affisi (Affisat, To clean)", "Aheshi (Ahesh, Snow)", "Ahi (Ahesh, Snow)",
    "Allayi (Allayafat, To please)", "Annithi (Annithat, To cause pain)", "Aressi (Aresak, Coward)",
    "Ari (Aresak, Coward)", "Asavvi (Asavva, Sky)", "Asheffi (Ashefa, River)", "Ashi (Ashefa, River)",
    "Awazzi (Awazat, To scream)", "Awwi (Awazat, To scream)", "Ayi (Ayolat, To wait)", "Ayolli (Ayolat, To wait)",
    "Chakki (Chakat, To be silent)", "Charli (Charloat, To listen)", "Charri (Charloat, To listen)",
    "Chelli (Chelsian, Locust)", "Chelsi (Chelsian, Locust)", "Chommi (Chomat, To be respectful)",
    "Dalfi (Dalfe, Cow/Beef)", "Dalli (Dalfe, Cow/Beef)", "Davralli (Davralat, To be useful)",
    "Davri (Davra, Good/Useful)", "Davvi (Davra, Good/Useful)", "Dissi (Dis, Simple/Plain)",
    "Edavri (Edavrasa, Useless)", "Emmati (Emmat, To amuse)", "Emmi (Emat, To smile)",
    "Enosshi (Enossho, Mule)", "Enossi (Enossho, Mule)", "Erri (Erin, Kind/Good)", "Eshi (Eshina, Fish)",
    "Eshinni (Eshina, Fish)", "Esinni (Esina, Different)", "Esinni (Esinalat, To be different)",
    "Essi (Esina, Different)", "Evethi (Eveth, Water)", "Evi (Eveth, Water)", "Ewwi (Ewe, Olive)",
    "Eyelli (Eyel, Rain)", "Ezhi (Ezhirat, To dance)", "Ezhirri (Ezhirat, To dance)",
    "Ezolli (Ezolat, To learn)", "Ezzi (Ezolat, To learn)", "Ezzoli (Ezzolat, To teach)",
    "Feldi (Feldekh, Feather)", "Felli (Feldekh, Feather)", "Fichi (Fichat, To take/To bring)",
    "Filki (Filkak, Coward)", "Filli (Filkak, Coward)", "Fitti (Fitte, Short)", "Gevvi (Geve, Mole)",
    "Gilli (Gillo, Breeze)", "Gizzi (Giz, Bee)", "Haddi (Hador, Gust of wind)", "Haffi (Haf, Soft/Quiet)",
    "Haji (Haj, Strong)", "Halahhi (Halah, Flower)", "Halli (Halah, Flower)", "Hanni (Hanna, Rose)",
    "Havazhi (Havazh, Sea)", "Havvi (Havazh, Sea)", "Havzi (Havziven, Lazy)", "Hoski (Hoska, Mouth of an animal)",
    "Hossi (Hoska, Mouth of an animal)", "Hoyalli (Hoyalat, To sing)", "Hoyi (Hoyalat, To sing)",
    "Ifakki (Ifak, To walk)", "Iffi (Ifak, Foreigner)", "Ikhi (Ikh, Ashes)", "Inti (Inte, Beetle)",
    "Irri (Irra, Trout)", "Izzatti (Izzat, To poison)", "Izzi (Iz, Poison)", "Janni (Jano, Dog)",
    "Jasatti (Jasat, To laugh)", "Jassi (Jasat, To laugh)", "Jeddi (Jedda, Pony)", "Jeshi (Jesh, Ice)",
    "Jolinni (Jolinat, To cook)", "Jolli (Jolinat, To cook)", "Jommi (Joma, Salmon)", "Kendri (Kendra, Opal)",
    "Kesselli (Kesselat, To carry)", "Kessi (Kesselat, To carry)", "Khewi (Khewo, Worm)", "Laqqi (Laqat, To cry)",
    "Lavakhi (Lavakhat, To be loud)", "Lavvi (Lavakhat, To be loud)", "Layaffi (Layafat, To be happy)",
    "Layi (Layafat, To be happy)", "Leqsi (Leqse, Rat)", "Loshatti (Loshat, To carry)", "Loshi (Loshat, To carry)",
    "Madatti (Madat, To sew)", "Maddi (Madat, To sew)", "Mattelli (Mattelat, To limp)", "Matti (Mattelat, To limp)",
    "Mavelli (Mavelat, To make by hand)", "Mavi (Mavelat, To make by hand)", "Mawi (Mawizzi, Rabbit)",
    "Melli (Melat, To be evil)", "Naqqi (Naqis, Small)", "Navvi (Navik, Beginner)", "Nevvi (Nevak, Guest)",
    "Nivvi (Nivat, To frown)", "Nizhi (Nizhat, To be tough)", "Oholli (Oholat, To be still)", "Oqetti (Oqet, Sheep)",
    "Oqqi (Oqet, Sheep)", "Osti (Ostat, To bite)", "Ovahhi (Ovah, Fat)", "Ovvi (Ovah, Fat)", "Ozzi (Ozzir, Ruby)",
    "Ozzirri (Ozzir, Ruby)", "Qiffi (Qifo, Boar/Pig)", "Qossi (Qosar, Spider)", "Qothi (Qothat, To be loyal/To be repetitive)",
    "Qovatti (Qovat, To tremble)", "Qovvi (Qovat, To tremble)", "Remekki (Remekat, To sleep)", "Remmi (Remekat, To sleep)",
    "Rhelli (Rhelat, To help)", "Shovi (Shoven, Marked/Smudged)", "Thashi (Thash, Soft)", "Thirli (Thirlat, To survive)",
    "Thirri (Thirlat, To survive)", "Verakki (Verak, Traveler)", "Verri (Verak, Traveler)", "Vitihi (Vitihirat, To watch/To oberserve)",
    "Vitti (Vitihirat, To watch/To oberserve)", "Vorri (Vorsa, Fire)", "Vorsakhi (Vorsakh, Flame)", "Vrozzi (Vroz, Slow)",
    "Yetti (Yetto, Frog)", "Zhali (Zhalia, Butterfly)", "Zhalli (Zhalia, Butterfly)", "Zhavvi (Zhav, Lizard)",
    "Zhowi (Zhowak, Dangerous)", "Zichi (Zichome, Disrespectful)", "Zichomi (Zichome, Disrespectful)", "Ziffi (Zifichelat, To steal)",
    "Zifichi (Zifichelat, To steal)", "Ziganni (Ziganesolat, To defy/To oppose)", "Ziggi (Ziganesolat, To defy/To oppose)",
    "Zimemmi (Zimemelat, To distract)", "Zimmi (Zimemelat, To distract)", "Zireyyi (Zireyeselat, To offend/To bug)",
    "Zirqi (Zirqoyi, Bird of prey)", "Zirri (Zir, Bird)"
};

static const std::vector<std::string> namesM1 = {"", "", "", "", "", "b", "c", "d", "h", "j", "k", "m", "p", "q", "r", "bh", "ch", "jh", "kh", "qh", "rh", "br", "cr", "dr", "kr", "pr", "qr"};
static const std::vector<std::string> namesM2 = {"ae", "a", "o", "a", "o", "a", "o"};
static const std::vector<std::string> namesM3 = {"d", "dd", "h", "j", "jh", "k", "kh", "kk", "l", "ll", "m", "mm", "n", "nn", "t", "tt", "v", "z", "zh", "zz", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
static const std::vector<std::string> namesM4 = {"", "a", "o", "a", "o", "a", "o", "ae"};
static const std::vector<std::string> namesM5 = {"bo", "ggo", "go", "kho", "llo", "no", "qo", "rbo", "ro", "rro", "tho", "ko", "kko", "rko", "rqo", "rlo", "rgo", "mo", "nno", "mmo", "qqo", "zho", "zo", "zzo", "vo", "vvo"};

static const std::vector<std::string> namesF1 = {"", "", "", "", "f", "h", "jh", "k", "l", "m", "n", "q", "r", "s", "sh", "t", "th", "v", "w", "y", "zh"};
static const std::vector<std::string> namesF2 = {"e", "i", "a", "i"};
static const std::vector<std::string> namesF3 = {"f", "ff", "g", "h", "l", "ll", "m", "mm", "n", "nn", "q", "r", "s", "sh", "ss", "t", "th", "w", "z", "zh", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
static const std::vector<std::string> namesF4 = {"", "e", "i", "a", "i"};
static const std::vector<std::string> namesF5 = {"bi", "ffi", "fi", "ssi", "si", "gi", "hhi", "hi", "ki", "kki", "lli", "mi", "mmi", "ni", "nni", "qi", "qqi", "qui", "ri", "rri", "thi", "vi", "vvi", "wi", "zhi", "zi", "zzi"};

std::string generate_game_of_thrones_dothrakis_name(std::mt19937& rng) {
    bool female = (rng() % 2) == 1;          // 0 = male, 1 = female
    int i = static_cast<int>(rng() % 10);   // mimic Math.floor(Math.random()*10)

    if (female) {
        if (i < 5) {
            std::uniform_int_distribution<std::size_t> dist(0, namesFemale.size() - 1);
            return namesFemale[dist(rng)];
        } else {
            std::uniform_int_distribution<std::size_t> d1(0, namesF1.size() - 1);
            std::uniform_int_distribution<std::size_t> d2(0, namesF2.size() - 1);
            std::uniform_int_distribution<std::size_t> d3(0, namesF3.size() - 1);
            std::uniform_int_distribution<std::size_t> d4(0, namesF4.size() - 1);
            std::uniform_int_distribution<std::size_t> d5(0, namesF5.size() - 1);

            std::size_t idx1 = d1(rng);
            std::size_t idx2 = d2(rng);
            std::size_t idx3 = d3(rng);
            std::size_t idx4 = d4(rng);
            std::size_t idx5 = d5(rng);

            if (idx1 < 4) {
                while (idx2 == 0) {
                    idx2 = d2(rng);
                }
            }
            if (idx3 > 19) {
                idx4 = 0;
            } else {
                while (idx4 == 0) {
                    idx4 = d4(rng);
                }
            }
            return namesF1[idx1] + namesF2[idx2] + namesF3[idx3] + namesF4[idx4] + namesF5[idx5];
        }
    } else {
        if (i < 5) {
            std::uniform_int_distribution<std::size_t> dist(0, namesMale.size() - 1);
            return namesMale[dist(rng)];
        } else {
            std::uniform_int_distribution<std::size_t> d1(0, namesM1.size() - 1);
            std::uniform_int_distribution<std::size_t> d2(0, namesM2.size() - 1);
            std::uniform_int_distribution<std::size_t> d3(0, namesM3.size() - 1);
            std::uniform_int_distribution<std::size_t> d4(0, namesM4.size() - 1);
            std::uniform_int_distribution<std::size_t> d5(0, namesM5.size() - 1);

            std::size_t idx1 = d1(rng);
            std::size_t idx2 = d2(rng);
            std::size_t idx3 = d3(rng);
            std::size_t idx4 = d4(rng);
            std::size_t idx5 = d5(rng);

            if (idx1 < 5) {
                while (idx2 == 0) {
                    idx2 = d2(rng);
                }
            }
            if (idx3 > 19) {
                idx4 = 0;
            } else {
                while (idx4 == 0) {
                    idx4 = d4(rng);
                }
            }
            return namesM1[idx1] + namesM2[idx2] + namesM3[idx3] + namesM4[idx4] + namesM5[idx5];
        }
    }
}
