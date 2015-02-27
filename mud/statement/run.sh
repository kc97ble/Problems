#!/bin/bash
g++ mud.cpp -o mud 
n=0; x=0;
for ((c = 1; ; c++)) do
  if (! find $c.in > /dev/null); then break; fi
  let "x = x + 1";
  echo Running test $c
  timeout 1s ./mud < $c.in > mud.out 
  if diff -w $c.out mud.out > /dev/null ; then let "n = n + 1"; 
    else diff -w $c.out mud.out; fi
done
echo "Correct tests: $n/$x"
