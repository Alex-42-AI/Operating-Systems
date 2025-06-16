dir=$1
n=$2
if test -d $dir
then
for f in ./$dir/*
do
if test wc -c < $f -gt $n
then echo "$f"
fi
done
else echo no such directory
fi
