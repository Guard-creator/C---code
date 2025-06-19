#include <iostream>

void printCout(std::string name, int age);

int main() {

  // const parameters 
  // when passing a function arguements you can assign them 
  // as constant value.

   std::string name = "Basit Shaikh";
   int age = 17;

  printCout(name, age);

  return 0;
}

void printCout(const std::string name,const int age) {

  // now the value is const it cant be changed
  // it important when we pass the original value using memory address.
  // we dont want to change the orignal value huh ?? do you ??
  // name = " ";
  // age = 0;

  std::cout << name << '\n';
  std::cout << age << '\n';
}