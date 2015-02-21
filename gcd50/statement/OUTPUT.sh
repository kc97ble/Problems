#!/bin/bash

ls *.in

if ! g++ -O2 JURY.cpp -o JURY
then exit
fi

for i in *.in; do 
	time ./JURY < $i > ${i%.in}.out
done
	
