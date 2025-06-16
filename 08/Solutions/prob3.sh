dir=$1
if test ! -d "$dir"
then mkdir $dir
n=0
for f in ./*
do
if test -f "$f" -a -r "$f"
then cp "$f" $dir
else n=$((n + 1))
fi
done
echo $n
fi
