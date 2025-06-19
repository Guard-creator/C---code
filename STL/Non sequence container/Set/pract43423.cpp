#include <iostream>
#include <set>

int main() {

  std::set<int> s = {10, 20, 30};

  int userInput;

  std::cout << "Put Something In it..: ";
  std::cin >> userInput;

  auto it = s.lower_bound(userInput);

  if(it != s.end()) {
    std::cout << "Lower bound of " << userInput << " is " << *it << "\n";
  } else {
    std::cout << "No element >= "<< userInput << " found.\n";
  }

  return 0;
}