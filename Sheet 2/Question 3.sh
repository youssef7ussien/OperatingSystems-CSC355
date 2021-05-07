#!/bin/bash

echo -n "Enter your gross salary: "

read salary

if [ $salary -gt 2000 ]
then
	salary=$(($salary - $salary * 15 / 100))

elif [ $salary -ge 1000 ] && [ $salary -lt 2000 ]
then
	salary=$(($salary - $salary * 10 / 100))

fi

echo "Your net salary after tax reduction: $salary"
