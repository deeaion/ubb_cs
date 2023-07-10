#!/bin/bash
#7. Sa se scrie un fisier de comenzi care preia un fisier de intrare dat
# ca parametru si creeaza din el un alt f
#isier (al carui nume este dat ca parametru) in care pastreaza 
#doar cuvintele care contin litere mici. 
#Fisierul se va ordona alfabetic, si se vor semnala liniile consecutive identice.
if [ $# -ne 2 ]; then
	echo "Usage $0 nume_fisier_intrare nume_fisier_output"
	exit 1
fi

F_I="$1"
F_O="$2"

if [ ! -f "$F_I" ]; then
	echo " "$F_I" not a file"
	exit 1
fi

continut=""
p_line=""
count_l=0
IFS=$'\n'
for l in `cat "$F_I"`; do
        line=$(echo "$l"| grep -o '\b[a-z]*\b'| tr '\n' ' ')
        #echo "$line"
                continut+="$line"
                continut+="\n"
done
#echo -e "$continut"
IFS=$'\n'
continut_s=$(echo -e "$continut"|sort)
#echo "$continut_s"
nr_linii=$(echo -e "$continut_s"| wc -l)
if [ $nr_linii -eq 0 ]; then
	echo "There were no words found"
	exit 0
fi 
continut_f=""
IFS=$'\n'
for l in `echo -e "$continut_s"`; do
	#echo "$l"
	if [ "$p_line" == "$l" ]; then
			continut_f+="---"
			continut_f+="$l"
			continut_f+="\n"
			p_line="$l"
	else 
		continut_f+="$l"
                continut_f+="\n"
                p_line="$l"
	fi
done

echo -e "$continut_f"| sed '$d'>"$F_O"



		
	


