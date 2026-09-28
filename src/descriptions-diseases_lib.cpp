#include "descriptions-diseases_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_diseases_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Aggressive", "Agitated", "Agony", "Aggressive", "Ancient", "Angel", "Angry", "Animated", "Anxious", "Arachnid", "Autumn", "Avian", "Bacterial", "Banshee", "Beer", "Black", "Boar", "Brain", "Brittle", "Buzzing", "Canine", "Cat", "Cave", "Chicken", "Chilling", "Cold", "Collapsing", "Contagious", "Cow", "Crazy", "Creeping", "Crippling", "Crumbling", "Crying", "Crystal", "Curable", "Deadly", "Death's", "Deathbell", "Decaying", "Delirious", "Demon", "Desert", "Desolation", "Deteriorating", "Devil's", "Dog", "Dragon", "Dream", "Dreaming", "Duck", "Dwarf", "Dying", "Elastic", "Elephant", "Enlarged", "Ethereal", "Exhausting", "Explosive", "Fading", "Failing", "Fall", "Falling", "Fatal", "Feline", "Fickle", "Fiery", "Fisherman's", "Flower", "Forceful", "Forest", "Frenzied", "Frost", "Frozen", "Ghastly", "Ghost", "Goblin", "Golden", "Goose", "Grave", "Green", "Growing", "Guttural", "Happy", "Harmless", "Heaven's", "Hell", "Hellish", "Hiccup", "Hopeless", "Horse", "Hostile", "Hot", "Humming", "Hyper", "Icy", "Immobilizing", "Impossible", "Incurable", "Intense", "Iron", "Ironbark", "Island", "Jumping", "Jungle", "King's", "Lady", "Laughing", "Lifeless", "Limp", "Lion", "Lizard", "Man", "Marsh", "Memory", "Mild", "Milk", "Mortal", "Mountain", "Mouse", "Necrotic", "Nervous", "Numb", "Numbing", "Ogre", "Orange", "Pale", "Paralyzing", "Peaceful", "Permanent", "Pestilent", "Petrifying", "Phantom", "Pig", "Pink", "Pygmy", "Queen's", "Quiet", "Quivering", "Rabbit", "Rabid", "Rasping", "Rat", "Red", "Restless", "Rickety", "Rock", "Rodent", "Rooster", "Rotting", "Running", "Sage", "Screaming", "Sedated", "Serpent", "Shadow", "Shaking", "Shaky", "Sheep", "Shivering", "Shriveling", "Silent", "Silver", "Sinister", "Sleep", "Smiling", "Snake", "Sniffeling", "Soft", "Soul", "Spastic", "Spider", "Spine", "Spirit", "Spring", "Steel", "Sterile", "Stiff", "Stiffening", "Stimulated", "Stinging", "Stomach", "Stranger's", "Stressed", "Stressful", "Stunned", "Summer", "Swamp", "Swine", "Temporary", "Terrifying", "Thorny", "Ticklish", "Tiring", "Tomb", "Tranquil", "Tree", "Trembling", "Trivial", "Twitching", "Ugly", "Undead", "Vein", "Violet", "Volatile", "Warping", "Water", "Weak", "Weakening", "Whispering", "Wicked", "Wild", "Winter", "Wired", "Witch", "Withering", "Wizard", "Wolf", "Wooden", "Worn", "Wraith", "Yellow", "Zombie"};
    static constexpr std::string_view nm2[] = {"Ache", "Aching", "Acne", "Allergy", "Amnesia", "Anemia", "Anthrax", "Anxiety", "Arthritis", "Asthma", "Baldness", "Blight", "Blindness", "Blisters", "Body", "Bones", "Bronchitis", "Cancer", "Cannibalism", "Chills", "Chlamydia", "Cholera", "Cold", "Cough", "Cramps", "Deafness", "Death", "Decay", "Deficiency", "Dehydration", "Delirium", "Delusion", "Delusions", "Depression", "Diptheria", "Disease", "Dysfunctions", "Ears", "Ebola", "Epilepsy", "Euphoria", "Eye", "Eyes", "Fatigue", "Feet", "Fever", "Finger", "Flu", "Foot", "Gangrene", "Gonorrhea", "Hallucinations", "Hands", "Head", "Heart", "Hepatitis", "Herpes", "Illness", "Infection", "Infertility", "Inflammation", "Influenza", "Insanity", "Insomnia", "Intolerance", "Irritation", "Leprosy", "Lupus", "Malaria", "Measles", "Meningitis", "Migraine", "Mouth", "Mutation", "Nausea", "Nose", "Panic", "Paralysis", "Paranoia", "Parasite", "Plague", "Pneumonia", "Poisoning", "Pox", "Rabies", "Rage", "Rash", "Salmonella", "Scarring", "Schizophrenia", "Scurvy", "Shock", "Skin", "Sleep Disorder", "Sneeze", "Soreness", "Sores", "Spasms", "Stiffness", "Stomach", "Swelling", "Syndrome", "Syphilis", "Tetanus", "Throat", "Tongue", "Tumor", "Ulcers", "Vampirism", "Virus", "Warts"};
    static constexpr std::string_view nm3[] = {"a bad taste in mouth", "a dry mouth", "a dry skin", "a fever", "a loss of appetite", "a loss of taste", "a metallic taste in mouth", "a rash", "a runny nose", "a shortness of breath", "a skin bump outbreak", "a skin sore outbreak", "a sore throat", "a sore tongue", "abdominal pain", "acid reflux", "an altered mental status", "an itchy skin", "ankle pain", "arm pain", "back pain", "bad breath", "blistering", "blood in urine", "bloody nose", "blurred vision", "breast pain", "breathing difficulty", "burning urination", "chest pain", "chills", "cloudy urine", "cold feet", "cold fingers", "cold hands", "confusion", "constipation", "coughing", "cramping", "delirium", "delusion", "depression", "diarrhea", "dizziness", "double vision", "drooling", "ear pain", "easy bruising", "euphoria", "excess sweating", "excessive yawning", "eye discharge", "eye swelling", "eye twitching", "fainting", "feeling light-headed", "feeling sick", "feeling sleepy", "feeling tired", "feeling weak", "finger numbness", "frequent urination", "gum pain", "hair loss", "hallucination", "headache", "hearing difficulty", "heartburn", "hip pain", "hyperactivity", "inattention", "increased thirst", "jaw pain", "joint redness", "joint stiffness", "joint swelling", "knee pain", "leg pain", "leg swelling", "memory loss", "mood fluctuation", "mouth sores", "moving difficulty", "muscle cramps", "muscle weakness", "nail brittleness", "nasal congestion", "nausea", "neck pain", "peeing difficulty", "pelvic pain", "pupil dilation", "rectal pain", "red spot outbreak", "ringing ears", "seizures", "shaking hands", "shoulder pain", "sleeping difficulty", "sneezing", "swallowing difficulty", "temperature fluctuation", "temporary blindness", "tingling feet", "tingling hands", "toe numbness", "toothache", "vomiting", "walking difficulty", "weight gain", "weight loss"};
    static constexpr std::string_view nm4[] = {"generally start within a week", "generally start within a few days", "generally start within a few hours", "may start within a week", "may start within a few days", "may start within a few hours", "slowly increase in severity over a week", "slowly increase in severity over a few days", "slowly increase in severity over several hours", "often start out of nowhere within a week", "often start out of nowhere within a few days", "often start out of nowhere within a few hours"};
    static constexpr std::string_view nm5[] = {"rarely together at the same time", "rarely are both experienced at once", "both symptoms always start together", "both symptoms are always experienced at some time", "not necessarily at the same time", "only one symptom may be experienced", "both symptoms may differ in severity", "both symptoms are usually equally intense", "one symptom may be subdued in some cases", "one symptom generally lags behind the other"};
    static constexpr std::string_view nm6[] = {"generally fades away and never returns", "generally fades away, but may linger for a while", "generally fades away, only to return later", "often increases in intensity", "generally increases in intensity", "usually fades away, but never completely", "often gradually loses its intensity", "tends to linger for a long time", "tends to become seemingly random and infrequent", "usually loses how frequently it's experienced", "often reaches extremes at seemingly random times", "may reach severely uncomfortable peaks", "may turn into more severe experiences", "often becomes less severe after a few days", "tends to stop very quickly"};
    static constexpr std::string_view nm7[] = {"by most people", "by the majority of people", "by the vast majority of people", "by almost all cases", "by all people", "by all cases so far"};
    static constexpr std::string_view nm8[] = {"sometimes decreases the severity of the", "often has an amplifying effect on the", "generally tends to worsen the effects of the", "generally leads to a decrease of the", "often subdues the severity of the", "may be experienced more strongly in combination with the", "may be less severe in combination with the", "may be amplified by the", "may be subdued a little by the", "is often experienced more severe due to the"};
    static constexpr std::string_view nm9[] = {"by 50% of people", "by about 25% of people", "fairly often", "often", "rarely", "frequently", "infrequently"};
    static constexpr std::string_view nm10[] = {"often experienced severely", "often experienced moderately", "often experienced at random times", "usually experienced in the morning", "usually experienced in the evening", "usually experienced at night", "generally experienced at severe levels", "generally experienced at moderate levels", "generally experienced only faintly", "mostly experienced after eating", "mostly experienced after drinking", "mostly experienced after waking up", "usually experienced while standing up"};
    static constexpr std::string_view nm11[] = {"in rare cases", "in only some cases", "in only some people", "in a minority of people", "in rare cases", "in extreme cases", "in some extreme cases", "in specific cases", "in very specific cases", "very rarely"};
    static constexpr std::string_view nm12[] = {"may become a chronic experience", "may become a more severe experience", "is usually only experienced faintly", "is generally not experienced to extreme levels", "often fades as quickly as it starts", "may be completely unrelated and coincidental", "is generally only experienced for a short time", "may be experienced for a long time", "can be experienced at extreme levels", "could be a symptom of a different disease"};
    static constexpr std::string_view nm13[] = {"Ingesting a virus from vermin droppings, usually through food", "Ingesting a virus through improperly cooked meats and fish", "Bad hygiene or coming in contact with contaminated water", "Improper and/or unbalanced diet", "Infection, often after an injury", "Often injected by insects, like mosquitoes", "Genetic birth defects", "Being infected by contaminated bodily fluids", "Infection in a weak(ened) immune system", "Deficiency of nutrients and vitamins", "Breathing contaminated air, often in combination with a weaker immune system", "Too much stress and a weakened immune system", "Lack of sleep, exercise and/or imbalanced diet", "Lack of sleep, often in combination with stress", "A virus. Often ingested through food and drinks", "Bacteria ingested through food from places with bad hygiene", "Ingesting meat from contaminated animals", "Bacterial infection after an injury, usually in combination with bad hygiene", "Evolved virus from animals. Those who work with animals are thus at higher risk", "Currently unknown", "Unknown, but a weakened immune system is usually part of it"};
    static constexpr std::string_view nm14[] = {"Spicy food", "Stress", "Lack of sleep", "Alcohol", "Caffeine", "Stimulating drugs", "Doing nothing", "Poor nutrition", "Certain medications", "Lack of exercise", "Heavy exercise/labor", "High blood pressure", "Being overweight", "Being underweight", "Excess vitamins", "Exertion", "Excess supplements"};
    static constexpr std::string_view nm15[] = {"Spicy food.", "Stress.", "Lack of sleep.", "Alcohol.", "Caffeine.", "Stimulating drugs.", "Doing nothing.", "Poor nutrition.", "Certain medications.", "Lack of exercise.", "Heavy exercise/labor.", "High blood pressure.", "Being overweight.", "Being underweight.", "Excess vitamins.", "Exertion.", "Excess supplements.", "", "", "", "", ""};
    static constexpr std::string_view nm16[] = {"Simple medication routine", "Heavy medication routine", "Medication and dietary supplement routine", "Light suppressants", "Heavy suppressants", "Simple surgical procedure", "Invasive surgical procedure", "Medication routine and in some cases a surgical procedure", "Suppressants and medication routine", "Change of lifestyle", "None needed, medication is given in some cases", "Untreatable. (Pain) medication helps manage it", "Stress reduction and a light medication routine", "Light suppressants and in some cases a surgical procedure", "Invasive medication routine", "Heavy medication and suppressant routine", "Proper diet and enough rest", "Rest, relaxation and in some cases minor medication", "Usually rest is enough. Some cases require a minor surgical procedure", "Usually rest and a proper diet are enough. Some cases require medication"};
    static constexpr std::string_view nm17[] = {"3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33"};
    static constexpr std::string_view nm18[] = {"people", "young adults", "adults", "older adults", "children", "young children", "teenagers", "senior adults", "people", "people"};

    std::string name; std::string name10; std::string name11; std::string name12; std::string name13; std::string name14; std::string name15; std::string name2; std::string name3; std::string name4; std::string name5; std::string name6; std::string name7; std::string name8; std::string name9; std::string result; size_t rnd1 = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14a = 0; size_t rnd14b = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd17 = 0; size_t rnd18 = 0; size_t rnd2 = 0; size_t rnd3a = 0; size_t rnd3b = 0; size_t rnd3c = 0; size_t rnd3d = 0; size_t rnd3e = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

    rnd1 = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3a = rng() % std::size(nm3);
    rnd3b = rng() % std::size(nm3);
    rnd3c = rng() % std::size(nm3);
    rnd3d = rng() % std::size(nm3);
    rnd3e = rng() % std::size(nm3);
    while (rnd3b == rnd3a) {
    rnd3b = rng() % std::size(nm3);
    }
    rnd3c = rng() % std::size(nm3);
    while (rnd3b == rnd3c || rnd3a == rnd3c) {
    rnd3c = rng() % std::size(nm3);
    }
    rnd3d = rng() % std::size(nm3);
    while (rnd3d == rnd3a || rnd3d == rnd3b || rnd3d == rnd3c) {
    rnd3d = rng() % std::size(nm3);
    }
    rnd3e = rng() % std::size(nm3);
    while (rnd3e == rnd3a || rnd3e == rnd3b || rnd3e == rnd3c || rnd3e == rnd3d) {
    rnd3e = rng() % std::size(nm3);
    }
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    rnd9 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    rnd12 = rng() % std::size(nm12);
    rnd13 = rng() % std::size(nm13);
    rnd14a = rng() % std::size(nm14);
    rnd14b = rng() % std::size(nm14);
    rnd15 = rng() % std::size(nm15);
    while (rnd14b == rnd14a) {
    rnd14b = rng() % std::size(nm14);
    }
    while (rnd15 == rnd14a || rnd15 == rnd14b) {
    rnd15 = rng() % std::size(nm15);
    }
    rnd16 = rng() % std::size(nm16);
    rnd17 = rng() % std::size(nm17);
    rnd18 = rng() % std::size(nm18);
    name = "Name: " + nm1[rnd1] + "  " + nm2[rnd2];
    name2 = "Possible symptoms:";
    name3 = "- " + nm3[rnd3a];
    name4 = "- " + nm3[rnd3b];
    name5 = "- " + nm3[rnd3c];
    name6 = "- " + nm3[rnd3d] + " (not in all cases)";
    name7 = "- " + nm3[rnd3e] + " (uncommon)";
    name8 = "What to expect: " + nm3[rnd3a] + " and " + nm3[rnd3b] + " " + nm4[rnd4] + ", but " + nm5[rnd5] + ". After the initial onset, " + nm3[rnd3a] + " " + nm6[rnd6] + ". Around this time " + nm3[rnd3c] + " is experienced " + nm7[rnd7] + ".";
    name9 = "The experience of " + nm3[rnd3c] + " " + nm8[rnd8] + " experience of " + nm3[rnd3b] + ".";
    name10 = "After a few more days " + nm3[rnd3d] + " is experienced " + nm9[rnd9] + " and is " + nm10[rnd10] + ".";
    name11 = "Throughout the course of the disease, " + nm3[rnd3e] + " may be experienced, but only " + nm11[rnd11] + " and " + nm12[rnd12] + ".";
    name12 = "Cause: " + nm13[rnd13] + ".";
    name13 = "Made worse by: " + nm14[rnd14a] + ". " + nm14[rnd14b] + ". " + nm15[rnd15];
    name14 = "Treatment: " + nm16[rnd16] + ".";
    name15 = "Rarity: 1 in " + nm17[rnd17] + " " + nm18[rnd18] + " have " + nm1[rnd1] + "  " + nm2[rnd2] + ".";
    result = "";
    result += name;
    result += "\n";
    result += name2;
    result += "\n";
    result += name3;
    result += "\n";
    result += name4;
    result += "\n";
    result += name5;
    result += "\n";
    result += name6;
    result += "\n";
    result += name7;
    result += "\n";
    result += "\n";
    result += name8;
    result += "\n";
    result += name9;
    result += "\n";
    result += name10;
    result += "\n";
    result += name11;
    result += "\n";
    result += name12;
    result += "\n";
    result += name13;
    result += "\n";
    result += name14;
    result += "\n";
    result += name15;
    return result;
}
