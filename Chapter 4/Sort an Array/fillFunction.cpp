#include <iostream>

using string = std::string;

int main() {

  // fill function are used to fills the element of array that are long 
  // if we want a array of 100 element of string pizza
  // you have to type manual but with fill it becomes easy

  string menu[9];
  
  // is first argument we hve to tell where to start 
  // and in second we tell when to end
  // in third we tell what we want to print.
  fill(menu, menu + 9/3, "Pizza");
  fill(menu + 9/3, menu + (9/3)*2, "Burger");
  fill(menu + (9/3)*2, menu + 9, "Macroni");

  for(string element : menu) {
    std::cout << element << '\n';
  }

  return 0;
}