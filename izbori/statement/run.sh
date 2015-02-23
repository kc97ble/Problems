#!/bin/bash
for ((i = 0; i < 10; i++)) do
echo $i
timeout 1s ./izbori < izbori.in.$i > izbori.out.$i
done
echo Judging...
./scoring
