n=$1
m=$2
if test $n -le $m
then expr \( $m - $n \)
else expr \( $n - $m \)
fi
