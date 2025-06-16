dir=$1
read file
read line1 < "$file"
read line2 < <(seq -n 2p "$file")
for f in "$dir"/*
do
if [-f "$f"] then
tail -n +3 "$f" > tmp
echo "$line1" > $f
echo "$line2" >> $f
cat "$tmp" >> $f
rm -r tmp
fi
done
