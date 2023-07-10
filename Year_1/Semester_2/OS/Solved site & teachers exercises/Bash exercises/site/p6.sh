#!/bin/bash

if [ $# -eq 0 ]; then
	echo "USAGE:$0 dir"
	exit 1
fi

if [ ! -d $1 ]; then
        echo "USAGE:$0 dir"
        exit 1
fi


for f in `find $1 -type f -perm -a=w`; do
	echo "BEFORE:"
	ls -lR "$f"| awk '{ printf("%s ",$1) ; printf("%s\n", $NF)}'
	chmod a-w "$f"
	echo "AFTER:"	
	 ls -lR "$f"| awk '{ printf("%s ",$1) ; printf("%s\n", $NF)}'
done


