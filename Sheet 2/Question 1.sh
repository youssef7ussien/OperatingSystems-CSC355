#!/bin/bash

echo -n "Enter a number of second: " 
read number

echo "Equivalent period: $((($number/60)/60)):$((($number/60)%60)):$(($number%60))"