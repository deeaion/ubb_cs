#!/bin/bash

if [ $# -eq 0 ]; then
	echo "USAGE: $0 dir"
	exit 1
fi

if [ ! -d $1 ]; then
	echo "USAGE: $0 dir"
        exit 1
fi
nr_f=0
for f in `find $1 -type f`; do
	if `echo "$f"| grep -q '.*\.c'`; then
		nr_l=`wc -l < "$f"`
		if [ $nr_l -gt 500 ]; then
			echo "$f"
			nr_f=$(($nr_f+1))
			if [ $nr_f -eq 2 ]; then
				break
			fi
		fi
	fi
done
