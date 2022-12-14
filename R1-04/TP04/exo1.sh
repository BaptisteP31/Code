#!/bin/bash
#liste fichiers, nb arg indéterminé

rep=$1 #Répertoire en premier argument

read -p "Chaine de char> " chain

countarg=0
countchain=0
temp=0
	
arg=$@

for i in $arg
do
	temp=$(cat $1 | grep -c $chain)
	
	if [ $temp -ge 1  ]
	then
		countchain=$(($countchain + $temp))
	fi

	shift
	countarg=$(($countarg + 1 ))
done
echo $countchain "Chars correspondants"

ratio=$((($countchain / $countarg)*100))

if [ $ratio -ge 50 ]
then
	echo "Au moins la moitié des fichiers fournis contiennent la chaine de caractère"
fi	
