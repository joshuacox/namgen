#include "towns_and_cities-west_african_towns_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_towns_and_cities_west_african_towns_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Ari", "Aribi", "Ba", "Banfo", "Bo", "Boga", "Boro", "Bou", "Dé", "Dédou", "Da", "Dié", "Diébou", "Dia", "Diapa", "Dji", "Do", "Fa", "Ga", "Gaoua", "Gara", "Gayé", "Go", "Goro", "Gou", "Hou", "Ka", "Ki", "Ko", "Koko", "Kombi", "Kongou", "Kou", "Koudou", "Koupé", "Loro", "Mé", "Ma", "Mogte", "Nia", "Nou", "Oro", "Oua", "Ouaga", "Ouahi", "Pa", "Pi", "Pissi", "Po", "Pou", "Pouy", "Réo", "Sé", "Ségué", "Sa", "Sapo", "Se", "Si", "So", "Sole", "Ta", "Te", "Tenko", "Ti", "Tika", "To", "Tou", "Vi", "Ya", "Zi", "Zinia", "Zo"};
    static constexpr std::string_view nm2[] = {"bba", "binda", "bo", "bougou", "chari", "da", "dara", "do", "dogo", "dougou", "fora", "ga", "gan", "gandé", "go", "goloko", "gou", "goussi", "gouya", "gré", "gtedo", "guet", "ka", "karé", "ko", "kodogo", "kologo", "la", "lasso", "lenzo", "lly", "logo", "loko", "lsa", "ma", "mo", "néga", "nénéga", "na", "ndé", "nda", "ndi", "ndou", "nfora", "nga", "ngin", "ngo", "ni", "niaré", "no", "péla", "paga", "peni", "poné", "pouy", "ré", "range", "rcy", "rdié", "rgaye", "rgo", "ri", "rma", "rom", "romo", "ssé", "ssi", "ssila", "ssiri", "sso", "ssouri", "tao", "tchari", "tenga", "tié", "yéri", "ya", "ye"};
    static constexpr std::string_view nm3[] = {"Abo", "Abu", "Ade", "Ago", "Aki", "Akro", "Akwa", "Ango", "Ano", "Anoma", "Apa", "Asa", "Asama", "Ashia", "Axi", "Ba", "Be", "Bego", "Bere", "Bi", "Bibi", "Bibia", "Bo", "Bolga", "Do", "Du", "Dua", "Effi", "Effia", "Eju", "Elmi", "Fo", "Gba", "Ho", "Ka", "Ke", "Ki", "Kinta", "Ko", "Kofo", "Kono", "Kpa", "Ku", "Kuma", "La", "Lashi", "Ma", "Madi", "Mpra", "Mprae", "NAvro", "Na", "Nka", "Nsa", "Nu", "Nya", "Obua", "Odu", "Odupo", "Pre", "Sa", "Sala", "Save", "Se", "Seko", "Sha", "So", "Soma", "Su", "Sunya", "Ta", "Tai", "Tama", "Te", "Techi", "We", "Wi", "Winne", "Ye"};
    static constexpr std::string_view nm4[] = {"ba", "bi", "biana", "biani", "boso", "bu", "chem", "chi", "chiman", "de", "dina", "dua", "fa", "fao", "ffin", "flao", "ga", "go", "gogo", "gona", "goro", "gu", "he", "hoe", "hum", "kese", "kim", "kondi", "krom", "krwa", "kum", "kuma", "kwai", "laga", "le", "loga", "lugu", "ma", "mabu", "male", "man", "mankese", "manya", "masi", "me", "mina", "mpo", "mpong", "na", "nchi", "ndae", "ndi", "ndu", "nga", "ngo", "ngua", "ni", "nkese", "nkpehe", "nkwa", "nloga", "nneba", "nongo", "nta", "ntamp", "ntapo", "nya", "nyo", "pam", "pehe", "po", "pong", "ra", "rekum", "ri", "ridua", "ru", "se", "shibi", "shie", "si", "so", "stea", "tanga", "tapo", "te", "tia", "vrongo", "wam", "we", "wkaw", "wku", "xim", "yani", "yaw", "yow"};
    static constexpr std::string_view nm5[] = {"Ánya", "Ányo", "Aba", "Abe", "Abi", "Aboi", "Adza", "Adzo", "Agbi", "Agbo", "Ba", "Bara", "Bi", "Bia", "Bo", "Bona", "Bou", "Bu", "Buoa", "Da", "Daba", "Dana", "Dano", "Di", "Dimbo", "Do", "Dona", "Dora", "Fa", "Fe", "Ferke", "Fia", "Fou", "Ga", "Ka", "Katio", "Kia", "Kie", "Ko", "Kou", "Ma", "Mana", "Mara", "Mi", "Mia", "Mo", "Mou", "Na", "Nara", "Ni", "Nia", "No", "Odia", "Odie", "Odya", "Ou", "Sé", "Sa", "Sana", "Sano", "Sassa", "Si", "Sia", "Sora", "Sou", "Té", "Ta", "Ti", "Tia", "Tou", "Ya", "Yamou"};
    static constexpr std::string_view nm6[] = {"ba", "bakala", "bokro", "bou", "bré", "dané", "dara", "diala", "diali", "djan", "dougou", "doukou", "dro", "dzopé", "flé", "fré", "fra", "gba", "gnoa", "go", "gourou", "guéla", "gu", "ha", "houé", "hou", "ké", "kala", "kessé", "kiala", "kiali", "kou", "kouma", "kro", "la", "li", "lle", "loa", "mé", "ma", "mbokro", "né", "na", "nané", "naré", "ndré", "ndra", "nfra", "ng", "nné", "nyama", "pé", "rahoué", "rhoga", "rhogo", "rou", "sam", "ssé", "ssam", "ssiam", "sso", "ssoukro", "tala", "tiola", "to", "vo"};
    static constexpr std::string_view nm7[] = {"Ba", "Bama", "Bandia", "Bgui", "Bla", "Bou", "Dié", "Di", "Dioï", "Dio", "Dje", "Doue", "Fé", "Fa", "Ga", "Gao", "Gla", "Go", "Gou", "Gui", "Ka", "Kadio", "Kala", "Kanga", "Kara", "Ki", "Ko", "Kolo", "Koro", "Kou", "Koulo", "Kouma", "Kounia", "Kourou", "Kouta", "Koutia", "Ma", "Massi", "Mo", "Ni", "Nio", "No", "Oue", "Ouele", "Pe", "Pele", "Sé", "Sa", "Si", "Sika", "So", "Soma", "Té", "Téme", "Téne", "To", "Tombou", "Tou", "Trou", "Wa", "Wassou", "Yé", "Yéli", "Ya", "Yanfo", "Yo", "Yoro", "You"};
    static constexpr std::string_view nm8[] = {"ba", "bancoro", "bougou", "ctou", "da", "dal", "dam", "diéba", "di", "diagara", "diolo", "dougou", "folila", "gara", "gou", "goumbé", "gouni", "gui", "kani", "kary", "kasso", "kiary", "kidi", "ko", "koro", "koto", "kou", "la", "lesse", "likoro", "lila", "lo", "lou", "ma", "mako", "mané", "mantou", "mbé", "né", "na", "ncoro", "ndé", "ndam", "ndiéba", "neda", "nenkou", "ngaba", "ngana", "ni", "niaka", "nikoto", "nka", "nkidi", "nkou", "nné", "no", "ntou", "ntza", "pti", "ré", "ra", "ran", "rem", "ri", "ro", "rosso", "ry", "ssigui", "sso", "ta", "tao", "ti", "tiala", "to", "tou", "ya", "yes"};
    static constexpr std::string_view nm9[] = {"Aba", "Ade", "Aderbi", "Aga", "Akou", "Aou", "Assa", "Asso", "Ayou", "Ba", "Bale", "Bi", "Bo", "Bou", "Ché", "Chéti", "Che", "Da", "Daba", "Dako", "Di", "Dia", "Diago", "Dogo", "Fa", "Fi", "Fili", "Ga", "Gawe", "Gaya", "Gou", "Goudou", "Gue", "Gui", "Guidi", "Ife", "Illé", "Ka", "Kablé", "Kela", "Ko", "Koro", "La", "Lamo", "Maï", "Ma", "Mada", "Maga", "Malba", "Mara", "Mata", "Maya", "Mi", "N'gou", "Ngue", "Nia", "Oua", "Sa", "Sou", "Té", "Ta", "Takie", "Tchi", "Tchiro", "Te", "Tegguia", "Ti", "Tilla", "Zi"};
    static constexpr std::string_view nm10[] = {"béri", "baga", "balak", "bissinat", "bléwa", "bnou", "bounou", "chi", "dé", "da", "dama", "dan", "daoua", "deras", "dez", "dimouni", "douré", "doutchi", "ffa", "ga", "gadez", "garia", "gmi", "gorou", "guié", "guiada", "hane", "houa", "kérou", "kam", "kieta", "kka", "koro", "la", "labéri", "lak", "lakam", "lbaza", "lingué", "llam", "llo", "lma", "lmi", "ma", "makka", "mari", "maria", "mey", "meye", "mia", "mordé", "né", "nat", "nder", "ndoutchi", "ne", "ngou", "ngué", "ni", "nkari", "nni", "nou", "nout", "ré", "ra", "radi", "ras", "rdé", "rgui", "ri", "ria", "rine", "rlit", "rma", "rni", "roa", "rohane", "rou", "roua", "rouane", "rria", "rti", "saoua", "ssaoua", "ssinat", "sso", "ssodé", "ta", "tameye", "tchi", "timari", "wa", "weye", "ya", "yahi", "yara", "ye", "yourou", "zérina", "za", "zine"};
    static constexpr std::string_view nm11[] = {"Aba", "Abaka", "Abeo", "Age", "Aku", "Asa", "Bau", "BeBeni", "Bi", "Bu", "Ca", "Cala", "Du", "Eke", "Enu", "Go", "Gu", "Iba", "Ike", "Iko", "Ilo", "Ira", "Ja", "Jali", "Ji", "Jime", "Jo", "Ka", "Kadu", "Katsi", "Ku", "Kuma", "La", "Lago", "Lo", "Loko", "Ma", "Mai", "Maidu", "Maku", "Mi", "Nsu", "Oga", "Ogami", "Ogbo", "Oke", "Oni", "Orlu", "Oro", "Osho", "Owe", "Owo", "Oyo", "Po", "Poti", "So", "Soko", "Su", "Sule", "Umua", "Uyo", "Wa", "Wu", "Wuka", "Ye", "Yena", "Yo", "Yola", "Za"};
    static constexpr std::string_view nm12[] = {"ba", "badan", "bar", "basi", "biji", "buja", "chi", "dan", "duguri", "duna", "fe", "fia", "gbiji", "gbo", "ge", "gege", "goa", "gos", "gu", "guri", "hia", "ja", "ji", "kaliki", "kari", "keja", "kene", "ket", "ki", "kka", "koja", "kot", "koto", "kpene", "kurdi", "kure", "kuta", "la", "laba", "leka", "liki", "lingo", "lorin", "mariya", "mbe", "meta", "minana", "moso", "na", "nagoa", "nana", "ne", "ngo", "nin", "nna", "no", "nugu", "rdu", "ri", "ria", "rin", "riya", "rlu", "rnin", "ron", "rri", "ru", "saba", "sau", "si", "skum", "so", "ta", "to", "tse", "tsha", "tsina", "ya", "yi", "yo"};
    static constexpr std::string_view nm13[] = {"Ba", "Bi", "Bigno", "Da", "Daga", "Daka", "Damnia", "Diou", "Fa", "Fati", "Go", "Gossa", "Gou", "Gui", "Guingui", "Ké", "Kébé", "Kédou", "Ka", "Kane", "Kao", "Kaya", "Kho", "Ko", "Koa", "Kou", "Lé", "La", "Lao", "Li", "Lou", "Mé", "M'Bou", "Ma", "Mata", "Mba", "Mbo", "Né", "Na", "Ndiou", "Ngué", "Nio", "Ou", "Pa", "Pao", "Pou", "Ri", "Rufi", "Sé", "Sébi", "Sa", "Sara", "Sata", "So", "Soko", "Ta", "Tamba", "Thiè", "Thia", "Ti", "Tivaoua", "Tou", "Vé", "Véli", "Za", "Zao", "Zi", "Zigui"};
    static constexpr std::string_view nm14[] = {"bémer", "ba", "bacou", "cké", "counda", "dhiou", "diaye", "dio", "diouth", "domp", "dougou", "ffri", "ffrine", "frine", "ga", "gana", "gheul", "gnona", "gou", "guére", "gui", "guinéo", "guin", "hra", "kar", "kel", "khé", "kho", "khokh", "khota", "khotane", "ko", "kone", "lack", "lda", "linga", "mbey", "mbole", "mer", "mnia", "néo", "na", "nchor", "nda", "ne", "nel", "ngara", "ngheul", "nguére", "niadio", "nona", "que", "ra", "rbel", "re", "rine", "ro", "sas", "sque", "ssas", "tam", "tane", "tick", "vaouane", "yar", "ye"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

    /* Burkina Faso */
    /* Ghana */
    /* Ivory Coast */
    /* Mali */
    /* Niger */
    /* Nigeria */
    /* Senegal */
i = rng() % 14; {
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
    } else {
    rnd = rng() % std::size(nm13);
    rnd2 = rng() % std::size(nm14);
    names = nm13[rnd] + nm14[rnd2];
    }
    return names;
    }
}
