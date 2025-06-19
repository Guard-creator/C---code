#include <iostream>
#include <deque>

int main() {

  std::deque<int> deqSve;

  int n;
  std::cout << "Enter Number of Elements: ";
  std::cin >> n;

  for(int i = 0; i < n; i++) {
    std::cout << "Element " << i + 1 << ": ";
    int num;
    std::cin >> num;
    deqSve.push_back(num);
  } 

  std::cout << "Reversed Order: ";
  for (auto it = deqSve.rbegin(); it != deqSve.rend(); ++it) {
    std::cout << *it << " ";
  }

  return 0;
}

