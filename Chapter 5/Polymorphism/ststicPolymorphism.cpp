#include <iostream>

// the another type of static polymorphism 
// is Function overloading 

// I already discuss this but let discuss it again for clarifying 
// others issue when we encounter..

// function overloading is when we have multiple function we same name but different parameters 
// compiler determined which function to call based on the argument.

class Math {
  public: 

  int add(int num1, int num2) {
    return num1 + num2;
  };

  double add(double num1, double num2) {
    return num1 + num2;
  };

  std::string add(std::string text1, std::string text2) {
    return text1 + text2;
  }

};

int main() {

  Math number;

  std::cout << "Int: " << number.add(6, 8) << '\n';
  std::cout << "Double: " << number.add(7.8, 56.5) << '\n';
  std::cout << "String: " << number.add("Bas", "it") << '\n';

  return 0;
}