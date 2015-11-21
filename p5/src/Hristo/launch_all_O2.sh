#!/bin/bash

TAM=$1

make all_flags_O2

for e in $(ls cholesky_all_O2*); do
    for i in {1..4}; do
	./$e $TAM
    done
    echo "---------------------------------------------------------------------------"
done

make clean
