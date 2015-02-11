#!/bin/bash
n=0; x=0;
for ((c = 1; ; c++)) do
  if (! find $c.in > /dev/null); then break; fi
  let "x = x + 1";
  echo Running test $c
  timeout 1s ./chess < $c.in > output.out 
  if diff -w $c.out output.out > /dev/null ; then let "n = n + 1"; 
    else diff -w $c.out output.out > /dev/null; fi
done
echo "Correct tests: $n/$x"
