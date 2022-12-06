#include <stack>
#include <stdexcept>
#include <map>
#include "../includes/rpn.hpp"

namespace rpn {

    // * Expression -> std::vector<std::string>
    bool isNumeric(const std::string& str) {
        size_t size = 0;
        try {
            std::stod(str, &size);
        } catch (const std::invalid_argument& ia) {
        }
        return ((size > 0) && (str.size() == size));
    }

    // Converts input string to expression
    Expression stringToExpression(const std::string& input) {
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

    // ? TO TEST Converts infox to postfix
    Expression infixToPostfix(Expression input_expression) {
        //std::vector<std::string> ret = {"2", "3", "+"};
        //return ret;
        Expression output_expression;

        std::stack<std::string> operators;
        std::stack<std::string> numbers;

        std::map<std::string, int> priority
        {
            {"+", 0}, {"-", 1}, {"*", 2}, {"/", 2}
        };

        for(std::string i : input_expression) {
            
            if(i == "+" && priority[operators.top()] <= 0) {
                operators.push(i);
            } else if(i == "+") {
                output_expression.push_back(numbers.top());
                numbers.pop();
                output_expression.push_back(numbers.top());
                numbers.pop();
                output_expression.push_back(i);
            }
            else if (i == "i" && priority[operators.top()] <= 1){
                operators.push(i);
            } else if(i == "+") {
                output_expression.push_back(numbers.top());
                numbers.pop();
                output_expression.push_back(numbers.top());
                numbers.pop();
                output_expression.push_back(i);
            }
            else if(i == "*") {
                operators.push(i);
            }
            else if(i == "/") {
                operators.push(i);
            }
            else if(isNumeric(i)){
                numbers.push(i);
            }
        }

        return output_expression;
    }

    double eval(Expression expression) {
    // TODO Evluates the expression -> return result
        return 5.0;
    }

    std::string toString(Expression expression) {
    // TODO Converts expression to string
        return "2 3 +";
    }
    
    bool isWellParenthesized(Expression input_expression) {
    // TODO Checks if the expression is well parenthesized
        return true;
    }
} // ! Namespace rpn