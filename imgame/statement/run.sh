#!/bin/bash
for ((c = 0; c < 153; c++)) do
echo $i
./imgame < imgame.in.$c > imgame.out.$c
done
echo Judding...
./judge
