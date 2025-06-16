dir=$1
for f in ./$dir/*.c
do
echo "$f"
name="${f##*/}"
base="${name%.c}"
cc "$f" -o $dir/${base}.exe
done
