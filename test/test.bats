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

@test "make clean" {
  make clean
}
@test "make" {
  make
}
@test "test namgen at 10" {
  result="$(counto=10 ./namgen|wc -l)"
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
