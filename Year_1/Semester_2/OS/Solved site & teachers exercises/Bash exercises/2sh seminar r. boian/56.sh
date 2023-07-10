#!/bin/bash


#@56.Sa se scrie un program shell care primeste ca si parametru un nume de director
# si un fisier. Programul va afisa toate fisierele din director si subdirectoarele 
#sale care au extensia .c si care sunt mai noi decat fisierul dat ca al doilea parametru.

if [ $# -ne 2 ] ; then
	echo "Usage: $0 dir file"
	exit 1
fi


if [ ! -d "$1" ]; then
	echo "U did not provide a directory"
	exit 1
fi

#trebuie sa gasesti path ul fisierului . Ca tu il ai dar gandestete daca e in alta parte
file=$(find . -type f | grep '^.*/'"$2"'')
echo "$file"

data_file=$( find "$file" -printf '%Ty-%Tm-%Td')
an_f=$(echo "$data_file"| awk '  BEGIN { FS="-" } { printf("%d",$1)}' )
zi_f=$(echo "$data_file"| awk '  BEGIN { FS="-" } { printf("%d",$3)}' )
month_f=$(echo "$data_file"| awk ' BEGIN { FS="-" } { printf("%d",$2)}' )



for f in `find "$1" -type f`; do
	if `echo "$f"| grep -q '^.*\.c$'`; then
		an=$(find "$f" -printf '%Ty')
		if (( $an > $an_f )); then
			echo "$f"
		elif (( $an == $an_f )); then
			month=$(find "$f" -printf '%Tm')
			if (($month>$month_f)); then
				echo "$f"
			elif (($month==$month_f)); then
				day=$(find "$f" -printf '%Td')
				if (( $day > $zi_f)); then
					echo "$f"
				fi
			fi
		fi
fi
done


