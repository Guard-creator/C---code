#include <iostream>

int main() {

  char op;
  double num1;
  double num2;
  double result;

  std::cout << "************CALCULATOR************\n";

  std::cout << "Please put a Operator (- + * /): ";
  std::cin >> op;

  std::cout << "Enter num#1: ";
  std::cin >> num1;

  std::cout << "Enter num#2: ";
  std::cin >> num2;

  switch(op) {

    case '+':
      result = num1 + num2;
      std::cout << "Result: " << result << '\n';
      break;
    case '-':
      result = num1 - num2;
      std::cout << "Result: " << result << '\n';
      break;
    case '*':
      result = num1 * num2;
      std::cout << "Result: " << result << '\n';
      break;
    case '/':
      result = num1 / num2;
      std::cout << "Result: " << result << '\n';
      break;
    default :
      std::cout << "the operator is not valid";
      break;
      
  }

  std::cout << "***********************************\n";

  return 0;
}