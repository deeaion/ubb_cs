#!/bin/bash

if [ $# -eq 0 ]; then
	echo "Requires file"
	exit 1
fi
string=""
nr_lines=`wc -l < "$1"`
file=$(cat "$1")
for line in $file; do
	if [ $nr_lines -ne 1 ] ;then
		string+="$line"
		string+="@scs.ubbcluj.ro,"
	else
	   	string+="$line"
 		string+="@scs.ubbcluj.ro"
	fi
	nr_lines=$(($nr_lines-1))
done

 
echo "$string"
