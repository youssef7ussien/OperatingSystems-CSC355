#!/bin/bash

echo -n "Enter number: "
read number

for ((i=2 ; i<$number/2 ; i++))
do
    if [ $(($number%i)) -eq 0 ]
    then
        echo "$number is not a prime number"
        exit
    fi
done

echo "$number is a prime number"
    