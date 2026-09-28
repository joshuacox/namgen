#include "towns_and_cities-north_european_towns_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_towns_and_cities_north_european_towns_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Aal", "Aar", "Alberts", "Balle", "Birke", "Brønd", "Copen", "Es", "Glad", "Glo", "Hørs", "Hader", "Hel", "Her", "Hille", "Hjør", "Hol", "Holste", "Hor", "Hvido", "Kol", "Lyng", "Næst", "Nørre", "Rødo", "Ring", "Ros", "Sønder", "Silke", "Sla", "Svend", "Tårn", "Taa", "Vi"};
    static constexpr std::string_view nm2[] = {"bæk", "bæka", "berga", "bjerg", "borg", "bya", "gelse", "hagen", "havn", "holm", "hus", "kilde", "leva", "lunda", "nse", "rød", "ring", "rupa", "saxea", "sens", "singør", "slev", "sted", "strup", "strupa", "sundby", "ve", "ved", "vrea"};
    static constexpr std::string_view nm3[] = {"Ab", "Ant", "El", "Haap", "Jõge", "Jõh", "Kär", "Kal", "Kar", "Keh", "Kei", "Ki", "Kiviõ", "Koht", "Kun", "Kure", "Li", "Lihu", "Lok", "Mõisa", "Maar", "Must", "Nar", "Ote", "Pär", "Põl", "Pai", "Pal", "Rä", "Räpi", "Rak", "Rap", "Silla", "Sin", "Suur", "Tõr", "Tü", "Ta", "Tal", "Tam", "Tar", "Võ", "Võh", "Val", "Vil"};
    static constexpr std::string_view nm4[] = {"de", "di", "diski", "duu", "ga", "geva", "hula", "ja", "jandi", "küla", "la", "lamäe", "li", "lin", "lingi", "linn", "luoja", "mäe", "ma", "me", "mme", "na", "ngi", "nu", "pää", "pa", "pina", "ra", "ri", "ru", "sa", "saare", "salu", "samaa", "si", "ski", "ssaare", "ssi", "ste", "suu", "tu", "va", "vee", "vere", "viõli", "vi"};
    static constexpr std::string_view nm5[] = {"Ääne", "Ähtä", "Ala", "Hämeen", "Ha", "Haapa", "Han", "Harja", "Hauki", "Hei", "Hel", "Hui", "Hy", "Iisal", "Ikaa", "Ima", "Jäm", "Järven", "Joen", "Juan", "Jyväs", "Ka", "Kaa", "Kala", "Kan", "Kankaan", "Kark", "Kas", "Kau", "Kauha", "Ke", "Kemi", "Kera", "Keu", "Ki", "Kiure", "Kok", "Koke", "Kot", "Kou", "Kuh", "Kuo", "Kuri", "Kuu", "La", "Lah", "Lai", "Lappeen", "Liek", "Lo", "Loh", "Loi", "Män", "Mik", "När", "Naan", "Ni", "Nil", "No", "Nur", "Ori", "Orima", "Ou", "Outo", "Pa", "Pai", "Par", "Piek", "Pietar", "Pro", "Pudas", "Pyhä", "Raase", "Rai", "Riihi", "Rova", "Saari", "Sasta", "Savon", "Seinä", "Siu", "So", "Suonen", "Tam", "Tor", "Tur", "Ul", "Ussi", "Uusikau", "Valkea", "Van", "Var", "Viita", "Ylö", "Yli"};
    static constexpr std::string_view nm6[] = {"hamina", "hava", "järvi", "joki", "kää", "kano", "kaupunki", "keli", "kia", "kila", "kinen", "ko", "kola", "koski", "ksa", "kumpu", "kylä", "lepyy", "linen", "linna", "mäki", "mi", "mina", "ni", "niemi", "nkää", "nola", "ntio", "pää", "piö", "pio", "pori", "pua", "pudas", "pula", "punki", "rainen", "ranta", "rava", "ri", "rina", "ruu", "sä", "sämäki", "saari", "siä", "sinki", "ssa", "suu", "tali", "tee", "tila", "tinen", "tra", "ttila", "ttinen", "vala", "valta", "vesi", "vieska", "viisa", "voo", "vus"};
    static constexpr std::string_view nm7[] = {"Álf", "Árbæjar", "Ísaf", "Ólafs", "Þórs", "Þin", "Þorláks", "Ak", "Aku", "Bíldu", "Búðar", "Bakka", "Bi", "Blön", "Bolungar", "Borgar", "Brúnah", "Brautar", "Breiðdals", "Byggðak", "Dal", "Djúpi", "Drang", "Eglis", "Eskif", "Eyrar", "Fjalla", "Garða", "Grím", "Greni", "Grinda", "Grundar", "Hó", "Hól", "Húsa", "Haf", "Hafnar", "Helli", "Hnífs", "Hof", "Hrí", "Hraf", "Hua", "Hvamm", "Hvan", "Hvera", "Hvols", "Inn", "Kópa", "Kópas", "Kefla", "Krist", "Lóns", "Lauga", "Laugar", "Lit", "Melah", "Mosfells", "Nesjah", "Neskau", "Nja", "Patreks", "Raufar", "Reyk", "Sól", "Sand", "Sauðár", "Sel", "Seltjar", "Seyðis", "Skaga", "Stok", "Stuk", "Sval", "Tálkna", "Tjarna", "Varmah", "Vest", "Vopna"};
    static constexpr std::string_view nm8[] = {"tanes", "verfi", "jarhverfi", "fjörður", "vík", "höfn", "nes", "reyri", "dalur", "röst", "duós", "nesi", "nes", "líð", "holt", "jarni", "vogur", "snes", "staðir", "bakki", "bær", "byggð", "ðir", "ður", "sey", "verfi", "nir", "ganes", "sandur", "ssandur", "dalur", "sós", "nagil", "stangi", "neyri", "gerði", "völlur", "nes", "sker", "vogur", "lavik", "klaustur", "reykir", "rás", "garás", "vatn", "sandur", "verfi", "firði", "staður", "lækur", "höfn", "hólar", "holt", "jahlíð", "javík", "heimar", "vík", "gerði", "krókur", "foss", "narnes", "strönd", "seyri", "hólmur", "reyri", "seyri", "naeyjar"};
    static constexpr std::string_view nm9[] = {"Ai", "Aiz", "Ak", "Akni", "Alo", "Alu", "Aluk", "Ba", "Bal", "Baus", "Bro", "Ce", "Ces", "Dag", "Daugav", "Do", "Dur", "Es", "Gro", "Gul", "Ik", "Iluk", "Jaun", "Jekab", "Jel", "Jur", "Kan", "Kar", "Ke", "Kras", "Kul", "Li", "Lie", "Liel", "Ligat", "Lim", "Lu", "Lud", "Ma", "Maz", "Ol", "Pavi", "Pla", "Prei", "Prie", "Rezek", "Ri", "Ru", "Rujie", "Sa", "Sabi", "Sal", "Sala", "Salac", "Saul", "Se", "Si", "Skrun", "Smil", "Stai", "Sten", "Stren", "Su", "Tal", "Tu", "Val", "Valdemar", "Van", "Varak", "Vents", "Vi", "Vie", "Zi"};
    static constexpr std::string_view nm10[] = {"škile", "baži", "bana", "bate", "bazi", "be", "bele", "bile", "bina", "ca", "cele", "ceni", "cut", "da", "dava", "dona", "done", "dus", "gaži", "ga", "gava", "gazilani", "gda", "griva", "gulda", "gums", "ja", "jiena", "kile", "kne", "kraukle", "ksne", "kste", "kule", "kums", "laca", "laine", "lava", "li", "loži", "losta", "lozi", "lsi", "lupe", "lvi", "mala", "miera", "naži", "na", "nas", "nazi", "nci", "nda", "nde", "niste", "paja", "pils", "pute", "salaca", "sava", "sis", "site", "ska", "skile", "sne", "sta", "tene", "tne", "vaine", "vani", "vinas", "za", "zekne"};
    static constexpr std::string_view nm11[] = {"Šak", "Šal", "Šed", "Šiaul", "Šil", "Šir", "Šven", "Žag", "Žiež", "Ak", "Al", "Anyk", "Ario", "Bal", "Bir", "Daug", "Drus", "Duk", "Duset", "Ežer", "Eišis", "Elek", "Gar", "Garg", "Gel", "Grig", "Ignal", "Jiez", "Jon", "Jur", "Kaiš", "Kal", "Kaun", "Kavar", "Kaz", "Kedain", "Kel", "Klai", "Kret", "Kudir", "Kupiš", "Kur", "Kybar", "Laz", "Lent", "Lin", "Mažeik", "Marij", "Mol", "Nauj", "Ne", "Nemen", "Obel", "Pab", "Pag", "Pak", "Pal", "Pan", "Panem", "Panev", "Pas", "Plun", "Prie", "Rad", "Ramy", "Rasein", "Riet", "Rokiš", "Rudiš", "Sal", "Sed", "Sim", "Skaud", "Skuod", "Smal", "Subac", "Taur", "Tel", "Trak", "Troš", "Tytu", "Už", "Uk", "Ut", "Vabal", "Var", "Ven", "Ver", "Vie", "Viek", "Vies", "Vil", "Vir", "Visa", "Zara"};
    static constexpr std::string_view nm12[] = {"šciai", "šenai", "šiadorys", "šiai", "škelis", "škes", "škis", "škunai", "šniai", "štas", "štona", "žai", "ždai", "žys", "balis", "barkas", "brade", "cine", "cininkai", "cioneliai", "cionys", "cius", "da", "das", "delus", "dijai", "dorys", "duva", "gai", "gala", "gara", "giai", "ginas", "jai", "jis", "joji", "kai", "kas", "kiai", "kija", "kininkai", "kis", "kos", "kruojis", "kule", "kuva", "lale", "lantai", "liškis", "liai", "liava", "lina", "lis", "lute", "mariai", "me", "mene", "merge", "mune", "na", "nai", "nas", "neliai", "nga", "nge", "niai", "ninka", "ninkai", "ninkas", "nius", "nta", "peda", "pole", "rage", "relis", "rena", "rkas", "rtai", "sai", "siejai", "skas", "skes", "tai", "tavas", "tena", "tinga", "toji", "tos", "trenai", "tus", "va", "valus", "varija", "varis", "vas", "vežys", "venai", "ventis", "viškis", "vile", "viliškis", "vintos", "vis", "zlu", "znas"};
    static constexpr std::string_view nm13[] = {"Åkre", "Åle", "Åndal", "Åsgård", "Aren", "As", "Brønnøy", "Bre", "Brek", "Brumund", "Drø", "Eger", "El", "Fager", "Far", "Finn", "Flekke", "Fos", "Gjø", "Grim", "Høne", "Hal", "Hammer", "Har", "Hauge", "Hokk", "Holme", "Holms", "Honning", "Hvit", "Jørpe", "Kirke", "Kolve", "Kongs", "Koper", "Lange", "Lar", "Leir", "Lek", "Lille", "Lung", "Man", "Mol", "Mos", "Nam", "Nar", "Notod", "Or", "Os", "Pors", "Rju", "Søg", "Sand", "Sande", "Sarps", "Seter", "Skudenes", "Sogn", "Sort", "Sta", "Stat", "Stein", "Stjørdals", "Tøns", "Trom", "Trond", "Ulstein", "Vad", "Var", "Vennes", "Verdal"};
    static constexpr std::string_view nm14[] = {"bak", "berg", "bu", "dal", "den", "fest", "fjord", "foss", "grunn", "halsen", "hammer", "hamn", "heim", "helle", "jøen", "kan", "kanger", "kenes", "kim", "kjer", "land", "nes", "reid", "ros", "rum", "søor", "søra", "sand", "ske", "sla", "snes", "sos", "stad", "strøm", "strand", "sund", "våg", "vanger", "verg", "vern", "vik", "vinger"};
    static constexpr std::string_view nm15[] = {"Ängel", "Ål", "Ö", "Öre", "Öst", "Öster", "Aling", "Ar", "Asker", "Båt", "Berg", "Björn", "Boll", "Bor", "Borg", "Dag", "Djurs", "Ek", "En", "Eskil", "Fager", "Falken", "Falster", "Fin", "Fol", "Gamle", "Gammal", "Gothen", "Grön", "Gran", "Härnö", "Hässle", "Höga", "Hag", "Halm", "Hapar", "Havs", "Helsing", "Hem", "Hudiks", "Husk", "Jön", "Karl", "Karls", "Kram", "Kungs", "Kväll", "Lands", "Lid", "Lin", "Lindes", "Lud", "Lyck", "Lyse", "Mar", "Marie", "Mjöl", "Norr", "Ny", "Nynä", "Oskar", "Oxelö", "Söder", "Sölves", "Sand", "Sig", "Simri", "Skän", "Ske", "Skog", "So", "Stock", "Ström", "Sundby", "Sunds", "Tida", "Tors", "Träd", "Udde", "Ulrice", "Upp", "Väners", "Väst", "Väster", "Vad", "Vagn", "Var", "Vax", "Vet", "Vummer"};
    static constexpr std::string_view nm16[] = {"backa", "berg", "bo", "borg", "bro", "burg", "by", "dal", "fed", "fors", "gård", "grund", "hälla", "härad", "hättan", "hall", "hammar", "hamn", "holm", "köping", "kil", "koga", "krona", "länge", "land", "landa", "llefteå", "näs", "sås", "sand", "sele", "shamn", "sjö", "stad", "strand", "stuna", "sun", "sund", "tälje", "torp", "tuna", "vall", "valla", "vik", "viken"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

    /* Denmark */
    /* Estonia */
    /* Finland */
    /* Iceland */
    /* Latvia */
    /* Lithuania */
    /* Norway */
    /* Sweden */
i = rng() % 16; {
    if (i < 2) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2];
    } else if (i < 4) {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    names = nm3[rnd] + nm4[rnd2];
    } else if (i < 6) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2];
    } else if (i < 8) {
    rnd = rng() % std::size(nm7);
    rnd2 = rng() % std::size(nm8);
    names = nm7[rnd] + nm8[rnd2];
    } else if (i < 10) {
    rnd = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm10);
    names = nm9[rnd] + nm10[rnd2];
    } else if (i < 12) {
    rnd = rng() % std::size(nm11);
    rnd2 = rng() % std::size(nm12);
    names = nm11[rnd] + nm12[rnd2];
    } else if (i < 14) {
    rnd = rng() % std::size(nm13);
    rnd2 = rng() % std::size(nm14);
    names = nm13[rnd] + nm14[rnd2];
    } else {
    rnd = rng() % std::size(nm15);
    rnd2 = rng() % std::size(nm16);
    names = nm15[rnd] + nm16[rnd2];
    }
    return names;
    }
}
