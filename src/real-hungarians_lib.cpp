#include "real-hungarians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_real_hungarians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Ábel", "Ádám", "Ákos", "Ármin", "Áron", "Árpád", "Adrián", "Albert", "Alex", "Alexander", "András", "Antal", "Arnold", "Attila", "Bálint", "Béla", "Balázs", "Barna", "Barnabás", "Bence", "Bendegúz", "Benedek", "Benjámin", "Benjamin", "Bertalan", "Boldizsár", "Botond", "Csaba", "Csanád", "Csongor", "Dániel", "Dávid", "Dénes", "Dezső", "Dominik", "Domonkos", "Donát", "Endre", "Erik", "Ferenc", "Flórián", "Gábor", "Géza", "Gergő", "Gergely", "György", "Gyula", "Henrik", "Imre", "István", "János", "József", "Jakab", "Kálmán", "Károly", "Kevin", "Kornél", "Kristóf", "Krisztián", "Krisztofer", "László", "Lajos", "Levente", "Márió", "Márkó", "Márk", "Márton", "Máté", "Mátyás", "Marcell", "Martin", "Mihály", "Miklós", "Milán", "Nándor", "Noel", "Norbert", "Olivér", "Pál", "Péter", "Patrik", "Róbert", "Rajmund", "Renátó", "Richárd", "Roland", "Rudolf", "Sándor", "Soma", "Szabolcs", "Szilárd", "Szilveszter", "Tamás", "Tibor", "Valentin", "Viktor", "Vilmos", "Vince", "Zalán", "Zoltán", "Zsolt", "Zsombor"};
    static constexpr std::string_view nm2[] = {"Ágnes", "Éva", "Adél", "Adrienn", "Alexandra", "Andrea", "Anett", "Anikó", "Anita", "Anna", "Annamária", "Barbara", "Beatrix", "Bernadett", "Bettina", "Bianka", "Blanka", "Boglárka", "Borbála", "Brigitta", "Cintia", "Csenge", "Csilla", "Dóra", "Dalma", "Daniella", "Diána", "Dominika", "Dorina", "Dorina Mária", "Dorka", "Dorottya", "Dzsenifer", "Edina", "Elizabet", "Emese", "Enikő", "Erika", "Erzsébet", "Eszter", "Evelin", "Fanni", "Flóra", "Fruzsina", "Gabriella", "Georgina", "Gréta", "Hajnalka", "Hanna", "Henrietta", "Ildikó", "Ivett", "Izabella", "Júlia", "Judit", "Kíra", "Kamilla", "Kata", "Katalin", "Kinga", "Kitti", "Klaudia", "Krisztina", "Laura", "Liliána", "Lili", "Lilla", "Luca", "Mária", "Mónika", "Martina", "Melinda", "Mercédesz", "Nóra", "Natália", "Nikolett", "Nikoletta", "Noémi", "Orsolya", "Panna", "Patrícia", "Petra", "Réka", "Ramóna", "Rebeka", "Regina", "Renáta", "Sára", "Szabina", "Szilvia", "Szimonetta", "Tímea", "Tünde", "Tamara", "Vanda", "Vanessza", "Veronika", "Viktória", "Virág", "Vivien", "Zita", "Zsófia", "Zsanett", "Zsuzsanna"};
    static constexpr std::string_view nm3[] = {"Antal", "Bálint", "Bakos", "Miksa", "Csatár", "Bács", "Balázs", "Apród", "Balla", "Balog", "Balogh", "Barna", "Barta", "Biró", "Bodnár", "Bogdán", "Bognár", "Borbély", "Boros", "Budai", "Egyed", "Csonka", "Deák", "Dobos", "Dudás", "Fábián", "Fülöp", "Faragó", "Farkas", "Fazekas", "Fehér", "Fekete", "Fodor", "Gál", "Gáspár", "Gulyás", "Hajdú", "Halász", "Hegedüs", "Horváth", "Illés", "Jónás", "Jakab", "Juhász", "Katona", "Kelemen", "Kerekes", "Király", "Kis", "Kiss", "Kocsis", "Kovács", "Kozma", "László", "Lakatos", "Lengyel", "Lukács", "Márton", "Máté", "Mészáros", "Magyar", "Major", "Mezei", "Molnár", "Németh", "Nagy", "Nemes", "Novák", "Oláh", "Orbán", "Orosz", "Orsós", "Pál", "Pásztor", "Péter", "Pap", "Papp", "Vászoly", "Pataki", "Pintér", "Rácz", "Sándor", "Simon", "Sípos", "Soós", "Somogyi", "Székely", "Surány", "Szücs", "Szabó", "Kende", "Szalai", "Szekeres", "Szilágyi", "Szőke", "Szűts", "Tóth", "Török", "Takács", "Tamás", "Váradi", "Kapolcs", "Zobor", "Vörös", "Varga", "Vass", "Veres", "Vincze", "Virág"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm3);
    if (type == 1) {
    rnd = rng() % std::size(nm2);
    names = nm3[rnd2] + " " + nm2[rnd];
    } else {
    rnd = rng() % std::size(nm1);
    names = nm3[rnd2] + " " + nm1[rnd];
    }
    return names;
    }
}
