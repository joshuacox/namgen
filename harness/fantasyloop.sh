#!/usr/bin/env bash
HARNESS_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${HARNESS_DIR}/.." && pwd)"

cd "${REPO_ROOT}"

SOURCE_DIR="${REPO_ROOT}/.javascript-fantasy-names-deprecated/generators"
if [[ -f "${REPO_ROOT}/.venv/bin/activate" ]]; then
  source "${REPO_ROOT}/.venv/bin/activate"
fi

: ${counto:=0}
: ${time_delta:=0}
: ${VERBOSITY:=0}

reads=''
mass_reader () {
  for cpp_lib in $(ls "${REPO_ROOT}"/src/*lib.cpp 2>/dev/null); do
    reads="$reads --read ${cpp_lib}"
  done
  for h_lib in $(ls "${REPO_ROOT}"/src/*lib.h 2>/dev/null); do
    reads="$reads --read ${h_lib}"
  done
}

add_score() {
    SCORE_MESSAGE=$1
    echo "${this_new_name},${AIDER_CMD},${model_name},${edit_format},$(date +%Y-%m-%d-%H:%M:%S),$(date +%s),${time_delta},${loopster_count},${SCORE_MESSAGE}" >> "${HARNESS_DIR}/score.csv"
}

# Function to be called when Ctrl+C is pressed
ctrl_c() {
    echo -e "\n** Ouch! SIGINT received (Ctrl+C). Performing cleanup..." >&2
    time2=$(date +%s.%N)
    export time_delta=$(echo "scale=40;${time2} - ${time1}" | bc)
    add_score "interrupt-fail"
    echo "** Cleanup complete. Exiting script." >&2
    exit 1  # Exit the script after handling the signal
}
trap ctrl_c INT

clean_dirty_git () {
  if [[ $(git status --porcelain) ]]; then
    echo "Git working directory is dirty. committing everything..."
    git add .
    time ${AIDER_CMD} ${AIDER_OPTS} \
      --commit 
  else
    echo "Git working directory is clean."
  fi
}

do_aider () {
  this_new_name=$1
  loopster_count=0
  export this_new_flag=$2
  this_genscript=$3
  export model_name=$(shuf -n 1 "${HARNESS_DIR}/models")
  export edit_format=$(shuf -n 1 "${HARNESS_DIR}/edit-formats")
  export weak_model_name=$(shuf -n 1 "${HARNESS_DIR}/weak_models")
  this_lib_file="${this_new_name}_lib.cpp"
  this_lib_h_file="${this_new_name}_lib.h"
  if [[ -f "src/${this_lib_file}" ]]; then
    echo "skipping ${this_lib_file}"
  else
    set -u
    echo "doing ${this_lib_file}"
    # Check for uncommitted changes
    clean_dirty_git
    git checkout main 
    git checkout -b "${this_new_name}"
    envsubst '${this_new_flag}' \
      < test/test.tpl \
      >> test/full.bats
    "${HARNESS_DIR}/ignorer.sh"
    export time1=$(date +%s.%N)
    export FILES="--file man/namgen.1 --file src/generator_registry.cpp --file src/${this_lib_file} --file src/${this_lib_h_file} --file README.md"
    export READS="--read test/full.bats --read ${genscript} ${reads}"
    export MODELS="--model ollama_chat/${model_name} --editor-model ollama_chat/${model_name} --weak-model ollama_chat/${weak_model_name}"
    export MESSAGE="I'd like to add a new flag ${this_new_flag} that replicates the functionality in ${this_genscript} in cpp, add this as a lib in src/${this_lib_file} and src/${this_lib_h_file}, register it in src/generator_registry.cpp, and update the man page."
    export AIDER_OPTS="${MODELS} ${FILES} ${READS}"
    export AIDER_CMD=$(shuf -n 1 "${HARNESS_DIR}/aider-cmds")

    time ${AIDER_CMD} ${AIDER_OPTS} -m "${MESSAGE}"

    time2=$(date +%s.%N)
    export time_delta=$(echo "scale=40;${time2} - ${time1}" | bc)
    clean_dirty_git
    set +e
    bats test/full.bats
    if [[ ! $? -eq 0 ]]; then
      add_score "initial-fail"
      loopster -c 5 \
        --success-cleanup "${HARNESS_DIR}/successLoopster.sh" \
        --fail-cleanup "${HARNESS_DIR}/failLoopster.sh" \
        -t "${REPO_ROOT}/test.sh" \
        -l "${HARNESS_DIR}/iter.sh"
    else
      clean_dirty_git
      git checkout -b "${this_new_name}_success"
      add_score "eagle"
      "${REPO_ROOT}/scripts/reset2main.sh"
    fi
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
  if [[ ${VERBOSITY} -gt 10 ]]; then
    set -x
  fi
  GEN_DIRS=$(find "${SOURCE_DIR}" -maxdepth 1 -mindepth 1 -type d | shuf)

  countzero=0
  for gendir in ${GEN_DIRS}; do
    echo "${gendir}"
    basedir=$(basename "${gendir}")
    countone=0
    
    GEN_SCRIPTS=$(find "${gendir}" -maxdepth 1 -mindepth 1 -type f -iname '*.js' | grep -v '.*min.js$' | shuf)
    for genscript in ${GEN_SCRIPTS}; do
      echo "${genscript}"
      filename=$(basename "${genscript}")
      filename_no_ext="${filename%.*}"
      new_name="$(echo ${basedir}-${filename_no_ext} | sed 's/wildstar_//')"
      new_flag="--${new_name}"
      do_aider "${new_name}" "${new_flag}" "${genscript}"
      ((++countone))
      if [[ ${countone} -gt ${counto} ]]; then
        echo "${countone} countone hit ${counto}"
        break
      fi
    done
    ((++countzero))
    if [[ ${countzero} -gt ${counto} ]]; then
      echo "${countzero} countzero hit ${counto}"
      break
    fi
  done
}

time main "$@"
