/*
Créer un programme qui demande à l'utilisateur une taille (c'est-à-dire une valeur de type size_t). 
Le programme alloue dynamiquement un tableau de « taille » valeurs réelles, puis il attend que l'utilisateur saisisse « taille » valeurs réelles. 
Enfin, il calcule et affiche la moyenne des « taille » valeurs.

Testez le bon fonctionnement de votre programme sur une série simple de quelques valeurs.

Avez-vous bien pensé à libérer la mémoire allouée lorsqu'elle n'est plus nécessaire ?

Savez-vous que si vous tapez plusieurs valeurs d'un coup (la taille, la valeur 1, la valeur 2, etc.) avant de taper sur la touche entrée, 
votre programme n'aura pas besoin de faire une pause en attendant la valeur suivante ? Essayez par exemple de lancer votre programme puis de 
copier/coller le bloc de texte suivant dans la console avant de valider une seule fois avec entrée :

5
1.1 2.2 3.3 4.4 5.5

Il est même possible d'utiliser une redirection du shell pour « injecter », avec son opérateur « < », 
le contenu d'un fichier de texte comme entrée standard (cin) d'un programme. Téléchargez le fichiers suivant [valeurs.txt] 
et tentez de l'injecter les 1000 valeurs qu'il contient comme source d'entrée pour votre programme en tapant « ./exo1 < valeurs.txt ». 
Obtenez-vous bien la moyenne « -16.0135 » ? Obtenez-vous la moyenne « -0.428094 » sur les 100 000 valeurs contenues dans cet autre fichier : [valeurs2.txt] ?
*/


//Usage : ./executable <valeurs.txt

#include <iostream>
#include "../../../includes/CommonThings/commonthings.hpp"

void printTab(int tab[], size_t size) { //Affiche les cases d'un tableau dans la sortie standard
    for(size_t i=0; i<size-1; ++i) {
        std::cout << tab[i] << ",";
    }
    std::cout << tab[size-1] << "." << std::endl;
}

int main() {
    size_t size;
    commonthings::userinput::askUser(size, "Taille");
    int *pst = nullptr;
    pst = new int[size];

    for(size_t i=0; i<size; ++i)
        std::cin >> pst[i];

    printTab(pst, size);
    delete[] pst;

    return EXIT_SUCCESS;
}