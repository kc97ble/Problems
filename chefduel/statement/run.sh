#!/bin/bash
for ((c = 0; c < 10; c++)) do
echo $c
timeout 5s ./chefduel < $c.in > $c.out
done
./judge
