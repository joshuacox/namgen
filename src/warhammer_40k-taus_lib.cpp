#include "warhammer_40k-taus_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_40k_taus_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Aun'El", "Aun'La", "Aun'O", "Aun'Ui", "Aun'Vre", "Fio'El", "Fio'La", "Fio'O", "Fio'Ui", "Fio'Vre", "Kor'El", "Kor'La", "Kor'O", "Kor'Ui", "Kor'Vre", "Por'El", "Por'La", "Por'O", "Por'Ui", "Por'Vre", "Shas'El", "Shas'La", "Shas'O", "Shas'Saal", "Shas'Ui", "Shas'Vre"};
    static constexpr std::string_view names2[] = {"Au'taal", "Bor'kan", "Bork'an", "D'yanoi", "Dal'yth", "Elsy'eir", "Es'Tau", "Fal'shia", "Fi'rios", "Ho'sarn", "Ka'mais", "Ke'lshan", "Ksi'm'yen", "Me'lek", "Mu'gulath", "N'dras", "Pech", "Sa'cea", "Sha'draig", "T'au", "T'olku", "T'ros", "Tash'var", "Tau'n", "Vash'ya", "Velk'Han", "Vespid", "Vior'la"};
    static constexpr std::string_view names3[] = {"Al", "Ar", "Ash", "Bant", "Bra", "Bun", "Dia", "Dor", "Dra", "Fio", "Fir", "Fral", "Gir", "Gra", "Gras", "Har", "Hia", "Hova", "Inio", "Ir", "Irah", "Jax", "Jila", "Jol", "Kes", "Ko", "Krin", "Man", "Mira", "Mon", "Nar", "Nase", "Nori", "Ora", "Orna", "Oxa", "Pax", "Pira", "Prin", "Resh", "Ria", "Ril", "Shase", "Shi", "Sio", "Tor", "Tsu", "Tsua", "Var", "Vra", "Vura", "Wran", "Wua", "Wura", "Xira", "Xo", "Xral"};
    static constexpr std::string_view names4[] = {"'are", "'ath", "'ax", "'bash", "'bin", "'bur", "'dax", "'dis", "'dras", "'elo", "'en", "'erk", "'fa", "'fel", "'fin", "'ga", "'gos", "'gri", "'ha", "'hin", "'hos", "'jash", "'jin", "'jor", "'kir", "'ko", "'kran", "'la", "'las", "'len", "'me", "'min", "'mor", "'na", "'nera", "'nesh", "'or", "'os", "'osh", "'par", "'pin", "'pras", "'ra", "'rak", "'rax", "'sha", "'shash", "'som", "'taga", "'ter", "'tin", "'un", "'ur", "'us", "'vash", "'vax", "'vren", "'wer", "'werd", "'wra", "'xan", "'xil", "'xo", "'yr", "ah", "al", "aln", "an", "ara", "arn", "ash", "ax", "eh", "el", "en", "er", "erra", "es", "esh", "eth", "ina", "ir", "ira", "irn", "irr", "ish", "ith", "ix", "o", "oh", "ol", "om", "on", "or", "ot", "oth", "u", "ug", "un", "ur", "urn", "us", "uth", "ux"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    rnd4 = rng() % std::size(names4);
    names = names1[rnd] + " " + names2[rnd2] + " " + names3[rnd3] + names4[rnd4];
    return names;
    }
}
