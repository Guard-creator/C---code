#include <iostream>

  // cout << (insertion operator)
  // cin >> (extraction operator)

  // character input = cin

  // its is used for when you wanna type a text and saved it a string or nums
  // in a variable, its is useful to input from a person.

int main() {

  std::string name;
  int age;

  std::cout << "what is your age ? " << '\n';
  std::cin >> age;

  std::cout << "what is your name ?" << '\n';
  // getline is a function that you can used it for to get the full line or full string.
  std::getline(std::cin >> std::ws, name);
  // the reason we add a std::ws is because to prevent a bug
  // the reason is when you input your age and do getline function 
  // it will just pick a empty line because the age is a new line32


  std:: cout << "your name is " << name << "." << '\n';
  std::cout << "you are " << age << " years old."; 

  return 0;
}