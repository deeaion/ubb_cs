#!/bin/bash

if [ $# -eq 0 ]; then
	echo "USAGE $0 dir"
	exit 1
fi


while true; do
	for p in $*; do
		informatie=`ps -ef|awk '{printf("%d : ",$2); for (i=8;i<=NF;i++)  { printf ("%s ",$i); } print ""}'`
		if `echo "$informatie"|grep -q '[0-9]* : '"$p"' '`; then
			PID=$(echo "$informatie" | grep '[0-9]* : '"$p"' '| awk '{ print $1 }')
			echo "$PID"
			echo "FOUND A FAULTY PROCESS!!! WILL KILL IT NOW"
			kill -9 $PID
		fi	
	done
	sleep 10	
done


