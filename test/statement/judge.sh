#!/bin/bash
declare task=$1;
declare	limit=$2;
declare mode=$3;
declare -i nTest=0;
declare -i point=0;
ulimit -s unlimited;
if ! g++ "$task.cpp" -std=c++11 -O2 -lm -DSKY > /dev/null 2>&1; then echo "Compilation Error"; exit 2; fi;
if [ "$mode" == "challenge" ]; then touch summary.txt; fi;
for test in $task/*.in; do
	declare verdict="Judgement Failed";
	declare i=${test: $((${#task}+1)): $((${#test}-${#task}-4))};
	timeout $limit ./a.out < "$task/$i.in" > ans 2> /dev/null;
	declare -i error=$?;
	if [ $error != 0 ]; then
		if [ $error == 124 ]; then verdict="Time limit exceeded";
		else verdict="Runtime error"; fi;
	else
		if ! ./$task/checker "$task/$i.in" ans "$task/$i.out"; then verdict="Wrong answer"; 
		else verdict="OK"; fi;
	fi;
	if [ "$mode" != "ACM" ]; then
		echo "Test $i: $verdict";
		if [ "$verdict" == "OK" ]; then point=$(($point+1)); fi;
	else
		if [ "$verdict" != "OK" ]; then echo "$verdict on test $i"; rm ans; rm a.out; exit 1; fi;
	fi;
	nTest=$(($nTest+1));
done;
if [ "$mode" == "OI" ]; then echo "Result: $point of $nTest"; fi;
if [ "$mode" == "ACM" ]; then echo "Accepted"; fi;
if [ "$mode" == "challenge" ]; then ./$task/summary < summary.txt; rm summary.txt; fi;
rm ans; rm a.out;
exit 0;
