#include "towns_and_cities-south_asian_towns_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_towns_and_cities_south_asian_towns_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Ab", "Abed", "Abre", "Adi", "Adram", "Baba", "Bad", "Badur", "Bago", "Ba", "Bal", "Cah", "Car", "Cha", "Chan", "Dan", "Danla", "Da", "Das", "Do", "Elya", "Esh", "Fa", "Farma", "Ganja", "Gan", "Gaw", "Ghero", "Ghu", "Ha", "Hey", "Il", "Jad", "Jal", "Jaw", "Kah", "Kal", "Ka", "Keli", "Kora", "Kulu", "Lon", "Ma", "Mah", "Muri", "Nas", "Naw", "Nu", "Om", "Ota", "Pala", "Par", "Quba", "Qanda", "Rakh", "Rur", "Sab", "Sew", "Shey", "Takh"};
    static constexpr std::string_view names2[] = {"bahar", "bar", "botara", "burgha", "chaman", "chaq", "daha", "dana", "deh", "dura", "durzar", "gan", "gazi", "ghez", "ghisi", "gorak", "gozar", "hari", "jabad", "jur", "kata", "khak", "kharak", "khel", "khin", "khlah", "kul", "kusta", "laran", "latabad", "lur", "mandan", "mandi", "mard", "mazar", "nadeh", "najar", "naqla", "patan", "qachi", "qolak", "qoli", "rabad", "ramzai", "ran", "rangi", "raseh", "ratan", "rawan", "rejan", "rozar", "ryd", "sabad", "sang", "sarak", "shan", "suran", "tabad", "taken", "tara"};
    static constexpr std::string_view names3[] = {"Ath", "Ayu", "Bat", "Batta", "Bhal", "Bure", "Cha", "Chak", "Chish", "Dar", "Dipal", "Hafi", "Jam", "Kala", "Kash", "Kha", "Khair", "Khu", "Khui", "Khuz", "Kula", "Lar", "Las", "Latam", "Man", "Mas", "Min", "Miran", "Mul", "Nagar", "Naro", "Nush", "Pas", "Qaim", "Qam", "Raz", "Risal", "Sak", "San", "Shakar", "Shar", "Shikar", "Si", "Skar", "Tang", "Timer", "Tur"};
    static constexpr std::string_view names4[] = {"bagh", "bar", "bat", "bela", "ber", "bi", "bia", "chi", "da", "dar", "dara", "du", "gai", "gara", "garh", "ghar", "gora", "gram", "kana", "khela", "ki", "mak", "man", "more", "muqam", "ni", "parkar", "pur", "ran", "rand", "ratta", "rud", "sehra", "shab", "shah", "tan", "tian", "tung", "wal", "wala", "wani", "zabad"};
    static constexpr std::string_view names5[] = {"Ada", "Ad", "Ambe", "Ba", "Bal", "Bar", "Bhi", "Byasa", "Chat", "Chhap", "Chir", "Dham", "Dhu", "Di", "Dum", "Farooq", "Fateh", "Fazil", "Gad", "Gopal", "Gu", "Guru", "Han", "Hazari", "Haza", "Jag", "Jalan", "Jan", "Jhar", "Kandu", "Karim", "Khaga", "Kyatha", "Lak", "Lal", "Ling", "Luna", "Madhe", "Ma", "Mahid", "Malkan", "Mangal", "Musa", "Nabaran", "Nahar", "Nar", "Nela", "?Nida", "Pa", "Periya", "Piriya", "Pukh", "Rafi", "Rajal", "Raj", "Revel", "Rudra", "Safi", "Sag", "Sher", "Shish", "Sila", "Siva", "Sundar", "Tara", "Tiru", "Umar", "Vanda", "Vis", "Wan"};
    static constexpr std::string_view names6[] = {"bag", "bani", "bri", "desar", "dhar", "dhargat", "doi", "dukur", "dwal", "gadi", "gam", "ganj", "gank", "gaon", "garh", "garia", "gat", "ghati", "giri", "gudi", "gundi", "jogai", "ka", "kaner", "khed", "kheri", "kulam", "lagun", "laj", "langir", "mangala", "mia", "miri", "nagar", "palle", "pathar", "pathur", "patna", "phu", "pra", "pur", "pura", "raon", "rayan", "ribag", "si", "sugur", "tari", "thampalle", "tial", "tra", "vasi", "vayoor", "wada", "wani", "yar"};
    static constexpr std::string_view names7[] = {"Addalai", "Amune", "Arambe", "Attara", "Bakala", "Bambara", "Batti", "Bo", "Bodi", "Buweli", "Dambara", "Dolos", "Domati", "Dunuke", "Egoda", "Elemal", "Eta", "Gan", "Ge", "Goda", "Gunne", "Hega", "Hom", "Hulu", "Ilpe", "Imbul", "Ira", "Jiwana", "Kande", "Karal", "Khata", "Lappa", "Lini", "Maliga", "Mi", "Miwa", "Moraga", "Na", "Nika", "Nuga", "Ota", "Owi", "Paha", "Pe", "Pol", "Puwak", "Rada", "Reki", "Roti", "Sela", "Suriya", "Taigaha", "Tetta", "Thikko", "Thiray", "Tora", "Una", "Uppo", "Uru", "Vadd", "Vaka", "Veera", "Veppan", "Ya", "Yatima"};
    static constexpr std::string_view names8[] = {"bage", "bawa", "bepola", "bura", "caloa", "chenai", "dai", "davan", "diya", "dura", "gaginna", "gaha", "galla", "gama", "ganga", "gatenna", "ginna", "goda", "golla", "hala", "handa", "hilla", "kada", "kamam", "karai", "kewatta", "kodai", "kotuwa", "kuda", "kumbura", "landa", "lawa", "lena", "likada", "liyada", "mada", "madu", "mulla", "mure", "nagama", "pana", "pitiya", "pola", "ragama", "rai", "rawa", "ruppa", "sa", "sulla", "tagaha", "tale", "tembe", "tenna", "tipe", "tivu", "tiya", "tiyawa", "tota", "tura", "wala", "wana", "watta", "watura", "wela", "wella", "wewa", "yada", "yawa"};
    static constexpr std::string_view names9[] = {"Amara", "Bandi", "Bane", "Bhakta", "Bir", "Birat", "Chain", "Chau", "Chit", "Da", "Dha", "Gai", "Gaida", "Gho", "Gor", "Gula", "Ina", "Janak", "Jit", "Ka", "Kama", "Kapil", "Khand", "Kirti", "Kohal", "Lalit", "Man", "Mechi", "Nara", "Pa", "Po", "Pyu", "Raja", "Ram", "Ratna", "Sankhar", "Sanphe", "Taple", "Tri", "Urla"};
    static constexpr std::string_view names10[] = {"bagar", "bari", "dakot", "gadhi", "ganj", "gar", "gram", "hari", "jung", "kha", "khara", "kot", "lamai", "mai", "mak", "nagar", "nepa", "pa", "pur", "rahi", "ran", "riya", "ruwa", "tara", "tari", "thali", "than", "vastu", "wan", "yan", "yuga"};
    static constexpr std::string_view names11[] = {"Ak", "Ba", "Baghe", "Ban", "Bandar", "Bar", "Bari", "Chand", "Chau", "Chaumu", "Chitta", "Co", "Fe", "Gai", "Gopal", "Jamal", "Jhalo", "Jhe", "Jhenai", "Kha", "Khagra", "Lak", "Lakshmi", "Lalmo", "Lalmoni", "Ma", "Munshi", "Na", "Nao", "Nar", "Narsing", "Netro", "Pab", "Patau", "Raj", "Ran", "Sand", "Shat", "Sul", "Tan", "Tha", "Thakur"};
    static constexpr std::string_view names12[] = {"ban", "bandha", "chhari", "dah", "di", "gail", "ganj", "gaon", "gong", "guna", "gunia", "gura", "hani", "hat", "haura", "het", "kati", "khali", "khira", "kona", "lokati", "milla", "mipur", "muhani", "na", "naidah", "ni", "nirhat", "pur", "rail", "sal", "sam", "shahi", "singdi", "wip"};
    static constexpr std::string_view names13[] = {"Dhidh", "Eydha", "Far", "Farukol", "Feli", "Fevah", "Funa", "Hinna", "Hitha", "Hulhu", "Kuda", "Kudahu", "Kulhu", "Kulhudhuf", "Ma", "Magoo", "Mana", "Maro", "Mi", "Mu", "Nai", "Nolhi", "Nolhiva", "Nolhivaran", "Thi", "Thinda", "Ungoo", "Vey", "Veyman", "Vili", "Villi", "Villin"};
    static constexpr std::string_view names14[] = {"badhoo", "dhoo", "dhuffushi", "du", "faaru", "faru", "funadhoo", "fushi", "gili", "goodhoo", "huffushi", "hufunadhoo", "humale", "huvadhoo", "la", "male", "mandhoo", "mandoo", "meedhoo", "mulah", "n", "nadhoo", "navaru", "ranfaru", "roshi", "ru", "shi", "vadhoo", "varanfaru", "varu"};
    static constexpr std::string_view names15[] = {"Ba", "Bar", "Cha", "Che", "Chung", "Dam", "Dip", "Don", "Ga", "Gom", "Gye", "Ha", "Hara", "Hati", "Ka", "Kam", "Kang", "Ken", "Ki", "Kiso", "Lame", "Lhe", "Lob", "Mao", "Mon", "Nai", "Nak", "Ouna", "Pa", "Phi", "Phisu", "Pin", "Pinso", "Ri", "Rung", "Sak", "Sam", "Sar", "Sha", "Shin", "Shing", "Ta", "Tari", "Thim", "Thun", "Tosu", "Tsha", "Tshal", "Tshalu", "Ya"};
    static constexpr std::string_view names16[] = {"be", "bling", "cha", "chap", "cho", "chu", "dada", "dang", "ganka", "gaon", "gar", "gha", "hong", "ka", "kar", "kha", "laika", "lang", "lunang", "maito", "manu", "nakha", "nang", "nig", "pang", "par", "pe", "pero", "phu", "ripe", "sang", "sar", "shong", "sila", "sona", "soperi", "tang", "teng", "tola", "tsa", "tsang", "tse", "tu", "zyung"};

    std::string names; size_t rnd0 = 0; size_t rnd1 = 0; int i = 0;

