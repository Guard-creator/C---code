#include <iostream>

int main() {

  // sizeof() function is useds to measure the 
  // size of a data type in bytes;


  std::string name = "Basit";
  //std::cout << sizeof(name) << '\n'; // 32 bytes

  int num = 323;
  //std::cout << sizeof(num) << '\n'; // 4 bytes

  double num43 = 545.53;
  //std::cout << sizeof(num43) << '\n'; // 8 bytes

  char grade3 = 'A';
  //std::cout << sizeof(grade3) << '\n'; // 1  byte

  bool student = true;
  //std::cout << sizeof(student) << '\n'; // 1 byte

  // let find an array data size.

  std::string names[] = {"rick", "Ben", "eren", "mikasa", "Berthold"};

  //std::cout << sizeof(names) << '\n'; // 160 bytes

  // using this method we can also find the length of a array.

  //std::cout << sizeof(names) / sizeof(std::string) << '\n'; // 5 and there are 5 string.

  return 0;
}