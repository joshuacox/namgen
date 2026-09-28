#include "real-modern_egyptians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_real_modern_egyptians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Abasi", "Abdalla", "Abdelrahman", "Achraf", "Adel", "Adham", "Ahmad", "Ahmed", "Alaa", "Ali", "Aly", "Amir", "Amr", "Anwar", "Ari", "Ashraf", "Assem", "Athouman", "Aymn", "Barika", "Bassam", "Bassel", "Bebi", "Bebti", "Bedario", "Boody", "Chaths", "Chatuluka", "Chibale", "Chigaru", "Chisisi", "Darwishi", "David", "Desire", "Dodi", "Dodo", "Dods", "Gahiji", "Garai", "Gyasi", "Haisam", "Haji", "Hamadi", "Hamed", "Hanbal", "Hanif", "Hany", "Hassan", "Hatem", "Haytham", "Hesso", "Hosni", "Hossam", "Husani", "Hussein", "Ishaq", "Islam", "Isma", "Ismael", "Issa", "Kafele", "Kamuzu", "Kaphiri", "Kareem", "Karim", "Kasiya", "Kasto", "Khaled", "Kontar", "Louai", "Madu", "Maged", "Mahmoud", "Male", "Mamdoh", "Mando", "Manu", "Marwan", "Masud", "Mazen", "Medo", "Mero", "Mido", "Mina", "Mody", "Mohab", "Mohammed", "Momo", "Monim", "Moustafa", "Muhanad", "Mustafa", "Nader", "Nafty", "Nassor", "Nino", "Nizsm", "Nour", "Nuru", "Odion", "Omar", "Osahar", "Osaze", "Osman", "Ossama", "Psamtic", "Qeb", "Quasshie", "Radames", "Raffy", "Ragab", "Reda", "Redore", "Romuald", "Sadiki", "Samir", "Seif", "Selim", "Shaaban", "Shakir", "Sharky", "Teremun", "Thabit", "Tsekani", "Ubaid", "Ufa", "Usi", "Wael", "Waleed", "Wessam"};
    static constexpr std::string_view nm2[] = {"Aaliyah", "Abby", "Alia", "Aliaa", "Alima", "Amal", "Ameera", "Amina", "Amirah", "Anan", "Andra", "Arwa", "Asmaa", "Aya", "Ayah", "Babes", "Babu", "Baniti", "Bassam", "Bassant", "Bassma", "Boombaa", "Chavi", "Dalia", "Deena", "Dendera", "Dina", "Donya", "Ehsan", "Farida", "Fatma", "Femi", "Galela", "Gameela", "Habiba", "Hafsah", "Hana", "Hanaa", "Haqikah", "Heba", "Houda", "Ife", "Iman", "Isis", "Jehan", "Kaikara", "Kakra", "Kamilah", "Karima", "Kiara", "Lapis", "Mai", "Maibe", "Malak", "Manar", "Maria", "Mariah", "Mariam", "Marwa", "Masika", "Mayar", "Menna", "Meroo", "Mert", "Mesi", "Mi-Soon", "Miria", "Mona", "Monifa", "Monique", "Mosi", "Moushira", "Muminah", "Myrrh", "Nabirye", "Nada", "Nadeen", "Nadia", "Nadine", "Nagwa", "Naima", "Nannosa", "Nehad", "Nerin", "Nero", "Nesma", "Nihad", "Nile", "Noha", "Nona", "Norhan", "Nourane", "Nubia", "Ode", "Olabisis", "Olufemi", "Omorose", "Oseye", "Panya", "Pili", "Quibailah", "Rabiah", "Rana", "Raneem", "Rania", "Rasha", "Razan", "Reem", "Rehema", "Sabah", "Safa", "Sagira", "Sahirah", "Salama", "Sally", "Salma", "Salwa", "Samah", "Samar", "Samia", "Sanie", "Sanura", "Sara", "Sarah", "Selki", "Shadya", "Shafira", "Shahirah", "Shaimaa", "Shani", "Shesho", "Siti", "Sohaila", "Sohair", "Somaya", "Souhila", "Suhaila", "Tabia", "Taheya", "Tale", "Talibah", "Tania", "Tauret", "Theoris", "Umayma", "Urbi", "Walaa", "Walidah", "Weam", "Yasmeen", "Yasmin", "Yasmine", "Zalika"};
    static constexpr std::string_view nm3[] = {"Abadi", "Abboud", "Al Sadat", "Almasi", "Amari", "Antar", "Antoun", "Arian", "Asfour", "Asghar", "Asker", "Assaf", "Aswad", "Atiyeh", "Attia", "Awad", "Ba", "Baba", "Bahar", "Basara", "Bata", "Baz", "Bazzi", "Bishara", "Bitar", "Botros", "Boulos", "Boutros", "Cham", "Dagher", "Daher", "Deeb", "El Sadat", "Essa", "Fakhoury", "Gaber", "Ganem", "Ganim", "Gerges", "Ghanem", "Ghannam", "Guirguis", "Hadad", "Haddad", "Haik", "Hajjar", "Hakimi", "Halabi", "Hanania", "Handal", "Harb", "Isa", "Issa", "Kalb", "Kanaan", "Kassab", "Kassis", "Kattan", "Khouri", "Khoury", "Kouri", "Koury", "Maalouf", "Maloof", "Malouf", "Mansour", "Maroun", "Masih", "Mifsud", "Mikhail", "Moghadam", "Morcos", "Mubarak", "Mustafa", "Nader", "Nahas", "Naifeh", "Najjar", "Naser", "Nassar", "Nazari", "Quraishi", "Qureshi", "Rahal", "Sabbag", "Sabbagh", "Safar", "Said", "Salib", "Saliba", "Samaha", "Sarkis", "Sarraf", "Sayegh", "Seif", "Shadid", "Shalhoub", "Shammas", "Shamon", "Shamoon", "Shamoun", "Sleiman", "Srour", "Tahan", "Tannous", "Toma", "Totah", "Touma", "Tuma", "Wasem", "Zogby"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm3);
    if (type == 1) {
    rnd = rng() % std::size(nm2);
    names = nm2[rnd] + " " + nm3[rnd2];
    } else {
    rnd = rng() % std::size(nm1);
    names = nm1[rnd] + " " + nm3[rnd2];
    }
    return names;
    }
}
