#!/bin/bash
n=0; x=0;
for ((c = 1; ; c++)) do
  if (! find $c.in); then break; fi
  let "x = x + 1";
  echo $c
  timeout 3s ./knight < $c.in > knight.out
  if diff -w $c.out knight.out > /dev/null ; then let "n = n + 1"; 
    else diff -w $c.out knight.out; fi
done
echo "Correct tests: $n/$x"
