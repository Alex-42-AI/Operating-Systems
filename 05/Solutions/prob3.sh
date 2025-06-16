user=$1
who | grep $user | cut -f1 -d' ' | wc -l
