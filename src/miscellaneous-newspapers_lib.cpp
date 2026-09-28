#include "miscellaneous-newspapers_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_newspapers_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm3[][2] = {
		{"The ", "Bulletin"},
		{"The ", "Chronicle"},
		{"The ", "Chronicles"},
		{"The ", "Gazette"},
		{"The ", "Herald"},
		{"The ", "Inquirer"},
		{"The ", "Journal"},
		{"The ", "Mirror"},
		{"", "News"},
		{"", "News"},
		{"", "News"},
		{"The ", "Observer"},
		{"The ", "Post"},
		{"", "Press"},
		{"The ", "Record"},
		{"", "Record"},
		{"The ", "Register"},
		{"The ", "Report"},
		{"The ", "Reporter"},
		{"The ", "Sentinel"},
		{"The ", "Telegram"},
		{"", "Time"},
		{"", "Times"},
		{"The ", "Time"},
		{"The ", "Times"},
		{"", "Tribune"},
		{"The ", "Tribune"}
	};
    static constexpr std::string_view nm4[] = {"Daily", "Daily", "Daily", "Weekly", "Morning", "Evening"};
    static constexpr std::string_view nm1[] = {"Apex", "Aurora", "Avant-Garde", "Banner", "Beacon", "Break of Day", "Breakfast", "Bulletin", "Business", "Capital", "Capitol", "Carpe Diem", "Citizen", "Community", "Courier", "Crack of Dawn", "Daily", "Daily Watch", "Dawn", "Dawning", "Day Break", "Daybreak", "Daylight", "Dayspring", "Diem", "Dispatch", "Early", "Early Bird", "Eastern", "Echo", "Emerald", "Emporium", "Enterprise", "Epoch", "Era", "Estate", "Evening", "Everyday", "Explorer", "Express", "Eyewitness", "First Light", "Foreday", "Foundation", "Global", "Headline", "Heritage", "Independent", "Inside", "Insider", "Key", "Leading", "Legacy", "Liberty", "Life", "Local", "Local Voice", "Lodestar", "Metropolitan", "Modest", "Monday", "Morn", "Morning", "Morning Star", "Morning Watch", "Morningtide", "Morrow", "National", "New", "Northern", "Nova", "Observer", "Paragon", "Patriot", "Patron", "Pinnacle", "Pioneer", "Plain", "Prime", "Public", "Record", "Relay", "Saturday", "Society", "Southern", "Standard", "Star", "State", "Sun", "Sunday", "Sunrise", "Sunup", "Telegraph", "Today's", "Tribune", "Vertex", "Vista", "Weekly", "Western", "Witness", "World", "Zenith"};
    static constexpr std::string_view nm2[] = {"Account", "Alliance", "Apex", "Aurora", "Beacon", "Breakfast", "Bulletin", "Business", "Capital", "Capitol", "Carpe Diem", "Chronicle", "Chronicles", "Citizen", "Community", "Connection", "Courier", "Day Break", "Diem", "Dispatch", "Echo", "Emerald", "Emporium", "Enquirer", "Enterprise", "Epoch", "Era", "Estate", "Evening", "Explorer", "Express", "Eyewitness", "Gazette", "Global", "Globe", "Headline", "Herald", "Heritage", "Home", "Independent", "Inside", "Insider", "Journal", "Leader", "Ledger", "Legacy", "Liberty", "Life", "Local", "Local Voice", "Lodestar", "Look", "Look Back", "Mail", "Metropolitan", "Morn", "Morning Star", "Morning Watch", "Morningtide", "Morrow", "Narrative", "National", "Network", "News", "Nova", "Observer", "Outlook", "Paragon", "Patriot", "Patron", "Pinnacle", "Pioneer", "Prime", "Record", "Register", "Relay", "Report", "Reporter", "Review", "Sentinel", "Society", "Standard", "Star", "Sun", "Telegram", "Telegraph", "Time", "Times", "Tribune", "Union", "Unity", "Vista", "Witness", "World", "Zenith"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    if (i < 6) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm3);
    names = nm3[rnd2][0] + nm1[rnd] + " " + nm3[rnd2][1];
    } else if (i < 8) {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm4);
    names = nm2[rnd] + " " + nm4[rnd2];
    } else {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm4);
    names = nm4[rnd2] + " " + nm2[rnd];
    }
    return names;
    }
}
