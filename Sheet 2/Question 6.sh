#!/bin/bash

number=1 ; sum=0 ; count=0

while [ $number -ne 0 ]
do
    echo -n "Enter a positive integer: "
    read number
    
    if [ $number -gt 0 ]
    then
        sum=$(($sum + $number)) ; count=$(($count + 1))
	elif [ $number -lt 0 ]
	then 
		echo -n "Error, "
	fi
done

if [ $sum -eq 0 ]
then
	echo "No AVERAGE."
else
	echo "Average = $(($sum / $count))"
fi