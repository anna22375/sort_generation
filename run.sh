#!/bin/bash
g++ -std=c++14 main.cpp -o sorting
for i in 100 1000 10000 20000
do
    rm "$i.txt"
    for j in `seq 1 10`
    do
       #sleep 1
       ./sorting $i random $i 100 >> "$i.txt"
    done
done
python graphic.py

