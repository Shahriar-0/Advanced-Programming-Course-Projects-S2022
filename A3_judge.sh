g++ A3*.cpp -o A3

if [ $? -eq 0 ];
then
    ls | grep results.txt &>/dev/null
    if [ $? -eq 0 ];
    then
        rm results.txt
    fi

    unzip A3_testcases.zip &>/dev/null
    total=5
    wrong=0
    for i in $( seq 1 $total )
    do
        ./A3 $i.in > $i.out
        cmp -s $i.out $i.ans 
        if [ $? -eq 1 ];
        then   
            wrong=$((wrong+1))
            echo "test number $i: " >> results.txt
            diff $i.out $i.ans >> results.txt
            echo "________________________________" >> results.txt
        fi
    done
    echo "$total tests, $(expr $total - $wrong) right, $wrong wrong"
fi
