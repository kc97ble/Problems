#/bin/bash
for ((i = 0; i < 119; i++)) do
echo $i
timeout 2s ./pickup < pickup.in.$i > pickup.out.$i
done
echo Judging...
./judge
