#include "rift-dwarfs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_rift_dwarfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names1_1[] = {"Ale", "Ali", "A", "Ba", "Bari", "Be", "Bi", "Bise", "Bo", "Bohu", "Bori", "Boza", "Bra", "Brani", "Bre", "Bro", "Da", "Dani", "Dari", "De", "Deni", "Dobri", "Do", "Dobro", "Dra", "Draga", "Draho", "Du", "Dusa", "Eli", "Ela", "Go", "Gora", "Gro", "Gra", "Ida", "Iva", "Ja", "Jani", "Jale", "Jase", "Jele", "Ka", "Kali", "Ke", "La", "Le", "Li", "Ma", "Mali", "Me", "Meli", "Mi", "Mila", "Mile", "Miru", "Mo", "Mora", "Ne", "Neve", "O", "Ole", "Ra", "Radi", "Ro", "Rosi", "Ru", "Rumi", "Se", "Sta", "Stani", "Suda", "Su", "Ti", "Tiha", "Tu", "Va", "Ve", "Veli", "Bo", "Borghi", "Bry", "Ei", "Fre", "Ge", "Gri", "Gro", "Gu", "Hei", "Hi", "Hu", "Na", "Sa", "Si", "Ska", "Sva", "Ve"};
    static constexpr std::string_view names2_1[] = {"bla", "bra", "briana", "bromira", "dana", "dandi", "dania", "danka", "dda", "dka", "dmila", "domia", "domira", "drana", "drun", "duna", "dunn", "ga", "gana", "gdana", "ghild", "ghildr", "gna", "gny", "grun", "ha", "hana", "hild", "hildr", "homira", "humira", "jana", "kadi", "ksana", "kuld", "lana", "lda", "ldr", "lena", "lenka", "lica", "lika", "lina", "linka", "lmira", "mbla", "mena", "mhild", "mhildr", "miana", "mila", "mira", "na", "nca", "nhild", "nhildr", "nia", "nica", "nika", "nimira", "nka", "nna", "nuska", "ra", "rana", "ranka", "rdandi", "reyja", "ria", "riana", "rid", "rigg", "rina", "rinka", "ritza", "rka", "rmila", "romira", "runa", "ruska", "rvara", "rya", "rzanna", "sana", "senka", "sera", "serka", "sica", "ska", "tka", "tza", "vana", "vara", "vena", "venka", "zana", "zanna", "zda", "zdana", "zena", "zhana", "zka"};
    static constexpr std::string_view names1_2[] = {"Ba", "Be", "Bi", "Bla", "Bo", "Bogo", "Bohu", "Boji", "Bozhi", "Bozi", "Bra", "Bre", "Bu", "Budi", "Buri", "Ca", "Casi", "Da", "Dali", "De", "Di", "Do", "Dobro", "Dra", "Fre", "Ga", "Go", "Gode", "Gra", "Gro", "Gu", "Ja", "Jaro", "Ka", "Kazi", "Kra", "Krasi", "Kre", "Kresi", "Lo", "Lu", "Lubo", "Ludo", "Ma", "Mi", "Milo", "Mo", "Nja", "Njo", "O", "Ode", "Odi", "Ogni", "Orva", "Pa", "Pre", "Pro", "Ra", "Radi", "Rado", "Si", "Sta", "Stani", "Straa", "Tho", "Ty", "Va", "Ve", "Veli", "Vi", "Volu", "Za", "Ze", "Zeli", "Zi", "Zito"};
    static constexpr std::string_view names2_2[] = {"ban", "bomir", "bor", "borek", "brad", "bren", "brin", "bromir", "cimir", "dalf", "dan", "dar", "darr", "dek", "demir", "der", "dik", "dim", "dimir", "dinn", "domer", "domir", "dos", "dovan", "dran", "dzimir", "gan", "gdan", "gisa", "gnian", "go", "gomil", "gomir", "gotin", "goy", "grun", "gumil", "gun", "gurd", "gutin", "gvi", "hdan", "himir", "homir", "hos", "hren", "humer", "humil", "humir", "jan", "jek", "jidar", "lek", "libor", "lik", "limir", "lin", "ljan", "lko", "lon", "lorad", "los", "lovan", "lund", "lundr", "lyan", "mard", "mek", "mer", "mil", "mir", "narr", "nat", "ndri", "nek", "nik", "nimir", "nko", "nnarr", "ran", "rban", "rce", "rek", "rey", "reyr", "rian", "rik", "ril", "rin", "ris", "rko", "rlin", "romer", "romir", "ros", "rut", "rvan", "rvar", "rwan", "ser", "simir", "stan", "tek", "tik", "tomir", "van", "vis", "vor", "vril", "wan", "zan", "zdan", "zen", "zhil", "zhin", "zidar", "zimir", "zydar"};

    ArrayView names1; ArrayView names2; std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

    if (type == 1) {
    names1 = make_view(names1_1);
    names2 = make_view(names2_1);
    } else {
    names1 = make_view(names1_2);
    names2 = make_view(names2_2);
    }
i = rng() % 10; {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = names1[rnd] + names2[rnd2];
    return names;
    }
}
