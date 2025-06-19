#include <iostream>

  // overLoaded function 
  // these function can have same name but with  different Parameters
  // which is i find useful because we can change the parameter anytime 
  // with the same function name execute but with a different datatype 
  // here iis what i mean by it.

  using string = std::string;

  // When you call a function and provide parameters, the function signature helps the compiler 
  // figure out which specific version of the function to call. It matches the name and the parameters 
  // (number, types, and order) with the correct function definition.

  void bakePizza();
  void bakePizza(string topping1);
  void bakePizza(string topping1, string topping2); 

int main() {

  bakePizza();
  bakePizza("Fagita");
  bakePizza("PineApple", "Mushroom");

  return 0;
}

  // When you declare multiple functions with the same name but different 
  // parameters, this is called function overloading. It allows you to reuse 
  // the same function name for different tasks depending on the inputs.

  void bakePizza() {
    std::cout << "Here is Your Pizza!!!\n";
  };

  void bakePizza(string topping1) {
    std::cout << "Here is Your Pizza With topping of " << topping1 << '\n';
  };

  void bakePizza(string topping1, string topping2) {
    std::cout << "Here is Your Pizza With topping of " << topping1 << " and With " << topping2 << '\n';
  };