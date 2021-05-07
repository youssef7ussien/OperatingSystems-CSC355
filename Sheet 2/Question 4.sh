#!/bin/bash

echo -n "Enter number: "
read number

echo -ne "Enter power: "
read power

# With for loop

result=1

for ((i=0 ; i<power ; i++)) 
do
    result=$(($result * $number))
done

echo "Result = $result"

# Without for loop
# echo "Result = $(($number**$power))"

