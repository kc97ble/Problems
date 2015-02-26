#!/bin/bash
for ((c = 1; c <= 12; c++)) do
echo $c
timeout 1s ./job < job.$c.in > job.$c.ans
done
./judge
