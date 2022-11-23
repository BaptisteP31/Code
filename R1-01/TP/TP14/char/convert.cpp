#include "convert.hpp"
#include <math.h>
#include <cmath>
#include <algorithm>
#include <iostream>

namespace color {
    
    namespace convert {

        HEX RGBtoHEX(const RGB& color) {
            HEX redHEX = UIntToHex(color.R);
            HEX greeHEX = UIntToHex(color.G);
            HEX blueHEX = UIntToHex(color.B);

            HEX colorHEX = redHEX + greeHEX + blueHEX;

            return colorHEX;
        }

        HEX UIntToHex(const unsigned char comp) {
            const char tabHex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
            const char V0 = comp%16,
                       V1 = (comp-V0)/16;

            std::string hex = "00";
            hex[0] = tabHex[V1];
            hex[1] = tabHex[V0];
            return hex;
        }

       HSL RGBtoHSL(const RGB& color) {
            float r, g, b; 
            unsigned short int rI, gI, bI;

            rI = (unsigned short int)color.R;
            gI = (unsigned short int)color.G;
            bI = (unsigned short int)color.B;

            r = (float)rI / 255;
            g = (float)gI / 255;
            b = (float)bI / 255;

            /*
            r = (float)color.R;
            g = (float)color.G;
            b = (float)color.B;
            */

            float M, m;
            M = std::max({r, g, b});
            m = std::min({r, g, b});

            float C = M - m;

            float h;
            if(C == 0)
                h = 0;
            else if(M == r)
                h = std::fmod( (g - b) / C, 6.0);
            else if(M == g)
                h = ((b - r) / C) + 2;
            else if(M == b)
                h = ((r - g) / C) + 4;

            float L = (float)1/2*(M + m);

            float S;
            if(L == 0 || L == 1)
                S = 0;
            else if(L > 0 && L <= 1/2)
                S = C / (2*L);
            else if(L > 1/2 && L < 1)
                S = C / (2 - (2*L));

            HSL hsl;
            hsl.H = 60*h;
            hsl.S = S*100;
            hsl.L = L*100;

            return hsl;            

       }

    } // namespace convert

} // namespace color