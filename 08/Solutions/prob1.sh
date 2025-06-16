dir0=$1
dir1=$2
a=0
b=0
for f in $dir0/*.out
do
a=$((a + 1))
done
for f in $dir1/*.out
do
b=$((b + 1))
done
if test $a -gt $b
then
mkdir prob1_directory
echo prob1_directory
for f in $dir0/*
do
if test -f $f -a -r $f -a -w $f
then mv $f prob1_directory
fi
done
fi
