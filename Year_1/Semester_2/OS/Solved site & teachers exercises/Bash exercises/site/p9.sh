#!/bin/bash

#Write a script that finds in a given directory hierarchy,
# all duplicate files and displays their paths. 
#Hint: use checksums to detect whether two files are identical.


PD=$(find $1 -type f | sed 's@.*./@@'| sort|uniq -c | sort -nr| awk '{ if ( $1 > 1)  print $2}')
IFS=$'\n'
for line in $PD; do
	#echo "$line"	
	one=""
	found_one=0
	for f in `find "$1" -type f| grep ''"$line"''`; do
		if [ $found_one -ne 0 ]; then
			f_h=`md5sum "$f"| awk '{ print $1}'`
			if [ "$f_h" = "$this_h" ]; then
				echo "FOUND TWO EQUAL FILES $f and $one"
			fi
		else
			found_one=1
			this_h=`md5sum "$f"| awk '{ print $1}'`
			#echo "$this_h"
			one="$f"
		fi
	done
done
