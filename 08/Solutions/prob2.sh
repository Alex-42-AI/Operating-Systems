dir0=$1
dir1=$2
n=`ls $dir0 | grep *.c | wc -l`
m=`ls $dir1 | grep *.c | wc -l`
a=$((n + m))
if test $a -gt 20
then
touch c_files_new
for f in $dir0/*.c
do
echo $f >> c_files_new
done
for f in $dir1/*.c
do
echo $f >> c_files_new
done
chmod 444 c_files_new
else
echo total c files:
echo $a
fi
