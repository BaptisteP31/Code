#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "../includes/files.hpp"

namespace file {

    std::vector<std::string> split(const std::string& str, char) {

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
    std::vector<FileAttribute> sortPerDate(std::vector<FileAttribute>& v) {
        std::sort(v.begin(), v.end(), [](FileAttribute fa1, FileAttribute fa2){
            return std::make_tuple(fa1.date.year, fa1.date.month, fa1.date.date, fa1.path) < std::make_tuple(fa2.date.year, fa2.date.month, fa2.date.date, fa2.path);
        });
    }
    void sortPerSha(std::vector<FileAttribute>& v) {
        std::stable_sort(v.begin(), v.end(), [](FileAttribute fa1, FileAttribute fa2){
            return fa1.shasum < fa2.shasum;
        });
    }
}