i = rng() % 16; {
    if (i < 2) {
    rnd0 = rng() % std::size(names1);
    rnd1 = rng() % std::size(names2);
    names = names1[rnd0] + names2[rnd1];
    } else if (i < 4) {
    rnd0 = rng() % std::size(names3);
    rnd1 = rng() % std::size(names4);
    names = names3[rnd0] + names4[rnd1];
    } else if (i < 6) {
    rnd0 = rng() % std::size(names5);
    rnd1 = rng() % std::size(names6);
    names = names5[rnd0] + names6[rnd1];
    } else if (i < 8) {
    rnd0 = rng() % std::size(names7);
    rnd1 = rng() % std::size(names8);
    names = names7[rnd0] + names8[rnd1];
    } else if (i < 10) {
    rnd0 = rng() % std::size(names9);
    rnd1 = rng() % std::size(names10);
    names = names9[rnd0] + names10[rnd1];
    } else if (i < 12) {
    rnd0 = rng() % std::size(names11);
    rnd1 = rng() % std::size(names12);
    names = names11[rnd0] + names12[rnd1];
    } else if (i < 14) {
    rnd0 = rng() % std::size(names13);
    rnd1 = rng() % std::size(names14);
    names = names13[rnd0] + names14[rnd1];
    } else {
    rnd0 = rng() % std::size(names15);
    rnd1 = rng() % std::size(names16);
    names = names15[rnd0] + names16[rnd1];
    }
    return names;
    }
}
