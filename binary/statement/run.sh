#!/bin/bash
for ((c = 1; c <= 55; c++)) do
echo $c
timeout 2s ./binary < $c > $c.out
done
echo Judging...
./judge
