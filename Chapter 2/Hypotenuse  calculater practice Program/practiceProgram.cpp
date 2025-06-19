#include <iostream>
#include <cmath>

int main() {

  // no rocket science just a simple practice program.
  
  double a;
  double b;
  double c; 

  std::cout << "Enter A value: ";
  std::cin >> a;

  std::cout << "Enter B value: ";
  std::cin >> b;

  c = sqrt(pow(a, 2) + pow(b, 2));

  std::cout << "The hypotenuse of giving angle value is " << c << '\n';

  return 0; 
}