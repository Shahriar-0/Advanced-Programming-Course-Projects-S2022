#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <source_file>"
    exit 1
fi

g++ "$1"

if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

indir="in"
outdir="out"
errdir="err"

for i in $(ls $indir); do
    infile="$indir/$i"
    expected="$outdir/${i%.*}.out"

    ./a.out <"$infile" >"$outfile"

    diff "$outfile" "$expected" &>/dev/null
    if [ $? -ne 0 ]; then
        echo -e "\033[31mTest $i failed\033[0m"
        ((failed++))
        errfile="$errdir/${i%.*}.err"
        diff "$outfile" "$expected" >"$errfile"
    else
        echo -e "\033[32mTest $i passed\033[0m"
        ((passed++))
    fi

done

echo -e "\033[32m$passed/$num_tests tests passed\033[0m"
echo -e "\033[31m$failed/$num_tests tests failed\033[0m"
