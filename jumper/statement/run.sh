#!/bin/bash
for ((c = 0; c < 38; c++)) do
echo $c
./jumper < jumper.in.$c > jumper.expect.$c
done
