#include <fstream>
#include <stdexcept>
#include <iostream>
#include "../include/file.hpp"

// Takes a file full of double values -> returns a vector of thoes values
std::vector<std::string> file_to_vector(std::filesystem::path pathToFile) {
   std::ifstream ifs(pathToFile);

    // Checks if the file has been correctly openned
    if (!ifs.is_open()) {
        std::cerr << "Le fichier est introuvable" << std::endl;
        exit(0);
    }

    std::vector<std::string> words;

    // Go through the file line by line
    std::string currentWord = "";
    while(ifs >> currentWord)
        words.push_back(currentWord);

    return words;
}