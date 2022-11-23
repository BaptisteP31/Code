#include <iostream>
#include <vector>

#include "convert.hpp"

namespace cl = color;

void askBetween(unsigned int& color, unsigned int r1, unsigned int r2, std::string msg) {    
    color=r1;
    do {
        if(color < r1 || color > r2)
            std::cout << "Erreur: Nombre hors de la plage indiquée..." << std::endl;
        std::cout << msg;
        std::cin >> color;
    } while(color < r1 || color > r2);
}




int main() {


    unsigned int col_num;
    askBetween(col_num, 1, 8, "Entrer le nombre de couleurs à saisir[1-8]> ");
    
    cl::RGB rgb;
    std::vector<cl::RGB> rgbs;

    for(size_t i=0; i < col_num; ++i) {

        std::cout << "\nSaisir la couleur " << i+1 << "(R,G,B) :" << std::endl;

        unsigned int r, g, b;

        askBetween(r, 0, 255, "Rouge[0-255]> ");
        askBetween(g, 0, 255, "Vert[0-255]> ");
        askBetween(b, 0, 255, "Bleu[0-255]> ");

        rgb.R = r%256; rgb.G = g%256; rgb.B = b%256;

        rgbs.push_back(rgb);

        std::cout << std::endl;
    }

    cl::HSL hsl = cl::convert::RGBtoHSL(rgb);
    cl::HEX hex = cl::convert::RGBtoHEX(rgb);

    std::cout << "== Liste des couleurs ==" << std::endl;

    for(size_t i=0; i < col_num; ++i) {

        std::cout << "Couleur " << i+1 << ":" << std::endl;

        std::cout << "\x1b[38;2;" << (int)rgb.R << ";" << (int)rgb.B << ";" << (int)rgb.B << "m";

        std::cout << "▉▉▉▉" << "\x1B[38;2;200;200;200m"
              << " RGB(" << (int)rgbs.back().R << ", " << (int)rgbs.back().G << ", " << (int)rgbs.back().G << ")" << " / " 
              << "HEX #" << hex << " / "
              << "HSL(" << hsl.H << "°, " << hsl.S << "%, "  << hsl.L << "%)" << std::endl;

        rgbs.pop_back();

        std::cout << std::endl; 
    }

    return 0;
}