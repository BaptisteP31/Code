#include "convert.hpp"

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

    } // namespace convert

} // namespace color