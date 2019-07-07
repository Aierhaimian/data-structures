#!/bin/bash
#random product

>array.txt

echo -n "10000 " > array.txt

function myRandom()
{
    min=$1;
    max=$2-$1;
    num=$(date +%s%N);
    ((retnum=num%max+min));
    echo $retnum;
}

for (( a=1; a <=10000; a++ ))
do
	ran=$(( (RANDOM % 10000) - 1 ));
#   ran=$(myRandom 2 10000);
	echo -n "$ran " >> array.txt;
done;
echo -e " " >> array.txt;
