#!/bin/bash

# use awk:
# internal const var NR: number of record in job
awk 'NR == 10' file.txt

# use sed:
sed -n '10p' file.txt

# tail and head:
tail -n+10 file.txt | head -n1

# start from the 10th line til the end
tail -n+10 file.txt

# print all, except the last 10 lines
head -n-10 file.txt

# print from the 4th line to the 10th line
head -n10 file.txt | tail -n+4
