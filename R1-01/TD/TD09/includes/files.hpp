#pragma once
#include <string>
#include <vector>

namespace file {

    struct DATE {
        unsigned short int month, date, year;
    };

    struct FileAttribute {
        DATE date;
        std::string shasum, path;
    };

    std::vector<std::string> split(const std::string& str, char =' ');
    std::vector<FileAttribute> readFile(const std::string& fileName);
    std::vector<FileAttribute> sortPerDate(std::vector<FileAttribute>& v);
    void sortPerSha(std::vector<FileAttribute>& v);
} // namespace file