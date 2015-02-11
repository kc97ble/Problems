#!/bin/bash
n=0; x=0;
for ((c = 1; ; c++)) do
  if (! find $c.in > /dev/null); then break; fi
  let "x = x + 1";
  echo $c
  timeout 2s ./embroidery < $c.in > embroidery.out
  if diff -w $c.out embroidery.out > /dev/null ; then let "n = n + 1"; 
    else diff -w $c.out embroidery.out; fi
done
echo "Correct tests: $n/$x"
