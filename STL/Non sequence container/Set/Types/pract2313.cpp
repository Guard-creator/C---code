#include <iostream>
#include <unordered_set>

int main() {

  int n;
  std::cout << "Enter the size of set: ";
  std::cin >> n;

  std::unordered_set<int> unorderSet;
  int num;

  std::cout << "Enter " << n << "in set: \n";
  for(int i = 0; i < n; i++) {
    std::cin >> num;
    unorderSet.insert(num);
  }

  if(unorderSet.size() == n) {
    std::cout << "All elements are unique.\n";
  } else {
    std::cout << "Dublicates detected.\n";
  }

  return 0;
}