#include "descriptions-rag_clothings_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_rag_clothings_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Her", "She", "her", "she", "her", "His", "He", "his", "he", "him"};
    static constexpr std::string_view nm2_1[] = {"shirt", "t-shirt"};
    static constexpr std::string_view nm3[] = {"merely a dirt stained piece of fabric, hanging from one of", "barely a piece of clothing at all, the dirt stained fabric hangs onto", "nothing more than pieces of fabric held barely together, it hangs from", "a torn, dirt stained shadow of its former self, only barely able to hang from", "a gross, tattered home to lice and dirt, hanging from one of", "a dirty, flimsy piece of fabric, held together by a handful of fibers hanging from", "a dirty, tattered mess of fibers and fabric, only barely able to hang from", "a ruffled mess of loose fibers, dirt stains and holes, it barely manages to hang from", "a collection of dirt, lice and who knows what else, it barely manages to hang from", "nothing more than a collection of dirt, loose pieces of fabric and holes, only barely able to hang from", "a vile collection of pieces of dirty fabric, grime and muck, it barely manages to hang from", "nothing more than a crummy old piece of fabric full of holes and stained with dirt, it barely manages to hang from", "a nasty mess of holes, muck and dirty stains, hanging from one of", "a foul collection of raggedy pieces of fabric, dirt and holes, barely able to hang from", "nothing more than dirty pieces of fabric barely held together, hanging from"};
    static constexpr std::string_view nm4[] = {"There's a massive tear on the right side, which leaves much of", "There are holes all over it. Big, small and anything in between, leaving much of", "There's a huge tear on the left side, which leaves much of", "The bottom's worn and tattered and there's a huge hole in the front, leaving much of", "There are more holes than fabric at this point, leaving much of", "It's filled with holes which have grown over time, leaving much of", "Part of the bottom has been torns of and the sleeves are worn away, leaving much of", "There's a huge hole in one of the shoulders which reaches almost all the way down, leaving much of", "Insects or rodents have chewed hundreds of small holes in it, leaving much of", "Holes and tears are scattered all over and leave much of", "There's a big tear across the backside and holes all over the front, leaving much of", "Both of the sides are torn and worn out, leaving much of", "A big piece has been ripped from the right side and there are holes all over, leaving much of", "A big chunk of fabric has been torn from the left side and there are holes and tears all over, leaving much of", "The neck has been torn on one side and there are dozens of holes, leaving much of"};
    static constexpr std::string_view nm5[] = {"a tattered", "a ripped", "a worn out", "an old", "a scraggy", "a rugged"};
    static constexpr std::string_view nm6[] = {"vest", "poncho", "hoody", "jacket", "fleece", "coat"};
    static constexpr std::string_view nm7[] = {"It's far too big and stained with who knows what", "It's too big, torn and very dirty", "It's dirty, it's torn and it's worn out", "It's a size too small, stained and dirty", "It's too small, dirty and it smells", "It smells, it's dirty and full of stains", "It's in relative good condition apart from the holes", "It's in a fairly good condition, apart from the tears and stains", "It's a size too large, it's dirty and it's torn", "It's worn out, dirty and stained with grime", "It's almost the right size, but dirty, smelly and torn", "It's a torn, dirty, stinking mess", "It's filthy, flimsy and worn out", "It's greasy, full of stains and torn", "It's a nasty mess of stains and dirt"};
    static constexpr std::string_view nm8[] = {"stay warm", "fight the elements", "stay protected from the elements", "stay protected", "stay relatively dry", "stay protected from the wind"};
    static constexpr std::string_view nm9[] = {"aren't in great shape either", "aren't much better either", "are in terrible shape as well", "aren't what they used to be either", "are a mess as well", "are just as bad", "aren't looking great either", "have seen better times as well"};
    static constexpr std::string_view nm10[] = {"Holes everywhere and the legs have been shortened by wear and tear", "The right side is nothing more than a bunch of shreds", "The left side is torn up and nothing more than a bunch shreds", "There are holes all over the bottom part and there's a big tear on the right side", "Dirt stains, holes and tears are scattered all over", "There are holes all over the right side and what's left is covered in stains", "Rips and tears have turned these pants into a dirt stained mess of shreds", "There's a big tear at the backside and holes all across the sides", "A big tear has split the left leg in two and the right leg is full of smaller tears as well", "The pants are covered in small tears and covered in unknown stains", "Wear and tear has turned what were once small tears into big gaping holes", "There's a big tear on the left side which runs from the top to almost the bottom", "Dirt and other substances have stained these pants and gave them a new color", "The right leg has been torn at the knee and the left leg is full of holes", "The knees are torn and there are plenty of other small tears all over"};
    static constexpr std::string_view nm11[] = {"old", "dirty", "worn out", "broken", "missing laces", "tattered", "ragged", "grimy", "stained", "murky"};
    static constexpr std::string_view nm12[] = {"a size too small", "a size too big", "way too big", "a little too small", "barely the right size", "only just the right size", "a little too big"};
    static constexpr std::string_view nm13[] = {"a hole in the sole of the right shoe lets in water and dirt", "a hole in the sole of the left shoe lets in water and dirt", "the heel of the left shoe is worn far more than the right", "the outer fabric is tattered, worn and missing in some places", "the outer sole of the left shoe has long been lost", "the outer sole of the right shoe has long been lost", "the right toebox has come loose from the sole", "the left toebox has come loose from the sole", "the sole of the right shoe has come loose at the heel", "the sole of the left shoe has come loose at the heel", "the soles are worn to barely a sliver of what they were", "there are holes in the right side of the left shoe", "there are holes in the right side of the right shoe", "there's a hole in the left heel which lets in water and dirt", "there's a hole in the left toebox which lets in water and dirt", "there's a hole in the right heel which lets in water and dirt", "there's a hole in the right toebox which lets in water and dirt"};
    static constexpr std::string_view nm14[] = {"large scarf", "small scarf", "scarf", "bandana"};
    static constexpr std::string_view nm15[] = {"face to just below the nose", "face to just below the eyes", "face in a way that covers the chin"};
    static constexpr std::string_view nm16[] = {"dirty and shoddy, but at least it doesn't smell", "old and ragged, but relatively clean", "torn and worn, but otherwise in a decent shape", "ragged and stained, but at least it's not smelly", "full of holes, but still holding together", "old and worn, but otherwise in a good condition", "torn and slightly stained, but otherwise in a decent shape", "worn out, but still holding together"};
    static constexpr std::string_view nm17[] = {"beanie, there was once a small pom pom on the top, but all that's left now is a small piece of yarn", "beanie, there's a hole in the top, but that's pretty much its only flaw", "beanie, it's in suprisingly good condition. It's old, but there are no holes or stains", "beanie, which may be old and worn out, but it's still in a relatively good and clean condition", "beanie, there's a small dirt stain on one of the sides, but that's its only real flaw", "bandana, there's a hole at the front, but other than that it's in pretty good shape", "bandana, it's old and ragged, but otherwise in a good and relatively clean condition", "bandana, there are a few small stains here and there, but it's otherwise in a relatively great condition", "bandana, there's a couple of small holes here and there, but it's relatively clean and in a decent condition", "bandana, surprisingly there are no holes or stains or any other major flaws besides its age"};
    static constexpr std::string_view nm2_2[] = {"shirt", "t-shirt", "dress"};

    ArrayView nm2; std::string name; std::string name2; std::string name3; std::string name4; std::string name5; std::string name6; std::string result; std::string tp; size_t rnd1 = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd17 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int v = 0; int w = 0; int x = 0; int y = 0; int z = 0;

    tp = type;
    nm2 = make_view(nm2_1);
    v = 5;
    w = 6;
    x = 7;
    y = 8;
    z = 9;
    if (tp == 1) {
    v = 0;
    w = 1;
    x = 2;
    y = 3;
    z = 4;
    }
    rnd1 = rng() % std::size(nm1);
    if (rnd1 < 5) {
    nm2 = make_view(nm2_2);
    }
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
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
    rnd14 = rng() % std::size(nm14);
    rnd15 = rng() % std::size(nm15);
    rnd16 = rng() % std::size(nm16);
    rnd17 = rng() % std::size(nm17);
    name = "What was once a " + nm2[rnd2] + " is now " + nm3[rnd3] + " " + nm1[x] + " shoulders like a discarded old towel.";
    name2 = nm4[rnd4] + " " + nm1[z] + " exposed to the elements.";
    name3 = nm1[w] + "'s wearing " + nm5[rnd5] + " " + nm6[rnd6] + " over " + nm1[x] + " " + nm2[rnd2] + ". " + nm7[rnd7] + ", but at least it helps " + nm1[z] + " " + nm8[rnd8] + ", even if only for a little.";
    name4 = nm1[v] + " pants " + nm9[rnd9] + ". " + nm10[rnd10] + ". But at least " + nm1[y] + " has shoes to protect " + nm1[x] + " feet. Although they're " + nm11[rnd11] + ", " + nm12[rnd12] + " and " + nm13[rnd13] + ".";
    name5 = nm1[w] + " wears a  " + nm14[rnd14] + " around " + nm1[x] + " neck and has it wrapped around " + nm1[x] + " " + nm15[rnd15] + ". It's " + nm16[rnd16] + ".";
    name6 = nm1[v] + " head is covered by a " + nm17[rnd17] + ".";
    result = "";
    result += name;
    result += "\n";
    result += name2;
    result += "\n";
    result += "\n";
    result += name3;
    result += "\n";
    result += "\n";
    result += name4;
    result += "\n";
    result += "\n";
    result += name5;
    result += "\n";
    result += name6;
    return result;
}
