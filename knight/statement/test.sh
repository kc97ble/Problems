#!/bin/bash
n=0;
if diff -w 21.out 21.try > /dev/null ; then let "n = n + 1";
fi
echo Correct tests $n
