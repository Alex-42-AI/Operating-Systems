terminals=`who | cut -c10-16`
for t in $terminals
do
ps -e | grep $t
done
