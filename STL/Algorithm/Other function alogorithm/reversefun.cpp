#include <iostream>
#include <vector>
#include <algorithm>

int main() {

  // i mean do we really need to go through

  std::vector<int> vec = {1, 2, 3, 4, 5};

  reverse(vec.begin(), vec.end());

  for(int pr : vec) {
    std::cout << pr << " ";
  }

  return 0;
}