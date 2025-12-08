@test "test namgen ${this_new_flag} at 10" {
  result="$(counto=10 ./namgen ${this_new_flag}|wc -l)"
  [[ "$result" -eq 10 ]]
}
