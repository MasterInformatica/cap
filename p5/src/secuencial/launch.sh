#!/bin/bash

RUN=-1
TAM=0

function echo_help {
    echo "Help:"
    echo "    -h: Help."
    echo "    -a: OPTION. Lo que queremos correr [1..N]. Consulta codigo."
    echo "    -t TAM: Tamaño."
}

while getopts ":ha:t:" opt; do
    case $opt in
        h)
	    echo_help
	    exit
            ;;
        a)
	    RUN=$OPTARG
	    ;;
        t)
	    TAM=$OPTARG
	    ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            exit 1
            ;;
        :)
            echo "Option -$OPTARG requires an argument." >&2
            exit 1
            ;;
    esac
done

function flags_normales {
    make
    for e in $(ls cholesky-*); do
        for i in {1..4}; do
	    ./$e $1
        done
        echo "---------------------------------------------------------------------------"
    done
    make clean
}

function flags_OXs {
    make flags_$2
    for e in $(ls cholesky-*); do
        for i in {1..4}; do
	    ./$e $1
        done
        echo "---------------------------------------------------------------------------"
    done
    make clean
}


if [ $RUN -eq -1 ] || [ $TAM -eq 0 ]; then
    echo_help
    exit
fi

if [ $RUN -eq 0 ]; then
    flags_normales $TAM
    exit
fi

if [ $RUN -eq 1 ]; then
    flags_OXs $TAM "O1s"
    exit
fi

if [ $RUN -eq 2 ]; then
    flags_OXs $TAM "O2s"
    exit
fi

if [ $RUN -eq 1 ]; then
    flags_normales $TAM
    exit
fi

if [ $RUN -eq 1 ]; then
    flags_normales $TAM
    exit
fi

exit
