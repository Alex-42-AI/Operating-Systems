read message
for user in $*
do
if test `who | grep $user | wc -l` -ne 0
then echo $message | write $user
fi
done
