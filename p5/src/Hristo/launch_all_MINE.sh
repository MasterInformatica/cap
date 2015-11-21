#!/bin/bash

TAM=$1

make all_flags_MINE

for e in $(ls cholesky_all_MINE*); do
    for i in {1..4}; do
	./$e $TAM
    done
    echo "---------------------------------------------------------------------------"
done

make clean
