#include "miscellaneous-political_partys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_political_partys_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Advanced", "Collective", "Common", "Constitutional", "Contemporary", "Eastern", "Extremist", "Fanatical", "Federal", "First", "Free", "Global", "Independent", "Industrial", "International", "Lawful", "Leading", "Liberal", "Moderate", "Modern", "National", "Neo", "New", "Northern", "Organized", "Patriotic", "Peaceful", "People's", "Permanent", "Prime", "Progressive", "Radical", "Rational", "Revolutionary", "Social", "Southern", "Sovereign", "Traditional", "Unconditional", "Undivided", "Unified", "United", "Universal", "Vocal", "Western", "World", "", "", ""};
    static constexpr std::string_view nm2[] = {"Abolition", "Action", "Administration", "Advancement", "Affinity", "Agrarian", "Alliance", "Amendment", "Animal", "Appreciation", "Autocrat", "Choice", "Citizens", "Civic", "Civil Rights", "Coalition", "Communion", "Communist", "Community", "Compromise", "Conservative", "Constitution", "Defiance", "Democratic", "Denizen", "Diligence", "Earth", "Egalitarian", "Egalitarianism", "Egalitarion", "Emancipation", "Enterprise", "Equality", "Equilibrium", "Evaluation", "Evolution", "Family", "Fascist", "Fatherland", "Federation", "Formation", "Freedom", "Future", "Green", "Homeland", "Honesty", "Household", "Humanitarian", "Identity", "Immunity", "Impartiality", "Independence", "Industry", "Integrity", "Isolation", "Justice", "Labor", "Law", "Left", "Left Wing", "Legislation", "Liberation", "Libertarian", "Liberty", "Life", "Loyalist", "Monarchist", "Motherland", "Nation", "Nationalist", "Nature", "Operation", "Opportunity", "Pacifism", "Pacifist", "Parliamentary", "Patriot", "Peace", "People", "Preservation", "Privilege", "Probation", "Progress", "Progression", "Prohibition", "Proposition", "Prosperity", "Protection", "Reconciliation", "Red", "Reformation", "Regulation", "Rehabilitation", "Renovation", "Republican", "Resistance", "Respect", "Right", "Right Wing", "Science", "Segregation", "Separation", "Separatist", "Socialist", "Solidarity", "State", "Taxpayer", "Theocratic", "Transformation", "Trust", "Uniformity", "Unionist", "Unity", "Voice", "Voter", "Welfare", "Workers", "Working Class"};
    static constexpr std::string_view nm3[] = {"Party", "League", "Movement", "Group", "Union", "Coalition", "Party", "Party"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    names = nm1[rnd] + " " + nm2[rnd2] + " " + nm3[rnd3];
    return names;
    }
}
