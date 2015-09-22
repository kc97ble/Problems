#!/bin/bash
echo "Running small test"
timeout 240s ./aiwar < 1.in > aiwar.out
if diff -w aiwar.out 1.out > /dev/null ; then echo "Correct!"; 
  else echo "Incorrect"; fi
echo "Running large test"
timeout 480s ./aiwar < 2.in > aiwar.out
if diff -w aiwar.out 2.out > /dev/null ; then echo "Correct!"; 
  else echo "Incorrect"; fi

