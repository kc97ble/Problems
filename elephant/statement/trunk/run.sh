#!/bin/bash
n=0; x=0;
for ((c = 0; ; c++)) do
  if (! find $c.in); then break; fi
  let "x = x + 1";
  echo $c
  timeout 1s ./elephant < $c.in > elephant.out
  if diff -w $c.out elephant.out > /dev/null ; then let "n = n + 1"; 
    else diff -w $c.out elephant.out; fi
done
echo "Correct tests: $n/$x"
