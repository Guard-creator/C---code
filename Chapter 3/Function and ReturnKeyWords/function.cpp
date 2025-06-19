#include <iostream>

// funtion are different in cpp 
// function can be call in main function when the void funtion is 
// declare first otherwise if the function is declare after the main function
// then its cannot be called we have to declare the function on top for that 
// its the only way it can worked.

// parameter i know them very well.
// but parameter should also be declare 
// what kind of data is passing.

// this is called function declaration.
void playerFun(std::string name);

int main() {

  std::string name = "Basit Shaikh";

  playerFun(name);
  playerFun(name);
  playerFun(name);

  return 0;
}

// and this is function definition
void playerFun(std::string name) {
  std::cout << name << " Learning function for the first time.\n\n";
}