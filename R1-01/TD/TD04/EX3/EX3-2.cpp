#include <iostream>

int getMin(const int tab[], int n)
{ // Récupère la plus petite valeur d'un tableau
    int min = tab[0];
    for (int i = 1; i < n; i++)
        if (tab[i] < min)
            min = tab[i];

    return min;
}

int main()
{
    int tab[] = {3, 5, 1};
    int len = sizeof(tab) / sizeof(tab[0]);
    std::cout << getMin(tab, len) << std::endl;

    return EXIT_SUCCESS;
}
