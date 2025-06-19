#include <iostream>
#include <set>

int main() {

  std::multiset<int> ms = {5, 3, 5, 7, 3, 3, 5};

  int userInput;
  std::cout << "Enter the Number: ";
  std::cin >> userInput;
  
  int count = ms.count(userInput);
  std::cout << userInput << " Apperear " << count << " Times.\n";

  return 0;
}