#include <iostream>

int main() {

  // memory address of something data address that are store in computer
  // like take variables variables have memory address in hexadecimal 
  // we can see it like this using &. 

  std::string food = "Pizza";
  double myAge = 17.5;
  bool student = true;

  std::cout << &food << '\n'; // 0xe04d3ffa00 into octal 16011517775000
  std::cout << &myAge << '\n'; // 0xe04d3ff9f8 into octal 16011517774770
  std::cout << &student << '\n'; // 0xe04d3ff9f7 into octal 16011517774767

  return 0;
}

