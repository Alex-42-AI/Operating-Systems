ps -e -o uid= -o pid= -o cmd= | while read uid pid cmd do
for target_uid in "$@" do
if ["$uid" = "$target_uid"] then
echo "$uid" "$pid" "$cmd"
fi
done
done
