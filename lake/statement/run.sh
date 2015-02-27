#!/bin/bash
g++ lake.cpp -o lake 
n=0; x=0;
for ((c = 1; ; c++)) do
  if (! find $c.in > /dev/null); then break; fi
  let "x = x + 1";
  echo Running test $c
  timeout 1s ./lake < $c.in > lake.out 
  if diff -w $c.out lake.out > /dev/null ; then let "n = n + 1"; 
    else diff -w $c.out lake.out; fi
done
echo "Correct tests: $n/$x"
