#include <string>
#include <fstream>
#include <iostream>
#include "../includes/files.hpp"

int main() {

    std::vector<file::FileAttribute> sepLine = file::readFile("file.txt");
    //file::sortPerSha(sepLine);

    std::cout << sepLine[0].date.date << std::endl;
    std::cout << sepLine[0].date.month << std::endl;
    std::cout << sepLine[0].date.year << std::endl;
    std::cout << sepLine[0].shasum << std::endl;
    std::cout << sepLine[0].path << std::endl;

    return 0;
}