#!/bin/bash
#random product

echo -n "200000 " > input_number.txt
echo -n "566 " >> input_number.txt

for (( a=1; a <=100000; a++ ))
do
	ran=$(( (RANDOM % 100) - 50 ))
	echo -n "$ran " >> input_number.txt
done
echo -e " " >> input_number.txt
