#!/bin/bash

echo -n "Enter a temperature in degrees Celsius: "

read degree

result=$(($degree * 9 / 5 + 32))

echo "Equivalent period: $result"