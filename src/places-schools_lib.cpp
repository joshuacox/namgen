#include "places-schools_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_schools_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Acadia", "Angelwood", "Apple Valley", "Bayshore", "Bear Mountain", "Bear River", "Bear Valley", "Big Pine", "Big Valley", "Blue River", "Broad River", "Canyon View", "Cape Coral", "Central", "Central Valley", "Clear Lake", "Clearwater", "Columbus", "Copper Cove", "Coral Coast", "Coral Springs", "Crossroads", "Crystal River", "Cypress", "Da Vinci", "Darwin", "Deer River", "Deer Valley", "Desert Sands", "Desert Winds", "Diamond", "Eagle Mountain", "East Bridge", "East Shores", "Eastside", "Eastview", "Eastwood", "Edgewater", "Edgewood", "Einstein", "Elk Creek", "Elk Grove", "Elk Valley", "Enterprise", "Eureka", "Evergreen", "Faith", "Faraday", "Foothill", "Forest Lake", "Fortuna", "Freedom", "Frozen Lake", "Garden Grove", "Golden Oak", "Golden Sierra", "Golden Valley", "Grand Mountain", "Grand Ridge", "Grandview", "Granite Bay", "Granite Hills", "Grapevine", "Great Oak", "Green Meadows", "Green Valley", "Greenfield", "Greenlands", "Greenville", "Harbor View", "Hawking", "Hercules", "Heritage", "Highland", "Hillview", "Holy Oaks", "Horizon", "Independence", "Laguna Bay", "Laguna Beach", "Laguna Creek", "Lakeside", "Lakewood", "Liberty", "Lincoln", "Little Valley", "Littlerock", "Littlewood", "Lone Oak", "Lone Pine", "Long Beach", "Mammoth", "Maple Hills", "Maple Leaf", "Maple Park", "Maple Ridge", "Marble Hills", "Marie Curie", "Martin Luther King", "Meadows", "Meadows Ridge", "Millenium", "Monarch", "Mountain Oak", "Mountainridge", "Mountainview", "Northride", "Northview", "Oak Grove", "Oak Hills", "Oak Park", "Oak Ridge", "Oakland", "Oakleaf", "Oakwood", "Ocean View", "Oceanside", "Oyster Harbour", "Pacific Grove", "Palm Valley", "Panorama", "Paradise", "Paramount", "Patriot", "Pine Hill", "Pine Hills", "Pinewood", "Pioneer", "Pleasant Grove", "Pleasant Hill", "Pleasant Valley", "Promise", "Providence", "Rainbow", "Ravenwood", "Redlands", "Redwood", "Ridgeview", "River Fork", "River Valley", "Riverbank", "Riverdale", "Riverview", "Rutherford", "Sacred Heart", "Saint Helena", "Saint Mary's", "Sandalwood", "Savanna", "Seacoast", "Seal Bay", "Seal Coast", "Seal Gulch", "Seaside", "Sierra", "Silver Creek", "Silver Oak", "Silver Valley", "Silverleaf", "Skyline", "Somerset", "South Fork", "Southview", "Spring Gardens", "Spring Hill", "Springfield", "Stonewall", "Storm Coast", "Summerfield", "Summers", "Summerville", "Summit", "Sun Valley", "Sunny Coast", "Sunny Hills", "Sunnyside", "Sunset", "Sunshine", "Timber Creek", "Tranquillity", "Trinity", "Upper Lake", "Valley View", "Village", "Vista", "Waterfall", "Waterfalls", "Waterford", "West Bridge", "West Shores", "Westside", "Westview", "Westwood", "Whale Coast", "Whale Gulch", "White Mountain", "Whitewater", "Wildwood", "Willow", "Willow Creek", "Willow Park", "Winters", "Winterville", "Woodcreek", "Woodside"};
    static constexpr std::string_view names2[] = {"Academy", "College", "High", "High School", "School", "University", "Elementary", "Middle School", "Institute", "Charter School", "School of Fine Arts", "Secondary School", "School for Girls", "School for Boys", "Conservatory", "Grammar School", "Kindergarten", "Technical School"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = names1[rnd] + " " + names2[rnd2];
    return names;
    }
}
