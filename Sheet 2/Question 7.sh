#!/bin/bash

number=1 ; sum=0 ; count=0 ; reverseNum=""

echo -n "Enter a positive integer: "
read number

while [ $number -gt 0 ]
do
	sum=$(($sum + $number % 10))
    reverseNum=$(echo $reverseNum$(($number % 10)))
    number=$(($number / 10))
    count=$(($count + 1))
done

echo "1- The number digits in reverse order: $reverseNum"
echo "2- The sum of its digits: $sum"
echo "3- The average of its digits: $(($sum / $count))"