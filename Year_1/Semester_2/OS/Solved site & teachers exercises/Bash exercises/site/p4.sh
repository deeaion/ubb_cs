#!/bin/bash

if [ $# -eq 0 ]; then
	echo "USAGE: $0 dir"
	exit 1
fi

if [ ! -d $1 ]; then
        echo "USAGE: $0 dir"
        exit 1
fi


for l in `find $1 -type l`; do
	echo "LINK: $l"
	FTOPOINT=`file "$l"| awk 'END {print $NF}'`
	if [ ! -e "$FTOPOINT" ]; then
		echo "$FTOPOINT does not exist anymore!"
	fi
done
