#!/bin/bash
#16.Pentru fiecare parametru din linia de comanda,
# daca el reprezinta un fisier, se va afisa cuvantul
# de lungime maxima. Afisarea se va face in ordine 
#decsrescatoare a lungimii cuvantului. Ceilalti parametri se vor
# scrie intr-un fisier cu numele 'eronat'.
if [ $# -eq 0 ]; then
	echo "Usage: "$0": numef altparams etc"
	exit 1
fi

cuvinte=""
for f in $*; do
	if [ -f "$f" ]; then
		curent_word=$(cat "$f"| awk '{ for (i=1;i<=NF;i++) { printf("%s\t",$i); lung= length ($i); printf("%d\n", lung) } }'| sort|uniq| sort -nr | head -n 1)
		w=$(cat "$f"| wc -c)
		if [ $w -ne 0 ];  then
			cuvinte+="$curent_word"
			cuvinte+="\t"
			cuvinte+="$f"
			cuvinte+="\n"
			#echo -e "$cuvinte"
		fi
	else
		echo "$f">eronat
	fi
done

cuvinte_sortate=$(echo -e "$cuvinte"| sort -k 2n)

echo -e "$cuvinte_sortate\n"

