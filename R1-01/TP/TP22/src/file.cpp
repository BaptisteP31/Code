#include <fstream>
#include <stdexcept>
#include <string>
#include "../include/file.hpp"

// Takes a file full of double values -> returns a vector of thoes values
std::vector<double> file_to_vector(std::filesystem::path pathToFile) {
   std::ifstream ifs(pathToFile);

    // Checks if the file has been correctly openned
    if (!ifs.is_open())
        throw std::runtime_error(0);

    std::vector<double> values;

    // Go through the file line by line
    double currentValue = 0;
    while(ifs >> currentValue)
        values.push_back(currentValue);

    return values;
}