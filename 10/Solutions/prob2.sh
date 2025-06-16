n=$1
dir=$2
shift 2
users=("$@")
read msg
output_file="prob2_file.txt"
touch "$output_file"
read -a logged_users <<< $(who | cut -f1 | sort -u)
for u in "${users[@]}"
do
for l in "${logged_users[@]}"
do
if test "$u" = "$l"
then
if test -f "$dir/$u"
then
num=$(ls "$dir" | wc -l)
if [$count -gt $n]
then
echo "%msg" | write $u
else
"$u $num" > $output_file
fi
fi
fi
done
done
sort -o $output_file $output_file
