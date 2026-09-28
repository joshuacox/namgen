#include "mass_effect-asaris_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_mass_effect_asaris_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Ae", "Ai", "Aj", "Al", "Am", "An", "Ar", "As", "Ash", "A", "Ba", "Bat", "Ben", "Be", "Bi", "Ce", "Che", "Cha", "Ce", "Da", "De", "Di", "Ea", "El", "Em", "En", "Er", "Fa", "Fal", "Fre", "Ge", "Gel", "Gen", "Gi", "Gla", "He", "Hi", "Hol", "Ho", "In", "Ir", "Im", "Is", "Ish", "Esh", "Es", "Hal", "Hel", "Ja", "Jal", "Jan", "Je", "Jen", "Jes", "Ji", "Jin", "Jon", "Jos", "Ka", "Kal", "Kas", "Kash", "Kel", "Ke", "Kes", "Ki", "Kin", "La", "Le", "Len", "Let", "Li", "Lid", "Lin", "Lim", "Lis", "Lu", "Luc", "Ly", "Lys", "Lyn", "Lym", "Ma", "Mal", "May", "Mir", "Mi", "Mo", "Mor", "My", "Myr", "Na", "Nar", "Nas", "Ni", "Nir", "No", "Nor", "Nos", "Nis", "Nu", "Nul", "Num", "Ny", "Nyx", "Myx", "Pe", "Pen", "Pha", "Phe", "Pho", "Po", "Por", "Pri", "Ra", "Ran", "Rev", "Ri", "Ril", "Sa", "Sal", "Sam", "San", "Sar", "Sas", "Sash", "Se", "Sel", "Sey", "Shi", "Sha", "She", "Si", "Sta", "Su", "Sul", "Ta", "Tal", "Tar", "Te", "Tel", "Tes", "Tev", "Tre", "Un", "Um", "Us", "Ush", "Va", "Val", "Ve", "Vey", "Vi", "Vis", "Vo", "Von", "Xa", "Xan", "Ya", "Ye", "Ze", "Zel", "Zen", "Zem"};
    static constexpr std::string_view nm2[] = {"'da", "'ir", "'ko", "'li", "'me", "'mo", "'na", "'ne", "'no", "'phi", "'ra", "'sa", "'sha", "'ya", "a", "aki", "al", "an", "ana", "any", "ar", "ara", "ari", "arv", "ass", "ava", "ay", "edra", "eem", "een", "ees", "eez", "eka", "el", "eld", "ell", "els", "enth", "er", "es", "ese", "ess", "est", "et", "ey", "ez", "ezi", "fin", "ga", "i", "ia", "if", "ife", "il", "in", "ina", "ira", "is", "iss", "ith", "ix", "iy", "iz", "ler", "li", "lik", "ly", "me", "oll", "or", "ora", "os", "ova", "ra", "ri", "ry", "tha", "thy", "uc", "uci", "ul", "um", "un", "yr", "yx", "yxa", "yxe"};
    static constexpr std::string_view nm3[] = {"a", "da", "e", "es", "ga", "h", "hin", "ha", "ir", "is", "ka", "la", "lea", "ley", "lia", "ly", "ma", "me", "mea", "mey", "mia", "na", "ne", "nea", "nia", "ny", "o", "phea", "phia", "ra", "rae", "sa", "se", "sha", "shi", "sy", "ta", "te", "tea", "thea", "thia", "tia", "u", "us", "ux", "vi", "ya", "ze", "zea", "zia", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm4[] = {"Arte", "Ate", "Atru", "Ave", "Be", "Ca", "Cale", "Cali", "Coni", "Corli", "D'a", "D'bie", "D'cori", "D'ky", "D'la", "D'lina", "D'na", "D'ra", "D'ria", "D'ro", "D'rone", "D've", "D'yse", "Da", "Dali", "Danti", "Di", "Ditri", "Dri", "Eda", "Edo", "Ga", "Gade", "He", "Heli", "Ia", "Ialli", "Ie", "Iessa", "Iessi", "Ja", "Jani", "Janni", "Jannu", "Janu", "Ke", "Ky", "Kya", "Le", "Leda", "Li", "Lo", "M'cry", "M'do", "M'ja", "M'ki", "M'kya", "M'lio", "M'lo", "M'pri", "M'ta", "M'to", "Ma", "Mai", "Make", "Mato", "Me", "Mere", "Mi", "Mo", "Mora", "Mu", "Mura", "My", "Myra", "No", "Nura", "Pe", "Pesa", "Pra", "Ra", "Radi", "Ru", "Sa", "Sabu", "Se", "Sede", "Sha", "Shi", "Ska", "T'ne", "T'da", "T'do", "T'ea", "T'er", "T'es", "T'go", "T'ha", "T'ka", "T'ke", "T'lo", "T'me", "T'mi", "T'mo", "T'na", "T'ne", "T'pe", "T'ra", "T'rao", "T're", "T'sa", "T'sca", "T'so", "T'va", "T've", "T'ze", "tha", "thani", "thano", "V'cri", "V'do", "V'la", "V'mo", "V'na", "V'ti", "Va"};
    static constexpr std::string_view nm5[] = {"ala", "ana", "ara", "ari", "ava", "buro", "ci", "do", "dri", "eri", "fi", "ios", "is", "ius", "ix", "jah", "jin", "la", "las", "li", "lis", "lyt", "mi", "na", "ni", "nis", "nus", "or", "ora", "os", "qua", "ra", "ran", "re", "rev", "ri", "ria", "ris", "rix", "ro", "ros", "rus", "san", "sava", "se", "shi", "si", "sir", "sus", "tari", "te", "tis", "to", "tora", "us", "va", "ve", "vius", "vo", "vus", "yma", "yne", "za", "ze", "zea", "zor"};

    std::string names; size_t rnd = 0; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd1 = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd1] + nm3[rnd2] + " " + nm4[rnd3] + nm5[rnd4];
    return names;
    }
}
