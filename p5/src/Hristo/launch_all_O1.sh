#!/bin/bash

TAM=$1

make all_flags_O1

for e in $(ls cholesky_all_O1*); do
    for i in {1..4}; do
	./$e $TAM
    done
    echo "---------------------------------------------------------------------------"
done

make clean
