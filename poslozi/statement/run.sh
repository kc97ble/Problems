#!/bin/bash
n=0; x=0;
if ([ ! -f poslozi.cpp ]); then echo "File not found"; else g++ poslozi.cpp -o poslozi;
fi
for ((c = 1; ; c++)) do
  if (! find $c.in); then break; fi
  let "x = x + 1";
  echo $c
  timeout 1s ./poslozi < $c.in > poslozi.out
  if diff -w $c.out poslozi.out > /dev/null ; then let "n = n + 1"; 
    else diff -w $c.out poslozi.out; fi
done
echo "Correct tests: $n/$x"
