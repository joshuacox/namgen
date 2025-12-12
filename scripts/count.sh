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
    #--agent \

do_aider () {
  this_new_name=$1
  export this_new_flag=$2
  this_genscript=$3
  this_lib_file="${this_new_name}_lib.cpp"
  this_lib_h_file="${this_new_name}_lib.h"
  if [[ ! -f src/${this_lib_file} ]]; then
    echo "doing ${this_lib_file}"
  fi
}

main () {
set -u
GEN_DIRS=$(find ${SOURCE_DIR} -maxdepth 1 -mindepth 1 -type d|shuf)

countzero=0
for gendir in ${GEN_DIRS}; do
  #echo ${gendir}
  basedir=$(basename ${gendir})
  countone=0
  
  #GEN_SCRIPTS=$(find ${gendir} -maxdepth 1 -mindepth 1 -type f -iname '*.js'|grep -v '.*min.js$'|sed 's/wildstar_//'|shuf)
  GEN_SCRIPTS=$(find ${gendir} -maxdepth 1 -mindepth 1 -type f -iname '*.js'|grep -v '.*min.js$'|shuf)
  for genscript in ${GEN_SCRIPTS}; do
    #echo ${genscript}
    filename=$(basename ${genscript})
    #echo "${filename}"
    filename_no_ext="${filename%.*}"
    new_name="$(echo ${basedir}-${filename_no_ext}|sed 's/wildstar_//')"
    new_flag="--${new_name}"
    do_aider ${new_name} ${new_flag} ${genscript}
    #set -x
    #((++countone))
    if [[ ${countone} -gt ${counto} ]]; then
      echo "${countone} countone hit ${counto}"
      break
    fi
    #set +x
  done
  #((++countzero))
  if [[ ${countzero} -gt ${counto} ]]; then
    #echo "${countzero} countzero hit ${counto}"
    break
  fi
done
}

main $@ |wc -l
