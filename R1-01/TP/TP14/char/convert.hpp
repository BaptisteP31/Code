#pragma once
#include <map>
#include <string>

namespace color {
    
    struct RGB {
        //unsigned int rgbvalues[3];
        //unsigned short int R, G, B;
        //unsigned int R, G, B; // goes to 255
        unsigned char R, G, B;
    };

    struct HSL {
        //unsigned int hslvalues[3];
        float H, S, L;
    };

    // typedef std::string HEX; -> C
    using HEX = std::string; // -> C++

    //print color
    void print (const RGB& color);
    void print (const HSL& color);
    void print (const HEX& color); 

    //read
    void askForColor(RGB& color);
    void askForColor(HSL& color);
    void askForColor(HEX& color);

    namespace convert {

        HEX RGBtoHEX(const RGB& color);
        HEX UIntToHex(const unsigned char comp);
        HSL RGBtoHSL(const RGB& color);
        
    } // namespace convert

} // namespace color