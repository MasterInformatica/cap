#!/bin/bash

TAM=$1

EXE="g 0 1 2 3"
PROG="./cholesky-"

for e in $EXE; do
    for i in {1..4}; do
	$PROG$e $TAM
    done
    echo "---------------------------------------------------------------------------"
done



