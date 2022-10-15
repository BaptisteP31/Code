#!/bin/bash

ligne=""


for file in $@
do
    read ligne
    while [[ "$ligne" != "fin" ]]
    do
        echo $ligne >> $file
        read ligne
    done
done

mkdir Fichiers

declare -i somme=0

for file in $@
do
    cp $file Fichiers
    var=$(wc -c $file)
    somme+=${var% *}
done

cd Fichiers

echo $somme > TailleFichiers.txt
