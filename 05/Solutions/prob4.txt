file=$1
m=$2
n=$3
head -$m $file | tail -$n | sort -r
