read text
for file in $*
do
echo $file: `grep $text $file | wc -l`
done
