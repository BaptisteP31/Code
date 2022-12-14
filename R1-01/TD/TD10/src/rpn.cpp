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
        return (input_expression == "*") || (input_expression == "+") || (input_expression == "-") || (input_expression == "/");
    }

    // Precedent
    int prec(const std::string& str) {
        if (str == "/" || str == "*")
            return 2;
        else if (str == "+" || str == "-")
            return 1;
        return 0;
    }


    // * Converts infox to postfix
    Expression infixToPostfix(Expression input_expression) {
        std::stack<std::string> operators;
        Expression output_expression;

        for(std::string i : input_expression) {
            // If the current i is an operand -> output
            if (isNumeric(i))
                output_expression.push_back(i);

            // If the current i is a ( -> operators stack
            else if (i == "(")
                operators.push(i);

            // If the current i is a ) -> append and pop until (
            else if (i == ")") {
                while (operators.top() != "(") {
                    output_expression.push_back(operators.top());
                    operators.pop();
                }
                operators.pop();
            }

            // If i is an operator
            else {
                while (!operators.empty() && prec(i) <= prec(operators.top())) {
                    output_expression.push_back(operators.top());
                    operators.pop();
                }
                operators.push(i);
            }
        }

        // Pop the remaining elements in operators stack
        while (!operators.empty()) {
            output_expression.push_back(operators.top());
            operators.pop();
        }

        return output_expression;
    }

    std::string operate(const double val1, const double val2, const std::string op) {
        if (op == "+")
            return std::to_string(val2 + val1);
        else if (op == "-")
            return std::to_string(val2 - val1);
        else if (op == "/")
            return std::to_string(val2 / val1);
        else if (op == "*")
            return std::to_string(val2 * val1);
        return "";
    }

    double eval(Expression expression) {
    // * Evluates the expression -> return result
        std::stack<std::string> operands;

        for(std::string i : expression) {
            // If the current i is an operand -> operand stack
            if (isNumeric(i)) {
                operands.push(i);
            } else {
                // If the current i is an operator -> evaluate it
                double val1 = stod(operands.top());
                operands.pop();
                double val2 = stod(operands.top());
                operands.pop();
                operands.push(operate(val1, val2, i));
            }
        }
        double evalResult = stod(operands.top());
        return evalResult;
    }

    std::string toString(Expression expression) {
    // * Converts expression to string
        std::string result = "";
        for(std::string i : expression)
            result += i;
        return result;
    }
    
    bool isWellParenthesized(Expression input_expression) {
    // TODO Checks if the expression is well parenthesized
        size_t count = 0;
        for(std::string i : input_expression)
            if (i == "(") {
                count += 1;
                if (count < 1)
                    return false;
            }
            else if (i == ")")
                count -= 1;
        return true;
    }
} // ! Namespace rpn