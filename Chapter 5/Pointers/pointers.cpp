#include <iostream>

int main() {

  // A pointer is variable that store other variables memory address.
  // it have been sayed for many centuries that it is useful for working with memory Address.

  // pointer doesn't have a fix memory address it keep changing when you run the code.
  
  std::string meal = "Pizza";
  int age = 17;

  std::string * pMeal = &meal; // this is an pointer.
  int * pAge = &age;

  // you can use * derefrence operator to get the value of the pointer.
  std::cout << *pMeal << '\n';
  std::cout << *pAge << '\n';

  // refrence operator & are used to get the memory address like above.

  // however using pointer you can also view memory address
  // like this 
  std::cout << pMeal << '\n';
  std::cout << pAge << '\n';

  return 0;
}