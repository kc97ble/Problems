#!/bin/bash
for ((i = 0; i < 10; i++)) do
echo $i
timeout 2s ./ecircle < ecircle.in.$i > ecircle.out.$i
done
./scoring
