#include <iostream>

int main() {

  // dynamic memory that is allocated or distributed after 
  // the program is already running or compiling.
  // it's get store in heap instead of stack

  // useful when we dont know the what to assign the
  // value before running the program like (user input)
  // and dont know how much memory we need 
  // it is to make our program more flexible expecially 
  // when accepting user input.

  std::string *pName = new std::string;

  std::cout << "ENTER A DATA TYPE OR ANYTHING YOU LIKE: \n";
  std::cin >> *pName;

  std::cout << "ADDRESS: " << pName << '\n';
  std::cout << "Value: " << *pName << '\n';
  
  delete pName;

  return 0;
}

// another example on the different file using array -- 