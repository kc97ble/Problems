#!/bin/bash

name="squares"
for f in {0..9}{0..9} ; do
  if [ -e $f ] ; then
    echo "Test $f"
    cp "${f}" "${name}.in"
    time $1
    ./check.exe "${name}.in" "${name}.out" "${f}.a" || exit
  fi
done
