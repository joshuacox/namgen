#!/usr/bin/env bash
SOURCE_DIR=".javascript-fantasy-names-deprecated/generators"
source .venv/bin/activate
: ${counto:=0}
reads=''
mass_reader () {
for cpp_lib in $(ls ./src/*lib.cpp); do
  reads="$reads --read ${cpp_lib}"
done
for h_lib in $(ls ./src/*lib.h); do
  reads="$reads --read ${h_lib}"
done
}

do_aider () {
  this_new_name=$1
  export this_new_flag=$2
  this_genscript=$3
  this_lib_file="${this_new_name}_lib.cpp"
  this_lib_h_file="${this_new_name}_lib.h"
  if [[ -f src/${this_lib_file} ]]; then
    echo "skipping ${this_lib_file}"
  else
    set -eu
    echo "doing ${this_lib_file}"
    # Check for uncommitted changes
    if [[ $(git status --porcelain) ]]; then
      echo "Git working directory is dirty. Executing command..."
      git add .
      git commit -am 'tidy up'
    else
      echo "Git working directory is clean."
    fi
    git checkout main 
    git checkout -b "${this_new_name}"
    envsubst '${this_new_flag}' \
      < test/test.tpl \
      >> test/full.bats
    ./ignorer.sh
    time aider-ce \
    --read test/full.bats \
    --read "${genscript}"  \
    $reads \
    --file man/namgen.1 \
    --file src/namgen.cpp \
    --file "src/${this_lib_file}" \
    --file "src/${this_lib_h_file}" \
    --file CMakeLists.txt \
    --file README.md \
    -m "I'd like to add a new flag ${this_new_flag} that replicates the functionality in ${this_genscript} in cpp, add this as a lib in ${this_lib_file}_lib.cpp and include this functionality in namgen.cpp, update CMakeLists.txt to build ${this_lib_file}_lib.cpp and include it in the installation, update the man page."
    bats test/full.bats
    set +e
    echo $reads|grep "src/$this_lib_file" > /dev/null
    if [[ ! $? -eq 0 ]]; then
      reads="$reads --read src/$this_lib_file"
    fi
    echo $reads|grep "src/$this_lib_h_file" > /dev/null
    if [[ ! $? -eq 0 ]]; then
      reads="$reads --read src/$this_lib_h_file"
    fi
    set -e
    if [[ ! $? -eq 0 ]]; then
      loopster -t ./test.sh -l ./iter.sh
    fi
  fi
}

main () {
set -u
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
