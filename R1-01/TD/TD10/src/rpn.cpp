#include "../includes/rpn.hpp"

namespace rpn {

    // * Expression is std::vector<std::string>

    // Converts input string to expression
    Expression stringToExpression(std::string input) {
        std::string word;
        char separator = ' ';

        std::vector<std::string> expression_to_return;
        size_t i = 0;

        for(char currentChar: input) {

            if( currentChar == separator) {
                expression_to_return.push_back(word);
                word = "";

            } else if(i == input.length()-1) {
                word += currentChar;
                expression_to_return.push_back(word);
                return expression_to_return;

            } else {
                word += currentChar;
            }

            i += 1;
        }
        return expression_to_return;
    }

    // Checks for valid operator
    bool isValidOperator(std::string& input_expression) {
        return (input_expression == "*") || (input_expression == "+") || (input_expression == "-");
    }

    // TODO Converts infox to postfix
    Expression infixToPostfix(Expression input_expression) {

    }

    // TODO Evluates the expression -> return result
    double eval(Expression expression) {

    }

    // TODO Converts expression to string
    std::string toString(Expression expression) {

    }
    
    // TODO Checks if the expression is well parenthesized
    bool isWellParenthesized(Expression input_expression) {

    }
} // ! Namespace rpn