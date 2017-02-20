#!/bin/bash
rm -r results
mkdir results

g++ -std=c++11 main.cpp -o sorting

for i in 100 1000 10000 20000
do
    fname=`date +%s%3N`
    sleep 1
    echo "$i " >> "results/$fname.txt"
    for j in `seq 1 10`
    do
       #sleep 1
       ./sorting $i random $i 100 >> "results/$fname.txt"
    done
done

python graphic.py results

