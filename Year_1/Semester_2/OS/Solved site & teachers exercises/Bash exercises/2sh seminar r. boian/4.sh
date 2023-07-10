#!/bin/bash


if [ $# -eq 0 ]; then
	echo "You have not priveded any file"
	exit 1
fi
IFS=$'\n'
for f in $*;do
	if [ -f "$f" ];then
		echo "$f"
		NR_MAXIM_COLOANE=$(cat "$f"|awk 'BEGIN{nr_max=0} {if(nr_max<NF) {nr_max=NF} } END{printf("%d",nr_max)}')
		echo "$f $NR_MAXIM_COLOANE"
		NR_LINES=`wc -l <"$f"`
		sume=""
		IFS=$'\n'
		for i in $(seq 1 $NR_MAXIM_COLOANE); do
			coloana=$(cat "$f"| awk '{print $'$i'}')
			if ! `echo "$coloana"| grep -q -v -E '^[0-9]{1,}$'`;then
				#inseamna ca nu s-a gasit nimc so we are in the case of all numbers
				suma=$(echo "$coloana"| awk ' BEGIN{sum=0} {sum=sum+$1} END{printf("%d",sum)}')
				sume+="$suma"
				sume+=" "
			fi
		done
	echo -e "FISIER: "$f"\tNR_COL:"$NR_MAXIM_COLOANE"\tNR_LINES:"$NR_LINES"\n\tSUME"$sume""
	fi
done
 
