#include <iostream>

void askUser(std::string things, double& a, char& b, double& c) {
    std::cout << things << " ?> ";
    std::cin >> a >> b >> c;
}

double calcul(double a, char b, double c) {
    switch (b) {
        case '+':
            return a + c;
            break;

        case '-':
            return a - c;
            break;

        case '/':
            return a / c;
            break;

        case '*':
            return a * c;
            break;

        default:
            std::cout << "Opération arithmétique inconnue" << std::endl;
            break;
    }
    return 0;
}

int main() {
    char operation;
    double nb1, nb2;
    askUser("Opération", nb1, operation, nb2);
    double result=0;
    
    std::cout << calcul(nb1, operation, nb2) << std::endl;

    return 0;
}