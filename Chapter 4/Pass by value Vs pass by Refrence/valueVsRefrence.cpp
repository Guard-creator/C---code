#include <iostream>

using string = std::string;

void swap(string &x, string &y);

int main() {

  // PASS BY VALUE VS PASS BY REFRENCE.
  
  // so when ever we give the value to function 
  // the value that is pass is not the orginal value that have been assign in the main function
  // let see what i mean when i try to swap the value by function

  string x = "Nissan";
  string y = "Lamborgini";

  swap(x, y);

  std::cout << "X: " << x << '\n';
  std::cout << "Y: " << y << '\n';

  return 0;
}

// this create a copy of the variable its not the orginal the is assign in main function.
// you can also check their both memory address.

/*
void swap(string x, string y) {

  string temp;

  temp = x;
  x = y;
  y = temp;

}
*/

// now lets use the memory address & to swap  the both variables
// see?? works right 
// so its better to use memory address to swap or change the orignal value.
void swap(string &x, string &y) {

  string temp;

  temp = x;
  x = y;
  y = temp;

}