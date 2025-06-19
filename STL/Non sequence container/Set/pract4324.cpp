#include <iostream>
#include <set>

int main() {

  std::set<int> s = {2, 4, 6, 8, 10};

  auto it = s.lower_bound(5);

  while(it != s.end()) {
    std::cout << *it << " ";
    ++it;
  }

  return 0;
}