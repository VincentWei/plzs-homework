#!/bin/bash

SYS=`uname`
if [ $SYS = Darwin ]
then
    TIME='/usr/bin/time -l -h -o'
elif [ $SYS = Linux ]
then
    TIME='/usr/bin/time -v -o'
fi

if [ $# -ne 1 ]
then
    echo 'Usage: judge.sh <PROGRAM>'
    exit 1
fi

prog=$1

if ! [ -x "./$prog" ]
then
    echo "No such file or not an executable: ./$prog; try to make it..."
    make $prog
    if [ $? -ne 0 ]
    then
        echo "Failed to make $prog"
        exit 1
    fi
fi

problem=${prog%-*}

for inf in cases-$problem/*.in
do
    rm -f tmp.out

    outf=${inf%in*}out
    timef=${inf%in*}time
    if [ -r $outf ]
    then
        $TIME $timef ./$prog < $inf > tmp.out
        diff $outf tmp.out
        if [ $? -eq 0 ]
        then
            echo "Case $inf passed"
        else
            echo "Case $inf failed"
            exit 1
        fi
    else
        echo "No valid output file ($outf), skip case: $inf"
    fi
done

rm -f tmp.out
exit 0
