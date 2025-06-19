#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> vec = {2, 1, 3, 5, 6, 4};

    // sort need for vector to search binary
    std::sort(vec.begin(), vec.end());

    std::cout << "10 Exist in Vector: " << binary_search(vec.begin(), vec.end(), 10) << '\n';
    std::cout << "6 Exist in Vector: " << binary_search(vec.begin(), vec.end(), 6) << '\n';

  return 0;
}