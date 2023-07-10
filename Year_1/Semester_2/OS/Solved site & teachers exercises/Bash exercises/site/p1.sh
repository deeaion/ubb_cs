#!/bin/bash

users="$(cat who.fake.txt| awk '{ print $1}'| tr '\n' ' ')"
process="$(cat ps.fake.txt|  awk '{ print $1 }'| sort | uniq -c| sort -n)"
for user in `echo $users`; do
	nrp=`echo "$process"| grep ''$user''| awk '{print $1}'`
	echo "$user $nrp" 
done

