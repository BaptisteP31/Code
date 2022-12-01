#include <string>
#include <fstream>
#include <iostream>
#include "../includes/files.hpp"

int main() {
    std::vector<std::string> sepLine;

    sepLine = file::split("24-03-2022 d7527265aa459e4b89dad7c547f89e5ea31abc88 hopscotch-map/README.md", ' ');
    
    for(std::string str : sepLine)
        std::cout << str << std::endl;

    return 0;
}