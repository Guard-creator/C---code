#include <iostream>

int main() {

  // making a program to convert any number to faherenhiet to celicus and c to f.

  double temp;
  char unit;
  int result;

  std::cout << "*****TEMPERATURE CONVERSION******\n";
  std::cout << "F = Fahrenheit\n";
  std::cout << "C = Celicus\n";
  std::cout << "What unit would you like to convert to: ";
  std::cin >> unit;

  if(unit == 'F' || unit == 'f') {

    std::cout << "Enter the Temperature in C: ";
    std::cin >> temp;

    result = (1.8 * temp) + 32.0;
    std::cout << "The Temperature is " << result << "F \n";

  } else if (unit == 'C' ||  unit == 'c') {

    std::cout << "Enter the Temperature in F: ";
    std::cin >> temp;

    result = (temp - 32.0) / 1.8;
    std::cout << "The Temperature is " << result << "C \n";

  } else {
    std::cout << "Please Enter the Unit in C or F \n";
  }


  std::cout << "********************************* \n";

  return 0;
}