!#/bin/bash
for ((i = 0; i < 74; i++)) do
echo $i
timeout 2s ./adict < adict.in.$i > adict.out.$i
done
./judge
