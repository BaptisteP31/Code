#include <vector>

#include "convert.hpp"
#include "../../includes/CommonThings/commonthings.hpp"

namespace cl = color;
namespace ui = commonthings::userinput;

void askColorsRange(unsigned int rl, unsigned int rh, cl::RGB& color) {
    unsigned int r,b,g;

    do {
        ui::askUser(r, "Rouge [0-255]");
    } while(r < 0 || r > 255);
    
    ui::askUser(g, "Vert> [0-255]");
    ui::askUser(b, "Bleu> [0-255]");

    color.R = r; color.G = g; color.B = b;
}



int main() {

    cl::RGB rgb;
    askColorsRange(0, 255, rgb);
    //std::cout << rgb.R << rgb.G << rgb.B << std::endl;

    cl::HSL hsl = cl::convert::RGBtoHSL(rgb);
    //cl::HEX hex = cl::convert::RGBtoHEX(rgb);

    std::cout << "RGB(" << rgb.R << ", " << rgb.G << ", " << rgb.B << ")" << " / " 
              /*<< "HEX #" << hex << " / "*/
              << "HSL(" << hsl.H << "°, " << hsl.S << "%, "  << hsl.L << "%)" << std::endl;

    return 0;
}