#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
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
                word += currentChar;
                toRet.push_back(word);
                return toRet;
            } else {
                word += currentChar;
            }
            i += 1;
        }
        return toRet;
    }

    std::vector<FileAttribute> readFile(const std::string &fn){
        std::ifstream file(fn); 
        std::string str2;
        std::vector<FileAttribute> ret;
        if(!file.is_open()) throw std::runtime_error("Fichier non ouvert");
        while(std::getline(file, str2)){
            FileAttribute attri;
            std::vector<std::string> values = split(str2, ' ');
            attri.shasum = values[1];
            attri.path = values[2];
            values = split(values[0], '-');
            attri.date.date = stoi(values[0]);
            attri.date.month = stoi(values[1]);
            attri.date.year = stoi(values[2]);
            ret.push_back(attri);
        }
        return ret;
    }
    std::vector<FileAttribute> sortPerDate(std::vector<FileAttribute>& v) {
        std::sort(v.begin(), v.end(), [](FileAttribute fa1, FileAttribute fa2){
            return std::make_tuple(fa1.date.year, fa1.date.month, fa1.date.date, fa1.path) < std::make_tuple(fa2.date.year, fa2.date.month, fa2.date.date, fa2.path);
        });
    }
    void sortPerSha(std::vector<file::FileAttribute> &v) {
    std::stable_sort(v.begin(), v.end(), [](FileAttribute fa1, FileAttribute fa2){
        return fa1.shasum < fa2.shasum;
    });
    }

}