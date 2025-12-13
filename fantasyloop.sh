#!/usr/bin/env bash
SOURCE_DIR=".javascript-fantasy-names-deprecated/generators"
source .venv/bin/activate
: ${counto:=0}
: ${time_delta:=0}
: ${VERBOSITY:=0}
reads=''
mass_reader () {
for cpp_lib in $(ls ./src/*lib.cpp); do
  reads="$reads --read ${cpp_lib}"
done
for h_lib in $(ls ./src/*lib.h); do
  reads="$reads --read ${h_lib}"
done
}

add_score() {
    SCORE_MESSAGE=$1
    echo "${this_new_name},${model_name},$(date +%Y-%m-%d-%H:%M:%S),$(date +%s),${time_delta},${loopster_count},${SCORE_MESSAGE}" >> score.csv
}

# Function to be called when Ctrl+C is pressed
ctrl_c() {
    echo -e "\n** Ouch! SIGINT received (Ctrl+C). Performing cleanup..." >&2
    time2=$(date +%s.%N)
    export time_delta=$(echo "scale=40;${time2} - ${time1}" | bc)
    add_score "interrupt-fail"
    #echo "${this_new_name},${model_name},${time_delta},${loopster_count},interrupt-fail" >> score.csv
    echo "** Cleanup complete. Exiting script." >&2
    exit 1  # Exit the script after handling the signal
}
# Set the trap: call the ctrl_c function when SIGINT (INT) is received
trap ctrl_c INT

clean_dirty_git () {
  if [[ $(git status --porcelain) ]]; then
    echo "Git working directory is dirty. committing everything..."
    git add .
    aider-ce --commit
  else
    echo "Git working directory is clean."
  fi
}

do_aider () {
  this_new_name=$1
  loopster_count=0
  export this_new_flag=$2
  this_genscript=$3
  export model_name=$(shuf -n 1 models)
  export weak_model_name=$(shuf -n 1 weak_models)
  this_lib_file="${this_new_name}_lib.cpp"
  this_lib_h_file="${this_new_name}_lib.h"
  if [[ -f src/${this_lib_file} ]]; then
    echo "skipping ${this_lib_file}"
  else
    #set -eu
    set -u
    echo "doing ${this_lib_file}"
    # Check for uncommitted changes
    clean_dirty_git
    git checkout main 
    git checkout -b "${this_new_name}"
    envsubst '${this_new_flag}' \
      < test/test.tpl \
      >> test/full.bats
    ./ignorer.sh
    export time1=$(date +%s.%N)
    export FILES="--file man/namgen.1 --file src/namgen.cpp --file src/${this_lib_file} --file src/${this_lib_h_file} --file CMakeLists.txt --file README.md"
    export READS="--read test/full.bats --read ${genscript} ${reads}"
    export MODELS="--model ollama_chat/${model_name} --editor-model ollama_chat/${model_name} --weak-model ollama_chat/${weak_model_name}"
    export MESSAGE="I'd like to add a new flag ${this_new_flag} that replicates the functionality in ${this_genscript} in cpp, add this as a lib in ${this_lib_file}_lib.cpp and include this functionality in namgen.cpp, update CMakeLists.txt to build ${this_lib_file}_lib.cpp and include it in the installation, update the man page."
    export AIDER_OPTS="${MODELS} ${FILES} ${READS}"
    export AIDER_CMD="aider-ce ${AIDER_OPTS}"

    time ${AIDER_CMD} -m "${MESSAGE}"

    time2=$(date +%s.%N)
    export time_delta=$(echo "scale=40;${time2} - ${time1}" | bc)
    clean_dirty_git
    set +e
    bats test/full.bats
    if [[ ! $? -eq 0 ]]; then
      add_score "initial-fail"
      #echo "${this_new_name},${model_name},${time_delta},${loopster_count},initial-fail" >> score.csv
      loopster -c 5 \
        --success-cleanup ./successLoopster.sh \
        --fail-cleanup ./failLoopster.sh \
        -t ./test.sh \
        -l ./iter.sh
    else
      clean_dirty_git
      git checkout -b "${this_new_name}_success"
      add_score "eagle"
      scripts/reset2main.sh
      #echo "${this_new_name},${model_name},${time_delta},${loopster_count},eagle" >> score.csv
    fi
    #set -e
    echo $reads|grep "src/$this_lib_file" > /dev/null
    if [[ ! $? -eq 0 ]]; then
      reads="$reads --read src/$this_lib_file"
    fi
    echo $reads|grep "src/$this_lib_h_file" > /dev/null
    if [[ ! $? -eq 0 ]]; then
      reads="$reads --read src/$this_lib_h_file"
    fi
  fi
}

main () {
set -u
if [[ ${VERBOSITY} -gt 10 ]];then
  set -x
fi
GEN_DIRS=$(find ${SOURCE_DIR} -maxdepth 1 -mindepth 1 -type d|shuf)

countzero=0
for gendir in ${GEN_DIRS}; do
  echo ${gendir}
  basedir=$(basename ${gendir})
  countone=0
  
  #GEN_SCRIPTS=$(find ${gendir} -maxdepth 1 -mindepth 1 -type f -iname '*.js'|grep -v '.*min.js$'|sed 's/wildstar_//'|shuf)
  GEN_SCRIPTS=$(find ${gendir} -maxdepth 1 -mindepth 1 -type f -iname '*.js'|grep -v '.*min.js$'|shuf)
  for genscript in ${GEN_SCRIPTS}; do
    echo ${genscript}
    filename=$(basename ${genscript})
    #echo "${filename}"
    filename_no_ext="${filename%.*}"
    new_name="$(echo ${basedir}-${filename_no_ext}|sed 's/wildstar_//')"
    new_flag="--${new_name}"
    echo do_aider ${new_name} ${new_flag} ${genscript}
    do_aider ${new_name} ${new_flag} ${genscript}
    #set -x
    ((++countone))
    if [[ ${countone} -gt ${counto} ]]; then
      echo "${countone} countone hit ${counto}"
      break
    fi
    #set +x
  done
  ((++countzero))
  if [[ ${countzero} -gt ${counto} ]]; then
    echo "${countzero} countzero hit ${counto}"
    break
  fi
done
}

time main $@
