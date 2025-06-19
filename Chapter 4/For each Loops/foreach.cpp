#include <iostream>

int main() {

  // same as i learn in javascripts but different synatax

  // let dispaly the string of arrays using for each loop

  std::string names[] = {"Rick", "Morty", "mango", "eren", "akane", "jarico"};

  for(std::string name : names) {
    std::cout << name << '\n';
  }

  // another example

  double nums[] = {44, 1312, 43, 22, 77, 34, 4, 434};

  double result = 0;

  for(double num : nums) {
    result += num;
  }

  std::cout << result << '\n';

  return 0;
}