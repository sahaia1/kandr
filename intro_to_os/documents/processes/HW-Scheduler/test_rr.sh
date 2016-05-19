for i in `seq 1 200`
do
    ./scheduler.py -p RR -l 100,200,300 -q $i -c 
    sleep 2
done
