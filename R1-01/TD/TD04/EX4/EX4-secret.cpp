#include <iostream>

#include <iostream>

struct PointChar { //coordonnées d'un point et caratère à placer à ce point
    int x,y;
    char c;
};

int contains(const PointChar tab[], size_t tabSize, int x0, int y0) { //Renvoie le caratère contenu aux coordonnées x0 y0
    for(size_t i=0; i<tabSize; i++) {
        if(tab[i].x == x0 && tab[i].y == y0)
            return tab[i].c;
    }
    return -1;
}

void display(PointChar t[], const int size=84){ //Affiche un ASCII art à partir d'un tableau
    for(int y=0; y<size; y++){
        for(int x=0; x<size; x++){
            char c = contains(t, size, x, y);
            if(c != -1) std::cout << c;
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
}


int main() {
    PointChar secret[84] = {
    {1,0,'_'},{2,0,'('},{3,0,'\\'},{8,0,'|'},{9,0,'@'},{10,0,'@'},
    {11,0,'|'},{0,1,'('},{1,1,'_'},{2,1,'_'},{3,1,'/'},{4,1,'\\'},
    {5,1,'_'},{6,1,'_'},{8,1,'\\'},{9,1,'-'},{10,1,'-'},{11,1,'/'},
    {13,1,'_'},{14,1,'_'},{3,2,'\\'},{4,2,'_'},{5,2,'_'},{6,2,'_'},
    {7,2,'|'},{8,2,'-'},{9,2,'-'},{10,2,'-'},{11,2,'-'},{12,2,'|'},
    {15,2,'|'},{19,2,'_'},{20,2,'_'},{7,3,'\\'},{9,3,'}'},{10,3,'{'},
    {12,3,'/'},{13,3,'\\'},{15,3,')'},{16,3,'_'},{18,3,'/'},{20,3,'_'},
    {21,3,'\\'},{7,4,'/'},{8,4,'\\'},{9,4,'_'},{10,4,'_'},{11,4,'/'},
    {12,4,'\\'},{14,4,'\\'},{15,4,'_'},{16,4,'_'},{17,4,'O'},{19,4,'('},
    {20,4,'_'},{21,4,'_'},{6,5,'('},{7,5,'-'},{8,5,'-'},{9,5,'/'},
    {10,5,'\\'},{11,5,'-'},{12,5,'-'},{13,5,')'},{18,5,'\\'},{19,5,'_'},
    {20,5,'_'},{21,5,'/'},{6,6,'_'},{7,6,')'},{8,6,'('},{11,6,')'},
    {12,6,'('},{13,6,'_'},{5,7,'`'},{6,7,'-'},{7,7,'-'},{8,7,'-'},
    {9,7,'\''},{10,7,'\''},{11,7,'-'},{12,7,'-'},{13,7,'-'},{14,7,'`'}
    };
        
    size_t secretSize = 84;
    display(secret);

    return EXIT_SUCCESS;
}