user=$1
while true
do
lines=`who | grep $user | wc -l`
if test $lines -ne 0
then echo found
break
fi
sleep 1
done
