#include "../includes/rpn.hpp"

int main() {
    //std::vector<std::string> expression = {"2", "3", "-"};
    std::string str = "2 + 5 * 8";
    rpn::Expression exp = rpn::stringToExpression(str);
    rpn::infixToPostfix(exp);

    return 0;
}