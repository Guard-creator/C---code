#include <iostream>
#include <set>

int main() {

  std::set<int> s = {1, 3, 5, 7, 9};

  int userInput;
  std::cout << "Enter a number to see it exist in set: ";
  std::cin >> userInput;

  auto it = s.lower_bound(userInput);

  if(it != s.end() && *it == userInput) {
    std::cout << "Yes it Exist in Set.";
  } else  {
    std::cout << "no it doesn't Exist in Set.";
  }

  return 0;
}