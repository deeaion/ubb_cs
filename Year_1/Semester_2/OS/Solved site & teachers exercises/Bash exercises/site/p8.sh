#!/bin/bash

#Display all the mounted file systems
# who are either smaller than than 1GB or
# have less than 20% free space.
IFS=$'\n'
file=$(cat df.fake.txt| sed -n '2,$p')
for line in $file; do
	#echo "$line l"
	size=`echo "$line"| awk '{print $2}'|sed 's@M@@'`
	#echo "$size"
	used=`echo "$line"| awk '{print $5}'|sed 's@%@@'`
	#echo "$used"
	if (( $size < 1024 || $used >= 80 )); then
		echo "$line"| awk '{print $NF}'
	fi
done
