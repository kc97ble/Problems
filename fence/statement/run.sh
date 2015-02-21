#!/bin/bash
for ((c = 1; c <= 15; c++)) do
echo $i
timeout 1s ./fence < fence.$c.in > fence.$c.out
done
./judge
