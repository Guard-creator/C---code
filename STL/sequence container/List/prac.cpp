#include <iostream>
#include <list>
#include <algorithm>

int main() {

  std::list<int> list1 = {10, 20, 30, 40, 50};

  int findElement;
  std::cout << "Enter a Element to Find it: ";
  std::cin >> findElement;

  auto it = find(list1.begin(), list1.end(), findElement);

  if(it != list1.end()) {
    std::cout << "Element " << findElement << " Found in the list\n";
  } else {
    std::cout << "Element " << findElement << " Not Found in the list\n";
  }

  return 0;
}