#!/bin/bash

if [ $# -eq 0 ]; then
	echo " USAGE: $0 dir"
	exit 1
fi


if [ ! -d $1 ]; then
        echo " USAGE: $0 dir"
        exit 1
fi


for f in `find "$1" -type f`; do
	if `echo "$f"| grep -q '.*\.log'`; then
		NEWC=`cat "$f"| sort`
		echo "$NEWC" >"$f"
	fi
done
