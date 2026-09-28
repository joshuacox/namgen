#include "elder_scrolls-argonians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_elder_scrolls_argonians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Alex", "Antigon", "August", "Calig", "Claud", "Demer", "Dioclet", "German", "Her", "Jul", "Ner", "Pil", "Tib", "Asu", "Bun", "Bus", "Cha", "Chi", "Chu", "Chu", "Har", "Hat", "Hee", "Hul", "Huz", "Ine", "Ita", "Mee", "Mil", "Nee", "Oka", "Pee", "Ras", "Ree", "Ree", "See", "Ske", "Tan", "Tee", "Tul", "Uka", "Ula", "Uta", "Wee", "Wee", "Sis", "Yel", "Amu", "Dee", "Gee", "Jee", "Mah", "Otu", "Paj", "Ree", "Sak", "Sal", "Tee", "Tei", "Ush", "Wum", "Yin", "Dee", "Der", "Mad", "Nee", "Ush", "Vee", "Dee", "She", "Tsl", "Asum", "Buni", "Bush", "Chal", "Chiw", "Chul", "Chun", "Hara", "Hath", "Heed", "Hule", "Huze", "Inee", "Itan", "Meer", "Milo", "Neet", "Okaw", "Peer", "Rash", "Reem", "Rees", "Seew", "Skee", "Tana", "Teeg", "Tul", "Ukaw", "Ula", "Utad", "Weel", "Weer", "Siss", "Yeln", "Amus", "Deeh", "Geel", "Jeel", "Mahe", "Otum", "Paje", "Reen", "Sake", "Sali", "Teek", "Tein", "Ushe", "Wume", "Yinz", "Deek", "Derk", "Made", "Neet", "Usha", "Veez", "Deer", "Sheh", "Tsle"};
    static constexpr std::string_view nm2[] = {"meya", "ish", "heeus", "lureel", "wish", "lz", "na", "an", "hei", "dul", "eeya", "ei", "erei", "neen", "raz", "os", "tinei", "wor", "radeeh", "ha", "mukeeus", "sa", "wul", "etul", "an", "gla", "wei", "deek", "ltul", "re", "sithik", "nicin", "sei", "haj", "leesh", "lius", "ei", "meel", "een", "num", "eepa", "iith", "keeus", "naava", "eeja", "eek", "z'k", "kus", "keethus", "esi", "trenaza", "are", "zara", "rkaza", "hsi", "eeixth", "sh", "eeus", "ureel", "ish", "z'r", "a'th", "nee", "ei", "ul", "eya", "il", "sehk", "inei", "adeeh", "akees", "ukeeus", "at", "ul", "tul", "nesh", "la", "ei", "eek", "tul", "ithik", "icin", "ei", "ius", "ieth", "eel", "en", "um", "epa", "ith", "eeus", "aava", "eja", "ek", "k'r", "us", "eethus", "si", "renaza", "ara", "kaza", "s'r", "eixth", "acles", "andros", "ate", "erius", "ian", "iar", "icus", "ides", "ios", "ius", "os", "ula", "us"};
    static constexpr std::string_view nm3[] = {"An", "Bun", "Bar", "Dan", "Effe", "Eleedal", "Gah", "Gam", "Geel", "Haj", "Han", "Heem", "Heir", "Im", "Jeelus", "Jeer", "J'Ram", "Junal", "Keerasa", "Miun", "Mush", "Okan", "Oleen", "Olink", "Reeh", "Silm", "Tee", "Tim", "Vistha", "Wanan", "Wih", "Wud", "Wuleen", "Ah", "Ajum", "Beem", "Dar", "Deetum", "Dreet", "Er", "Geem", "Gin", "Jee", "Jeetum", "Oleed", "Pad", "Tar", "Tun", "Weebam", "Beem", "Brand", "Gulum", "Ilas", "Jaree", "Talen", "Teeba", "Bah"};
    static constexpr std::string_view nm4[] = {"-Zaw", "-Teemeeta", "-Ru", "-Tei", "-Lei", "-Julan", "-Kur", "-Lah", "-Ei", "-Tulm", "-La", "-Zish", "-Kilaya", "-Tei", "-Maht", "-Dar", "-Lei", "-Tan", "-Gei", "-Mere", "-Shei", "-Gei", "-Nur", "-Jah", "-Dar", "-Lan", "-Jush", "-Kai", "-Dum", "-Eius", "-Neeus", "-Shei", "-Malz", "-Kajin", "-Kiurz", "-Jee", "-Ja", "-Ju", "-Lai", "-Teeus", "-Jasaiin", "-Wulm", "-Tah", "-Ze", "-Ei", "-Ei", "-Meena", "-Zeeus", "-Na", "-Ja", "-Shei", "-Ei", "-Tei", "-Ra", "-Jei", "-Ei"};
    static constexpr std::string_view nm5[] = {"Ahah", "Akis", "Bana", "Beek", "Eute", "Gilm", "Gish", "Hule", "Kasa", "Mila", "Naku", "Nees", "Nura", "Nush", "Okur", "Onas", "Shat", "Tash", "Wush", "Beel", "Beew", "Beje", "Deet", "Druj", "Marz", "Nume", "Oche", "Pash", "Rana", "Shal", "Skal", "Wits", "Deej", "Keer", "Shah", "Wuje", "Aha", "Aki", "Ban", "Bee", "Eut", "Gil", "Gis", "Hul", "Kas", "Mil", "Nak", "Nee", "Nur", "Nus", "Oku", "Ona", "Sha", "Tas", "Wus", "Bee", "Bee", "Bej", "Dee", "Dru", "Mar", "Num", "Och", "Pas", "Ran", "Sha", "Ska", "Wit", "Dee", "Kee", "Sha", "Wuj"};
    static constexpr std::string_view nm6[] = {"ht", "sh", "alz", "katan", "ei", "mee", "hee", "ayee", "ah", "uma", "sha", "alg", "h'r", "resh", "sha", "talg", "ha", "ha", "lei", "wos", "een", "tsan", "ja", "z'r", "een", "eeva", "ha", "aye", "leez", "leel", "seidutsei", "ja", "rava", "hvee", "eeta", "tvee", "haz", "lz", "atan", "ila", "hota", "ma", "ha", "lg", "ha", "alg", "aree", "aza", "ei", "os", "en", "san", "araje", "en", "eva", "a", "eez", "eel", "eedutsee", "ayo", "ava", "vee", "eta"};
    static constexpr std::string_view nm7[] = {"Ah", "Am", "An", "Bur", "Chanil", "Cheesh", "Dar", "Deesh", "El", "Ereel", "Gih", "Hal", "Jeed", "Kal", "Keel", "Kud", "Mach", "Meeh", "Meen", "Mim", "Muz", "Nam", "Olank", "On", "Seed", "Seen", "Sheer ", "Tar", "Weedum", "Erh", "Amee", "Aney", "Bour", "Cheenal", "Chesoh", "Dur", "Deeth", "En", "Ereej", "Ginh", "Kahl", "Jid", "Kani", "Kelo", "Kudo", "Meech", "Meefh", "Mereen", "Meem", "Mez", "Nem", "Olink", "Oneer", "Sedir", "Tereen", "Sheef ", "Thari", "Wedum"};
    static constexpr std::string_view nm8[] = {"-Deesei", "-Ei", "-Ja", "-Jeen", "-La", "-Lee", "-Lei", "-Liurz", "-Lurasha", "-Ma", "-Meedish", "-Meema", "-Meena", "-Meesei", "-Meeus", "-Mei", "-Na", "-Neeus", "-Ra", "-Raniur", "-Rei", "-Sa", "-Wan", "-Wazei", "-Deese", "-Eji", "-Jazee", "-Jereen", "-Lari", "-Leef", "-Leith", "-Liruz", "-Lursha", "-Maki", "-Mideesh", "-Meemar", "-Menari", "-Meseif", "-Meefus", "-Meik", "-Nash", "-Nevus", "-Rafee", "-Ranier", "-Reij", "-Kajee", "-Wahn", "-Wareih", "-Deseith", "-Eijar", "-Jarlee", "-Jeleen", "-Lak", "-Leehp", "-Leish", "-Lirzee", "-Leesha", "-Majee", "-Meedish", "-Mena", "-Meeka", "-Meei", "-Neeus", "-Slei", "-Nha", "-Nefeus", "-Rajee", "-Raneer", "-Reiki", "-Sakee", "-Ran", "-Razei"};
    static constexpr std::string_view nm9[] = {"Andro", "Augus", "Ca", "Cae", "Cali", "Gal", "Mag", "Me", "Ni", "Per", "Theo", "Tiber", "Xer", "Andree", "Augees", "Caya", "Caree", "Calee", "Geel", "Nag", "Meree", "Nefe", "Peri", "Thefi", "Tikeer", "Xeir", "Endore", "Agius", "Cas", "Cay", "Cani", "Kay", "Laf", "Pe", "Neeth", "Pehr", "Theer", "Taier", "Xem"};
    static constexpr std::string_view nm10[] = {"cles", "des", "dorus", "gulus", "lus", "mean", "mus", "nes", "sar", "seus", "sion", "ssius", "tus", "calees", "desh", "dorees", "goulus", "lures", "mareen", "museeth", "mesh", "sareth", "sesh", "seene", "seus", "tius", "clesh", "daresh", "deseer", "galus", "leesh", "rean", "marush", "naresh", "sareeth", "teus", "sifon", "silus", "thees"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 6) {
    rnd = rng() % std::size(nm4);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm9);
    rnd4 = rng() % std::size(nm10);
    names = nm5[rnd] + nm6[rnd2] + " " + nm9[rnd3] + nm10[rnd4];
    } else {
    rnd = rng() % std::size(nm7);
    rnd2 = rng() % std::size(nm8);
    rnd3 = rng() % std::size(nm9);
    rnd4 = rng() % std::size(nm10);
    names = nm7[rnd] + nm8[rnd2] + " " + nm9[rnd3] + nm10[rnd4];
    }
    } else {
    if (i < 6) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm9);
    rnd4 = rng() % std::size(nm10);
    names = nm1[rnd] + nm2[rnd2] + " " + nm9[rnd3] + nm10[rnd4];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm9);
    rnd4 = rng() % std::size(nm10);
    names = nm3[rnd] + nm4[rnd2] + " " + nm9[rnd3] + nm10[rnd4];
    }
    }
    return names;
    }
}
