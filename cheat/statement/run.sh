#!/bin/bash
g++ cheat.cpp -o cheat 
n=0; x=0;
for ((c = 1; ; c++)) do
  if (! find $c.in > /dev/null); then break; fi
  let "x = x + 1";
  echo Running test $c
  timeout 1s ./cheat < $c.in > cheat.out 
  if diff -w $c.out cheat.out > /dev/null ; then let "n = n + 1"; 
	    else echo "Test 5c incorrect"; fi
done
echo "Correct tests: $n/$x"
