#include <string>
#include <vector>
#pragma once

namespace rpn {
    using Expression = std::vector<std::string>;

    Expression stringToExpression(const std::string& input);
    bool isValidOperator(std::string& input_expression);
    Expression infixToPostfix(Expression input_expression);

    double eval(Expression expression);
    std::string toString(Expression expression);
    
    bool isWellParenthesized(Expression input_expression);
} // ! Namespace rpn