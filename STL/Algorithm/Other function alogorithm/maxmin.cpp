#include <iostream>
#include <vector>
#include <algorithm>

int main() {

  std::vector<int> vec = {2, 1, 3, 5, 6, 4};

  int max = *max_element(vec.begin(), vec.end());
  int min = *min_element(vec.begin(), vec.end());

  std::cout << "MAX: " << max << '\n';
  std::cout << "MIN: " << min << '\n';

  return 0;
}