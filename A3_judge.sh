g++ A3*.cpp

if [ $? -eq 0 ];
then
    ls | grep results.txt &>/dev/null
    if [ $? -eq 0 ];
    then
        rm results.txt
    fi

    total=5
    wrong=0
    for i in $( seq 1 $total )
    do
        ./a.out $i.in > $i.out
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
