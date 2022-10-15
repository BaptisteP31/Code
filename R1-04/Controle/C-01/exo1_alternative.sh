#!/bin/bash

cat $1 | while read ligne
do
    ls $2 | while read file
    do
        if [[ $file == $ligne ]];
        then
            var=$(grep $3 $2$file)
            if [[ $var != "" ]];
            then
            echo $ligne $var >> Resultat.txt
            fi
        fi
    done
done
