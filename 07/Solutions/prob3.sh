a=$1
b=$2
k=$a
while test $k -le $b
do
echo $k
k=$((k + 1))
done
