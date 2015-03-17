#!/bin/bash
g++ roads.cpp -o roads 
n=0; x=0;
for ((c = 1; ; c++)) do
  if (! find $c.in > /dev/null); then break; fi
  let "x = x + 1";
  echo Running test $c
  timeout 1s ./roads < $c.in > roads.out 
  if diff -w $c.out roads.out > /dev/null ; then let "n = n + 1"; 
    else diff -w $c.out roads.out; fi
done
echo "Correct tests: $n/$x"
