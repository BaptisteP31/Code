#include <iostream>
#include "rpn.hpp"
#include <vector>

/* -- README -------------------------------------------------------------------*/
// Use ./run-test-postfix to test your RPN calculator.
// The expected output is shown below
//
/* -- Expected output ----------------------------------------------------------*/
// Test postfixed expression
// ========================
// Well formed expressions
// -----------------------
// >> 5 4 +
// 9
//
// >> 5 4 + 2.3 -
// 6.7
//
// >> 0.5 0.2 0.7 - *
// -0.25
//
// >> 0.3 -4 / 3 + 1.5 *
// 4.3875
//
//
// Misformed expressions
// ---------------------
// >> 4 0 /
// /!\ Error - Division by zero, we go back
// 4
//
// >> 5 +
// /!\ Error - you need at least 2 operands to apply operator [+]
// 5
//
// >> 0.5 0.2 - -
// /!\ Error - you need at least 2 operands to apply operator [-]
// 0.3
//
// >> 8 2 %
// /!\ Error - unknow symbol [%]
// 2
/* -----------------------------------------------------------------------------*/

void printTitle(const std::string& title, char c = '=') {
std::cout<<title<<std::endl;
  for (size_t k=0; k<title.length(); k++)
    std::cout<<c;
  std::cout<<std::endl;
}

void runTest(const std::string& title, const std::vector<rpn::Expression>& test_set) {
  printTitle(title, '-');
  for (const rpn::Expression& test : test_set) {
    // Print the rpn (postfixed) expression
    std::cout << ">> " << rpn::toString(test) << std::endl;

    // Eval the rpn expression and print the result
    std::cout << rpn::eval(test)  << std::endl << std::endl;
  }
  std::cout<<std::endl;
}

int main() {
  printTitle("Test postfixed expression", '=');

  std::vector<rpn::Expression> test_set_1 = {
    { "5", "4", "+" },
    { "5", "4", "+", "2.3", "-" },
    { "0.5", "0.2", "0.7", "-", "*" },
    { "0.3", "-4", "/", "3", "+", "1.5", "*" }
  };
  runTest("Well formed expressions", test_set_1);

  std::vector<rpn::Expression> test_set_2 = {
    { "4", "0", "/" },
    { "5", "+" },
    { "0.5", "0.2", "-", "-" },
    { "8", "2", "%" }
  };
  runTest("Misformed expressions", test_set_2);

  return 0;
}
