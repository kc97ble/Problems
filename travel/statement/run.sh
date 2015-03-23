#!/bin/bash
n=0; x=0;
for ((c = 0; ; c++)) do
  if (! find $c.in > /dev/null); then break; fi
  let "x = x + 1";
  echo Running test $c
  timeout 2s ./travel < $c.in > travel.out
  if diff -w $c.out travel.out > /dev/null ; then let "n = n + 1"; 
    else diff -w $c.out travel.out > /dev/null; fi
done
echo "Correct tests: $n/$x"
