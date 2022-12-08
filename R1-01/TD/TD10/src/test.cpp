#include <iostream>
#include "../includes/rpn.hpp"

int main() {
    std::string str = "4 - ( 5 * 6 )";
    rpn::Expression exp = rpn::stringToExpression(str);
    rpn::Expression expPostFix = rpn::infixToPostfix(exp);
    
    for (auto i : expPostFix)
        std::cout << i;
    std::cout << std::endl;
    
    return 0;
}