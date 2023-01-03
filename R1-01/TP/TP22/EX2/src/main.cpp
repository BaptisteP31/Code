#include <iostream>
#include "../include/file.hpp"

void askUser(std::string str, int& nb) {
    std::cout << str;
    std::string nbr;
    std::cin >> nbr;

    // Tries to convert to a integer
    try {
        nb = stoi(nbr);
    } catch (std::invalid_argument& ia) {
        std::cerr << "argument invalide, appuyez sur une touche pour continuer" << std::endl;
        std::cin.get();
        askUser(str, nb);
    }
}

size_t number_of_words(std::vector<std::string> words, size_t size) {
    size_t count = 0;

    /*
    for (size_t i = 0; i < words.size(); ++i) {
        if (words[i].size() == size)
            count ++;
    }
    */
    for (std::string i : words) {                
        if (i.size() == size)
            count++;
    }

    return count;
}

int main() {
    std::filesystem::path currentPath = std::filesystem::current_path();
    //std::filesystem::path pathToFile =  currentPath / "liste_de_mots_francais-UTF8-LF.txt";
    std::filesystem::path pathToFile = currentPath / "reduced_list.txt";
    std::vector<std::string> words = file_to_vector(pathToFile);

    int choice = 0;
    askUser("Entrez le nombre de lettres (0 pour quitter)> ", choice);

    if (choice == 0)
        return 0;


    std::cout << "Le nombre de mots avec " << choice << " lettre(s) est " << number_of_words(words, choice) << std::endl;

    return 0;
}