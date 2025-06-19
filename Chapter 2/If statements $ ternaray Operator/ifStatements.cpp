#include <iostream>
#include <cmath>

int main() {

  // if statements that are same as javascripts ones
  // no change of synatax its same


  /*
  int age;

  std::cout << "Enter your Age: ";
  std::cin >> age;

  if (age <= 0) {
    std::cout << "you are not even born yet";
  } else if(age <= 18) { 
    std::cout << "you are too young";
  } else if (age >= 50) {
    std::cout << "you are too old";
  } else if (age >= 18) {
    std::cout << "Welcome to the Site";
  }
  */

  double pizzaEaten;
  const double pizzaPrice = 1000;
  double totalPrice;

  std::cout << "how many pizza have you eaten: ";
  std::cin >> pizzaEaten;

  if(pizzaEaten <= 0) {
    std::cout << "you cant eat zero pizza";
    return 1;
  }

  totalPrice = (round(pizzaEaten) * pizzaPrice) / 100;

  std::cout << "You're total price will be: $" << totalPrice;


  return 0;
}