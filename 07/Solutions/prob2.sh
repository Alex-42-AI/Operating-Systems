a=$1
b=$2
c=$a
while test $c -le $b
do
echo $c
c=$(($c + 1))
done
