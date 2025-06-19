#include <iostream>
#include <vector>
#include <algorithm>

int main() {

  // this is an function for sort which i hate i like to make my own function

  int arr[5] = {8, 2, 4, 6, 10};

  std::sort(arr, arr + 5);

  std::cout << "==================================" << '\n';

  std::cout << "Array: ";
  for(auto pr : arr) {
    std::cout << pr << " ";
  }

  std::cout << '\n';

  std::vector<int> vec = {5, 3, 4, 2, 1};

  sort(vec.begin(), vec.end());

  std::cout << "==================================" << '\n';

  std::cout << "Vector: ";
  for(auto pr : vec) {
    std::cout << pr << " ";
  }

  std::cout << '\n';
  std::cout << "==================================" << '\n';

  std::vector<int> vec2 = {3, 7, 5, 1, 9};

  // using this comparater we reverse the sort.
  sort(vec2.begin(), vec2.end(), std::greater<int>());

  std::cout << "Vector2 (greater funtion for desending order(reverse order)): \n";
  for(auto pr : vec2) {
    std::cout << pr << " ";
  }

  std::cout << '\n';
  std::cout << "==================================" << '\n';

  // here in pairs we can only sort pair first element to each other 
  // but not the second
  // we have to build custom parameter for that.
  std::vector<std::pair<int, int>> vecPair3 = {{3, 2}, {5, 1}, {8, 4}, {9, 5}};

  sort(vecPair3.begin(), vecPair3.end());

    std::cout << "Vector 3 but with double pair: \n";
  for(auto pr : vecPair3) {
    std::cout << pr.first << " | " << pr.second << '\n'; 
  }

    std::cout << '\n';
  std::cout << "==================================" << '\n';

  return 0;
}