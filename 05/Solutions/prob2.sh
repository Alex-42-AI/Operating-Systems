f1=$1
f2=$2
cat $f1 > tmp
cat $f2 > $f1
cat tmp > $f2
