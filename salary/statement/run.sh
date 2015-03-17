#!/bin/bash
for ((c = 0; c < 20; c++)) do
echo $c
./salary < salary.in.$c > salary.out.$c
done
./judge
