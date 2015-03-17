#!/bin/bash
n=0; x=0;
for ((c = 0; ; c++)) do
  if (! find $c.in > /dev/null); then break; fi
  let "x = x + 1";
  echo Running test $c
  timeout 2s ./soi < $c.in > soi.out
  if diff -w $c.out soi.out > /dev/null ; then let "n = n + 1"; 
    else diff -w $c.out soi.out > /dev/null; fi
done
echo "Correct tests: $n/$x"
