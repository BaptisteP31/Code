/***********************************************************************/
// This program is a command line tool used to evaluate postfixed
// and infixed mathematical expressions
// Usage:
//  calc [OPTION...]
//
//  -f, --format arg  Specify expression input format [auto | infix | postfix]
//                    (default: postfix)
//  -i, --input arg   Input expression
//  -d, --debug       Show trace only
//  -h, --help        Print usage
//
/***********************************************************************/
#include <iostream>
#include <string>
#include "../includes/rpn.hpp"
#include "../includes/cxxopts.hpp"

bool isAuto(const std::string& format) { return format == "auto"; }
bool isInfix(const std::string& format) { return format == "infix"; }
bool isPostfix(const std::string& format) { return format == "postfix"; }

int main(int argc, char const *argv[]) {
  // Setting up commands lines options
  cxxopts::Options options("calc", "This program is a command line tool used to evaluate postfixed and infixed mathematical expressions");
  options.add_options()
      ("f,format", "Specify expression input format [auto | infix | postfix]", cxxopts::value<std::string>()->default_value("postfix"))
      ("i,input", "Input expression", cxxopts::value<std::string>())
      ("d,debug", "Show trace only", cxxopts::value<bool>()->default_value("false"))
      ("h,help", "Print usage")
  ;

  // Parsing commands lines
  auto result = options.parse(argc, argv);
  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    exit(0);
  }

  // Asking for input if no expression was given
  std::string input;
  if (result.count("input")) {
    input = result["input"].as<std::string>();
  } else {
    std::cout<<"Enter an expression> ";
    std::getline(std::cin, input);
  }

  // Parsing input and building the corresponding expression
  rpn::Expression input_expression = rpn::stringToExpression(input);

  // Define expression format (infix, postfix or auto)
  std::string format = result["format"].as<std::string>();
  if (isAuto(format))
    format = rpn::isValidOperator(input_expression.back())?"postfix":"infix";

  if (!isInfix(format) && !isPostfix(format)) {
    std::cerr<<"/!\\ Error - invalid format specifier ["<<format<<"]"<<std::endl;
    exit(0);
  }

  // If it's an infix expression we convert first
  rpn::Expression expression = isInfix(format)?rpn::infixToPostfix(input_expression):input_expression;

  // If 'debug' option isn't used, we evaluate the expression
  bool isDebug = result["debug"].as<bool>();
  if (!isDebug) {
    double value = rpn::eval(expression);
    std::cout<<rpn::toString(expression)<<" => "<<value<<std::endl;
  } else {
    std::cout<<"Debug - info"<<std::endl;
    std::cout<<"============"<<std::endl;
    std::cout<<"input: "<<input<<std::endl;
    std::cout<<"format: "<<format<<std::endl;
    std::cout<<"expression: "<<rpn::toString(expression)<<std::endl;
    if (isInfix(format))
      std::cout<<"parenthesis: "<<(rpn::isWellParenthesized(input_expression)?"ok":"nope")<<std::endl;
  }

  return 0;
}
