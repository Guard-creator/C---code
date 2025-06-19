#include <iostream>

int main () {

  // ternary operator is like if statements
  // let say its a shortcut key

  /*
    int marks;
    std::string result;

    std::cout << "Enter your Marks: ";
    std::cin >> marks;


    result = marks >= 75 ? "You Pass!!" : "YOU FAILED !!";

    std::cout << result; 
  */

  /*
    int num;
    std::string result;

    std::cout << "Enter a number: ";
    std::cin >> num;

    result = num % 2 ? "Odd" : "Even";

    std::cout << result;
  */

    bool computer = false;
    std::string result;

    result = computer ? "Computer is On" : "Computer is Off";

    std::cout << result;

  return 0;
}