#include "world_of_warcraft-draenei_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_world_of_warcraft_draenei_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Aho", "Ak", "Ar", "Art", "Az", "Beh", "Beho", "Bra", "Bran'", "Bre", "Cae", "Caed", "Cem", "Dek", "Der", "Dere", "Dran'", "Du", "Dug", "Eoc", "Fal", "Fan", "Fin", "Fun", "Ga", "Gan", "Han", "Har", "Hob", "Hoba", "Iz", "Jov", "Kav", "Kel", "Kha", "Kil", "Luc", "Ma", "Mah", "Maho", "Mu", "Mua", "Nah", "Naho", "Nob", "Nobu", "Oc", "Ock", "On", "Os", "Rem", "Ste", "Tal", "Tho", "Tor", "Tora", "Toral", "Uz", "Vel", "Vel'", "Ven", "Vor", "Yil"};
    static constexpr std::string_view nm2[] = {"g", "n", "ph", "f", "r", "t", "h", "d", "m", "ga", "na", "pha", "fa", "ra", "ta", "ha", "da", "ma", "go", "no", "pho", "fo", "ro", "to", "ho", "do", "mo", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm3[] = {"aam", "aan", "ag", "aid", "allius", "allus", "alus", "am", "an", "anaar", "anos", "ard", "as", "at", "ath", "co", "daan", "diir", "ed", "el", "en", "fik", "iir", "il", "in", "ir", "iru", "is", "khen", "lac", "lag", "lat", "liir", "lir", "luun", "mat", "miir", "miis", "mir", "mis", "mos", "naar", "nan", "niir", "nis", "ogg", "omat", "onan", "ord", "orhan", "oth", "ras", "red", "tun", "ul", "undo", "uun"};
    static constexpr std::string_view nm4[] = {"Aal", "Ael", "Aelle", "Aello", "Aev", "Aeva", "Aeve", "Al", "Alta", "Av", "Ava", "Ave", "Ba", "Bet", "Bel", "Bil", "Cuz", "Ed", "Edi", "Edir", "Ego", "El", "Elle", "Ello", "En", "Er", "Ere", "Far", "Fe", "Fin", "Go", "Gor", "Got", "Haf", "Hafe", "Ir", "Ire", "Ires", "Is", "Ja", "Jael", "Jal", "Ji", "Jol", "Kha", "Kaz", "Lun", "Luna", "Ma", "Mah", "Mam", "Mer", "Mes", "Mi", "Mia", "Mo", "Mom", "Mon", "Mu", "Muh", "Mum", "Mus", "Ne", "Nes", "Nur", "Nurg", "Nus", "Pha", "Phae", "Phe", "Rem", "Reme", "Ruk", "Se", "Ses", "Si", "Sul", "Thel", "Thela", "Tre", "Tri", "Um", "Ura", "Val", "Valu"};
    static constexpr std::string_view nm5[] = {"b", "ba", "be", "bo", "d", "da", "de", "do", "h", "ha", "he", "ho", "la", "le", "lo", "r", "ra", "re", "ro", "s", "sa", "se", "so", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm6[] = {"aan", "al", "all", "ally", "araa", "ca", "dine", "ela", "elle", "elli", "era", "ere", "ett", "ette", "gin", "guni", "haa", "hi", "hri", "in", "ine", "irah", "kua", "la", "laa", "laana", "lae", "laena", "lun", "mae", "mena", "mere", "mis", "mon", "nii", "nora", "oh", "ora", "raa", "rah", "ran", "ret", "rette", "ri", "rii", "rua", "sa", "stra", "straa", "taa", "ti", "tia", "tra", "traa", "ua", "un", "uni", "zi"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm4);
    rnd2 = rng() % std::size(nm5);
    rnd3 = rng() % std::size(nm6);
    names = nm4[rnd] + nm5[rnd2] + nm6[rnd3];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3];
    }
    return names;
    }
}
