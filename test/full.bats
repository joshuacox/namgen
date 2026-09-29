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
  if ! command -v cmake >/dev/null 2>&1; then
    skip "cmake not found"
  fi
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
@test "test namgen --real-norwegians at 10" {
  result="$(counto=10 ./namgen --real-norwegians|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --rift-eths at 10" {
  result="$(counto=10 ./namgen --rift-eths|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --halo-mgalekgolos at 10" {
  result="$(counto=10 ./namgen --halo-mgalekgolos|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --doctor_who-ice_warriors at 10" {
  result="$(counto=10 ./namgen --doctor_who-ice_warriors|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --warhammer-daemons_of_chaos at 10" {
  result="$(counto=10 ./namgen --warhammer-daemons_of_chaos|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --elder_scrolls-bosmers at 10" {
  result="$(counto=10 ./namgen --elder_scrolls-bosmers|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --harry_potter-goblins at 10" {
  result="$(counto=10 ./namgen --harry_potter-goblins|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --eve_online-gallentes at 10" {
  result="$(counto=10 ./namgen --eve_online-gallentes|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --star_wars_the_old_republic-cathars at 10" {
  result="$(counto=10 ./namgen --star_wars_the_old_republic-cathars|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --military-royal_navy at 10" {
  result="$(counto=10 ./namgen --military-royal_navy|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --towns_and_cities-west_european_towns at 10" {
  result="$(counto=10 ./namgen --towns_and_cities-west_european_towns|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --places-plazas at 10" {
  result="$(counto=10 ./namgen --places-plazas|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --dragon_age-dwarfs at 10" {
  result="$(counto=10 ./namgen --dragon_age-dwarfs|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --pets-reptiles at 10" {
  result="$(counto=10 ./namgen --pets-reptiles|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test out of dir" {
  cd /tmp
  unset ADJ_FILE
  unset NOUN_FILE
  result=$(namgen -c 11|wc -l)
  echo $result
  [[ "$result" -eq 11 ]]
}
@test "test namgen --wildstar-mordeshs at 10" {
  result="$(counto=10 ./namgen --wildstar-mordeshs|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --towns_and_cities-dwarven_citys at 10" {
  result="$(counto=10 ./namgen --towns_and_cities-dwarven_citys|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --real-anglo_saxons at 10" {
  result="$(counto=10 ./namgen --real-anglo_saxons|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --harry_potter-dragon_species at 10" {
  result="$(counto=10 ./namgen --harry_potter-dragon_species|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --game_of_thrones-dothrakis at 10" {
  result="$(counto=10 ./namgen --game_of_thrones-dothrakis|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --descriptions-prophecys at 10" {
  result="$(counto=10 ./namgen --descriptions-prophecys|wc -l)"
  [[ "$result" -eq 80 ]]
}
@test "test namgen --star_wars_the_old_republic-chiss at 10" {
  result="$(counto=10 ./namgen --star_wars_the_old_republic-chiss|wc -l)"
  [[ "$result" -eq 10 ]]
}
@test "test namgen --destiny-vexs at 10" {
  result="$(counto=10 ./namgen  --destiny-vexs|wc -l)"
  [[ "$result" -eq 10 ]]
}

@test "test namgen --seed determinism" {
  r1=$(./namgen -c 5 --seed 4242)
  r2=$(./namgen -c 5 -S 4242)
  [[ "$r1" == "$r2" ]]
}

@test "test namgen --seed with specialized generator" {
  r1=$(./namgen --fantasy-dragons -c 3 --seed 777)
  r2=$(./namgen --fantasy-dragons -c 3 -S 777)
  [[ "$r1" == "$r2" ]]
}

@test "test namgen --unique deduplication" {
  # With test/test containing only 1 word, asking for 10 unique names must yield exactly 1
  count_single=$(./namgen -c 10 -u | wc -l)
  [[ "$count_single" -eq 1 ]]

  # With specialized generator, asking for 25 unique names yields 25 unique items
  count_gen=$(./namgen --fantasy-dragons -c 25 -u | wc -l)
  uniq_gen=$(./namgen --fantasy-dragons -c 25 -u | sort -u | wc -l)
  [[ "$count_gen" -eq 25 ]]
  [[ "$uniq_gen" -eq 25 ]]
}

@test "test namgen --json output format" {
  out=$(./namgen -c 3 --json)
  first_char=$(echo "$out" | head -n 1)
  last_char=$(echo "$out" | tail -n 1)
  [[ "$first_char" == "[" ]]
  [[ "$last_char" == "]" ]]
}

@test "test namgen --csv output format" {
  header=$(./namgen -c 3 --csv | head -n 1)
  line_count=$(./namgen -c 3 --csv | wc -l)
  [[ "$header" == '"name"' ]]
  [[ "$line_count" -eq 4 ]]
}

@test "test namgen --slug format" {
  out=$(./namgen -c 5 --slug)
  # Ensure only lowercase, digits, and hyphens
  invalid_chars=$(echo "$out" | grep -v '^[a-z0-9-]*$' || true)
  [[ -z "$invalid_chars" ]]
}

@test "test natural English spelling aliases" {
  ./namgen --descriptions-backstories -c 1
  ./namgen --descriptions-cities -c 1
  ./namgen --towns_and_cities-cities -c 1
}

@test "test namgen.wasm CLI runner" {
  if ! command -v node >/dev/null 2>&1; then
    skip "node not found"
  fi
  if [ ! -f "wasm/namgen.js" ]; then
    skip "wasm/namgen.js not built"
  fi
  result=$(node wasm/namgen-cli.js --fantasy-dragons -c 5 | wc -l)
  [[ "$result" -eq 5 ]]
}

@test "test namgen.wasm deterministic seed" {
  if ! command -v node >/dev/null 2>&1; then
    skip "node not found"
  fi
  if [ ! -f "wasm/namgen.js" ]; then
    skip "wasm/namgen.js not built"
  fi
  r1=$(node wasm/namgen-cli.js --fantasy-dragons -c 3 --seed 12345)
  r2=$(node wasm/namgen-cli.js --fantasy-dragons -c 3 --seed 12345)
  [[ "$r1" == "$r2" ]]
}

