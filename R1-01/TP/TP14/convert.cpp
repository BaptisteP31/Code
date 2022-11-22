#include "convert.hpp"
#include <math.h>
#include <cmath>
#include <algorithm>
#include <iostream>

namespace color {
    
    namespace convert {

        HEX RGBtoHEX(const RGB& color) {
            
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

        /*
        HSL RGBtoHSL(const RGB& color) {
            unsigned int rr=0, gg=0, bb=0;
            float M=1, m=0, d=0, L=0, S=0, H=0;

            M = std::max({color.R, color.G, color.B});
            m = std::min({color.R, color.G, color.B});

            L = (1/2*(M + m))/255;

            if(L > 0) 
                S = d/(1 - (2L-1));
            else if(L == 0)
                S = 0;

            
            if(gg >= bb)
                H = std::pow(std::cos((rr - (1/2*gg) - (1/2*bb) / sqrt(std::pow(rr, 2) + std::pow(gg, 2) + std::pow(bb, 2) - rr*gg - rr*bb - gg*bb))), -1);
            else if(bb > gg)
                H = 360 - std::pow(std::cos((rr - (1/2*gg) - (1/2*bb) / sqrt(std::pow(rr, 2) + std::pow(gg, 2) + std::pow(bb, 2) - rr*gg - rr*bb - gg*bb))), -1);
            


            HSL hsl;
            hsl.H = H;
            hsl.S = S;
            hsl.L = L;

            return hsl;
        }
        */

       HSL RGBtoHSL(const RGB& color) {
            float r, g, b; 
            r = (float)color.R / 255;
            g = (float)color.G / 255;
            b = (float)color.B / 255;

            float M, m;
            M = std::max({r, g, b});
            m = std::min({r, g, b});
            std::cout << M << " " << m << std::endl;

            float C = M - m;
            //std::cout << C << std::endl;

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
            std::cout << L << std::endl;

            float S;
            if(L == 0 || L == 1)
                S = 0;
            else if(L > 0 && L <= 1/2)
                S = C / (2*L);
            else if(L > 1/2 && L < 1)
                S = C / (2 - (2*L));

            std::cout << S << std::endl;

            HSL hsl;
            hsl.H = 60*h;
            hsl.S = S*100;
            hsl.L = L*100;

            return hsl;            

       }


    } // namespace convert

} // namespace color