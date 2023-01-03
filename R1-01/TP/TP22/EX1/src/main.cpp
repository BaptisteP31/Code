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

int main() {
    std::filesystem::path currentPath = std::filesystem::current_path();
    std::filesystem::path pathToFile =  currentPath / "MasseAtomiqueParElement.txt";
    std::vector<double> values = file_to_vector(pathToFile);

    /* Outputs the vector
    for (auto i : values)
        std::cout << i << std::endl;

    std::cout << std::endl;
    */

    int choice = 0;
    askUser("Entrez le numéro atomique (0 pour quitter)> ", choice);

    if (choice == 0)
        return 0;

    if (choice < 0 || size_t(choice) > values.size()) {
        std::cerr << "Le numéro de l'élément n'existe pas" << std::endl;
        return 0;
    }

    std::cout << "La masse atomique de l'élément " << choice << " est " << values[choice+1] << std::endl;
    

    return 0;
}