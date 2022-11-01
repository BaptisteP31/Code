/*
Écrivez une fonction qui supprime tous les éléments de valeur 0 du tableau.
13, 0, 0, 10, 2, 0, 14, 0 → 13, 10, 2, 14
*/

#include <iostream>

void removeZero(int val[], size_t& size) { //Retire les 0 d'un tableau
    size_t write = 0;
    for (size_t read=0; read<size; read++) { //Lis chaque case du tableau
        if(val[read] == 0)
            continue; //Avance si la valeur est 0
        else 
            val[write++]=val[read]; //Écrit la dernière valeur en train d'être lue dans un case libre (0)
    }
    size=write; //Ajuste la taille du tableau en fonction du nombre de 0 enlevés
}
