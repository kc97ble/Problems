#!/bin/bash
g++ shelf2.cpp -o shelf2 
n=0; x=0;
for ((c = 1; ; c++)) do
  if (! find $c.in > /dev/null); then break; fi
  let "x = x + 1";
  echo Running test $c
  timeout 1s ./shelf2 < $c.in > shelf2.out 
  if diff -w $c.out shelf2.out > /dev/null ; then let "n = n + 1"; 
    else diff -w $c.out shelf2.out; fi
done
echo "Correct tests: $n/$x"
