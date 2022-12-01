#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include <iostream>

#include "../includes/files.hpp"

namespace file {
    std::vector<std::string> split(const std::string& str, char sep) {
        std::string word;
        std::vector<std::string> toRet;
        size_t i = 0;
        for(char currentChar: str) {
            if( currentChar == sep) {
                toRet.push_back(word);
                word = "";
            } else if(i == str.length()-1) {
                toRet.push_back(word);
                return toRet;
            } else {
                word += currentChar;
            }
            i += 1;
        }
        return toRet;
    }

    std::vector<FileAttribute> readFile(const std::string& fileName) {
        std::ifstream f(fileName);
        std::string str;
        std::vector<FileAttribute> ret;

        while(getline(f, str)) {
            FileAttribute fa;
            std::vector<std::string> token = split(str);
            fa.path = token[1];
            fa.shasum = token[2];
            token = split(token[0], '-');
            fa.date.date = (unsigned short int)std::stoi(token[0]);
            fa.date.month = (unsigned short int)std::stoi(token[1]);
            fa.date.year = (unsigned short int)std::stoi(token[2]);
            ret.push_back(fa);
        }
        return ret;
    }

}