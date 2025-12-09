#!/usr/bin/env bats

setup() {
    # ... the remaining setup is unchanged

    # get the containing directory of this file
    # use $BATS_TEST_FILENAME instead of ${BASH_SOURCE[0]} or $0,
    # as those will point to the bats executable's location or the preprocessed file respectively
    DIR="$( cd "$( dirname "$BATS_TEST_FILENAME" )" >/dev/null 2>&1 && pwd )"
    # make executables in src/ visible to PATH
    PATH="$DIR/../src:$PATH"
    export NOUN_FILE=test/test 
    export ADJ_FILE=test/test 
    export SEPARATOR='_'
    export counto=1
}

@test "cmake ." {
  cmake .
  result=$?
  [[ "$result" -eq 0 ]]
}
@test "make" {
  make
  result=$?
  [[ "$result" -eq 0 ]]
}
@test "test namgen at 10" {
  result="$(counto=10 ./namgen|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --elf at 10" {
  result="$(counto=10 ./namgen --elf|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen at 333" {
  result="$(counto=333 ./namgen|wc -l)"
  [[ "$result" -eq 333 ]]
}
@test "test namgen -c 343" {
  result="$(./namgen -c 343|wc -l)"
  [[ "$result" -eq 343 ]]
}
@test "test namgen --count 3433" {
  result="$(./namgen --count 3433|wc -l)"
  [[ "$result" -eq 3433 ]]
}
@test "test namgen test/test" {
  result=$(./namgen)
  [[ "$result" == "test_test" ]]
}
@test "test null_separator test/test" {
  result=$(./namgen -x)
  [[ "$result" == "testtest" ]]
}
@test "test capcasing test/test" {
  result=$(./namgen --capcasing)
  echo $result
  [[ "$result" == "Test_Test" ]]
}
@test "test NULL_SEPARATOR capcasing test/test" {
  result=$(NULL_SEPARATOR=true ./namgen --capcasing)
  echo $result
  [[ "$result" == "TestTest" ]]
}
@test "test NULL_SEPARATOR camelcasing test/test" {
  result=$(NULL_SEPARATOR=true ./namgen --camelcasing)
  echo $result
  [[ "$result" == "testTest" ]]
}
@test "test --null-separator camelcasing test/test" {
  result=$(./namgen --null-separator --camelcasing)
  echo $result
  [[ "$result" == "testTest" ]]
}
@test "test -x camelcasing test/test" {
  result=$(./namgen -x --camelcasing)
  echo $result
  [[ "$result" == "testTest" ]]
}
@test "test SEPARATOR test/test" {
  result=$(SEPARATOR='^' ./namgen)
  echo $result
  [[ "$result" == "test^test" ]]
}
@test "test -s camelcasing test/test" {
  result=$(./namgen -s '^' --camelcasing)
  echo $result
  [[ "$result" == "test^Test" ]]
}
@test "test --separator test/test" {
  result=$(./namgen --separator '^' --camelcasing)
  echo $result
  [[ "$result" == "test^Test" ]]
}
@test "test --debug test/test" {
  result=$(./namgen --debug)
  echo $result
  [[ "$result" == "test_test" ]]
}
@test "test default exclude test/test" {
  result=$(counto=1 NOUN_FILE=test/excludes ADJ_FILE=test/excludes SEPARATOR='^' CAPCASING=true ./namgen)
  echo $result
  [[ "$result" == "Test^Test" ]]
}
@test "test exclude test/test" {
  result=$(counto=1 NOUN_FILE=test/excludes ADJ_FILE=test/excludes SEPARATOR='^' CAPCASING=true ./namgen --exclude "-'")
  echo $result
  [[ "$result" == "Test^Test" ]]
}
@test "sudo make install" {
  sudo make install
}
@test "test namgen --destiny-awokens at 10" {
  result="$(counto=10 ./namgen --destiny-awokens|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --destiny-cabals at 10" {
  result="$(counto=10 ./namgen --destiny-cabals|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --destiny-exos at 10" {
  result="$(counto=10 ./namgen --destiny-exos|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --destiny-fallens at 10" {
  result="$(counto=10 ./namgen --destiny-fallens|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --diablo-angels at 10" {
  result="$(counto=10 ./namgen --diablo-angels|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --dungeon_and_dragons-devas at 10" {
  result="$(counto=10 ./namgen --dungeon_and_dragons-devas|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --diablo-demons at 10" {
  result="$(counto=10 ./namgen --diablo-demons|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --diablo-khazras at 10" {
  result="$(counto=10 ./namgen --diablo-khazras|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --dragon_ball-frieza_clans at 10" {
  result="$(counto=10 ./namgen --dragon_ball-frieza_clans|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --dragon_ball-hakaishins at 10" {
  result="$(counto=10 ./namgen --dragon_ball-hakaishins|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --diablo-nephalems at 10" {
  result="$(counto=10 ./namgen --diablo-nephalems|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --dragon_ball-humans at 10" {
  result="$(counto=10 ./namgen --dragon_ball-humans|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --fantasy-animal_species at 10" {
  result="$(counto=10 ./namgen --fantasy-animal_species|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --fantasy-animatronics at 10" {
  result="$(counto=10 ./namgen --fantasy-animatronics|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --destiny-humans at 10" {
  result="$(counto=10 ./namgen --destiny-humans|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --destiny-vexs at 10" {
  result="$(counto=10 ./namgen --destiny-vexs|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --dragon_ball-skians at 10" {
  result="$(counto=10 ./namgen --dragon_ball-skians|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --dragon_ball-tuffles at 10" {
  result="$(counto=10 ./namgen --dragon_ball-tuffles|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --dungeon_and_dragons-elfs at 10" {
  result="$(counto=10 ./namgen --dungeon_and_dragons-elfs|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --dungeon_and_dragons-githzerais at 10" {
  result="$(counto=10 ./namgen --dungeon_and_dragons-githzerais|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --fantasy-apocalypse_mutants at 10" {
  result="$(counto=10 ./namgen --fantasy-apocalypse_mutants|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --halo-forerunners at 10" {
  result="$(counto=10 ./namgen --halo-forerunners|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --military-united_states at 10" {
  result="$(counto=10 ./namgen --military-united_states|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --warhammer-ogres at 10" {
  result="$(counto=10 ./namgen --warhammer-ogres|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --doctor_who-silurians at 10" {
  result="$(counto=10 ./namgen --doctor_who-silurians|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --towns_and_cities-ancient_greek_towns at 10" {
  result="$(counto=10 ./namgen --towns_and_cities-ancient_greek_towns|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --final_fantasy-roegadyns at 10" {
  result="$(counto=10 ./namgen --final_fantasy-roegadyns|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --pets-marine_mammals at 10" {
  result="$(counto=10 ./namgen --pets-marine_mammals|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --rift-bahmis at 10" {
  result="$(counto=10 ./namgen --rift-bahmis|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --doctor_who-raxacoricofallapatorians at 10" {
  result="$(counto=10 ./namgen --doctor_who-raxacoricofallapatorians|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --inheritance_cycle-dragons at 10" {
  result="$(counto=10 ./namgen --inheritance_cycle-dragons|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --pop_culture-homestucks at 10" {
  result="$(counto=10 ./namgen --pop_culture-homestucks|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --warhammer_40k-sisters_of_battles at 10" {
  result="$(counto=10 ./namgen --warhammer_40k-sisters_of_battles|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --towns_and_cities-east_european_towns at 10" {
  result="$(counto=10 ./namgen --towns_and_cities-east_european_towns|wc -l)"
  [[ "$result" -eq 10 ]]
}
