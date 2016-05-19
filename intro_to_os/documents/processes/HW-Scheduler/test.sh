for i in `seq 1 100`
do
    j=$((i+100))
    k=$((i+200))
    ./scheduler.py -p SJF -l $i,$j,$k -c
done
