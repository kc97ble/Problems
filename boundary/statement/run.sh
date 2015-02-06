#!/bin/bash
for ((c = 0; c < 26; c++)) do
echo $i
timeout 3s ./boundary < boundary.$c.in > boundary.$c.out
done
./judge
