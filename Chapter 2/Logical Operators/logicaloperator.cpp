#include <iostream>

int main() {

  // && = check if two condition is true other wise if 
  // one statement is false whole statments wil be false.

  // || = if from two statement only one is true otherwise 
  // one statement is false whole statment is false.

  // ! = change false statement to true and true to false.

  // && example.

  /*
    double num1;

    std::cout << "Enter a number Bitch: ";
    std::cin >> num1;

    if(num1 >= 0 && num1 < 50) {
      std::cout << "You are smart";
    } else {
      std::cout << "You are Dumbass";
    }
  */

  // || example

  /*
    double num1;

    std::cout << "Enter a number Bitch: ";
    std::cin >> num1;

    if(num1 <= 0 || num1 >= 50) {
      std::cout << "You are Dumbass";
    } else {
      std::cout << "You are Smart";
    }
  */

  // ! example

  bool computer = true;

  if(!computer) {
    std::cout << "computer is off";
  } else {
    std::cout << "computer is on";
  }

  return 0;
}